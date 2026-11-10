# AIPL Machine-Readable Diagnostics Specification
**Schema Version: diagnostic-v1.json**

---

## 1. Overview & Machine-Readability Mandate

Autonomous AI coding agents spend a substantial portion of their inference budget parsing, interpreting, and recovering from unstructured compiler error messages. Traditional textual compilers (e.g., GCC, Clang, rustc, tsc) emit ANSI terminal escape codes (`\x1b[`), ASCII art pointer carets (`^~~~`), and conversational human-centric notes that frequently confuse subword tokenizers and induce hallucination loops.

AIPL establishes an **Agent-First Diagnostics Protocol** implemented in `compiler/types.aipl` and `compiler/main.aipl`:
1. **Single-Root JSON Diagnostic Report (`AiplDiagnosticReport`)**: All diagnostics are emitted in a single-root JSON document conforming to `diagnostic-v1.json`, including file path, SHA-256 content hash, overall status, and aggregated summary metrics.
2. **Exact Byte Locator**: Exact zero-indexed half-open byte spans `[start_byte, end_byte)` paired with 1-indexed `(line, column)` coordinates and `utf16_offset` eliminate off-by-one errors across LLM tokenizer boundaries and language server (LSP) integrations.
3. **Semantic AST Path Breadcrumbs**: The deterministic structural path through the AST (e.g. `["program", "models", "User", "fields", "age"]`) allows agents to immediately locate grammatical hierarchy without re-parsing source text.
4. **Poisoned Symbol Cascade Tracking & Suppression**: When a type or identifier fails resolution or produces an error, it is flagged as poisoned in the scope-aware `TaintedSymbolRegistry`:
   - **Primary Faults (`role: "primary_fault"`, `cascade: false`, `root_cause_id: None`)**: The originating declaration or usage failure is assigned a fresh unique ID (e.g., `ERR-1001`).
   - **Cascading Consequences (`role: "cascading_consequence"`, `cascade: true`, `root_cause_id: "ERR-1001"`)**: Subsequent references and downstream type inference failures inherit the poison and referentially link to the root cause.
   - **Agent Filtering Mode (`filter_cascades = true`)**: In agent execution mode, the `diagnostics` array contains strictly primary faults, saving up to 98% of context tokens, while `summary.cascading_suppressed` precisely tracks the number of suppressed secondary errors.
   - **Independent Error Preservation**: Unrelated syntax or type errors on independent lines are never tainted and remain reported as primary faults.
5. **Candidate Repair Unified Diffs & TextEdits**: Whenever the compiler or linter has high confidence in a fix, it synthesizes byte-exact `TextEdit` slices and ready-to-apply unified diffs with zero offset drift.
6. **Total Elimination of ANSI & Caret Formatting**: Zero terminal ANSI escape codes (`\x1b[`) and zero ASCII art carets are permitted in JSON mode.

---

## 2. Authoritative JSON Schema (`diagnostic-v1.json`)

The following is the authoritative JSON Schema (Draft 2020-12) for AIPL compiler diagnostic reports:

```json
{
  "$schema": "https://json-schema.org/draft/2020-12/schema",
  "$id": "https://aipl.dev/schemas/diagnostic-v1.json",
  "title": "AiplDiagnosticReport",
  "description": "Standardized machine-readable single-root diagnostic output for the AIPL compiler",
  "type": "object",
  "required": [
    "schema",
    "version",
    "file",
    "file_hash",
    "status",
    "summary",
    "diagnostics"
  ],
  "properties": {
    "schema": {
      "type": "string",
      "enum": ["https://aipl.dev/schemas/diagnostic-v1.json"]
    },
    "version": {
      "type": "string",
      "enum": ["1.0.0"]
    },
    "file": {
      "type": "string",
      "description": "Relative file path from project root or workspace"
    },
    "file_hash": {
      "type": "string",
      "pattern": "^[0-9a-f]{64}$",
      "description": "SHA-256 hash of the target source file content"
    },
    "status": {
      "type": "string",
      "enum": ["ok", "warning", "error"]
    },
    "summary": {
      "$ref": "#/$defs/ReportSummary"
    },
    "diagnostics": {
      "type": "array",
      "items": {
        "$ref": "#/$defs/DiagnosticItem"
      }
    }
  },
  "additionalProperties": false,
  "$defs": {
    "ReportSummary": {
      "type": "object",
      "required": [
        "total_diagnostics",
        "primary_errors",
        "cascading_suppressed"
      ],
      "properties": {
        "total_diagnostics": {
          "type": "integer",
          "minimum": 0
        },
        "primary_errors": {
          "type": "integer",
          "minimum": 0
        },
        "cascading_suppressed": {
          "type": "integer",
          "minimum": 0
        }
      },
      "additionalProperties": false
    },
    "DiagnosticItem": {
      "type": "object",
      "required": [
        "id",
        "code",
        "severity",
        "role",
        "cascade",
        "message",
        "rule",
        "location",
        "context",
        "suggested_fixes"
      ],
      "properties": {
        "id": {
          "type": "string",
          "description": "Unique diagnostic identifier within this report"
        },
        "code": {
          "type": "string",
          "description": "Standard compiler error or warning code"
        },
        "severity": {
          "type": "string",
          "enum": ["error", "warning", "info"]
        },
        "role": {
          "type": "string",
          "enum": ["primary_fault", "cascading_consequence"]
        },
        "cascade": {
          "type": "boolean",
          "description": "True if this diagnostic is a downstream cascade of an earlier poisoned symbol"
        },
        "root_cause_id": {
          "type": "string",
          "description": "Unique ID of the root cause diagnostic that poisoned this symbol"
        },
        "message": {
          "type": "string",
          "description": "Succinct, factual machine-readable error message without ANSI formatting"
        },
        "rule": {
          "$ref": "#/$defs/DiagnosticRule"
        },
        "location": {
          "$ref": "#/$defs/Location"
        },
        "context": {
          "$ref": "#/$defs/Context"
        },
        "suggested_fixes": {
          "type": "array",
          "items": {
            "$ref": "#/$defs/SuggestedFix"
          }
        }
      },
      "additionalProperties": false
    },
    "DiagnosticRule": {
      "type": "object",
      "required": ["id", "description"],
      "properties": {
        "id": { "type": "string" },
        "description": { "type": "string" }
      },
      "additionalProperties": false
    },
    "PositionCoordinates": {
      "type": "object",
      "required": ["line", "column", "utf16_offset"],
      "properties": {
        "line": { "type": "integer", "minimum": 1 },
        "column": { "type": "integer", "minimum": 1 },
        "utf16_offset": { "type": "integer", "minimum": 0 }
      },
      "additionalProperties": false
    },
    "Location": {
      "type": "object",
      "required": [
        "start_byte",
        "end_byte",
        "start",
        "end",
        "ast_path"
      ],
      "properties": {
        "start_byte": { "type": "integer", "minimum": 0 },
        "end_byte": { "type": "integer", "minimum": 0 },
        "start": { "$ref": "#/$defs/PositionCoordinates" },
        "end": { "$ref": "#/$defs/PositionCoordinates" },
        "ast_path": {
          "type": "array",
          "items": { "type": "string" },
          "description": "Deterministic semantic breadcrumb path through AST/HIR"
        }
      },
      "additionalProperties": false
    },
    "Context": {
      "type": "object",
      "required": ["snippet", "focus_line"],
      "properties": {
        "enclosing_symbol": { "type": "string" },
        "snippet": { "type": "string" },
        "focus_line": { "type": "integer", "minimum": 1 }
      },
      "additionalProperties": false
    },
    "TextEdit": {
      "type": "object",
      "required": ["start_byte", "end_byte", "new_text"],
      "properties": {
        "start_byte": { "type": "integer", "minimum": 0 },
        "end_byte": { "type": "integer", "minimum": 0 },
        "new_text": { "type": "string" }
      },
      "additionalProperties": false
    },
    "SuggestedFix": {
      "type": "object",
      "required": [
        "title",
        "confidence",
        "safety",
        "edits",
        "diff_unified"
      ],
      "properties": {
        "title": { "type": "string" },
        "confidence": { "type": "number", "minimum": 0, "maximum": 1 },
        "safety": {
          "type": "string",
          "enum": ["safe_auto_fix", "requires_intent", "safe", "potentially_breaking"]
        },
        "edits": {
          "type": "array",
          "items": { "$ref": "#/$defs/TextEdit" }
        },
        "diff_unified": { "type": "string" }
      },
      "additionalProperties": false
    }
  }
}
```

---

## 3. Concrete Diagnostic Examples

### 3.1 Primary Error with Candidate Repair Unified Diff (Tokenomics Invariant)

When an AI agent accidentally outputs snake_case instead of the mandatory camelCase invariant:

```json
{
  "schema": "https://aipl.dev/schemas/diagnostic-v1.json",
  "version": "1.0.0",
  "file": "src/analytics/counter.aipl",
  "file_hash": "2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824",
  "status": "warning",
  "summary": {
    "total_diagnostics": 1,
    "primary_errors": 0,
    "cascading_suppressed": 0
  },
  "diagnostics": [
    {
      "id": "WARN-1001",
      "code": "AIPL_W0041_SNAKE_CASE_TOKEN_PENALTY",
      "severity": "warning",
      "role": "primary_fault",
      "cascade": false,
      "message": "Identifier 'total_count' violates camelCase tokenomics invariant. Underscores are forbidden in SentencePiece 256k tokenomics. Use 'totalCount' instead.",
      "rule": {
        "id": "AIPL_W0041_SNAKE_CASE_TOKEN_PENALTY",
        "description": "AIPL Tokenomics & Lexical Formatting Invariant"
      },
      "location": {
        "start_byte": 128,
        "end_byte": 139,
        "start": {
          "line": 6,
          "column": 7,
          "utf16_offset": 128
        },
        "end": {
          "line": 6,
          "column": 18,
          "utf16_offset": 139
        },
        "ast_path": ["program", "modules", "counter", "stmts", "0", "pattern", "ident"]
      },
      "context": {
        "snippet": "  let total_count: int = 0",
        "focus_line": 6
      },
      "suggested_fixes": [
        {
          "title": "Replace with compliant text 'totalCount'",
          "confidence": 1.0,
          "safety": "safe",
          "edits": [
            {
              "start_byte": 128,
              "end_byte": 139,
              "new_text": "totalCount"
            }
          ],
          "diff_unified": "--- src/analytics/counter.aipl\n+++ src/analytics/counter.aipl\n@@ -6,1 +6,1 @@\n-  let total_count: int = 0\n+  let totalCount: int = 0\n"
        }
      ]
    }
  ]
}
```

### 3.2 Poisoned Symbol Cascade Suppression

In the example below, a missing field in a struct causes an initial error `ERR-2001`. Downstream lines that attempt to access the invalid field or perform operations on the poisoned expression are flagged with `"role": "cascading_consequence"`, `"cascade": true`, and link back to `"root_cause_id": "ERR-2001"`:

```json
{
  "schema": "https://aipl.dev/schemas/diagnostic-v1.json",
  "version": "1.0.0",
  "file": "src/physics/integrator.aipl",
  "file_hash": "4b227777d4dd1fc61c6f884f48641d02b4d121d3fd328cb08b5531fcacdabf8a",
  "status": "error",
  "summary": {
    "total_diagnostics": 2,
    "primary_errors": 1,
    "cascading_suppressed": 1
  },
  "diagnostics": [
    {
      "id": "ERR-2001",
      "code": "AIPL_E2002_TYPE_MISMATCH",
      "severity": "error",
      "role": "primary_fault",
      "cascade": false,
      "message": "Field 'velocity' does not exist on struct 'Transform'. Available fields: 'x', 'y', 'z', 'rotation'.",
      "rule": {
        "id": "AIPL_E2002_TYPE_MISMATCH",
        "description": "AIPL Sound Bidirectional Type System Invariant"
      },
      "location": {
        "start_byte": 512,
        "end_byte": 520,
        "start": {
          "line": 24,
          "column": 18,
          "utf16_offset": 512
        },
        "end": {
          "line": 24,
          "column": 26,
          "utf16_offset": 520
        },
        "ast_path": ["program", "systems", "integrator", "body", "stmts", "2", "rhs", "field"]
      },
      "context": {
        "enclosing_symbol": "integrator",
        "snippet": "  let v = entity.transform.velocity",
        "focus_line": 24
      },
      "suggested_fixes": []
    },
    {
      "id": "ERR-2002",
      "code": "AIPL_E2002_TYPE_MISMATCH",
      "severity": "error",
      "role": "cascading_consequence",
      "cascade": true,
      "root_cause_id": "ERR-2001",
      "message": "Cannot apply binary operator '+' to '<poisoned>' and 'float'.",
      "rule": {
        "id": "AIPL_E2002_TYPE_MISMATCH",
        "description": "Downstream consequence of earlier failure: AIPL_E2002_TYPE_MISMATCH"
      },
      "location": {
        "start_byte": 530,
        "end_byte": 545,
        "start": {
          "line": 25,
          "column": 5,
          "utf16_offset": 530
        },
        "end": {
          "line": 25,
          "column": 20,
          "utf16_offset": 545
        },
        "ast_path": ["program", "systems", "integrator", "body", "stmts", "3", "rhs"]
      },
      "context": {
        "enclosing_symbol": "integrator",
        "snippet": "  let next = v + 1.0",
        "focus_line": 25
      },
      "suggested_fixes": []
    }
  ]
}
```

### 3.3 SMT Refinement Type Failure with Counter-Example Value

When an input value cannot be proven to satisfy a refinement constraint at compile time:

```json
{
  "schema": "https://aipl.dev/schemas/diagnostic-v1.json",
  "version": "1.0.0",
  "file": "src/net/server.aipl",
  "file_hash": "ef2d127de37b942baad06145e54b0c619a1f22327b2ebbcfbec78f5564afe39d",
  "status": "error",
  "summary": {
    "total_diagnostics": 1,
    "primary_errors": 1,
    "cascading_suppressed": 0
  },
  "diagnostics": [
    {
      "id": "ERR-3001",
      "code": "AIPL_E3001_REFINEMENT_VIOLATION",
      "severity": "error",
      "role": "primary_fault",
      "cascade": false,
      "message": "Refinement constraint violation: expression 'portNum' may violate '{ p: int | p >= 1 and p <= 65535 }'. Counter-example found by SMT solver: portNum = 0.",
      "rule": {
        "id": "AIPL_E3001_REFINEMENT_VIOLATION",
        "description": "AIPL Embedded SMT Refinement & Safety Proof Invariant"
      },
      "location": {
        "start_byte": 310,
        "end_byte": 317,
        "start": {
          "line": 14,
          "column": 22,
          "utf16_offset": 310
        },
        "end": {
          "line": 14,
          "column": 29,
          "utf16_offset": 317
        },
        "ast_path": ["program", "functions", "startServer", "body", "stmts", "1", "call", "args", "0"]
      },
      "context": {
        "enclosing_symbol": "startServer",
        "snippet": "  bindSocket(portNum)",
        "focus_line": 14
      },
      "suggested_fixes": [
        {
          "title": "Add explicit range guard before invocation",
          "confidence": 0.90,
          "safety": "safe",
          "edits": [],
          "diff_unified": "--- src/net/server.aipl\n+++ src/net/server.aipl\n@@ -14,1 +14,2 @@\n+  if portNum < 1 or portNum > 65535: return Err(ServerError.InvalidPort)\n   bindSocket(portNum)\n"
        }
      ]
    }
  ]
}
```

### 3.4 Agent-Filtered Cascade Suppression Report (40 Cascading Consequences Suppressed)

When an AI agent compiles source code containing a missing type (e.g. `Session`) that is referenced across 41 functions, `filter_cascades = true` suppresses all 40 cascading secondary errors from the `diagnostics` array, leaving strictly the actionable root cause while recording exact metrics in `summary`:

```json
{
  "schema": "https://aipl.dev/schemas/diagnostic-v1.json",
  "version": "1.0.0",
  "file": "src/auth/session_manager.aipl",
  "file_hash": "a8f331b2c4568910fedcba9876543210123456789abcdef0123456789abcdef0",
  "status": "error",
  "summary": {
    "total_diagnostics": 41,
    "primary_errors": 1,
    "cascading_suppressed": 40
  },
  "diagnostics": [
    {
      "id": "ERR-1001",
      "code": "AIPL_E1002_UNRESOLVED_TYPE",
      "severity": "error",
      "role": "primary_fault",
      "cascade": false,
      "message": "Type 'Session' is not declared in this scope",
      "rule": {
        "id": "AIPL_E1002_UNRESOLVED_TYPE",
        "description": "AIPL Canonical HIR Type Resolution Invariant"
      },
      "location": {
        "start_byte": 18,
        "end_byte": 25,
        "start": {
          "line": 1,
          "column": 19,
          "utf16_offset": 18
        },
        "end": {
          "line": 1,
          "column": 26,
          "utf16_offset": 25
        },
        "ast_path": ["program", "functions", "initSession", "params", "s", "type"]
      },
      "context": {
        "enclosing_symbol": "initSession",
        "snippet": "fn initSession(s: Session): void:",
        "focus_line": 1
      },
      "suggested_fixes": []
    }
  ]
}
```

---

## 4. Phase 2–6 Diagnostic Catalog & ADR-0023 Single-Root Schema Reference

The pure self-hosted toolchain (`./bin/aipl`) implements the `ADR-0023` single-root JSON diagnostics protocol in `compiler/types.aipl` (`formatDiagnosticsJson`) and `compiler/main.aipl` (`aipl verify --json`, `aipl lint --json`).

### 4.1 ADR-0023 Single-Root JSON Envelope
Every diagnostic run in JSON mode emits a single root JSON object designed for deterministic machine consumption without partial output or stream interlacing:

```json
{
  "schema_version": "1.0",
  "status": "error",
  "file": "src/main.aipl",
  "error_count": 1,
  "diagnostics": [
    {
      "code": "AIPL_E2002",
      "message": "Type mismatch in match scrutinee: expected Result/Option for pattern 'Ok', found bool",
      "span": {
        "fileId": 0,
        "start": 10,
        "end": 25,
        "line": 15,
        "column": 3
      },
      "severity": "error",
      "hint": "Wrap scrutinee in Option/Result",
      "autofix": {
        "available": true,
        "replacement": "Some(value)"
      }
    }
  ]
}
```

### 4.2 Diagnostic Code Catalog

#### `AIPL_E2002`: Type Mismatch in Scrutinee or Binding
- **Severity**: `error`
- **Description**: Triggered when a match statement pattern (e.g. `Ok(v)`, `Err(e)`, `Some(x)`, `None`) does not match the scrutinee type (such as matching `Ok` against a `bool` or `int`), or when variable assignments and return types do not match their declarations.
- **Example Message**: `AIPL_E2002: Type mismatch in match scrutinee: expected Result/Option for pattern 'Ok', found bool`
- **Hint**: `Wrap scrutinee in Option/Result`
- **Autofix**: Suggested replacement provided via `autofix.replacement`.

#### `AIPL_E2014`: Unknown Struct Field (`UNKNOWN_STRUCT_FIELD`)
- **Severity**: `error`
- **Description**: Triggered when accessing an undefined field on a nominal struct type. Replaces silent runtime `nil` errors with static verification, inspecting nominal struct definitions (excluding synthetic methods `toJson`, `fromJson`, `jsonSchema`, `len`, `length`, `clone`, `toString`, `f`, `i`).
- **Example Message**: `AIPL_E2014: Struct 'SoASnowPool' has no field 'capaciti'; did you mean 'capacity'?`
- **Hint**: `did you mean 'capacity'?`
- **Typo Recovery**: Provides deterministic field suggestions when the Levenshtein distance between the requested field name and an existing struct member is $\le 2$.

#### `AIPL_E1015`: Single-Quoted Strings Forbidden
- **Severity**: `error`
- **Description**: Single-quoted literals (`'...'`) are forbidden in AIPL to preserve tokenomic density and avoid ambiguities with lifetime syntax and apostrophes in comments. Double-quoted strings (`"..."`) must be used for all string literals.
- **Example Message**: `AIPL_E1015: Single-quoted strings are not supported; use double quotes "..."`
- **Hint**: Replace single quotes with double quotes.

#### `AIPL_W1001_UNPARAMETRIZED_MAP`: Unparameterized Map/Set
- **Severity**: `warning`
- **Description**: Struct fields declared as unparameterized `Map` or `Set` lose compile-time type safety and force dynamic boxing.
- **Example Message**: `AIPL_W1001_UNPARAMETRIZED_MAP: struct 'ServerConfig' field 'connections' uses unparameterized Map; prefer Map[K, V] or Set[T]`
- **Hint**: Explicitly specify key and value parameter types e.g. `Map[str, int]` or `Set[str]`.

#### `AIPL_W0201`: Complex String Interpolation
- **Severity**: `warning`
- **Description**: Interpolating complex expressions (nested calls, arithmetic, or quotes) inside `"... {expr} ..."` creates parsing ambiguities and tokenomic bloat.
- **Example Message**: `AIPL_W0201: complex expression inside string interpolation`
- **Hint**: Extract the complex expression to a preceding `let` binding and interpolate the resulting variable name.

#### `LINT010`: Unused Import Auto-Fix
- **Severity**: `warning` / `error`
- **Description**: Emitted when an identifier imported via `import { ... } from "..."` is never referenced within the module body.
- **Example Message**: `LINT010: Unused import 'fileExists'`
- **Autonomous Auto-Fix**: Invoking `./bin/aipl fix <file.aipl>` automatically strips all unused imported symbols from import declarations and removes empty import lines entirely with zero syntax errors.

#### `AIPL_E_INFINITE_LOOP_RISK`: Indentation-Induced Infinite Loop Guard
- **Severity**: `error`
- **Description**: Statically emitted by `compiler/types.aipl` and `compiler/smt.aipl` when analyzing a `while` loop whose termination condition depends on variables that are not mutated along the unconditional control-flow path of the loop body (e.g., when an increment statement `i += 1` is accidentally indented inside an inner `if` branch that can evaluate to false, or when non-mutating branches fail to `break` or `ret`).
- **Example Message**: `AIPL_E_INFINITE_LOOP_RISK: While loop condition variable 'i' is not unconditionally mutated or terminated on line 42; check indentation of loop increment`
- **Hint**: Verify that loop counters or condition variables are mutated unconditionally at the main loop body indentation level, or ensure that non-mutating branches contain an explicit `break` or `ret`.

#### `AIPL_E_TIMEOUT`: Execution Watchdog Timeout
- **Severity**: `error`
- **Description**: Emitted by the runtime CLI execution watchdog when process execution exceeds the configured `--timeout <seconds>` threshold (or default CLI watchdog limit). The watchdog intercepts the execution thread via `SIGALRM`, prints the current call stack, and terminates with exit code 1 to prevent infinite runtime hangs in CI test runs.
- **Example Message**: `AIPL_E_TIMEOUT: Execution watchdog timed out after 10.0 seconds in 'simulatePhysics' (src/physics.aipl:128)`
- **Hint**: Increase timeout with `--timeout <sec>`, check for unbounded loops or blocking I/O, or profile performance hot paths with `--profile`.

#### `AIPL_W0045_BRACE_BLOCK_TOKEN_PENALTY`: Brace Block / Arrow Return Token Penalty
- **Severity**: `warning`
- **Description**: Emitted by `aipl lint` when source code uses C/Rust-style curly-brace block delimiters (`{ ... }`) or `->` return type arrows instead of AIPL's canonical 2-space offside indentation and `:` block syntax.
- **Example Message**: `AIPL_W0045_BRACE_BLOCK_TOKEN_PENALTY: Prefer canonical significant indentation ':' over '{ ... }' block delimiters or '->' return syntax`
- **Hint**: Run `aipl fmt <file.aipl>` to normalize `) -> Type:` headers to `): Type:` and use canonical `:` offside indentation.
