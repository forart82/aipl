[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Domain 11: `compress` API Reference

> Complete API reference manual for AIPL standard library domain `compress` (35 callable functions & methods across ["std/compress/compress_mod.aipl", "std/compress/deflate.aipl", "std/compress/gzip.aipl", "std/compress/lz4.aipl", "std/compress/tar_archive.aipl", "std/compress/zstd.aipl", "std/compress/apk_zip_writer.aipl"]).

## 1. Domain Overview & Source Modules

- **Domain Name**: `compress`
- **Target Source Modules**: ["std/compress/compress_mod.aipl", "std/compress/deflate.aipl", "std/compress/gzip.aipl", "std/compress/lz4.aipl", "std/compress/tar_archive.aipl", "std/compress/zstd.aipl", "std/compress/apk_zip_writer.aipl"]
- **Total Callable Functions & Methods**: 35
- **Total Data Types (`struct` & `enum`)**: 12
- **Master Reference Hub**: [STDLIB_REFERENCE.md](STDLIB_REFERENCE.md)

---

## 2. Domain Data Types (`struct` & `enum`)

(12 public types declared across this domain's modules)

| Type Name | Kind | Source Module | Fields / Variants | Default Constructor / Description |
| :--- | :--- | :--- | :--- | :--- |
| `DeflateOptions` | `pub struct` | `std/compress/deflate.aipl` | `level: int = 6`, `windowBits: int = 15`, `memLevel: int = 8` | `DeflateOptions(level, windowBits, memLevel)` |
| `HuffmanTree` | `pub struct` | `std/compress/deflate.aipl` | `codeLens: [int]`, `codes: [int]`, `maxLen: int` | `HuffmanTree(codeLens, codes, maxLen)` |
| `Lz77Token` | `pub struct` | `std/compress/deflate.aipl` | `isMatch: bool`, `literalOrLength: int`, `distance: int` | `Lz77Token(isMatch, literalOrLength, distance)` |
| `GzipHeader` | `pub struct` | `std/compress/gzip.aipl` | `magic: (int, int)`, `compressionMethod: int`, `flags: int`, `mtime: int`, `extraFlags: int`, `os: int`, `fileName: str`, `comment: str` | `GzipHeader(magic, compressionMethod, flags, mtime, extraFlags, os, fileName, comment)` |
| `ZlibHeader` | `pub struct` | `std/compress/gzip.aipl` | `compressionMethod: int`, `info: int`, `fcheck: int`, `fdict: bool`, `flevel: int` | `ZlibHeader(compressionMethod, info, fcheck, fdict, flevel)` |
| `Lz4BlockHeader` | `pub struct` | `std/compress/lz4.aipl` | `compressedSize: int`, `uncompressedSize: int` | `Lz4BlockHeader(compressedSize, uncompressedSize)` |
| `Lz4FrameHeader` | `pub struct` | `std/compress/lz4.aipl` | `blockSizeMax: int`, `blockMode: int`, `contentChecksum: bool` | `Lz4FrameHeader(blockSizeMax, blockMode, contentChecksum)` |
| `TarEntry` | `pub struct` | `std/compress/tar_archive.aipl` | `path: str`, `mode: int`, `size: int`, `mtime: int`, `isDir: bool`, `data: bytes` | `TarEntry(path, mode, size, mtime, isDir, data)` |
| `TarArchive` | `pub struct` | `std/compress/tar_archive.aipl` | `mut entries: [TarEntry] = []` | `TarArchive(mut entries)` |
| `ZstdFrameHeader` | `pub struct` | `std/compress/zstd.aipl` | `magic: int`, `windowSize: int`, `singleSegment: bool`, `contentChecksum: bool` | `ZstdFrameHeader(magic, windowSize, singleSegment, contentChecksum)` |
| `ZstdBlockHeader` | `pub struct` | `std/compress/zstd.aipl` | `isLast: bool`, `blockType: int`, `blockSize: int` | `ZstdBlockHeader(isLast, blockType, blockSize)` |
| `ApkArchiveBuilder` | `pub struct` | `std/compress/apk_zip_writer.aipl` | `currentOffset: int`, `entryCount: int`, `dosTimestamp: int`, `entries: [str]` | `ApkArchiveBuilder(currentOffset, entryCount, dosTimestamp, entries)` |

## 3. Quick-Lookup Function Index


| # | Source Module | Function / Method | Exact Signature | Unit Test File |
| :--- | :--- | :--- | :--- | :--- |
| `1` | `std/compress/compress_mod.aipl` | `compressGzip` | `pub fn compressGzip(data: bytes): bytes:` | `tests/functions/compress/compress_mod_test.aipl` |
| `2` | `std/compress/compress_mod.aipl` | `decompressGzip` | `pub fn decompressGzip(data: bytes): Result[bytes, str]:` | `tests/functions/compress/compress_mod_test.aipl` |
| `3` | `std/compress/compress_mod.aipl` | `compressLz4` | `pub fn compressLz4(data: bytes): bytes:` | `tests/functions/compress/compress_mod_test.aipl` |
| `4` | `std/compress/compress_mod.aipl` | `decompressLz4` | `pub fn decompressLz4(data: bytes): Result[bytes, str]:` | `tests/functions/compress/compress_mod_test.aipl` |
| `5` | `std/compress/compress_mod.aipl` | `compressZstd` | `pub fn compressZstd(data: bytes, level: int = 3): bytes:` | `tests/functions/compress/compress_mod_test.aipl` |
| `6` | `std/compress/compress_mod.aipl` | `decompressZstd` | `pub fn decompressZstd(data: bytes): Result[bytes, str]:` | `tests/functions/compress/compress_mod_test.aipl` |
| `7` | `std/compress/deflate.aipl` | `buildHuffmanTree` | `pub fn buildHuffmanTree(symbolFreqs: [int]): HuffmanTree:` | `tests/functions/compress/deflate_test.aipl` |
| `8` | `std/compress/deflate.aipl` | `lz77FindMatches` | `pub fn lz77FindMatches(data: bytes, windowSize: int = 32768, minMatchLen: int = 3): [Lz77Token]:` | `tests/functions/compress/deflate_test.aipl` |
| `9` | `std/compress/deflate.aipl` | `deflateCompress` | `pub fn deflateCompress(data: bytes, opts: DeflateOptions): bytes:` | `tests/functions/compress/deflate_test.aipl` |
| `10` | `std/compress/deflate.aipl` | `deflateDecompress` | `pub fn deflateDecompress(data: bytes): Result[bytes, str]:` | `tests/functions/compress/deflate_test.aipl` |
| `11` | `std/compress/gzip.aipl` | `computeAdler32` | `pub fn computeAdler32(data: bytes): int:` | `tests/functions/compress/gzip_test.aipl` |
| `12` | `std/compress/gzip.aipl` | `computeCrc32` | `pub fn computeCrc32(data: bytes): int:` | `tests/functions/compress/gzip_test.aipl` |
| `13` | `std/compress/gzip.aipl` | `gzipCompress` | `pub fn gzipCompress(data: bytes, filename: str = "", mtime: int = 0): bytes:` | `tests/functions/compress/gzip_test.aipl` |
| `14` | `std/compress/gzip.aipl` | `gzipDecompress` | `pub fn gzipDecompress(data: bytes): Result[bytes, str]:` | `tests/functions/compress/gzip_test.aipl` |
| `15` | `std/compress/gzip.aipl` | `zlibCompress` | `pub fn zlibCompress(data: bytes, level: int = 6): bytes:` | `tests/functions/compress/gzip_test.aipl` |
| `16` | `std/compress/gzip.aipl` | `zlibDecompress` | `pub fn zlibDecompress(data: bytes): Result[bytes, str]:` | `tests/functions/compress/gzip_test.aipl` |
| `17` | `std/compress/lz4.aipl` | `lz4CompressBlock` | `pub fn lz4CompressBlock(src: bytes): bytes:` | `tests/functions/compress/lz4_test.aipl` |
| `18` | `std/compress/lz4.aipl` | `lz4DecompressBlock` | `pub fn lz4DecompressBlock(src: bytes, uncompressedSize: int): Result[bytes, str]:` | `tests/functions/compress/lz4_test.aipl` |
| `19` | `std/compress/lz4.aipl` | `lz4CompressFrame` | `pub fn lz4CompressFrame(src: bytes): bytes:` | `tests/functions/compress/lz4_test.aipl` |
| `20` | `std/compress/lz4.aipl` | `lz4DecompressFrame` | `pub fn lz4DecompressFrame(src: bytes): Result[bytes, str]:` | `tests/functions/compress/lz4_test.aipl` |
| `21` | `std/compress/tar_archive.aipl` | `writeOctalField` | `fn writeOctalField(mut blk: [int], offset: int, width: int, val: int): [int]:` | `tests/functions/compress/tar_archive_test.aipl` |
| `22` | `std/compress/tar_archive.aipl` | `parseOctalField` | `fn parseOctalField(data: bytes, offset: int, width: int): int:` | `tests/functions/compress/tar_archive_test.aipl` |
| `23` | `std/compress/tar_archive.aipl` | `readNullTermStr` | `fn readNullTermStr(data: bytes, offset: int, maxLen: int): str:` | `tests/functions/compress/tar_archive_test.aipl` |
| `24` | `std/compress/tar_archive.aipl` | `tarPack` | `pub fn tarPack(entries: [TarEntry]): bytes:` | `tests/functions/compress/tar_archive_test.aipl` |
| `25` | `std/compress/tar_archive.aipl` | `tarUnpack` | `pub fn tarUnpack(archiveBytes: bytes): Result[[TarEntry], str]:` | `tests/functions/compress/tar_archive_test.aipl` |
| `26` | `std/compress/tar_archive.aipl` | `getEntry` | `pub fn (self: TarArchive) getEntry(path: str): Option[TarEntry]:` | `tests/functions/compress/tar_archive_test.aipl` |
| `27` | `std/compress/tar_archive.aipl` | `addFile` | `pub fn (mut self: TarArchive) addFile(path: str, data: bytes, mode: int = 420): void:` | `tests/functions/compress/tar_archive_test.aipl` |
| `28` | `std/compress/tar_archive.aipl` | `addDirectory` | `pub fn (mut self: TarArchive) addDirectory(path: str, mode: int = 493): void:` | `tests/functions/compress/tar_archive_test.aipl` |
| `29` | `std/compress/tar_archive.aipl` | `toBytes` | `pub fn (self: TarArchive) toBytes(): bytes:` | `tests/functions/compress/tar_archive_test.aipl` |
| `30` | `std/compress/zstd.aipl` | `zstdCompress` | `pub fn zstdCompress(data: bytes, level: int = 3): bytes:` | `tests/functions/compress/zstd_test.aipl` |
| `31` | `std/compress/zstd.aipl` | `zstdDecompress` | `pub fn zstdDecompress(data: bytes): Result[bytes, str]:` | `tests/functions/compress/zstd_test.aipl` |
| `32` | `std/compress/apk_zip_writer.aipl` | `createApkArchiveBuilder` | `pub fn createApkArchiveBuilder(templateSizeBytes: int): ApkArchiveBuilder:` | `tests/functions/compress/apk_zip_writer_test.aipl` |
| `33` | `std/compress/apk_zip_writer.aipl` | `apkAlignUncompressed4Byte` | `pub fn apkAlignUncompressed4Byte(localHeaderEndOffset: int, fileName: str): (int, int):` | `tests/functions/compress/apk_zip_writer_test.aipl` |
| `34` | `std/compress/apk_zip_writer.aipl` | `apkInjectAssetEntry` | `pub fn apkInjectAssetEntry(currentOffset: int, entryName: str, payload: str): (int, int, int):` | `tests/functions/compress/apk_zip_writer_test.aipl` |
| `35` | `std/compress/apk_zip_writer.aipl` | `finalizeApkCentralDirectory` | `pub fn finalizeApkCentralDirectory(cdStartOffset: int, entryNames: [str]): (int, int, int):` | `tests/functions/compress/apk_zip_writer_test.aipl` |

---

## 4. Detailed API Reference & Runnable Verification Snippets

### `compressGzip` (`std/compress/compress_mod.aipl`)

- **Signature**: `pub fn compressGzip(data: bytes): bytes:`
- **Import**: `import * from "std/compress/compress_mod"` (or barrel `import * from "std/compress/compress_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/compress/compress_mod_test.aipl` | **Example**: `examples/ex_082_compress_deflate_huffman_cli.aipl`
- **Behavioral Summary**: Verify top-level compression facade `compressGzip` across empty, single-byte, and multi-kilobyte payloads. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `gzipCompress(data, "", 0)`.

```aipl
module tests.functions.compress.compress_mod_z1_test
import * from "std/compress/compress_mod"
import { DeflateOptions, HuffmanTree, Lz77Token, buildHuffmanTree, lz77FindMatches, deflateCompress, deflateDecompress } from "std/compress/deflate"
import { GzipHeader, ZlibHeader, computeAdler32, computeCrc32, gzipCompress, gzipDecompress, zlibCompress, zlibDecompress } from "std/compress/gzip"
import { Lz4BlockHeader, Lz4FrameHeader, lz4CompressBlock, lz4DecompressBlock, lz4CompressFrame, lz4DecompressFrame } from "std/compress/lz4"
import { ZstdFrameHeader, ZstdBlockHeader, zstdCompress, zstdDecompress } from "std/compress/zstd"
import { TarEntry, TarArchive, tarPack, tarUnpack } from "std/compress/tar_archive"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_compress_mod_compressGzip_1(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let resNom = compressGzip(arg_data)
  let resEdge = compressGzip(edge_data)
  assertEqInt(resNom.len(), 23, "compressGzip nominal resNom.len() == 23")
  assertEqInt(resEdge.len(), 20, "compressGzip boundary resEdge.len() == 20")
  ret 0
```

---

### `decompressGzip` (`std/compress/compress_mod.aipl`)

- **Signature**: `pub fn decompressGzip(data: bytes): Result[bytes, str]:`
- **Import**: `import * from "std/compress/compress_mod"` (or barrel `import * from "std/compress/compress_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes` | **Returns**: `Result[bytes, str]`
- **Unit Test**: `tests/functions/compress/compress_mod_test.aipl` | **Example**: `examples/ex_083_compress_gzip_crc32_tool_cli.aipl`
- **Behavioral Summary**: Verify top-level compression facade `decompressGzip` across empty, single-byte, and multi-kilobyte payloads. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `gzipDecompress(data)`.

```aipl
module tests.functions.compress.compress_mod_z2_test
import * from "std/compress/compress_mod"
import { DeflateOptions, HuffmanTree, Lz77Token, buildHuffmanTree, lz77FindMatches, deflateCompress, deflateDecompress } from "std/compress/deflate"
import { GzipHeader, ZlibHeader, computeAdler32, computeCrc32, gzipCompress, gzipDecompress, zlibCompress, zlibDecompress } from "std/compress/gzip"
import { Lz4BlockHeader, Lz4FrameHeader, lz4CompressBlock, lz4DecompressBlock, lz4CompressFrame, lz4DecompressFrame } from "std/compress/lz4"
import { ZstdFrameHeader, ZstdBlockHeader, zstdCompress, zstdDecompress } from "std/compress/zstd"
import { TarEntry, TarArchive, tarPack, tarUnpack } from "std/compress/tar_archive"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_compress_mod_decompressGzip_2(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let resNom = decompressGzip(arg_data)
  let resEdge = decompressGzip(edge_data)
  assert(resNom.isOk() == false, "decompressGzip nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "decompressGzip boundary resEdge.isOk() == false")
  ret 0
```

---

### `compressLz4` (`std/compress/compress_mod.aipl`)

- **Signature**: `pub fn compressLz4(data: bytes): bytes:`
- **Import**: `import * from "std/compress/compress_mod"` (or barrel `import * from "std/compress/compress_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/compress/compress_mod_test.aipl` | **Example**: `examples/ex_084_compress_lz4_highspeed_cli.aipl`
- **Behavioral Summary**: Verify top-level compression facade `compressLz4` across empty, single-byte, and multi-kilobyte payloads. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `lz4CompressFrame(data)`.

```aipl
module tests.functions.compress.compress_mod_z3_test
import * from "std/compress/compress_mod"
import { DeflateOptions, HuffmanTree, Lz77Token, buildHuffmanTree, lz77FindMatches, deflateCompress, deflateDecompress } from "std/compress/deflate"
import { GzipHeader, ZlibHeader, computeAdler32, computeCrc32, gzipCompress, gzipDecompress, zlibCompress, zlibDecompress } from "std/compress/gzip"
import { Lz4BlockHeader, Lz4FrameHeader, lz4CompressBlock, lz4DecompressBlock, lz4CompressFrame, lz4DecompressFrame } from "std/compress/lz4"
import { ZstdFrameHeader, ZstdBlockHeader, zstdCompress, zstdDecompress } from "std/compress/zstd"
import { TarEntry, TarArchive, tarPack, tarUnpack } from "std/compress/tar_archive"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_compress_mod_compressLz4_3(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let resNom = compressLz4(arg_data)
  let resEdge = compressLz4(edge_data)
  assertEqInt(resNom.len(), 24, "compressLz4 nominal resNom.len() == 24")
  assertEqInt(resEdge.len(), 21, "compressLz4 boundary resEdge.len() == 21")
  ret 0
```

---

### `decompressLz4` (`std/compress/compress_mod.aipl`)

- **Signature**: `pub fn decompressLz4(data: bytes): Result[bytes, str]:`
- **Import**: `import * from "std/compress/compress_mod"` (or barrel `import * from "std/compress/compress_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes` | **Returns**: `Result[bytes, str]`
- **Unit Test**: `tests/functions/compress/compress_mod_test.aipl` | **Example**: `examples/ex_082_compress_deflate_huffman_cli.aipl`
- **Behavioral Summary**: Verify top-level compression facade `decompressLz4` across empty, single-byte, and multi-kilobyte payloads. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `lz4DecompressFrame(data)`.

```aipl
module tests.functions.compress.compress_mod_z4_test
import * from "std/compress/compress_mod"
import { DeflateOptions, HuffmanTree, Lz77Token, buildHuffmanTree, lz77FindMatches, deflateCompress, deflateDecompress } from "std/compress/deflate"
import { GzipHeader, ZlibHeader, computeAdler32, computeCrc32, gzipCompress, gzipDecompress, zlibCompress, zlibDecompress } from "std/compress/gzip"
import { Lz4BlockHeader, Lz4FrameHeader, lz4CompressBlock, lz4DecompressBlock, lz4CompressFrame, lz4DecompressFrame } from "std/compress/lz4"
import { ZstdFrameHeader, ZstdBlockHeader, zstdCompress, zstdDecompress } from "std/compress/zstd"
import { TarEntry, TarArchive, tarPack, tarUnpack } from "std/compress/tar_archive"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_compress_mod_decompressLz4_4(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let resNom = decompressLz4(arg_data)
  let resEdge = decompressLz4(edge_data)
  assert(resNom.isOk() == false, "decompressLz4 nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "decompressLz4 boundary resEdge.isOk() == false")
  ret 0
```

---

### `compressZstd` (`std/compress/compress_mod.aipl`)

- **Signature**: `pub fn compressZstd(data: bytes, level: int = 3): bytes:`
- **Import**: `import * from "std/compress/compress_mod"` (or barrel `import * from "std/compress/compress_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes, level: int = 3` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/compress/compress_mod_test.aipl` | **Example**: `examples/ex_083_compress_gzip_crc32_tool_cli.aipl`
- **Behavioral Summary**: Verify top-level compression facade `compressZstd` across empty, single-byte, and multi-kilobyte payloads. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`, `level: int = 1`; exercises core body path returning/computing `zstdCompress(data, level)`.

```aipl
module tests.functions.compress.compress_mod_z5_test
import * from "std/compress/compress_mod"
import { DeflateOptions, HuffmanTree, Lz77Token, buildHuffmanTree, lz77FindMatches, deflateCompress, deflateDecompress } from "std/compress/deflate"
import { GzipHeader, ZlibHeader, computeAdler32, computeCrc32, gzipCompress, gzipDecompress, zlibCompress, zlibDecompress } from "std/compress/gzip"
import { Lz4BlockHeader, Lz4FrameHeader, lz4CompressBlock, lz4DecompressBlock, lz4CompressFrame, lz4DecompressFrame } from "std/compress/lz4"
import { ZstdFrameHeader, ZstdBlockHeader, zstdCompress, zstdDecompress } from "std/compress/zstd"
import { TarEntry, TarArchive, tarPack, tarUnpack } from "std/compress/tar_archive"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_compress_mod_compressZstd_5(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let arg_level = 2
  let edge_level = 0
  let resNom = compressZstd(arg_data, arg_level)
  let resEdge = compressZstd(edge_data, edge_level)
  assertEqInt(resNom.len(), 21, "compressZstd nominal resNom.len() == 21")
  assertEqInt(resEdge.len(), 18, "compressZstd boundary resEdge.len() == 18")
  ret 0
```

---

### `decompressZstd` (`std/compress/compress_mod.aipl`)

- **Signature**: `pub fn decompressZstd(data: bytes): Result[bytes, str]:`
- **Import**: `import * from "std/compress/compress_mod"` (or barrel `import * from "std/compress/compress_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes` | **Returns**: `Result[bytes, str]`
- **Unit Test**: `tests/functions/compress/compress_mod_test.aipl` | **Example**: `examples/ex_084_compress_lz4_highspeed_cli.aipl`
- **Behavioral Summary**: Verify top-level compression facade `decompressZstd` across empty, single-byte, and multi-kilobyte payloads. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `zstdDecompress(data)`.

```aipl
module tests.functions.compress.compress_mod_z6_test
import * from "std/compress/compress_mod"
import { DeflateOptions, HuffmanTree, Lz77Token, buildHuffmanTree, lz77FindMatches, deflateCompress, deflateDecompress } from "std/compress/deflate"
import { GzipHeader, ZlibHeader, computeAdler32, computeCrc32, gzipCompress, gzipDecompress, zlibCompress, zlibDecompress } from "std/compress/gzip"
import { Lz4BlockHeader, Lz4FrameHeader, lz4CompressBlock, lz4DecompressBlock, lz4CompressFrame, lz4DecompressFrame } from "std/compress/lz4"
import { ZstdFrameHeader, ZstdBlockHeader, zstdCompress, zstdDecompress } from "std/compress/zstd"
import { TarEntry, TarArchive, tarPack, tarUnpack } from "std/compress/tar_archive"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_compress_mod_decompressZstd_6(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let resNom = decompressZstd(arg_data)
  let resEdge = decompressZstd(edge_data)
  assert(resNom.isOk() == false, "decompressZstd nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "decompressZstd boundary resEdge.isOk() == false")
  ret 0
```

---

### `buildHuffmanTree` (`std/compress/deflate.aipl`)

- **Signature**: `pub fn buildHuffmanTree(symbolFreqs: [int]): HuffmanTree:`
- **Import**: `import * from "std/compress/deflate"` (or barrel `import * from "std/compress/compress_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `symbolFreqs: [int]` | **Returns**: `HuffmanTree`
- **Unit Test**: `tests/functions/compress/deflate_test.aipl` | **Example**: `examples/ex_082_compress_deflate_huffman_cli.aipl`
- **Behavioral Summary**: Verify `buildHuffmanTree` RFC 1951 LZ77 sliding-window match finder, canonical Huffman tree builder, and lossless `deflateDecompress(deflateCompress(data)) == data` round-trip. Concrete nominal inputs: `symbolFreqs: [int] = [1]`; exercises core body path returning/computing `HuffmanTree(codeLens = codeLens, codes = codes, maxLen = maxLen)`.

```aipl
module tests.functions.compress.deflate_z1_test
import * from "std/compress/deflate"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deflate_buildHuffmanTree_1(): int:
  let arg_symbolFreqs = [4]
  let edge_symbolFreqs = []
  let resNom = buildHuffmanTree(arg_symbolFreqs)
  let resEdge = buildHuffmanTree(edge_symbolFreqs)
  assertEqInt(resNom.codeLens.len(), 1, "buildHuffmanTree nominal resNom.codeLens.len() == 1")
  assertEqInt(resEdge.codeLens.len(), 0, "buildHuffmanTree boundary resEdge.codeLens.len() == 0")
  ret 0
```

---

### `lz77FindMatches` (`std/compress/deflate.aipl`)

- **Signature**: `pub fn lz77FindMatches(data: bytes, windowSize: int = 32768, minMatchLen: int = 3): [Lz77Token]:`
- **Import**: `import * from "std/compress/deflate"` (or barrel `import * from "std/compress/compress_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes, windowSize: int = 32768, minMatchLen: int = 3` | **Returns**: `[Lz77Token]`
- **Unit Test**: `tests/functions/compress/deflate_test.aipl` | **Example**: `examples/ex_083_compress_gzip_crc32_tool_cli.aipl`
- **Behavioral Summary**: Verify `lz77FindMatches` RFC 1951 LZ77 sliding-window match finder, canonical Huffman tree builder, and lossless `deflateDecompress(deflateCompress(data)) == data` round-trip. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`, `windowSize: int = 64`, `minMatchLen: int = 64`; exercises core body path returning/computing `tokens`.

```aipl
module tests.functions.compress.deflate_z2_test
import * from "std/compress/deflate"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deflate_lz77FindMatches_2(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let arg_windowSize = 4
  let edge_windowSize = 1
  let arg_minMatchLen = 4
  let edge_minMatchLen = 1
  let resNom = lz77FindMatches(arg_data, arg_windowSize, arg_minMatchLen)
  let resEdge = lz77FindMatches(edge_data, edge_windowSize, edge_minMatchLen)
  assertEqInt(resNom.len(), 4, "lz77FindMatches nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 1, "lz77FindMatches boundary resEdge.len() == 1")
  ret 0
```

---

### `deflateCompress` (`std/compress/deflate.aipl`)

- **Signature**: `pub fn deflateCompress(data: bytes, opts: DeflateOptions): bytes:`
- **Import**: `import * from "std/compress/deflate"` (or barrel `import * from "std/compress/compress_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes, opts: DeflateOptions` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/compress/deflate_test.aipl` | **Example**: `examples/ex_084_compress_lz4_highspeed_cli.aipl`
- **Behavioral Summary**: Verify `deflateCompress` RFC 1951 LZ77 sliding-window match finder, canonical Huffman tree builder, and lossless `deflateDecompress(deflateCompress(data)) == data` round-trip. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`, `opts: DeflateOptions = DeflateOptions(level = int = 6(), windowBits = int = 15(), memLevel = int = 8())`; exercises core body path returning/computing `bytesFromArray(out)`.

```aipl
module tests.functions.compress.deflate_z3_test
import * from "std/compress/deflate"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deflate_deflateCompress_3(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let arg_opts = DeflateOptions(level = 0, windowBits = 4, memLevel = 4)
  let edge_opts = DeflateOptions(level = 0, windowBits = 1, memLevel = 1)
  let resNom = deflateCompress(arg_data, arg_opts)
  let resEdge = deflateCompress(edge_data, edge_opts)
  assertEqInt(resNom.len(), 9, "deflateCompress nominal resNom.len() == 9")
  assertEqInt(resEdge.len(), 6, "deflateCompress boundary resEdge.len() == 6")
  ret 0
```

---

### `deflateDecompress` (`std/compress/deflate.aipl`)

- **Signature**: `pub fn deflateDecompress(data: bytes): Result[bytes, str]:`
- **Import**: `import * from "std/compress/deflate"` (or barrel `import * from "std/compress/compress_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes` | **Returns**: `Result[bytes, str]`
- **Unit Test**: `tests/functions/compress/deflate_test.aipl` | **Example**: `examples/ex_082_compress_deflate_huffman_cli.aipl`
- **Behavioral Summary**: Verify `deflateDecompress` RFC 1951 LZ77 sliding-window match finder, canonical Huffman tree builder, and lossless `deflateDecompress(deflateCompress(data)) == data` round-trip. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `Err("deflateDecompress: unsupported block type " + toString(btype))`.

```aipl
module tests.functions.compress.deflate_z4_test
import * from "std/compress/deflate"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deflate_deflateDecompress_4(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let resNom = deflateDecompress(arg_data)
  let resEdge = deflateDecompress(edge_data)
  assert(resNom.isOk() == false, "deflateDecompress nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "deflateDecompress boundary resEdge.isOk() == false")
  ret 0
```

---

### `computeAdler32` (`std/compress/gzip.aipl`)

- **Signature**: `pub fn computeAdler32(data: bytes): int:`
- **Import**: `import * from "std/compress/gzip"` (or barrel `import * from "std/compress/compress_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes` | **Returns**: `int`
- **Unit Test**: `tests/functions/compress/gzip_test.aipl` | **Example**: `examples/ex_083_compress_gzip_crc32_tool_cli.aipl`
- **Behavioral Summary**: Verify `computeAdler32` RFC 1952 GZIP (`0x1F 0x8B` + CRC-32 trailer) and RFC 1950 ZLIB (+ Adler-32 trailer) framing, compression round-trip, and corrupt-byte rejection. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `((b << 16) | a) & 4294967295`.

```aipl
module tests.functions.compress.gzip_z1_test
import * from "std/compress/gzip"
import { DeflateOptions, deflateCompress, deflateDecompress } from "std/compress/deflate"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gzip_computeAdler32_1(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let resNom = computeAdler32(arg_data)
  let resEdge = computeAdler32(edge_data)
  assertEqInt(resNom, 47120679, "computeAdler32 nominal resNom == 47120679")
  assertEqInt(resEdge, 4325442, "computeAdler32 boundary resEdge == 4325442")
  ret 0
```

---

### `computeCrc32` (`std/compress/gzip.aipl`)

- **Signature**: `pub fn computeCrc32(data: bytes): int:`
- **Import**: `import * from "std/compress/gzip"` (or barrel `import * from "std/compress/compress_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes` | **Returns**: `int`
- **Unit Test**: `tests/functions/compress/gzip_test.aipl` | **Example**: `examples/ex_084_compress_lz4_highspeed_cli.aipl`
- **Behavioral Summary**: Verify `computeCrc32` RFC 1952 GZIP (`0x1F 0x8B` + CRC-32 trailer) and RFC 1950 ZLIB (+ Adler-32 trailer) framing, compression round-trip, and corrupt-byte rejection. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `(crc ^ 4294967295) & 4294967295`.

```aipl
module tests.functions.compress.gzip_z2_test
import * from "std/compress/gzip"
import { DeflateOptions, deflateCompress, deflateDecompress } from "std/compress/deflate"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gzip_computeCrc32_2(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let resNom = computeCrc32(arg_data)
  let resEdge = computeCrc32(edge_data)
  assertEqInt(resNom, 3094742756, "computeCrc32 nominal resNom == 3094742756")
  assertEqInt(resEdge, 3554254475, "computeCrc32 boundary resEdge == 3554254475")
  ret 0
```

---

### `gzipCompress` (`std/compress/gzip.aipl`)

- **Signature**: `pub fn gzipCompress(data: bytes, filename: str = "", mtime: int = 0): bytes:`
- **Import**: `import * from "std/compress/gzip"` (or barrel `import * from "std/compress/compress_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes, filename: str = "", mtime: int = 0` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/compress/gzip_test.aipl` | **Example**: `examples/ex_082_compress_deflate_huffman_cli.aipl`
- **Behavioral Summary**: Verify `gzipCompress` RFC 1952 GZIP (`0x1F 0x8B` + CRC-32 trailer) and RFC 1950 ZLIB (+ Adler-32 trailer) framing, compression round-trip, and corrupt-byte rejection. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`, `filename: str = "/tmp/aipl_test_artifact.tmp"`, `mtime: int = 1`; exercises core body path returning/computing `bytesFromArray(out)`.

```aipl
module tests.functions.compress.gzip_z3_test
import * from "std/compress/gzip"
import { DeflateOptions, deflateCompress, deflateDecompress } from "std/compress/deflate"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gzip_gzipCompress_3(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let arg_filename = "127.0.0.1"
  let edge_filename = "127.0.0.1"
  let arg_mtime = 4
  let edge_mtime = 1
  let resNom = gzipCompress(arg_data, arg_filename, arg_mtime)
  let resEdge = gzipCompress(edge_data, edge_filename, edge_mtime)
  assertEqInt(resNom.len(), 33, "gzipCompress nominal resNom.len() == 33")
  assertEqInt(resEdge.len(), 30, "gzipCompress boundary resEdge.len() == 30")
  ret 0
```

---

### `gzipDecompress` (`std/compress/gzip.aipl`)

- **Signature**: `pub fn gzipDecompress(data: bytes): Result[bytes, str]:`
- **Import**: `import * from "std/compress/gzip"` (or barrel `import * from "std/compress/compress_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes` | **Returns**: `Result[bytes, str]`
- **Unit Test**: `tests/functions/compress/gzip_test.aipl` | **Example**: `examples/ex_083_compress_gzip_crc32_tool_cli.aipl`
- **Behavioral Summary**: Verify `gzipDecompress` RFC 1952 GZIP (`0x1F 0x8B` + CRC-32 trailer) and RFC 1950 ZLIB (+ Adler-32 trailer) framing, compression round-trip, and corrupt-byte rejection. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `Ok(raw)`.

```aipl
module tests.functions.compress.gzip_z4_test
import * from "std/compress/gzip"
import { DeflateOptions, deflateCompress, deflateDecompress } from "std/compress/deflate"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gzip_gzipDecompress_4(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let resNom = gzipDecompress(arg_data)
  let resEdge = gzipDecompress(edge_data)
  assert(resNom.isOk() == false, "gzipDecompress nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "gzipDecompress boundary resEdge.isOk() == false")
  ret 0
```

---

### `zlibCompress` (`std/compress/gzip.aipl`)

- **Signature**: `pub fn zlibCompress(data: bytes, level: int = 6): bytes:`
- **Import**: `import * from "std/compress/gzip"` (or barrel `import * from "std/compress/compress_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes, level: int = 6` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/compress/gzip_test.aipl` | **Example**: `examples/ex_084_compress_lz4_highspeed_cli.aipl`
- **Behavioral Summary**: Verify `zlibCompress` RFC 1952 GZIP (`0x1F 0x8B` + CRC-32 trailer) and RFC 1950 ZLIB (+ Adler-32 trailer) framing, compression round-trip, and corrupt-byte rejection. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`, `level: int = 1`; exercises core body path returning/computing `bytesFromArray(out)`.

```aipl
module tests.functions.compress.gzip_z5_test
import * from "std/compress/gzip"
import { DeflateOptions, deflateCompress, deflateDecompress } from "std/compress/deflate"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gzip_zlibCompress_5(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let arg_level = 2
  let edge_level = 0
  let resNom = zlibCompress(arg_data, arg_level)
  let resEdge = zlibCompress(edge_data, edge_level)
  assertEqInt(resNom.len(), 11, "zlibCompress nominal resNom.len() == 11")
  assertEqInt(resEdge.len(), 12, "zlibCompress boundary resEdge.len() == 12")
  ret 0
```

---

### `zlibDecompress` (`std/compress/gzip.aipl`)

- **Signature**: `pub fn zlibDecompress(data: bytes): Result[bytes, str]:`
- **Import**: `import * from "std/compress/gzip"` (or barrel `import * from "std/compress/compress_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes` | **Returns**: `Result[bytes, str]`
- **Unit Test**: `tests/functions/compress/gzip_test.aipl` | **Example**: `examples/ex_082_compress_deflate_huffman_cli.aipl`
- **Behavioral Summary**: Verify `zlibDecompress` RFC 1952 GZIP (`0x1F 0x8B` + CRC-32 trailer) and RFC 1950 ZLIB (+ Adler-32 trailer) framing, compression round-trip, and corrupt-byte rejection. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `Ok(raw)`.

```aipl
module tests.functions.compress.gzip_z6_test
import * from "std/compress/gzip"
import { DeflateOptions, deflateCompress, deflateDecompress } from "std/compress/deflate"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gzip_zlibDecompress_6(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let resNom = zlibDecompress(arg_data)
  let resEdge = zlibDecompress(edge_data)
  assert(resNom.isOk() == false, "zlibDecompress nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "zlibDecompress boundary resEdge.isOk() == false")
  ret 0
```

---

### `lz4CompressBlock` (`std/compress/lz4.aipl`)

- **Signature**: `pub fn lz4CompressBlock(src: bytes): bytes:`
- **Import**: `import * from "std/compress/lz4"` (or barrel `import * from "std/compress/compress_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `src: bytes` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/compress/lz4_test.aipl` | **Example**: `examples/ex_083_compress_gzip_crc32_tool_cli.aipl`
- **Behavioral Summary**: Verify `lz4CompressBlock` high-speed LZ4 literal/match block and `0x184D2204` frame compression and exact byte-for-byte decompression. Concrete nominal inputs: `src: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `bytesFromArray(out)`.

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

---

### `lz4DecompressBlock` (`std/compress/lz4.aipl`)

- **Signature**: `pub fn lz4DecompressBlock(src: bytes, uncompressedSize: int): Result[bytes, str]:`
- **Import**: `import * from "std/compress/lz4"` (or barrel `import * from "std/compress/compress_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `src: bytes, uncompressedSize: int` | **Returns**: `Result[bytes, str]`
- **Unit Test**: `tests/functions/compress/lz4_test.aipl` | **Example**: `examples/ex_084_compress_lz4_highspeed_cli.aipl`
- **Behavioral Summary**: Verify `lz4DecompressBlock` high-speed LZ4 literal/match block and `0x184D2204` frame compression and exact byte-for-byte decompression. Concrete nominal inputs: `src: bytes = [65, 73, 80, 76]`, `uncompressedSize: int = 64`; exercises core body path returning/computing `Ok(bytesFromArray(out))`.

```aipl
module tests.functions.compress.lz4_z2_test
import * from "std/compress/lz4"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_lz4_lz4DecompressBlock_2(): int:
  let arg_src = [65, 73, 80, 76]
  let edge_src = [65]
  let arg_uncompressedSize = 4
  let edge_uncompressedSize = 1
  let resNom = lz4DecompressBlock(arg_src, arg_uncompressedSize)
  let resEdge = lz4DecompressBlock(edge_src, edge_uncompressedSize)
  assert(resNom.isOk() == false, "lz4DecompressBlock nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "lz4DecompressBlock boundary resEdge.isOk() == false")
  ret 0
```

---

### `lz4CompressFrame` (`std/compress/lz4.aipl`)

- **Signature**: `pub fn lz4CompressFrame(src: bytes): bytes:`
- **Import**: `import * from "std/compress/lz4"` (or barrel `import * from "std/compress/compress_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `src: bytes` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/compress/lz4_test.aipl` | **Example**: `examples/ex_082_compress_deflate_huffman_cli.aipl`
- **Behavioral Summary**: Verify `lz4CompressFrame` high-speed LZ4 literal/match block and `0x184D2204` frame compression and exact byte-for-byte decompression. Concrete nominal inputs: `src: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `bytesFromArray(out)`.

```aipl
module tests.functions.compress.lz4_z3_test
import * from "std/compress/lz4"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_lz4_lz4CompressFrame_3(): int:
  let arg_src = [65, 73, 80, 76]
  let edge_src = [65]
  let resNom = lz4CompressFrame(arg_src)
  let resEdge = lz4CompressFrame(edge_src)
  assertEqInt(resNom.len(), 24, "lz4CompressFrame nominal resNom.len() == 24")
  assertEqInt(resEdge.len(), 21, "lz4CompressFrame boundary resEdge.len() == 21")
  ret 0
```

---

### `lz4DecompressFrame` (`std/compress/lz4.aipl`)

- **Signature**: `pub fn lz4DecompressFrame(src: bytes): Result[bytes, str]:`
- **Import**: `import * from "std/compress/lz4"` (or barrel `import * from "std/compress/compress_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `src: bytes` | **Returns**: `Result[bytes, str]`
- **Unit Test**: `tests/functions/compress/lz4_test.aipl` | **Example**: `examples/ex_083_compress_gzip_crc32_tool_cli.aipl`
- **Behavioral Summary**: Verify `lz4DecompressFrame` high-speed LZ4 literal/match block and `0x184D2204` frame compression and exact byte-for-byte decompression. Concrete nominal inputs: `src: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `lz4DecompressBlock(blkSlice, rawLen)`.

```aipl
module tests.functions.compress.lz4_z4_test
import * from "std/compress/lz4"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_lz4_lz4DecompressFrame_4(): int:
  let arg_src = [65, 73, 80, 76]
  let edge_src = [65]
  let resNom = lz4DecompressFrame(arg_src)
  let resEdge = lz4DecompressFrame(edge_src)
  assert(resNom.isOk() == false, "lz4DecompressFrame nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "lz4DecompressFrame boundary resEdge.isOk() == false")
  ret 0
```

---

### `writeOctalField` (`std/compress/tar_archive.aipl`)

- **Signature**: `fn writeOctalField(mut blk: [int], offset: int, width: int, val: int): [int]:`
- **Import**: `import * from "std/compress/tar_archive"` (or barrel `import * from "std/compress/compress_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut blk: [int], offset: int, width: int, val: int` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/compress/tar_archive_test.aipl` | **Example**: `examples/ex_084_compress_lz4_highspeed_cli.aipl`
- **Behavioral Summary**: Verify `writeOctalField` (`free fn`) POSIX UStar 512-byte header octal checksums, multi-file/directory archiving, and exact `tarUnpack` extraction. Concrete nominal inputs: `blk: [int] = [1]`, `offset: int = 0`, `width: int = 128`, `val: int = 1`; exercises core body path returning/computing `blk`.

```aipl
module tests.functions.compress.tar_archive_z1_test
import * from "std/compress/tar_archive"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tar_archive_writeOctalField_1(): int:
  let arg_blk = [4]
  let edge_blk = []
  let arg_offset = 1
  let edge_offset = 0
  let arg_width = 4
  let edge_width = 1
  let arg_val = 2
  let edge_val = 0
  let resNom = writeOctalField(arg_blk, arg_offset, arg_width, arg_val)
  let resEdge = writeOctalField(edge_blk, edge_offset, edge_width, edge_val)
  assertEqInt(resNom.len(), 1, "writeOctalField nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "writeOctalField boundary resEdge.len() == 0")
  ret 0
```

---

### `parseOctalField` (`std/compress/tar_archive.aipl`)

- **Signature**: `fn parseOctalField(data: bytes, offset: int, width: int): int:`
- **Import**: `import * from "std/compress/tar_archive"` (or barrel `import * from "std/compress/compress_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes, offset: int, width: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/compress/tar_archive_test.aipl` | **Example**: `examples/ex_082_compress_deflate_huffman_cli.aipl`
- **Behavioral Summary**: Verify `parseOctalField` (`free fn`) POSIX UStar 512-byte header octal checksums, multi-file/directory archiving, and exact `tarUnpack` extraction. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`, `offset: int = 0`, `width: int = 128`; exercises core body path returning/computing `acc`.

```aipl
module tests.functions.compress.tar_archive_z2_test
import * from "std/compress/tar_archive"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tar_archive_parseOctalField_2(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let arg_offset = 1
  let edge_offset = 0
  let arg_width = 4
  let edge_width = 1
  let resNom = parseOctalField(arg_data, arg_offset, arg_width)
  let resEdge = parseOctalField(edge_data, edge_offset, edge_width)
  assertEqInt(resNom, 0, "parseOctalField nominal resNom == 0")
  assertEqInt(resEdge, 0, "parseOctalField boundary resEdge == 0")
  ret 0
```

---

### `readNullTermStr` (`std/compress/tar_archive.aipl`)

- **Signature**: `fn readNullTermStr(data: bytes, offset: int, maxLen: int): str:`
- **Import**: `import * from "std/compress/tar_archive"` (or barrel `import * from "std/compress/compress_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes, offset: int, maxLen: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/compress/tar_archive_test.aipl` | **Example**: `examples/ex_083_compress_gzip_crc32_tool_cli.aipl`
- **Behavioral Summary**: Verify `readNullTermStr` (`free fn`) POSIX UStar 512-byte header octal checksums, multi-file/directory archiving, and exact `tarUnpack` extraction. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`, `offset: int = 0`, `maxLen: int = 64`; exercises core body path returning/computing `bytesFromArray(chars).toStringLossy()`.

```aipl
module tests.functions.compress.tar_archive_z3_test
import * from "std/compress/tar_archive"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tar_archive_readNullTermStr_3(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let arg_offset = 1
  let edge_offset = 0
  let arg_maxLen = 4
  let edge_maxLen = 1
  let resNom = readNullTermStr(arg_data, arg_offset, arg_maxLen)
  let resEdge = readNullTermStr(edge_data, edge_offset, edge_maxLen)
  assertEqStr(resNom, "IPL", "readNullTermStr nominal string matches")
  assertEqStr(resEdge, "A", "readNullTermStr boundary string matches")
  ret 0
```

---

### `tarPack` (`std/compress/tar_archive.aipl`)

- **Signature**: `pub fn tarPack(entries: [TarEntry]): bytes:`
- **Import**: `import * from "std/compress/tar_archive"` (or barrel `import * from "std/compress/compress_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `entries: [TarEntry]` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/compress/tar_archive_test.aipl` | **Example**: `examples/ex_084_compress_lz4_highspeed_cli.aipl`
- **Behavioral Summary**: Verify `tarPack` (`free fn`) POSIX UStar 512-byte header octal checksums, multi-file/directory archiving, and exact `tarUnpack` extraction. Concrete nominal inputs: `entries: [TarEntry] = [TarEntry(path = "/tmp/aipl_test_artifact.tmp", mode = 1, size = 64, mtime = 1, isDir = true, data = [65, 73, 80, 76])]`; exercises core body path returning/computing `bytesFromArray(out)`.

```aipl
module tests.functions.compress.tar_archive_z4_test
import * from "std/compress/tar_archive"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tar_archive_tarPack_4(): int:
  let arg_entries = [TarEntry(path = "/tmp/aipl_test_path", mode = 4, size = 0, mtime = 4, isDir = true, data = [65, 73, 80, 76])]
  let edge_entries = []
  let resNom = tarPack(arg_entries)
  let resEdge = tarPack(edge_entries)
  assertEqInt(resNom.len(), 1536, "tarPack nominal resNom.len() == 1536")
  assertEqInt(resEdge.len(), 1024, "tarPack boundary resEdge.len() == 1024")
  ret 0
```

---

### `tarUnpack` (`std/compress/tar_archive.aipl`)

- **Signature**: `pub fn tarUnpack(archiveBytes: bytes): Result[[TarEntry], str]:`
- **Import**: `import * from "std/compress/tar_archive"` (or barrel `import * from "std/compress/compress_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `archiveBytes: bytes` | **Returns**: `Result[[TarEntry], str]`
- **Unit Test**: `tests/functions/compress/tar_archive_test.aipl` | **Example**: `examples/ex_082_compress_deflate_huffman_cli.aipl`
- **Behavioral Summary**: Verify `tarUnpack` (`free fn`) POSIX UStar 512-byte header octal checksums, multi-file/directory archiving, and exact `tarUnpack` extraction. Concrete nominal inputs: `archiveBytes: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `Ok(entries)`.

```aipl
module tests.functions.compress.tar_archive_z5_test
import * from "std/compress/tar_archive"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tar_archive_tarUnpack_5(): int:
  let arg_archiveBytes = [65, 73, 80, 76]
  let edge_archiveBytes = [65]
  let resNom = tarUnpack(arg_archiveBytes)
  let resEdge = tarUnpack(edge_archiveBytes)
  assert(resNom.isOk() == false, "tarUnpack nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "tarUnpack boundary resEdge.isOk() == false")
  ret 0
```

---

### `getEntry` (`std/compress/tar_archive.aipl`)

- **Signature**: `pub fn (self: TarArchive) getEntry(path: str): Option[TarEntry]:`
- **Import**: `import * from "std/compress/tar_archive"` (or barrel `import * from "std/compress/compress_mod"`)
- **Receiver**: `self: TarArchive` | **Parameters**: `path: str` | **Returns**: `Option[TarEntry]`
- **Unit Test**: `tests/functions/compress/tar_archive_test.aipl` | **Example**: `examples/ex_083_compress_gzip_crc32_tool_cli.aipl`
- **Behavioral Summary**: Verify `getEntry` (`self: TarArchive`) POSIX UStar 512-byte header octal checksums, multi-file/directory archiving, and exact `tarUnpack` extraction. Concrete nominal inputs: receiver `recvObj: TarArchive = TarArchive()`, `path: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.compress.tar_archive_z6_test
import * from "std/compress/tar_archive"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tar_archive_TarArchive_getEntry_6(): int:
  let recv_self = TarArchive(entries = [])
  let edge_self = TarArchive(entries = [])
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let resNom = recv_self.getEntry(arg_path)
  let resEdge = edge_self.getEntry(edge_path)
  assert(resNom.isSome() == false, "getEntry nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "getEntry boundary resEdge.isSome() == false")
  ret 0
```

---

### `addFile` (`std/compress/tar_archive.aipl`)

- **Signature**: `pub fn (mut self: TarArchive) addFile(path: str, data: bytes, mode: int = 420): void:`
- **Import**: `import * from "std/compress/tar_archive"` (or barrel `import * from "std/compress/compress_mod"`)
- **Receiver**: `mut self: TarArchive` | **Parameters**: `path: str, data: bytes, mode: int = 420` | **Returns**: `void`
- **Unit Test**: `tests/functions/compress/tar_archive_test.aipl` | **Example**: `examples/ex_084_compress_lz4_highspeed_cli.aipl`
- **Behavioral Summary**: Verify `addFile` (`mut self: TarArchive`) POSIX UStar 512-byte header octal checksums, multi-file/directory archiving, and exact `tarUnpack` extraction. Concrete nominal inputs: receiver `recvObj: TarArchive = TarArchive()`, `path: str = "/tmp/aipl_test_artifact.tmp"`, `data: bytes = [65, 73, 80, 76]`, `mode: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.compress.tar_archive_z7_test
import * from "std/compress/tar_archive"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tar_archive_TarArchive_addFile_7(): int:
  let mut recv_self = TarArchive(entries = [])
  let mut edge_self = TarArchive(entries = [])
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let arg_mode = 4
  let edge_mode = 1
  recv_self.addFile(arg_path, arg_data, arg_mode)
  edge_self.addFile(edge_path, edge_data, edge_mode)
  assertEqInt(recv_self.entries.len(), 1, "addFile nominal recv_self.entries.len() == 1")
  assertEqInt(edge_self.entries.len(), 1, "addFile boundary edge_self.entries.len() == 1")
  ret 0
```

---

### `addDirectory` (`std/compress/tar_archive.aipl`)

- **Signature**: `pub fn (mut self: TarArchive) addDirectory(path: str, mode: int = 493): void:`
- **Import**: `import * from "std/compress/tar_archive"` (or barrel `import * from "std/compress/compress_mod"`)
- **Receiver**: `mut self: TarArchive` | **Parameters**: `path: str, mode: int = 493` | **Returns**: `void`
- **Unit Test**: `tests/functions/compress/tar_archive_test.aipl` | **Example**: `examples/ex_082_compress_deflate_huffman_cli.aipl`
- **Behavioral Summary**: Verify `addDirectory` (`mut self: TarArchive`) POSIX UStar 512-byte header octal checksums, multi-file/directory archiving, and exact `tarUnpack` extraction. Concrete nominal inputs: receiver `recvObj: TarArchive = TarArchive()`, `path: str = "/tmp/aipl_test_artifact.tmp"`, `mode: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.compress.tar_archive_z8_test
import * from "std/compress/tar_archive"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tar_archive_TarArchive_addDirectory_8(): int:
  let mut recv_self = TarArchive(entries = [])
  let mut edge_self = TarArchive(entries = [])
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let arg_mode = 4
  let edge_mode = 1
  recv_self.addDirectory(arg_path, arg_mode)
  edge_self.addDirectory(edge_path, edge_mode)
  assertEqInt(recv_self.entries.len(), 1, "addDirectory nominal recv_self.entries.len() == 1")
  assertEqInt(edge_self.entries.len(), 1, "addDirectory boundary edge_self.entries.len() == 1")
  ret 0
```

---

### `toBytes` (`std/compress/tar_archive.aipl`)

- **Signature**: `pub fn (self: TarArchive) toBytes(): bytes:`
- **Import**: `import * from "std/compress/tar_archive"` (or barrel `import * from "std/compress/compress_mod"`)
- **Receiver**: `self: TarArchive` | **Parameters**: `none` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/compress/tar_archive_test.aipl` | **Example**: `examples/ex_083_compress_gzip_crc32_tool_cli.aipl`
- **Behavioral Summary**: Verify `toBytes` (`self: TarArchive`) POSIX UStar 512-byte header octal checksums, multi-file/directory archiving, and exact `tarUnpack` extraction. Concrete nominal inputs: receiver `recvObj: TarArchive = TarArchive()`; exercises core body path returning/computing `tarPack(self.entries)`.

```aipl
module tests.functions.compress.tar_archive_z9_test
import * from "std/compress/tar_archive"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tar_archive_TarArchive_toBytes_9(): int:
  let recv_self = TarArchive(entries = [])
  let edge_self = TarArchive(entries = [])
  let resNom = recv_self.toBytes()
  let resEdge = edge_self.toBytes()
  assertEqInt(resNom.len(), 1024, "toBytes nominal resNom.len() == 1024")
  assertEqInt(resEdge.len(), 1024, "toBytes boundary resEdge.len() == 1024")
  ret 0
```

---

### `zstdCompress` (`std/compress/zstd.aipl`)

- **Signature**: `pub fn zstdCompress(data: bytes, level: int = 3): bytes:`
- **Import**: `import * from "std/compress/zstd"` (or barrel `import * from "std/compress/compress_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes, level: int = 3` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/compress/zstd_test.aipl` | **Example**: `examples/ex_084_compress_lz4_highspeed_cli.aipl`
- **Behavioral Summary**: Verify `zstdCompress` Zstandard `0xFD2FB528` frame compression and exact decompression round-trip. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`, `level: int = 1`; exercises core body path returning/computing `bytesFromArray(out)`.

```aipl
module tests.functions.compress.zstd_z1_test
import * from "std/compress/zstd"
import { DeflateOptions, deflateCompress, deflateDecompress } from "std/compress/deflate"
import { computeCrc32 } from "std/compress/gzip"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_zstd_zstdCompress_1(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let arg_level = 2
  let edge_level = 0
  let resNom = zstdCompress(arg_data, arg_level)
  let resEdge = zstdCompress(edge_data, edge_level)
  assertEqInt(resNom.len(), 21, "zstdCompress nominal resNom.len() == 21")
  assertEqInt(resEdge.len(), 18, "zstdCompress boundary resEdge.len() == 18")
  ret 0
```

---

### `zstdDecompress` (`std/compress/zstd.aipl`)

- **Signature**: `pub fn zstdDecompress(data: bytes): Result[bytes, str]:`
- **Import**: `import * from "std/compress/zstd"` (or barrel `import * from "std/compress/compress_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes` | **Returns**: `Result[bytes, str]`
- **Unit Test**: `tests/functions/compress/zstd_test.aipl` | **Example**: `examples/ex_082_compress_deflate_huffman_cli.aipl`
- **Behavioral Summary**: Verify `zstdDecompress` Zstandard `0xFD2FB528` frame compression and exact decompression round-trip. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `Ok(raw)`.

```aipl
module tests.functions.compress.zstd_z2_test
import * from "std/compress/zstd"
import { DeflateOptions, deflateCompress, deflateDecompress } from "std/compress/deflate"
import { computeCrc32 } from "std/compress/gzip"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_zstd_zstdDecompress_2(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let resNom = zstdDecompress(arg_data)
  let resEdge = zstdDecompress(edge_data)
  assert(resNom.isOk() == false, "zstdDecompress nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "zstdDecompress boundary resEdge.isOk() == false")
  ret 0
```

---

### `createApkArchiveBuilder` (`std/compress/apk_zip_writer.aipl`)

- **Signature**: `pub fn createApkArchiveBuilder(templateSizeBytes: int): ApkArchiveBuilder requires templateSizeBytes >= 0 ensures result.dosTimestamp == 0 and result.entryCount == 0:`
- **Import**: `import { createApkArchiveBuilder } from "std/compress/apk_zip_writer"`
- **Receiver**: `None (free function)` | **Parameters**: `templateSizeBytes: int` | **Returns**: `ApkArchiveBuilder`
- **Unit Test**: `tests/functions/compress/apk_zip_writer_test.aipl` | **Example**: `examples/ex_081_compress_gzip_streaming_cli.aipl`
- **Behavioral Summary**: Constructs an `ApkArchiveBuilder` initialized at the base template file size with zero entries and deterministic DOS timestamp (0).

```aipl
module tests.functions.compress.apk_zip_ref_01_test
import { createApkArchiveBuilder } from "std/compress/apk_zip_writer"
import { assertEqInt } from "std/prelude"
pub fn test_createApkArchiveBuilder_ref(): int:
  let b = createApkArchiveBuilder(4096)
  assertEqInt(b.currentOffset, 4096, "currentOffset initialized to template size")
  assertEqInt(b.entryCount, 0, "entry count is zero")
  assertEqInt(b.dosTimestamp, 0, "deterministic timestamp is zero")
  ret 0
```

---

### `apkAlignUncompressed4Byte` (`std/compress/apk_zip_writer.aipl`)

- **Signature**: `pub fn apkAlignUncompressed4Byte(localHeaderEndOffset: int, fileName: str): (int, int) requires localHeaderEndOffset >= 0 ensures result[0] >= 0 and result[1] >= localHeaderEndOffset:`
- **Import**: `import { apkAlignUncompressed4Byte } from "std/compress/apk_zip_writer"`
- **Receiver**: `None (free function)` | **Parameters**: `localHeaderEndOffset: int, fileName: str` | **Returns**: `(int, int)`
- **Unit Test**: `tests/functions/compress/apk_zip_writer_test.aipl` | **Example**: `examples/ex_081_compress_gzip_streaming_cli.aipl`
- **Behavioral Summary**: Calculates padding bytes and aligned data start offset for ZIP entries: 4096-byte page alignment for `.so` shared libraries (direct kernel `mmap`) and 4-byte alignment for uncompressed assets.

```aipl
module tests.functions.compress.apk_zip_ref_02_test
import { apkAlignUncompressed4Byte } from "std/compress/apk_zip_writer"
import { assertEqInt } from "std/prelude"
pub fn test_apkAlignUncompressed4Byte_ref(): int:
  let (padAsset, startAsset) = apkAlignUncompressed4Byte(33, "assets/main.aiplb")
  assertEqInt(padAsset, 3, "padding to 4-byte boundary")
  assertEqInt(startAsset % 4, 0, "aligned to 4-byte boundary")
  let (padSo, startSo) = apkAlignUncompressed4Byte(100, "lib/arm64-v8a/libaipl_runner.so")
  assertEqInt(startSo % 4096, 0, "aligned to 4096-byte page boundary")
  ret 0
```

---

### `apkInjectAssetEntry` (`std/compress/apk_zip_writer.aipl`)

- **Signature**: `pub fn apkInjectAssetEntry(currentOffset: int, entryName: str, payload: str): (int, int, int) requires currentOffset >= 0 ensures result[0] >= currentOffset and result[1] >= result[0]:`
- **Import**: `import { apkInjectAssetEntry } from "std/compress/apk_zip_writer"`
- **Receiver**: `None (free function)` | **Parameters**: `currentOffset: int, entryName: str, payload: str` | **Returns**: `(int, int, int)`
- **Unit Test**: `tests/functions/compress/apk_zip_writer_test.aipl` | **Example**: `examples/ex_081_compress_gzip_streaming_cli.aipl`
- **Behavioral Summary**: Computes aligned payload start offset, next entry offset, and CRC32 checksum for a newly injected uncompressed asset entry in the APK archive.

```aipl
module tests.functions.compress.apk_zip_ref_03_test
import { apkInjectAssetEntry } from "std/compress/apk_zip_writer"
import { assertEqInt } from "std/prelude"
pub fn test_apkInjectAssetEntry_ref(): int:
  let (dataStart, nextOff, crc) = apkInjectAssetEntry(1000, "assets/app.json", "{\"status\":\"ok\"}")
  assertEqInt(dataStart % 4, 0, "data start is 4-byte aligned")
  assertEqInt(nextOff, dataStart + 15, "next offset advances by payload length")
  ret 0
```

---

### `finalizeApkCentralDirectory` (`std/compress/apk_zip_writer.aipl`)

- **Signature**: `pub fn finalizeApkCentralDirectory(cdStartOffset: int, entryNames: [str]): (int, int, int) requires cdStartOffset >= 0 ensures result[0] >= 0 and result[1] >= cdStartOffset and result[2] >= result[1]:`
- **Import**: `import { finalizeApkCentralDirectory } from "std/compress/apk_zip_writer"`
- **Receiver**: `None (free function)` | **Parameters**: `cdStartOffset: int, entryNames: [str]` | **Returns**: `(int, int, int)`
- **Unit Test**: `tests/functions/compress/apk_zip_writer_test.aipl` | **Example**: `examples/ex_081_compress_gzip_streaming_cli.aipl`
- **Behavioral Summary**: Finalizes the ZIP Central Directory and End of Central Directory (EOCD) records, computing the total Central Directory byte size, EOCD offset, and final APK archive size.

```aipl
module tests.functions.compress.apk_zip_ref_04_test
import { finalizeApkCentralDirectory } from "std/compress/apk_zip_writer"
import { assertEqInt } from "std/prelude"
pub fn test_finalizeApkCentralDirectory_ref(): int:
  let entries: [str] = ["AndroidManifest.xml", "assets/main.aiplb"]
  let (cdSize, eocdOff, totalSize) = finalizeApkCentralDirectory(5000, entries)
  assertEqInt(eocdOff, 5000 + cdSize, "eocd offset immediately follows CD")
  assertEqInt(totalSize, eocdOff + 22, "total size includes 22-byte EOCD")
  ret 0
```
