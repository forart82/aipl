"use strict";

const fs = require("fs");
const path = require("path");
const os = require("os");
const { spawn, spawnSync } = require("child_process");

let vscode = null;
try {
  vscode = require("vscode");
} catch (_) {
  vscode = null;
}

let lspProcess = null;
let diagCollection = null;
let misalignedDecorationType = null;
let syntaxErrorDecorationType = null;
let nextRequestId = 1;
const pendingRequests = new Map();
const lspDiagnosticsByUri = new Map();
const localDiagnosticsByUri = new Map();
const workspaceSymbolCache = new Map(); // filePath -> { mtimeMs, symbols }

const STD_DOMAINS = [
  "sys",
  "alloc",
  "rt",
  "math",
  "collections",
  "fmt",
  "regex",
  "time",
  "encoding",
  "crypto",
  "compress",
  "io",
  "fs",
  "thread",
  "sync",
  "os",
  "net",
  "db",
  "test",
  "ecs",
  "spatial",
  "phys2d",
  "phys3d",
  "window",
  "input",
  "gfx2d",
  "gfx3d",
  "gfx",
  "ui",
  "audio",
  "asset",
  "procgen",
  "particle",
  "ai",
  "mechanics",
];

const AIPL_THEMES = [
  {
    label: "AIPL Aura Dark",
    uiTheme: "vs-dark",
    path: "./themes/aipl-aura-dark-color-theme.json",
    description: "Deep Slate (#161922) & Soft Mist (#B8C4D9)",
    detail: "Low-eye-strain cyber-slate dark theme with lavender, sky-blue, and sage pastels.",
  },
  {
    label: "AIPL Nordic Frost",
    uiTheme: "vs-dark",
    path: "./themes/aipl-nordic-frost-color-theme.json",
    description: "Arctic Fjord (#242933) & Snow Mist (#D8DEE9)",
    detail: "Calm polar palette with glacier cyan, frost blue, and aurora green.",
  },
  {
    label: "AIPL Evergreen Forest",
    uiTheme: "vs-dark",
    path: "./themes/aipl-evergreen-forest-color-theme.json",
    description: "Woodland Moss (#1E2522) & Warm Parchment (#D3C6AA)",
    detail: "Organic botanical palette with fern green, aqua, and honey gold.",
  },
  {
    label: "AIPL Rose Pine Dusk",
    uiTheme: "vs-dark",
    path: "./themes/aipl-rose-pine-dusk-color-theme.json",
    description: "Twilight Velvet (#232136) & Lavender Foam (#E0DEF4)",
    detail: "Soothing dusk palette with rosebud, pine teal, iris violet, and soft gold.",
  },
  {
    label: "AIPL Espresso Warm",
    uiTheme: "vs-dark",
    path: "./themes/aipl-espresso-warm-color-theme.json",
    description: "Roasted Coffee (#24201E) & Warm Oatmilk (#DDC7A1)",
    detail: "Earthy warm dark palette with cinnamon orange, pistachio green, and ochre.",
  },
  {
    label: "AIPL Solarized Daylight",
    uiTheme: "vs",
    path: "./themes/aipl-solarized-daylight-color-theme.json",
    description: "Warm Cream Parchment (#F4EFE6) & Charcoal Ink (#3B4252)",
    detail: "Low-glare daylight theme with ocean blue, forest green, and terracotta.",
  },
];

// ============================================================================
// 1. Binary & Workspace Root Discovery
// ============================================================================

function getWorkspaceRoots(currentFilePath) {
  const roots = [];
  if (vscode && vscode.workspace && Array.isArray(vscode.workspace.workspaceFolders)) {
    for (const wf of vscode.workspace.workspaceFolders) {
      if (wf && wf.uri && wf.uri.fsPath) {
        roots.push(wf.uri.fsPath);
      }
    }
  }
  if (currentFilePath) {
    let dir = path.dirname(path.resolve(currentFilePath));
    for (let depth = 0; depth < 6; depth++) {
      if (
        fs.existsSync(path.join(dir, "std")) ||
        fs.existsSync(path.join(dir, "bin", "aipl")) ||
        fs.existsSync(path.join(dir, "AI_SPEC.md"))
      ) {
        if (!roots.includes(dir)) roots.push(dir);
        break;
      }
      const parent = path.dirname(dir);
      if (parent === dir) break;
      dir = parent;
    }
    const startDir = path.dirname(path.resolve(currentFilePath));
    if (!roots.includes(startDir)) {
      roots.push(startDir);
    }
  }
  const extRepoRoot = path.resolve(__dirname, "../..");
  if (fs.existsSync(path.join(extRepoRoot, "std")) && !roots.includes(extRepoRoot)) {
    roots.push(extRepoRoot);
  }
  return roots;
}

function getAiplBin() {
  if (vscode && vscode.workspace) {
    const cfg = vscode.workspace.getConfiguration("aipl");
    const configured = cfg.get("executablePath");
    if (configured && configured !== "aipl") {
      if (fs.existsSync(configured)) return configured;
      const roots = getWorkspaceRoots();
      for (const r of roots) {
        const cand = path.resolve(r, configured);
        if (fs.existsSync(cand)) return cand;
      }
    }
  }
  if (process.env.AIPL_BIN && fs.existsSync(process.env.AIPL_BIN)) {
    return process.env.AIPL_BIN;
  }
  const roots = getWorkspaceRoots();
  for (const r of roots) {
    const binCand = path.join(r, "bin", "aipl");
    if (fs.existsSync(binCand)) return binCand;
  }
  const extBin = path.resolve(__dirname, "../../bin/aipl");
  if (fs.existsSync(extBin)) return extBin;

  const home = os.homedir();
  if (home) {
    const localBin = path.join(home, ".local", "bin", "aipl");
    if (fs.existsSync(localBin)) return localBin;
    const cargoBin = path.join(home, ".cargo", "bin", "aipl");
    if (fs.existsSync(cargoBin)) return cargoBin;
  }
  return "aipl";
}

// ============================================================================
// 2. Built-in Code Beautifier & Formatter (`aipl fmt --stdin` + AST/Block Align)
// ============================================================================

function tokenizeLineSegments(line) {
  const segments = [];
  let comment = "";
  let opensMultiline = null;
  let unclosedQuote = null;
  let i = 0;
  let codeStart = 0;

  const flushCode = (endIdx) => {
    if (endIdx > codeStart) {
      segments.push({ isString: false, text: line.slice(codeStart, endIdx), start: codeStart, end: endIdx });
    }
  };

  while (i < line.length) {
    // 1. Check raw triple-quoted string r"""...""" or triple-quoted string """..."""
    const isRawTriple =
      line[i] === "r" &&
      i + 3 < line.length &&
      line.slice(i + 1, i + 4) === '"""' &&
      (i === 0 || !/[a-zA-Z0-9_]/.test(line[i - 1]));
    const isTriple = !isRawTriple && i + 2 < line.length && line.slice(i, i + 3) === '"""';

    if (isRawTriple || isTriple) {
      flushCode(i);
      const openLen = isRawTriple ? 4 : 3;
      const closeIdx = line.indexOf('"""', i + openLen);
      if (closeIdx !== -1) {
        const endIdx = closeIdx + 3;
        segments.push({ isString: true, text: line.slice(i, endIdx), start: i, end: endIdx });
        i = endIdx;
        codeStart = i;
        continue;
      } else {
        segments.push({ isString: true, text: line.slice(i), start: i, end: line.length });
        opensMultiline = '"""';
        i = line.length;
        codeStart = i;
        break;
      }
    }

    // 2. Check raw strings r#"..."#, r##"..."##, or r"..."
    if (
      line[i] === "r" &&
      i + 1 < line.length &&
      (line[i + 1] === '"' || line[i + 1] === "#") &&
      (i === 0 || !/[a-zA-Z0-9_]/.test(line[i - 1]))
    ) {
      let hashes = 0;
      let scan = i + 1;
      while (scan < line.length && line[scan] === "#") {
        hashes += 1;
        scan += 1;
      }
      if (scan < line.length && line[scan] === '"') {
        flushCode(i);
        const closeSeq = '"' + "#".repeat(hashes);
        let closeIdx = line.indexOf(closeSeq, scan + 1);
        if (closeIdx !== -1) {
          // If nested raw string delimiter immediately follows (e.g. r#"..."#"#), consume outer closeSeq
          while (
            hashes > 0 &&
            line.slice(closeIdx + closeSeq.length, closeIdx + 2 * closeSeq.length) === closeSeq
          ) {
            closeIdx += closeSeq.length;
          }
          const endIdx = closeIdx + closeSeq.length;
          segments.push({ isString: true, text: line.slice(i, endIdx), start: i, end: endIdx });
          i = endIdx;
          codeStart = i;
          continue;
        } else {
          segments.push({ isString: true, text: line.slice(i), start: i, end: line.length });
          if (hashes > 0) {
            opensMultiline = closeSeq;
          } else {
            unclosedQuote = '"';
          }
          i = line.length;
          codeStart = i;
          break;
        }
      }
    }

    // 3. Check comments (# or //) outside strings
    if (line[i] === "#") {
      flushCode(i);
      comment = line.slice(i);
      codeStart = line.length;
      break;
    }
    if (line[i] === "/" && i + 1 < line.length && line[i + 1] === "/") {
      if (i === 0 || /\s/.test(line[i - 1])) {
        flushCode(i);
        comment = line.slice(i);
        codeStart = line.length;
        break;
      }
    }

    // 4. Check standard single-line double or single quoted strings
    if (line[i] === '"' || line[i] === "'") {
      const q = line[i];
      flushCode(i);
      let end = i + 1;
      let closed = false;
      while (end < line.length) {
        if (line[end] === "\\") {
          end += 2;
          continue;
        }
        if (line[end] === q) {
          end += 1;
          closed = true;
          break;
        }
        end += 1;
      }
      segments.push({ isString: true, text: line.slice(i, end), start: i, end });
      if (!closed) {
        unclosedQuote = q;
      }
      i = end;
      codeStart = i;
      continue;
    }

    i += 1;
  }

  flushCode(line.length);
  return { segments, comment, opensMultiline, unclosedQuote };
}

function splitCodeAndComment(trimmedLine) {
  const { segments, comment, opensMultiline } = tokenizeLineSegments(trimmedLine);
  const code = segments
    .map((s) => s.text)
    .join("")
    .replace(/\s+$/, "");
  return { code, comment, opensMultiline };
}

function normalizeCodeSpacing(codePart) {
  if (!codePart) return "";
  const { segments } = tokenizeLineSegments(codePart);

  let rebuilt = segments
    .map((seg, idx) => {
      if (seg.isString) return seg.text;
      let s = seg.text;
      if (idx === 0) {
        s = s.replace(
          /^(pub\s+)?(fn|struct|enum|trait|impl|let|mut|const|type|if|elif|else\s+if|while|for|match|ret|return|import|module)\s{2,}/,
          (_, p1, p2) => (p1 ? "pub " : "") + p2.replace(/\s+/g, " ") + " "
        );
        s = s.replace(/^pub\s{2,}/, "pub ");
      }
      // Collapse multiple spaces after commas
      s = s.replace(/,\s*(\S)/g, ", $1");
      // Collapse multiple spaces around ) ->
      s = s.replace(/\)\s*->\s*/g, "): ");
      return s;
    })
    .join("");

  // Remove stray spaces before trailing block colon
  if (
    /^(?:pub\s+)?(?:fn|struct|enum|trait|impl|if|elif|else\s+if|else|while|for|match|@agent|@capabilities)\b/.test(
      rebuilt
    ) &&
    /\s+:$/.test(rebuilt)
  ) {
    rebuilt = rebuilt.replace(/\s+:$/, ":");
  }

  return rebuilt;
}

function countBracketDelta(codePart) {
  if (!codePart) return 0;
  const { segments } = tokenizeLineSegments(codePart);
  let delta = 0;
  for (const seg of segments) {
    if (seg.isString) continue;
    for (let i = 0; i < seg.text.length; i++) {
      const ch = seg.text[i];
      if (ch === "(" || ch === "[" || ch === "{") delta += 1;
      else if (ch === ")" || ch === "]" || ch === "}") delta -= 1;
    }
  }
  return delta;
}

function findNextCodeLineTrimmed(lines, fromIdx) {
  for (let k = fromIdx; k < lines.length; k++) {
    const t = lines[k].trim();
    if (t.length === 0 || t.startsWith("#") || t.startsWith("//")) continue;
    return t;
  }
  return "";
}

function isContractClauseLine(codeTrimmed) {
  return /^(?:requires|require|ensures|ensure|decreases|decrease|invariant|where)\b/.test(
    codeTrimmed
  );
}

function isContinuationLineEnd(codeTrimmed) {
  return (
    !codeTrimmed.endsWith(":") &&
    !codeTrimmed.endsWith("=>") &&
    /(\band|\bor|\+|-|\*|\/|,|=|\|>)$/.test(codeTrimmed)
  );
}

function isBlockOpenerCode(codeTrimmed, nextCodeLine) {
  if (!codeTrimmed) return false;
  if (codeTrimmed.endsWith(":") || codeTrimmed.endsWith("=>")) return true;
  if (
    /^(?:pub\s+)?(?:async\s+)?fn\s+[A-Za-z_][A-Za-z0-9_]*\s*\(/.test(codeTrimmed) &&
    isContractClauseLine(nextCodeLine)
  ) {
    return true;
  }
  return false;
}

function beautifyAiplSource(text) {
  const normalized = String(text || "").replace(/\r\n/g, "\n");
  const lines = normalized.split("\n");
  const out = [];
  // Stack of [rawIndentCols, logicalLevel, isConditionalBlock]
  const indentStack = [[0, 0, false]];
  let prevOpenedBlock = false;
  let prevLineIsContinuation = false;
  let blankCount = 0;
  let emittedAny = false;
  let inMultiline = false;
  let multilineClose = "";
  // Stack of bracket frames: { count, innerLevel, closeLevel }
  const bracketFrames = [];

  for (let lineIdx = 0; lineIdx < lines.length; lineIdx++) {
    const rawLine = lines[lineIdx];

    if (inMultiline) {
      out.push(rawLine);
      if (multilineClose.length > 0 && rawLine.includes(multilineClose)) {
        const closePos = rawLine.indexOf(multilineClose) + multilineClose.length;
        const tail = rawLine.slice(closePos);
        inMultiline = false;
        multilineClose = "";
        if (tail.trim().length > 0) {
          const tailDelta = countBracketDelta(tail);
          if (tailDelta < 0 && bracketFrames.length > 0) {
            let rem = -tailDelta;
            while (rem > 0 && bracketFrames.length > 0) {
              const top = bracketFrames[bracketFrames.length - 1];
              if (top.count <= rem) {
                rem -= top.count;
                bracketFrames.pop();
              } else {
                top.count -= rem;
                rem = 0;
              }
            }
          }
        }
      }
      emittedAny = true;
      continue;
    }

    const trimmedEnd = rawLine.replace(/[ \t]+$/, "");
    const trimmed = trimmedEnd.replace(/^[ \t]+/, "");

    if (trimmed.length === 0) {
      if (emittedAny) {
        blankCount += 1;
      }
      continue;
    }

    if (blankCount > 0 && emittedAny) {
      out.push("");
      blankCount = 0;
    }

    let rawIndent = 0;
    for (let i = 0; i < trimmedEnd.length; i++) {
      if (trimmedEnd[i] === " ") rawIndent += 1;
      else if (trimmedEnd[i] === "\t") rawIndent += 2;
      else break;
    }

    const isComment = trimmed.startsWith("#") || trimmed.startsWith("//");
    const {
      code: rawCode,
      comment,
      opensMultiline: lineOpensMultiline,
    } = isComment
      ? { code: "", comment: trimmed, opensMultiline: null }
      : splitCodeAndComment(trimmed);

    const formattedCode = isComment ? "" : normalizeCodeSpacing(rawCode);
    const rebuiltTrimmed = isComment
      ? trimmed
      : comment
      ? `${formattedCode} ${comment}`
      : formattedCode;

    // Handle multi-line bracket continuations (e.g. multi-line import { ... } or struct/call args)
    if (bracketFrames.length > 0) {
      const topFrame = bracketFrames[bracketFrames.length - 1];
      const leadingCloseMatch = trimmed.match(/^[)\]}]+/);
      const level = leadingCloseMatch ? topFrame.closeLevel : topFrame.innerLevel;
      out.push("  ".repeat(level) + rebuiltTrimmed);
      emittedAny = true;
      if (!isComment) {
        const bDelta = countBracketDelta(formattedCode);
        if (bDelta > 0) {
          bracketFrames.push({
            count: bDelta,
            innerLevel: level + 1,
            closeLevel: level,
          });
        } else if (bDelta < 0) {
          let rem = -bDelta;
          while (rem > 0 && bracketFrames.length > 0) {
            const top = bracketFrames[bracketFrames.length - 1];
            if (top.count <= rem) {
              rem -= top.count;
              bracketFrames.pop();
            } else {
              top.count -= rem;
              rem = 0;
            }
          }
        }
        if (bracketFrames.length === 0) {
          const nextCode = findNextCodeLineTrimmed(lines, lineIdx + 1);
          prevOpenedBlock = isBlockOpenerCode(formattedCode, nextCode);
          prevLineIsContinuation = isContinuationLineEnd(formattedCode);
        }
        if (lineOpensMultiline) {
          inMultiline = true;
          multilineClose = lineOpensMultiline;
        }
      }
      continue;
    }

    const last = indentStack[indentStack.length - 1];
    let level = last[1];
    const startsWithContinuationOp =
      !isComment && (formattedCode.startsWith(".") || formattedCode.startsWith("|>"));
    const isContractLine = !isComment && isContractClauseLine(formattedCode);

    if (isComment) {
      if (rawIndent > last[0]) {
        level = prevOpenedBlock ? last[1] + 1 : last[1];
      } else {
        level = 0;
        for (let idx = indentStack.length - 1; idx >= 0; idx--) {
          if (indentStack[idx][0] <= rawIndent) {
            level = indentStack[idx][1];
            break;
          }
        }
      }
    } else {
      const isElseOrElif = /^(?:elif\b|else\s+if\b|else\s*:)/.test(formattedCode);
      if (isElseOrElif) {
        while (indentStack.length > 1) {
          const top = indentStack[indentStack.length - 1];
          if (top[0] > rawIndent && !(top[2] && indentStack.length === 2)) {
            indentStack.pop();
          } else {
            break;
          }
        }
        level = indentStack[indentStack.length - 1][1];
      } else if (prevLineIsContinuation || startsWithContinuationOp) {
        if (rawIndent > last[0]) {
          const contOffset = rawIndent >= last[0] + 4 ? 2 : 1;
          level = last[1] + contOffset;
        } else {
          level = last[1];
        }
      } else if (rawIndent > last[0]) {
        if (prevOpenedBlock) {
          level = last[1] + 1;
          const isCond = /^(?:if|elif|else\s+if|while|for)\b/.test(formattedCode);
          indentStack.push([rawIndent, level, isCond]);
        } else {
          // Misaligned sibling line (indented without a preceding ':' or '=>' block opener) -> snap to current block level
          level = last[1];
        }
      } else if (rawIndent < last[0]) {
        if (prevOpenedBlock && rawIndent === last[0]) {
          level = last[1] + 1;
        } else {
          while (
            indentStack.length > 1 &&
            indentStack[indentStack.length - 1][0] > rawIndent
          ) {
            indentStack.pop();
          }
          level = indentStack[indentStack.length - 1][1];
        }
      } else if (prevOpenedBlock && rawIndent === last[0] && rawIndent > 0 && !isContractLine) {
        // Line immediately after ':' had same raw indent by mistake
        level = last[1] + 1;
        const isCond = /^(?:if|elif|else\s+if|while|for)\b/.test(formattedCode);
        indentStack.push([rawIndent + 2, level, isCond]);
      } else {
        level = last[1];
      }
    }

    out.push("  ".repeat(level) + rebuiltTrimmed);
    emittedAny = true;

    if (!isComment) {
      const bDelta = countBracketDelta(formattedCode);
      if (bDelta > 0) {
        bracketFrames.push({
          count: bDelta,
          innerLevel: level + 1,
          closeLevel: level,
        });
        prevOpenedBlock = false;
        prevLineIsContinuation = false;
      } else {
        const nextCode = findNextCodeLineTrimmed(lines, lineIdx + 1);
        if (isContractLine) {
          // Contract lines are already at fnLevel + 1 on indentStack; body stays at fnLevel + 1
          prevOpenedBlock = false;
        } else {
          prevOpenedBlock = isBlockOpenerCode(formattedCode, nextCode);
        }
        prevLineIsContinuation = isContinuationLineEnd(formattedCode);
        if (/^(?:if|elif|else\s+if|while|for)\b/.test(formattedCode)) {
          indentStack[indentStack.length - 1][2] = true;
        }
      }

      if (lineOpensMultiline) {
        inMultiline = true;
        multilineClose = lineOpensMultiline;
      }
    }
  }

  return out.join("\n") + (out.length > 0 ? "\n" : "");
}

function formatDocumentText(text) {
  let working = String(text || "");
  const bin = getAiplBin();
  try {
    const res = spawnSync(bin, ["fmt", "--stdin"], {
      input: working,
      encoding: "utf8",
      timeout: 5000,
    });
    if (res && res.status === 0 && typeof res.stdout === "string" && res.stdout.length > 0) {
      working = res.stdout;
    }
  } catch (_) {
    // Ignore spawn errors when binary is not on PATH; beautifyAiplSource handles full formatting
  }
  return beautifyAiplSource(working);
}

// ============================================================================
// 3. Live Alignment & Syntax Error Validator (`validateAiplDocument`)
// ============================================================================

function stripStringsAndComments(line) {
  const { segments, opensMultiline, unclosedQuote } = tokenizeLineSegments(line);
  let result = "";
  for (const seg of segments) {
    if (!seg.isString) {
      result += seg.text;
    } else {
      const len = seg.text.length;
      result += '"' + " ".repeat(Math.max(0, len - 2)) + (len >= 2 ? '"' : "");
    }
  }
  return {
    stripped: result.replace(/\s+$/, ""),
    unclosedQuote,
    opensMultiline,
  };
}

function validateAiplDocument(text) {
  const normalized = String(text || "").replace(/\r\n/g, "\n");
  const lines = normalized.split("\n");
  const diagnostics = [];

  const indentStack = [0];
  let prevOpenedBlock = false;
  let prevLineIsContinuation = false;
  let prevOpenerLine = -1;
  let prevOpenerIndent = 0;
  let inMultiline = false;
  let multilineClose = "";
  let bracketDepth = 0;
  const openBracketStack = []; // { char, line, col }

  const BAD_KEYWORDS = {
    function: "Use 'fn' instead of 'function' to declare functions in AIPL",
    def: "Use 'fn' instead of 'def' to declare functions in AIPL",
    var: "Use 'let' (immutable) or 'mut' (mutable) instead of 'var' in AIPL",
    elsif: "Use 'elif' or 'else if' instead of 'elsif' in AIPL",
    elseif: "Use 'elif' or 'else if' instead of 'elseif' in AIPL",
  };

  const BAD_TYPES = {
    string: "str",
    boolean: "bool",
    number: "float",
    integer: "int",
  };

  for (let i = 0; i < lines.length; i++) {
    const rawLine = lines[i];

    // Handle inside multiline string
    if (inMultiline) {
      if (multilineClose.length > 0 && rawLine.includes(multilineClose)) {
        const closePos = rawLine.indexOf(multilineClose) + multilineClose.length;
        const tail = rawLine.slice(closePos);
        inMultiline = false;
        multilineClose = "";
        if (tail.trim().length > 0) {
          const { stripped: tailStripped } = stripStringsAndComments(tail);
          const matchPairs = { ")": "(", "]": "[", "}": "{" };
          for (let c = 0; c < tailStripped.length; c++) {
            const ch = tailStripped[c];
            if (ch === "(" || ch === "[" || ch === "{") {
              openBracketStack.push({ char: ch, line: i, col: closePos + c });
              bracketDepth += 1;
            } else if (ch === ")" || ch === "]" || ch === "}") {
              if (
                openBracketStack.length > 0 &&
                openBracketStack[openBracketStack.length - 1].char === matchPairs[ch]
              ) {
                openBracketStack.pop();
                bracketDepth = Math.max(0, bracketDepth - 1);
              }
            }
          }
        }
      }
      continue;
    }

    const trimmed = rawLine.trim();
    if (trimmed.length === 0) {
      continue;
    }

    // Measure leading whitespace
    const leadingMatch = rawLine.match(/^[ \t]*/);
    const leadingWs = leadingMatch ? leadingMatch[0] : "";
    const hasTab = leadingWs.includes("\t");
    let indentCols = 0;
    for (let c = 0; c < leadingWs.length; c++) {
      indentCols += leadingWs[c] === "\t" ? 2 : 1;
    }

    // 1. Check tab characters in indentation
    if (hasTab) {
      diagnostics.push({
        line: i,
        startCol: 0,
        endCol: Math.max(1, leadingWs.length),
        severity: "warning",
        code: "AIPL_ALIGN_TAB",
        category: "alignment",
        message: "Tab character used in indentation; AIPL requires 2-space indentation",
      });
    }

    // 2. Check odd number of leading spaces (not a multiple of 2) when outside multi-line brackets
    if (!hasTab && bracketDepth === 0 && leadingWs.length % 2 !== 0) {
      diagnostics.push({
        line: i,
        startCol: 0,
        endCol: Math.max(1, leadingWs.length),
        severity: "warning",
        code: "AIPL_ALIGN_ODD_INDENT",
        category: "alignment",
        message: `Misaligned indentation: found ${leadingWs.length} space(s), expected a multiple of 2 spaces`,
      });
    }

    const isCommentLine = trimmed.startsWith("#") || trimmed.startsWith("//");
    if (isCommentLine) {
      continue;
    }

    const { stripped, unclosedQuote, opensMultiline } = stripStringsAndComments(rawLine);
    const strippedTrimmed = stripped.trim();
    const opensMultilineHere = Boolean(opensMultiline);
    if (opensMultilineHere) {
      inMultiline = true;
      multilineClose = opensMultiline;
    }

    const startsWithContinuationOp =
      strippedTrimmed.startsWith(".") || strippedTrimmed.startsWith("|>");
    const isContractLine = isContractClauseLine(strippedTrimmed);
    const nextCodeTrimmed = findNextCodeLineTrimmed(lines, i + 1);
    const hasFollowingContract = isContractClauseLine(nextCodeTrimmed);

    // Check structural block indentation when outside multi-line brackets
    if (bracketDepth === 0 && !prevLineIsContinuation && !startsWithContinuationOp) {
      const currentIndent = indentStack[indentStack.length - 1];
      if (prevOpenedBlock) {
        if (indentCols <= prevOpenerIndent) {
          diagnostics.push({
            line: i,
            startCol: 0,
            endCol: Math.max(1, rawLine.length),
            severity: "error",
            code: "AIPL_ALIGN_MISSING_INDENT",
            category: "alignment",
            message: `Expected an indented block (${prevOpenerIndent + 2} spaces) after ':' on line ${prevOpenerLine + 1}`,
          });
        } else if (indentCols > prevOpenerIndent + 2 && indentCols % 2 === 0) {
          diagnostics.push({
            line: i,
            startCol: 0,
            endCol: Math.max(1, leadingWs.length),
            severity: "warning",
            code: "AIPL_ALIGN_DEEP_INDENT",
            category: "alignment",
            message: `Inconsistent block indentation: expected ${prevOpenerIndent + 2} spaces after ':', found ${indentCols} spaces`,
          });
        }
        if (indentCols > currentIndent) {
          indentStack.push(indentCols);
        }
      } else {
        if (indentCols > currentIndent) {
          diagnostics.push({
            line: i,
            startCol: 0,
            endCol: Math.max(1, leadingWs.length || rawLine.length),
            severity: "error",
            code: "AIPL_ALIGN_UNEXPECTED_INDENT",
            category: "alignment",
            message: `Unexpected indentation (${indentCols} spaces): previous line did not open a ':' block (expected ${currentIndent} spaces)`,
          });
          indentStack.push(indentCols);
        } else if (indentCols < currentIndent) {
          while (indentStack.length > 1 && indentStack[indentStack.length - 1] > indentCols) {
            indentStack.pop();
          }
          if (indentStack[indentStack.length - 1] !== indentCols) {
            diagnostics.push({
              line: i,
              startCol: 0,
              endCol: Math.max(1, leadingWs.length),
              severity: "warning",
              code: "AIPL_ALIGN_DANGLING_DEDENT",
              category: "alignment",
              message: `Misaligned dedent (${indentCols} spaces): does not match any outer block indentation level (expected ${indentStack[indentStack.length - 1]} spaces)`,
            });
          }
        }
      }
    }

    if (unclosedQuote && !opensMultilineHere) {
      const qIdx = rawLine.lastIndexOf(unclosedQuote);
      diagnostics.push({
        line: i,
        startCol: qIdx >= 0 ? qIdx : 0,
        endCol: rawLine.length,
        severity: "error",
        code: "AIPL_SYNTAX_UNCLOSED_STRING",
        category: "syntax",
        message: `Unclosed string literal (${unclosedQuote})`,
      });
    }

    const isHeaderWithBrace =
      /^(?:pub\s+)?(?:fn|function|def|if|elif|else\s+if|else|while|for|struct|enum|trait|impl)\b/.test(
        strippedTrimmed
      ) && strippedTrimmed.endsWith("{");

    // Track bracket balance across the line (ignoring trailing block-header '{')
    const lineForBrackets = isHeaderWithBrace
      ? stripped.slice(0, stripped.lastIndexOf("{"))
      : stripped;
    const matchPairs = { ")": "(", "]": "[", "}": "{" };
    for (let c = 0; c < lineForBrackets.length; c++) {
      const ch = lineForBrackets[c];
      if (ch === "(" || ch === "[" || ch === "{") {
        openBracketStack.push({ char: ch, line: i, col: c });
        bracketDepth += 1;
      } else if (ch === ")" || ch === "]" || ch === "}") {
        if (
          openBracketStack.length === 0 ||
          openBracketStack[openBracketStack.length - 1].char !== matchPairs[ch]
        ) {
          if (ch !== "}" || strippedTrimmed !== "}") {
            diagnostics.push({
              line: i,
              startCol: c,
              endCol: c + 1,
              severity: "error",
              code: "AIPL_SYNTAX_UNBALANCED_BRACKET",
              category: "syntax",
              message: `Unmatched closing bracket '${ch}'`,
            });
          }
        } else {
          openBracketStack.pop();
          bracketDepth = Math.max(0, bracketDepth - 1);
        }
      }
    }

    // 3. Check wrongly written keywords at statement start
    const firstWordMatch = strippedTrimmed.match(/^(?:pub\s+)?([a-zA-Z_][a-zA-Z0-9_]*)\b/);
    if (firstWordMatch) {
      const word = firstWordMatch[1];
      if (Object.prototype.hasOwnProperty.call(BAD_KEYWORDS, word)) {
        const colIdx = rawLine.indexOf(word);
        diagnostics.push({
          line: i,
          startCol: colIdx >= 0 ? colIdx : leadingWs.length,
          endCol: (colIdx >= 0 ? colIdx : leadingWs.length) + word.length,
          severity: "error",
          code: "AIPL_SYNTAX_BAD_KEYWORD",
          category: "syntax",
          message: BAD_KEYWORDS[word],
        });
      }
    }

    // 4. Check null / undefined literals outside strings
    const nullMatch = stripped.match(/\b(null|undefined)\b/);
    if (nullMatch) {
      const badLit = nullMatch[1];
      const colIdx = stripped.indexOf(badLit);
      diagnostics.push({
        line: i,
        startCol: colIdx,
        endCol: colIdx + badLit.length,
        severity: "error",
        code: "AIPL_SYNTAX_BAD_LITERAL",
        category: "syntax",
        message: `Invalid literal '${badLit}'; use 'nil' or 'None' in AIPL`,
      });
    }

    // 5. Check === or !== operators
    const strictEqMatch = stripped.match(/(===|!==)/);
    if (strictEqMatch) {
      const op = strictEqMatch[1];
      const colIdx = stripped.indexOf(op);
      diagnostics.push({
        line: i,
        startCol: colIdx,
        endCol: colIdx + op.length,
        severity: "error",
        code: "AIPL_SYNTAX_BAD_OPERATOR",
        category: "syntax",
        message: `Invalid operator '${op}'; use '${op.slice(0, 2)}' in AIPL`,
      });
    }

    // 6. Check wrong primitive type names (: string, : boolean, : number, : integer)
    const badTypeRegex = /:\s*\b(string|boolean|number|integer)\b/g;
    let typeMatch;
    while ((typeMatch = badTypeRegex.exec(stripped)) !== null) {
      const badType = typeMatch[1];
      const suggested = BAD_TYPES[badType];
      const startCol = typeMatch.index + typeMatch[0].lastIndexOf(badType);
      diagnostics.push({
        line: i,
        startCol,
        endCol: startCol + badType.length,
        severity: "error",
        code: "AIPL_SYNTAX_BAD_TYPE",
        category: "syntax",
        message: `Unknown type '${badType}'; use '${suggested}' in AIPL`,
      });
    }

    // 7. Check brace block penalty or -> return type on declarations
    if (
      isHeaderWithBrace ||
      (/^(?:pub\s+)?(?:fn|function|def)\s+/.test(strippedTrimmed) &&
        strippedTrimmed.includes(") -> "))
    ) {
      diagnostics.push({
        line: i,
        startCol: leadingWs.length,
        endCol: rawLine.length,
        severity: "warning",
        code: "AIPL_W0045_BRACE_BLOCK_TOKEN_PENALTY",
        category: "syntax",
        message:
          "Prefer canonical significant indentation ':' and '): ReturnType:' over '{ ... }' or '->' syntax",
      });
    }

    // 8. Check missing colon ':' on block headers when brackets are balanced
    if (bracketDepth === 0 && !opensMultilineHere) {
      const isCompactStructOrEnum =
        /^(?:pub\s+)?(?:struct|enum)\s+[A-Za-z_][A-Za-z0-9_]*(?:\s*\[[^\]]*\])?\s*\(.*\)\s*$/.test(strippedTrimmed) ||
        /^(?:pub\s+)?enum\s+[A-Za-z_][A-Za-z0-9_]*(?:\s*\[[^\]]*\])?\s*:.+$/.test(strippedTrimmed);
      const isStructOrEnumHeader =
        /^(?:pub\s+)?(?:struct|enum|trait|impl)\s+[A-Za-z_][A-Za-z0-9_]*/.test(strippedTrimmed) &&
        !strippedTrimmed.includes("=") &&
        !isCompactStructOrEnum;
      const isFnHeader =
        /^(?:pub\s+)?(?:async\s+)?fn\s+[A-Za-z_][A-Za-z0-9_]*\s*\(/.test(strippedTrimmed) &&
        !strippedTrimmed.startsWith("extern ") &&
        !strippedTrimmed.includes("=") &&
        !hasFollowingContract;
      const isBareElse = strippedTrimmed === "else";
      const isControlHeader =
        /^(?:if|elif|else\s+if|while|for)\s+.+/.test(strippedTrimmed) &&
        !strippedTrimmed.includes(":") &&
        !/(\band|\bor|\+|-|\*|\/|,|=|\\)$/.test(strippedTrimmed);

      if (
        (isStructOrEnumHeader || isFnHeader || isBareElse || isControlHeader) &&
        !strippedTrimmed.endsWith(":") &&
        !strippedTrimmed.endsWith("{")
      ) {
        diagnostics.push({
          line: i,
          startCol: leadingWs.length,
          endCol: rawLine.length,
          severity: "error",
          code: "AIPL_SYNTAX_MISSING_COLON",
          category: "syntax",
          message: "Missing ':' at the end of block declaration/control header",
        });
      }
    }

    // Update block opener & continuation tracker for next line
    if (bracketDepth === 0) {
      const wasContinuation = prevLineIsContinuation || startsWithContinuationOp;
      const isFnWithContract =
        /^(?:pub\s+)?(?:async\s+)?fn\s+[A-Za-z_][A-Za-z0-9_]*\s*\(/.test(strippedTrimmed) &&
        hasFollowingContract;
      prevOpenedBlock =
        strippedTrimmed.endsWith(":") ||
        strippedTrimmed.endsWith("=>") ||
        isHeaderWithBrace ||
        isFnWithContract;
      prevLineIsContinuation = isContinuationLineEnd(strippedTrimmed);
      if (prevOpenedBlock) {
        prevOpenerLine = i;
        if (isContractLine) {
          // A contract line (`requires`/`ensures`) is at fnIndent + 2; the body is also at fnIndent + 2
          prevOpenerIndent = Math.max(0, indentCols - 2);
        } else if (wasContinuation) {
          // A multi-line header (`if a or\n  b:`) opens its block relative to the statement's base indent
          prevOpenerIndent = indentStack[indentStack.length - 1];
        } else {
          prevOpenerIndent = indentCols;
        }
      }
    } else {
      prevOpenedBlock = false;
      prevLineIsContinuation = false;
    }
  }

  return diagnostics;
}

// ============================================================================
// 4. Cross-File Symbol Resolution ("Go to Definition" & File Relations)
// ============================================================================

function parseAiplImports(text) {
  const normalized = String(text || "").replace(/\r\n/g, "\n");
  const lines = normalized.split("\n");
  const imports = [];

  // Mask out comment lines while preserving line offsets for multi-line regex matching
  const uncommentedLines = lines.map((l) => {
    const t = l.trim();
    if (t.startsWith("#") || t.startsWith("//")) {
      return " ".repeat(l.length);
    }
    return l;
  });
  const uncommentedText = uncommentedLines.join("\n");

  // 1. Single-line and multi-line `import { a, b as c } from "path"` (including `pub import`)
  const namedImportRegex = /\bimport\s*\{([\s\S]*?)\}\s*from\s*["']([^"']+)["']/g;
  let m;
  while ((m = namedImportRegex.exec(uncommentedText)) !== null) {
    const specBlock = m[1];
    const modulePath = m[2].trim();
    const startOffset = m.index;
    const endOffset = m.index + m[0].length;
    const startLine = uncommentedText.slice(0, startOffset).split("\n").length - 1;
    const endLine = uncommentedText.slice(0, endOffset).split("\n").length - 1;

    const specs = specBlock
      .split(",")
      .map((s) => s.replace(/\/\/.*$|#.*$/gm, "").trim())
      .filter(Boolean);

    const symbols = [];
    for (const sp of specs) {
      const asMatch = sp.match(/^([a-zA-Z_][a-zA-Z0-9_]*)\s+as\s+([a-zA-Z_][a-zA-Z0-9_]*)$/);
      if (asMatch) {
        symbols.push({ importedName: asMatch[1], localName: asMatch[2] });
      } else if (/^[a-zA-Z_][a-zA-Z0-9_]*$/.test(sp)) {
        symbols.push({ importedName: sp, localName: sp });
      }
    }

    imports.push({
      kind: "named",
      modulePath,
      symbols,
      startLine,
      endLine,
    });
  }

  // 2. Line-by-line module imports: `import std.canvas`, `import "path.aipl"`, `from "path" import a, b`
  for (let i = 0; i < lines.length; i++) {
    const line = lines[i].trim();
    if (line.startsWith("#") || line.startsWith("//")) continue;

    const dotImport = line.match(
      /^(?:pub\s+)?import\s+(std\.[a-zA-Z0-9_.]+)(?:\s+as\s+([a-zA-Z_][a-zA-Z0-9_]*))?/
    );
    if (dotImport) {
      const modPath = dotImport[1].replace(/\./g, "/");
      const leaf = modPath.split("/").pop();
      imports.push({
        kind: "module",
        modulePath: modPath,
        alias: dotImport[2] || leaf || null,
        symbols: [],
        startLine: i,
        endLine: i,
      });
      continue;
    }

    const starImport = line.match(/^(?:pub\s+)?import\s+\*\s+from\s+["']([^"']+)["']/);
    if (starImport) {
      imports.push({
        kind: "wildcard",
        modulePath: starImport[1].trim(),
        symbols: [],
        startLine: i,
        endLine: i,
      });
      continue;
    }

    const directImport = line.match(
      /^(?:pub\s+)?import\s+["']([^"']+)["'](?:\s+as\s+([a-zA-Z_][a-zA-Z0-9_]*))?/
    );
    if (directImport) {
      const rawMod = directImport[1].trim();
      const baseLeaf = path.basename(rawMod, ".aipl");
      imports.push({
        kind: "module",
        modulePath: rawMod,
        alias: directImport[2] || baseLeaf || null,
        symbols: [],
        startLine: i,
        endLine: i,
      });
      continue;
    }

    const fromImport = line.match(/^(?:pub\s+)?from\s+["']([^"']+)["']\s+import\s+(.+)$/);
    if (fromImport) {
      const modulePath = fromImport[1].trim();
      const symbols = fromImport[2]
        .split(",")
        .map((s) => s.trim())
        .filter((s) => /^[a-zA-Z_][a-zA-Z0-9_]*$/.test(s))
        .map((s) => ({ importedName: s, localName: s }));
      imports.push({
        kind: "named",
        modulePath,
        symbols,
        startLine: i,
        endLine: i,
      });
    }
  }

  return imports;
}

function resolveAiplModulePath(baseDir, rawImportPath, workspaceRoots) {
  if (!rawImportPath) return null;
  const cleanRaw = String(rawImportPath)
    .trim()
    .replace(/^["']+|["']+$/g, "");
  if (!cleanRaw) return null;

  const roots = Array.isArray(workspaceRoots) && workspaceRoots.length > 0
    ? workspaceRoots
    : getWorkspaceRoots(baseDir ? path.join(baseDir, "dummy.aipl") : undefined);

  // 1. Standard library module resolution (`std/fs`, `std.canvas`, `std/io/fs`, etc.)
  if (cleanRaw.startsWith("std/") || cleanRaw.startsWith("std.")) {
    let modName = cleanRaw.slice(4);
    if (modName.endsWith(".aipl")) {
      modName = modName.slice(0, -5);
    }
    modName = modName.replace(/\./g, "/");
    const leafName = modName.includes("/") ? modName.split("/").pop() : modName;

    const searchBases = [];
    if (baseDir) {
      let cur = path.resolve(baseDir);
      for (let d = 0; d < 6; d++) {
        if (!searchBases.includes(cur)) searchBases.push(cur);
        const parent = path.dirname(cur);
        if (parent === cur) break;
        cur = parent;
      }
    }
    for (const r of roots) {
      if (r && !searchBases.includes(r)) searchBases.push(r);
    }
    if (process.env.AIPL_STD_DIR) searchBases.push(process.env.AIPL_STD_DIR);
    if (process.env.AIPL_HOME) searchBases.push(process.env.AIPL_HOME);
    const extRoot = path.resolve(__dirname, "../..");
    if (!searchBases.includes(extRoot)) searchBases.push(extRoot);

    for (const base of searchBases) {
      const direct1 = path.join(base, "std", modName + ".aipl");
      if (fs.existsSync(direct1)) return direct1;
      const barrel1 = path.join(base, "std", modName, leafName + "_mod.aipl");
      if (fs.existsSync(barrel1)) return barrel1;
      const direct2 = path.join(base, modName + ".aipl");
      if (fs.existsSync(direct2)) return direct2;

      for (const dom of STD_DOMAINS) {
        const domCand = path.join(base, "std", dom, leafName + ".aipl");
        if (fs.existsSync(domCand)) return domCand;
      }
    }
    return null;
  }

  // 2. Relative or explicit file path resolution
  const candidateBases = [];
  if (baseDir) candidateBases.push(path.resolve(baseDir));
  for (const r of roots) {
    if (r && !candidateBases.includes(r)) candidateBases.push(r);
  }

  for (const base of candidateBases) {
    const exact = path.resolve(base, cleanRaw);
    if (fs.existsSync(exact) && fs.statSync(exact).isFile()) {
      return exact;
    }
    if (!cleanRaw.endsWith(".aipl")) {
      const withExt = path.resolve(base, cleanRaw + ".aipl");
      if (fs.existsSync(withExt) && fs.statSync(withExt).isFile()) {
        return withExt;
      }
    }
  }

  return null;
}

function extractFileSymbols(text, filePath) {
  const normalized = String(text || "").replace(/\r\n/g, "\n");
  const lines = normalized.split("\n");
  const symbols = [];

  const patterns = [
    {
      kind: "function",
      regex: /^(\s*(?:@[a-zA-Z_]+\s+)*(?:pub\s+)?(?:async\s+)?(?:extern(?:\s+"[^"]+")?\s+)?fn\s+)([a-zA-Z_][a-zA-Z0-9_]*)/,
    },
    { kind: "struct", regex: /^(\s*(?:pub\s+)?(?:struct|component)\s+)([a-zA-Z_][a-zA-Z0-9_]*)/ },
    { kind: "enum", regex: /^(\s*(?:pub\s+)?enum\s+)([a-zA-Z_][a-zA-Z0-9_]*)/ },
    { kind: "trait", regex: /^(\s*(?:pub\s+)?trait\s+)([a-zA-Z_][a-zA-Z0-9_]*)/ },
    { kind: "impl", regex: /^(\s*impl\s+)([a-zA-Z_][a-zA-Z0-9_]*)/ },
    { kind: "function", regex: /^(\s*(?:pub\s+)?(?:system|shader|ui)\s+)([a-zA-Z_][a-zA-Z0-9_]*)/ },
    { kind: "const", regex: /^(\s*(?:pub\s+)?const\s+)([a-zA-Z_][a-zA-Z0-9_]*)/ },
    { kind: "type", regex: /^(\s*(?:pub\s+)?type\s+)([a-zA-Z_][a-zA-Z0-9_]*)/ },
  ];

  for (let i = 0; i < lines.length; i++) {
    const line = lines[i];
    for (const p of patterns) {
      const m = line.match(p.regex);
      if (m) {
        const prefix = m[1];
        const name = m[2];
        const startCol = prefix.length;
        const endCol = startCol + name.length;

        // Collect preceding doc comments if any
        const docLines = [];
        let k = i - 1;
        while (k >= 0) {
          const prev = lines[k].trim();
          if (prev.startsWith("//") || prev.startsWith("#")) {
            docLines.unshift(prev.replace(/^(\/\/+|#+)\s?/, ""));
            k -= 1;
          } else {
            break;
          }
        }

        symbols.push({
          name,
          kind: p.kind,
          filePath: filePath || "",
          line: i,
          startCol,
          endCol,
          lineLength: line.length,
          signature: line.trim().replace(/:$/, ""),
          doc: docLines.join("\n"),
          isPublic: /^\s*pub\s+/.test(line),
        });
        break;
      }
    }
  }

  return symbols;
}

function getCachedFileSymbols(filePath) {
  if (!filePath || !fs.existsSync(filePath)) return [];
  try {
    const stat = fs.statSync(filePath);
    if (!stat.isFile()) return [];
    const cached = workspaceSymbolCache.get(filePath);
    if (cached && cached.mtimeMs === stat.mtimeMs) {
      return cached.symbols;
    }
    const content = fs.readFileSync(filePath, "utf8");
    const symbols = extractFileSymbols(content, filePath);
    workspaceSymbolCache.set(filePath, { mtimeMs: stat.mtimeMs, symbols });
    return symbols;
  } catch (_) {
    return [];
  }
}

function discoverWorkspaceAiplFiles(workspaceRoots, currentFilePath) {
  const roots = getWorkspaceRoots(currentFilePath);
  if (Array.isArray(workspaceRoots)) {
    for (const r of workspaceRoots) {
      if (r && !roots.includes(r)) roots.push(r);
    }
  }

  const visitedDirs = new Set();
  const aiplFiles = [];
  const IGNORE_DIRS = new Set([
    ".git",
    "node_modules",
    "__pycache__",
    ".pytest_cache",
    "dist",
    "build",
    "target",
    ".aipl",
  ]);

  function walk(dir, depth) {
    if (depth > 5 || aiplFiles.length > 600) return;
    let realDir = dir;
    try {
      realDir = fs.realpathSync(dir);
    } catch (_) {
      return;
    }
    if (visitedDirs.has(realDir)) return;
    visitedDirs.add(realDir);

    let entries = [];
    try {
      entries = fs.readdirSync(dir, { withFileTypes: true });
    } catch (_) {
      return;
    }
    for (const entry of entries) {
      if (entry.name.startsWith(".")) continue;
      const fullPath = path.join(dir, entry.name);
      if (entry.isDirectory()) {
        if (!IGNORE_DIRS.has(entry.name)) {
          walk(fullPath, depth + 1);
        }
      } else if (entry.isFile() && entry.name.endsWith(".aipl")) {
        aiplFiles.push(fullPath);
      }
    }
  }

  for (const r of roots) {
    if (r && fs.existsSync(r)) {
      walk(r, 0);
    }
  }
  return aiplFiles;
}

function extractWordAtPosition(lineText, character) {
  if (!lineText || character < 0 || character > lineText.length) return null;
  const isIdent = (ch) => /[a-zA-Z0-9_]/.test(ch);
  let start = character;
  while (start > 0 && isIdent(lineText[start - 1])) {
    start -= 1;
  }
  let end = character;
  while (end < lineText.length && isIdent(lineText[end])) {
    end += 1;
  }
  if (start === end) return null;
  const word = lineText.slice(start, end);
  if (!/^[a-zA-Z_][a-zA-Z0-9_]*$/.test(word)) return null;
  return { word, startCol: start, endCol: end };
}

function findSymbolInTargetFile(targetFilePath, symbolName, visited = new Set()) {
  if (!targetFilePath || !fs.existsSync(targetFilePath) || visited.has(targetFilePath)) {
    return null;
  }
  visited.add(targetFilePath);

  const symbols = getCachedFileSymbols(targetFilePath);
  const exact = symbols.find((s) => s.name === symbolName);
  if (exact) return exact;

  // Check transitive re-exports / imports in targetFilePath
  try {
    const content = fs.readFileSync(targetFilePath, "utf8");
    const imports = parseAiplImports(content);
    const baseDir = path.dirname(targetFilePath);
    for (const imp of imports) {
      if (imp.kind === "named") {
        const matchSym = imp.symbols.find((s) => s.localName === symbolName);
        if (matchSym) {
          const nextFile = resolveAiplModulePath(baseDir, imp.modulePath);
          if (nextFile) {
            const found = findSymbolInTargetFile(nextFile, matchSym.importedName, visited);
            if (found) return found;
          }
        }
      } else if (imp.kind === "wildcard" || imp.kind === "module") {
        const nextFile = resolveAiplModulePath(baseDir, imp.modulePath);
        if (nextFile) {
          const found = findSymbolInTargetFile(nextFile, symbolName, visited);
          if (found) return found;
        }
      }
    }
  } catch (_) {}

  return null;
}

function findSymbolDefinitionCrossFile(text, filePath, line, character, workspaceRoots) {
  const normalized = String(text || "").replace(/\r\n/g, "\n");
  const lines = normalized.split("\n");
  if (line < 0 || line >= lines.length) return [];

  const currentLine = lines[line];
  const baseDir = filePath ? path.dirname(path.resolve(filePath)) : process.cwd();
  const roots = getWorkspaceRoots(filePath);
  if (Array.isArray(workspaceRoots)) {
    for (const r of workspaceRoots) {
      if (r && !roots.includes(r)) roots.push(r);
    }
  }

  // 1. Check if cursor is on an import path string literal `from "..."` or `import "..."`
  const stringImportRegex = /(?:from|import)\s+["']([^"']+)["']/g;
  let strMatch;
  while ((strMatch = stringImportRegex.exec(currentLine)) !== null) {
    const rawMod = strMatch[1];
    const modStart = strMatch.index + strMatch[0].indexOf(rawMod);
    const modEnd = modStart + rawMod.length;
    if (character >= modStart - 1 && character <= modEnd + 1) {
      const resolved = resolveAiplModulePath(baseDir, rawMod, roots);
      if (resolved) {
        return [
          {
            name: rawMod,
            kind: "module",
            filePath: resolved,
            line: 0,
            startCol: 0,
            endCol: 0,
            signature: `module ${path.basename(resolved)}`,
            doc: "",
          },
        ];
      }
    }
  }

  // Also check `import std.xxx`
  const stdDotMatch = currentLine.match(/^\s*(?:pub\s+)?import\s+(std\.[a-zA-Z0-9_.]+)/);
  if (stdDotMatch) {
    const rawMod = stdDotMatch[1];
    const modStart = currentLine.indexOf(rawMod);
    const modEnd = modStart + rawMod.length;
    if (character >= modStart && character <= modEnd) {
      const resolved = resolveAiplModulePath(baseDir, rawMod, roots);
      if (resolved) {
        return [
          {
            name: rawMod,
            kind: "module",
            filePath: resolved,
            line: 0,
            startCol: 0,
            endCol: 0,
            signature: `module ${rawMod}`,
            doc: "",
          },
        ];
      }
    }
  }

  const wordInfo = extractWordAtPosition(currentLine, character);
  if (!wordInfo) return [];
  const word = wordInfo.word;

  const imports = parseAiplImports(normalized);

  // 1b. Check qualified module access `alias.member` (e.g. `math.cos` from `import std.math as math`)
  const prefixBeforeWord = currentLine.slice(0, wordInfo.startCol);
  const qualMatch = prefixBeforeWord.match(/([a-zA-Z_][a-zA-Z0-9_]*)\.\s*$/);
  if (qualMatch) {
    const qualifier = qualMatch[1];
    for (const imp of imports) {
      if (imp.kind === "module" && imp.alias === qualifier) {
        const targetPath = resolveAiplModulePath(baseDir, imp.modulePath, roots);
        if (targetPath) {
          const targetSym = findSymbolInTargetFile(targetPath, word);
          if (targetSym) return [targetSym];
          return [
            {
              name: word,
              kind: "function",
              filePath: targetPath,
              line: 0,
              startCol: 0,
              endCol: 0,
              signature: `imported from ${imp.modulePath}`,
              doc: "",
            },
          ];
        }
      }
    }
  }

  // 1c. Check if word itself is a module alias (`import std.math as math` -> clicking `math` in `math.cos`)
  for (const imp of imports) {
    if (imp.kind === "module" && imp.alias === word) {
      const targetPath = resolveAiplModulePath(baseDir, imp.modulePath, roots);
      if (targetPath) {
        return [
          {
            name: word,
            kind: "module",
            filePath: targetPath,
            line: 0,
            startCol: 0,
            endCol: 0,
            signature: `module ${imp.modulePath}`,
            doc: "",
          },
        ];
      }
    }
  }

  // 2. Check if word is explicitly imported via `import { ... } from "..."`
  for (const imp of imports) {
    if (imp.kind === "named") {
      const symSpec = imp.symbols.find((s) => s.localName === word || s.importedName === word);
      if (symSpec) {
        const targetPath = resolveAiplModulePath(baseDir, imp.modulePath, roots);
        if (targetPath) {
          const targetSym = findSymbolInTargetFile(targetPath, symSpec.importedName);
          if (targetSym) {
            return [targetSym];
          }
          // Even if symbol regex didn't match (e.g. intrinsic), jump to the imported file
          return [
            {
              name: symSpec.importedName,
              kind: "function",
              filePath: targetPath,
              line: 0,
              startCol: 0,
              endCol: 0,
              signature: `imported from ${imp.modulePath}`,
              doc: "",
            },
          ];
        }
      }
    }
  }

  // 3. Check if word is defined in the current document (top-level fn, struct, enum, trait, const, type)
  const localSymbols = extractFileSymbols(normalized, filePath ? path.resolve(filePath) : "");
  const sameFileSym = localSymbols.find((s) => s.name === word);
  if (sameFileSym) {
    return [sameFileSym];
  }

  // 4. Check local variable / parameter binding (`let word`, `mut word`, `for word in`, or fn param) within enclosing function
  const isCallSite = /^\s*\(/.test(currentLine.slice(wordInfo.endCol));
  if (!isCallSite) {
    for (let i = line; i >= 0; i--) {
      const l = lines[i];
      const letMatch = l.match(new RegExp(`^(\\s*(?:let|mut|for)\\s+)(${word})\\b`));
      if (letMatch) {
        const startCol = letMatch[1].length;
        return [
          {
            name: word,
            kind: "variable",
            filePath: filePath ? path.resolve(filePath) : "",
            line: i,
            startCol,
            endCol: startCol + word.length,
            signature: l.trim().replace(/:$/, ""),
            doc: "",
          },
        ];
      }
      if (/^\s*(?:pub\s+)?(?:async\s+)?fn\s+[a-zA-Z_][a-zA-Z0-9_]*\s*\(/.test(l)) {
        const paramRegex = new RegExp(`[(,\\s](?:mut\\s+)?(${word})\\s*:`);
        const pm = l.match(paramRegex);
        if (pm) {
          const pCol = l.indexOf(pm[1], l.indexOf("("));
          return [
            {
              name: word,
              kind: "variable",
              filePath: filePath ? path.resolve(filePath) : "",
              line: i,
              startCol: pCol >= 0 ? pCol : 0,
              endCol: (pCol >= 0 ? pCol : 0) + word.length,
              signature: l.trim().replace(/:$/, ""),
              doc: "",
            },
          ];
        }
        break; // Do not cross into earlier functions for local variables
      }
    }
  }

  // 5. Check module-level imports in current file (`import std.math`, `import "./helpers.aipl"`)
  for (const imp of imports) {
    if (imp.kind === "module") {
      const targetPath = resolveAiplModulePath(baseDir, imp.modulePath, roots);
      if (targetPath) {
        const targetSym = findSymbolInTargetFile(targetPath, word);
        if (targetSym) {
          return [targetSym];
        }
      }
    }
  }

  // 6. Search across all `.aipl` files in the workspace / project directory!
  const allFiles = discoverWorkspaceAiplFiles(roots, filePath);
  const matches = [];
  const normCurrent = filePath ? path.resolve(filePath) : "";

  for (const candidateFile of allFiles) {
    if (path.resolve(candidateFile) === normCurrent) continue;
    const fileSyms = getCachedFileSymbols(candidateFile);
    for (const s of fileSyms) {
      if (s.name === word) {
        matches.push(s);
      }
    }
  }

  if (matches.length > 0) {
    // Prioritize: (a) same directory, (b) `pub` declarations, (c) non-test files
    matches.sort((a, b) => {
      const aSameDir = path.dirname(a.filePath) === baseDir ? 1 : 0;
      const bSameDir = path.dirname(b.filePath) === baseDir ? 1 : 0;
      if (aSameDir !== bSameDir) return bSameDir - aSameDir;
      if (a.isPublic !== b.isPublic) return a.isPublic ? -1 : 1;
      const aIsTest = a.filePath.includes("/tests/") ? 1 : 0;
      const bIsTest = b.filePath.includes("/tests/") ? 1 : 0;
      return aIsTest - bIsTest;
    });
    return matches;
  }

  return [];
}

// ============================================================================
// 5. LSP JSON-RPC Communication & Diagnostic Merging
// ============================================================================

function sendRpc(method, params, id) {
  if (!lspProcess || !lspProcess.stdin || !lspProcess.stdin.writable) {
    return;
  }
  const payload = {
    jsonrpc: "2.0",
    method,
  };
  if (params !== undefined) {
    payload.params = params;
  }
  if (id !== undefined) {
    payload.id = id;
  }
  const json = JSON.stringify(payload);
  const header = `Content-Length: ${Buffer.byteLength(json, "utf8")}\r\n\r\n`;
  try {
    // The trailing "\n" is required: `aipl lsp` reads stdin line-by-line (readLine) and ignores Content-Length, so
    // the JSON body must be terminated by a newline to be dispatched before the next message arrives.
    lspProcess.stdin.write(header + json + "\n");
  } catch (_) {}
}

const LSP_REQUEST_TIMEOUT_MS = 8000;
const LSP_DOCUMENT_SYMBOL_TIMEOUT_MS = 1500;

function sendRequest(method, params, timeoutMs) {
  const id = nextRequestId++;
  return new Promise((resolve, reject) => {
    if (!lspProcess || !lspProcess.stdin || !lspProcess.stdin.writable) {
      return reject(new Error("LSP process not running"));
    }
    // A hung/crashed daemon must never leave hover/definition providers awaiting forever
    const timer = setTimeout(() => {
      if (pendingRequests.has(id)) {
        pendingRequests.delete(id);
        reject(new Error(`LSP request '${method}' timed out`));
      }
    }, timeoutMs || LSP_REQUEST_TIMEOUT_MS);
    if (timer && typeof timer.unref === "function") timer.unref();
    pendingRequests.set(id, {
      resolve: (v) => { clearTimeout(timer); resolve(v); },
      reject: (e) => { clearTimeout(timer); reject(e); },
    });
    sendRpc(method, params, id);
  });
}

function rejectAllPendingRequests(reason) {
  for (const pending of pendingRequests.values()) {
    try {
      pending.reject(new Error(reason));
    } catch (_) {}
  }
  pendingRequests.clear();
}

function refreshMergedDiagnostics(uri) {
  if (!vscode || !diagCollection) return;
  const key = uri.toString();
  const lspDiags = lspDiagnosticsByUri.get(key) || [];
  const localDiags = localDiagnosticsByUri.get(key) || [];
  const seen = new Set();
  const combined = [];

  for (const d of [...localDiags, ...lspDiags]) {
    const sig = `${d.range.start.line}:${d.code || ""}:${d.message}`;
    if (!seen.has(sig)) {
      seen.add(sig);
      combined.push(d);
    }
  }
  diagCollection.set(uri, combined);
}

function updateDocumentValidationAndDecorations(document) {
  if (!vscode || !document || document.languageId !== "aipl") return;

  const cfg = vscode.workspace.getConfiguration("aipl");
  const highlightMisaligned = cfg.get("highlightMisalignedCode") !== false;
  const highlightSyntax = cfg.get("highlightSyntaxErrors") !== false;

  const rawIssues = validateAiplDocument(document.getText());
  const vsDiags = [];
  const misalignedDecorations = [];
  const syntaxDecorations = [];

  for (const issue of rawIssues) {
    if (issue.category === "alignment" && !highlightMisaligned) continue;
    if (issue.category === "syntax" && !highlightSyntax) continue;

    const range = new vscode.Range(
      new vscode.Position(issue.line, issue.startCol),
      new vscode.Position(issue.line, Math.max(issue.startCol + 1, issue.endCol))
    );

    let severity = vscode.DiagnosticSeverity.Error;
    if (issue.severity === "warning") severity = vscode.DiagnosticSeverity.Warning;
    else if (issue.severity === "info") severity = vscode.DiagnosticSeverity.Information;

    const diag = new vscode.Diagnostic(range, issue.message, severity);
    diag.source = issue.category === "alignment" ? "aipl-align" : "aipl-syntax";
    diag.code = issue.code;
    vsDiags.push(diag);

    if (issue.category === "alignment") {
      misalignedDecorations.push({
        range,
        hoverMessage: new vscode.MarkdownString(`**AIPL Alignment (${issue.code})**: ${issue.message}\n\n*Tip: Press \`Shift+Alt+F\` to beautify and align code.*`),
      });
    } else {
      syntaxDecorations.push({
        range,
        hoverMessage: new vscode.MarkdownString(`**AIPL Syntax (${issue.code})**: ${issue.message}`),
      });
    }
  }

  localDiagnosticsByUri.set(document.uri.toString(), vsDiags);
  refreshMergedDiagnostics(document.uri);

  if (vscode.window && Array.isArray(vscode.window.visibleTextEditors)) {
    for (const editor of vscode.window.visibleTextEditors) {
      if (editor.document.uri.toString() === document.uri.toString()) {
        if (misalignedDecorationType) {
          editor.setDecorations(misalignedDecorationType, misalignedDecorations);
        }
        if (syntaxErrorDecorationType) {
          editor.setDecorations(syntaxErrorDecorationType, syntaxDecorations);
        }
      }
    }
  }
}

function sendDidOpen(document) {
  if (document.languageId !== "aipl") return;
  updateDocumentValidationAndDecorations(document);
  sendRpc("textDocument/didOpen", {
    textDocument: {
      uri: document.uri.toString(),
      languageId: "aipl",
      version: document.version,
      text: document.getText(),
    },
  });
}

function sendDidChange(document) {
  if (document.languageId !== "aipl") return;
  if (document.uri && document.uri.fsPath) {
    workspaceSymbolCache.delete(document.uri.fsPath);
  }
  updateDocumentValidationAndDecorations(document);
  sendRpc("textDocument/didChange", {
    textDocument: {
      uri: document.uri.toString(),
      version: document.version,
    },
    contentChanges: [
      {
        text: document.getText(),
      },
    ],
  });
}

function handleLspMessage(msg) {
  if (!msg || !vscode) return;

  if (msg.id !== undefined && pendingRequests.has(msg.id)) {
    const pending = pendingRequests.get(msg.id);
    pendingRequests.delete(msg.id);
    if (msg.error) {
      pending.reject(new Error(msg.error.message || "LSP request failed"));
    } else {
      pending.resolve(msg.result);
    }
    return;
  }

  if (msg.method === "textDocument/publishDiagnostics" && msg.params && diagCollection) {
    const rawUri = msg.params.uri;
    const uri = vscode.Uri.parse(rawUri);
    const rawDiags = msg.params.diagnostics || [];
    const diagnostics = rawDiags.map((d) => {
      const start = new vscode.Position(
        d.range && d.range.start ? d.range.start.line : 0,
        d.range && d.range.start ? d.range.start.character : 0
      );
      const end = new vscode.Position(
        d.range && d.range.end ? d.range.end.line : start.line,
        d.range && d.range.end ? d.range.end.character : start.character
      );
      const range = new vscode.Range(start, end);
      let severity = vscode.DiagnosticSeverity.Error;
      if (d.severity === 2) severity = vscode.DiagnosticSeverity.Warning;
      else if (d.severity === 3) severity = vscode.DiagnosticSeverity.Information;
      else if (d.severity === 4) severity = vscode.DiagnosticSeverity.Hint;

      const diag = new vscode.Diagnostic(range, d.message || "Diagnostic", severity);
      if (d.source) diag.source = d.source;
      if (d.code) diag.code = d.code;
      return diag;
    });
    lspDiagnosticsByUri.set(uri.toString(), diagnostics);
    refreshMergedDiagnostics(uri);
  }
}

// ============================================================================
// 6. VS Code Extension Activation & Providers
// ============================================================================

function activate(context) {
  if (!vscode) return;

  // Create visual editor decoration types for misaligned indentation and syntax errors
  misalignedDecorationType = vscode.window.createTextEditorDecorationType({
    backgroundColor: "rgba(224, 175, 104, 0.20)",
    borderWidth: "0 0 1px 0",
    borderStyle: "dashed",
    borderColor: "#E0AF68",
    overviewRulerColor: "#E0AF68",
    overviewRulerLane: vscode.OverviewRulerLane.Right,
  });
  syntaxErrorDecorationType = vscode.window.createTextEditorDecorationType({
    backgroundColor: "rgba(240, 113, 120, 0.18)",
    borderWidth: "0 0 1px 0",
    borderStyle: "wavy",
    borderColor: "#F07178",
    overviewRulerColor: "#F07178",
    overviewRulerLane: vscode.OverviewRulerLane.Right,
  });
  context.subscriptions.push(misalignedDecorationType, syntaxErrorDecorationType);

  // Document formatting provider (Beautifier)
  const formattingProvider = vscode.languages.registerDocumentFormattingEditProvider("aipl", {
    provideDocumentFormattingEdits(document) {
      const original = document.getText();
      const formatted = formatDocumentText(original);
      if (formatted === original) {
        return [];
      }
      const fullRange = new vscode.Range(
        document.positionAt(0),
        document.positionAt(original.length)
      );
      return [vscode.TextEdit.replace(fullRange, formatted)];
    },
  });
  context.subscriptions.push(formattingProvider);

  // Range formatting provider (Format Selection)
  if (vscode.languages.registerDocumentRangeFormattingEditProvider) {
    const rangeFormattingProvider = vscode.languages.registerDocumentRangeFormattingEditProvider(
      "aipl",
      {
        provideDocumentRangeFormattingEdits(document, range) {
          const selected = document.getText(range);
          const formatted = formatDocumentText(selected).replace(/\n$/, "");
          if (formatted === selected) {
            return [];
          }
          return [vscode.TextEdit.replace(range, formatted)];
        },
      }
    );
    context.subscriptions.push(rangeFormattingProvider);
  }

  // Format on save listener when aipl.formatOnSave is enabled
  if (vscode.workspace.onWillSaveTextDocument) {
    context.subscriptions.push(
      vscode.workspace.onWillSaveTextDocument((event) => {
        if (event.document.languageId !== "aipl") return;
        const cfg = vscode.workspace.getConfiguration("aipl");
        if (cfg.get("formatOnSave") === false) return;
        const original = event.document.getText();
        const formatted = formatDocumentText(original);
        if (formatted !== original) {
          const fullRange = new vscode.Range(
            event.document.positionAt(0),
            event.document.positionAt(original.length)
          );
          event.waitUntil(Promise.resolve([vscode.TextEdit.replace(fullRange, formatted)]));
        }
      })
    );
  }

  // Register explicit commands
  if (vscode.commands && vscode.commands.registerCommand) {
    context.subscriptions.push(
      vscode.commands.registerCommand("aipl.beautifyDocument", async () => {
        const editor = vscode.window.activeTextEditor;
        if (!editor || editor.document.languageId !== "aipl") return;
        const original = editor.document.getText();
        const formatted = formatDocumentText(original);
        if (formatted !== original) {
          const fullRange = new vscode.Range(
            editor.document.positionAt(0),
            editor.document.positionAt(original.length)
          );
          await editor.edit((editBuilder) => {
            editBuilder.replace(fullRange, formatted);
          });
        }
        updateDocumentValidationAndDecorations(editor.document);
      })
    );

    context.subscriptions.push(
      vscode.commands.registerCommand("aipl.checkAlignmentAndSyntax", () => {
        const editor = vscode.window.activeTextEditor;
        if (!editor || editor.document.languageId !== "aipl") return;
        updateDocumentValidationAndDecorations(editor.document);
      })
    );

    const resolveAiplTheme = (arg) => {
      const raw =
        typeof arg === "string"
          ? arg.trim()
          : arg && typeof arg.label === "string"
          ? arg.label.trim()
          : "";
      if (!raw) return null;
      const lower = raw.toLowerCase();
      for (const t of AIPL_THEMES) {
        const slug = path
          .basename(t.path, ".json")
          .replace(/-color-theme$/, "")
          .toLowerCase();
        if (t.label.toLowerCase() === lower || slug === lower) {
          return t.label;
        }
      }
      return null;
    };

    const selectThemeHandler = async (themeArg) => {
      const wbCfg = vscode.workspace.getConfiguration("workbench");
      const directMatch = resolveAiplTheme(themeArg);
      if (directMatch) {
        await wbCfg.update("colorTheme", directMatch, vscode.ConfigurationTarget.Global);
        return directMatch;
      }
      const currentTheme =
        wbCfg && typeof wbCfg.get === "function" ? wbCfg.get("colorTheme") : null;
      if (vscode.window && typeof vscode.window.showQuickPick === "function") {
        const picked = await vscode.window.showQuickPick(
          AIPL_THEMES.map((t) => ({
            label: t.label,
            description:
              t.label === currentTheme ? `${t.description} (Active)` : t.description,
            detail: t.detail,
            picked: t.label === currentTheme,
          })),
          {
            placeHolder: "Select an agreeable, low-eye-strain AIPL color theme (6 themes)",
            matchOnDescription: true,
            matchOnDetail: true,
          }
        );
        if (!picked) return null;
        const chosenLabel = resolveAiplTheme(picked) || (typeof picked === "string" ? picked : picked.label);
        await wbCfg.update("colorTheme", chosenLabel, vscode.ConfigurationTarget.Global);
        return chosenLabel;
      }
      await wbCfg.update("colorTheme", "AIPL Aura Dark", vscode.ConfigurationTarget.Global);
      return "AIPL Aura Dark";
    };

    context.subscriptions.push(
      vscode.commands.registerCommand("aipl.selectTheme", selectThemeHandler)
    );

    context.subscriptions.push(
      vscode.commands.registerCommand("aipl.applyDarkStyle", selectThemeHandler)
    );
  }

  // Quick Fix CodeActionProvider for misaligned indentation & syntax typos
  if (vscode.languages.registerCodeActionsProvider) {
    const codeActionProvider = vscode.languages.registerCodeActionsProvider("aipl", {
      provideCodeActions(document, range, contextInfo) {
        const actions = [];
        for (const diag of contextInfo.diagnostics || []) {
          if (diag.source === "aipl-align" || String(diag.code).startsWith("AIPL_ALIGN")) {
            const fixAction = new vscode.CodeAction(
              "AIPL: Beautify & align document indentation (2 spaces)",
              vscode.CodeActionKind.QuickFix
            );
            fixAction.command = {
              command: "aipl.beautifyDocument",
              title: "AIPL: Beautify / Format Document",
            };
            fixAction.diagnostics = [diag];
            fixAction.isPreferred = true;
            actions.push(fixAction);
            break;
          }
        }
        return actions;
      },
    });
    context.subscriptions.push(codeActionProvider);
  }

  // Diagnostic collection
  diagCollection = vscode.languages.createDiagnosticCollection("aipl");
  context.subscriptions.push(diagCollection);

  // Start persistent `aipl lsp` background daemon
  try {
    const bin = getAiplBin();
    lspProcess = spawn(bin, ["lsp"], { stdio: ["pipe", "pipe", "pipe"] });

    let stdoutBuffer = Buffer.alloc(0);
    lspProcess.stdout.on("data", (chunk) => {
      stdoutBuffer = Buffer.concat([stdoutBuffer, chunk]);
      while (true) {
        const headerEnd = stdoutBuffer.indexOf("\r\n\r\n");
        if (headerEnd === -1) break;
        const headerStr = stdoutBuffer.slice(0, headerEnd).toString("utf8");
        const match = headerStr.match(/Content-Length:\s*(\d+)/i);
        if (!match) {
          stdoutBuffer = stdoutBuffer.slice(headerEnd + 4);
          continue;
        }
        const contentLength = parseInt(match[1], 10);
        const totalLength = headerEnd + 4 + contentLength;
        if (stdoutBuffer.length < totalLength) {
          break; // Wait for full content
        }
        const bodyBuf = stdoutBuffer.slice(headerEnd + 4, totalLength);
        stdoutBuffer = stdoutBuffer.slice(totalLength);
        try {
          const msg = JSON.parse(bodyBuf.toString("utf8"));
          handleLspMessage(msg);
        } catch (_) {}
      }
    });

    lspProcess.stderr.on("data", () => {
      // Drain stderr to prevent pipe backpressure
    });

    // Writing to a daemon that already exited emits EPIPE on stdin; without a listener that is an unhandled
    // stream error in the extension host.
    lspProcess.stdin.on("error", () => {});

    const spawnedLsp = lspProcess;
    lspProcess.on("error", () => {
      if (lspProcess === spawnedLsp) lspProcess = null;
      rejectAllPendingRequests("LSP daemon failed to start");
    });

    lspProcess.on("exit", () => {
      if (lspProcess === spawnedLsp) lspProcess = null;
      rejectAllPendingRequests("LSP daemon exited");
    });

    sendRequest("initialize", {
      processId: process.pid,
      rootUri:
        vscode.workspace.workspaceFolders && vscode.workspace.workspaceFolders[0]
          ? vscode.workspace.workspaceFolders[0].uri.toString()
          : null,
      capabilities: {
        textDocument: {
          hover: { dynamicRegistration: true, contentFormat: ["markdown", "plaintext"] },
          definition: { dynamicRegistration: true },
          documentSymbol: { dynamicRegistration: true },
          synchronization: { didSave: true, willSave: false },
        },
      },
    })
      .then(() => {
        sendRpc("initialized", {});
        vscode.workspace.textDocuments.forEach((doc) => {
          if (doc.languageId === "aipl") {
            sendDidOpen(doc);
          }
        });
      })
      .catch(() => {});
  } catch (_) {
    lspProcess = null;
  }

  // Validate already-open AIPL documents immediately
  if (vscode.workspace && Array.isArray(vscode.workspace.textDocuments)) {
    vscode.workspace.textDocuments.forEach((doc) => {
      if (doc.languageId === "aipl") {
        updateDocumentValidationAndDecorations(doc);
      }
    });
  }

  // Document synchronization listeners
  context.subscriptions.push(
    vscode.workspace.onDidOpenTextDocument((doc) => {
      if (doc.languageId === "aipl") {
        sendDidOpen(doc);
      }
    })
  );

  context.subscriptions.push(
    vscode.workspace.onDidChangeTextDocument((e) => {
      if (e.document.languageId === "aipl") {
        sendDidChange(e.document);
      }
    })
  );

  if (vscode.window && vscode.window.onDidChangeActiveTextEditor) {
    context.subscriptions.push(
      vscode.window.onDidChangeActiveTextEditor((editor) => {
        if (editor && editor.document && editor.document.languageId === "aipl") {
          updateDocumentValidationAndDecorations(editor.document);
        }
      })
    );
  }

  context.subscriptions.push(
    vscode.workspace.onDidCloseTextDocument((doc) => {
      if (doc.languageId === "aipl") {
        const key = doc.uri.toString();
        lspDiagnosticsByUri.delete(key);
        localDiagnosticsByUri.delete(key);
        if (diagCollection) {
          diagCollection.delete(doc.uri);
        }
        sendRpc("textDocument/didClose", {
          textDocument: {
            uri: key,
          },
        });
      }
    })
  );

  // Hover Provider: Cross-File Symbol Signature + LSP fallback
  const hoverProvider = vscode.languages.registerHoverProvider("aipl", {
    provideHover(document, position) {
      const crossDefs = findSymbolDefinitionCrossFile(
        document.getText(),
        document.uri ? document.uri.fsPath : "",
        position.line,
        position.character
      );
      if (crossDefs.length > 0) {
        const sym = crossDefs[0];
        const mdLines = [`\`\`\`aipl\n${sym.signature}\n\`\`\``];
        if (sym.doc) {
          mdLines.push(sym.doc);
        }
        if (sym.filePath) {
          const relPath = path.basename(sym.filePath);
          const fileUri = vscode.Uri.file(sym.filePath).toString();
          mdLines.push(`*Defined in [${relPath}:${sym.line + 1}](${fileUri}#L${sym.line + 1})*`);
        }
        const md = new vscode.MarkdownString(mdLines.join("\n\n"));
        md.isTrusted = true;
        return new vscode.Hover(md);
      }

      return sendRequest("textDocument/hover", {
        textDocument: { uri: document.uri.toString() },
        position: { line: position.line, character: position.character },
      })
        .then((res) => {
          if (!res || !res.contents) return null;
          let contents;
          if (typeof res.contents === "string") {
            contents = [new vscode.MarkdownString(res.contents)];
          } else if (Array.isArray(res.contents)) {
            contents = res.contents.map((c) =>
              new vscode.MarkdownString(typeof c === "string" ? c : c.value)
            );
          } else if (res.contents.value) {
            contents = [new vscode.MarkdownString(res.contents.value)];
          } else {
            contents = [new vscode.MarkdownString(String(res.contents))];
          }
          let range = undefined;
          if (res.range && res.range.start && res.range.end) {
            range = new vscode.Range(
              new vscode.Position(res.range.start.line, res.range.start.character),
              new vscode.Position(res.range.end.line, res.range.end.character)
            );
          }
          return new vscode.Hover(contents, range);
        })
        .catch(() => null);
    },
  });
  context.subscriptions.push(hoverProvider);

  // Definition Provider: Cross-File Function/Struct/Enum & Import Resolver + LSP fallback
  const defProvider = vscode.languages.registerDefinitionProvider("aipl", {
    provideDefinition(document, position) {
      const crossDefs = findSymbolDefinitionCrossFile(
        document.getText(),
        document.uri ? document.uri.fsPath : "",
        position.line,
        position.character
      );
      if (crossDefs.length > 0) {
        return crossDefs.map((sym) => {
          const targetUri = sym.filePath
            ? vscode.Uri.file(sym.filePath)
            : document.uri;
          const targetRange = new vscode.Range(
            new vscode.Position(sym.line, sym.startCol),
            new vscode.Position(sym.line, Math.max(sym.startCol, sym.endCol))
          );
          return new vscode.Location(targetUri, targetRange);
        });
      }

      return sendRequest("textDocument/definition", {
        textDocument: { uri: document.uri.toString() },
        position: { line: position.line, character: position.character },
      })
        .then((res) => {
          if (!res) return null;
          if (Array.isArray(res)) {
            return res.map((loc) => {
              const uri = vscode.Uri.parse(loc.uri);
              const r = loc.range;
              return new vscode.Location(
                uri,
                new vscode.Range(r.start.line, r.start.character, r.end.line, r.end.character)
              );
            });
          }
          if (res.uri && res.range) {
            const uri = vscode.Uri.parse(res.uri);
            const r = res.range;
            return new vscode.Location(
              uri,
              new vscode.Range(r.start.line, r.start.character, r.end.line, r.end.character)
            );
          }
          return null;
        })
        .catch(() => null);
    },
  });
  context.subscriptions.push(defProvider);

  // Document Link Provider: Clickable `import ... from "..."` and `import std.xxx` file links
  if (vscode.languages.registerDocumentLinkProvider) {
    const linkProvider = vscode.languages.registerDocumentLinkProvider("aipl", {
      provideDocumentLinks(document) {
        const links = [];
        const baseDir = document.uri && document.uri.fsPath ? path.dirname(document.uri.fsPath) : "";
        const roots = getWorkspaceRoots(document.uri ? document.uri.fsPath : undefined);
        const text = document.getText();
        const lines = text.split("\n");
        const importPathRegex = /(?:from|import)\s+["']([^"']+)["']/g;

        for (let i = 0; i < lines.length; i++) {
          const line = lines[i];
          const trimmed = line.trim();
          if (trimmed.startsWith("#") || trimmed.startsWith("//")) continue;

          importPathRegex.lastIndex = 0;
          let m;
          while ((m = importPathRegex.exec(line)) !== null) {
            const rawMod = m[1];
            const resolved = resolveAiplModulePath(baseDir, rawMod, roots);
            if (resolved) {
              const startCol = m.index + m[0].indexOf(rawMod);
              const endCol = startCol + rawMod.length;
              const range = new vscode.Range(i, startCol, i, endCol);
              const link = new vscode.DocumentLink(range, vscode.Uri.file(resolved));
              link.tooltip = `Open AIPL module: ${resolved}`;
              links.push(link);
            }
          }

          const dotMatch = line.match(/^\s*(?:pub\s+)?import\s+(std\.[a-zA-Z0-9_.]+)/);
          if (dotMatch) {
            const rawMod = dotMatch[1];
            const resolved = resolveAiplModulePath(baseDir, rawMod, roots);
            if (resolved) {
              const startCol = line.indexOf(rawMod);
              const endCol = startCol + rawMod.length;
              const range = new vscode.Range(i, startCol, i, endCol);
              const link = new vscode.DocumentLink(range, vscode.Uri.file(resolved));
              link.tooltip = `Open AIPL module: ${resolved}`;
              links.push(link);
            }
          }
        }
        return links;
      },
    });
    context.subscriptions.push(linkProvider);
  }

  // Reference Provider: Find all references to a function/symbol across workspace `.aipl` files
  if (vscode.languages.registerReferenceProvider) {
    const refProvider = vscode.languages.registerReferenceProvider("aipl", {
      provideReferences(document, position) {
        const lineText = document.lineAt(position.line).text;
        const wordInfo = extractWordAtPosition(lineText, position.character);
        if (!wordInfo) return [];
        const word = wordInfo.word;
        const wordRegex = new RegExp(`\\b${word}\\b`, "g");
        const files = discoverWorkspaceAiplFiles(
          [],
          document.uri ? document.uri.fsPath : undefined
        );
        const locations = [];

        for (const file of files) {
          let content = "";
          try {
            content = fs.readFileSync(file, "utf8");
          } catch (_) {
            continue;
          }
          const fLines = content.replace(/\r\n/g, "\n").split("\n");
          for (let li = 0; li < fLines.length; li++) {
            const fl = fLines[li];
            if (fl.trim().startsWith("#") || fl.trim().startsWith("//")) continue;
            wordRegex.lastIndex = 0;
            let m;
            while ((m = wordRegex.exec(fl)) !== null) {
              locations.push(
                new vscode.Location(
                  vscode.Uri.file(file),
                  new vscode.Range(li, m.index, li, m.index + word.length)
                )
              );
            }
          }
        }
        return locations;
      },
    });
    context.subscriptions.push(refProvider);
  }

  // Workspace Symbol Provider (`Ctrl+T` to jump to any function/struct/enum across files)
  if (vscode.languages.registerWorkspaceSymbolProvider) {
    const wsSymbolProvider = vscode.languages.registerWorkspaceSymbolProvider({
      provideWorkspaceSymbols(query) {
        const q = String(query || "").toLowerCase();
        const files = discoverWorkspaceAiplFiles([], undefined);
        const results = [];
        for (const file of files) {
          const syms = getCachedFileSymbols(file);
          for (const s of syms) {
            if (!q || s.name.toLowerCase().includes(q)) {
              const kind = mapSymbolKind(s.kind);
              const loc = new vscode.Location(
                vscode.Uri.file(file),
                new vscode.Range(s.line, s.startCol, s.line, s.endCol)
              );
              results.push(new vscode.SymbolInformation(s.name, kind, path.basename(file), loc));
            }
          }
        }
        return results;
      },
    });
    context.subscriptions.push(wsSymbolProvider);
  }

  // Document Symbol Provider forwarding textDocument/documentSymbol to `aipl lsp` daemon.
  // Falls back to regex-based AST outlines if LSP times out or returns an empty result.
  let lspDocumentSymbolUnanswered = false;
  const symbolProvider = vscode.languages.registerDocumentSymbolProvider("aipl", {
    provideDocumentSymbols(document) {
      if (lspDocumentSymbolUnanswered) {
        return getFallbackSymbols(document);
      }
      return sendRequest("textDocument/documentSymbol", {
        textDocument: { uri: document.uri.toString() },
      }, LSP_DOCUMENT_SYMBOL_TIMEOUT_MS)
        .then((res) => {
          if (Array.isArray(res) && res.length > 0) {
            return res.map((s) => mapLspSymbol(s, document.uri)).filter(Boolean);
          }
          return getFallbackSymbols(document);
        })
        .catch((err) => {
          if (err && /timed out/.test(String(err.message || err))) lspDocumentSymbolUnanswered = true;
          return getFallbackSymbols(document);
        });
    },
  });
  context.subscriptions.push(symbolProvider);
}

function mapSymbolKind(kind) {
  if (!vscode) return 11;
  if (typeof kind === "string") {
    const k = kind.toLowerCase();
    if (k === "file") return vscode.SymbolKind.File;
    if (k === "module") return vscode.SymbolKind.Module;
    if (k === "namespace") return vscode.SymbolKind.Namespace;
    if (k === "package") return vscode.SymbolKind.Package;
    if (k === "class" || k === "impl") return vscode.SymbolKind.Class;
    if (k === "method") return vscode.SymbolKind.Method;
    if (k === "property") return vscode.SymbolKind.Property;
    if (k === "field") return vscode.SymbolKind.Field;
    if (k === "constructor") return vscode.SymbolKind.Constructor;
    if (k === "enum") return vscode.SymbolKind.Enum;
    if (k === "interface" || k === "trait") return vscode.SymbolKind.Interface;
    if (k === "function" || k === "fn") return vscode.SymbolKind.Function;
    if (k === "variable" || k === "let" || k === "mut") return vscode.SymbolKind.Variable;
    if (k === "constant" || k === "const") return vscode.SymbolKind.Constant;
    if (k === "struct") return vscode.SymbolKind.Struct;
    if (k === "event") return vscode.SymbolKind.Event;
    if (k === "operator") return vscode.SymbolKind.Operator;
    return vscode.SymbolKind.Function;
  }
  if (typeof kind === "number") {
    if (kind >= 1 && kind <= 26) {
      return kind - 1;
    }
  }
  return vscode.SymbolKind.Function;
}

function mapLspSymbol(s, defaultUri) {
  if (!vscode || !s || !s.name) return null;
  const name = s.name;
  const kind = mapSymbolKind(s.kind);

  if (s.range && s.range.start && s.range.end) {
    const startPos = new vscode.Position(s.range.start.line, s.range.start.character);
    const endPos = new vscode.Position(s.range.end.line, s.range.end.character);
    const range = new vscode.Range(startPos, endPos);
    let selRange = range;
    if (s.selectionRange && s.selectionRange.start && s.selectionRange.end) {
      selRange = new vscode.Range(
        new vscode.Position(s.selectionRange.start.line, s.selectionRange.start.character),
        new vscode.Position(s.selectionRange.end.line, s.selectionRange.end.character)
      );
    }
    const docSymbol = new vscode.DocumentSymbol(name, s.detail || "", kind, range, selRange);
    if (Array.isArray(s.children)) {
      docSymbol.children = s.children
        .map((child) => mapLspSymbol(child, defaultUri))
        .filter(Boolean);
    }
    return docSymbol;
  }

  if (s.location && s.location.range) {
    const locUri = s.location.uri ? vscode.Uri.parse(s.location.uri) : defaultUri;
    const r = s.location.range;
    const range = new vscode.Range(
      new vscode.Position(r.start.line, r.start.character),
      new vscode.Position(r.end.line, r.end.character)
    );
    return new vscode.SymbolInformation(name, kind, s.containerName || "", new vscode.Location(locUri, range));
  }

  if (typeof s.line === "number") {
    const l = Math.max(0, s.line > 0 ? s.line - 1 : 0);
    const range = new vscode.Range(l, 0, l, 80);
    return new vscode.DocumentSymbol(name, s.detail || "", kind, range, range);
  }

  return null;
}

function getFallbackSymbols(document) {
  if (!vscode) return [];
  const extracted = extractFileSymbols(document.getText(), document.uri ? document.uri.fsPath : "");
  return extracted.map((sym) => {
    const fullRange = new vscode.Range(sym.line, 0, sym.line, sym.lineLength);
    const selRange = new vscode.Range(sym.line, sym.startCol, sym.line, sym.endCol);
    return new vscode.DocumentSymbol(
      sym.name,
      sym.kind,
      mapSymbolKind(sym.kind),
      fullRange,
      selRange
    );
  });
}

function deactivate() {
  if (lspProcess) {
    try {
      sendRpc("shutdown", {}, 999999);
      sendRpc("exit", {});
    } catch (_) {}
    try {
      lspProcess.kill();
    } catch (_) {}
    lspProcess = null;
  }
  for (const pending of pendingRequests.values()) {
    pending.reject(new Error("LSP daemon deactivated"));
  }
  pendingRequests.clear();
  lspDiagnosticsByUri.clear();
  localDiagnosticsByUri.clear();
  workspaceSymbolCache.clear();
  if (diagCollection) {
    diagCollection.clear();
    diagCollection.dispose();
    diagCollection = null;
  }
}

module.exports = {
  activate,
  deactivate,
  AIPL_THEMES,
  beautifyAiplSource,
  formatDocumentText,
  validateAiplDocument,
  parseAiplImports,
  resolveAiplModulePath,
  extractFileSymbols,
  findSymbolDefinitionCrossFile,
};
