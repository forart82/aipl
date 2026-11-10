# SPEC_04: File System Log Aggregator & Analyzer (`test_04_log_aggregator`)

- **Tier**: Medium
- **Category**: File I/O, Hash Map Aggregation & Statistical Summary

## 1. Functional Requirements
1. Define `LogSummary(totalLines: int, errorCount: int, warnCount: int, infoCount: int, topEndpoint: str, errorRatePct: float)`.
2. Write the 5-line sample access log to `/tmp/bench04_sample.log` and read it back from disk.
3. Implement `analyzeLogs(content)` that counts non-empty lines (`totalLines`), counts `ERROR`, `WARN`, and `INFO` entries, tracks frequency per endpoint (3rd whitespace-separated column) in a hash map to identify `topEndpoint`, and computes `errorRatePct = (errorCount * 100.0) / totalLines`.
4. Assert `totalLines == 5`, `errorCount == 2`, `warnCount == 1`, `infoCount == 2`, `topEndpoint == "/api/pay"`, and `39.9 < errorRatePct < 40.1`.
5. Print `"Total=5 Errors=2 Top=/api/pay"` followed by `BENCH_04_OK`.

## 2. Structural & Algorithmic Parity (Rule B)
- **Normalized Identifiers**: `LogSummary`, `analyzeLogs`, `logPath`, `sample`, `loaded`, `summary`.
- **Data Structures**: Structured `LogSummary` record + frequency map (`Map<String, Int>`).

## 3. Expected Deterministic Stdout
```text
Total=5 Errors=2 Top=/api/pay
BENCH_04_OK
```
