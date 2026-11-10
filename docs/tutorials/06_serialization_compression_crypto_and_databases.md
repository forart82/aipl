[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](INDEX.md) | [Cookbook](cookbook.md) | [Stdlib Reference](../STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Chapter 06: Serialization, Compression, Cryptography & Databases

> **Chapter Summary**: Structured formats (JSON, YAML, TOML, CSV, Markdown, QR), streaming compression (Deflate, Gzip, LZ4, Zstd, Tar), cryptography (SHA-256, BLAKE3, ChaCha20-Poly1305, Argon2id, HMAC), and embedded ACID persistence (KV-WAL & SQLite).

## Table of Contents
- [Chapter 06.1: Structured Data Formats (JSON, YAML, TOML, CSV, XML, HTML, Markdown, QR, SemVer)](#chapter-061-structured-data-formats-json-yaml-toml-csv-xml-html-markdown-qr-semver)
- [Chapter 06.2: Lossless Compression & Archive Streams (Deflate, Gzip, LZ4, Zstd, Tar)](#chapter-062-lossless-compression--archive-streams-deflate-gzip-lz4-zstd-tar)
- [Chapter 06.3: Cryptographic Hashing, AEAD Encryption, Signatures & Password KDFs (std/crypto/*)](#chapter-063-cryptographic-hashing-aead-encryption-signatures--password-kdfs-stdcrypto)
- [Chapter 06.4: Embedded ACID Persistence (KV-WAL Store & Relational B-Tree SQLite Engine)](#chapter-064-embedded-acid-persistence-kv-wal-store--relational-b-tree-sqlite-engine)

---

### Chapter 06.1: Structured Data Formats (JSON, YAML, TOML, CSV, XML, HTML, Markdown, QR, SemVer)

#### 1. Concept in 30 Seconds
Teach parsing and serializing across all 13 `std/encoding/*` modules (`json`, `yaml`, `toml`, `csv`, `xml`, `html`, `markdown`, `ini`, `base64`, `bincode`, `semver`, `qrcode`, `utf8`).

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn jsonNull(): JsonValue:` from `std/encoding/json.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.encoding.json_z1_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonNull_1(): int:
  let resNom = jsonNull()
  let resEdge = jsonNull()
  assertEqStr(resNom.kind, "null", "jsonNull nominal string matches")
  assertEqStr(resEdge.kind, "null", "jsonNull boundary string matches")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_069` | [examples/ex_069_time_frame_pacer_hud_window.aipl](../../examples/ex_069_time_frame_pacer_hud_window.aipl) | `tests/examples/ex_069_time_frame_pacer_hud_window_test.aipl` | `./bin/aipl test tests/examples/ex_069_time_frame_pacer_hud_window_test.aipl` |
| `ex_070` | [examples/ex_070_encoding_json_jq_query_cli.aipl](../../examples/ex_070_encoding_json_jq_query_cli.aipl) | `tests/examples/ex_070_encoding_json_jq_query_cli_test.aipl` | `./bin/aipl test tests/examples/ex_070_encoding_json_jq_query_cli_test.aipl` |
| `ex_071` | [examples/ex_071_encoding_toml_manifest_cli.aipl](../../examples/ex_071_encoding_toml_manifest_cli.aipl) | `tests/examples/ex_071_encoding_toml_manifest_cli_test.aipl` | `./bin/aipl test tests/examples/ex_071_encoding_toml_manifest_cli_test.aipl` |
| `ex_072` | [examples/ex_072_encoding_yaml_pipeline_cli.aipl](../../examples/ex_072_encoding_yaml_pipeline_cli.aipl) | `tests/examples/ex_072_encoding_yaml_pipeline_cli_test.aipl` | `./bin/aipl test tests/examples/ex_072_encoding_yaml_pipeline_cli_test.aipl` |
| `ex_073` | [examples/ex_073_encoding_csv_analytics_cli.aipl](../../examples/ex_073_encoding_csv_analytics_cli.aipl) | `tests/examples/ex_073_encoding_csv_analytics_cli_test.aipl` | `./bin/aipl test tests/examples/ex_073_encoding_csv_analytics_cli_test.aipl` |
| `ex_074` | [examples/ex_074_encoding_xml_xpath_cli.aipl](../../examples/ex_074_encoding_xml_xpath_cli.aipl) | `tests/examples/ex_074_encoding_xml_xpath_cli_test.aipl` | `./bin/aipl test tests/examples/ex_074_encoding_xml_xpath_cli_test.aipl` |

---

### Chapter 06.2: Lossless Compression & Archive Streams (Deflate, Gzip, LZ4, Zstd, Tar)

#### 1. Concept in 30 Seconds
Teach high-speed block and stream compression (`std/compress/deflate`, `gzip`, `lz4`, `zstd`) and POSIX `tar` archiving (`std/compress/tar_archive`).

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn lz4CompressBlock(src: bytes): bytes:` from `std/compress/lz4.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.compress.lz4_z1_test
import * from "std/compress/lz4"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_lz4_lz4CompressBlock_1(): int:
  let arg_src = [65, 73, 80, 76]
  let edge_src = [65]
  let resNom = lz4CompressBlock(arg_src)
  let resEdge = lz4CompressBlock(edge_src)
  assertEqInt(resNom.len(), 5, "lz4CompressBlock nominal resNom.len() == 5")
  assertEqInt(resEdge.len(), 2, "lz4CompressBlock boundary resEdge.len() == 2")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_082` | [examples/ex_082_compress_deflate_huffman_cli.aipl](../../examples/ex_082_compress_deflate_huffman_cli.aipl) | `tests/examples/ex_082_compress_deflate_huffman_cli_test.aipl` | `./bin/aipl test tests/examples/ex_082_compress_deflate_huffman_cli_test.aipl` |
| `ex_083` | [examples/ex_083_compress_gzip_crc32_tool_cli.aipl](../../examples/ex_083_compress_gzip_crc32_tool_cli.aipl) | `tests/examples/ex_083_compress_gzip_crc32_tool_cli_test.aipl` | `./bin/aipl test tests/examples/ex_083_compress_gzip_crc32_tool_cli_test.aipl` |
| `ex_084` | [examples/ex_084_compress_lz4_highspeed_cli.aipl](../../examples/ex_084_compress_lz4_highspeed_cli.aipl) | `tests/examples/ex_084_compress_lz4_highspeed_cli_test.aipl` | `./bin/aipl test tests/examples/ex_084_compress_lz4_highspeed_cli_test.aipl` |
| `ex_085` | [examples/ex_085_compress_zstd_dictionary_cli.aipl](../../examples/ex_085_compress_zstd_dictionary_cli.aipl) | `tests/examples/ex_085_compress_zstd_dictionary_cli_test.aipl` | `./bin/aipl test tests/examples/ex_085_compress_zstd_dictionary_cli_test.aipl` |
| `ex_086` | [examples/ex_086_compress_tar_archive_bundler_cli.aipl](../../examples/ex_086_compress_tar_archive_bundler_cli.aipl) | `tests/examples/ex_086_compress_tar_archive_bundler_cli_test.aipl` | `./bin/aipl test tests/examples/ex_086_compress_tar_archive_bundler_cli_test.aipl` |

---

### Chapter 06.3: Cryptographic Hashing, AEAD Encryption, Signatures & Password KDFs (std/crypto/*)

#### 1. Concept in 30 Seconds
Teach `sha256`, `blake3`, `hmac` (RFC 2104), `chacha20_poly1305` (RFC 8439 AEAD), `ed25519`, `argon2` KDF, and `csprng` entropy generation.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn sha256(data: bytes): bytes:` from `std/crypto/hash.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.crypto.hash_z1_test
import * from "std/crypto/hash"
import { hexEncode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_sha256_1(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let resNom = sha256(arg_data)
  let resEdge = sha256(edge_data)
  assertEqInt(resNom.len(), 32, "sha256 nominal resNom.len() == 32")
  assertEqInt(resEdge.len(), 32, "sha256 boundary resEdge.len() == 32")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_087` | [examples/ex_087_crypto_sha256_blake3_shasum_cli.aipl](../../examples/ex_087_crypto_sha256_blake3_shasum_cli.aipl) | `tests/examples/ex_087_crypto_sha256_blake3_shasum_cli_test.aipl` | `./bin/aipl test tests/examples/ex_087_crypto_sha256_blake3_shasum_cli_test.aipl` |
| `ex_088` | [examples/ex_088_crypto_hmac_jwt_token_cli.aipl](../../examples/ex_088_crypto_hmac_jwt_token_cli.aipl) | `tests/examples/ex_088_crypto_hmac_jwt_token_cli_test.aipl` | `./bin/aipl test tests/examples/ex_088_crypto_hmac_jwt_token_cli_test.aipl` |
| `ex_089` | [examples/ex_089_crypto_kdf_pbkdf2_hkdf_cli.aipl](../../examples/ex_089_crypto_kdf_pbkdf2_hkdf_cli.aipl) | `tests/examples/ex_089_crypto_kdf_pbkdf2_hkdf_cli_test.aipl` | `./bin/aipl test tests/examples/ex_089_crypto_kdf_pbkdf2_hkdf_cli_test.aipl` |
| `ex_090` | [examples/ex_090_crypto_aead_chacha20_poly1305_cli.aipl](../../examples/ex_090_crypto_aead_chacha20_poly1305_cli.aipl) | `tests/examples/ex_090_crypto_aead_chacha20_poly1305_cli_test.aipl` | `./bin/aipl test tests/examples/ex_090_crypto_aead_chacha20_poly1305_cli_test.aipl` |
| `ex_091` | [examples/ex_091_crypto_csprng_uuid_generator_cli.aipl](../../examples/ex_091_crypto_csprng_uuid_generator_cli.aipl) | `tests/examples/ex_091_crypto_csprng_uuid_generator_cli_test.aipl` | `./bin/aipl test tests/examples/ex_091_crypto_csprng_uuid_generator_cli_test.aipl` |
| `ex_092` | [examples/ex_092_crypto_tls_handshake_inspector_cli.aipl](../../examples/ex_092_crypto_tls_handshake_inspector_cli.aipl) | `tests/examples/ex_092_crypto_tls_handshake_inspector_cli_test.aipl` | `./bin/aipl test tests/examples/ex_092_crypto_tls_handshake_inspector_cli_test.aipl` |

---

### Chapter 06.4: Embedded ACID Persistence (KV-WAL Store & Relational B-Tree SQLite Engine)

#### 1. Concept in 30 Seconds
Teach append-only CRC-verified log storage (`std/db/kv_wal`) and relational SQL tables, B-tree indexes, and savepoint rollback (`std/db/sqlite`).

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `fn sqlValNull(): SqliteValue:` from `std/db/sqlite.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.db.sqlite_z1_test
import * from "std/db/sqlite"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sqlite_sqlValNull_1(): int:
  let resNom = sqlValNull()
  let resEdge = sqlValNull()
  assertEqInt(resNom.kind, 0, "sqlValNull nominal resNom.kind == 0")
  assertEqInt(resEdge.kind, 0, "sqlValNull boundary resEdge.kind == 0")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_094` | [examples/ex_094_db_kv_wal_acid_store_cli.aipl](../../examples/ex_094_db_kv_wal_acid_store_cli.aipl) | `tests/examples/ex_094_db_kv_wal_acid_store_cli_test.aipl` | `./bin/aipl test tests/examples/ex_094_db_kv_wal_acid_store_cli_test.aipl` |
| `ex_095` | [examples/ex_095_io_stdio_interactive_prompt_cli.aipl](../../examples/ex_095_io_stdio_interactive_prompt_cli.aipl) | `tests/examples/ex_095_io_stdio_interactive_prompt_cli_test.aipl` | `./bin/aipl test tests/examples/ex_095_io_stdio_interactive_prompt_cli_test.aipl` |
| `ex_096` | [examples/ex_096_io_buffered_reader_writer_cli.aipl](../../examples/ex_096_io_buffered_reader_writer_cli.aipl) | `tests/examples/ex_096_io_buffered_reader_writer_cli_test.aipl` | `./bin/aipl test tests/examples/ex_096_io_buffered_reader_writer_cli_test.aipl` |
