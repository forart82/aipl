# SPEC_03: Structured Data Parser & Serializer (`test_03_data_parser`)

- **Tier**: Easy-Medium
- **Category**: Text Parsing, Validation, Transformation & JSON Serialization

## 1. Functional Requirements
1. Define a structured record `ConfigRecord` with fields `(service: str, port: int, tls: bool, tags: [str])`.
2. Implement `parseRecords(src)` that splits lines, ignores empty lines and `#` comment lines, splits on `"|"`, trims fields, and parses `service`, `port`, `tls == "true"`, and comma-separated `tags`.
3. Implement `validateAndMutate(records)` that filters records where `service` is non-empty and `0 < port <= 65535`, increments `port` by `100`, sets `tls = true`, trims existing tags, and appends `"verified"`.
4. Implement `serializeJson(records)` producing compact JSON array output:
   `[{"service":"auth","port":8100,"tls":true,"tags":["core","jwt","verified"]},{"service":"gateway","port":8180,"tls":true,"tags":["edge","http","verified"]}]`.
5. Verify against the 3-record sample input (`auth`, `gateway`, `invalid`), assert `parsed.len == 3`, `valid.len == 2`, and print the JSON string followed by `BENCH_03_OK`.

## 2. Structural & Algorithmic Parity (Rule B)
- **Normalized Identifiers**: `ConfigRecord`, `parseRecords`, `validateAndMutate`, `serializeJson`, `parsed`, `valid`, `jsonOut`.
- **Data Structures**: Typed record/struct/class `ConfigRecord` in all 8 languages (no untyped ad-hoc dicts bypassing record construction).

## 3. Expected Deterministic Stdout
```text
[{"service":"auth","port":8100,"tls":true,"tags":["core","jwt","verified"]},{"service":"gateway","port":8180,"tls":true,"tags":["edge","http","verified"]}]
BENCH_03_OK
```
