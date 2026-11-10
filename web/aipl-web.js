/**
 * AIPL Zero-Build Browser Ingestion Loader (Step 28)
 * https://github.com/forart82/aipl
 * Direct in-browser execution of <script type="text/aipl"> tags.
 */
(function (global) {
  'use strict';

  const root = typeof window !== 'undefined' ? window : (typeof globalThis !== 'undefined' ? globalThis : global);

  root.__AIPL_STATE__ = root.__AIPL_STATE__ || {};
  root.__AIPL_MODULES__ = root.__AIPL_MODULES__ || new Map();

  const config = {
    wasmUrl: 'aipl-compiler.wasm',
    autoInit: true,
    hmr: true,
    debug: false,
  };

  if (typeof document !== 'undefined') {
    const cs = document.currentScript;
    if (cs) {
      const customWasm = cs.getAttribute('data-wasm');
      if (customWasm) {
        config.wasmUrl = customWasm;
      } else if (cs.src) {
        const idx = cs.src.lastIndexOf('/');
        if (idx !== -1) config.wasmUrl = cs.src.substring(0, idx + 1) + 'aipl-compiler.wasm';
      }
      if (cs.getAttribute('data-hmr') === 'false') config.hmr = false;
      if (cs.getAttribute('data-debug') === 'true') config.debug = true;
    }
  }

  const workerCode = `
    let wasmInstance = null, isInitializing = false, initPromise = null;
    async function initWasm(urlOrBuffer) {
      if (wasmInstance) return wasmInstance;
      if (isInitializing) return initPromise;
      isInitializing = true;
      initPromise = (async () => {
        let bytes;
        if (urlOrBuffer instanceof ArrayBuffer || (typeof Uint8Array !== 'undefined' && urlOrBuffer instanceof Uint8Array)) {
          bytes = urlOrBuffer;
        } else {
          const res = await fetch(urlOrBuffer);
          bytes = await res.arrayBuffer();
        }
        const { instance } = await WebAssembly.instantiate(bytes, {});
        wasmInstance = instance;
        return wasmInstance;
      })();
      return initPromise;
    }

    self.onmessage = async (e) => {
      const { id, action, payload } = e.data;
      try {
        if (action === 'init') {
          await initWasm(payload.wasmUrlOrBuffer);
          self.postMessage({ id, success: true });
          return;
        }
        if (action === 'compile') {
          if (!wasmInstance) await initWasm(payload.wasmUrl);
          const { source, options } = payload;
          const enc = new TextEncoder(), dec = new TextDecoder();
          const srcBytes = enc.encode(source), optBytes = enc.encode(options || '{}');

          const srcPtr = wasmInstance.exports.aipl_alloc(srcBytes.length);
          const optPtr = wasmInstance.exports.aipl_alloc(optBytes.length);

          new Uint8Array(wasmInstance.exports.memory.buffer, srcPtr, srcBytes.length).set(srcBytes);
          new Uint8Array(wasmInstance.exports.memory.buffer, optPtr, optBytes.length).set(optBytes);

          const resPtr = wasmInstance.exports.aipl_compile(srcPtr, srcBytes.length, optPtr, optBytes.length);
          const resLen = wasmInstance.exports.aipl_result_len();

          const resBytes = new Uint8Array(wasmInstance.exports.memory.buffer, resPtr, resLen);
          const resJsonStr = dec.decode(resBytes);

          wasmInstance.exports.aipl_dealloc(srcPtr, srcBytes.length);
          wasmInstance.exports.aipl_dealloc(optPtr, optBytes.length);

          self.postMessage({ id, success: true, result: JSON.parse(resJsonStr) });
        }
      } catch (err) {
        self.postMessage({ id, success: false, error: err.message || String(err) });
      }
    };
  `;

  class CompilerWorkerBridge {
    constructor() {
      this.worker = null;
      this.reqId = 0;
      this.callbacks = new Map();
      this.wasmInstance = null;
      this.isReady = false;
      this.initPromise = null;
    }

    async init(wasmUrlOrBuffer) {
      if (this.isReady) return;
      if (this.initPromise) return this.initPromise;

      this.initPromise = (async () => {
        const targetWasm = wasmUrlOrBuffer || config.wasmUrl;

        if (typeof Worker !== 'undefined' && typeof Blob !== 'undefined' && typeof URL !== 'undefined') {
          try {
            const blob = new Blob([workerCode], { type: 'application/javascript' });
            const workerUrl = URL.createObjectURL(blob);
            this.worker = new Worker(workerUrl);

            this.worker.onmessage = (e) => {
              const { id, success, result, error } = e.data;
              const cb = this.callbacks.get(id);
              if (cb) {
                this.callbacks.delete(id);
                if (success) cb.resolve(result);
                else cb.reject(new Error(error));
              }
            };

            await this._sendWorkerMessage('init', { wasmUrlOrBuffer: targetWasm });
            this.isReady = true;
            return;
          } catch (workerErr) {
            if (config.debug) console.warn('[AIPL] Worker fallback to main thread:', workerErr);
          }
        }

        let bytes;
        if (targetWasm instanceof ArrayBuffer || (typeof Uint8Array !== 'undefined' && targetWasm instanceof Uint8Array)) {
          bytes = targetWasm;
        } else if (typeof fetch !== 'undefined') {
          const res = await fetch(targetWasm);
          bytes = await res.arrayBuffer();
        } else if (typeof require !== 'undefined') {
          const fs = require('fs'), path = require('path');
          const p = path.isAbsolute(targetWasm) ? targetWasm : path.resolve(process.cwd(), targetWasm);
          bytes = fs.readFileSync(p);
        } else {
          throw new Error('No mechanism available to fetch wasm binary');
        }

        const { instance } = await WebAssembly.instantiate(bytes, {});
        this.wasmInstance = instance;
        this.isReady = true;
      })();

      return this.initPromise;
    }

    _sendWorkerMessage(action, payload) {
      return new Promise((resolve, reject) => {
        const id = ++this.reqId;
        this.callbacks.set(id, { resolve, reject });
        this.worker.postMessage({ id, action, payload });
      });
    }

    async compile(source, options) {
      const t0 = typeof performance !== 'undefined' ? performance.now() : Date.now();
      await this.init();

      let result;
      if (this.worker) {
        result = await this._sendWorkerMessage('compile', {
          source,
          options: JSON.stringify(options || {}),
          wasmUrl: config.wasmUrl,
        });
      } else {
        result = this._compileSync(source, options);
      }

      const elapsed = (typeof performance !== 'undefined' ? performance.now() : Date.now()) - t0;
      return { result, elapsed };
    }

    _compileSync(source, options) {
      if (!this.wasmInstance) throw new Error('AIPL Wasm compiler not initialized');
      const enc = new TextEncoder(), dec = new TextDecoder();
      const srcBytes = enc.encode(source), optBytes = enc.encode(JSON.stringify(options || {}));

      const srcPtr = this.wasmInstance.exports.aipl_alloc(srcBytes.length);
      const optPtr = this.wasmInstance.exports.aipl_alloc(optBytes.length);

      new Uint8Array(this.wasmInstance.exports.memory.buffer, srcPtr, srcBytes.length).set(srcBytes);
      new Uint8Array(this.wasmInstance.exports.memory.buffer, optPtr, optBytes.length).set(optBytes);

      const resPtr = this.wasmInstance.exports.aipl_compile(srcPtr, srcBytes.length, optPtr, optBytes.length);
      const resLen = this.wasmInstance.exports.aipl_result_len();

      const resBytes = new Uint8Array(this.wasmInstance.exports.memory.buffer, resPtr, resLen);
      const resJsonStr = dec.decode(resBytes);

      this.wasmInstance.exports.aipl_dealloc(srcPtr, srcBytes.length);
      this.wasmInstance.exports.aipl_dealloc(optPtr, optBytes.length);

      return JSON.parse(resJsonStr);
    }
  }

  const bridge = new CompilerWorkerBridge();

  async function importModuleFromCode(code) {
    if (typeof URL !== 'undefined' && typeof URL.createObjectURL === 'function' && typeof Blob !== 'undefined') {
      try {
        const blob = new Blob([code], { type: 'text/javascript' });
        const blobUrl = URL.createObjectURL(blob);
        const mod = await import(blobUrl);
        return { module: mod, blobUrl };
      } catch (err) {
        if (err.message && err.message.includes("protocol 'blob:'")) {
          const b64 = typeof btoa === 'function' ? btoa(unescape(encodeURIComponent(code))) : Buffer.from(code).toString('base64');
          const dataUri = `data:text/javascript;base64,${b64}`;
          const mod = await import(dataUri);
          return { module: mod, blobUrl: dataUri };
        }
        throw err;
      }
    }
    const b64 = typeof btoa === 'function' ? btoa(unescape(encodeURIComponent(code))) : Buffer.from(code).toString('base64');
    const dataUri = `data:text/javascript;base64,${b64}`;
    const mod = await import(dataUri);
    return { module: mod, blobUrl: dataUri };
  }

  let scriptCounter = 0;

  function getScriptId(el) {
    let id = el.getAttribute('data-aipl-id') || el.id || el.getAttribute('src');
    if (!id) {
      id = `aipl-script-${++scriptCounter}`;
      if (el.setAttribute) { el.setAttribute('data-aipl-id', id); }
    }
    return id;
  }

  async function getScriptSource(el) {
    const src = el.getAttribute('src');
    if (src) {
      const res = await fetch(src);
      return res.text();
    }
    return el.textContent || el.innerText || '';
  }

  async function loadAndExecuteScript(scriptEl, isHmrUpdate = false) {
    const scriptId = getScriptId(scriptEl);
    const source = await getScriptSource(scriptEl);
    if (!source.trim()) return null;

    const options = {
      source_file_name: scriptEl.getAttribute('src') || `${scriptId}.aipl`,
      jsx_mode: scriptEl.getAttribute('data-jsx-mode') || 'react19_runtime',
      inline_source_map: true,
      pure_js: true,
      hmr: config.hmr,
      script_id: scriptId,
    };

    const { result, elapsed } = await bridge.compile(source, options);
    if (!result || !result.code) throw new Error(`[AIPL] Compilation produced no code for: ${scriptId}`);

    const { module: mod, blobUrl } = await importModuleFromCode(result.code);

    const oldRecord = root.__AIPL_MODULES__.get(scriptId);
    if (oldRecord && oldRecord.blobUrl && oldRecord.blobUrl.startsWith('blob:')) {
      try { URL.revokeObjectURL(oldRecord.blobUrl); } catch (_) {}
    }

    root.__AIPL_MODULES__.set(scriptId, {
      scriptElement: scriptEl,
      scriptId,
      source,
      code: result.code,
      map: result.map,
      module: mod,
      blobUrl,
      lastUpdated: Date.now(),
    });

    if (typeof CustomEvent !== 'undefined' && typeof scriptEl.dispatchEvent === 'function') {
      const eventName = isHmrUpdate ? 'aipl:hmr' : 'aipl:loaded';
      const event = new CustomEvent(eventName, {
        bubbles: true,
        detail: { scriptId, module: mod, elapsed, state: root.__AIPL_STATE__[scriptId] },
      });
      scriptEl.dispatchEvent(event);
      if (typeof window !== 'undefined' && typeof window.dispatchEvent === 'function') window.dispatchEvent(event);
    }

    return { scriptId, module: mod, elapsed, map: result.map };
  }

  const processedScripts = new WeakSet();

  function scanAndProcessScripts(container = document) {
    if (!container || typeof container.querySelectorAll !== 'function') return;
    const scripts = container.querySelectorAll('script[type="text/aipl"]');
    for (let i = 0; i < scripts.length; i++) {
      const script = scripts[i];
      if (!processedScripts.has(script)) {
        processedScripts.add(script);
        loadAndExecuteScript(script, false).catch((err) => {
          console.error(`[AIPL] Error executing script (${getScriptId(script)}):`, err);
        });
      }
    }
  }

  function setupMutationObserver() {
    if (typeof MutationObserver === 'undefined' || typeof document === 'undefined') return;

    const observer = new MutationObserver((mutations) => {
      for (const mut of mutations) {
        if (mut.type === 'childList') {
          for (let i = 0; i < mut.addedNodes.length; i++) {
            const node = mut.addedNodes[i];
            if (node.nodeType === 1) {
              if (node.tagName === 'SCRIPT' && node.getAttribute('type') === 'text/aipl') {
                if (!processedScripts.has(node)) {
                  processedScripts.add(node);
                  loadAndExecuteScript(node, false).catch(console.error);
                }
              } else {
                scanAndProcessScripts(node);
              }
            }
          }
        }

        if (config.hmr) {
          let targetScript = null;
          if (mut.type === 'characterData' && mut.target && mut.target.parentNode) {
            const p = mut.target.parentNode;
            if (p.tagName === 'SCRIPT' && p.getAttribute('type') === 'text/aipl') targetScript = p;
          } else if (mut.type === 'childList' && mut.target && mut.target.tagName === 'SCRIPT') {
            if (mut.target.getAttribute('type') === 'text/aipl') targetScript = mut.target;
          }
          if (targetScript) {
            loadAndExecuteScript(targetScript, true).catch(console.error);
          }
        }
      }
    });

    observer.observe(document.documentElement || document.body, {
      childList: true,
      subtree: true,
      characterData: true,
    });

    return observer;
  }

  const AIPL = {
    config,
    bridge,
    init: (w) => bridge.init(w),
    compile: (s, o) => bridge.compile(s, o),
    loadScript: (el, h) => loadAndExecuteScript(el, h),
    scan: (c) => scanAndProcessScripts(c),
    getState: (id) => root.__AIPL_STATE__[id] || null,
    setState: (id, st) => { root.__AIPL_STATE__[id] = st; },
    getModule: (id) => root.__AIPL_MODULES__.get(id) || null,
  };

  root.AIPL = AIPL;

  if (config.autoInit && typeof document !== 'undefined') {
    if (document.readyState === 'loading') {
      document.addEventListener('DOMContentLoaded', () => {
        setupMutationObserver();
        scanAndProcessScripts(document);
      });
    } else {
      setupMutationObserver();
      scanAndProcessScripts(document);
    }
  }

  if (typeof module !== 'undefined' && module.exports) {
    module.exports = AIPL;
  }
})(typeof window !== 'undefined' ? window : (typeof globalThis !== 'undefined' ? globalThis : this));
