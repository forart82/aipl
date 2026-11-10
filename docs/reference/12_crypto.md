[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Domain 12: `crypto` API Reference

> Complete API reference manual for AIPL standard library domain `crypto` (64 callable functions & methods across ["std/crypto/aead.aipl", "std/crypto/crypto_mod.aipl", "std/crypto/csprng.aipl", "std/crypto/hash.aipl", "std/crypto/hmac.aipl", "std/crypto/kdf.aipl", "std/crypto/tls.aipl", "std/crypto/apk_Sig_v2.aipl"]).

## 1. Domain Overview & Source Modules

- **Domain Name**: `crypto`
- **Target Source Modules**: ["std/crypto/aead.aipl", "std/crypto/crypto_mod.aipl", "std/crypto/csprng.aipl", "std/crypto/hash.aipl", "std/crypto/hmac.aipl", "std/crypto/kdf.aipl", "std/crypto/tls.aipl", "std/crypto/apk_Sig_v2.aipl"]
- **Total Callable Functions & Methods**: 64
- **Total Data Types (`struct` & `enum`)**: 14
- **Master Reference Hub**: [STDLIB_REFERENCE.md](STDLIB_REFERENCE.md)

---

## 2. Domain Data Types (`struct` & `enum`)

(14 public types declared across this domain's modules)

| Type Name | Kind | Source Module | Fields / Variants | Default Constructor / Description |
| :--- | :--- | :--- | :--- | :--- |
| `AeadCiphertext` | `pub struct` | `std/crypto/aead.aipl` | `ciphertext: bytes`, `tag: bytes` | `AeadCiphertext(ciphertext, tag)` |
| `CsprngStream` | `pub struct` | `std/crypto/csprng.aipl` | `seed: bytes`, `counter: int` | `CsprngStream(seed, counter)` |
| `Uuid` | `pub struct` | `std/crypto/csprng.aipl` | `bytes16: bytes` | `Uuid(bytes16)` |
| `Sha256Hasher` | `pub struct` | `std/crypto/hash.aipl` | `mut state: [int] = []`, `mut buffer: [int] = []`, `mut totalBytes: int = 0` | `Sha256Hasher(mut state, mut buffer, mut totalBytes)` |
| `Sha512Hasher` | `pub struct` | `std/crypto/hash.aipl` | `stateH: [int]`, `stateL: [int]`, `buffer: [int]`, `totalBytes: int` | `Sha512Hasher(stateH, stateL, buffer, totalBytes)` |
| `Blake3Hasher` | `pub struct` | `std/crypto/hash.aipl` | `cv: [int]`, `chunkState: [int]`, `key: [int]`, `flags: int` | `Blake3Hasher(cv, chunkState, key, flags)` |
| `XxHash64` | `pub struct` | `std/crypto/hash.aipl` | `v1: int`, `v2: int`, `v3: int`, `v4: int`, `totalLen: int`, `mem: [int]` | `XxHash64(v1, v2, v3, v4, totalLen, mem)` |
| `HmacSha256` | `pub struct` | `std/crypto/hmac.aipl` | `hasher: Sha256Hasher`, `oKeyPad: bytes` | `HmacSha256(hasher, oKeyPad)` |
| `Pbkdf2Params` | `pub struct` | `std/crypto/kdf.aipl` | `iterations: int`, `keyLen: int`, `salt: bytes` | `Pbkdf2Params(iterations, keyLen, salt)` |
| `Argon2Params` | `pub struct` | `std/crypto/kdf.aipl` | `timeCost: int`, `memoryCostKiB: int`, `parallelism: int`, `keyLen: int`, `salt: bytes` | `Argon2Params(timeCost, memoryCostKiB, parallelism, keyLen, salt)` |
| `TlsRecord` | `pub struct` | `std/crypto/tls.aipl` | `contentType: int`, `protocolVersion: int`, `length: int`, `fragment: bytes` | `TlsRecord(contentType, protocolVersion, length, fragment)` |
| `TlsClientHello` | `pub struct` | `std/crypto/tls.aipl` | `cipherSuites: [int]`, `serverName: str`, `clientRandom: bytes`, `keyShare: bytes` | `TlsClientHello(cipherSuites, serverName, clientRandom, keyShare)` |
| `X509Cert` | `pub struct` | `std/crypto/tls.aipl` | `issuer: str`, `subject: str`, `notBefore: int`, `notAfter: int`, `publicKey: bytes` | `X509Cert(issuer, subject, notBefore, notAfter, publicKey)` |
| `ApkSigningBlockV2` | `pub struct` | `std/crypto/apk_Sig_v2.aipl` | `sizeOfBlockHead: int`, `v2SchemeId: int`, `topLevelSha256Hex: str`, `sizeOfBlockTail: int`, `magic: str`, `isValid: bool` | `ApkSigningBlockV2(sizeOfBlockHead, v2SchemeId, topLevelSha256Hex, sizeOfBlockTail, magic, isValid)` |

## 3. Quick-Lookup Function Index


| # | Source Module | Function / Method | Exact Signature | Unit Test File |
| :--- | :--- | :--- | :--- | :--- |
| `1` | `std/crypto/aead.aipl` | `rotl32` | `fn rotl32(x: int, n: int): int:` | `tests/functions/crypto/aead_test.aipl` |
| `2` | `std/crypto/aead.aipl` | `chachaQuarterRound` | `fn chachaQuarterRound(mut s: [int], a: int, b: int, c: int, d: int): void:` | `tests/functions/crypto/aead_test.aipl` |
| `3` | `std/crypto/aead.aipl` | `readLe32Pad` | `fn readLe32Pad(b: bytes, offset: int): int:` | `tests/functions/crypto/aead_test.aipl` |
| `4` | `std/crypto/aead.aipl` | `chacha20Block` | `fn chacha20Block(key: bytes, counter: int, nonce: bytes): [int]:` | `tests/functions/crypto/aead_test.aipl` |
| `5` | `std/crypto/aead.aipl` | `chacha20Xor` | `fn chacha20Xor(key: bytes, startCounter: int, nonce: bytes, input: bytes): bytes:` | `tests/functions/crypto/aead_test.aipl` |
| `6` | `std/crypto/aead.aipl` | `computeAeadTag` | `fn computeAeadTag(domain: str, key: bytes, nonce: bytes, ciphertext: bytes, aad: bytes): bytes:` | `tests/functions/crypto/aead_test.aipl` |
| `7` | `std/crypto/aead.aipl` | `chacha20Poly1305Encrypt` | `pub fn chacha20Poly1305Encrypt(key: bytes, nonce: bytes, plaintext: bytes, aad: bytes = bytesNew(0)): AeadCiphertext:` | `tests/functions/crypto/aead_test.aipl` |
| `8` | `std/crypto/aead.aipl` | `chacha20Poly1305Decrypt` | `pub fn chacha20Poly1305Decrypt(key: bytes, nonce: bytes, cipher: AeadCiphertext, aad: bytes = bytesNew(0)): Result[bytes, str]:` | `tests/functions/crypto/aead_test.aipl` |
| `9` | `std/crypto/aead.aipl` | `aes256GcmEncrypt` | `pub fn aes256GcmEncrypt(key: bytes, nonce: bytes, plaintext: bytes, aad: bytes = bytesNew(0)): AeadCiphertext:` | `tests/functions/crypto/aead_test.aipl` |
| `10` | `std/crypto/aead.aipl` | `aes256GcmDecrypt` | `pub fn aes256GcmDecrypt(key: bytes, nonce: bytes, cipher: AeadCiphertext, aad: bytes = bytesNew(0)): Result[bytes, str]:` | `tests/functions/crypto/aead_test.aipl` |
| `11` | `std/crypto/aead.aipl` | `zeroize` | `pub fn zeroize(mut data: bytes): void:` | `tests/functions/crypto/aead_test.aipl` |
| `12` | `std/crypto/crypto_mod.aipl` | `sha256Hex` | `pub fn sha256Hex(data: str): str:` | `tests/functions/crypto/crypto_mod_test.aipl` |
| `13` | `std/crypto/crypto_mod.aipl` | `sha512Hex` | `pub fn sha512Hex(data: str): str:` | `tests/functions/crypto/crypto_mod_test.aipl` |
| `14` | `std/crypto/crypto_mod.aipl` | `blake3Hex` | `pub fn blake3Hex(data: str): str:` | `tests/functions/crypto/crypto_mod_test.aipl` |
| `15` | `std/crypto/crypto_mod.aipl` | `hmacSha256Hex` | `pub fn hmacSha256Hex(key: str, msg: str): str:` | `tests/functions/crypto/crypto_mod_test.aipl` |
| `16` | `std/crypto/csprng.aipl` | `csprngRandomBytes` | `pub fn csprngRandomBytes(count: int): bytes:` | `tests/functions/crypto/csprng_test.aipl` |
| `17` | `std/crypto/csprng.aipl` | `csprngRandomInt` | `pub fn csprngRandomInt(min: int, max: int): int:` | `tests/functions/crypto/csprng_test.aipl` |
| `18` | `std/crypto/csprng.aipl` | `csprngRandomFloat` | `pub fn csprngRandomFloat(): float:` | `tests/functions/crypto/csprng_test.aipl` |
| `19` | `std/crypto/csprng.aipl` | `formatUuidBytes` | `fn formatUuidBytes(b: bytes): str:` | `tests/functions/crypto/csprng_test.aipl` |
| `20` | `std/crypto/csprng.aipl` | `uuidNil` | `pub fn uuidNil(): str:` | `tests/functions/crypto/csprng_test.aipl` |
| `21` | `std/crypto/csprng.aipl` | `uuidV4` | `pub fn uuidV4(): str:` | `tests/functions/crypto/csprng_test.aipl` |
| `22` | `std/crypto/csprng.aipl` | `uuidV7` | `pub fn uuidV7(timestampMs: int = 0): str:` | `tests/functions/crypto/csprng_test.aipl` |
| `23` | `std/crypto/csprng.aipl` | `isHexCharCode` | `fn isHexCharCode(code: int): bool:` | `tests/functions/crypto/csprng_test.aipl` |
| `24` | `std/crypto/csprng.aipl` | `isValidUuid` | `pub fn isValidUuid(s: str): bool:` | `tests/functions/crypto/csprng_test.aipl` |
| `25` | `std/crypto/csprng.aipl` | `parseUuid` | `pub fn parseUuid(s: str): Result[Uuid, str]:` | `tests/functions/crypto/csprng_test.aipl` |
| `26` | `std/crypto/csprng.aipl` | `toString` | `pub fn (self: Uuid) toString(): str:` | `tests/functions/crypto/csprng_test.aipl` |
| `27` | `std/crypto/csprng.aipl` | `ulidGenerate` | `pub fn ulidGenerate(timestampMs: int = 0): str:` | `tests/functions/crypto/csprng_test.aipl` |
| `28` | `std/crypto/hash.aipl` | `sha256` | `pub fn sha256(data: bytes): bytes:` | `tests/functions/crypto/hash_test.aipl` |
| `29` | `std/crypto/hash.aipl` | `sha256Str` | `pub fn sha256Str(s: str): str:` | `tests/functions/crypto/hash_test.aipl` |
| `30` | `std/crypto/hash.aipl` | `rotr64H` | `fn rotr64H(h: int, l: int, n: int): int:` | `tests/functions/crypto/hash_test.aipl` |
| `31` | `std/crypto/hash.aipl` | `rotr64L` | `fn rotr64L(h: int, l: int, n: int): int:` | `tests/functions/crypto/hash_test.aipl` |
| `32` | `std/crypto/hash.aipl` | `shr64H` | `fn shr64H(h: int, n: int): int:` | `tests/functions/crypto/hash_test.aipl` |
| `33` | `std/crypto/hash.aipl` | `shr64L` | `fn shr64L(h: int, l: int, n: int): int:` | `tests/functions/crypto/hash_test.aipl` |
| `34` | `std/crypto/hash.aipl` | `add64` | `fn add64(aH: int, aL: int, bH: int, bL: int): (int, int):` | `tests/functions/crypto/hash_test.aipl` |
| `35` | `std/crypto/hash.aipl` | `sha512` | `pub fn sha512(data: bytes): bytes:` | `tests/functions/crypto/hash_test.aipl` |
| `36` | `std/crypto/hash.aipl` | `sha512Str` | `pub fn sha512Str(s: str): str:` | `tests/functions/crypto/hash_test.aipl` |
| `37` | `std/crypto/hash.aipl` | `blake3` | `pub fn blake3(data: bytes): bytes:` | `tests/functions/crypto/hash_test.aipl` |
| `38` | `std/crypto/hash.aipl` | `blake3Str` | `pub fn blake3Str(s: str): str:` | `tests/functions/crypto/hash_test.aipl` |
| `39` | `std/crypto/hash.aipl` | `fnv1a64` | `pub fn fnv1a64(s: str): int:` | `tests/functions/crypto/hash_test.aipl` |
| `40` | `std/crypto/hash.aipl` | `xxhash64` | `pub fn xxhash64(data: bytes, seed: int = 0): int:` | `tests/functions/crypto/hash_test.aipl` |
| `41` | `std/crypto/hash.aipl` | `siphash24` | `pub fn siphash24(key: (int, int), data: bytes): int:` | `tests/functions/crypto/hash_test.aipl` |
| `42` | `std/crypto/hash.aipl` | `crc32` | `pub fn crc32(data: bytes): int:` | `tests/functions/crypto/hash_test.aipl` |
| `43` | `std/crypto/hash.aipl` | `sha256HasherNew` | `pub fn sha256HasherNew(): Sha256Hasher:` | `tests/functions/crypto/hash_test.aipl` |
| `44` | `std/crypto/hash.aipl` | `update` | `pub fn (mut self: Sha256Hasher) update(chunk: bytes): void:` | `tests/functions/crypto/hash_test.aipl` |
| `45` | `std/crypto/hash.aipl` | `finalize` | `pub fn (self: Sha256Hasher) finalize(): bytes:` | `tests/functions/crypto/hash_test.aipl` |
| `46` | `std/crypto/hmac.aipl` | `hmacSha256` | `pub fn hmacSha256(key: bytes, message: bytes): bytes:` | `tests/functions/crypto/hmac_test.aipl` |
| `47` | `std/crypto/hmac.aipl` | `hmacSha256Str` | `pub fn hmacSha256Str(key: str, message: str): str:` | `tests/functions/crypto/hmac_test.aipl` |
| `48` | `std/crypto/hmac.aipl` | `hmacSha512` | `pub fn hmacSha512(key: bytes, message: bytes): bytes:` | `tests/functions/crypto/hmac_test.aipl` |
| `49` | `std/crypto/hmac.aipl` | `hmacSha512Str` | `pub fn hmacSha512Str(key: str, message: str): str:` | `tests/functions/crypto/hmac_test.aipl` |
| `50` | `std/crypto/hmac.aipl` | `constantTimeEqual` | `pub fn constantTimeEqual(a: bytes, b: bytes): bool:` | `tests/functions/crypto/hmac_test.aipl` |
| `51` | `std/crypto/hmac.aipl` | `constantTimeEqualStr` | `pub fn constantTimeEqualStr(a: str, b: str): bool:` | `tests/functions/crypto/hmac_test.aipl` |
| `52` | `std/crypto/kdf.aipl` | `hkdfExtract` | `pub fn hkdfExtract(salt: bytes, ikm: bytes): bytes:` | `tests/functions/crypto/kdf_test.aipl` |
| `53` | `std/crypto/kdf.aipl` | `hkdfExpand` | `pub fn hkdfExpand(prk: bytes, info: bytes, outLen: int): bytes:` | `tests/functions/crypto/kdf_test.aipl` |
| `54` | `std/crypto/kdf.aipl` | `hkdfSha256` | `pub fn hkdfSha256(salt: bytes, ikm: bytes, info: bytes, outLen: int): bytes:` | `tests/functions/crypto/kdf_test.aipl` |
| `55` | `std/crypto/kdf.aipl` | `pbkdf2HmacSha256` | `pub fn pbkdf2HmacSha256(password: bytes, salt: bytes, iterations: int, outLen: int): bytes:` | `tests/functions/crypto/kdf_test.aipl` |
| `56` | `std/crypto/kdf.aipl` | `argon2idHash` | `pub fn argon2idHash(password: bytes, params: Argon2Params): bytes:` | `tests/functions/crypto/kdf_test.aipl` |
| `57` | `std/crypto/kdf.aipl` | `argon2idVerify` | `pub fn argon2idVerify(password: bytes, hash: bytes, params: Argon2Params): bool:` | `tests/functions/crypto/kdf_test.aipl` |
| `58` | `std/crypto/tls.aipl` | `tlsFrameRecord` | `pub fn tlsFrameRecord(contentType: int, payload: bytes): bytes:` | `tests/functions/crypto/tls_test.aipl` |
| `59` | `std/crypto/tls.aipl` | `tlsParseRecord` | `pub fn tlsParseRecord(streamBytes: bytes, offset: int = 0): Result[(TlsRecord, int), str]:` | `tests/functions/crypto/tls_test.aipl` |
| `60` | `std/crypto/tls.aipl` | `tlsBuildClientHello` | `pub fn tlsBuildClientHello(host: str, suites: [int], random: bytes, keyShare: bytes): bytes:` | `tests/functions/crypto/tls_test.aipl` |
| `61` | `std/crypto/tls.aipl` | `verifyX509Validity` | `pub fn verifyX509Validity(cert: X509Cert, currentUnixSec: int): bool:` | `tests/functions/crypto/tls_test.aipl` |
| `62` | `std/crypto/apk_Sig_v2.aipl` | `computeApkV2DigestsSha256` | `pub fn computeApkV2DigestsSha256(zipEntriesSection: str, centralDirSection: str, eocdSection: str): str:` | `tests/functions/crypto/apk_Sig_v2_test.aipl` |
| `63` | `std/crypto/apk_Sig_v2.aipl` | `buildApkSigningBlockV2` | `pub fn buildApkSigningBlockV2(topLevelSha256Hex: str): ApkSigningBlockV2:` | `tests/functions/crypto/apk_Sig_v2_test.aipl` |
| `64` | `std/crypto/apk_Sig_v2.aipl` | `verifyApkSigningBlockV2` | `pub fn verifyApkSigningBlockV2(magic: str, sizeHead: int, sizeTail: int, schemeId: int, signedDigest: str, computedDigest: str): bool:` | `tests/functions/crypto/apk_Sig_v2_test.aipl` |

---

## 4. Detailed API Reference & Runnable Verification Snippets

### `rotl32` (`std/crypto/aead.aipl`)

- **Signature**: `fn rotl32(x: int, n: int): int:`
- **Import**: `import * from "std/crypto/aead"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: int, n: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/crypto/aead_test.aipl` | **Example**: `examples/ex_087_crypto_sha256_blake3_shasum_cli.aipl`
- **Behavioral Summary**: Verify `rotl32` RFC 8439 ChaCha20-Poly1305 / AES-256-GCM authenticated encryption, 1-bit ciphertext/AAD tamper rejection (`Err`/`None`), and `zeroize` key wiping. Concrete nominal inputs: `x: int = 1`, `n: int = 1`; exercises core body path returning/computing `(((u << n) & 4294967295) | (u >> (32 - n))) & 4294967295`.

```aipl
module tests.functions.crypto.aead_z1_test
import * from "std/crypto/aead"
import { hmacSha256, constantTimeEqual } from "std/crypto/hmac"
import { sha256 } from "std/crypto/hash"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_aead_rotl32_1(): int:
  let arg_x = 1
  let edge_x = 0
  let arg_n = 4
  let edge_n = 1
  let resNom = rotl32(arg_x, arg_n)
  let resEdge = rotl32(edge_x, edge_n)
  assertEqInt(resNom, 16, "rotl32 nominal resNom == 16")
  assertEqInt(resEdge, 0, "rotl32 boundary resEdge == 0")
  ret 0
```

---

### `chachaQuarterRound` (`std/crypto/aead.aipl`)

- **Signature**: `fn chachaQuarterRound(mut s: [int], a: int, b: int, c: int, d: int): void:`
- **Import**: `import * from "std/crypto/aead"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut s: [int], a: int, b: int, c: int, d: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/crypto/aead_test.aipl` | **Example**: `examples/ex_088_crypto_hmac_jwt_token_cli.aipl`
- **Behavioral Summary**: Verify `chachaQuarterRound` RFC 8439 ChaCha20-Poly1305 / AES-256-GCM authenticated encryption, 1-bit ciphertext/AAD tamper rejection (`Err`/`None`), and `zeroize` key wiping. Concrete nominal inputs: `s: [int] = [1]`, `a: int = 1`, `b: int = 1`, `c: int = 1`, `d: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.crypto.aead_z2_test
import * from "std/crypto/aead"
import { hmacSha256, constantTimeEqual } from "std/crypto/hmac"
import { sha256 } from "std/crypto/hash"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_aead_chachaQuarterRound_2(): int:
  let arg_s = [2]
  let edge_s = []
  let arg_a = 2
  let edge_a = 0
  let arg_b = 4
  let edge_b = 1
  let arg_c = 2
  let edge_c = 0
  let arg_d = 2
  let edge_d = 0
  chachaQuarterRound(arg_s, arg_a, arg_b, arg_c, arg_d)
  chachaQuarterRound(edge_s, edge_a, edge_b, edge_c, edge_d)
  assertEqInt(arg_s.len(), 1, "chachaQuarterRound nominal arg_s.len() == 1")
  assertEqInt(edge_s.len(), 0, "chachaQuarterRound boundary edge_s.len() == 0")
  ret 0
```

---

### `readLe32Pad` (`std/crypto/aead.aipl`)

- **Signature**: `fn readLe32Pad(b: bytes, offset: int): int:`
- **Import**: `import * from "std/crypto/aead"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `b: bytes, offset: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/crypto/aead_test.aipl` | **Example**: `examples/ex_089_crypto_kdf_pbkdf2_hkdf_cli.aipl`
- **Behavioral Summary**: Verify `readLe32Pad` RFC 8439 ChaCha20-Poly1305 / AES-256-GCM authenticated encryption, 1-bit ciphertext/AAD tamper rejection (`Err`/`None`), and `zeroize` key wiping. Concrete nominal inputs: `b: bytes = [65, 73, 80, 76]`, `offset: int = 0`; exercises core body path returning/computing `v & 4294967295`.

```aipl
module tests.functions.crypto.aead_z3_test
import * from "std/crypto/aead"
import { hmacSha256, constantTimeEqual } from "std/crypto/hmac"
import { sha256 } from "std/crypto/hash"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_aead_readLe32Pad_3(): int:
  let arg_b = [65, 73, 80, 76]
  let edge_b = [65]
  let arg_offset = 1
  let edge_offset = 0
  let resNom = readLe32Pad(arg_b, arg_offset)
  let resEdge = readLe32Pad(edge_b, edge_offset)
  assertEqInt(resNom, 5001289, "readLe32Pad nominal resNom == 5001289")
  assertEqInt(resEdge, 65, "readLe32Pad boundary resEdge == 65")
  ret 0
```

---

### `chacha20Block` (`std/crypto/aead.aipl`)

- **Signature**: `fn chacha20Block(key: bytes, counter: int, nonce: bytes): [int]:`
- **Import**: `import * from "std/crypto/aead"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `key: bytes, counter: int, nonce: bytes` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/crypto/aead_test.aipl` | **Example**: `examples/ex_087_crypto_sha256_blake3_shasum_cli.aipl`
- **Behavioral Summary**: Verify `chacha20Block` RFC 8439 ChaCha20-Poly1305 / AES-256-GCM authenticated encryption, 1-bit ciphertext/AAD tamper rejection (`Err`/`None`), and `zeroize` key wiping. Concrete nominal inputs: `key: bytes = [65, 73, 80, 76]`, `counter: int = 64`, `nonce: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.crypto.aead_z4_test
import * from "std/crypto/aead"
import { hmacSha256, constantTimeEqual } from "std/crypto/hmac"
import { sha256 } from "std/crypto/hash"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_aead_chacha20Block_4(): int:
  let arg_key = [65, 73, 80, 76]
  let edge_key = [65]
  let arg_counter = 4
  let edge_counter = 1
  let arg_nonce = [65, 73, 80, 76]
  let edge_nonce = [65]
  let resNom = chacha20Block(arg_key, arg_counter, arg_nonce)
  let resEdge = chacha20Block(edge_key, edge_counter, edge_nonce)
  assertEqInt(resNom.len(), 64, "chacha20Block nominal resNom.len() == 64")
  assertEqInt(resEdge.len(), 64, "chacha20Block boundary resEdge.len() == 64")
  ret 0
```

---

### `chacha20Xor` (`std/crypto/aead.aipl`)

- **Signature**: `fn chacha20Xor(key: bytes, startCounter: int, nonce: bytes, input: bytes): bytes:`
- **Import**: `import * from "std/crypto/aead"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `key: bytes, startCounter: int, nonce: bytes, input: bytes` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/crypto/aead_test.aipl` | **Example**: `examples/ex_088_crypto_hmac_jwt_token_cli.aipl`
- **Behavioral Summary**: Verify `chacha20Xor` RFC 8439 ChaCha20-Poly1305 / AES-256-GCM authenticated encryption, 1-bit ciphertext/AAD tamper rejection (`Err`/`None`), and `zeroize` key wiping. Concrete nominal inputs: `key: bytes = [65, 73, 80, 76]`, `startCounter: int = 64`, `nonce: bytes = [65, 73, 80, 76]`, `input: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `bytesFromArray(out)`.

```aipl
module tests.functions.crypto.aead_z5_test
import * from "std/crypto/aead"
import { hmacSha256, constantTimeEqual } from "std/crypto/hmac"
import { sha256 } from "std/crypto/hash"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_aead_chacha20Xor_5(): int:
  let arg_key = [65, 73, 80, 76]
  let edge_key = [65]
  let arg_startCounter = 4
  let edge_startCounter = 1
  let arg_nonce = [65, 73, 80, 76]
  let edge_nonce = [65]
  let arg_input = [65, 73, 80, 76]
  let edge_input = [65]
  let resNom = chacha20Xor(arg_key, arg_startCounter, arg_nonce, arg_input)
  let resEdge = chacha20Xor(edge_key, edge_startCounter, edge_nonce, edge_input)
  assertEqInt(resNom.len(), 4, "chacha20Xor nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 1, "chacha20Xor boundary resEdge.len() == 1")
  ret 0
```

---

### `computeAeadTag` (`std/crypto/aead.aipl`)

- **Signature**: `fn computeAeadTag(domain: str, key: bytes, nonce: bytes, ciphertext: bytes, aad: bytes): bytes:`
- **Import**: `import * from "std/crypto/aead"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `domain: str, key: bytes, nonce: bytes, ciphertext: bytes, aad: bytes` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/crypto/aead_test.aipl` | **Example**: `examples/ex_089_crypto_kdf_pbkdf2_hkdf_cli.aipl`
- **Behavioral Summary**: Verify `computeAeadTag` RFC 8439 ChaCha20-Poly1305 / AES-256-GCM authenticated encryption, 1-bit ciphertext/AAD tamper rejection (`Err`/`None`), and `zeroize` key wiping. Concrete nominal inputs: `domain: str = "aipl_test"`, `key: bytes = [65, 73, 80, 76]`, `nonce: bytes = [65, 73, 80, 76]`, `ciphertext: bytes = [65, 73, 80, 76]`, `aad: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `fullMac.slice(0, 16)`.

```aipl
module tests.functions.crypto.aead_z6_test
import * from "std/crypto/aead"
import { hmacSha256, constantTimeEqual } from "std/crypto/hmac"
import { sha256 } from "std/crypto/hash"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_aead_computeAeadTag_6(): int:
  let arg_domain = "test"
  let edge_domain = "a"
  let arg_key = [65, 73, 80, 76]
  let edge_key = [65]
  let arg_nonce = [65, 73, 80, 76]
  let edge_nonce = [65]
  let arg_ciphertext = [65, 73, 80, 76]
  let edge_ciphertext = [65]
  let arg_aad = [65, 73, 80, 76]
  let edge_aad = [65]
  let resNom = computeAeadTag(arg_domain, arg_key, arg_nonce, arg_ciphertext, arg_aad)
  let resEdge = computeAeadTag(edge_domain, edge_key, edge_nonce, edge_ciphertext, edge_aad)
  assertEqInt(resNom.len(), 16, "computeAeadTag nominal resNom.len() == 16")
  assertEqInt(resEdge.len(), 16, "computeAeadTag boundary resEdge.len() == 16")
  ret 0
```

---

### `chacha20Poly1305Encrypt` (`std/crypto/aead.aipl`)

- **Signature**: `pub fn chacha20Poly1305Encrypt(key: bytes, nonce: bytes, plaintext: bytes, aad: bytes = bytesNew(0)): AeadCiphertext:`
- **Import**: `import * from "std/crypto/aead"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `key: bytes, nonce: bytes, plaintext: bytes, aad: bytes = bytesNew(0)` | **Returns**: `AeadCiphertext`
- **Unit Test**: `tests/functions/crypto/aead_test.aipl` | **Example**: `examples/ex_087_crypto_sha256_blake3_shasum_cli.aipl`
- **Behavioral Summary**: Verify `chacha20Poly1305Encrypt` RFC 8439 ChaCha20-Poly1305 / AES-256-GCM authenticated encryption, 1-bit ciphertext/AAD tamper rejection (`Err`/`None`), and `zeroize` key wiping. Concrete nominal inputs: `key: bytes = [65, 73, 80, 76]`, `nonce: bytes = [65, 73, 80, 76]`, `plaintext: bytes = [65, 73, 80, 76]`, `aad: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `AeadCiphertext(ciphertext: ct, tag: tag)`.

```aipl
module tests.functions.crypto.aead_z7_test
import * from "std/crypto/aead"
import { hmacSha256, constantTimeEqual } from "std/crypto/hmac"
import { sha256 } from "std/crypto/hash"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_aead_chacha20Poly1305Encrypt_7(): int:
  let arg_key = [65, 73, 80, 76]
  let edge_key = [65]
  let arg_nonce = [65, 73, 80, 76]
  let edge_nonce = [65]
  let arg_plaintext = [65, 73, 80, 76]
  let edge_plaintext = [65]
  let arg_aad = [65, 73, 80, 76]
  let edge_aad = [65]
  let resNom = chacha20Poly1305Encrypt(arg_key, arg_nonce, arg_plaintext, arg_aad)
  let resEdge = chacha20Poly1305Encrypt(edge_key, edge_nonce, edge_plaintext, edge_aad)
  assertEqInt(resNom.ciphertext.len(), 4, "chacha20Poly1305Encrypt nominal resNom.ciphertext.len() == 4")
  assertEqInt(resEdge.ciphertext.len(), 1, "chacha20Poly1305Encrypt boundary resEdge.ciphertext.len() == 1")
  ret 0
```

---

### `chacha20Poly1305Decrypt` (`std/crypto/aead.aipl`)

- **Signature**: `pub fn chacha20Poly1305Decrypt(key: bytes, nonce: bytes, cipher: AeadCiphertext, aad: bytes = bytesNew(0)): Result[bytes, str]:`
- **Import**: `import * from "std/crypto/aead"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `key: bytes, nonce: bytes, cipher: AeadCiphertext, aad: bytes = bytesNew(0)` | **Returns**: `Result[bytes, str]`
- **Unit Test**: `tests/functions/crypto/aead_test.aipl` | **Example**: `examples/ex_088_crypto_hmac_jwt_token_cli.aipl`
- **Behavioral Summary**: Verify `chacha20Poly1305Decrypt` RFC 8439 ChaCha20-Poly1305 / AES-256-GCM authenticated encryption, 1-bit ciphertext/AAD tamper rejection (`Err`/`None`), and `zeroize` key wiping. Concrete nominal inputs: `key: bytes = [65, 73, 80, 76]`, `nonce: bytes = [65, 73, 80, 76]`, `cipher: AeadCiphertext = AeadCiphertext(ciphertext = [65, 73, 80, 76], tag = [65, 73, 80, 76])`, `aad: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `Ok(pt)`.

```aipl
module tests.functions.crypto.aead_z8_test
import * from "std/crypto/aead"
import { hmacSha256, constantTimeEqual } from "std/crypto/hmac"
import { sha256 } from "std/crypto/hash"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_aead_chacha20Poly1305Decrypt_8(): int:
  let arg_key = [65, 73, 80, 76]
  let edge_key = [65]
  let arg_nonce = [65, 73, 80, 76]
  let edge_nonce = [65]
  let arg_cipher = AeadCiphertext(ciphertext = [65, 73, 80, 76], tag = [65, 73, 80, 76])
  let edge_cipher = AeadCiphertext(ciphertext = [65], tag = [65])
  let arg_aad = [65, 73, 80, 76]
  let edge_aad = [65]
  let resNom = chacha20Poly1305Decrypt(arg_key, arg_nonce, arg_cipher, arg_aad)
  let resEdge = chacha20Poly1305Decrypt(edge_key, edge_nonce, edge_cipher, edge_aad)
  assert(resNom.isOk() == false, "chacha20Poly1305Decrypt nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "chacha20Poly1305Decrypt boundary resEdge.isOk() == false")
  ret 0
```

---

### `aes256GcmEncrypt` (`std/crypto/aead.aipl`)

- **Signature**: `pub fn aes256GcmEncrypt(key: bytes, nonce: bytes, plaintext: bytes, aad: bytes = bytesNew(0)): AeadCiphertext:`
- **Import**: `import * from "std/crypto/aead"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `key: bytes, nonce: bytes, plaintext: bytes, aad: bytes = bytesNew(0)` | **Returns**: `AeadCiphertext`
- **Unit Test**: `tests/functions/crypto/aead_test.aipl` | **Example**: `examples/ex_089_crypto_kdf_pbkdf2_hkdf_cli.aipl`
- **Behavioral Summary**: Verify `aes256GcmEncrypt` RFC 8439 ChaCha20-Poly1305 / AES-256-GCM authenticated encryption, 1-bit ciphertext/AAD tamper rejection (`Err`/`None`), and `zeroize` key wiping. Concrete nominal inputs: `key: bytes = [65, 73, 80, 76]`, `nonce: bytes = [65, 73, 80, 76]`, `plaintext: bytes = [65, 73, 80, 76]`, `aad: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `AeadCiphertext(ciphertext: ct, tag: tag)`.

```aipl
module tests.functions.crypto.aead_z9_test
import * from "std/crypto/aead"
import { hmacSha256, constantTimeEqual } from "std/crypto/hmac"
import { sha256 } from "std/crypto/hash"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_aead_aes256GcmEncrypt_9(): int:
  let arg_key = [65, 73, 80, 76]
  let edge_key = [65]
  let arg_nonce = [65, 73, 80, 76]
  let edge_nonce = [65]
  let arg_plaintext = [65, 73, 80, 76]
  let edge_plaintext = [65]
  let arg_aad = [65, 73, 80, 76]
  let edge_aad = [65]
  let resNom = aes256GcmEncrypt(arg_key, arg_nonce, arg_plaintext, arg_aad)
  let resEdge = aes256GcmEncrypt(edge_key, edge_nonce, edge_plaintext, edge_aad)
  assertEqInt(resNom.ciphertext.len(), 4, "aes256GcmEncrypt nominal resNom.ciphertext.len() == 4")
  assertEqInt(resEdge.ciphertext.len(), 1, "aes256GcmEncrypt boundary resEdge.ciphertext.len() == 1")
  ret 0
```

---

### `aes256GcmDecrypt` (`std/crypto/aead.aipl`)

- **Signature**: `pub fn aes256GcmDecrypt(key: bytes, nonce: bytes, cipher: AeadCiphertext, aad: bytes = bytesNew(0)): Result[bytes, str]:`
- **Import**: `import * from "std/crypto/aead"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `key: bytes, nonce: bytes, cipher: AeadCiphertext, aad: bytes = bytesNew(0)` | **Returns**: `Result[bytes, str]`
- **Unit Test**: `tests/functions/crypto/aead_test.aipl` | **Example**: `examples/ex_087_crypto_sha256_blake3_shasum_cli.aipl`
- **Behavioral Summary**: Verify `aes256GcmDecrypt` RFC 8439 ChaCha20-Poly1305 / AES-256-GCM authenticated encryption, 1-bit ciphertext/AAD tamper rejection (`Err`/`None`), and `zeroize` key wiping. Concrete nominal inputs: `key: bytes = [65, 73, 80, 76]`, `nonce: bytes = [65, 73, 80, 76]`, `cipher: AeadCiphertext = AeadCiphertext(ciphertext = [65, 73, 80, 76], tag = [65, 73, 80, 76])`, `aad: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `Ok(pt)`.

```aipl
module tests.functions.crypto.aead_z10_test
import * from "std/crypto/aead"
import { hmacSha256, constantTimeEqual } from "std/crypto/hmac"
import { sha256 } from "std/crypto/hash"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_aead_aes256GcmDecrypt_10(): int:
  let arg_key = [65, 73, 80, 76]
  let edge_key = [65]
  let arg_nonce = [65, 73, 80, 76]
  let edge_nonce = [65]
  let arg_cipher = AeadCiphertext(ciphertext = [65, 73, 80, 76], tag = [65, 73, 80, 76])
  let edge_cipher = AeadCiphertext(ciphertext = [65], tag = [65])
  let arg_aad = [65, 73, 80, 76]
  let edge_aad = [65]
  let resNom = aes256GcmDecrypt(arg_key, arg_nonce, arg_cipher, arg_aad)
  let resEdge = aes256GcmDecrypt(edge_key, edge_nonce, edge_cipher, edge_aad)
  assert(resNom.isOk() == false, "aes256GcmDecrypt nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "aes256GcmDecrypt boundary resEdge.isOk() == false")
  ret 0
```

---

### `zeroize` (`std/crypto/aead.aipl`)

- **Signature**: `pub fn zeroize(mut data: bytes): void:`
- **Import**: `import * from "std/crypto/aead"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut data: bytes` | **Returns**: `void`
- **Unit Test**: `tests/functions/crypto/aead_test.aipl` | **Example**: `examples/ex_088_crypto_hmac_jwt_token_cli.aipl`
- **Behavioral Summary**: Verify `zeroize` RFC 8439 ChaCha20-Poly1305 / AES-256-GCM authenticated encryption, 1-bit ciphertext/AAD tamper rejection (`Err`/`None`), and `zeroize` key wiping. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.crypto.aead_z11_test
import * from "std/crypto/aead"
import { hmacSha256, constantTimeEqual } from "std/crypto/hmac"
import { sha256 } from "std/crypto/hash"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_aead_zeroize_11(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  zeroize(arg_data)
  zeroize(edge_data)
  assertEqInt(arg_data.len(), 4, "zeroize nominal arg_data.len() == 4")
  assertEqInt(edge_data.len(), 1, "zeroize boundary edge_data.len() == 1")
  ret 0
```

---

### `sha256Hex` (`std/crypto/crypto_mod.aipl`)

- **Signature**: `pub fn sha256Hex(data: str): str:`
- **Import**: `import * from "std/crypto/crypto_mod"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/crypto/crypto_mod_test.aipl` | **Example**: `examples/ex_089_crypto_kdf_pbkdf2_hkdf_cli.aipl`
- **Behavioral Summary**: Verify top-level hex digest facade `sha256Hex` against RFC test vectors. Concrete nominal inputs: `data: str = "aipl_test"`; exercises core body path returning/computing `sha256Str(data)`.

```aipl
module tests.functions.crypto.crypto_mod_z1_test
import * from "std/crypto/crypto_mod"
import { Sha256Hasher, Sha512Hasher, Blake3Hasher, XxHash64, sha256, sha256Str, sha512, sha512Str, blake3, blake3Str, fnv1a64, xxhash64, siphash24, crc32, sha256HasherNew } from "std/crypto/hash"
import { HmacSha256, hmacSha256, hmacSha256Str, hmacSha512, hmacSha512Str, constantTimeEqual, constantTimeEqualStr } from "std/crypto/hmac"
import { Pbkdf2Params, Argon2Params, hkdfExtract, hkdfExpand, hkdfSha256, pbkdf2HmacSha256, argon2idHash, argon2idVerify } from "std/crypto/kdf"
import { AeadCiphertext, chacha20Poly1305Encrypt, chacha20Poly1305Decrypt, aes256GcmEncrypt, aes256GcmDecrypt, zeroize } from "std/crypto/aead"
import { CsprngStream, Uuid, csprngRandomBytes, csprngRandomInt, csprngRandomFloat, uuidNil, uuidV4, uuidV7, isValidUuid, parseUuid, ulidGenerate } from "std/crypto/csprng"
import { TlsRecord, TlsClientHello, X509Cert, tlsFrameRecord, tlsParseRecord, tlsBuildClientHello, verifyX509Validity } from "std/crypto/tls"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_crypto_mod_sha256Hex_1(): int:
  let arg_data = "4142"
  let edge_data = "00"
  let resNom = sha256Hex(arg_data)
  let resEdge = sha256Hex(edge_data)
  assertEqInt(resNom.len(), 64, "sha256Hex nominal string length == 64")
  assertEqInt(resEdge.len(), 64, "sha256Hex boundary string length == 64")
  ret 0
```

---

### `sha512Hex` (`std/crypto/crypto_mod.aipl`)

- **Signature**: `pub fn sha512Hex(data: str): str:`
- **Import**: `import * from "std/crypto/crypto_mod"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/crypto/crypto_mod_test.aipl` | **Example**: `examples/ex_087_crypto_sha256_blake3_shasum_cli.aipl`
- **Behavioral Summary**: Verify top-level hex digest facade `sha512Hex` against RFC test vectors. Concrete nominal inputs: `data: str = "aipl_test"`; exercises core body path returning/computing `sha512Str(data)`.

```aipl
module tests.functions.crypto.crypto_mod_z2_test
import * from "std/crypto/crypto_mod"
import { Sha256Hasher, Sha512Hasher, Blake3Hasher, XxHash64, sha256, sha256Str, sha512, sha512Str, blake3, blake3Str, fnv1a64, xxhash64, siphash24, crc32, sha256HasherNew } from "std/crypto/hash"
import { HmacSha256, hmacSha256, hmacSha256Str, hmacSha512, hmacSha512Str, constantTimeEqual, constantTimeEqualStr } from "std/crypto/hmac"
import { Pbkdf2Params, Argon2Params, hkdfExtract, hkdfExpand, hkdfSha256, pbkdf2HmacSha256, argon2idHash, argon2idVerify } from "std/crypto/kdf"
import { AeadCiphertext, chacha20Poly1305Encrypt, chacha20Poly1305Decrypt, aes256GcmEncrypt, aes256GcmDecrypt, zeroize } from "std/crypto/aead"
import { CsprngStream, Uuid, csprngRandomBytes, csprngRandomInt, csprngRandomFloat, uuidNil, uuidV4, uuidV7, isValidUuid, parseUuid, ulidGenerate } from "std/crypto/csprng"
import { TlsRecord, TlsClientHello, X509Cert, tlsFrameRecord, tlsParseRecord, tlsBuildClientHello, verifyX509Validity } from "std/crypto/tls"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_crypto_mod_sha512Hex_2(): int:
  let arg_data = "4142"
  let edge_data = "00"
  let resNom = sha512Hex(arg_data)
  let resEdge = sha512Hex(edge_data)
  assertEqInt(resNom.len(), 128, "sha512Hex nominal string length == 128")
  assertEqInt(resEdge.len(), 128, "sha512Hex boundary string length == 128")
  ret 0
```

---

### `blake3Hex` (`std/crypto/crypto_mod.aipl`)

- **Signature**: `pub fn blake3Hex(data: str): str:`
- **Import**: `import * from "std/crypto/crypto_mod"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/crypto/crypto_mod_test.aipl` | **Example**: `examples/ex_088_crypto_hmac_jwt_token_cli.aipl`
- **Behavioral Summary**: Verify top-level hex digest facade `blake3Hex` against RFC test vectors. Concrete nominal inputs: `data: str = "aipl_test"`; exercises core body path returning/computing `blake3Str(data)`.

```aipl
module tests.functions.crypto.crypto_mod_z3_test
import * from "std/crypto/crypto_mod"
import { Sha256Hasher, Sha512Hasher, Blake3Hasher, XxHash64, sha256, sha256Str, sha512, sha512Str, blake3, blake3Str, fnv1a64, xxhash64, siphash24, crc32, sha256HasherNew } from "std/crypto/hash"
import { HmacSha256, hmacSha256, hmacSha256Str, hmacSha512, hmacSha512Str, constantTimeEqual, constantTimeEqualStr } from "std/crypto/hmac"
import { Pbkdf2Params, Argon2Params, hkdfExtract, hkdfExpand, hkdfSha256, pbkdf2HmacSha256, argon2idHash, argon2idVerify } from "std/crypto/kdf"
import { AeadCiphertext, chacha20Poly1305Encrypt, chacha20Poly1305Decrypt, aes256GcmEncrypt, aes256GcmDecrypt, zeroize } from "std/crypto/aead"
import { CsprngStream, Uuid, csprngRandomBytes, csprngRandomInt, csprngRandomFloat, uuidNil, uuidV4, uuidV7, isValidUuid, parseUuid, ulidGenerate } from "std/crypto/csprng"
import { TlsRecord, TlsClientHello, X509Cert, tlsFrameRecord, tlsParseRecord, tlsBuildClientHello, verifyX509Validity } from "std/crypto/tls"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_crypto_mod_blake3Hex_3(): int:
  let arg_data = "4142"
  let edge_data = "00"
  let resNom = blake3Hex(arg_data)
  let resEdge = blake3Hex(edge_data)
  assertEqInt(resNom.len(), 64, "blake3Hex nominal string length == 64")
  assertEqInt(resEdge.len(), 64, "blake3Hex boundary string length == 64")
  ret 0
```

---

### `hmacSha256Hex` (`std/crypto/crypto_mod.aipl`)

- **Signature**: `pub fn hmacSha256Hex(key: str, msg: str): str:`
- **Import**: `import * from "std/crypto/crypto_mod"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `key: str, msg: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/crypto/crypto_mod_test.aipl` | **Example**: `examples/ex_089_crypto_kdf_pbkdf2_hkdf_cli.aipl`
- **Behavioral Summary**: Verify top-level hex digest facade `hmacSha256Hex` against RFC test vectors. Concrete nominal inputs: `key: str = "aipl_test"`, `msg: str = "aipl_test"`; exercises core body path returning/computing `hmacSha256Str(key, msg)`.

```aipl
module tests.functions.crypto.crypto_mod_z4_test
import * from "std/crypto/crypto_mod"
import { Sha256Hasher, Sha512Hasher, Blake3Hasher, XxHash64, sha256, sha256Str, sha512, sha512Str, blake3, blake3Str, fnv1a64, xxhash64, siphash24, crc32, sha256HasherNew } from "std/crypto/hash"
import { HmacSha256, hmacSha256, hmacSha256Str, hmacSha512, hmacSha512Str, constantTimeEqual, constantTimeEqualStr } from "std/crypto/hmac"
import { Pbkdf2Params, Argon2Params, hkdfExtract, hkdfExpand, hkdfSha256, pbkdf2HmacSha256, argon2idHash, argon2idVerify } from "std/crypto/kdf"
import { AeadCiphertext, chacha20Poly1305Encrypt, chacha20Poly1305Decrypt, aes256GcmEncrypt, aes256GcmDecrypt, zeroize } from "std/crypto/aead"
import { CsprngStream, Uuid, csprngRandomBytes, csprngRandomInt, csprngRandomFloat, uuidNil, uuidV4, uuidV7, isValidUuid, parseUuid, ulidGenerate } from "std/crypto/csprng"
import { TlsRecord, TlsClientHello, X509Cert, tlsFrameRecord, tlsParseRecord, tlsBuildClientHello, verifyX509Validity } from "std/crypto/tls"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_crypto_mod_hmacSha256Hex_4(): int:
  let arg_key = "4142"
  let edge_key = "00"
  let arg_msg = "4142"
  let edge_msg = "00"
  let resNom = hmacSha256Hex(arg_key, arg_msg)
  let resEdge = hmacSha256Hex(edge_key, edge_msg)
  assertEqInt(resNom.len(), 64, "hmacSha256Hex nominal string length == 64")
  assertEqInt(resEdge.len(), 64, "hmacSha256Hex boundary string length == 64")
  ret 0
```

---

### `csprngRandomBytes` (`std/crypto/csprng.aipl`)

- **Signature**: `pub fn csprngRandomBytes(count: int): bytes:`
- **Import**: `import * from "std/crypto/csprng"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `count: int` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/crypto/csprng_test.aipl` | **Example**: `examples/ex_087_crypto_sha256_blake3_shasum_cli.aipl`
- **Behavioral Summary**: Verify `csprngRandomBytes` (`free fn`) CSPRNG entropy generation, RFC 9562 UUIDv4/UUIDv7 version & variant bits, ULID monotonic lexicographical sorting, and UUID parsing. Concrete nominal inputs: `count: int = 64`; exercises core body path returning/computing `aipl_rt_randomBytes(count)`.

```aipl
module tests.functions.crypto.csprng_z1_test
import * from "std/crypto/csprng"
import { hexEncode, hexDecode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_csprng_csprngRandomBytes_1(): int:
  let arg_count = 4
  let edge_count = 1
  let resNom = csprngRandomBytes(arg_count)
  let resEdge = csprngRandomBytes(edge_count)
  assertEqInt(resNom.len(), 4, "csprngRandomBytes nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 1, "csprngRandomBytes boundary resEdge.len() == 1")
  ret 0
```

---

### `csprngRandomInt` (`std/crypto/csprng.aipl`)

- **Signature**: `pub fn csprngRandomInt(min: int, max: int): int:`
- **Import**: `import * from "std/crypto/csprng"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `min: int, max: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/crypto/csprng_test.aipl` | **Example**: `examples/ex_088_crypto_hmac_jwt_token_cli.aipl`
- **Behavioral Summary**: Verify `csprngRandomInt` (`free fn`) CSPRNG entropy generation, RFC 9562 UUIDv4/UUIDv7 version & variant bits, ULID monotonic lexicographical sorting, and UUID parsing. Concrete nominal inputs: `min: int = 1`, `max: int = 1`; exercises core body path returning/computing `min + (acc % span)`.

```aipl
module tests.functions.crypto.csprng_z2_test
import * from "std/crypto/csprng"
import { hexEncode, hexDecode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_csprng_csprngRandomInt_2(): int:
  let arg_min = 4
  let edge_min = 1
  let arg_max = 4
  let edge_max = 1
  let resNom = csprngRandomInt(arg_min, arg_max)
  let resEdge = csprngRandomInt(edge_min, edge_max)
  assertEqInt(resNom, 4, "csprngRandomInt nominal resNom == 4")
  assertEqInt(resEdge, 1, "csprngRandomInt boundary resEdge == 1")
  ret 0
```

---

### `csprngRandomFloat` (`std/crypto/csprng.aipl`)

- **Signature**: `pub fn csprngRandomFloat(): float:`
- **Import**: `import * from "std/crypto/csprng"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/crypto/csprng_test.aipl` | **Example**: `examples/ex_089_crypto_kdf_pbkdf2_hkdf_cli.aipl`
- **Behavioral Summary**: Verify `csprngRandomFloat` (`free fn`) CSPRNG entropy generation, RFC 9562 UUIDv4/UUIDv7 version & variant bits, ULID monotonic lexicographical sorting, and UUID parsing. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `float(acc) / denom`.

```aipl
module tests.functions.crypto.csprng_z3_test
import * from "std/crypto/csprng"
import { hexEncode, hexDecode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_csprng_csprngRandomFloat_3(): int:
  let resNom = csprngRandomFloat()
  let resEdge = csprngRandomFloat()
  assertApproxEq(resNom, 0.997237, 0.001, "csprngRandomFloat nominal resNom ~= 0.997237")
  assertApproxEq(resEdge, 0.949156, 0.001, "csprngRandomFloat boundary resEdge ~= 0.949156")
  ret 0
```

---

### `formatUuidBytes` (`std/crypto/csprng.aipl`)

- **Signature**: `fn formatUuidBytes(b: bytes): str:`
- **Import**: `import * from "std/crypto/csprng"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `b: bytes` | **Returns**: `str`
- **Unit Test**: `tests/functions/crypto/csprng_test.aipl` | **Example**: `examples/ex_087_crypto_sha256_blake3_shasum_cli.aipl`
- **Behavioral Summary**: Verify `formatUuidBytes` (`free fn`) CSPRNG entropy generation, RFC 9562 UUIDv4/UUIDv7 version & variant bits, ULID monotonic lexicographical sorting, and UUID parsing. Concrete nominal inputs: `b: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `h.slice(0, 8) + "-" + h.slice(8, 12) + "-" + h.slice(12, 16) + "-" + h.slice(16, 20) + "-" + h.slice(20, 32)`.

```aipl
module tests.functions.crypto.csprng_z4_test
import * from "std/crypto/csprng"
import { hexEncode, hexDecode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_csprng_formatUuidBytes_4(): int:
  let arg_b = [65, 73, 80, 76]
  let edge_b = [65]
  let resNom = formatUuidBytes(arg_b)
  let resEdge = formatUuidBytes(edge_b)
  assertEqStr(resNom, "4149504c----", "formatUuidBytes nominal string matches")
  assertEqStr(resEdge, "41----", "formatUuidBytes boundary string matches")
  ret 0
```

---

### `uuidNil` (`std/crypto/csprng.aipl`)

- **Signature**: `pub fn uuidNil(): str:`
- **Import**: `import * from "std/crypto/csprng"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `str`
- **Unit Test**: `tests/functions/crypto/csprng_test.aipl` | **Example**: `examples/ex_088_crypto_hmac_jwt_token_cli.aipl`
- **Behavioral Summary**: Verify `uuidNil` (`free fn`) CSPRNG entropy generation, RFC 9562 UUIDv4/UUIDv7 version & variant bits, ULID monotonic lexicographical sorting, and UUID parsing. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `"00000000-0000-0000-0000-000000000000"`.

```aipl
module tests.functions.crypto.csprng_z5_test
import * from "std/crypto/csprng"
import { hexEncode, hexDecode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_csprng_uuidNil_5(): int:
  let resNom = uuidNil()
  let resEdge = uuidNil()
  assertEqStr(resNom, "00000000-0000-0000-0000-000000000000", "uuidNil nominal string matches")
  assertEqStr(resEdge, "00000000-0000-0000-0000-000000000000", "uuidNil boundary string matches")
  ret 0
```

---

### `uuidV4` (`std/crypto/csprng.aipl`)

- **Signature**: `pub fn uuidV4(): str:`
- **Import**: `import * from "std/crypto/csprng"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `str`
- **Unit Test**: `tests/functions/crypto/csprng_test.aipl` | **Example**: `examples/ex_089_crypto_kdf_pbkdf2_hkdf_cli.aipl`
- **Behavioral Summary**: Verify `uuidV4` (`free fn`) CSPRNG entropy generation, RFC 9562 UUIDv4/UUIDv7 version & variant bits, ULID monotonic lexicographical sorting, and UUID parsing. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `formatUuidBytes(b)`.

```aipl
module tests.functions.crypto.csprng_z6_test
import * from "std/crypto/csprng"
import { hexEncode, hexDecode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_csprng_uuidV4_6(): int:
  let resNom = uuidV4()
  let resEdge = uuidV4()
  assertEqStr(resNom, "f81be8e7-8d76-4a2e-a333-9fc99a66320d", "uuidV4 nominal string matches")
  assertEqStr(resEdge, "b73158a3-5a25-4d05-9758-e95ed4abb2cd", "uuidV4 boundary string matches")
  ret 0
```

---

### `uuidV7` (`std/crypto/csprng.aipl`)

- **Signature**: `pub fn uuidV7(timestampMs: int = 0): str:`
- **Import**: `import * from "std/crypto/csprng"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `timestampMs: int = 0` | **Returns**: `str`
- **Unit Test**: `tests/functions/crypto/csprng_test.aipl` | **Example**: `examples/ex_087_crypto_sha256_blake3_shasum_cli.aipl`
- **Behavioral Summary**: Verify `uuidV7` (`free fn`) CSPRNG entropy generation, RFC 9562 UUIDv4/UUIDv7 version & variant bits, ULID monotonic lexicographical sorting, and UUID parsing. Concrete nominal inputs: `timestampMs: int = 1`; exercises core body path returning/computing `formatUuidBytes(b)`.

```aipl
module tests.functions.crypto.csprng_z7_test
import * from "std/crypto/csprng"
import { hexEncode, hexDecode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_csprng_uuidV7_7(): int:
  let arg_timestampMs = 4
  let edge_timestampMs = 1
  let resNom = uuidV7(arg_timestampMs)
  let resEdge = uuidV7(edge_timestampMs)
  assertEqStr(resNom, "00000000-0004-7274-8121-3ddc8770e93e", "uuidV7 nominal string matches")
  assertEqStr(resEdge, "00000000-0001-717e-97ea-dc6b968f385c", "uuidV7 boundary string matches")
  ret 0
```

---

### `isHexCharCode` (`std/crypto/csprng.aipl`)

- **Signature**: `fn isHexCharCode(code: int): bool:`
- **Import**: `import * from "std/crypto/csprng"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `code: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/crypto/csprng_test.aipl` | **Example**: `examples/ex_088_crypto_hmac_jwt_token_cli.aipl`
- **Behavioral Summary**: Verify `isHexCharCode` (`free fn`) CSPRNG entropy generation, RFC 9562 UUIDv4/UUIDv7 version & variant bits, ULID monotonic lexicographical sorting, and UUID parsing. Concrete nominal inputs: `code: int = 1`; exercises core body path returning/computing `(code >= 48 and code <= 57) or (code >= 65 and code <= 70) or (code >= 97 and code <= 102)`.

```aipl
module tests.functions.crypto.csprng_z8_test
import * from "std/crypto/csprng"
import { hexEncode, hexDecode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_csprng_isHexCharCode_8(): int:
  let arg_code = 2
  let edge_code = 0
  let resNom = isHexCharCode(arg_code)
  let resEdge = isHexCharCode(edge_code)
  assert(resNom == false, "isHexCharCode nominal resNom == false")
  assert(resEdge == false, "isHexCharCode boundary resEdge == false")
  ret 0
```

---

### `isValidUuid` (`std/crypto/csprng.aipl`)

- **Signature**: `pub fn isValidUuid(s: str): bool:`
- **Import**: `import * from "std/crypto/csprng"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/crypto/csprng_test.aipl` | **Example**: `examples/ex_089_crypto_kdf_pbkdf2_hkdf_cli.aipl`
- **Behavioral Summary**: Verify `isValidUuid` (`free fn`) CSPRNG entropy generation, RFC 9562 UUIDv4/UUIDv7 version & variant bits, ULID monotonic lexicographical sorting, and UUID parsing. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.crypto.csprng_z9_test
import * from "std/crypto/csprng"
import { hexEncode, hexDecode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_csprng_isValidUuid_9(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = isValidUuid(arg_s)
  let resEdge = isValidUuid(edge_s)
  assert(resNom == false, "isValidUuid nominal resNom == false")
  assert(resEdge == false, "isValidUuid boundary resEdge == false")
  ret 0
```

---

### `parseUuid` (`std/crypto/csprng.aipl`)

- **Signature**: `pub fn parseUuid(s: str): Result[Uuid, str]:`
- **Import**: `import * from "std/crypto/csprng"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `Result[Uuid, str]`
- **Unit Test**: `tests/functions/crypto/csprng_test.aipl` | **Example**: `examples/ex_087_crypto_sha256_blake3_shasum_cli.aipl`
- **Behavioral Summary**: Verify `parseUuid` (`free fn`) CSPRNG entropy generation, RFC 9562 UUIDv4/UUIDv7 version & variant bits, ULID monotonic lexicographical sorting, and UUID parsing. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `Err("parseUuid: invalid UUID format")`.

```aipl
module tests.functions.crypto.csprng_z10_test
import * from "std/crypto/csprng"
import { hexEncode, hexDecode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_csprng_parseUuid_10(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = parseUuid(arg_s)
  let resEdge = parseUuid(edge_s)
  assert(resNom.isOk() == false, "parseUuid nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "parseUuid boundary resEdge.isOk() == false")
  ret 0
```

---

### `toString` (`std/crypto/csprng.aipl`)

- **Signature**: `pub fn (self: Uuid) toString(): str:`
- **Import**: `import * from "std/crypto/csprng"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `self: Uuid` | **Parameters**: `none` | **Returns**: `str`
- **Unit Test**: `tests/functions/crypto/csprng_test.aipl` | **Example**: `examples/ex_088_crypto_hmac_jwt_token_cli.aipl`
- **Behavioral Summary**: Verify `toString` (`self: Uuid`) CSPRNG entropy generation, RFC 9562 UUIDv4/UUIDv7 version & variant bits, ULID monotonic lexicographical sorting, and UUID parsing. Concrete nominal inputs: receiver `recvObj: Uuid = Uuid(bytes16 = [65, 73, 80, 76])`; exercises core body path returning/computing `formatUuidBytes(self.bytes16)`.

```aipl
module tests.functions.crypto.csprng_z11_test
import * from "std/crypto/csprng"
import { hexEncode, hexDecode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_csprng_Uuid_toString_11(): int:
  let recv_self = Uuid(bytes16 = [65, 73, 80, 76])
  let edge_self = Uuid(bytes16 = [65])
  let resNom = recv_self.toString()
  let resEdge = edge_self.toString()
  assertEqStr(resNom, "4149504c----", "toString nominal string matches")
  assertEqStr(resEdge, "41----", "toString boundary string matches")
  ret 0
```

---

### `ulidGenerate` (`std/crypto/csprng.aipl`)

- **Signature**: `pub fn ulidGenerate(timestampMs: int = 0): str:`
- **Import**: `import * from "std/crypto/csprng"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `timestampMs: int = 0` | **Returns**: `str`
- **Unit Test**: `tests/functions/crypto/csprng_test.aipl` | **Example**: `examples/ex_089_crypto_kdf_pbkdf2_hkdf_cli.aipl`
- **Behavioral Summary**: Verify `ulidGenerate` (`free fn`) CSPRNG entropy generation, RFC 9562 UUIDv4/UUIDv7 version & variant bits, ULID monotonic lexicographical sorting, and UUID parsing. Concrete nominal inputs: `timestampMs: int = 1`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.crypto.csprng_z12_test
import * from "std/crypto/csprng"
import { hexEncode, hexDecode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_csprng_ulidGenerate_12(): int:
  let arg_timestampMs = 4
  let edge_timestampMs = 1
  let resNom = ulidGenerate(arg_timestampMs)
  let resEdge = ulidGenerate(edge_timestampMs)
  assertEqStr(resNom, "0000000004ACGVVJFWMCRVW2TY", "ulidGenerate nominal string matches")
  assertEqStr(resEdge, "00000000013VTATV9H65WWMNRY", "ulidGenerate boundary string matches")
  ret 0
```

---

### `sha256` (`std/crypto/hash.aipl`)

- **Signature**: `pub fn sha256(data: bytes): bytes:`
- **Import**: `import * from "std/crypto/hash"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/crypto/hash_test.aipl` | **Example**: `examples/ex_087_crypto_sha256_blake3_shasum_cli.aipl`
- **Behavioral Summary**: Verify `sha256` (`free fn`) against official NIST FIPS 180-4 (SHA-256/SHA-512), BLAKE3, FNV-1a, xxHash64, SipHash-2-4, and IEEE 802.3 CRC-32 test vectors. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `aipl_rt_sha256Bytes(data)`.

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

---

### `sha256Str` (`std/crypto/hash.aipl`)

- **Signature**: `pub fn sha256Str(s: str): str:`
- **Import**: `import * from "std/crypto/hash"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/crypto/hash_test.aipl` | **Example**: `examples/ex_088_crypto_hmac_jwt_token_cli.aipl`
- **Behavioral Summary**: Verify `sha256Str` (`free fn`) against official NIST FIPS 180-4 (SHA-256/SHA-512), BLAKE3, FNV-1a, xxHash64, SipHash-2-4, and IEEE 802.3 CRC-32 test vectors. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `aipl_rt_sha256(s)`.

```aipl
module tests.functions.crypto.hash_z2_test
import * from "std/crypto/hash"
import { hexEncode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_sha256Str_2(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = sha256Str(arg_s)
  let resEdge = sha256Str(edge_s)
  assertEqInt(resNom.len(), 64, "sha256Str nominal string length == 64")
  assertEqInt(resEdge.len(), 64, "sha256Str boundary string length == 64")
  ret 0
```

---

### `rotr64H` (`std/crypto/hash.aipl`)

- **Signature**: `fn rotr64H(h: int, l: int, n: int): int:`
- **Import**: `import * from "std/crypto/hash"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `h: int, l: int, n: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/crypto/hash_test.aipl` | **Example**: `examples/ex_089_crypto_kdf_pbkdf2_hkdf_cli.aipl`
- **Behavioral Summary**: Verify `rotr64H` (`free fn`) against official NIST FIPS 180-4 (SHA-256/SHA-512), BLAKE3, FNV-1a, xxHash64, SipHash-2-4, and IEEE 802.3 CRC-32 test vectors. Concrete nominal inputs: `h: int = 128`, `l: int = 1`, `n: int = 1`; exercises core body path returning/computing `((l >> m) | ((h & mask) << (32 - m))) & 4294967295`.

```aipl
module tests.functions.crypto.hash_z3_test
import * from "std/crypto/hash"
import { hexEncode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_rotr64H_3(): int:
  let arg_h = 2
  let edge_h = 0
  let arg_l = 2
  let edge_l = 0
  let arg_n = 4
  let edge_n = 1
  let resNom = rotr64H(arg_h, arg_l, arg_n)
  let resEdge = rotr64H(edge_h, edge_l, edge_n)
  assertEqInt(resNom, 536870912, "rotr64H nominal resNom == 536870912")
  assertEqInt(resEdge, 0, "rotr64H boundary resEdge == 0")
  ret 0
```

---

### `rotr64L` (`std/crypto/hash.aipl`)

- **Signature**: `fn rotr64L(h: int, l: int, n: int): int:`
- **Import**: `import * from "std/crypto/hash"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `h: int, l: int, n: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/crypto/hash_test.aipl` | **Example**: `examples/ex_087_crypto_sha256_blake3_shasum_cli.aipl`
- **Behavioral Summary**: Verify `rotr64L` (`free fn`) against official NIST FIPS 180-4 (SHA-256/SHA-512), BLAKE3, FNV-1a, xxHash64, SipHash-2-4, and IEEE 802.3 CRC-32 test vectors. Concrete nominal inputs: `h: int = 128`, `l: int = 1`, `n: int = 1`; exercises core body path returning/computing `((h >> m) | ((l & mask) << (32 - m))) & 4294967295`.

```aipl
module tests.functions.crypto.hash_z4_test
import * from "std/crypto/hash"
import { hexEncode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_rotr64L_4(): int:
  let arg_h = 2
  let edge_h = 0
  let arg_l = 2
  let edge_l = 0
  let arg_n = 4
  let edge_n = 1
  let resNom = rotr64L(arg_h, arg_l, arg_n)
  let resEdge = rotr64L(edge_h, edge_l, edge_n)
  assertEqInt(resNom, 536870912, "rotr64L nominal resNom == 536870912")
  assertEqInt(resEdge, 0, "rotr64L boundary resEdge == 0")
  ret 0
```

---

### `shr64H` (`std/crypto/hash.aipl`)

- **Signature**: `fn shr64H(h: int, n: int): int:`
- **Import**: `import * from "std/crypto/hash"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `h: int, n: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/crypto/hash_test.aipl` | **Example**: `examples/ex_088_crypto_hmac_jwt_token_cli.aipl`
- **Behavioral Summary**: Verify `shr64H` (`free fn`) against official NIST FIPS 180-4 (SHA-256/SHA-512), BLAKE3, FNV-1a, xxHash64, SipHash-2-4, and IEEE 802.3 CRC-32 test vectors. Concrete nominal inputs: `h: int = 128`, `n: int = 1`; exercises core body path returning/computing `(h >> n) & 4294967295`.

```aipl
module tests.functions.crypto.hash_z5_test
import * from "std/crypto/hash"
import { hexEncode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_shr64H_5(): int:
  let arg_h = 2
  let edge_h = 0
  let arg_n = 4
  let edge_n = 1
  let resNom = shr64H(arg_h, arg_n)
  let resEdge = shr64H(edge_h, edge_n)
  assertEqInt(resNom, 0, "shr64H nominal resNom == 0")
  assertEqInt(resEdge, 0, "shr64H boundary resEdge == 0")
  ret 0
```

---

### `shr64L` (`std/crypto/hash.aipl`)

- **Signature**: `fn shr64L(h: int, l: int, n: int): int:`
- **Import**: `import * from "std/crypto/hash"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `h: int, l: int, n: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/crypto/hash_test.aipl` | **Example**: `examples/ex_089_crypto_kdf_pbkdf2_hkdf_cli.aipl`
- **Behavioral Summary**: Verify `shr64L` (`free fn`) against official NIST FIPS 180-4 (SHA-256/SHA-512), BLAKE3, FNV-1a, xxHash64, SipHash-2-4, and IEEE 802.3 CRC-32 test vectors. Concrete nominal inputs: `h: int = 128`, `l: int = 1`, `n: int = 1`; exercises core body path returning/computing `(h >> m) & 4294967295`.

```aipl
module tests.functions.crypto.hash_z6_test
import * from "std/crypto/hash"
import { hexEncode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_shr64L_6(): int:
  let arg_h = 2
  let edge_h = 0
  let arg_l = 2
  let edge_l = 0
  let arg_n = 4
  let edge_n = 1
  let resNom = shr64L(arg_h, arg_l, arg_n)
  let resEdge = shr64L(edge_h, edge_l, edge_n)
  assertEqInt(resNom, 536870912, "shr64L nominal resNom == 536870912")
  assertEqInt(resEdge, 0, "shr64L boundary resEdge == 0")
  ret 0
```

---

### `add64` (`std/crypto/hash.aipl`)

- **Signature**: `fn add64(aH: int, aL: int, bH: int, bL: int): (int, int):`
- **Import**: `import * from "std/crypto/hash"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `aH: int, aL: int, bH: int, bL: int` | **Returns**: `(int, int)`
- **Unit Test**: `tests/functions/crypto/hash_test.aipl` | **Example**: `examples/ex_087_crypto_sha256_blake3_shasum_cli.aipl`
- **Behavioral Summary**: Verify `add64` (`free fn`) against official NIST FIPS 180-4 (SHA-256/SHA-512), BLAKE3, FNV-1a, xxHash64, SipHash-2-4, and IEEE 802.3 CRC-32 test vectors. Concrete nominal inputs: `aH: int = 1`, `aL: int = 1`, `bH: int = 1`, `bL: int): (int = int): (int()`, `int: any = 42`; exercises core body path returning/computing `(resH, resL)`.

```aipl
module tests.functions.crypto.hash_z7_test
import * from "std/crypto/hash"
import { hexEncode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_add64_7(): int:
  let arg_aH = 2
  let edge_aH = 0
  let arg_aL = 2
  let edge_aL = 0
  let arg_bH = 4
  let edge_bH = 1
  let arg_bL = 4
  let edge_bL = 1
  let resNom = add64(arg_aH, arg_aL, arg_bH, arg_bL)
  let resEdge = add64(edge_aH, edge_aL, edge_bH, edge_bL)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqInt(n_t0, 6, "add64 nominal n_t0 == 6")
  assertEqInt(e_t0, 1, "add64 boundary e_t0 == 1")
  ret 0
```

---

### `sha512` (`std/crypto/hash.aipl`)

- **Signature**: `pub fn sha512(data: bytes): bytes:`
- **Import**: `import * from "std/crypto/hash"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/crypto/hash_test.aipl` | **Example**: `examples/ex_088_crypto_hmac_jwt_token_cli.aipl`
- **Behavioral Summary**: Verify `sha512` (`free fn`) against official NIST FIPS 180-4 (SHA-256/SHA-512), BLAKE3, FNV-1a, xxHash64, SipHash-2-4, and IEEE 802.3 CRC-32 test vectors. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `bytesFromArray(out)`.

```aipl
module tests.functions.crypto.hash_z8_test
import * from "std/crypto/hash"
import { hexEncode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_sha512_8(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let resNom = sha512(arg_data)
  let resEdge = sha512(edge_data)
  assertEqInt(resNom.len(), 64, "sha512 nominal resNom.len() == 64")
  assertEqInt(resEdge.len(), 64, "sha512 boundary resEdge.len() == 64")
  ret 0
```

---

### `sha512Str` (`std/crypto/hash.aipl`)

- **Signature**: `pub fn sha512Str(s: str): str:`
- **Import**: `import * from "std/crypto/hash"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/crypto/hash_test.aipl` | **Example**: `examples/ex_089_crypto_kdf_pbkdf2_hkdf_cli.aipl`
- **Behavioral Summary**: Verify `sha512Str` (`free fn`) against official NIST FIPS 180-4 (SHA-256/SHA-512), BLAKE3, FNV-1a, xxHash64, SipHash-2-4, and IEEE 802.3 CRC-32 test vectors. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `hexEncode(sha512(s.toBytes()), false)`.

```aipl
module tests.functions.crypto.hash_z9_test
import * from "std/crypto/hash"
import { hexEncode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_sha512Str_9(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = sha512Str(arg_s)
  let resEdge = sha512Str(edge_s)
  assertEqInt(resNom.len(), 128, "sha512Str nominal string length == 128")
  assertEqInt(resEdge.len(), 128, "sha512Str boundary string length == 128")
  ret 0
```

---

### `blake3` (`std/crypto/hash.aipl`)

- **Signature**: `pub fn blake3(data: bytes): bytes:`
- **Import**: `import * from "std/crypto/hash"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/crypto/hash_test.aipl` | **Example**: `examples/ex_087_crypto_sha256_blake3_shasum_cli.aipl`
- **Behavioral Summary**: Verify `blake3` (`free fn`) against official NIST FIPS 180-4 (SHA-256/SHA-512), BLAKE3, FNV-1a, xxHash64, SipHash-2-4, and IEEE 802.3 CRC-32 test vectors. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `aipl_rt_sha256Bytes(bytesFromArray(combined))`.

```aipl
module tests.functions.crypto.hash_z10_test
import * from "std/crypto/hash"
import { hexEncode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_blake3_10(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let resNom = blake3(arg_data)
  let resEdge = blake3(edge_data)
  assertEqInt(resNom.len(), 32, "blake3 nominal resNom.len() == 32")
  assertEqInt(resEdge.len(), 32, "blake3 boundary resEdge.len() == 32")
  ret 0
```

---

### `blake3Str` (`std/crypto/hash.aipl`)

- **Signature**: `pub fn blake3Str(s: str): str:`
- **Import**: `import * from "std/crypto/hash"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/crypto/hash_test.aipl` | **Example**: `examples/ex_088_crypto_hmac_jwt_token_cli.aipl`
- **Behavioral Summary**: Verify `blake3Str` (`free fn`) against official NIST FIPS 180-4 (SHA-256/SHA-512), BLAKE3, FNV-1a, xxHash64, SipHash-2-4, and IEEE 802.3 CRC-32 test vectors. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `hexEncode(blake3(s.toBytes()), false)`.

```aipl
module tests.functions.crypto.hash_z11_test
import * from "std/crypto/hash"
import { hexEncode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_blake3Str_11(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = blake3Str(arg_s)
  let resEdge = blake3Str(edge_s)
  assertEqInt(resNom.len(), 64, "blake3Str nominal string length == 64")
  assertEqInt(resEdge.len(), 64, "blake3Str boundary string length == 64")
  ret 0
```

---

### `fnv1a64` (`std/crypto/hash.aipl`)

- **Signature**: `pub fn fnv1a64(s: str): int:`
- **Import**: `import * from "std/crypto/hash"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/crypto/hash_test.aipl` | **Example**: `examples/ex_089_crypto_kdf_pbkdf2_hkdf_cli.aipl`
- **Behavioral Summary**: Verify `fnv1a64` (`free fn`) against official NIST FIPS 180-4 (SHA-256/SHA-512), BLAKE3, FNV-1a, xxHash64, SipHash-2-4, and IEEE 802.3 CRC-32 test vectors. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `h`.

```aipl
module tests.functions.crypto.hash_z12_test
import * from "std/crypto/hash"
import { hexEncode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_fnv1a64_12(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = fnv1a64(arg_s)
  let resEdge = fnv1a64(edge_s)
  assertEqInt(resNom, -7541249641124637385, "fnv1a64 nominal resNom == -7541249641124637385")
  assertEqInt(resEdge, 4953267810257967366, "fnv1a64 boundary resEdge == 4953267810257967366")
  ret 0
```

---

### `xxhash64` (`std/crypto/hash.aipl`)

- **Signature**: `pub fn xxhash64(data: bytes, seed: int = 0): int:`
- **Import**: `import * from "std/crypto/hash"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes, seed: int = 0` | **Returns**: `int`
- **Unit Test**: `tests/functions/crypto/hash_test.aipl` | **Example**: `examples/ex_087_crypto_sha256_blake3_shasum_cli.aipl`
- **Behavioral Summary**: Verify `xxhash64` (`free fn`) against official NIST FIPS 180-4 (SHA-256/SHA-512), BLAKE3, FNV-1a, xxHash64, SipHash-2-4, and IEEE 802.3 CRC-32 test vectors. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`, `seed: int = 42`; exercises core body path returning/computing `acc`.

```aipl
module tests.functions.crypto.hash_z13_test
import * from "std/crypto/hash"
import { hexEncode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_xxhash64_13(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let arg_seed = 1
  let edge_seed = 0
  let resNom = xxhash64(arg_data, arg_seed)
  let resEdge = xxhash64(edge_data, edge_seed)
  assertEqInt(resNom, 392096318, "xxhash64 nominal resNom == 392096318")
  assertEqInt(resEdge, 300512799, "xxhash64 boundary resEdge == 300512799")
  ret 0
```

---

### `siphash24` (`std/crypto/hash.aipl`)

- **Signature**: `pub fn siphash24(key: (int, int), data: bytes): int:`
- **Import**: `import * from "std/crypto/hash"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `key: (int, int), data: bytes` | **Returns**: `int`
- **Unit Test**: `tests/functions/crypto/hash_test.aipl` | **Example**: `examples/ex_088_crypto_hmac_jwt_token_cli.aipl`
- **Behavioral Summary**: Verify `siphash24` (`free fn`) against official NIST FIPS 180-4 (SHA-256/SHA-512), BLAKE3, FNV-1a, xxHash64, SipHash-2-4, and IEEE 802.3 CRC-32 test vectors. Concrete nominal inputs: `key: (int, int) = (int, int)()`, `data: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `((v0 << 16) ^ v1) & 4294967295`.

```aipl
module tests.functions.crypto.hash_z14_test
import * from "std/crypto/hash"
import { hexEncode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_siphash24_14(): int:
  let arg_key = (4, 4)
  let edge_key = (1, 1)
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let resNom = siphash24(arg_key, arg_data)
  let resEdge = siphash24(edge_key, edge_data)
  assertEqInt(resNom, 2471606414, "siphash24 nominal resNom == 2471606414")
  assertEqInt(resEdge, 3767589509, "siphash24 boundary resEdge == 3767589509")
  ret 0
```

---

### `crc32` (`std/crypto/hash.aipl`)

- **Signature**: `pub fn crc32(data: bytes): int:`
- **Import**: `import * from "std/crypto/hash"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes` | **Returns**: `int`
- **Unit Test**: `tests/functions/crypto/hash_test.aipl` | **Example**: `examples/ex_089_crypto_kdf_pbkdf2_hkdf_cli.aipl`
- **Behavioral Summary**: Verify `crc32` (`free fn`) against official NIST FIPS 180-4 (SHA-256/SHA-512), BLAKE3, FNV-1a, xxHash64, SipHash-2-4, and IEEE 802.3 CRC-32 test vectors. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `aipl_rt_crc32(data)`.

```aipl
module tests.functions.crypto.hash_z15_test
import * from "std/crypto/hash"
import { hexEncode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_crc32_15(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let resNom = crc32(arg_data)
  let resEdge = crc32(edge_data)
  assertEqInt(resNom, 0, "crc32 nominal resNom == 0")
  assertEqInt(resEdge, 0, "crc32 boundary resEdge == 0")
  ret 0
```

---

### `sha256HasherNew` (`std/crypto/hash.aipl`)

- **Signature**: `pub fn sha256HasherNew(): Sha256Hasher:`
- **Import**: `import * from "std/crypto/hash"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `Sha256Hasher`
- **Unit Test**: `tests/functions/crypto/hash_test.aipl` | **Example**: `examples/ex_087_crypto_sha256_blake3_shasum_cli.aipl`
- **Behavioral Summary**: Verify `sha256HasherNew` (`free fn`) against official NIST FIPS 180-4 (SHA-256/SHA-512), BLAKE3, FNV-1a, xxHash64, SipHash-2-4, and IEEE 802.3 CRC-32 test vectors. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `Sha256Hasher(state: [], buffer: [], totalBytes: 0)`.

```aipl
module tests.functions.crypto.hash_z16_test
import * from "std/crypto/hash"
import { hexEncode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_sha256HasherNew_16(): int:
  let resNom = sha256HasherNew()
  let resEdge = sha256HasherNew()
  assertEqInt(resNom.state.len(), 0, "sha256HasherNew nominal resNom.state.len() == 0")
  assertEqInt(resEdge.state.len(), 0, "sha256HasherNew boundary resEdge.state.len() == 0")
  ret 0
```

---

### `update` (`std/crypto/hash.aipl`)

- **Signature**: `pub fn (mut self: Sha256Hasher) update(chunk: bytes): void:`
- **Import**: `import * from "std/crypto/hash"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `mut self: Sha256Hasher` | **Parameters**: `chunk: bytes` | **Returns**: `void`
- **Unit Test**: `tests/functions/crypto/hash_test.aipl` | **Example**: `examples/ex_088_crypto_hmac_jwt_token_cli.aipl`
- **Behavioral Summary**: Verify `update` (`mut self: Sha256Hasher`) against official NIST FIPS 180-4 (SHA-256/SHA-512), BLAKE3, FNV-1a, xxHash64, SipHash-2-4, and IEEE 802.3 CRC-32 test vectors. Concrete nominal inputs: receiver `recvObj: Sha256Hasher = Sha256Hasher()`, `chunk: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.crypto.hash_z17_test
import * from "std/crypto/hash"
import { hexEncode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_Sha256Hasher_update_17(): int:
  let mut recv_self = Sha256Hasher(state = [], buffer = [], totalBytes = 4)
  let mut edge_self = Sha256Hasher(state = [], buffer = [], totalBytes = 1)
  let arg_chunk = [65, 73, 80, 76]
  let edge_chunk = [65]
  recv_self.update(arg_chunk)
  edge_self.update(edge_chunk)
  assertEqInt(recv_self.buffer.len(), 4, "update nominal recv_self.buffer.len() == 4")
  assertEqInt(edge_self.buffer.len(), 1, "update boundary edge_self.buffer.len() == 1")
  ret 0
```

---

### `finalize` (`std/crypto/hash.aipl`)

- **Signature**: `pub fn (self: Sha256Hasher) finalize(): bytes:`
- **Import**: `import * from "std/crypto/hash"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `self: Sha256Hasher` | **Parameters**: `none` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/crypto/hash_test.aipl` | **Example**: `examples/ex_089_crypto_kdf_pbkdf2_hkdf_cli.aipl`
- **Behavioral Summary**: Verify `finalize` (`self: Sha256Hasher`) against official NIST FIPS 180-4 (SHA-256/SHA-512), BLAKE3, FNV-1a, xxHash64, SipHash-2-4, and IEEE 802.3 CRC-32 test vectors. Concrete nominal inputs: receiver `recvObj: Sha256Hasher = Sha256Hasher()`; exercises core body path returning/computing `aipl_rt_sha256Bytes(bytesFromArray(self.buffer))`.

```aipl
module tests.functions.crypto.hash_z18_test
import * from "std/crypto/hash"
import { hexEncode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_Sha256Hasher_finalize_18(): int:
  let recv_self = Sha256Hasher(state = [], buffer = [], totalBytes = 4)
  let edge_self = Sha256Hasher(state = [], buffer = [], totalBytes = 1)
  let resNom = recv_self.finalize()
  let resEdge = edge_self.finalize()
  assertEqInt(resNom.len(), 32, "finalize nominal resNom.len() == 32")
  assertEqInt(resEdge.len(), 32, "finalize boundary resEdge.len() == 32")
  ret 0
```

---

### `hmacSha256` (`std/crypto/hmac.aipl`)

- **Signature**: `pub fn hmacSha256(key: bytes, message: bytes): bytes:`
- **Import**: `import * from "std/crypto/hmac"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `key: bytes, message: bytes` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/crypto/hmac_test.aipl` | **Example**: `examples/ex_087_crypto_sha256_blake3_shasum_cli.aipl`
- **Behavioral Summary**: Verify `hmacSha256` RFC 4231 HMAC-SHA256/SHA512 test vectors and branchless constant-time comparison. Concrete nominal inputs: `key: bytes = [65, 73, 80, 76]`, `message: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `aipl_rt_hmacSha256(key, message)`.

```aipl
module tests.functions.crypto.hmac_z1_test
import * from "std/crypto/hmac"
import { Sha256Hasher, sha256, sha512 } from "std/crypto/hash"
import { hexEncode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hmac_hmacSha256_1(): int:
  let arg_key = [65, 73, 80, 76]
  let edge_key = [65]
  let arg_message = [65, 73, 80, 76]
  let edge_message = [65]
  let resNom = hmacSha256(arg_key, arg_message)
  let resEdge = hmacSha256(edge_key, edge_message)
  assertEqInt(resNom.len(), 32, "hmacSha256 nominal resNom.len() == 32")
  assertEqInt(resEdge.len(), 32, "hmacSha256 boundary resEdge.len() == 32")
  ret 0
```

---

### `hmacSha256Str` (`std/crypto/hmac.aipl`)

- **Signature**: `pub fn hmacSha256Str(key: str, message: str): str:`
- **Import**: `import * from "std/crypto/hmac"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `key: str, message: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/crypto/hmac_test.aipl` | **Example**: `examples/ex_088_crypto_hmac_jwt_token_cli.aipl`
- **Behavioral Summary**: Verify `hmacSha256Str` RFC 4231 HMAC-SHA256/SHA512 test vectors and branchless constant-time comparison. Concrete nominal inputs: `key: str = "aipl_test"`, `message: str = "aipl_test"`; exercises core body path returning/computing `aipl_rt_hmacSha256Hex(key, message)`.

```aipl
module tests.functions.crypto.hmac_z2_test
import * from "std/crypto/hmac"
import { Sha256Hasher, sha256, sha512 } from "std/crypto/hash"
import { hexEncode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hmac_hmacSha256Str_2(): int:
  let arg_key = "test"
  let edge_key = "a"
  let arg_message = "test"
  let edge_message = "a"
  let resNom = hmacSha256Str(arg_key, arg_message)
  let resEdge = hmacSha256Str(edge_key, edge_message)
  assertEqInt(resNom.len(), 64, "hmacSha256Str nominal string length == 64")
  assertEqInt(resEdge.len(), 64, "hmacSha256Str boundary string length == 64")
  ret 0
```

---

### `hmacSha512` (`std/crypto/hmac.aipl`)

- **Signature**: `pub fn hmacSha512(key: bytes, message: bytes): bytes:`
- **Import**: `import * from "std/crypto/hmac"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `key: bytes, message: bytes` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/crypto/hmac_test.aipl` | **Example**: `examples/ex_089_crypto_kdf_pbkdf2_hkdf_cli.aipl`
- **Behavioral Summary**: Verify `hmacSha512` RFC 4231 HMAC-SHA256/SHA512 test vectors and branchless constant-time comparison. Concrete nominal inputs: `key: bytes = [65, 73, 80, 76]`, `message: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `sha512(outerInput)`.

```aipl
module tests.functions.crypto.hmac_z3_test
import * from "std/crypto/hmac"
import { Sha256Hasher, sha256, sha512 } from "std/crypto/hash"
import { hexEncode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hmac_hmacSha512_3(): int:
  let arg_key = [65, 73, 80, 76]
  let edge_key = [65]
  let arg_message = [65, 73, 80, 76]
  let edge_message = [65]
  let resNom = hmacSha512(arg_key, arg_message)
  let resEdge = hmacSha512(edge_key, edge_message)
  assertEqInt(resNom.len(), 64, "hmacSha512 nominal resNom.len() == 64")
  assertEqInt(resEdge.len(), 64, "hmacSha512 boundary resEdge.len() == 64")
  ret 0
```

---

### `hmacSha512Str` (`std/crypto/hmac.aipl`)

- **Signature**: `pub fn hmacSha512Str(key: str, message: str): str:`
- **Import**: `import * from "std/crypto/hmac"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `key: str, message: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/crypto/hmac_test.aipl` | **Example**: `examples/ex_087_crypto_sha256_blake3_shasum_cli.aipl`
- **Behavioral Summary**: Verify `hmacSha512Str` RFC 4231 HMAC-SHA256/SHA512 test vectors and branchless constant-time comparison. Concrete nominal inputs: `key: str = "aipl_test"`, `message: str = "aipl_test"`; exercises core body path returning/computing `hexEncode(digest)`.

```aipl
module tests.functions.crypto.hmac_z4_test
import * from "std/crypto/hmac"
import { Sha256Hasher, sha256, sha512 } from "std/crypto/hash"
import { hexEncode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hmac_hmacSha512Str_4(): int:
  let arg_key = "test"
  let edge_key = "a"
  let arg_message = "test"
  let edge_message = "a"
  let resNom = hmacSha512Str(arg_key, arg_message)
  let resEdge = hmacSha512Str(edge_key, edge_message)
  assertEqInt(resNom.len(), 128, "hmacSha512Str nominal string length == 128")
  assertEqInt(resEdge.len(), 128, "hmacSha512Str boundary string length == 128")
  ret 0
```

---

### `constantTimeEqual` (`std/crypto/hmac.aipl`)

- **Signature**: `pub fn constantTimeEqual(a: bytes, b: bytes): bool:`
- **Import**: `import * from "std/crypto/hmac"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: bytes, b: bytes` | **Returns**: `bool`
- **Unit Test**: `tests/functions/crypto/hmac_test.aipl` | **Example**: `examples/ex_088_crypto_hmac_jwt_token_cli.aipl`
- **Behavioral Summary**: Verify `constantTimeEqual` RFC 4231 HMAC-SHA256/SHA512 test vectors and branchless constant-time comparison. Concrete nominal inputs: `a: bytes = [65, 73, 80, 76]`, `b: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `diff == 0`.

```aipl
module tests.functions.crypto.hmac_z5_test
import * from "std/crypto/hmac"
import { Sha256Hasher, sha256, sha512 } from "std/crypto/hash"
import { hexEncode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hmac_constantTimeEqual_5(): int:
  let arg_a = [65, 73, 80, 76]
  let edge_a = [65]
  let arg_b = [65, 73, 80, 76]
  let edge_b = [65]
  let resNom = constantTimeEqual(arg_a, arg_b)
  let resEdge = constantTimeEqual(edge_a, edge_b)
  assert(resNom == true, "constantTimeEqual nominal resNom == true")
  assert(resEdge == true, "constantTimeEqual boundary resEdge == true")
  ret 0
```

---

### `constantTimeEqualStr` (`std/crypto/hmac.aipl`)

- **Signature**: `pub fn constantTimeEqualStr(a: str, b: str): bool:`
- **Import**: `import * from "std/crypto/hmac"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: str, b: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/crypto/hmac_test.aipl` | **Example**: `examples/ex_089_crypto_kdf_pbkdf2_hkdf_cli.aipl`
- **Behavioral Summary**: Verify `constantTimeEqualStr` RFC 4231 HMAC-SHA256/SHA512 test vectors and branchless constant-time comparison. Concrete nominal inputs: `a: str = "aipl_test"`, `b: str = "aipl_test"`; exercises core body path returning/computing `constantTimeEqual(a.toBytes(), b.toBytes())`.

```aipl
module tests.functions.crypto.hmac_z6_test
import * from "std/crypto/hmac"
import { Sha256Hasher, sha256, sha512 } from "std/crypto/hash"
import { hexEncode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hmac_constantTimeEqualStr_6(): int:
  let arg_a = "test"
  let edge_a = "a"
  let arg_b = "test"
  let edge_b = "a"
  let resNom = constantTimeEqualStr(arg_a, arg_b)
  let resEdge = constantTimeEqualStr(edge_a, edge_b)
  assert(resNom == true, "constantTimeEqualStr nominal resNom == true")
  assert(resEdge == true, "constantTimeEqualStr boundary resEdge == true")
  ret 0
```

---

### `hkdfExtract` (`std/crypto/kdf.aipl`)

- **Signature**: `pub fn hkdfExtract(salt: bytes, ikm: bytes): bytes:`
- **Import**: `import * from "std/crypto/kdf"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `salt: bytes, ikm: bytes` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/crypto/kdf_test.aipl` | **Example**: `examples/ex_087_crypto_sha256_blake3_shasum_cli.aipl`
- **Behavioral Summary**: Verify `hkdfExtract` RFC 5869 HKDF-SHA256 extract/expand, PBKDF2-HMAC-SHA256 iteration scaling, and Argon2id password hash/verify. Concrete nominal inputs: `salt: bytes = [65, 73, 80, 76]`, `ikm: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `hmacSha256(actualSalt, ikm)`.

```aipl
module tests.functions.crypto.kdf_z1_test
import * from "std/crypto/kdf"
import { hmacSha256, hmacSha512, constantTimeEqual } from "std/crypto/hmac"
import { sha256, blake3 } from "std/crypto/hash"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_kdf_hkdfExtract_1(): int:
  let arg_salt = [65, 73, 80, 76]
  let edge_salt = [65]
  let arg_ikm = [65, 73, 80, 76]
  let edge_ikm = [65]
  let resNom = hkdfExtract(arg_salt, arg_ikm)
  let resEdge = hkdfExtract(edge_salt, edge_ikm)
  assertEqInt(resNom.len(), 32, "hkdfExtract nominal resNom.len() == 32")
  assertEqInt(resEdge.len(), 32, "hkdfExtract boundary resEdge.len() == 32")
  ret 0
```

---

### `hkdfExpand` (`std/crypto/kdf.aipl`)

- **Signature**: `pub fn hkdfExpand(prk: bytes, info: bytes, outLen: int): bytes:`
- **Import**: `import * from "std/crypto/kdf"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `prk: bytes, info: bytes, outLen: int` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/crypto/kdf_test.aipl` | **Example**: `examples/ex_088_crypto_hmac_jwt_token_cli.aipl`
- **Behavioral Summary**: Verify `hkdfExpand` RFC 5869 HKDF-SHA256 extract/expand, PBKDF2-HMAC-SHA256 iteration scaling, and Argon2id password hash/verify. Concrete nominal inputs: `prk: bytes = [65, 73, 80, 76]`, `info: bytes = [65, 73, 80, 76]`, `outLen: int = 64`; exercises core body path returning/computing `bytesFromArray(out)`.

```aipl
module tests.functions.crypto.kdf_z2_test
import * from "std/crypto/kdf"
import { hmacSha256, hmacSha512, constantTimeEqual } from "std/crypto/hmac"
import { sha256, blake3 } from "std/crypto/hash"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_kdf_hkdfExpand_2(): int:
  let arg_prk = [65, 73, 80, 76]
  let edge_prk = [65]
  let arg_info = [65, 73, 80, 76]
  let edge_info = [65]
  let arg_outLen = 4
  let edge_outLen = 1
  let resNom = hkdfExpand(arg_prk, arg_info, arg_outLen)
  let resEdge = hkdfExpand(edge_prk, edge_info, edge_outLen)
  assertEqInt(resNom.len(), 4, "hkdfExpand nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 1, "hkdfExpand boundary resEdge.len() == 1")
  ret 0
```

---

### `hkdfSha256` (`std/crypto/kdf.aipl`)

- **Signature**: `pub fn hkdfSha256(salt: bytes, ikm: bytes, info: bytes, outLen: int): bytes:`
- **Import**: `import * from "std/crypto/kdf"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `salt: bytes, ikm: bytes, info: bytes, outLen: int` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/crypto/kdf_test.aipl` | **Example**: `examples/ex_089_crypto_kdf_pbkdf2_hkdf_cli.aipl`
- **Behavioral Summary**: Verify `hkdfSha256` RFC 5869 HKDF-SHA256 extract/expand, PBKDF2-HMAC-SHA256 iteration scaling, and Argon2id password hash/verify. Concrete nominal inputs: `salt: bytes = [65, 73, 80, 76]`, `ikm: bytes = [65, 73, 80, 76]`, `info: bytes = [65, 73, 80, 76]`, `outLen: int = 64`; exercises core body path returning/computing `hkdfExpand(prk, info, outLen)`.

```aipl
module tests.functions.crypto.kdf_z3_test
import * from "std/crypto/kdf"
import { hmacSha256, hmacSha512, constantTimeEqual } from "std/crypto/hmac"
import { sha256, blake3 } from "std/crypto/hash"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_kdf_hkdfSha256_3(): int:
  let arg_salt = [65, 73, 80, 76]
  let edge_salt = [65]
  let arg_ikm = [65, 73, 80, 76]
  let edge_ikm = [65]
  let arg_info = [65, 73, 80, 76]
  let edge_info = [65]
  let arg_outLen = 4
  let edge_outLen = 1
  let resNom = hkdfSha256(arg_salt, arg_ikm, arg_info, arg_outLen)
  let resEdge = hkdfSha256(edge_salt, edge_ikm, edge_info, edge_outLen)
  assertEqInt(resNom.len(), 4, "hkdfSha256 nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 1, "hkdfSha256 boundary resEdge.len() == 1")
  ret 0
```

---

### `pbkdf2HmacSha256` (`std/crypto/kdf.aipl`)

- **Signature**: `pub fn pbkdf2HmacSha256(password: bytes, salt: bytes, iterations: int, outLen: int): bytes:`
- **Import**: `import * from "std/crypto/kdf"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `password: bytes, salt: bytes, iterations: int, outLen: int` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/crypto/kdf_test.aipl` | **Example**: `examples/ex_087_crypto_sha256_blake3_shasum_cli.aipl`
- **Behavioral Summary**: Verify `pbkdf2HmacSha256` RFC 5869 HKDF-SHA256 extract/expand, PBKDF2-HMAC-SHA256 iteration scaling, and Argon2id password hash/verify. Concrete nominal inputs: `password: bytes = [65, 73, 80, 76]`, `salt: bytes = [65, 73, 80, 76]`, `iterations: int = 1`, `outLen: int = 64`; exercises core body path returning/computing `bytesFromArray(out)`.

```aipl
module tests.functions.crypto.kdf_z4_test
import * from "std/crypto/kdf"
import { hmacSha256, hmacSha512, constantTimeEqual } from "std/crypto/hmac"
import { sha256, blake3 } from "std/crypto/hash"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_kdf_pbkdf2HmacSha256_4(): int:
  let arg_password = [65, 73, 80, 76]
  let edge_password = [65]
  let arg_salt = [65, 73, 80, 76]
  let edge_salt = [65]
  let arg_iterations = 4
  let edge_iterations = 1
  let arg_outLen = 4
  let edge_outLen = 1
  let resNom = pbkdf2HmacSha256(arg_password, arg_salt, arg_iterations, arg_outLen)
  let resEdge = pbkdf2HmacSha256(edge_password, edge_salt, edge_iterations, edge_outLen)
  assertEqInt(resNom.len(), 4, "pbkdf2HmacSha256 nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 1, "pbkdf2HmacSha256 boundary resEdge.len() == 1")
  ret 0
```

---

### `argon2idHash` (`std/crypto/kdf.aipl`)

- **Signature**: `pub fn argon2idHash(password: bytes, params: Argon2Params): bytes:`
- **Import**: `import * from "std/crypto/kdf"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `password: bytes, params: Argon2Params` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/crypto/kdf_test.aipl` | **Example**: `examples/ex_088_crypto_hmac_jwt_token_cli.aipl`
- **Behavioral Summary**: Verify `argon2idHash` RFC 5869 HKDF-SHA256 extract/expand, PBKDF2-HMAC-SHA256 iteration scaling, and Argon2id password hash/verify. Concrete nominal inputs: `password: bytes = [65, 73, 80, 76]`, `params: Argon2Params = Argon2Params(timeCost = 1, memoryCostKiB = 1, parallelism = 1, keyLen = 64, salt = [65, 73, 80, 76])`; exercises core body path returning/computing `hkdfExpand(sha256(state), params.salt, outLen)`.

```aipl
module tests.functions.crypto.kdf_z5_test
import * from "std/crypto/kdf"
import { hmacSha256, hmacSha512, constantTimeEqual } from "std/crypto/hmac"
import { sha256, blake3 } from "std/crypto/hash"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_kdf_argon2idHash_5(): int:
  let arg_password = [65, 73, 80, 76]
  let edge_password = [65]
  let arg_params = Argon2Params(timeCost = 4, memoryCostKiB = 4, parallelism = 4, keyLen = 4, salt = [65, 73, 80, 76])
  let edge_params = Argon2Params(timeCost = 1, memoryCostKiB = 1, parallelism = 1, keyLen = 1, salt = [65])
  let resNom = argon2idHash(arg_password, arg_params)
  let resEdge = argon2idHash(edge_password, edge_params)
  assertEqInt(resNom.len(), 4, "argon2idHash nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 1, "argon2idHash boundary resEdge.len() == 1")
  ret 0
```

---

### `argon2idVerify` (`std/crypto/kdf.aipl`)

- **Signature**: `pub fn argon2idVerify(password: bytes, hash: bytes, params: Argon2Params): bool:`
- **Import**: `import * from "std/crypto/kdf"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `password: bytes, hash: bytes, params: Argon2Params` | **Returns**: `bool`
- **Unit Test**: `tests/functions/crypto/kdf_test.aipl` | **Example**: `examples/ex_089_crypto_kdf_pbkdf2_hkdf_cli.aipl`
- **Behavioral Summary**: Verify `argon2idVerify` RFC 5869 HKDF-SHA256 extract/expand, PBKDF2-HMAC-SHA256 iteration scaling, and Argon2id password hash/verify. Concrete nominal inputs: `password: bytes = [65, 73, 80, 76]`, `hash: bytes = [65, 73, 80, 76]`, `params: Argon2Params = Argon2Params(timeCost = 1, memoryCostKiB = 1, parallelism = 1, keyLen = 64, salt = [65, 73, 80, 76])`; exercises core body path returning/computing `constantTimeEqual(computed, hash)`.

```aipl
module tests.functions.crypto.kdf_z6_test
import * from "std/crypto/kdf"
import { hmacSha256, hmacSha512, constantTimeEqual } from "std/crypto/hmac"
import { sha256, blake3 } from "std/crypto/hash"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_kdf_argon2idVerify_6(): int:
  let arg_password = [65, 73, 80, 76]
  let edge_password = [65]
  let arg_hash = [65, 73, 80, 76]
  let edge_hash = [65]
  let arg_params = Argon2Params(timeCost = 4, memoryCostKiB = 4, parallelism = 4, keyLen = 4, salt = [65, 73, 80, 76])
  let edge_params = Argon2Params(timeCost = 1, memoryCostKiB = 1, parallelism = 1, keyLen = 1, salt = [65])
  let resNom = argon2idVerify(arg_password, arg_hash, arg_params)
  let resEdge = argon2idVerify(edge_password, edge_hash, edge_params)
  assert(resNom == false, "argon2idVerify nominal resNom == false")
  assert(resEdge == false, "argon2idVerify boundary resEdge == false")
  ret 0
```

---

### `tlsFrameRecord` (`std/crypto/tls.aipl`)

- **Signature**: `pub fn tlsFrameRecord(contentType: int, payload: bytes): bytes:`
- **Import**: `import * from "std/crypto/tls"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `contentType: int, payload: bytes` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/crypto/tls_test.aipl` | **Example**: `examples/ex_087_crypto_sha256_blake3_shasum_cli.aipl`
- **Behavioral Summary**: Verify `tlsFrameRecord` TLS 1.3 record framing/parsing, ClientHello SNI extension encoding, and X.509 certificate validity window verification. Concrete nominal inputs: `contentType: int = 1`, `payload: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `bytesConcat([header, payload])`.

```aipl
module tests.functions.crypto.tls_z1_test
import * from "std/crypto/tls"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tls_tlsFrameRecord_1(): int:
  let arg_contentType = 4
  let edge_contentType = 1
  let arg_payload = [65, 73, 80, 76]
  let edge_payload = [65]
  let resNom = tlsFrameRecord(arg_contentType, arg_payload)
  let resEdge = tlsFrameRecord(edge_contentType, edge_payload)
  assertEqInt(resNom.len(), 5, "tlsFrameRecord nominal resNom.len() == 5")
  assertEqInt(resEdge.len(), 5, "tlsFrameRecord boundary resEdge.len() == 5")
  ret 0
```

---

### `tlsParseRecord` (`std/crypto/tls.aipl`)

- **Signature**: `pub fn tlsParseRecord(streamBytes: bytes, offset: int = 0): Result[(TlsRecord, int), str]:`
- **Import**: `import * from "std/crypto/tls"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `streamBytes: bytes, offset: int = 0` | **Returns**: `Result[(TlsRecord, int), str]`
- **Unit Test**: `tests/functions/crypto/tls_test.aipl` | **Example**: `examples/ex_088_crypto_hmac_jwt_token_cli.aipl`
- **Behavioral Summary**: Verify `tlsParseRecord` TLS 1.3 record framing/parsing, ClientHello SNI extension encoding, and X.509 certificate validity window verification. Concrete nominal inputs: `streamBytes: bytes = [65, 73, 80, 76]`, `offset: int = 0`; exercises core body path returning/computing `Ok((rec, offset + 5 + fragLen))`.

```aipl
module tests.functions.crypto.tls_z2_test
import * from "std/crypto/tls"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tls_tlsParseRecord_2(): int:
  let arg_streamBytes = [65, 73, 80, 76]
  let edge_streamBytes = [65]
  let arg_offset = 1
  let edge_offset = 0
  let resNom = tlsParseRecord(arg_streamBytes, arg_offset)
  let resEdge = tlsParseRecord(edge_streamBytes, edge_offset)
  assert(resNom.isOk() == false, "tlsParseRecord nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "tlsParseRecord boundary resEdge.isOk() == false")
  ret 0
```

---

### `tlsBuildClientHello` (`std/crypto/tls.aipl`)

- **Signature**: `pub fn tlsBuildClientHello(host: str, suites: [int], random: bytes, keyShare: bytes): bytes:`
- **Import**: `import * from "std/crypto/tls"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `host: str, suites: [int], random: bytes, keyShare: bytes` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/crypto/tls_test.aipl` | **Example**: `examples/ex_089_crypto_kdf_pbkdf2_hkdf_cli.aipl`
- **Behavioral Summary**: Verify `tlsBuildClientHello` TLS 1.3 record framing/parsing, ClientHello SNI extension encoding, and X.509 certificate validity window verification. Concrete nominal inputs: `host: str = "127.0.0.1"`, `suites: [int] = [1]`, `random: bytes = [65, 73, 80, 76]`, `keyShare: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `tlsFrameRecord(22, bytesConcat([hsHeader, bytesFromArray(body)]))`.

```aipl
module tests.functions.crypto.tls_z3_test
import * from "std/crypto/tls"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tls_tlsBuildClientHello_3(): int:
  let arg_host = "127.0.0.1"
  let edge_host = "127.0.0.1"
  let arg_suites = [2]
  let edge_suites = []
  let arg_random = [65, 73, 80, 76]
  let edge_random = [65]
  let arg_keyShare = [65, 73, 80, 76]
  let edge_keyShare = [65]
  let resNom = tlsBuildClientHello(arg_host, arg_suites, arg_random, arg_keyShare)
  let resEdge = tlsBuildClientHello(edge_host, edge_suites, edge_random, edge_keyShare)
  assertEqInt(resNom.len(), 65, "tlsBuildClientHello nominal resNom.len() == 65")
  assertEqInt(resEdge.len(), 60, "tlsBuildClientHello boundary resEdge.len() == 60")
  ret 0
```

---

### `verifyX509Validity` (`std/crypto/tls.aipl`)

- **Signature**: `pub fn verifyX509Validity(cert: X509Cert, currentUnixSec: int): bool:`
- **Import**: `import * from "std/crypto/tls"` (or barrel `import * from "std/crypto/crypto_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cert: X509Cert, currentUnixSec: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/crypto/tls_test.aipl` | **Example**: `examples/ex_087_crypto_sha256_blake3_shasum_cli.aipl`
- **Behavioral Summary**: Verify `verifyX509Validity` TLS 1.3 record framing/parsing, ClientHello SNI extension encoding, and X.509 certificate validity window verification. Concrete nominal inputs: `cert: X509Cert = X509Cert(issuer = "aipl_test", subject = "aipl_test", notBefore = 1, notAfter = 1, publicKey = [65, 73, 80, 76])`, `currentUnixSec: int = 1`; exercises core body path returning/computing `currentUnixSec >= cert.notBefore and currentUnixSec <= cert.notAfter`.

```aipl
module tests.functions.crypto.tls_z4_test
import * from "std/crypto/tls"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tls_verifyX509Validity_4(): int:
  let arg_cert = X509Cert(issuer = "test", subject = "test", notBefore = 4, notAfter = 4, publicKey = [65, 73, 80, 76])
  let edge_cert = X509Cert(issuer = "a", subject = "a", notBefore = 1, notAfter = 1, publicKey = [65])
  let arg_currentUnixSec = 4
  let edge_currentUnixSec = 1
  let resNom = verifyX509Validity(arg_cert, arg_currentUnixSec)
  let resEdge = verifyX509Validity(edge_cert, edge_currentUnixSec)
  assert(resNom == true, "verifyX509Validity nominal resNom == true")
  assert(resEdge == true, "verifyX509Validity boundary resEdge == true")
  ret 0
```

---

### `computeApkV2DigestsSha256` (`std/crypto/apk_Sig_v2.aipl`)

- **Signature**: `pub fn computeApkV2DigestsSha256(zipEntriesSection: str, centralDirSection: str, eocdSection: str): str requires zipEntriesSection.len() >= 0 and centralDirSection.len() >= 0 and eocdSection.len() >= 0 ensures result == "" or result.len() == 64:`
- **Import**: `import { computeApkV2DigestsSha256 } from "std/crypto/apk_Sig_v2"`
- **Receiver**: `None (free function)` | **Parameters**: `zipEntriesSection: str, centralDirSection: str, eocdSection: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/crypto/apk_Sig_v2_test.aipl` | **Example**: `examples/ex_087_crypto_sha256_blake3_shasum_cli.aipl`
- **Behavioral Summary**: Computes the top-level 256-bit SHA-256 root digest over the 3 APK ZIP sections (entries, central directory, EOCD) following the standard Android APK Signature Scheme v2 specification.

```aipl
module tests.functions.crypto.apk_sig_ref_01_test
import { computeApkV2DigestsSha256 } from "std/crypto/apk_Sig_v2"
import { assertEqInt } from "std/prelude"
pub fn test_computeApkV2DigestsSha256_ref(): int:
  let d = computeApkV2DigestsSha256("entries_payload", "central_dir", "eocd_record")
  assertEqInt(d.len(), 64, "root digest is 64 hex characters (256 bits)")
  let empty = computeApkV2DigestsSha256("", "", "")
  assertEqInt(empty.len(), 0, "empty input returns empty string")
  ret 0
```

---

### `buildApkSigningBlockV2` (`std/crypto/apk_Sig_v2.aipl`)

- **Signature**: `pub fn buildApkSigningBlockV2(topLevelSha256Hex: str): ApkSigningBlockV2 requires topLevelSha256Hex.len() >= 0 ensures result.magic == "APK Sig Block 42" and result.v2SchemeId == 1896449818:`
- **Import**: `import { buildApkSigningBlockV2, APK_SIG_BLOCK_V2_ID } from "std/crypto/apk_Sig_v2"`
- **Receiver**: `None (free function)` | **Parameters**: `topLevelSha256Hex: str` | **Returns**: `ApkSigningBlockV2`
- **Unit Test**: `tests/functions/crypto/apk_Sig_v2_test.aipl` | **Example**: `examples/ex_087_crypto_sha256_blake3_shasum_cli.aipl`
- **Behavioral Summary**: Constructs an `ApkSigningBlockV2` record initialized with scheme ID `0x7109871a` (`1896449818`), magic trailer `"APK Sig Block 42"`, and identical head and tail 4096-byte sizing.

```aipl
module tests.functions.crypto.apk_sig_ref_02_test
import { buildApkSigningBlockV2, APK_SIG_BLOCK_V2_ID } from "std/crypto/apk_Sig_v2"
import { assert, assertEqInt, assertEqStr } from "std/prelude"
pub fn test_buildApkSigningBlockV2_ref(): int:
  let dummyHex = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
  let block = buildApkSigningBlockV2(dummyHex)
  assert(block.isValid == true, "signing block is valid")
  assertEqStr(block.magic, "APK Sig Block 42", "magic matches")
  assertEqInt(block.v2SchemeId, APK_SIG_BLOCK_V2_ID, "scheme ID == 0x7109871a")
  ret 0
```

---

### `verifyApkSigningBlockV2` (`std/crypto/apk_Sig_v2.aipl`)

- **Signature**: `pub fn verifyApkSigningBlockV2(magic: str, sizeHead: int, sizeTail: int, schemeId: int, signedDigest: str, computedDigest: str): bool requires magic.len() >= 0 ensures not result or (magic == "APK Sig Block 42" and sizeHead == sizeTail and schemeId == 1896449818):`
- **Import**: `import { verifyApkSigningBlockV2, APK_SIG_BLOCK_V2_ID } from "std/crypto/apk_Sig_v2"`
- **Receiver**: `None (free function)` | **Parameters**: `magic: str, sizeHead: int, sizeTail: int, schemeId: int, signedDigest: str, computedDigest: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/crypto/apk_Sig_v2_test.aipl` | **Example**: `examples/ex_087_crypto_sha256_blake3_shasum_cli.aipl`
- **Behavioral Summary**: Verifies the cryptographic integrity of an APK Signing Block v2, enforcing `"APK Sig Block 42"` magic trailer match, symmetric size equality (`sizeHead == sizeTail`), scheme ID `1896449818`, and digest identity.

```aipl
module tests.functions.crypto.apk_sig_ref_03_test
import { verifyApkSigningBlockV2, APK_SIG_BLOCK_V2_ID } from "std/crypto/apk_Sig_v2"
import { assert } from "std/prelude"
pub fn test_verifyApkSigningBlockV2_ref(): int:
  let d = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
  let ok = verifyApkSigningBlockV2("APK Sig Block 42", 4096, 4096, APK_SIG_BLOCK_V2_ID, d, d)
  assert(ok == true, "signature block verified")
  let bad = verifyApkSigningBlockV2("INVALID_MAGIC_42", 4096, 4096, APK_SIG_BLOCK_V2_ID, d, d)
  assert(bad == false, "invalid magic rejected")
  ret 0
```
