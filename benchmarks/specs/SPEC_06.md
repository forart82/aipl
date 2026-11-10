# SPEC_06: Complex Console Command Tool (CLI) (`test_06_complex_cli`)

- **Tier**: Medium-Complex
- **Category**: Multi-Subcommand CLI Dispatcher & Data Pipeline

## 1. Functional Requirements
1. Define `CliResult(exitCode: int, output: str)` and `executeCliCommand(args: [str]): CliResult`.
2. Support subcommands:
   - Empty args, `"--help"`, or `"help"`: return `CliResult(0, "Usage: tool <stats|transform|pipeline> [options]")`.
   - `"stats"`: parse `--values=v1,v2,...` into integers. If empty, return `CliResult(2, "Error: --values required")`. Otherwise compute count, sum, min, and max and return `CliResult(0, "count={len} sum={sum} min={min} max={max}")`.
   - `"pipeline"`: parse `--input=<text>`, `--upper`, `--reverse-words`. If input is empty, return `CliResult(1, "Error: empty input")`. Apply uppercase if `--upper` and word-order reversal if `--reverse-words`, returning `CliResult(0, text)`.
   - Any other subcommand: return `CliResult(127, "Unknown subcommand: {sub}")`.
3. Verify all 4 subcommand paths (`--help`, `stats`, `pipeline`, `unknown`) with assertions, and print `"{rStats.output} | {rPipe.output}"` followed by `BENCH_06_OK`.

## 2. Structural & Algorithmic Parity (Rule B)
- **Normalized Identifiers**: `CliResult`, `executeCliCommand`, `rHelp`, `rStats`, `rPipe`, `rErr`.
- **Full Validation**: All 8 languages must implement all 4 branches (including error codes `1`, `2`, `127`) and all 4 assertions.

## 3. Expected Deterministic Stdout
```text
count=4 sum=80 min=5 max=40 | CLI NATIVE FAST AIPL
BENCH_06_OK
```
