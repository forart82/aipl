"use strict";

const { spawnSync } = require("child_process");
const { beautifyAiplSource } = require("../vscode-aipl/extension.js");

function formatWithPureJsFallback(text) {
  return beautifyAiplSource(text);
}

function formatAiplSource(text, options) {
  let working = String(text || "");
  const aiplBin = (options && options.aiplPath) || process.env.AIPL_BIN || "aipl";
  try {
    const res = spawnSync(aiplBin, ["fmt", "--stdin"], {
      input: working,
      encoding: "utf8",
      timeout: 5000,
    });
    if (res && res.status === 0 && typeof res.stdout === "string" && res.stdout.length > 0) {
      working = res.stdout;
    }
  } catch (_) {
    // Fall back to deterministic pure-JS formatter when `aipl` CLI binary is not on PATH
  }
  return formatWithPureJsFallback(working);
}

const languages = [
  {
    name: "AIPL",
    parsers: ["aipl"],
    extensions: [".aipl"],
    tmScope: "source.aipl",
    aceMode: "text",
    vscodeLanguageIds: ["aipl"],
  },
];

const parsers = {
  aipl: {
    parse(text) {
      return {
        type: "aipl-program",
        body: text,
        start: 0,
        end: text.length,
      };
    },
    astFormat: "aipl-ast",
    locStart(node) {
      return node.start || 0;
    },
    locEnd(node) {
      return node.end || 0;
    },
  },
};

const printers = {
  "aipl-ast": {
    print(path, options) {
      const node = path.getValue ? path.getValue() : path.node;
      return formatAiplSource(node.body, options);
    },
  },
};

// Prettier only passes declared plugin options through to printers; `--aipl-path` / `"aiplPath"` in .prettierrc.
const options = {
  aiplPath: {
    type: "path",
    category: "AIPL",
    default: undefined,
    description: "Path to the `aipl` binary used for `aipl fmt --stdin` (defaults to $AIPL_BIN, then `aipl` on PATH).",
  },
};

module.exports = {
  languages,
  parsers,
  printers,
  options,
  formatAiplSource,
  formatWithPureJsFallback,
};
