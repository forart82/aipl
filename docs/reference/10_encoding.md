[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Domain 10: `encoding` API Reference

> Complete API reference manual for AIPL standard library domain `encoding` (269 callable functions & methods across ["std/encoding/base64.aipl", "std/encoding/bincode.aipl", "std/encoding/csv.aipl", "std/encoding/encoding_mod.aipl", "std/encoding/hex.aipl", "std/encoding/html_dom.aipl", "std/encoding/ini_dotenv.aipl", "std/encoding/json.aipl", "std/encoding/markdown.aipl", "std/encoding/qrcode_semver.aipl", "std/encoding/toml.aipl", "std/encoding/xml.aipl", "std/encoding/yaml.aipl", "std/encoding/axml_manifest.aipl"]).

## 1. Domain Overview & Source Modules

- **Domain Name**: `encoding`
- **Target Source Modules**: ["std/encoding/base64.aipl", "std/encoding/bincode.aipl", "std/encoding/csv.aipl", "std/encoding/encoding_mod.aipl", "std/encoding/hex.aipl", "std/encoding/html_dom.aipl", "std/encoding/ini_dotenv.aipl", "std/encoding/json.aipl", "std/encoding/markdown.aipl", "std/encoding/qrcode_semver.aipl", "std/encoding/toml.aipl", "std/encoding/xml.aipl", "std/encoding/yaml.aipl", "std/encoding/axml_manifest.aipl"]
- **Total Callable Functions & Methods**: 269
- **Total Data Types (`struct` & `enum`)**: 24
- **Master Reference Hub**: [STDLIB_REFERENCE.md](STDLIB_REFERENCE.md)

---

## 2. Domain Data Types (`struct` & `enum`)

(24 public types declared across this domain's modules)

| Type Name | Kind | Source Module | Fields / Variants | Default Constructor / Description |
| :--- | :--- | :--- | :--- | :--- |
| `BitStream` | `pub struct` | `std/encoding/bincode.aipl` | `bytes: [int]`, `bitOffset: int` | `BitStream(bytes, bitOffset)` |
| `BincodeWriter` | `pub struct` | `std/encoding/bincode.aipl` | `buffer: bytes`, `offset: int`, `littleEndian: bool`, `mut data: [int] = []` | `BincodeWriter(buffer, offset, littleEndian, mut data)` |
| `BincodeReader` | `pub struct` | `std/encoding/bincode.aipl` | `buffer: bytes`, `offset: int`, `littleEndian: bool` | `BincodeReader(buffer, offset, littleEndian)` |
| `CsvOptions` | `pub struct` | `std/encoding/csv.aipl` | `delimiter: str`, `quoteChar: str`, `escapeChar: str`, `hasHeader: bool` | `CsvOptions(delimiter, quoteChar, escapeChar, hasHeader)` |
| `CsvReader` | `pub struct` | `std/encoding/csv.aipl` | `text: str`, `opts: CsvOptions`, `currentLine: int` | `CsvReader(text, opts, currentLine)` |
| `CsvWriter` | `pub struct` | `std/encoding/csv.aipl` | `opts: CsvOptions`, `rows: [[str]]` | `CsvWriter(opts, rows)` |
| `HtmlNode` | `pub struct` | `std/encoding/html_dom.aipl` | `tag: str`, `attributes: [(str, str)]`, `children: [HtmlNode]`, `innerText: str`, `id: str`, `classList: [str]` | `HtmlNode(tag, attributes, children, innerText, id, classList)` |
| `HtmlDocument` | `pub struct` | `std/encoding/html_dom.aipl` | `root: HtmlNode` | `HtmlDocument(root)` |
| `IniDocument` | `pub struct` | `std/encoding/ini_dotenv.aipl` | `sections: [(str, [(str, str)])]` | `IniDocument(sections)` |
| `DotEnvMap` | `pub struct` | `std/encoding/ini_dotenv.aipl` | `entries: [(str, str)]` | `DotEnvMap(entries)` |
| `JsonValue` | `pub struct` | `std/encoding/json.aipl` | `kind: str`, `numVal: float`, `strVal: str`, `boolVal: bool`, `arrayVal: [JsonValue]`, `objectVal: [(str, JsonValue)]` | `JsonValue(kind, numVal, strVal, boolVal, arrayVal, objectVal)` |
| `JsonWriter` | `pub struct` | `std/encoding/json.aipl` | `indent: int`, `compact: bool`, `buffer: str` | `JsonWriter(indent, compact, buffer)` |
| `MdBlockKind` | `pub enum` | `std/encoding/markdown.aipl` | `Heading`, `Paragraph`, `CodeBlock`, `List`, `BlockQuote`, `HorizontalRule`, `Table` | Algebraic Enum (7 variants) |
| `MdBlock` | `pub struct` | `std/encoding/markdown.aipl` | `kind: MdBlockKind`, `level: int = 0`, `lang: str = ""`, `text: str = ""`, `items: [str] = []`, `headers: [str] = []`, `rows: [[str]] = []` | `MdBlock(kind, level, lang, text, items, headers, rows)` |
| `MdDocument` | `pub struct` | `std/encoding/markdown.aipl` | `blocks: [MdBlock]` | `MdDocument(blocks)` |
| `SemVer` | `pub struct` | `std/encoding/qrcode_semver.aipl` | `major: int`, `minor: int`, `patch: int`, `prerelease: str = ""`, `build: str = ""` | `SemVer(major, minor, patch, prerelease, build)` |
| `QrMatrix` | `pub struct` | `std/encoding/qrcode_semver.aipl` | `version: int`, `size: int`, `modules: [bool]` | `QrMatrix(version, size, modules)` |
| `TomlValue` | `pub struct` | `std/encoding/toml.aipl` | `kind: str`, `strVal: str`, `intVal: int`, `floatVal: float`, `boolVal: bool`, `listVal: [TomlValue]`, `tableVal: [(str, TomlValue)]` | `TomlValue(kind, strVal, intVal, floatVal, boolVal, listVal, tableVal)` |
| `TomlDocument` | `pub struct` | `std/encoding/toml.aipl` | `rootTable: [(str, TomlValue)]` | `TomlDocument(rootTable)` |
| `XmlAttribute` | `pub struct` | `std/encoding/xml.aipl` | `name: str`, `value: str` | `XmlAttribute(name, value)` |
| `XmlNode` | `pub struct` | `std/encoding/xml.aipl` | `tag: str`, `attributes: [XmlAttribute]`, `children: [XmlNode]`, `textContent: str`, `isComment: bool` | `XmlNode(tag, attributes, children, textContent, isComment)` |
| `XmlDocument` | `pub struct` | `std/encoding/xml.aipl` | `root: XmlNode`, `declaration: str`, `tag: str = ""` | `XmlDocument(root, declaration, tag)` |
| `YamlNode` | `pub struct` | `std/encoding/yaml.aipl` | `kind: str`, `scalar: str`, `sequence: [YamlNode]`, `mapping: [(str, YamlNode)]` | `YamlNode(kind, scalar, sequence, mapping)` |
| `YamlEntry` | `pub struct` | `std/encoding/yaml.aipl` | `key: str`, `value: str` | `YamlEntry(key, value)` |

## 3. Quick-Lookup Function Index


| # | Source Module | Function / Method | Exact Signature | Unit Test File |
| :--- | :--- | :--- | :--- | :--- |
| `1` | `std/encoding/base64.aipl` | `b64CharVal` | `fn b64CharVal(code: int, urlSafe: bool): int:` | `tests/functions/encoding/base64_test.aipl` |
| `2` | `std/encoding/base64.aipl` | `base64Encode` | `pub fn base64Encode(data: bytes): str:` | `tests/functions/encoding/base64_test.aipl` |
| `3` | `std/encoding/base64.aipl` | `base64Decode` | `pub fn base64Decode(s: str): Result[bytes, str]:` | `tests/functions/encoding/base64_test.aipl` |
| `4` | `std/encoding/base64.aipl` | `base64UrlEncode` | `pub fn base64UrlEncode(data: bytes): str:` | `tests/functions/encoding/base64_test.aipl` |
| `5` | `std/encoding/base64.aipl` | `base64UrlDecode` | `pub fn base64UrlDecode(s: str): Result[bytes, str]:` | `tests/functions/encoding/base64_test.aipl` |
| `6` | `std/encoding/base64.aipl` | `base62Encode` | `pub fn base62Encode(n: int): str:` | `tests/functions/encoding/base64_test.aipl` |
| `7` | `std/encoding/base64.aipl` | `base62Decode` | `pub fn base62Decode(s: str): Result[int, str]:` | `tests/functions/encoding/base64_test.aipl` |
| `8` | `std/encoding/base64.aipl` | `crockfordBase32Encode` | `pub fn crockfordBase32Encode(data: bytes): str:` | `tests/functions/encoding/base64_test.aipl` |
| `9` | `std/encoding/base64.aipl` | `crockfordCharVal` | `fn crockfordCharVal(code: int): int:` | `tests/functions/encoding/base64_test.aipl` |
| `10` | `std/encoding/base64.aipl` | `crockfordBase32Decode` | `pub fn crockfordBase32Decode(s: str): Result[bytes, str]:` | `tests/functions/encoding/base64_test.aipl` |
| `11` | `std/encoding/base64.aipl` | `isUnreservedUrlByte` | `fn isUnreservedUrlByte(b: int): bool:` | `tests/functions/encoding/base64_test.aipl` |
| `12` | `std/encoding/base64.aipl` | `urlPercentEncode` | `pub fn urlPercentEncode(s: str): str:` | `tests/functions/encoding/base64_test.aipl` |
| `13` | `std/encoding/base64.aipl` | `urlPercentDecode` | `pub fn urlPercentDecode(s: str): Result[str, str]:` | `tests/functions/encoding/base64_test.aipl` |
| `14` | `std/encoding/base64.aipl` | `base62DecodeResult` | `pub fn base62DecodeResult(s: str): Result[int, str]:` | `tests/functions/encoding/base64_test.aipl` |
| `15` | `std/encoding/base64.aipl` | `urlEncode` | `pub fn urlEncode(s: str): str:` | `tests/functions/encoding/base64_test.aipl` |
| `16` | `std/encoding/base64.aipl` | `urlDecode` | `pub fn urlDecode(s: str): Result[str, str]:` | `tests/functions/encoding/base64_test.aipl` |
| `17` | `std/encoding/base64.aipl` | `base64EncodeStr` | `pub fn base64EncodeStr(s: str): str:` | `tests/functions/encoding/base64_test.aipl` |
| `18` | `std/encoding/base64.aipl` | `base64DecodeStr` | `pub fn base64DecodeStr(s: str): Result[str, str]:` | `tests/functions/encoding/base64_test.aipl` |
| `19` | `std/encoding/bincode.aipl` | `bincodeWriterNew` | `pub fn bincodeWriterNew(initialCapacity: int = 128, littleEndian: bool = true): BincodeWriter:` | `tests/functions/encoding/bincode_test.aipl` |
| `20` | `std/encoding/bincode.aipl` | `writeU8` | `pub fn (mut self: BincodeWriter) writeU8(val: int): void:` | `tests/functions/encoding/bincode_test.aipl` |
| `21` | `std/encoding/bincode.aipl` | `writeI32` | `pub fn (mut self: BincodeWriter) writeI32(val: int): void:` | `tests/functions/encoding/bincode_test.aipl` |
| `22` | `std/encoding/bincode.aipl` | `writeI64` | `pub fn (mut self: BincodeWriter) writeI64(val: int): void:` | `tests/functions/encoding/bincode_test.aipl` |
| `23` | `std/encoding/bincode.aipl` | `f64ToF32Bits` | `fn f64ToF32Bits(val: float): int:` | `tests/functions/encoding/bincode_test.aipl` |
| `24` | `std/encoding/bincode.aipl` | `f32BitsToF64` | `fn f32BitsToF64(bits32: int): float:` | `tests/functions/encoding/bincode_test.aipl` |
| `25` | `std/encoding/bincode.aipl` | `writeF32` | `pub fn (mut self: BincodeWriter) writeF32(val: float): void:` | `tests/functions/encoding/bincode_test.aipl` |
| `26` | `std/encoding/bincode.aipl` | `writeF64` | `pub fn (mut self: BincodeWriter) writeF64(val: float): void:` | `tests/functions/encoding/bincode_test.aipl` |
| `27` | `std/encoding/bincode.aipl` | `writeVarInt` | `pub fn (mut self: BincodeWriter) writeVarInt(val: int): void:` | `tests/functions/encoding/bincode_test.aipl` |
| `28` | `std/encoding/bincode.aipl` | `writeString` | `pub fn (mut self: BincodeWriter) writeString(s: str): void:` | `tests/functions/encoding/bincode_test.aipl` |
| `29` | `std/encoding/bincode.aipl` | `toBytes` | `pub fn (self: BincodeWriter) toBytes(): bytes:` | `tests/functions/encoding/bincode_test.aipl` |
| `30` | `std/encoding/bincode.aipl` | `bincodeReaderNew` | `pub fn bincodeReaderNew(data: bytes, littleEndian: bool = true): BincodeReader:` | `tests/functions/encoding/bincode_test.aipl` |
| `31` | `std/encoding/bincode.aipl` | `readU8` | `pub fn (mut self: BincodeReader) readU8(): Result[int, str]:` | `tests/functions/encoding/bincode_test.aipl` |
| `32` | `std/encoding/bincode.aipl` | `readI32` | `pub fn (mut self: BincodeReader) readI32(): Result[int, str]:` | `tests/functions/encoding/bincode_test.aipl` |
| `33` | `std/encoding/bincode.aipl` | `readI64` | `pub fn (mut self: BincodeReader) readI64(): Result[int, str]:` | `tests/functions/encoding/bincode_test.aipl` |
| `34` | `std/encoding/bincode.aipl` | `readF32` | `pub fn (mut self: BincodeReader) readF32(): Result[float, str]:` | `tests/functions/encoding/bincode_test.aipl` |
| `35` | `std/encoding/bincode.aipl` | `readF64` | `pub fn (mut self: BincodeReader) readF64(): Result[float, str]:` | `tests/functions/encoding/bincode_test.aipl` |
| `36` | `std/encoding/bincode.aipl` | `readVarInt` | `pub fn (mut self: BincodeReader) readVarInt(): Result[int, str]:` | `tests/functions/encoding/bincode_test.aipl` |
| `37` | `std/encoding/bincode.aipl` | `readString` | `pub fn (mut self: BincodeReader) readString(): Result[str, str]:` | `tests/functions/encoding/bincode_test.aipl` |
| `38` | `std/encoding/bincode.aipl` | `bitStreamNew` | `pub fn bitStreamNew(): BitStream:` | `tests/functions/encoding/bincode_test.aipl` |
| `39` | `std/encoding/bincode.aipl` | `bitStreamWriteBits` | `pub fn bitStreamWriteBits(mut bs: BitStream, val: int, count: int): BitStream:` | `tests/functions/encoding/bincode_test.aipl` |
| `40` | `std/encoding/bincode.aipl` | `bitStreamToBytes` | `pub fn bitStreamToBytes(bs: BitStream): bytes:` | `tests/functions/encoding/bincode_test.aipl` |
| `41` | `std/encoding/bincode.aipl` | `bitStreamBitCount` | `pub fn bitStreamBitCount(bs: BitStream): int:` | `tests/functions/encoding/bincode_test.aipl` |
| `42` | `std/encoding/bincode.aipl` | `bincodePackIntArray` | `pub fn bincodePackIntArray(vals: [int]): bytes:` | `tests/functions/encoding/bincode_test.aipl` |
| `43` | `std/encoding/bincode.aipl` | `bincodeUnpackIntArray` | `pub fn bincodeUnpackIntArray(data: bytes): Result[[int], str]:` | `tests/functions/encoding/bincode_test.aipl` |
| `44` | `std/encoding/csv.aipl` | `parseCsv` | `pub fn parseCsv(text: str, delimiter: str = ","): Result[[[str]], str]:` | `tests/functions/encoding/csv_test.aipl` |
| `45` | `std/encoding/csv.aipl` | `serializeCsvCell` | `fn serializeCsvCell(cell: str, delimiter: str): str:` | `tests/functions/encoding/csv_test.aipl` |
| `46` | `std/encoding/csv.aipl` | `serializeCsv` | `pub fn serializeCsv(rows: [[str]], delimiter: str = ","): str:` | `tests/functions/encoding/csv_test.aipl` |
| `47` | `std/encoding/csv.aipl` | `readRow` | `pub fn (mut self: CsvReader) readRow(): Option[[str]]:` | `tests/functions/encoding/csv_test.aipl` |
| `48` | `std/encoding/csv.aipl` | `stringifyCsv` | `pub fn stringifyCsv(rows: [[str]], delimiter: str = ","): str:` | `tests/functions/encoding/csv_test.aipl` |
| `49` | `std/encoding/csv.aipl` | `formatCsv` | `pub fn formatCsv(rows: [[str]], delimiter: str = ","): str:` | `tests/functions/encoding/csv_test.aipl` |
| `50` | `std/encoding/csv.aipl` | `toCsv` | `pub fn toCsv(rows: [[str]]): str:` | `tests/functions/encoding/csv_test.aipl` |
| `51` | `std/encoding/csv.aipl` | `parseCsvRecords` | `pub fn parseCsvRecords(text: str): [Map[str, str]]:` | `tests/functions/encoding/csv_test.aipl` |
| `52` | `std/encoding/csv.aipl` | `parseCsvWithHeaders` | `pub fn parseCsvWithHeaders(text: str): [Map[str, str]]:` | `tests/functions/encoding/csv_test.aipl` |
| `53` | `std/encoding/csv.aipl` | `stringifyCsvRecords` | `pub fn stringifyCsvRecords(records: [Map[str, str]], headers: [str]): str:` | `tests/functions/encoding/csv_test.aipl` |
| `54` | `std/encoding/csv.aipl` | `parseTsv` | `pub fn parseTsv(text: str): [[str]]:` | `tests/functions/encoding/csv_test.aipl` |
| `55` | `std/encoding/csv.aipl` | `parseTsvRecords` | `pub fn parseTsvRecords(text: str): [Map[str, str]]:` | `tests/functions/encoding/csv_test.aipl` |
| `56` | `std/encoding/csv.aipl` | `parseTsvWithHeaders` | `pub fn parseTsvWithHeaders(text: str): [Map[str, str]]:` | `tests/functions/encoding/csv_test.aipl` |
| `57` | `std/encoding/csv.aipl` | `stringifyTsv` | `pub fn stringifyTsv(rows: [[str]]): str:` | `tests/functions/encoding/csv_test.aipl` |
| `58` | `std/encoding/csv.aipl` | `toTsv` | `pub fn toTsv(rows: [[str]]): str:` | `tests/functions/encoding/csv_test.aipl` |
| `59` | `std/encoding/csv.aipl` | `formatTsv` | `pub fn formatTsv(rows: [[str]]): str:` | `tests/functions/encoding/csv_test.aipl` |
| `60` | `std/encoding/csv.aipl` | `stringifyTsvRecords` | `pub fn stringifyTsvRecords(records: [Map[str, str]], headers: [str]): str:` | `tests/functions/encoding/csv_test.aipl` |
| `61` | `std/encoding/csv.aipl` | `csvColumnValues` | `pub fn csvColumnValues(rows: [[str]], colIdx: int): [str]:` | `tests/functions/encoding/csv_test.aipl` |
| `62` | `std/encoding/hex.aipl` | `hexNibbleToChar` | `fn hexNibbleToChar(nib: int, uppercase: bool): str:` | `tests/functions/encoding/hex_test.aipl` |
| `63` | `std/encoding/hex.aipl` | `hexCharToVal` | `fn hexCharToVal(code: int): int:` | `tests/functions/encoding/hex_test.aipl` |
| `64` | `std/encoding/hex.aipl` | `hexEncode` | `pub fn hexEncode(data: bytes, uppercase: bool = false): str:` | `tests/functions/encoding/hex_test.aipl` |
| `65` | `std/encoding/hex.aipl` | `hexDecode` | `pub fn hexDecode(s: str): Result[bytes, str]:` | `tests/functions/encoding/hex_test.aipl` |
| `66` | `std/encoding/hex.aipl` | `padHex4` | `fn padHex4(val: int): str:` | `tests/functions/encoding/hex_test.aipl` |
| `67` | `std/encoding/hex.aipl` | `hexDump` | `pub fn hexDump(data: bytes, bytesPerLine: int = 16): str:` | `tests/functions/encoding/hex_test.aipl` |
| `68` | `std/encoding/hex.aipl` | `hexDigitChar` | `pub fn hexDigitChar(val: int): str:` | `tests/functions/encoding/hex_test.aipl` |
| `69` | `std/encoding/hex.aipl` | `hexEncodeUpper` | `pub fn hexEncodeUpper(data: bytes): str:` | `tests/functions/encoding/hex_test.aipl` |
| `70` | `std/encoding/hex.aipl` | `hexValidate` | `pub fn hexValidate(s: str): bool:` | `tests/functions/encoding/hex_test.aipl` |
| `71` | `std/encoding/hex.aipl` | `formatHexOffset8` | `pub fn formatHexOffset8(offset: int): str:` | `tests/functions/encoding/hex_test.aipl` |
| `72` | `std/encoding/hex.aipl` | `formatHexdump` | `pub fn formatHexdump(data: bytes): [str]:` | `tests/functions/encoding/hex_test.aipl` |
| `73` | `std/encoding/hex.aipl` | `hexdump` | `pub fn hexdump(data: bytes): str:` | `tests/functions/encoding/hex_test.aipl` |
| `74` | `std/encoding/html_dom.aipl` | `isVoidHtmlTag` | `fn isVoidHtmlTag(tag: str): bool:` | `tests/functions/encoding/html_dom_test.aipl` |
| `75` | `std/encoding/html_dom.aipl` | `parseHtmlAttrs` | `fn parseHtmlAttrs(raw: str): ([(str, str)], str, [str]):` | `tests/functions/encoding/html_dom_test.aipl` |
| `76` | `std/encoding/html_dom.aipl` | `parseHtmlNodeAt` | `fn parseHtmlNodeAt(htmlText: str, startPos: int): (int, HtmlNode):` | `tests/functions/encoding/html_dom_test.aipl` |
| `77` | `std/encoding/html_dom.aipl` | `parseHtml` | `pub fn parseHtml(htmlText: str): HtmlDocument:` | `tests/functions/encoding/html_dom_test.aipl` |
| `78` | `std/encoding/html_dom.aipl` | `matchesSelector` | `fn matchesSelector(node: HtmlNode, selector: str): bool:` | `tests/functions/encoding/html_dom_test.aipl` |
| `79` | `std/encoding/html_dom.aipl` | `collectMatchingHtmlNodes` | `fn collectMatchingHtmlNodes(node: HtmlNode, selector: str, mut acc: [HtmlNode]): [HtmlNode]:` | `tests/functions/encoding/html_dom_test.aipl` |
| `80` | `std/encoding/html_dom.aipl` | `querySelectorAll` | `pub fn (self: HtmlDocument) querySelectorAll(selector: str): [HtmlNode]:` | `tests/functions/encoding/html_dom_test.aipl` |
| `81` | `std/encoding/html_dom.aipl` | `querySelector` | `pub fn (self: HtmlDocument) querySelector(selector: str): Option[HtmlNode]:` | `tests/functions/encoding/html_dom_test.aipl` |
| `82` | `std/encoding/html_dom.aipl` | `getElementById` | `pub fn (self: HtmlNode) getElementById(id: str): Option[HtmlNode]:` | `tests/functions/encoding/html_dom_test.aipl` |
| `83` | `std/encoding/html_dom.aipl` | `getElementsByClassName` | `pub fn (self: HtmlNode) getElementsByClassName(className: str): [HtmlNode]:` | `tests/functions/encoding/html_dom_test.aipl` |
| `84` | `std/encoding/html_dom.aipl` | `escapeHtml` | `pub fn escapeHtml(s: str): str:` | `tests/functions/encoding/html_dom_test.aipl` |
| `85` | `std/encoding/html_dom.aipl` | `htmlEscape` | `pub fn htmlEscape(s: str): str:` | `tests/functions/encoding/html_dom_test.aipl` |
| `86` | `std/encoding/html_dom.aipl` | `htmlUnescape` | `pub fn htmlUnescape(s: str): str:` | `tests/functions/encoding/html_dom_test.aipl` |
| `87` | `std/encoding/html_dom.aipl` | `unescapeHtml` | `pub fn unescapeHtml(s: str): str:` | `tests/functions/encoding/html_dom_test.aipl` |
| `88` | `std/encoding/html_dom.aipl` | `sanitizeUrl` | `pub fn sanitizeUrl(url: str): str:` | `tests/functions/encoding/html_dom_test.aipl` |
| `89` | `std/encoding/html_dom.aipl` | `innerText` | `pub fn innerText(node: HtmlNode): str:` | `tests/functions/encoding/html_dom_test.aipl` |
| `90` | `std/encoding/html_dom.aipl` | `htmlToPlainText` | `pub fn htmlToPlainText(html: str): str:` | `tests/functions/encoding/html_dom_test.aipl` |
| `91` | `std/encoding/html_dom.aipl` | `htmlNodeAttr` | `pub fn htmlNodeAttr(node: HtmlNode, attrName: str): Option[str]:` | `tests/functions/encoding/html_dom_test.aipl` |
| `92` | `std/encoding/html_dom.aipl` | `formatHtml` | `pub fn formatHtml(node: HtmlNode): str:` | `tests/functions/encoding/html_dom_test.aipl` |
| `93` | `std/encoding/html_dom.aipl` | `toHtml` | `pub fn toHtml(doc: HtmlDocument): str:` | `tests/functions/encoding/html_dom_test.aipl` |
| `94` | `std/encoding/ini_dotenv.aipl` | `stripIniInlineComment` | `fn stripIniInlineComment(line: str): str:` | `tests/functions/encoding/ini_dotenv_test.aipl` |
| `95` | `std/encoding/ini_dotenv.aipl` | `unquoteIniVal` | `fn unquoteIniVal(v: str): str:` | `tests/functions/encoding/ini_dotenv_test.aipl` |
| `96` | `std/encoding/ini_dotenv.aipl` | `parseIni` | `pub fn parseIni(text: str): Result[IniDocument, str]:` | `tests/functions/encoding/ini_dotenv_test.aipl` |
| `97` | `std/encoding/ini_dotenv.aipl` | `get` | `pub fn (self: IniDocument) get(section: str, key: str): Option[str]:` | `tests/functions/encoding/ini_dotenv_test.aipl` |
| `98` | `std/encoding/ini_dotenv.aipl` | `serializeIni` | `pub fn serializeIni(doc: IniDocument): str:` | `tests/functions/encoding/ini_dotenv_test.aipl` |
| `99` | `std/encoding/ini_dotenv.aipl` | `parseDotEnv` | `pub fn parseDotEnv(text: str): DotEnvMap:` | `tests/functions/encoding/ini_dotenv_test.aipl` |
| `100` | `std/encoding/ini_dotenv.aipl` | `get` | `pub fn (self: DotEnvMap) get(key: str, fallback: str = ""): str:` | `tests/functions/encoding/ini_dotenv_test.aipl` |
| `101` | `std/encoding/ini_dotenv.aipl` | `containsKey` | `pub fn (self: DotEnvMap) containsKey(key: str): bool:` | `tests/functions/encoding/ini_dotenv_test.aipl` |
| `102` | `std/encoding/ini_dotenv.aipl` | `fastIniGetValue` | `pub fn fastIniGetValue(iniText: str, section: str, key: str, defaultVal: str): str:` | `tests/functions/encoding/ini_dotenv_test.aipl` |
| `103` | `std/encoding/ini_dotenv.aipl` | `parseDotenv` | `pub fn parseDotenv(text: str): Map[str, str]:` | `tests/functions/encoding/ini_dotenv_test.aipl` |
| `104` | `std/encoding/ini_dotenv.aipl` | `loadDotEnv` | `pub fn loadDotEnv(text: str): Map[str, str]:` | `tests/functions/encoding/ini_dotenv_test.aipl` |
| `105` | `std/encoding/ini_dotenv.aipl` | `loadDotenv` | `pub fn loadDotenv(text: str): Map[str, str]:` | `tests/functions/encoding/ini_dotenv_test.aipl` |
| `106` | `std/encoding/ini_dotenv.aipl` | `validateDotEnvSchema` | `pub fn validateDotEnvSchema(envMap: Map[str, str], requiredKeys: [str]): Result[bool, [str]]:` | `tests/functions/encoding/ini_dotenv_test.aipl` |
| `107` | `std/encoding/ini_dotenv.aipl` | `validateSchema` | `pub fn validateSchema(envMap: Map[str, str], requiredKeys: [str]): Result[bool, [str]]:` | `tests/functions/encoding/ini_dotenv_test.aipl` |
| `108` | `std/encoding/ini_dotenv.aipl` | `parseIniSection` | `pub fn parseIniSection(src: str, section: str): Map[str, str]:` | `tests/functions/encoding/ini_dotenv_test.aipl` |
| `109` | `std/encoding/ini_dotenv.aipl` | `parseIniSections` | `pub fn parseIniSections(src: str): [str]:` | `tests/functions/encoding/ini_dotenv_test.aipl` |
| `110` | `std/encoding/ini_dotenv.aipl` | `getIniValue` | `pub fn getIniValue(src: str, section: str, key: str, defaultVal: str): str:` | `tests/functions/encoding/ini_dotenv_test.aipl` |
| `111` | `std/encoding/ini_dotenv.aipl` | `toIni` | `pub fn toIni(section: str, m: Map[str, str]): str:` | `tests/functions/encoding/ini_dotenv_test.aipl` |
| `112` | `std/encoding/json.aipl` | `jsonNull` | `pub fn jsonNull(): JsonValue:` | `tests/functions/encoding/json_test.aipl` |
| `113` | `std/encoding/json.aipl` | `jsonBool` | `pub fn jsonBool(b: bool): JsonValue:` | `tests/functions/encoding/json_test.aipl` |
| `114` | `std/encoding/json.aipl` | `jsonNumber` | `pub fn jsonNumber(n: float): JsonValue:` | `tests/functions/encoding/json_test.aipl` |
| `115` | `std/encoding/json.aipl` | `jsonString` | `pub fn jsonString(s: str): JsonValue:` | `tests/functions/encoding/json_test.aipl` |
| `116` | `std/encoding/json.aipl` | `jsonArray` | `pub fn jsonArray(items: [JsonValue]): JsonValue:` | `tests/functions/encoding/json_test.aipl` |
| `117` | `std/encoding/json.aipl` | `jsonObject` | `pub fn jsonObject(entries: [(str, JsonValue)]): JsonValue:` | `tests/functions/encoding/json_test.aipl` |
| `118` | `std/encoding/json.aipl` | `skipJsonWs` | `fn skipJsonWs(text: str, start: int): int:` | `tests/functions/encoding/json_test.aipl` |
| `119` | `std/encoding/json.aipl` | `parseJsonStringAt` | `fn parseJsonStringAt(text: str, start: int): (int, str, str):` | `tests/functions/encoding/json_test.aipl` |
| `120` | `std/encoding/json.aipl` | `parseJsonNumberAt` | `fn parseJsonNumberAt(text: str, start: int): JsonParseCursor:` | `tests/functions/encoding/json_test.aipl` |
| `121` | `std/encoding/json.aipl` | `parseJsonValueAt` | `fn parseJsonValueAt(text: str, start: int): JsonParseCursor:` | `tests/functions/encoding/json_test.aipl` |
| `122` | `std/encoding/json.aipl` | `jsonParse` | `pub fn jsonParse(text: str): Result[JsonValue, str]:` | `tests/functions/encoding/json_test.aipl` |
| `123` | `std/encoding/json.aipl` | `escapeJsonString` | `pub fn escapeJsonString(s: str): str:` | `tests/functions/encoding/json_test.aipl` |
| `124` | `std/encoding/json.aipl` | `formatJsonNumber` | `fn formatJsonNumber(n: float): str:` | `tests/functions/encoding/json_test.aipl` |
| `125` | `std/encoding/json.aipl` | `jsonStringify` | `pub fn jsonStringify(val: JsonValue): str:` | `tests/functions/encoding/json_test.aipl` |
| `126` | `std/encoding/json.aipl` | `makeSpaces` | `fn makeSpaces(count: int): str:` | `tests/functions/encoding/json_test.aipl` |
| `127` | `std/encoding/json.aipl` | `jsonStringifyIndent` | `fn jsonStringifyIndent(val: JsonValue, indent: int, depth: int): str:` | `tests/functions/encoding/json_test.aipl` |
| `128` | `std/encoding/json.aipl` | `jsonStringifyPretty` | `pub fn jsonStringifyPretty(val: JsonValue, indent: int = 2): str:` | `tests/functions/encoding/json_test.aipl` |
| `129` | `std/encoding/json.aipl` | `get` | `pub fn (self: JsonValue) get(key: str): Option[JsonValue]:` | `tests/functions/encoding/json_test.aipl` |
| `130` | `std/encoding/json.aipl` | `getIndex` | `pub fn (self: JsonValue) getIndex(idx: int): Option[JsonValue]:` | `tests/functions/encoding/json_test.aipl` |
| `131` | `std/encoding/json.aipl` | `asStr` | `pub fn (self: JsonValue) asStr(): Option[str]:` | `tests/functions/encoding/json_test.aipl` |
| `132` | `std/encoding/json.aipl` | `asInt` | `pub fn (self: JsonValue) asInt(): Option[int]:` | `tests/functions/encoding/json_test.aipl` |
| `133` | `std/encoding/json.aipl` | `asFloat` | `pub fn (self: JsonValue) asFloat(): Option[float]:` | `tests/functions/encoding/json_test.aipl` |
| `134` | `std/encoding/json.aipl` | `asBool` | `pub fn (self: JsonValue) asBool(): Option[bool]:` | `tests/functions/encoding/json_test.aipl` |
| `135` | `std/encoding/json.aipl` | `jsonQueryPath` | `pub fn jsonQueryPath(val: JsonValue, path: str): Option[JsonValue]:` | `tests/functions/encoding/json_test.aipl` |
| `136` | `std/encoding/json.aipl` | `fastJsonGetInt` | `pub fn fastJsonGetInt(jsonStr: str, key: str, defaultVal: int): int:` | `tests/functions/encoding/json_test.aipl` |
| `137` | `std/encoding/json.aipl` | `fastJsonGetFloat` | `pub fn fastJsonGetFloat(jsonStr: str, key: str, defaultVal: float): float:` | `tests/functions/encoding/json_test.aipl` |
| `138` | `std/encoding/json.aipl` | `fastJsonGetStr` | `pub fn fastJsonGetStr(jsonStr: str, key: str, defaultVal: str): str:` | `tests/functions/encoding/json_test.aipl` |
| `139` | `std/encoding/json.aipl` | `fastJsonGetIntArray` | `pub fn fastJsonGetIntArray(jsonStr: str, key: str): [int]:` | `tests/functions/encoding/json_test.aipl` |
| `140` | `std/encoding/json.aipl` | `jsonGet` | `pub fn jsonGet(jsonStr: str, key: str): Option[str]:` | `tests/functions/encoding/json_test.aipl` |
| `141` | `std/encoding/json.aipl` | `formatJsonPrettyString` | `pub fn formatJsonPrettyString(jsonStr: str, indent: int = 2): str:` | `tests/functions/encoding/json_test.aipl` |
| `142` | `std/encoding/json.aipl` | `skipJsonWs` | `fn skipJsonWs(s: str, idx: int): int:` | `tests/functions/encoding/json_test.aipl` |
| `143` | `std/encoding/json.aipl` | `findJsonValueEnd` | `fn findJsonValueEnd(s: str, startIdx: int): int:` | `tests/functions/encoding/json_test.aipl` |
| `144` | `std/encoding/json.aipl` | `unquoteJsonValue` | `fn unquoteJsonValue(raw: str): str:` | `tests/functions/encoding/json_test.aipl` |
| `145` | `std/encoding/json.aipl` | `extractObjectKeyRaw` | `fn extractObjectKeyRaw(jsonObj: str, targetKey: str): Option[str]:` | `tests/functions/encoding/json_test.aipl` |
| `146` | `std/encoding/json.aipl` | `extractArrayIndexRaw` | `fn extractArrayIndexRaw(jsonArr: str, targetIdx: int): Option[str]:` | `tests/functions/encoding/json_test.aipl` |
| `147` | `std/encoding/json.aipl` | `parseNonNegInt` | `fn parseNonNegInt(s: str): Option[int]:` | `tests/functions/encoding/json_test.aipl` |
| `148` | `std/encoding/json.aipl` | `jsonQueryRaw` | `pub fn jsonQueryRaw(jsonText: str, queryPath: str): Option[str]:` | `tests/functions/encoding/json_test.aipl` |
| `149` | `std/encoding/json.aipl` | `jsonQuery` | `pub fn jsonQuery(jsonText: str, path: str): Option[str]:` | `tests/functions/encoding/json_test.aipl` |
| `150` | `std/encoding/json.aipl` | `jsonGetPathStr` | `pub fn jsonGetPathStr(jsonText: str, path: str, defaultVal: str): str:` | `tests/functions/encoding/json_test.aipl` |
| `151` | `std/encoding/json.aipl` | `jsonGetPathFloat` | `pub fn jsonGetPathFloat(jsonText: str, path: str, defaultVal: float): float:` | `tests/functions/encoding/json_test.aipl` |
| `152` | `std/encoding/json.aipl` | `jsonGetPathInt` | `pub fn jsonGetPathInt(jsonText: str, path: str, defaultVal: int): int:` | `tests/functions/encoding/json_test.aipl` |
| `153` | `std/encoding/json.aipl` | `jsonStringifyIntArray` | `pub fn jsonStringifyIntArray(arr: [int]): str:` | `tests/functions/encoding/json_test.aipl` |
| `154` | `std/encoding/json.aipl` | `jsonGetPathIntArray` | `pub fn jsonGetPathIntArray(jsonText: str, path: str): [int]:` | `tests/functions/encoding/json_test.aipl` |
| `155` | `std/encoding/json.aipl` | `jsonFieldInt` | `pub fn jsonFieldInt(key: str, val: int): str:` | `tests/functions/encoding/json_test.aipl` |
| `156` | `std/encoding/json.aipl` | `jsonFieldFloat` | `pub fn jsonFieldFloat(key: str, val: float): str:` | `tests/functions/encoding/json_test.aipl` |
| `157` | `std/encoding/json.aipl` | `jsonFieldStr` | `pub fn jsonFieldStr(key: str, val: str): str:` | `tests/functions/encoding/json_test.aipl` |
| `158` | `std/encoding/json.aipl` | `jsonFieldBool` | `pub fn jsonFieldBool(key: str, val: bool): str:` | `tests/functions/encoding/json_test.aipl` |
| `159` | `std/encoding/json.aipl` | `jsonObject2` | `pub fn jsonObject2(f1: str, f2: str): str:` | `tests/functions/encoding/json_test.aipl` |
| `160` | `std/encoding/json.aipl` | `jsonObject3` | `pub fn jsonObject3(f1: str, f2: str, f3: str): str:` | `tests/functions/encoding/json_test.aipl` |
| `161` | `std/encoding/json.aipl` | `jsonObject4` | `pub fn jsonObject4(f1: str, f2: str, f3: str, f4: str): str:` | `tests/functions/encoding/json_test.aipl` |
| `162` | `std/encoding/json.aipl` | `jsonObject5` | `pub fn jsonObject5(f1: str, f2: str, f3: str, f4: str, f5: str): str:` | `tests/functions/encoding/json_test.aipl` |
| `163` | `std/encoding/json.aipl` | `jsonObject6` | `pub fn jsonObject6(f1: str, f2: str, f3: str, f4: str, f5: str, f6: str): str:` | `tests/functions/encoding/json_test.aipl` |
| `164` | `std/encoding/json.aipl` | `jsonObject7` | `pub fn jsonObject7(f1: str, f2: str, f3: str, f4: str, f5: str, f6: str, f7: str): str:` | `tests/functions/encoding/json_test.aipl` |
| `165` | `std/encoding/json.aipl` | `jsonObject8` | `pub fn jsonObject8(f1: str, f2: str, f3: str, f4: str, f5: str, f6: str, f7: str, f8: str): str:` | `tests/functions/encoding/json_test.aipl` |
| `166` | `std/encoding/json.aipl` | `jsonObjectFields` | `pub fn jsonObjectFields(fields: [str]): str:` | `tests/functions/encoding/json_test.aipl` |
| `167` | `std/encoding/json.aipl` | `jsonArrayFields` | `pub fn jsonArrayFields(items: [str]): str:` | `tests/functions/encoding/json_test.aipl` |
| `168` | `std/encoding/json.aipl` | `jsonArrayStr` | `pub fn jsonArrayStr(items: [str]): str:` | `tests/functions/encoding/json_test.aipl` |
| `169` | `std/encoding/json.aipl` | `jsonArrayInt` | `pub fn jsonArrayInt(items: [int]): str:` | `tests/functions/encoding/json_test.aipl` |
| `170` | `std/encoding/markdown.aipl` | `escapeMdHtml` | `fn escapeMdHtml(s: str): str:` | `tests/functions/encoding/markdown_test.aipl` |
| `171` | `std/encoding/markdown.aipl` | `isHorizontalRuleLine` | `fn isHorizontalRuleLine(trimmed: str): bool:` | `tests/functions/encoding/markdown_test.aipl` |
| `172` | `std/encoding/markdown.aipl` | `splitTableRowCells` | `fn splitTableRowCells(line: str): [str]:` | `tests/functions/encoding/markdown_test.aipl` |
| `173` | `std/encoding/markdown.aipl` | `isTableSeparatorLine` | `fn isTableSeparatorLine(line: str): bool:` | `tests/functions/encoding/markdown_test.aipl` |
| `174` | `std/encoding/markdown.aipl` | `isOrderedListPrefix` | `fn isOrderedListPrefix(trimmed: str): int:` | `tests/functions/encoding/markdown_test.aipl` |
| `175` | `std/encoding/markdown.aipl` | `renderInlineMarkdown` | `fn renderInlineMarkdown(text: str): str:` | `tests/functions/encoding/markdown_test.aipl` |
| `176` | `std/encoding/markdown.aipl` | `parseMarkdown` | `pub fn parseMarkdown(text: str): MdDocument:` | `tests/functions/encoding/markdown_test.aipl` |
| `177` | `std/encoding/markdown.aipl` | `renderMarkdownHtml` | `pub fn renderMarkdownHtml(doc: MdDocument): str:` | `tests/functions/encoding/markdown_test.aipl` |
| `178` | `std/encoding/markdown.aipl` | `markdownToHtml` | `pub fn markdownToHtml(text: str): str:` | `tests/functions/encoding/markdown_test.aipl` |
| `179` | `std/encoding/markdown.aipl` | `extractMarkdownHeadings` | `pub fn extractMarkdownHeadings(text: str): [MdBlock]:` | `tests/functions/encoding/markdown_test.aipl` |
| `180` | `std/encoding/markdown.aipl` | `extractMarkdownCodeBlocks` | `pub fn extractMarkdownCodeBlocks(text: str): [MdBlock]:` | `tests/functions/encoding/markdown_test.aipl` |
| `181` | `std/encoding/markdown.aipl` | `markdownStrip` | `pub fn markdownStrip(text: str): str:` | `tests/functions/encoding/markdown_test.aipl` |
| `182` | `std/encoding/markdown.aipl` | `markdownToPlainText` | `pub fn markdownToPlainText(text: str): str:` | `tests/functions/encoding/markdown_test.aipl` |
| `183` | `std/encoding/markdown.aipl` | `parseMarkdownHeadings` | `pub fn parseMarkdownHeadings(text: str): [(int, str)]:` | `tests/functions/encoding/markdown_test.aipl` |
| `184` | `std/encoding/markdown.aipl` | `markdownWordCount` | `pub fn markdownWordCount(text: str): int:` | `tests/functions/encoding/markdown_test.aipl` |
| `185` | `std/encoding/markdown.aipl` | `extractMarkdownLinks` | `pub fn extractMarkdownLinks(text: str): [(str, str)]:` | `tests/functions/encoding/markdown_test.aipl` |
| `186` | `std/encoding/qrcode_semver.aipl` | `parseNonNegInt` | `fn parseNonNegInt(s: str): int:` | `tests/functions/encoding/qrcode_semver_test.aipl` |
| `187` | `std/encoding/qrcode_semver.aipl` | `parseSemVer` | `pub fn parseSemVer(text: str): Result[SemVer, str]:` | `tests/functions/encoding/qrcode_semver_test.aipl` |
| `188` | `std/encoding/qrcode_semver.aipl` | `formatSemVer` | `pub fn formatSemVer(v: SemVer): str:` | `tests/functions/encoding/qrcode_semver_test.aipl` |
| `189` | `std/encoding/qrcode_semver.aipl` | `comparePrerelease` | `fn comparePrerelease(preA: str, preB: str): int:` | `tests/functions/encoding/qrcode_semver_test.aipl` |
| `190` | `std/encoding/qrcode_semver.aipl` | `compareSemVer` | `pub fn compareSemVer(a: SemVer, b: SemVer): int:` | `tests/functions/encoding/qrcode_semver_test.aipl` |
| `191` | `std/encoding/qrcode_semver.aipl` | `satisfiesSingleSemVer` | `fn satisfiesSingleSemVer(v: SemVer, single: str): bool:` | `tests/functions/encoding/qrcode_semver_test.aipl` |
| `192` | `std/encoding/qrcode_semver.aipl` | `satisfiesSemVer` | `pub fn satisfiesSemVer(v: SemVer, constraint: str): bool:` | `tests/functions/encoding/qrcode_semver_test.aipl` |
| `193` | `std/encoding/qrcode_semver.aipl` | `generateQrMatrix` | `pub fn generateQrMatrix(payload: str, ecLevel: int = 1): QrMatrix:` | `tests/functions/encoding/qrcode_semver_test.aipl` |
| `194` | `std/encoding/qrcode_semver.aipl` | `qrGetModule` | `pub fn qrGetModule(qr: QrMatrix, x: int, y: int): bool:` | `tests/functions/encoding/qrcode_semver_test.aipl` |
| `195` | `std/encoding/qrcode_semver.aipl` | `renderQrAscii` | `pub fn renderQrAscii(qr: QrMatrix): str:` | `tests/functions/encoding/qrcode_semver_test.aipl` |
| `196` | `std/encoding/qrcode_semver.aipl` | `renderQrSvg` | `pub fn renderQrSvg(qr: QrMatrix, moduleSizePx: int = 4): str:` | `tests/functions/encoding/qrcode_semver_test.aipl` |
| `197` | `std/encoding/qrcode_semver.aipl` | `qrGf256Mul` | `pub fn qrGf256Mul(a: int, b: int): int:` | `tests/functions/encoding/qrcode_semver_test.aipl` |
| `198` | `std/encoding/qrcode_semver.aipl` | `qrReedSolomonEncode` | `pub fn qrReedSolomonEncode(data: [int], ecCount: int): [int]:` | `tests/functions/encoding/qrcode_semver_test.aipl` |
| `199` | `std/encoding/qrcode_semver.aipl` | `qrComputeBchFormatBits` | `pub fn qrComputeBchFormatBits(ecLevel: int, maskPattern: int): int:` | `tests/functions/encoding/qrcode_semver_test.aipl` |
| `200` | `std/encoding/qrcode_semver.aipl` | `encodeQrCode` | `pub fn encodeQrCode(text: str): QrMatrix:` | `tests/functions/encoding/qrcode_semver_test.aipl` |
| `201` | `std/encoding/qrcode_semver.aipl` | `qrToAscii` | `pub fn qrToAscii(matrix: QrMatrix): str:` | `tests/functions/encoding/qrcode_semver_test.aipl` |
| `202` | `std/encoding/qrcode_semver.aipl` | `qrToSvg` | `pub fn qrToSvg(matrix: QrMatrix, scale: int = 4): str:` | `tests/functions/encoding/qrcode_semver_test.aipl` |
| `203` | `std/encoding/qrcode_semver.aipl` | `parseSemver` | `pub fn parseSemver(text: str): Result[SemVer, str]:` | `tests/functions/encoding/qrcode_semver_test.aipl` |
| `204` | `std/encoding/qrcode_semver.aipl` | `formatSemver` | `pub fn formatSemver(v: SemVer): str:` | `tests/functions/encoding/qrcode_semver_test.aipl` |
| `205` | `std/encoding/qrcode_semver.aipl` | `compareSemver` | `pub fn compareSemver(a: SemVer, b: SemVer): int:` | `tests/functions/encoding/qrcode_semver_test.aipl` |
| `206` | `std/encoding/qrcode_semver.aipl` | `bumpMajor` | `pub fn bumpMajor(v: SemVer): SemVer:` | `tests/functions/encoding/qrcode_semver_test.aipl` |
| `207` | `std/encoding/qrcode_semver.aipl` | `bumpMinor` | `pub fn bumpMinor(v: SemVer): SemVer:` | `tests/functions/encoding/qrcode_semver_test.aipl` |
| `208` | `std/encoding/qrcode_semver.aipl` | `bumpPatch` | `pub fn bumpPatch(v: SemVer): SemVer:` | `tests/functions/encoding/qrcode_semver_test.aipl` |
| `209` | `std/encoding/qrcode_semver.aipl` | `bumpSemver` | `pub fn bumpSemver(v: SemVer, part: str): SemVer:` | `tests/functions/encoding/qrcode_semver_test.aipl` |
| `210` | `std/encoding/qrcode_semver.aipl` | `satisfiesRange` | `pub fn satisfiesRange(v: SemVer, rangeStr: str): bool:` | `tests/functions/encoding/qrcode_semver_test.aipl` |
| `211` | `std/encoding/toml.aipl` | `tomlStrVal` | `fn tomlStrVal(s: str): TomlValue:` | `tests/functions/encoding/toml_test.aipl` |
| `212` | `std/encoding/toml.aipl` | `tomlIntVal` | `fn tomlIntVal(n: int): TomlValue:` | `tests/functions/encoding/toml_test.aipl` |
| `213` | `std/encoding/toml.aipl` | `tomlFloatVal` | `fn tomlFloatVal(f: float): TomlValue:` | `tests/functions/encoding/toml_test.aipl` |
| `214` | `std/encoding/toml.aipl` | `tomlBoolVal` | `fn tomlBoolVal(b: bool): TomlValue:` | `tests/functions/encoding/toml_test.aipl` |
| `215` | `std/encoding/toml.aipl` | `tomlListVal` | `fn tomlListVal(items: [TomlValue]): TomlValue:` | `tests/functions/encoding/toml_test.aipl` |
| `216` | `std/encoding/toml.aipl` | `stripTomlComment` | `fn stripTomlComment(line: str): str:` | `tests/functions/encoding/toml_test.aipl` |
| `217` | `std/encoding/toml.aipl` | `parseTomlScalar` | `fn parseTomlScalar(raw: str): TomlValue:` | `tests/functions/encoding/toml_test.aipl` |
| `218` | `std/encoding/toml.aipl` | `parseToml` | `pub fn parseToml(text: str): Result[TomlDocument, str]:` | `tests/functions/encoding/toml_test.aipl` |
| `219` | `std/encoding/toml.aipl` | `getString` | `pub fn (self: TomlDocument) getString(key: str): Option[str]:` | `tests/functions/encoding/toml_test.aipl` |
| `220` | `std/encoding/toml.aipl` | `getInt` | `pub fn (self: TomlDocument) getInt(key: str): Option[int]:` | `tests/functions/encoding/toml_test.aipl` |
| `221` | `std/encoding/toml.aipl` | `getBool` | `pub fn (self: TomlDocument) getBool(key: str): Option[bool]:` | `tests/functions/encoding/toml_test.aipl` |
| `222` | `std/encoding/toml.aipl` | `formatTomlValue` | `fn formatTomlValue(v: TomlValue): str:` | `tests/functions/encoding/toml_test.aipl` |
| `223` | `std/encoding/toml.aipl` | `serializeToml` | `pub fn serializeToml(doc: TomlDocument): str:` | `tests/functions/encoding/toml_test.aipl` |
| `224` | `std/encoding/toml.aipl` | `tomlGetFloat` | `pub fn tomlGetFloat(doc: TomlDocument, key: str): Option[float]:` | `tests/functions/encoding/toml_test.aipl` |
| `225` | `std/encoding/toml.aipl` | `parseTomlSection` | `pub fn parseTomlSection(src: str, section: str): Map[str, str]:` | `tests/functions/encoding/toml_test.aipl` |
| `226` | `std/encoding/toml.aipl` | `parseTomlSections` | `pub fn parseTomlSections(src: str): [str]:` | `tests/functions/encoding/toml_test.aipl` |
| `227` | `std/encoding/toml.aipl` | `getTomlValue` | `pub fn getTomlValue(src: str, section: str, key: str, defaultVal: str): str:` | `tests/functions/encoding/toml_test.aipl` |
| `228` | `std/encoding/toml.aipl` | `toToml` | `pub fn toToml(section: str, m: Map[str, str]): str:` | `tests/functions/encoding/toml_test.aipl` |
| `229` | `std/encoding/xml.aipl` | `decodeXmlEntities` | `pub fn decodeXmlEntities(s: str): str:` | `tests/functions/encoding/xml_test.aipl` |
| `230` | `std/encoding/xml.aipl` | `encodeXmlEntities` | `pub fn encodeXmlEntities(s: str): str:` | `tests/functions/encoding/xml_test.aipl` |
| `231` | `std/encoding/xml.aipl` | `parseXmlAttributes` | `fn parseXmlAttributes(header: str): [XmlAttribute]:` | `tests/functions/encoding/xml_test.aipl` |
| `232` | `std/encoding/xml.aipl` | `parseXmlNodeAt` | `fn parseXmlNodeAt(text: str, startPos: int): (int, XmlNode, str):` | `tests/functions/encoding/xml_test.aipl` |
| `233` | `std/encoding/xml.aipl` | `parseXml` | `pub fn parseXml(text: str): Result[XmlDocument, str]:` | `tests/functions/encoding/xml_test.aipl` |
| `234` | `std/encoding/xml.aipl` | `serializeXmlNode` | `fn serializeXmlNode(node: XmlNode, pretty: bool, depth: int): str:` | `tests/functions/encoding/xml_test.aipl` |
| `235` | `std/encoding/xml.aipl` | `serializeXml` | `pub fn serializeXml(doc: XmlDocument, pretty: bool = false): str:` | `tests/functions/encoding/xml_test.aipl` |
| `236` | `std/encoding/xml.aipl` | `findChild` | `pub fn (self: XmlNode) findChild(tag: str): Option[XmlNode]:` | `tests/functions/encoding/xml_test.aipl` |
| `237` | `std/encoding/xml.aipl` | `getAttr` | `pub fn (self: XmlNode) getAttr(name: str): Option[str]:` | `tests/functions/encoding/xml_test.aipl` |
| `238` | `std/encoding/xml.aipl` | `escapeXml` | `pub fn escapeXml(s: str): str:` | `tests/functions/encoding/xml_test.aipl` |
| `239` | `std/encoding/xml.aipl` | `unescapeXml` | `pub fn unescapeXml(s: str): str:` | `tests/functions/encoding/xml_test.aipl` |
| `240` | `std/encoding/xml.aipl` | `collectXmlElements` | `fn collectXmlElements(node: XmlNode, tagName: str, mut acc: [XmlNode]): [XmlNode]:` | `tests/functions/encoding/xml_test.aipl` |
| `241` | `std/encoding/xml.aipl` | `xmlFindElements` | `pub fn xmlFindElements(node: XmlNode, tagName: str): [XmlNode]:` | `tests/functions/encoding/xml_test.aipl` |
| `242` | `std/encoding/xml.aipl` | `xmlFindAll` | `pub fn xmlFindAll(doc: XmlDocument, tagName: str): [XmlNode]:` | `tests/functions/encoding/xml_test.aipl` |
| `243` | `std/encoding/xml.aipl` | `xmlText` | `pub fn xmlText(node: XmlNode): str:` | `tests/functions/encoding/xml_test.aipl` |
| `244` | `std/encoding/xml.aipl` | `xmlAttr` | `pub fn xmlAttr(node: XmlNode, name: str): Option[str]:` | `tests/functions/encoding/xml_test.aipl` |
| `245` | `std/encoding/xml.aipl` | `formatXml` | `pub fn formatXml(doc: XmlDocument): str:` | `tests/functions/encoding/xml_test.aipl` |
| `246` | `std/encoding/xml.aipl` | `stringifyXml` | `pub fn stringifyXml(doc: XmlDocument): str:` | `tests/functions/encoding/xml_test.aipl` |
| `247` | `std/encoding/xml.aipl` | `toXml` | `pub fn toXml(doc: XmlDocument): str:` | `tests/functions/encoding/xml_test.aipl` |
| `248` | `std/encoding/yaml.aipl` | `yamlScalar` | `fn yamlScalar(s: str): YamlNode:` | `tests/functions/encoding/yaml_test.aipl` |
| `249` | `std/encoding/yaml.aipl` | `yamlSequence` | `fn yamlSequence(items: [YamlNode]): YamlNode:` | `tests/functions/encoding/yaml_test.aipl` |
| `250` | `std/encoding/yaml.aipl` | `yamlMapping` | `fn yamlMapping(entries: [(str, YamlNode)]): YamlNode:` | `tests/functions/encoding/yaml_test.aipl` |
| `251` | `std/encoding/yaml.aipl` | `countLeadingSpaces` | `fn countLeadingSpaces(line: str): int:` | `tests/functions/encoding/yaml_test.aipl` |
| `252` | `std/encoding/yaml.aipl` | `cleanYamlScalarText` | `fn cleanYamlScalarText(raw: str): str:` | `tests/functions/encoding/yaml_test.aipl` |
| `253` | `std/encoding/yaml.aipl` | `parseYamlLines` | `fn parseYamlLines(lines: [str], startIdx: int, minIndent: int): (int, YamlNode):` | `tests/functions/encoding/yaml_test.aipl` |
| `254` | `std/encoding/yaml.aipl` | `parseYaml` | `pub fn parseYaml(text: str): Result[YamlNode, str]:` | `tests/functions/encoding/yaml_test.aipl` |
| `255` | `std/encoding/yaml.aipl` | `makeYamlPad` | `fn makeYamlPad(spaces: int): str:` | `tests/functions/encoding/yaml_test.aipl` |
| `256` | `std/encoding/yaml.aipl` | `serializeYamlDepth` | `fn serializeYamlDepth(node: YamlNode, indentStep: int, depth: int): str:` | `tests/functions/encoding/yaml_test.aipl` |
| `257` | `std/encoding/yaml.aipl` | `serializeYaml` | `pub fn serializeYaml(node: YamlNode, indent: int = 2): str:` | `tests/functions/encoding/yaml_test.aipl` |
| `258` | `std/encoding/yaml.aipl` | `parseYamlEntries` | `pub fn parseYamlEntries(src: str): [YamlEntry]:` | `tests/functions/encoding/yaml_test.aipl` |
| `259` | `std/encoding/yaml.aipl` | `parseYamlMap` | `pub fn parseYamlMap(src: str): Map[str, str]:` | `tests/functions/encoding/yaml_test.aipl` |
| `260` | `std/encoding/yaml.aipl` | `getYamlValue` | `pub fn getYamlValue(src: str, key: str, defaultVal: str): str:` | `tests/functions/encoding/yaml_test.aipl` |
| `261` | `std/encoding/yaml.aipl` | `parseYamlList` | `pub fn parseYamlList(src: str): [str]:` | `tests/functions/encoding/yaml_test.aipl` |
| `262` | `std/encoding/yaml.aipl` | `toYamlMap` | `pub fn toYamlMap(m: Map[str, str]): str:` | `tests/functions/encoding/yaml_test.aipl` |
| `263` | `std/encoding/yaml.aipl` | `toYamlList` | `pub fn toYamlList(items: [str]): str:` | `tests/functions/encoding/yaml_test.aipl` |
| `264` | `std/encoding/yaml.aipl` | `yamlNodeToJsonStr` | `fn yamlNodeToJsonStr(node: YamlNode): str:` | `tests/functions/encoding/yaml_test.aipl` |
| `265` | `std/encoding/yaml.aipl` | `yamlToJson` | `pub fn yamlToJson(src: str): str:` | `tests/functions/encoding/yaml_test.aipl` |
| `266` | `std/encoding/axml_manifest.aipl` | `patchAxmlPackageName` | `pub fn patchAxmlPackageName(rawPackageId: str): Result[(str, int), str]:` | `tests/functions/encoding/axml_manifest_test.aipl` |
| `267` | `std/encoding/axml_manifest.aipl` | `patchAxmlAppLabel` | `pub fn patchAxmlAppLabel(baseAxmlSizeBytes: int, oldLabel: str, newLabel: str): (str, int):` | `tests/functions/encoding/axml_manifest_test.aipl` |
| `268` | `std/encoding/axml_manifest.aipl` | `patchAxmlVersionCode` | `pub fn patchAxmlVersionCode(versionCode: int, versionName: str): (int, str, [int]):` | `tests/functions/encoding/axml_manifest_test.aipl` |
| `269` | `std/encoding/axml_manifest.aipl` | `patchAxmlScreenOrientation` | `pub fn patchAxmlScreenOrientation(orientationMode: str): int:` | `tests/functions/encoding/axml_manifest_test.aipl` |

---

## 4. Detailed API Reference & Runnable Verification Snippets

### `b64CharVal` (`std/encoding/base64.aipl`)

- **Signature**: `fn b64CharVal(code: int, urlSafe: bool): int:`
- **Import**: `import * from "std/encoding/base64"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `code: int, urlSafe: bool` | **Returns**: `int`
- **Unit Test**: `tests/functions/encoding/base64_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `b64CharVal` RFC 4648 Base64 / Base64URL / Base62 / Crockford Base32 / RFC 3986 URL percent-encoding round-trips across 1-, 2-, and 3-byte padding boundaries. Concrete nominal inputs: `code: int = 1`, `urlSafe: bool = true`; exercises core body path returning/computing `-1`.

```aipl
module tests.functions.encoding.base64_z1_test
import * from "std/encoding/base64"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_base64_b64CharVal_1(): int:
  let arg_code = 2
  let edge_code = 0
  let arg_urlSafe = true
  let edge_urlSafe = false
  let resNom = b64CharVal(arg_code, arg_urlSafe)
  let resEdge = b64CharVal(edge_code, edge_urlSafe)
  assertEqInt(resNom, -1, "b64CharVal nominal resNom == -1")
  assertEqInt(resEdge, -1, "b64CharVal boundary resEdge == -1")
  ret 0
```

---

### `base64Encode` (`std/encoding/base64.aipl`)

- **Signature**: `pub fn base64Encode(data: bytes): str:`
- **Import**: `import * from "std/encoding/base64"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/base64_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `base64Encode` RFC 4648 Base64 / Base64URL / Base62 / Crockford Base32 / RFC 3986 URL percent-encoding round-trips across 1-, 2-, and 3-byte padding boundaries. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `out.join("")`.

```aipl
module tests.functions.encoding.base64_z2_test
import * from "std/encoding/base64"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_base64_base64Encode_2(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let resNom = base64Encode(arg_data)
  let resEdge = base64Encode(edge_data)
  assertEqStr(resNom, "QUlQTA==", "base64Encode nominal string matches")
  assertEqStr(resEdge, "QQ==", "base64Encode boundary string matches")
  ret 0
```

---

### `base64Decode` (`std/encoding/base64.aipl`)

- **Signature**: `pub fn base64Decode(s: str): Result[bytes, str]:`
- **Import**: `import * from "std/encoding/base64"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `Result[bytes, str]`
- **Unit Test**: `tests/functions/encoding/base64_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `base64Decode` RFC 4648 Base64 / Base64URL / Base62 / Crockford Base32 / RFC 3986 URL percent-encoding round-trips across 1-, 2-, and 3-byte padding boundaries. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `Ok(bytesFromArray(out))`.

```aipl
module tests.functions.encoding.base64_z3_test
import * from "std/encoding/base64"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_base64_base64Decode_3(): int:
  let arg_s = "QUJD"
  let edge_s = ""
  let resNom = base64Decode(arg_s)
  let resEdge = base64Decode(edge_s)
  assert(resNom.isOk() == true, "base64Decode nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "base64Decode boundary resEdge.isOk() == true")
  ret 0
```

---

### `base64UrlEncode` (`std/encoding/base64.aipl`)

- **Signature**: `pub fn base64UrlEncode(data: bytes): str:`
- **Import**: `import * from "std/encoding/base64"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/base64_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `base64UrlEncode` RFC 4648 Base64 / Base64URL / Base62 / Crockford Base32 / RFC 3986 URL percent-encoding round-trips across 1-, 2-, and 3-byte padding boundaries. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `out.join("")`.

```aipl
module tests.functions.encoding.base64_z4_test
import * from "std/encoding/base64"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_base64_base64UrlEncode_4(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let resNom = base64UrlEncode(arg_data)
  let resEdge = base64UrlEncode(edge_data)
  assertEqStr(resNom, "QUlQTA", "base64UrlEncode nominal string matches")
  assertEqStr(resEdge, "QQ", "base64UrlEncode boundary string matches")
  ret 0
```

---

### `base64UrlDecode` (`std/encoding/base64.aipl`)

- **Signature**: `pub fn base64UrlDecode(s: str): Result[bytes, str]:`
- **Import**: `import * from "std/encoding/base64"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `Result[bytes, str]`
- **Unit Test**: `tests/functions/encoding/base64_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `base64UrlDecode` RFC 4648 Base64 / Base64URL / Base62 / Crockford Base32 / RFC 3986 URL percent-encoding round-trips across 1-, 2-, and 3-byte padding boundaries. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `Ok(bytesFromArray(out))`.

```aipl
module tests.functions.encoding.base64_z5_test
import * from "std/encoding/base64"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_base64_base64UrlDecode_5(): int:
  let arg_s = "http://localhost/test"
  let edge_s = "http://localhost/test"
  let resNom = base64UrlDecode(arg_s)
  let resEdge = base64UrlDecode(edge_s)
  assert(resNom.isOk() == false, "base64UrlDecode nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "base64UrlDecode boundary resEdge.isOk() == false")
  ret 0
```

---

### `base62Encode` (`std/encoding/base64.aipl`)

- **Signature**: `pub fn base62Encode(n: int): str:`
- **Import**: `import * from "std/encoding/base64"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `n: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/base64_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `base62Encode` RFC 4648 Base64 / Base64URL / Base62 / Crockford Base32 / RFC 3986 URL percent-encoding round-trips across 1-, 2-, and 3-byte padding boundaries. Concrete nominal inputs: `n: int = 1`; exercises core body path returning/computing `rev.join("")`.

```aipl
module tests.functions.encoding.base64_z6_test
import * from "std/encoding/base64"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_base64_base62Encode_6(): int:
  let arg_n = 4
  let edge_n = 1
  let resNom = base62Encode(arg_n)
  let resEdge = base62Encode(edge_n)
  assertEqStr(resNom, "4", "base62Encode nominal string matches")
  assertEqStr(resEdge, "1", "base62Encode boundary string matches")
  ret 0
```

---

### `base62Decode` (`std/encoding/base64.aipl`)

- **Signature**: `pub fn base62Decode(s: str): Result[int, str]:`
- **Import**: `import * from "std/encoding/base64"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `Result[int, str]`
- **Unit Test**: `tests/functions/encoding/base64_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `base62Decode` RFC 4648 Base64 / Base64URL / Base62 / Crockford Base32 / RFC 3986 URL percent-encoding round-trips across 1-, 2-, and 3-byte padding boundaries. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `Ok(acc)`.

```aipl
module tests.functions.encoding.base64_z7_test
import * from "std/encoding/base64"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_base64_base62Decode_7(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = base62Decode(arg_s)
  let resEdge = base62Decode(edge_s)
  assert(resNom.isOk() == true, "base62Decode nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "base62Decode boundary resEdge.isOk() == true")
  ret 0
```

---

### `crockfordBase32Encode` (`std/encoding/base64.aipl`)

- **Signature**: `pub fn crockfordBase32Encode(data: bytes): str:`
- **Import**: `import * from "std/encoding/base64"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/base64_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `crockfordBase32Encode` RFC 4648 Base64 / Base64URL / Base62 / Crockford Base32 / RFC 3986 URL percent-encoding round-trips across 1-, 2-, and 3-byte padding boundaries. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `out.join("")`.

```aipl
module tests.functions.encoding.base64_z8_test
import * from "std/encoding/base64"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_base64_crockfordBase32Encode_8(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let resNom = crockfordBase32Encode(arg_data)
  let resEdge = crockfordBase32Encode(edge_data)
  assertEqStr(resNom, "854N0K0", "crockfordBase32Encode nominal string matches")
  assertEqStr(resEdge, "84", "crockfordBase32Encode boundary string matches")
  ret 0
```

---

### `crockfordCharVal` (`std/encoding/base64.aipl`)

- **Signature**: `fn crockfordCharVal(code: int): int:`
- **Import**: `import * from "std/encoding/base64"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `code: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/encoding/base64_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `crockfordCharVal` RFC 4648 Base64 / Base64URL / Base62 / Crockford Base32 / RFC 3986 URL percent-encoding round-trips across 1-, 2-, and 3-byte padding boundaries. Concrete nominal inputs: `code: int = 1`; exercises core body path returning/computing `CROCKFORD_ALPHABET.indexOf(ch)`.

```aipl
module tests.functions.encoding.base64_z9_test
import * from "std/encoding/base64"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_base64_crockfordCharVal_9(): int:
  let arg_code = 2
  let edge_code = 0
  let resNom = crockfordCharVal(arg_code)
  let resEdge = crockfordCharVal(edge_code)
  assertEqInt(resNom, -1, "crockfordCharVal nominal resNom == -1")
  assertEqInt(resEdge, -1, "crockfordCharVal boundary resEdge == -1")
  ret 0
```

---

### `crockfordBase32Decode` (`std/encoding/base64.aipl`)

- **Signature**: `pub fn crockfordBase32Decode(s: str): Result[bytes, str]:`
- **Import**: `import * from "std/encoding/base64"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `Result[bytes, str]`
- **Unit Test**: `tests/functions/encoding/base64_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `crockfordBase32Decode` RFC 4648 Base64 / Base64URL / Base62 / Crockford Base32 / RFC 3986 URL percent-encoding round-trips across 1-, 2-, and 3-byte padding boundaries. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `Ok(bytesFromArray(out))`.

```aipl
module tests.functions.encoding.base64_z10_test
import * from "std/encoding/base64"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_base64_crockfordBase32Decode_10(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = crockfordBase32Decode(arg_s)
  let resEdge = crockfordBase32Decode(edge_s)
  assert(resNom.isOk() == true, "crockfordBase32Decode nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "crockfordBase32Decode boundary resEdge.isOk() == true")
  ret 0
```

---

### `isUnreservedUrlByte` (`std/encoding/base64.aipl`)

- **Signature**: `fn isUnreservedUrlByte(b: int): bool:`
- **Import**: `import * from "std/encoding/base64"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `b: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/encoding/base64_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `isUnreservedUrlByte` RFC 4648 Base64 / Base64URL / Base62 / Crockford Base32 / RFC 3986 URL percent-encoding round-trips across 1-, 2-, and 3-byte padding boundaries. Concrete nominal inputs: `b: int = 1`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.encoding.base64_z11_test
import * from "std/encoding/base64"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_base64_isUnreservedUrlByte_11(): int:
  let arg_b = 4
  let edge_b = 1
  let resNom = isUnreservedUrlByte(arg_b)
  let resEdge = isUnreservedUrlByte(edge_b)
  assert(resNom == false, "isUnreservedUrlByte nominal resNom == false")
  assert(resEdge == false, "isUnreservedUrlByte boundary resEdge == false")
  ret 0
```

---

### `urlPercentEncode` (`std/encoding/base64.aipl`)

- **Signature**: `pub fn urlPercentEncode(s: str): str:`
- **Import**: `import * from "std/encoding/base64"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/base64_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `urlPercentEncode` RFC 4648 Base64 / Base64URL / Base62 / Crockford Base32 / RFC 3986 URL percent-encoding round-trips across 1-, 2-, and 3-byte padding boundaries. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `out.join("")`.

```aipl
module tests.functions.encoding.base64_z12_test
import * from "std/encoding/base64"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_base64_urlPercentEncode_12(): int:
  let arg_s = "http://localhost/test"
  let edge_s = "http://localhost/test"
  let resNom = urlPercentEncode(arg_s)
  let resEdge = urlPercentEncode(edge_s)
  assertEqStr(resNom, "http%3A%2F%2Flocalhost%2Ftest", "urlPercentEncode nominal string matches")
  assertEqStr(resEdge, "http%3A%2F%2Flocalhost%2Ftest", "urlPercentEncode boundary string matches")
  ret 0
```

---

### `urlPercentDecode` (`std/encoding/base64.aipl`)

- **Signature**: `pub fn urlPercentDecode(s: str): Result[str, str]:`
- **Import**: `import * from "std/encoding/base64"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `Result[str, str]`
- **Unit Test**: `tests/functions/encoding/base64_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `urlPercentDecode` RFC 4648 Base64 / Base64URL / Base62 / Crockford Base32 / RFC 3986 URL percent-encoding round-trips across 1-, 2-, and 3-byte padding boundaries. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `Ok(bytesFromArray(bytesArr).toStringLossy())`.

```aipl
module tests.functions.encoding.base64_z13_test
import * from "std/encoding/base64"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_base64_urlPercentDecode_13(): int:
  let arg_s = "http://localhost/test"
  let edge_s = "http://localhost/test"
  let resNom = urlPercentDecode(arg_s)
  let resEdge = urlPercentDecode(edge_s)
  assert(resNom.isOk() == true, "urlPercentDecode nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "urlPercentDecode boundary resEdge.isOk() == true")
  ret 0
```

---

### `base62DecodeResult` (`std/encoding/base64.aipl`)

- **Signature**: `pub fn base62DecodeResult(s: str): Result[int, str]:`
- **Import**: `import * from "std/encoding/base64"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `Result[int, str]`
- **Unit Test**: `tests/functions/encoding/base64_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `base62DecodeResult` RFC 4648 Base64 / Base64URL / Base62 / Crockford Base32 / RFC 3986 URL percent-encoding round-trips across 1-, 2-, and 3-byte padding boundaries. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `base62Decode(s)`.

```aipl
module tests.functions.encoding.base64_z14_test
import * from "std/encoding/base64"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_base64_base62DecodeResult_14(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = base62DecodeResult(arg_s)
  let resEdge = base62DecodeResult(edge_s)
  assert(resNom.isOk() == true, "base62DecodeResult nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "base62DecodeResult boundary resEdge.isOk() == true")
  ret 0
```

---

### `urlEncode` (`std/encoding/base64.aipl`)

- **Signature**: `pub fn urlEncode(s: str): str:`
- **Import**: `import * from "std/encoding/base64"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/base64_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `urlEncode` RFC 4648 Base64 / Base64URL / Base62 / Crockford Base32 / RFC 3986 URL percent-encoding round-trips across 1-, 2-, and 3-byte padding boundaries. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `urlPercentEncode(s)`.

```aipl
module tests.functions.encoding.base64_z15_test
import * from "std/encoding/base64"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_base64_urlEncode_15(): int:
  let arg_s = "http://localhost/test"
  let edge_s = "http://localhost/test"
  let resNom = urlEncode(arg_s)
  let resEdge = urlEncode(edge_s)
  assertEqStr(resNom, "http%3A%2F%2Flocalhost%2Ftest", "urlEncode nominal string matches")
  assertEqStr(resEdge, "http%3A%2F%2Flocalhost%2Ftest", "urlEncode boundary string matches")
  ret 0
```

---

### `urlDecode` (`std/encoding/base64.aipl`)

- **Signature**: `pub fn urlDecode(s: str): Result[str, str]:`
- **Import**: `import * from "std/encoding/base64"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `Result[str, str]`
- **Unit Test**: `tests/functions/encoding/base64_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `urlDecode` RFC 4648 Base64 / Base64URL / Base62 / Crockford Base32 / RFC 3986 URL percent-encoding round-trips across 1-, 2-, and 3-byte padding boundaries. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `urlPercentDecode(s)`.

```aipl
module tests.functions.encoding.base64_z16_test
import * from "std/encoding/base64"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_base64_urlDecode_16(): int:
  let arg_s = "http://localhost/test"
  let edge_s = "http://localhost/test"
  let resNom = urlDecode(arg_s)
  let resEdge = urlDecode(edge_s)
  assert(resNom.isOk() == true, "urlDecode nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "urlDecode boundary resEdge.isOk() == true")
  ret 0
```

---

### `base64EncodeStr` (`std/encoding/base64.aipl`)

- **Signature**: `pub fn base64EncodeStr(s: str): str:`
- **Import**: `import * from "std/encoding/base64"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/base64_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `base64EncodeStr` RFC 4648 Base64 / Base64URL / Base62 / Crockford Base32 / RFC 3986 URL percent-encoding round-trips across 1-, 2-, and 3-byte padding boundaries. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `base64Encode(s.toBytes())`.

```aipl
module tests.functions.encoding.base64_z17_test
import * from "std/encoding/base64"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_base64_base64EncodeStr_17(): int:
  let arg_s = "QUJD"
  let edge_s = ""
  let resNom = base64EncodeStr(arg_s)
  let resEdge = base64EncodeStr(edge_s)
  assertEqStr(resNom, "UVVKRA==", "base64EncodeStr nominal string matches")
  assertEqStr(resEdge, "", "base64EncodeStr boundary string matches")
  ret 0
```

---

### `base64DecodeStr` (`std/encoding/base64.aipl`)

- **Signature**: `pub fn base64DecodeStr(s: str): Result[str, str]:`
- **Import**: `import * from "std/encoding/base64"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `Result[str, str]`
- **Unit Test**: `tests/functions/encoding/base64_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `base64DecodeStr` RFC 4648 Base64 / Base64URL / Base62 / Crockford Base32 / RFC 3986 URL percent-encoding round-trips across 1-, 2-, and 3-byte padding boundaries. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `Ok(res.unwrap().toStringLossy())`.

```aipl
module tests.functions.encoding.base64_z18_test
import * from "std/encoding/base64"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_base64_base64DecodeStr_18(): int:
  let arg_s = "QUJD"
  let edge_s = ""
  let resNom = base64DecodeStr(arg_s)
  let resEdge = base64DecodeStr(edge_s)
  assert(resNom.isOk() == true, "base64DecodeStr nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "base64DecodeStr boundary resEdge.isOk() == true")
  ret 0
```

---

### `bincodeWriterNew` (`std/encoding/bincode.aipl`)

- **Signature**: `pub fn bincodeWriterNew(initialCapacity: int = 128, littleEndian: bool = true): BincodeWriter:`
- **Import**: `import * from "std/encoding/bincode"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `initialCapacity: int = 128, littleEndian: bool = true` | **Returns**: `BincodeWriter`
- **Unit Test**: `tests/functions/encoding/bincode_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `bincodeWriterNew` (`free fn`) binary wire packing/unpacking across `u8`, `i32`, `i64`, IEEE-754 `f32`/`f64`, LEB128 varints, bitstreams, and length-prefixed UTF-8 strings. Concrete nominal inputs: `initialCapacity: int = 64`, `littleEndian: bool = true`; exercises core body path returning/computing `BincodeWriter(`.

```aipl
module tests.functions.encoding.bincode_z1_test
import * from "std/encoding/bincode"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bincode_bincodeWriterNew_1(): int:
  let arg_initialCapacity = 4
  let edge_initialCapacity = 1
  let arg_littleEndian = true
  let edge_littleEndian = false
  let resNom = bincodeWriterNew(arg_initialCapacity, arg_littleEndian)
  let resEdge = bincodeWriterNew(edge_initialCapacity, edge_littleEndian)
  assertEqInt(resNom.buffer.len(), 4, "bincodeWriterNew nominal resNom.buffer.len() == 4")
  assertEqInt(resEdge.buffer.len(), 1, "bincodeWriterNew boundary resEdge.buffer.len() == 1")
  ret 0
```

---

### `writeU8` (`std/encoding/bincode.aipl`)

- **Signature**: `pub fn (mut self: BincodeWriter) writeU8(val: int): void:`
- **Import**: `import * from "std/encoding/bincode"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `mut self: BincodeWriter` | **Parameters**: `val: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/encoding/bincode_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `writeU8` (`mut self: BincodeWriter`) binary wire packing/unpacking across `u8`, `i32`, `i64`, IEEE-754 `f32`/`f64`, LEB128 varints, bitstreams, and length-prefixed UTF-8 strings. Concrete nominal inputs: receiver `recvObj: BincodeWriter = BincodeWriter(buffer = [65, 73, 80, 76], offset = 0, littleEndian = true)`, `val: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.encoding.bincode_z2_test
import * from "std/encoding/bincode"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bincode_BincodeWriter_writeU8_2(): int:
  let mut recv_self = BincodeWriter(buffer = [65, 73, 80, 76], offset = 0, littleEndian = true, data = [])
  let mut edge_self = BincodeWriter(buffer = [65], offset = 0, littleEndian = false, data = [])
  let arg_val = 2
  let edge_val = 0
  recv_self.writeU8(arg_val)
  edge_self.writeU8(edge_val)
  assertEqInt(recv_self.offset, 1, "writeU8 nominal recv_self.offset == 1")
  assertEqInt(edge_self.offset, 1, "writeU8 boundary edge_self.offset == 1")
  ret 0
```

---

### `writeI32` (`std/encoding/bincode.aipl`)

- **Signature**: `pub fn (mut self: BincodeWriter) writeI32(val: int): void:`
- **Import**: `import * from "std/encoding/bincode"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `mut self: BincodeWriter` | **Parameters**: `val: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/encoding/bincode_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `writeI32` (`mut self: BincodeWriter`) binary wire packing/unpacking across `u8`, `i32`, `i64`, IEEE-754 `f32`/`f64`, LEB128 varints, bitstreams, and length-prefixed UTF-8 strings. Concrete nominal inputs: receiver `recvObj: BincodeWriter = BincodeWriter(buffer = [65, 73, 80, 76], offset = 0, littleEndian = true)`, `val: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.encoding.bincode_z3_test
import * from "std/encoding/bincode"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bincode_BincodeWriter_writeI32_3(): int:
  let mut recv_self = BincodeWriter(buffer = [65, 73, 80, 76], offset = 0, littleEndian = true, data = [])
  let mut edge_self = BincodeWriter(buffer = [65], offset = 0, littleEndian = false, data = [])
  let arg_val = 2
  let edge_val = 0
  recv_self.writeI32(arg_val)
  edge_self.writeI32(edge_val)
  assertEqInt(recv_self.offset, 4, "writeI32 nominal recv_self.offset == 4")
  assertEqInt(edge_self.offset, 4, "writeI32 boundary edge_self.offset == 4")
  ret 0
```

---

### `writeI64` (`std/encoding/bincode.aipl`)

- **Signature**: `pub fn (mut self: BincodeWriter) writeI64(val: int): void:`
- **Import**: `import * from "std/encoding/bincode"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `mut self: BincodeWriter` | **Parameters**: `val: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/encoding/bincode_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `writeI64` (`mut self: BincodeWriter`) binary wire packing/unpacking across `u8`, `i32`, `i64`, IEEE-754 `f32`/`f64`, LEB128 varints, bitstreams, and length-prefixed UTF-8 strings. Concrete nominal inputs: receiver `recvObj: BincodeWriter = BincodeWriter(buffer = [65, 73, 80, 76], offset = 0, littleEndian = true)`, `val: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.encoding.bincode_z4_test
import * from "std/encoding/bincode"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bincode_BincodeWriter_writeI64_4(): int:
  let mut recv_self = BincodeWriter(buffer = [65, 73, 80, 76], offset = 0, littleEndian = true, data = [])
  let mut edge_self = BincodeWriter(buffer = [65], offset = 0, littleEndian = false, data = [])
  let arg_val = 2
  let edge_val = 0
  recv_self.writeI64(arg_val)
  edge_self.writeI64(edge_val)
  assertEqInt(recv_self.offset, 8, "writeI64 nominal recv_self.offset == 8")
  assertEqInt(edge_self.offset, 8, "writeI64 boundary edge_self.offset == 8")
  ret 0
```

---

### `f64ToF32Bits` (`std/encoding/bincode.aipl`)

- **Signature**: `fn f64ToF32Bits(val: float): int:`
- **Import**: `import * from "std/encoding/bincode"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: float` | **Returns**: `int`
- **Unit Test**: `tests/functions/encoding/bincode_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `f64ToF32Bits` (`free fn`) binary wire packing/unpacking across `u8`, `i32`, `i64`, IEEE-754 `f32`/`f64`, LEB128 varints, bitstreams, and length-prefixed UTF-8 strings. Concrete nominal inputs: `val: float = 1.0`; exercises core body path returning/computing `(sign << 31) | (exp32 << 23) | (mant32 & 8388607)`.

```aipl
module tests.functions.encoding.bincode_z5_test
import * from "std/encoding/bincode"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bincode_f64ToF32Bits_5(): int:
  let arg_val = 1.0
  let edge_val = 0.5
  let resNom = f64ToF32Bits(arg_val)
  let resEdge = f64ToF32Bits(edge_val)
  assertEqInt(resNom, 1065353216, "f64ToF32Bits nominal resNom == 1065353216")
  assertEqInt(resEdge, 1056964608, "f64ToF32Bits boundary resEdge == 1056964608")
  ret 0
```

---

### `f32BitsToF64` (`std/encoding/bincode.aipl`)

- **Signature**: `fn f32BitsToF64(bits32: int): float:`
- **Import**: `import * from "std/encoding/bincode"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bits32: int` | **Returns**: `float`
- **Unit Test**: `tests/functions/encoding/bincode_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `f32BitsToF64` (`free fn`) binary wire packing/unpacking across `u8`, `i32`, `i64`, IEEE-754 `f32`/`f64`, LEB128 varints, bitstreams, and length-prefixed UTF-8 strings. Concrete nominal inputs: `bits32: int = 1`; exercises core body path returning/computing `bitcastI64ToF64(bits64)`.

```aipl
module tests.functions.encoding.bincode_z6_test
import * from "std/encoding/bincode"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bincode_f32BitsToF64_6(): int:
  let arg_bits32 = 4
  let edge_bits32 = 1
  let resNom = f32BitsToF64(arg_bits32)
  let resEdge = f32BitsToF64(edge_bits32)
  assertApproxEq(resNom, 0.0, 0.001, "f32BitsToF64 nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "f32BitsToF64 boundary resEdge ~= 0.0")
  ret 0
```

---

### `writeF32` (`std/encoding/bincode.aipl`)

- **Signature**: `pub fn (mut self: BincodeWriter) writeF32(val: float): void:`
- **Import**: `import * from "std/encoding/bincode"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `mut self: BincodeWriter` | **Parameters**: `val: float` | **Returns**: `void`
- **Unit Test**: `tests/functions/encoding/bincode_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `writeF32` (`mut self: BincodeWriter`) binary wire packing/unpacking across `u8`, `i32`, `i64`, IEEE-754 `f32`/`f64`, LEB128 varints, bitstreams, and length-prefixed UTF-8 strings. Concrete nominal inputs: receiver `recvObj: BincodeWriter = BincodeWriter(buffer = [65, 73, 80, 76], offset = 0, littleEndian = true)`, `val: float = 1.0`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.encoding.bincode_z7_test
import * from "std/encoding/bincode"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bincode_BincodeWriter_writeF32_7(): int:
  let mut recv_self = BincodeWriter(buffer = [65, 73, 80, 76], offset = 0, littleEndian = true, data = [])
  let mut edge_self = BincodeWriter(buffer = [65], offset = 0, littleEndian = false, data = [])
  let arg_val = 1.0
  let edge_val = 0.5
  recv_self.writeF32(arg_val)
  edge_self.writeF32(edge_val)
  assertEqInt(recv_self.offset, 4, "writeF32 nominal recv_self.offset == 4")
  assertEqInt(edge_self.offset, 4, "writeF32 boundary edge_self.offset == 4")
  ret 0
```

---

### `writeF64` (`std/encoding/bincode.aipl`)

- **Signature**: `pub fn (mut self: BincodeWriter) writeF64(val: float): void:`
- **Import**: `import * from "std/encoding/bincode"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `mut self: BincodeWriter` | **Parameters**: `val: float` | **Returns**: `void`
- **Unit Test**: `tests/functions/encoding/bincode_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `writeF64` (`mut self: BincodeWriter`) binary wire packing/unpacking across `u8`, `i32`, `i64`, IEEE-754 `f32`/`f64`, LEB128 varints, bitstreams, and length-prefixed UTF-8 strings. Concrete nominal inputs: receiver `recvObj: BincodeWriter = BincodeWriter(buffer = [65, 73, 80, 76], offset = 0, littleEndian = true)`, `val: float = 1.0`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.encoding.bincode_z8_test
import * from "std/encoding/bincode"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bincode_BincodeWriter_writeF64_8(): int:
  let mut recv_self = BincodeWriter(buffer = [65, 73, 80, 76], offset = 0, littleEndian = true, data = [])
  let mut edge_self = BincodeWriter(buffer = [65], offset = 0, littleEndian = false, data = [])
  let arg_val = 1.0
  let edge_val = 0.5
  recv_self.writeF64(arg_val)
  edge_self.writeF64(edge_val)
  assertEqInt(recv_self.offset, 8, "writeF64 nominal recv_self.offset == 8")
  assertEqInt(edge_self.offset, 8, "writeF64 boundary edge_self.offset == 8")
  ret 0
```

---

### `writeVarInt` (`std/encoding/bincode.aipl`)

- **Signature**: `pub fn (mut self: BincodeWriter) writeVarInt(val: int): void:`
- **Import**: `import * from "std/encoding/bincode"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `mut self: BincodeWriter` | **Parameters**: `val: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/encoding/bincode_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `writeVarInt` (`mut self: BincodeWriter`) binary wire packing/unpacking across `u8`, `i32`, `i64`, IEEE-754 `f32`/`f64`, LEB128 varints, bitstreams, and length-prefixed UTF-8 strings. Concrete nominal inputs: receiver `recvObj: BincodeWriter = BincodeWriter(buffer = [65, 73, 80, 76], offset = 0, littleEndian = true)`, `val: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.encoding.bincode_z9_test
import * from "std/encoding/bincode"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bincode_BincodeWriter_writeVarInt_9(): int:
  let mut recv_self = BincodeWriter(buffer = [65, 73, 80, 76], offset = 0, littleEndian = true, data = [])
  let mut edge_self = BincodeWriter(buffer = [65], offset = 0, littleEndian = false, data = [])
  let arg_val = 2
  let edge_val = 0
  recv_self.writeVarInt(arg_val)
  edge_self.writeVarInt(edge_val)
  assertEqInt(recv_self.offset, 1, "writeVarInt nominal recv_self.offset == 1")
  assertEqInt(edge_self.offset, 1, "writeVarInt boundary edge_self.offset == 1")
  ret 0
```

---

### `writeString` (`std/encoding/bincode.aipl`)

- **Signature**: `pub fn (mut self: BincodeWriter) writeString(s: str): void:`
- **Import**: `import * from "std/encoding/bincode"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `mut self: BincodeWriter` | **Parameters**: `s: str` | **Returns**: `void`
- **Unit Test**: `tests/functions/encoding/bincode_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `writeString` (`mut self: BincodeWriter`) binary wire packing/unpacking across `u8`, `i32`, `i64`, IEEE-754 `f32`/`f64`, LEB128 varints, bitstreams, and length-prefixed UTF-8 strings. Concrete nominal inputs: receiver `recvObj: BincodeWriter = BincodeWriter(buffer = [65, 73, 80, 76], offset = 0, littleEndian = true)`, `s: str = "aipl_test"`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.encoding.bincode_z10_test
import * from "std/encoding/bincode"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bincode_BincodeWriter_writeString_10(): int:
  let mut recv_self = BincodeWriter(buffer = [65, 73, 80, 76], offset = 0, littleEndian = true, data = [])
  let mut edge_self = BincodeWriter(buffer = [65], offset = 0, littleEndian = false, data = [])
  let arg_s = "test"
  let edge_s = "a"
  recv_self.writeString(arg_s)
  edge_self.writeString(edge_s)
  assertEqInt(recv_self.offset, 5, "writeString nominal recv_self.offset == 5")
  assertEqInt(edge_self.offset, 2, "writeString boundary edge_self.offset == 2")
  ret 0
```

---

### `toBytes` (`std/encoding/bincode.aipl`)

- **Signature**: `pub fn (self: BincodeWriter) toBytes(): bytes:`
- **Import**: `import * from "std/encoding/bincode"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `self: BincodeWriter` | **Parameters**: `none` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/encoding/bincode_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `toBytes` (`self: BincodeWriter`) binary wire packing/unpacking across `u8`, `i32`, `i64`, IEEE-754 `f32`/`f64`, LEB128 varints, bitstreams, and length-prefixed UTF-8 strings. Concrete nominal inputs: receiver `recvObj: BincodeWriter = BincodeWriter(buffer = [65, 73, 80, 76], offset = 0, littleEndian = true)`; exercises core body path returning/computing `bytesFromArray(self.data)`.

```aipl
module tests.functions.encoding.bincode_z11_test
import * from "std/encoding/bincode"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bincode_BincodeWriter_toBytes_11(): int:
  let recv_self = BincodeWriter(buffer = [65, 73, 80, 76], offset = 0, littleEndian = true, data = [])
  let edge_self = BincodeWriter(buffer = [65], offset = 0, littleEndian = false, data = [])
  let resNom = recv_self.toBytes()
  let resEdge = edge_self.toBytes()
  assertEqInt(resNom.len(), 0, "toBytes nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "toBytes boundary resEdge.len() == 0")
  ret 0
```

---

### `bincodeReaderNew` (`std/encoding/bincode.aipl`)

- **Signature**: `pub fn bincodeReaderNew(data: bytes, littleEndian: bool = true): BincodeReader:`
- **Import**: `import * from "std/encoding/bincode"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes, littleEndian: bool = true` | **Returns**: `BincodeReader`
- **Unit Test**: `tests/functions/encoding/bincode_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `bincodeReaderNew` (`free fn`) binary wire packing/unpacking across `u8`, `i32`, `i64`, IEEE-754 `f32`/`f64`, LEB128 varints, bitstreams, and length-prefixed UTF-8 strings. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`, `littleEndian: bool = true`; exercises core body path returning/computing `BincodeReader(buffer = data, offset = 0, littleEndian = littleEndian)`.

```aipl
module tests.functions.encoding.bincode_z12_test
import * from "std/encoding/bincode"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bincode_bincodeReaderNew_12(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let arg_littleEndian = true
  let edge_littleEndian = false
  let resNom = bincodeReaderNew(arg_data, arg_littleEndian)
  let resEdge = bincodeReaderNew(edge_data, edge_littleEndian)
  assertEqInt(resNom.buffer.len(), 4, "bincodeReaderNew nominal resNom.buffer.len() == 4")
  assertEqInt(resEdge.buffer.len(), 1, "bincodeReaderNew boundary resEdge.buffer.len() == 1")
  ret 0
```

---

### `readU8` (`std/encoding/bincode.aipl`)

- **Signature**: `pub fn (mut self: BincodeReader) readU8(): Result[int, str]:`
- **Import**: `import * from "std/encoding/bincode"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `mut self: BincodeReader` | **Parameters**: `none` | **Returns**: `Result[int, str]`
- **Unit Test**: `tests/functions/encoding/bincode_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `readU8` (`mut self: BincodeReader`) binary wire packing/unpacking across `u8`, `i32`, `i64`, IEEE-754 `f32`/`f64`, LEB128 varints, bitstreams, and length-prefixed UTF-8 strings. Concrete nominal inputs: receiver `recvObj: BincodeReader = BincodeReader(buffer = [65, 73, 80, 76], offset = 0, littleEndian = true)`; exercises core body path returning/computing `Ok(b)`.

```aipl
module tests.functions.encoding.bincode_z13_test
import * from "std/encoding/bincode"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bincode_BincodeReader_readU8_13(): int:
  let mut recv_self = BincodeReader(buffer = [65, 73, 80, 76], offset = 0, littleEndian = true)
  let mut edge_self = BincodeReader(buffer = [65], offset = 0, littleEndian = false)
  let resNom = recv_self.readU8()
  let resEdge = edge_self.readU8()
  assert(resNom.isOk() == true, "readU8 nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "readU8 boundary resEdge.isOk() == true")
  ret 0
```

---

### `readI32` (`std/encoding/bincode.aipl`)

- **Signature**: `pub fn (mut self: BincodeReader) readI32(): Result[int, str]:`
- **Import**: `import * from "std/encoding/bincode"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `mut self: BincodeReader` | **Parameters**: `none` | **Returns**: `Result[int, str]`
- **Unit Test**: `tests/functions/encoding/bincode_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `readI32` (`mut self: BincodeReader`) binary wire packing/unpacking across `u8`, `i32`, `i64`, IEEE-754 `f32`/`f64`, LEB128 varints, bitstreams, and length-prefixed UTF-8 strings. Concrete nominal inputs: receiver `recvObj: BincodeReader = BincodeReader(buffer = [65, 73, 80, 76], offset = 0, littleEndian = true)`; exercises core body path returning/computing `Ok(raw)`.

```aipl
module tests.functions.encoding.bincode_z14_test
import * from "std/encoding/bincode"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bincode_BincodeReader_readI32_14(): int:
  let mut recv_self = BincodeReader(buffer = [65, 73, 80, 76], offset = 0, littleEndian = true)
  let mut edge_self = BincodeReader(buffer = [65], offset = 0, littleEndian = false)
  let resNom = recv_self.readI32()
  let resEdge = edge_self.readI32()
  assert(resNom.isOk() == true, "readI32 nominal resNom.isOk() == true")
  assert(resEdge.isOk() == false, "readI32 boundary resEdge.isOk() == false")
  ret 0
```

---

### `readI64` (`std/encoding/bincode.aipl`)

- **Signature**: `pub fn (mut self: BincodeReader) readI64(): Result[int, str]:`
- **Import**: `import * from "std/encoding/bincode"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `mut self: BincodeReader` | **Parameters**: `none` | **Returns**: `Result[int, str]`
- **Unit Test**: `tests/functions/encoding/bincode_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `readI64` (`mut self: BincodeReader`) binary wire packing/unpacking across `u8`, `i32`, `i64`, IEEE-754 `f32`/`f64`, LEB128 varints, bitstreams, and length-prefixed UTF-8 strings. Concrete nominal inputs: receiver `recvObj: BincodeReader = BincodeReader(buffer = [65, 73, 80, 76], offset = 0, littleEndian = true)`; exercises core body path returning/computing `Ok(raw)`.

```aipl
module tests.functions.encoding.bincode_z15_test
import * from "std/encoding/bincode"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bincode_BincodeReader_readI64_15(): int:
  let mut recv_self = BincodeReader(buffer = [65, 73, 80, 76], offset = 0, littleEndian = true)
  let mut edge_self = BincodeReader(buffer = [65], offset = 0, littleEndian = false)
  let resNom = recv_self.readI64()
  let resEdge = edge_self.readI64()
  assert(resNom.isOk() == false, "readI64 nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "readI64 boundary resEdge.isOk() == false")
  ret 0
```

---

### `readF32` (`std/encoding/bincode.aipl`)

- **Signature**: `pub fn (mut self: BincodeReader) readF32(): Result[float, str]:`
- **Import**: `import * from "std/encoding/bincode"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `mut self: BincodeReader` | **Parameters**: `none` | **Returns**: `Result[float, str]`
- **Unit Test**: `tests/functions/encoding/bincode_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `readF32` (`mut self: BincodeReader`) binary wire packing/unpacking across `u8`, `i32`, `i64`, IEEE-754 `f32`/`f64`, LEB128 varints, bitstreams, and length-prefixed UTF-8 strings. Concrete nominal inputs: receiver `recvObj: BincodeReader = BincodeReader(buffer = [65, 73, 80, 76], offset = 0, littleEndian = true)`; exercises core body path returning/computing `Ok(f32BitsToF64(r.unwrap()))`.

```aipl
module tests.functions.encoding.bincode_z16_test
import * from "std/encoding/bincode"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bincode_BincodeReader_readF32_16(): int:
  let mut recv_self = BincodeReader(buffer = [65, 73, 80, 76], offset = 0, littleEndian = true)
  let mut edge_self = BincodeReader(buffer = [65], offset = 0, littleEndian = false)
  let resNom = recv_self.readF32()
  let resEdge = edge_self.readF32()
  assert(resNom.isOk() == true, "readF32 nominal resNom.isOk() == true")
  assert(resEdge.isOk() == false, "readF32 boundary resEdge.isOk() == false")
  ret 0
```

---

### `readF64` (`std/encoding/bincode.aipl`)

- **Signature**: `pub fn (mut self: BincodeReader) readF64(): Result[float, str]:`
- **Import**: `import * from "std/encoding/bincode"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `mut self: BincodeReader` | **Parameters**: `none` | **Returns**: `Result[float, str]`
- **Unit Test**: `tests/functions/encoding/bincode_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `readF64` (`mut self: BincodeReader`) binary wire packing/unpacking across `u8`, `i32`, `i64`, IEEE-754 `f32`/`f64`, LEB128 varints, bitstreams, and length-prefixed UTF-8 strings. Concrete nominal inputs: receiver `recvObj: BincodeReader = BincodeReader(buffer = [65, 73, 80, 76], offset = 0, littleEndian = true)`; exercises core body path returning/computing `Ok(bitcastI64ToF64(r.unwrap()))`.

```aipl
module tests.functions.encoding.bincode_z17_test
import * from "std/encoding/bincode"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bincode_BincodeReader_readF64_17(): int:
  let mut recv_self = BincodeReader(buffer = [65, 73, 80, 76], offset = 0, littleEndian = true)
  let mut edge_self = BincodeReader(buffer = [65], offset = 0, littleEndian = false)
  let resNom = recv_self.readF64()
  let resEdge = edge_self.readF64()
  assert(resNom.isOk() == false, "readF64 nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "readF64 boundary resEdge.isOk() == false")
  ret 0
```

---

### `readVarInt` (`std/encoding/bincode.aipl`)

- **Signature**: `pub fn (mut self: BincodeReader) readVarInt(): Result[int, str]:`
- **Import**: `import * from "std/encoding/bincode"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `mut self: BincodeReader` | **Parameters**: `none` | **Returns**: `Result[int, str]`
- **Unit Test**: `tests/functions/encoding/bincode_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `readVarInt` (`mut self: BincodeReader`) binary wire packing/unpacking across `u8`, `i32`, `i64`, IEEE-754 `f32`/`f64`, LEB128 varints, bitstreams, and length-prefixed UTF-8 strings. Concrete nominal inputs: receiver `recvObj: BincodeReader = BincodeReader(buffer = [65, 73, 80, 76], offset = 0, littleEndian = true)`; exercises core body path returning/computing `Ok(result)`.

```aipl
module tests.functions.encoding.bincode_z18_test
import * from "std/encoding/bincode"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bincode_BincodeReader_readVarInt_18(): int:
  let mut recv_self = BincodeReader(buffer = [65, 73, 80, 76], offset = 0, littleEndian = true)
  let mut edge_self = BincodeReader(buffer = [65], offset = 0, littleEndian = false)
  let resNom = recv_self.readVarInt()
  let resEdge = edge_self.readVarInt()
  assert(resNom.isOk() == true, "readVarInt nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "readVarInt boundary resEdge.isOk() == true")
  ret 0
```

---

### `readString` (`std/encoding/bincode.aipl`)

- **Signature**: `pub fn (mut self: BincodeReader) readString(): Result[str, str]:`
- **Import**: `import * from "std/encoding/bincode"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `mut self: BincodeReader` | **Parameters**: `none` | **Returns**: `Result[str, str]`
- **Unit Test**: `tests/functions/encoding/bincode_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `readString` (`mut self: BincodeReader`) binary wire packing/unpacking across `u8`, `i32`, `i64`, IEEE-754 `f32`/`f64`, LEB128 varints, bitstreams, and length-prefixed UTF-8 strings. Concrete nominal inputs: receiver `recvObj: BincodeReader = BincodeReader(buffer = [65, 73, 80, 76], offset = 0, littleEndian = true)`; exercises core body path returning/computing `Ok(bytesFromArray(arr).toStringLossy())`.

```aipl
module tests.functions.encoding.bincode_z19_test
import * from "std/encoding/bincode"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bincode_BincodeReader_readString_19(): int:
  let mut recv_self = BincodeReader(buffer = [65, 73, 80, 76], offset = 0, littleEndian = true)
  let mut edge_self = BincodeReader(buffer = [65], offset = 0, littleEndian = false)
  let resNom = recv_self.readString()
  let resEdge = edge_self.readString()
  assert(resNom.isOk() == false, "readString nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "readString boundary resEdge.isOk() == false")
  ret 0
```

---

### `bitStreamNew` (`std/encoding/bincode.aipl`)

- **Signature**: `pub fn bitStreamNew(): BitStream:`
- **Import**: `import * from "std/encoding/bincode"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `BitStream`
- **Unit Test**: `tests/functions/encoding/bincode_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `bitStreamNew` (`free fn`) binary wire packing/unpacking across `u8`, `i32`, `i64`, IEEE-754 `f32`/`f64`, LEB128 varints, bitstreams, and length-prefixed UTF-8 strings. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `BitStream(bytes = empty, bitOffset = 0)`.

```aipl
module tests.functions.encoding.bincode_z20_test
import * from "std/encoding/bincode"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bincode_bitStreamNew_20(): int:
  let resNom = bitStreamNew()
  let resEdge = bitStreamNew()
  assertEqInt(resNom.bytes.len(), 0, "bitStreamNew nominal resNom.bytes.len() == 0")
  assertEqInt(resEdge.bytes.len(), 0, "bitStreamNew boundary resEdge.bytes.len() == 0")
  ret 0
```

---

### `bitStreamWriteBits` (`std/encoding/bincode.aipl`)

- **Signature**: `pub fn bitStreamWriteBits(mut bs: BitStream, val: int, count: int): BitStream:`
- **Import**: `import * from "std/encoding/bincode"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut bs: BitStream, val: int, count: int` | **Returns**: `BitStream`
- **Unit Test**: `tests/functions/encoding/bincode_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `bitStreamWriteBits` (`free fn`) binary wire packing/unpacking across `u8`, `i32`, `i64`, IEEE-754 `f32`/`f64`, LEB128 varints, bitstreams, and length-prefixed UTF-8 strings. Concrete nominal inputs: `bs: BitStream = BitStream(bytes = [64], bitOffset = 0)`, `val: int = 1`, `count: int = 64`; exercises core body path returning/computing `bs`.

```aipl
module tests.functions.encoding.bincode_z21_test
import * from "std/encoding/bincode"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bincode_bitStreamWriteBits_21(): int:
  let arg_bs = BitStream(bytes = [], bitOffset = 4)
  let edge_bs = BitStream(bytes = [], bitOffset = 1)
  let arg_val = 2
  let edge_val = 0
  let arg_count = 4
  let edge_count = 1
  let resNom = bitStreamWriteBits(arg_bs, arg_val, arg_count)
  let resEdge = bitStreamWriteBits(edge_bs, edge_val, edge_count)
  assertEqInt(resNom.bytes.len(), 0, "bitStreamWriteBits nominal resNom.bytes.len() == 0")
  assertEqInt(resEdge.bytes.len(), 0, "bitStreamWriteBits boundary resEdge.bytes.len() == 0")
  ret 0
```

---

### `bitStreamToBytes` (`std/encoding/bincode.aipl`)

- **Signature**: `pub fn bitStreamToBytes(bs: BitStream): bytes:`
- **Import**: `import * from "std/encoding/bincode"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bs: BitStream` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/encoding/bincode_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `bitStreamToBytes` (`free fn`) binary wire packing/unpacking across `u8`, `i32`, `i64`, IEEE-754 `f32`/`f64`, LEB128 varints, bitstreams, and length-prefixed UTF-8 strings. Concrete nominal inputs: `bs: BitStream = BitStream(bytes = [64], bitOffset = 0)`; exercises core body path returning/computing `bytesFromArray(bs.bytes)`.

```aipl
module tests.functions.encoding.bincode_z22_test
import * from "std/encoding/bincode"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bincode_bitStreamToBytes_22(): int:
  let arg_bs = BitStream(bytes = [], bitOffset = 4)
  let edge_bs = BitStream(bytes = [], bitOffset = 1)
  let resNom = bitStreamToBytes(arg_bs)
  let resEdge = bitStreamToBytes(edge_bs)
  assertEqInt(resNom.len(), 0, "bitStreamToBytes nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "bitStreamToBytes boundary resEdge.len() == 0")
  ret 0
```

---

### `bitStreamBitCount` (`std/encoding/bincode.aipl`)

- **Signature**: `pub fn bitStreamBitCount(bs: BitStream): int:`
- **Import**: `import * from "std/encoding/bincode"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bs: BitStream` | **Returns**: `int`
- **Unit Test**: `tests/functions/encoding/bincode_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `bitStreamBitCount` (`free fn`) binary wire packing/unpacking across `u8`, `i32`, `i64`, IEEE-754 `f32`/`f64`, LEB128 varints, bitstreams, and length-prefixed UTF-8 strings. Concrete nominal inputs: `bs: BitStream = BitStream(bytes = [64], bitOffset = 0)`; exercises core body path returning/computing `bs.bitOffset`.

```aipl
module tests.functions.encoding.bincode_z23_test
import * from "std/encoding/bincode"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bincode_bitStreamBitCount_23(): int:
  let arg_bs = BitStream(bytes = [], bitOffset = 4)
  let edge_bs = BitStream(bytes = [], bitOffset = 1)
  let resNom = bitStreamBitCount(arg_bs)
  let resEdge = bitStreamBitCount(edge_bs)
  assertEqInt(resNom, 4, "bitStreamBitCount nominal resNom == 4")
  assertEqInt(resEdge, 1, "bitStreamBitCount boundary resEdge == 1")
  ret 0
```

---

### `bincodePackIntArray` (`std/encoding/bincode.aipl`)

- **Signature**: `pub fn bincodePackIntArray(vals: [int]): bytes:`
- **Import**: `import * from "std/encoding/bincode"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `vals: [int]` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/encoding/bincode_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `bincodePackIntArray` (`free fn`) binary wire packing/unpacking across `u8`, `i32`, `i64`, IEEE-754 `f32`/`f64`, LEB128 varints, bitstreams, and length-prefixed UTF-8 strings. Concrete nominal inputs: `vals: [int] = [1]`; exercises core body path returning/computing `w.toBytes()`.

```aipl
module tests.functions.encoding.bincode_z24_test
import * from "std/encoding/bincode"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bincode_bincodePackIntArray_24(): int:
  let arg_vals = [2]
  let edge_vals = []
  let resNom = bincodePackIntArray(arg_vals)
  let resEdge = bincodePackIntArray(edge_vals)
  assertEqInt(resNom.len(), 5, "bincodePackIntArray nominal resNom.len() == 5")
  assertEqInt(resEdge.len(), 1, "bincodePackIntArray boundary resEdge.len() == 1")
  ret 0
```

---

### `bincodeUnpackIntArray` (`std/encoding/bincode.aipl`)

- **Signature**: `pub fn bincodeUnpackIntArray(data: bytes): Result[[int], str]:`
- **Import**: `import * from "std/encoding/bincode"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes` | **Returns**: `Result[[int], str]`
- **Unit Test**: `tests/functions/encoding/bincode_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `bincodeUnpackIntArray` (`free fn`) binary wire packing/unpacking across `u8`, `i32`, `i64`, IEEE-754 `f32`/`f64`, LEB128 varints, bitstreams, and length-prefixed UTF-8 strings. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `Ok(out)`.

```aipl
module tests.functions.encoding.bincode_z25_test
import * from "std/encoding/bincode"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bincode_bincodeUnpackIntArray_25(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let resNom = bincodeUnpackIntArray(arg_data)
  let resEdge = bincodeUnpackIntArray(edge_data)
  assert(resNom.isOk() == false, "bincodeUnpackIntArray nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "bincodeUnpackIntArray boundary resEdge.isOk() == false")
  ret 0
```

---

### `parseCsv` (`std/encoding/csv.aipl`)

- **Signature**: `pub fn parseCsv(text: str, delimiter: str = ","): Result[[[str]], str]:`
- **Import**: `import * from "std/encoding/csv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str, delimiter: str = ","` | **Returns**: `Result[[[str]], str]`
- **Unit Test**: `tests/functions/encoding/csv_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `parseCsv` (`free fn`) RFC 4180 CSV/TSV parsing and serialization with embedded commas, escaped double quotes (`""`), header-mapped records, and column extraction. Concrete nominal inputs: `text: str = "aipl_test"`, `delimiter: str = "aipl_test"`, `": any = 42`; exercises core body path returning/computing `Ok(rows)`.

```aipl
module tests.functions.encoding.csv_z1_test
import * from "std/encoding/csv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_csv_parseCsv_1(): int:
  let arg_text = "a,b\n1,2"
  let edge_text = "a,b\n1,2"
  let arg_delimiter = "a,b\n1,2"
  let edge_delimiter = "a,b\n1,2"
  let resNom = parseCsv(arg_text, arg_delimiter)
  let resEdge = parseCsv(edge_text, edge_delimiter)
  assert(resNom.isOk() == true, "parseCsv nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "parseCsv boundary resEdge.isOk() == true")
  ret 0
```

---

### `serializeCsvCell` (`std/encoding/csv.aipl`)

- **Signature**: `fn serializeCsvCell(cell: str, delimiter: str): str:`
- **Import**: `import * from "std/encoding/csv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cell: str, delimiter: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/csv_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `serializeCsvCell` (`free fn`) RFC 4180 CSV/TSV parsing and serialization with embedded commas, escaped double quotes (`""`), header-mapped records, and column extraction. Concrete nominal inputs: `cell: str = "aipl_test"`, `delimiter: str = "aipl_test"`; exercises core body path returning/computing `"\"" + escaped + "\""`.

```aipl
module tests.functions.encoding.csv_z2_test
import * from "std/encoding/csv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_csv_serializeCsvCell_2(): int:
  let arg_cell = "a,b\n1,2"
  let edge_cell = "a,b\n1,2"
  let arg_delimiter = "a,b\n1,2"
  let edge_delimiter = "a,b\n1,2"
  let resNom = serializeCsvCell(arg_cell, arg_delimiter)
  let resEdge = serializeCsvCell(edge_cell, edge_delimiter)
  assertEqInt(resNom.len(), 9, "serializeCsvCell nominal string length == 9")
  assertEqInt(resEdge.len(), 9, "serializeCsvCell boundary string length == 9")
  ret 0
```

---

### `serializeCsv` (`std/encoding/csv.aipl`)

- **Signature**: `pub fn serializeCsv(rows: [[str]], delimiter: str = ","): str:`
- **Import**: `import * from "std/encoding/csv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rows: [[str]], delimiter: str = ","` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/csv_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `serializeCsv` (`free fn`) RFC 4180 CSV/TSV parsing and serialization with embedded commas, escaped double quotes (`""`), header-mapped records, and column extraction. Concrete nominal inputs: `rows: [[str]] = [["aipl_test"]]`, `delimiter: str = "aipl_test"`, `": any = 42`; exercises core body path returning/computing `lineStrs.join("\n")`.

```aipl
module tests.functions.encoding.csv_z3_test
import * from "std/encoding/csv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_csv_serializeCsv_3(): int:
  let arg_rows = [[]]
  let edge_rows = []
  let arg_delimiter = "a,b\n1,2"
  let edge_delimiter = "a,b\n1,2"
  let resNom = serializeCsv(arg_rows, arg_delimiter)
  let resEdge = serializeCsv(edge_rows, edge_delimiter)
  assertEqStr(resNom, "", "serializeCsv nominal string matches")
  assertEqStr(resEdge, "", "serializeCsv boundary string matches")
  ret 0
```

---

### `readRow` (`std/encoding/csv.aipl`)

- **Signature**: `pub fn (mut self: CsvReader) readRow(): Option[[str]]:`
- **Import**: `import * from "std/encoding/csv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `mut self: CsvReader` | **Parameters**: `none` | **Returns**: `Option[[str]]`
- **Unit Test**: `tests/functions/encoding/csv_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `readRow` (`mut self: CsvReader`) RFC 4180 CSV/TSV parsing and serialization with embedded commas, escaped double quotes (`""`), header-mapped records, and column extraction. Concrete nominal inputs: receiver `recvObj: CsvReader = CsvReader(text = "aipl_test", opts = CsvOptions(delimiter = "aipl_test", quoteChar = "aipl_test", escapeChar = "aipl_test", hasHeader = true), currentLine = 1)`; exercises core body path returning/computing `Some(row)`.

```aipl
module tests.functions.encoding.csv_z4_test
import * from "std/encoding/csv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_csv_CsvReader_readRow_4(): int:
  let mut recv_self = CsvReader(text = "test", opts = CsvOptions(delimiter = "test", quoteChar = "test", escapeChar = "test", hasHeader = true), currentLine = 4)
  let mut edge_self = CsvReader(text = "a", opts = CsvOptions(delimiter = "a", quoteChar = "a", escapeChar = "a", hasHeader = false), currentLine = 1)
  let resNom = recv_self.readRow()
  let resEdge = edge_self.readRow()
  assert(resNom.isSome() == false, "readRow nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "readRow boundary resEdge.isSome() == false")
  ret 0
```

---

### `stringifyCsv` (`std/encoding/csv.aipl`)

- **Signature**: `pub fn stringifyCsv(rows: [[str]], delimiter: str = ","): str:`
- **Import**: `import * from "std/encoding/csv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rows: [[str]], delimiter: str = ","` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/csv_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `stringifyCsv` (`free fn`) RFC 4180 CSV/TSV parsing and serialization with embedded commas, escaped double quotes (`""`), header-mapped records, and column extraction. Concrete nominal inputs: `rows: [[str]] = [["aipl_test"]]`, `delimiter: str = "aipl_test"`, `": any = 42`; exercises core body path returning/computing `serializeCsv(rows, delimiter)`.

```aipl
module tests.functions.encoding.csv_z5_test
import * from "std/encoding/csv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_csv_stringifyCsv_5(): int:
  let arg_rows = [[]]
  let edge_rows = []
  let arg_delimiter = "a,b\n1,2"
  let edge_delimiter = "a,b\n1,2"
  let resNom = stringifyCsv(arg_rows, arg_delimiter)
  let resEdge = stringifyCsv(edge_rows, edge_delimiter)
  assertEqStr(resNom, "", "stringifyCsv nominal string matches")
  assertEqStr(resEdge, "", "stringifyCsv boundary string matches")
  ret 0
```

---

### `formatCsv` (`std/encoding/csv.aipl`)

- **Signature**: `pub fn formatCsv(rows: [[str]], delimiter: str = ","): str:`
- **Import**: `import * from "std/encoding/csv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rows: [[str]], delimiter: str = ","` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/csv_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `formatCsv` (`free fn`) RFC 4180 CSV/TSV parsing and serialization with embedded commas, escaped double quotes (`""`), header-mapped records, and column extraction. Concrete nominal inputs: `rows: [[str]] = [["aipl_test"]]`, `delimiter: str = "aipl_test"`, `": any = 42`; exercises core body path returning/computing `serializeCsv(rows, delimiter)`.

```aipl
module tests.functions.encoding.csv_z6_test
import * from "std/encoding/csv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_csv_formatCsv_6(): int:
  let arg_rows = [[]]
  let edge_rows = []
  let arg_delimiter = "a,b\n1,2"
  let edge_delimiter = "a,b\n1,2"
  let resNom = formatCsv(arg_rows, arg_delimiter)
  let resEdge = formatCsv(edge_rows, edge_delimiter)
  assertEqStr(resNom, "", "formatCsv nominal string matches")
  assertEqStr(resEdge, "", "formatCsv boundary string matches")
  ret 0
```

---

### `toCsv` (`std/encoding/csv.aipl`)

- **Signature**: `pub fn toCsv(rows: [[str]]): str:`
- **Import**: `import * from "std/encoding/csv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rows: [[str]]` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/csv_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `toCsv` (`free fn`) RFC 4180 CSV/TSV parsing and serialization with embedded commas, escaped double quotes (`""`), header-mapped records, and column extraction. Concrete nominal inputs: `rows: [[str]] = [["aipl_test"]]`; exercises core body path returning/computing `serializeCsv(rows, ",")`.

```aipl
module tests.functions.encoding.csv_z7_test
import * from "std/encoding/csv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_csv_toCsv_7(): int:
  let arg_rows = [[]]
  let edge_rows = []
  let resNom = toCsv(arg_rows)
  let resEdge = toCsv(edge_rows)
  assertEqStr(resNom, "", "toCsv nominal string matches")
  assertEqStr(resEdge, "", "toCsv boundary string matches")
  ret 0
```

---

### `parseCsvRecords` (`std/encoding/csv.aipl`)

- **Signature**: `pub fn parseCsvRecords(text: str): [Map[str, str]]:`
- **Import**: `import * from "std/encoding/csv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str` | **Returns**: `[Map[str, str]]`
- **Unit Test**: `tests/functions/encoding/csv_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `parseCsvRecords` (`free fn`) RFC 4180 CSV/TSV parsing and serialization with embedded commas, escaped double quotes (`""`), header-mapped records, and column extraction. Concrete nominal inputs: `text: str = "aipl_test"`; exercises core body path returning/computing `records`.

```aipl
module tests.functions.encoding.csv_z8_test
import * from "std/encoding/csv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_csv_parseCsvRecords_8(): int:
  let arg_text = "a,b\n1,2"
  let edge_text = "a,b\n1,2"
  let resNom = parseCsvRecords(arg_text)
  let resEdge = parseCsvRecords(edge_text)
  assertEqInt(resNom.len(), 1, "parseCsvRecords nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "parseCsvRecords boundary resEdge.len() == 1")
  ret 0
```

---

### `parseCsvWithHeaders` (`std/encoding/csv.aipl`)

- **Signature**: `pub fn parseCsvWithHeaders(text: str): [Map[str, str]]:`
- **Import**: `import * from "std/encoding/csv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str` | **Returns**: `[Map[str, str]]`
- **Unit Test**: `tests/functions/encoding/csv_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `parseCsvWithHeaders` (`free fn`) RFC 4180 CSV/TSV parsing and serialization with embedded commas, escaped double quotes (`""`), header-mapped records, and column extraction. Concrete nominal inputs: `text: str = "aipl_test"`; exercises core body path returning/computing `parseCsvRecords(text)`.

```aipl
module tests.functions.encoding.csv_z9_test
import * from "std/encoding/csv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_csv_parseCsvWithHeaders_9(): int:
  let arg_text = "a,b\n1,2"
  let edge_text = "a,b\n1,2"
  let resNom = parseCsvWithHeaders(arg_text)
  let resEdge = parseCsvWithHeaders(edge_text)
  assertEqInt(resNom.len(), 1, "parseCsvWithHeaders nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "parseCsvWithHeaders boundary resEdge.len() == 1")
  ret 0
```

---

### `stringifyCsvRecords` (`std/encoding/csv.aipl`)

- **Signature**: `pub fn stringifyCsvRecords(records: [Map[str, str]], headers: [str]): str:`
- **Import**: `import * from "std/encoding/csv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `records: [Map[str, str]], headers: [str]` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/csv_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `stringifyCsvRecords` (`free fn`) RFC 4180 CSV/TSV parsing and serialization with embedded commas, escaped double quotes (`""`), header-mapped records, and column extraction. Concrete nominal inputs: `records: [Map[str, str]] = [Map()]`, `headers: [str] = ["aipl_test"]`; exercises core body path returning/computing `serializeCsv(rows, ",")`.

```aipl
module tests.functions.encoding.csv_z10_test
import * from "std/encoding/csv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_csv_stringifyCsvRecords_10(): int:
  let arg_records = [{}]
  let edge_records = []
  let arg_headers = ["a,b\n1,2"]
  let edge_headers = []
  let resNom = stringifyCsvRecords(arg_records, arg_headers)
  let resEdge = stringifyCsvRecords(edge_records, edge_headers)
  assertEqInt(resNom.len(), 10, "stringifyCsvRecords nominal string length == 10")
  assertEqStr(resEdge, "", "stringifyCsvRecords boundary string matches")
  ret 0
```

---

### `parseTsv` (`std/encoding/csv.aipl`)

- **Signature**: `pub fn parseTsv(text: str): [[str]]:`
- **Import**: `import * from "std/encoding/csv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str` | **Returns**: `[[str]]`
- **Unit Test**: `tests/functions/encoding/csv_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `parseTsv` (`free fn`) RFC 4180 CSV/TSV parsing and serialization with embedded commas, escaped double quotes (`""`), header-mapped records, and column extraction. Concrete nominal inputs: `text: str = "aipl_test"`; exercises core body path returning/computing `res.unwrap()`.

```aipl
module tests.functions.encoding.csv_z11_test
import * from "std/encoding/csv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_csv_parseTsv_11(): int:
  let arg_text = "test"
  let edge_text = "a"
  let resNom = parseTsv(arg_text)
  let resEdge = parseTsv(edge_text)
  assertEqInt(resNom.len(), 1, "parseTsv nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "parseTsv boundary resEdge.len() == 1")
  ret 0
```

---

### `parseTsvRecords` (`std/encoding/csv.aipl`)

- **Signature**: `pub fn parseTsvRecords(text: str): [Map[str, str]]:`
- **Import**: `import * from "std/encoding/csv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str` | **Returns**: `[Map[str, str]]`
- **Unit Test**: `tests/functions/encoding/csv_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `parseTsvRecords` (`free fn`) RFC 4180 CSV/TSV parsing and serialization with embedded commas, escaped double quotes (`""`), header-mapped records, and column extraction. Concrete nominal inputs: `text: str = "aipl_test"`; exercises core body path returning/computing `records`.

```aipl
module tests.functions.encoding.csv_z12_test
import * from "std/encoding/csv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_csv_parseTsvRecords_12(): int:
  let arg_text = "test"
  let edge_text = "a"
  let resNom = parseTsvRecords(arg_text)
  let resEdge = parseTsvRecords(edge_text)
  assertEqInt(resNom.len(), 0, "parseTsvRecords nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "parseTsvRecords boundary resEdge.len() == 0")
  ret 0
```

---

### `parseTsvWithHeaders` (`std/encoding/csv.aipl`)

- **Signature**: `pub fn parseTsvWithHeaders(text: str): [Map[str, str]]:`
- **Import**: `import * from "std/encoding/csv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str` | **Returns**: `[Map[str, str]]`
- **Unit Test**: `tests/functions/encoding/csv_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `parseTsvWithHeaders` (`free fn`) RFC 4180 CSV/TSV parsing and serialization with embedded commas, escaped double quotes (`""`), header-mapped records, and column extraction. Concrete nominal inputs: `text: str = "aipl_test"`; exercises core body path returning/computing `parseTsvRecords(text)`.

```aipl
module tests.functions.encoding.csv_z13_test
import * from "std/encoding/csv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_csv_parseTsvWithHeaders_13(): int:
  let arg_text = "test"
  let edge_text = "a"
  let resNom = parseTsvWithHeaders(arg_text)
  let resEdge = parseTsvWithHeaders(edge_text)
  assertEqInt(resNom.len(), 0, "parseTsvWithHeaders nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "parseTsvWithHeaders boundary resEdge.len() == 0")
  ret 0
```

---

### `stringifyTsv` (`std/encoding/csv.aipl`)

- **Signature**: `pub fn stringifyTsv(rows: [[str]]): str:`
- **Import**: `import * from "std/encoding/csv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rows: [[str]]` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/csv_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `stringifyTsv` (`free fn`) RFC 4180 CSV/TSV parsing and serialization with embedded commas, escaped double quotes (`""`), header-mapped records, and column extraction. Concrete nominal inputs: `rows: [[str]] = [["aipl_test"]]`; exercises core body path returning/computing `serializeCsv(rows, "\t")`.

```aipl
module tests.functions.encoding.csv_z14_test
import * from "std/encoding/csv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_csv_stringifyTsv_14(): int:
  let arg_rows = [[]]
  let edge_rows = []
  let resNom = stringifyTsv(arg_rows)
  let resEdge = stringifyTsv(edge_rows)
  assertEqStr(resNom, "", "stringifyTsv nominal string matches")
  assertEqStr(resEdge, "", "stringifyTsv boundary string matches")
  ret 0
```

---

### `toTsv` (`std/encoding/csv.aipl`)

- **Signature**: `pub fn toTsv(rows: [[str]]): str:`
- **Import**: `import * from "std/encoding/csv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rows: [[str]]` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/csv_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `toTsv` (`free fn`) RFC 4180 CSV/TSV parsing and serialization with embedded commas, escaped double quotes (`""`), header-mapped records, and column extraction. Concrete nominal inputs: `rows: [[str]] = [["aipl_test"]]`; exercises core body path returning/computing `serializeCsv(rows, "\t")`.

```aipl
module tests.functions.encoding.csv_z15_test
import * from "std/encoding/csv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_csv_toTsv_15(): int:
  let arg_rows = [[]]
  let edge_rows = []
  let resNom = toTsv(arg_rows)
  let resEdge = toTsv(edge_rows)
  assertEqStr(resNom, "", "toTsv nominal string matches")
  assertEqStr(resEdge, "", "toTsv boundary string matches")
  ret 0
```

---

### `formatTsv` (`std/encoding/csv.aipl`)

- **Signature**: `pub fn formatTsv(rows: [[str]]): str:`
- **Import**: `import * from "std/encoding/csv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rows: [[str]]` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/csv_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `formatTsv` (`free fn`) RFC 4180 CSV/TSV parsing and serialization with embedded commas, escaped double quotes (`""`), header-mapped records, and column extraction. Concrete nominal inputs: `rows: [[str]] = [["aipl_test"]]`; exercises core body path returning/computing `serializeCsv(rows, "\t")`.

```aipl
module tests.functions.encoding.csv_z16_test
import * from "std/encoding/csv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_csv_formatTsv_16(): int:
  let arg_rows = [[]]
  let edge_rows = []
  let resNom = formatTsv(arg_rows)
  let resEdge = formatTsv(edge_rows)
  assertEqStr(resNom, "", "formatTsv nominal string matches")
  assertEqStr(resEdge, "", "formatTsv boundary string matches")
  ret 0
```

---

### `stringifyTsvRecords` (`std/encoding/csv.aipl`)

- **Signature**: `pub fn stringifyTsvRecords(records: [Map[str, str]], headers: [str]): str:`
- **Import**: `import * from "std/encoding/csv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `records: [Map[str, str]], headers: [str]` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/csv_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `stringifyTsvRecords` (`free fn`) RFC 4180 CSV/TSV parsing and serialization with embedded commas, escaped double quotes (`""`), header-mapped records, and column extraction. Concrete nominal inputs: `records: [Map[str, str]] = [Map()]`, `headers: [str] = ["aipl_test"]`; exercises core body path returning/computing `serializeCsv(rows, "\t")`.

```aipl
module tests.functions.encoding.csv_z17_test
import * from "std/encoding/csv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_csv_stringifyTsvRecords_17(): int:
  let arg_records = [{}]
  let edge_records = []
  let arg_headers = ["test"]
  let edge_headers = []
  let resNom = stringifyTsvRecords(arg_records, arg_headers)
  let resEdge = stringifyTsvRecords(edge_records, edge_headers)
  assertEqInt(resNom.len(), 5, "stringifyTsvRecords nominal string length == 5")
  assertEqStr(resEdge, "", "stringifyTsvRecords boundary string matches")
  ret 0
```

---

### `csvColumnValues` (`std/encoding/csv.aipl`)

- **Signature**: `pub fn csvColumnValues(rows: [[str]], colIdx: int): [str]:`
- **Import**: `import * from "std/encoding/csv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rows: [[str]], colIdx: int` | **Returns**: `[str]`
- **Unit Test**: `tests/functions/encoding/csv_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `csvColumnValues` (`free fn`) RFC 4180 CSV/TSV parsing and serialization with embedded commas, escaped double quotes (`""`), header-mapped records, and column extraction. Concrete nominal inputs: `rows: [[str]] = [["aipl_test"]]`, `colIdx: int = 0`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.encoding.csv_z18_test
import * from "std/encoding/csv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_csv_csvColumnValues_18(): int:
  let arg_rows = [[]]
  let edge_rows = []
  let arg_colIdx = 1
  let edge_colIdx = 0
  let resNom = csvColumnValues(arg_rows, arg_colIdx)
  let resEdge = csvColumnValues(edge_rows, edge_colIdx)
  assertEqInt(resNom.len(), 0, "csvColumnValues nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "csvColumnValues boundary resEdge.len() == 0")
  ret 0
```

---

### `hexNibbleToChar` (`std/encoding/hex.aipl`)

- **Signature**: `fn hexNibbleToChar(nib: int, uppercase: bool): str:`
- **Import**: `import * from "std/encoding/hex"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `nib: int, uppercase: bool` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/hex_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `hexNibbleToChar` lowercase/uppercase hex encoding, odd-length/non-hex rejection, and 16-byte offset + ASCII gutter hexdump formatting. Concrete nominal inputs: `nib: int = 1`, `uppercase: bool = true`; exercises core body path returning/computing `chr(87 + v)`.

```aipl
module tests.functions.encoding.hex_z1_test
import * from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hex_hexNibbleToChar_1(): int:
  let arg_nib = 4
  let edge_nib = 1
  let arg_uppercase = true
  let edge_uppercase = false
  let resNom = hexNibbleToChar(arg_nib, arg_uppercase)
  let resEdge = hexNibbleToChar(edge_nib, edge_uppercase)
  assertEqStr(resNom, "4", "hexNibbleToChar nominal string matches")
  assertEqStr(resEdge, "1", "hexNibbleToChar boundary string matches")
  ret 0
```

---

### `hexCharToVal` (`std/encoding/hex.aipl`)

- **Signature**: `fn hexCharToVal(code: int): int:`
- **Import**: `import * from "std/encoding/hex"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `code: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/encoding/hex_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `hexCharToVal` lowercase/uppercase hex encoding, odd-length/non-hex rejection, and 16-byte offset + ASCII gutter hexdump formatting. Concrete nominal inputs: `code: int = 1`; exercises core body path returning/computing `-1`.

```aipl
module tests.functions.encoding.hex_z2_test
import * from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hex_hexCharToVal_2(): int:
  let arg_code = 2
  let edge_code = 0
  let resNom = hexCharToVal(arg_code)
  let resEdge = hexCharToVal(edge_code)
  assertEqInt(resNom, -1, "hexCharToVal nominal resNom == -1")
  assertEqInt(resEdge, -1, "hexCharToVal boundary resEdge == -1")
  ret 0
```

---

### `hexEncode` (`std/encoding/hex.aipl`)

- **Signature**: `pub fn hexEncode(data: bytes, uppercase: bool = false): str:`
- **Import**: `import * from "std/encoding/hex"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes, uppercase: bool = false` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/hex_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `hexEncode` lowercase/uppercase hex encoding, odd-length/non-hex rejection, and 16-byte offset + ASCII gutter hexdump formatting. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`, `uppercase: bool = true`; exercises core body path returning/computing `parts.join("")`.

```aipl
module tests.functions.encoding.hex_z3_test
import * from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hex_hexEncode_3(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let arg_uppercase = true
  let edge_uppercase = false
  let resNom = hexEncode(arg_data, arg_uppercase)
  let resEdge = hexEncode(edge_data, edge_uppercase)
  assertEqStr(resNom, "4149504C", "hexEncode nominal string matches")
  assertEqStr(resEdge, "41", "hexEncode boundary string matches")
  ret 0
```

---

### `hexDecode` (`std/encoding/hex.aipl`)

- **Signature**: `pub fn hexDecode(s: str): Result[bytes, str]:`
- **Import**: `import * from "std/encoding/hex"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `Result[bytes, str]`
- **Unit Test**: `tests/functions/encoding/hex_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `hexDecode` lowercase/uppercase hex encoding, odd-length/non-hex rejection, and 16-byte offset + ASCII gutter hexdump formatting. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `Ok(bytesFromArray(out))`.

```aipl
module tests.functions.encoding.hex_z4_test
import * from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hex_hexDecode_4(): int:
  let arg_s = "4142"
  let edge_s = "00"
  let resNom = hexDecode(arg_s)
  let resEdge = hexDecode(edge_s)
  assert(resNom.isOk() == true, "hexDecode nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "hexDecode boundary resEdge.isOk() == true")
  ret 0
```

---

### `padHex4` (`std/encoding/hex.aipl`)

- **Signature**: `fn padHex4(val: int): str:`
- **Import**: `import * from "std/encoding/hex"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/hex_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `padHex4` lowercase/uppercase hex encoding, odd-length/non-hex rejection, and 16-byte offset + ASCII gutter hexdump formatting. Concrete nominal inputs: `val: int = 1`; exercises core body path returning/computing `chars.join("")`.

```aipl
module tests.functions.encoding.hex_z5_test
import * from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hex_padHex4_5(): int:
  let arg_val = 2
  let edge_val = 0
  let resNom = padHex4(arg_val)
  let resEdge = padHex4(edge_val)
  assertEqStr(resNom, "0002", "padHex4 nominal string matches")
  assertEqStr(resEdge, "0000", "padHex4 boundary string matches")
  ret 0
```

---

### `hexDump` (`std/encoding/hex.aipl`)

- **Signature**: `pub fn hexDump(data: bytes, bytesPerLine: int = 16): str:`
- **Import**: `import * from "std/encoding/hex"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes, bytesPerLine: int = 16` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/hex_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `hexDump` lowercase/uppercase hex encoding, odd-length/non-hex rejection, and 16-byte offset + ASCII gutter hexdump formatting. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`, `bytesPerLine: int = 64`; exercises core body path returning/computing `lines.join("\n")`.

```aipl
module tests.functions.encoding.hex_z6_test
import * from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hex_hexDump_6(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let arg_bytesPerLine = 4
  let edge_bytesPerLine = 1
  let resNom = hexDump(arg_data, arg_bytesPerLine)
  let resEdge = hexDump(edge_data, edge_bytesPerLine)
  assertEqStr(resNom, "0000: 41 49 50 4c  |AIPL|", "hexDump nominal string matches")
  assertEqStr(resEdge, "0000: 41  |A|", "hexDump boundary string matches")
  ret 0
```

---

### `hexDigitChar` (`std/encoding/hex.aipl`)

- **Signature**: `pub fn hexDigitChar(val: int): str:`
- **Import**: `import * from "std/encoding/hex"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/hex_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `hexDigitChar` lowercase/uppercase hex encoding, odd-length/non-hex rejection, and 16-byte offset + ASCII gutter hexdump formatting. Concrete nominal inputs: `val: int = 1`; exercises core body path returning/computing `hexNibbleToChar(val, false)`.

```aipl
module tests.functions.encoding.hex_z7_test
import * from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hex_hexDigitChar_7(): int:
  let arg_val = 2
  let edge_val = 0
  let resNom = hexDigitChar(arg_val)
  let resEdge = hexDigitChar(edge_val)
  assertEqStr(resNom, "2", "hexDigitChar nominal string matches")
  assertEqStr(resEdge, "0", "hexDigitChar boundary string matches")
  ret 0
```

---

### `hexEncodeUpper` (`std/encoding/hex.aipl`)

- **Signature**: `pub fn hexEncodeUpper(data: bytes): str:`
- **Import**: `import * from "std/encoding/hex"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/hex_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `hexEncodeUpper` lowercase/uppercase hex encoding, odd-length/non-hex rejection, and 16-byte offset + ASCII gutter hexdump formatting. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `hexEncode(data, true)`.

```aipl
module tests.functions.encoding.hex_z8_test
import * from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hex_hexEncodeUpper_8(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let resNom = hexEncodeUpper(arg_data)
  let resEdge = hexEncodeUpper(edge_data)
  assertEqStr(resNom, "4149504C", "hexEncodeUpper nominal string matches")
  assertEqStr(resEdge, "41", "hexEncodeUpper boundary string matches")
  ret 0
```

---

### `hexValidate` (`std/encoding/hex.aipl`)

- **Signature**: `pub fn hexValidate(s: str): bool:`
- **Import**: `import * from "std/encoding/hex"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/encoding/hex_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `hexValidate` lowercase/uppercase hex encoding, odd-length/non-hex rejection, and 16-byte offset + ASCII gutter hexdump formatting. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.encoding.hex_z9_test
import * from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hex_hexValidate_9(): int:
  let arg_s = "4142"
  let edge_s = "00"
  let resNom = hexValidate(arg_s)
  let resEdge = hexValidate(edge_s)
  assert(resNom == true, "hexValidate nominal resNom == true")
  assert(resEdge == true, "hexValidate boundary resEdge == true")
  ret 0
```

---

### `formatHexOffset8` (`std/encoding/hex.aipl`)

- **Signature**: `pub fn formatHexOffset8(offset: int): str:`
- **Import**: `import * from "std/encoding/hex"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `offset: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/hex_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `formatHexOffset8` lowercase/uppercase hex encoding, odd-length/non-hex rejection, and 16-byte offset + ASCII gutter hexdump formatting. Concrete nominal inputs: `offset: int = 0`; exercises core body path returning/computing `parts.join("")`.

```aipl
module tests.functions.encoding.hex_z10_test
import * from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hex_formatHexOffset8_10(): int:
  let arg_offset = 1
  let edge_offset = 0
  let resNom = formatHexOffset8(arg_offset)
  let resEdge = formatHexOffset8(edge_offset)
  assertEqStr(resNom, "00000001", "formatHexOffset8 nominal string matches")
  assertEqStr(resEdge, "00000000", "formatHexOffset8 boundary string matches")
  ret 0
```

---

### `formatHexdump` (`std/encoding/hex.aipl`)

- **Signature**: `pub fn formatHexdump(data: bytes): [str]:`
- **Import**: `import * from "std/encoding/hex"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes` | **Returns**: `[str]`
- **Unit Test**: `tests/functions/encoding/hex_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `formatHexdump` lowercase/uppercase hex encoding, odd-length/non-hex rejection, and 16-byte offset + ASCII gutter hexdump formatting. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `lines`.

```aipl
module tests.functions.encoding.hex_z11_test
import * from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hex_formatHexdump_11(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let resNom = formatHexdump(arg_data)
  let resEdge = formatHexdump(edge_data)
  assertEqInt(resNom.len(), 1, "formatHexdump nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "formatHexdump boundary resEdge.len() == 1")
  ret 0
```

---

### `hexdump` (`std/encoding/hex.aipl`)

- **Signature**: `pub fn hexdump(data: bytes): str:`
- **Import**: `import * from "std/encoding/hex"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/hex_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `hexdump` lowercase/uppercase hex encoding, odd-length/non-hex rejection, and 16-byte offset + ASCII gutter hexdump formatting. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `lines.join("\n")`.

```aipl
module tests.functions.encoding.hex_z12_test
import * from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hex_hexdump_12(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let resNom = hexdump(arg_data)
  let resEdge = hexdump(edge_data)
  assertEqInt(resNom.len(), 66, "hexdump nominal string length == 66")
  assertEqInt(resEdge.len(), 63, "hexdump boundary string length == 63")
  ret 0
```

---

### `isVoidHtmlTag` (`std/encoding/html_dom.aipl`)

- **Signature**: `fn isVoidHtmlTag(tag: str): bool:`
- **Import**: `import * from "std/encoding/html_dom"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `tag: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/encoding/html_dom_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `isVoidHtmlTag` (`free fn`) HTML5 DOM tree parser, void elements (`<img>`, `<br>`), CSS selector queries (`#id`, `.class`, `tag`), and XSS `javascript:` URL sanitization. Concrete nominal inputs: `tag: str = "aipl_test"`; exercises core body path returning/computing `t == "br" or t == "hr" or t == "img" or t == "input" or t == "meta" or t == "link" or t == "area" or t == "base" or t == "col" or t == "embed" or t == "source" or t == "track" or t == "wbr"`.

```aipl
module tests.functions.encoding.html_dom_z1_test
import * from "std/encoding/html_dom"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_html_dom_isVoidHtmlTag_1(): int:
  let arg_tag = "test"
  let edge_tag = "a"
  let resNom = isVoidHtmlTag(arg_tag)
  let resEdge = isVoidHtmlTag(edge_tag)
  assert(resNom == false, "isVoidHtmlTag nominal resNom == false")
  assert(resEdge == false, "isVoidHtmlTag boundary resEdge == false")
  ret 0
```

---

### `parseHtmlAttrs` (`std/encoding/html_dom.aipl`)

- **Signature**: `fn parseHtmlAttrs(raw: str): ([(str, str)], str, [str]):`
- **Import**: `import * from "std/encoding/html_dom"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `raw: str` | **Returns**: `([(str, str)], str, [str])`
- **Unit Test**: `tests/functions/encoding/html_dom_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `parseHtmlAttrs` (`free fn`) HTML5 DOM tree parser, void elements (`<img>`, `<br>`), CSS selector queries (`#id`, `.class`, `tag`), and XSS `javascript:` URL sanitization. Concrete nominal inputs: `raw: str): ([(str, str)] = str): (()`, `str: any = 42`, `[str]: any = 42`; exercises core body path returning/computing `(attrs, idVal, classes)`.

```aipl
module tests.functions.encoding.html_dom_z2_test
import * from "std/encoding/html_dom"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_html_dom_parseHtmlAttrs_2(): int:
  let arg_raw = "test"
  let edge_raw = "a"
  let resNom = parseHtmlAttrs(arg_raw)
  let resEdge = parseHtmlAttrs(edge_raw)
  let (n_t0, n_t1, n_t2) = resNom
  let (e_t0, e_t1, e_t2) = resEdge
  assertEqInt(n_t0.len(), 1, "parseHtmlAttrs nominal n_t0.len() == 1")
  assertEqInt(e_t0.len(), 1, "parseHtmlAttrs boundary e_t0.len() == 1")
  ret 0
```

---

### `parseHtmlNodeAt` (`std/encoding/html_dom.aipl`)

- **Signature**: `fn parseHtmlNodeAt(htmlText: str, startPos: int): (int, HtmlNode):`
- **Import**: `import * from "std/encoding/html_dom"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `htmlText: str, startPos: int` | **Returns**: `(int, HtmlNode)`
- **Unit Test**: `tests/functions/encoding/html_dom_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `parseHtmlNodeAt` (`free fn`) HTML5 DOM tree parser, void elements (`<img>`, `<br>`), CSS selector queries (`#id`, `.class`, `tag`), and XSS `javascript:` URL sanitization. Concrete nominal inputs: `htmlText: str = "aipl_test"`, `startPos: int): (int = int): (int()`, `HtmlNode: any = 42`; exercises core body path returning/computing `(cur, HtmlNode(tag = tagName, attributes = attrs, children = children, innerText = textAccum.join("").trim(), id = idVal, classList = classes))`.

```aipl
module tests.functions.encoding.html_dom_z3_test
import * from "std/encoding/html_dom"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_html_dom_parseHtmlNodeAt_3(): int:
  let arg_htmlText = "test"
  let edge_htmlText = "a"
  let arg_startPos = 1
  let edge_startPos = 0
  let resNom = parseHtmlNodeAt(arg_htmlText, arg_startPos)
  let resEdge = parseHtmlNodeAt(edge_htmlText, edge_startPos)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqInt(n_t0, 4, "parseHtmlNodeAt nominal n_t0 == 4")
  assertEqInt(e_t0, 1, "parseHtmlNodeAt boundary e_t0 == 1")
  ret 0
```

---

### `parseHtml` (`std/encoding/html_dom.aipl`)

- **Signature**: `pub fn parseHtml(htmlText: str): HtmlDocument:`
- **Import**: `import * from "std/encoding/html_dom"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `htmlText: str` | **Returns**: `HtmlDocument`
- **Unit Test**: `tests/functions/encoding/html_dom_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `parseHtml` (`free fn`) HTML5 DOM tree parser, void elements (`<img>`, `<br>`), CSS selector queries (`#id`, `.class`, `tag`), and XSS `javascript:` URL sanitization. Concrete nominal inputs: `htmlText: str = "aipl_test"`; exercises core body path returning/computing `HtmlDocument(root = rootNode)`.

```aipl
module tests.functions.encoding.html_dom_z4_test
import * from "std/encoding/html_dom"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_html_dom_parseHtml_4(): int:
  let arg_htmlText = "test"
  let edge_htmlText = "a"
  let resNom = parseHtml(arg_htmlText)
  let resEdge = parseHtml(edge_htmlText)
  assertEqStr(resNom.root.tag, "div", "parseHtml nominal string matches")
  assertEqStr(resEdge.root.tag, "div", "parseHtml boundary string matches")
  ret 0
```

---

### `matchesSelector` (`std/encoding/html_dom.aipl`)

- **Signature**: `fn matchesSelector(node: HtmlNode, selector: str): bool:`
- **Import**: `import * from "std/encoding/html_dom"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `node: HtmlNode, selector: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/encoding/html_dom_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `matchesSelector` (`free fn`) HTML5 DOM tree parser, void elements (`<img>`, `<br>`), CSS selector queries (`#id`, `.class`, `tag`), and XSS `javascript:` URL sanitization. Concrete nominal inputs: `node: HtmlNode = HtmlNode(tag = "aipl_test", attributes = [(str, str)()], children = [HtmlNode(tag = 0, attributes = 0, children = 0, innerText = 0, id = 0, classList = 0)], innerText = "aipl_test", id = "aipl_test", classList = ["aipl_test"])`, `selector: str = "aipl_test"`; exercises core body path returning/computing `node.tag == sel.toLower()`.

```aipl
module tests.functions.encoding.html_dom_z5_test
import * from "std/encoding/html_dom"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_html_dom_matchesSelector_5(): int:
  let arg_node = HtmlNode(tag = "test", attributes = [], children = [], innerText = "test", id = "test", classList = [])
  let edge_node = HtmlNode(tag = "a", attributes = [], children = [], innerText = "a", id = "a", classList = [])
  let arg_selector = "test"
  let edge_selector = "a"
  let resNom = matchesSelector(arg_node, arg_selector)
  let resEdge = matchesSelector(edge_node, edge_selector)
  assert(resNom == true, "matchesSelector nominal resNom == true")
  assert(resEdge == true, "matchesSelector boundary resEdge == true")
  ret 0
```

---

### `collectMatchingHtmlNodes` (`std/encoding/html_dom.aipl`)

- **Signature**: `fn collectMatchingHtmlNodes(node: HtmlNode, selector: str, mut acc: [HtmlNode]): [HtmlNode]:`
- **Import**: `import * from "std/encoding/html_dom"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `node: HtmlNode, selector: str, mut acc: [HtmlNode]` | **Returns**: `[HtmlNode]`
- **Unit Test**: `tests/functions/encoding/html_dom_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `collectMatchingHtmlNodes` (`free fn`) HTML5 DOM tree parser, void elements (`<img>`, `<br>`), CSS selector queries (`#id`, `.class`, `tag`), and XSS `javascript:` URL sanitization. Concrete nominal inputs: `node: HtmlNode = HtmlNode(tag = "aipl_test", attributes = [(str, str)()], children = [HtmlNode(tag = 0, attributes = 0, children = 0, innerText = 0, id = 0, classList = 0)], innerText = "aipl_test", id = "aipl_test", classList = ["aipl_test"])`, `selector: str = "aipl_test"`, `acc: [HtmlNode] = [HtmlNode(tag = "aipl_test", attributes = [0], children = [0], innerText = "aipl_test", id = "aipl_test", classList = [0])]`; exercises core body path returning/computing `acc`.

```aipl
module tests.functions.encoding.html_dom_z6_test
import * from "std/encoding/html_dom"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_html_dom_collectMatchingHtmlNodes_6(): int:
  let arg_node = HtmlNode(tag = "test", attributes = [], children = [], innerText = "test", id = "test", classList = [])
  let edge_node = HtmlNode(tag = "a", attributes = [], children = [], innerText = "a", id = "a", classList = [])
  let arg_selector = "test"
  let edge_selector = "a"
  let arg_acc = [HtmlNode(tag = "test", attributes = [], children = [], innerText = "test", id = "test", classList = [])]
  let edge_acc = []
  let resNom = collectMatchingHtmlNodes(arg_node, arg_selector, arg_acc)
  let resEdge = collectMatchingHtmlNodes(edge_node, edge_selector, edge_acc)
  assertEqInt(resNom.len(), 2, "collectMatchingHtmlNodes nominal resNom.len() == 2")
  assertEqInt(resEdge.len(), 1, "collectMatchingHtmlNodes boundary resEdge.len() == 1")
  ret 0
```

---

### `querySelectorAll` (`std/encoding/html_dom.aipl`)

- **Signature**: `pub fn (self: HtmlDocument) querySelectorAll(selector: str): [HtmlNode]:`
- **Import**: `import * from "std/encoding/html_dom"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `self: HtmlDocument` | **Parameters**: `selector: str` | **Returns**: `[HtmlNode]`
- **Unit Test**: `tests/functions/encoding/html_dom_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `querySelectorAll` (`self: HtmlDocument`) HTML5 DOM tree parser, void elements (`<img>`, `<br>`), CSS selector queries (`#id`, `.class`, `tag`), and XSS `javascript:` URL sanitization. Concrete nominal inputs: receiver `recvObj: HtmlDocument = HtmlDocument(root = HtmlNode(tag = "aipl_test", attributes = [0], children = [0], innerText = "aipl_test", id = "aipl_test", classList = [0]))`, `selector: str = "aipl_test"`; exercises core body path returning/computing `collectMatchingHtmlNodes(self.root, selector, acc)`.

```aipl
module tests.functions.encoding.html_dom_z7_test
import * from "std/encoding/html_dom"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_html_dom_HtmlDocument_querySelectorAll_7(): int:
  let recv_self = HtmlDocument(root = HtmlNode(tag = "test", attributes = [], children = [], innerText = "test", id = "test", classList = []))
  let edge_self = HtmlDocument(root = HtmlNode(tag = "a", attributes = [], children = [], innerText = "a", id = "a", classList = []))
  let arg_selector = "test"
  let edge_selector = "a"
  let resNom = recv_self.querySelectorAll(arg_selector)
  let resEdge = edge_self.querySelectorAll(edge_selector)
  assertEqInt(resNom.len(), 1, "querySelectorAll nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "querySelectorAll boundary resEdge.len() == 1")
  ret 0
```

---

### `querySelector` (`std/encoding/html_dom.aipl`)

- **Signature**: `pub fn (self: HtmlDocument) querySelector(selector: str): Option[HtmlNode]:`
- **Import**: `import * from "std/encoding/html_dom"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `self: HtmlDocument` | **Parameters**: `selector: str` | **Returns**: `Option[HtmlNode]`
- **Unit Test**: `tests/functions/encoding/html_dom_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `querySelector` (`self: HtmlDocument`) HTML5 DOM tree parser, void elements (`<img>`, `<br>`), CSS selector queries (`#id`, `.class`, `tag`), and XSS `javascript:` URL sanitization. Concrete nominal inputs: receiver `recvObj: HtmlDocument = HtmlDocument(root = HtmlNode(tag = "aipl_test", attributes = [0], children = [0], innerText = "aipl_test", id = "aipl_test", classList = [0]))`, `selector: str = "aipl_test"`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.encoding.html_dom_z8_test
import * from "std/encoding/html_dom"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_html_dom_HtmlDocument_querySelector_8(): int:
  let recv_self = HtmlDocument(root = HtmlNode(tag = "test", attributes = [], children = [], innerText = "test", id = "test", classList = []))
  let edge_self = HtmlDocument(root = HtmlNode(tag = "a", attributes = [], children = [], innerText = "a", id = "a", classList = []))
  let arg_selector = "test"
  let edge_selector = "a"
  let resNom = recv_self.querySelector(arg_selector)
  let resEdge = edge_self.querySelector(edge_selector)
  assert(resNom.isSome() == true, "querySelector nominal resNom.isSome() == true")
  assert(resEdge.isSome() == true, "querySelector boundary resEdge.isSome() == true")
  ret 0
```

---

### `getElementById` (`std/encoding/html_dom.aipl`)

- **Signature**: `pub fn (self: HtmlNode) getElementById(id: str): Option[HtmlNode]:`
- **Import**: `import * from "std/encoding/html_dom"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `self: HtmlNode` | **Parameters**: `id: str` | **Returns**: `Option[HtmlNode]`
- **Unit Test**: `tests/functions/encoding/html_dom_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `getElementById` (`self: HtmlNode`) HTML5 DOM tree parser, void elements (`<img>`, `<br>`), CSS selector queries (`#id`, `.class`, `tag`), and XSS `javascript:` URL sanitization. Concrete nominal inputs: receiver `recvObj: HtmlNode = HtmlNode(tag = "aipl_test", attributes = [(str, str)()], children = [HtmlNode(tag = 0, attributes = 0, children = 0, innerText = 0, id = 0, classList = 0)], innerText = "aipl_test", id = "aipl_test", classList = ["aipl_test"])`, `id: str = "aipl_test"`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.encoding.html_dom_z9_test
import * from "std/encoding/html_dom"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_html_dom_HtmlNode_getElementById_9(): int:
  let recv_self = HtmlNode(tag = "test", attributes = [], children = [], innerText = "test", id = "test", classList = [])
  let edge_self = HtmlNode(tag = "a", attributes = [], children = [], innerText = "a", id = "a", classList = [])
  let arg_id = "test"
  let edge_id = "a"
  let resNom = recv_self.getElementById(arg_id)
  let resEdge = edge_self.getElementById(edge_id)
  assert(resNom.isSome() == true, "getElementById nominal resNom.isSome() == true")
  assert(resEdge.isSome() == true, "getElementById boundary resEdge.isSome() == true")
  ret 0
```

---

### `getElementsByClassName` (`std/encoding/html_dom.aipl`)

- **Signature**: `pub fn (self: HtmlNode) getElementsByClassName(className: str): [HtmlNode]:`
- **Import**: `import * from "std/encoding/html_dom"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `self: HtmlNode` | **Parameters**: `className: str` | **Returns**: `[HtmlNode]`
- **Unit Test**: `tests/functions/encoding/html_dom_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `getElementsByClassName` (`self: HtmlNode`) HTML5 DOM tree parser, void elements (`<img>`, `<br>`), CSS selector queries (`#id`, `.class`, `tag`), and XSS `javascript:` URL sanitization. Concrete nominal inputs: receiver `recvObj: HtmlNode = HtmlNode(tag = "aipl_test", attributes = [(str, str)()], children = [HtmlNode(tag = 0, attributes = 0, children = 0, innerText = 0, id = 0, classList = 0)], innerText = "aipl_test", id = "aipl_test", classList = ["aipl_test"])`, `className: str = "aipl_test"`; exercises core body path returning/computing `collectMatchingHtmlNodes(self, "." + className, acc)`.

```aipl
module tests.functions.encoding.html_dom_z10_test
import * from "std/encoding/html_dom"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_html_dom_HtmlNode_getElementsByClassName_10(): int:
  let recv_self = HtmlNode(tag = "test", attributes = [], children = [], innerText = "test", id = "test", classList = [])
  let edge_self = HtmlNode(tag = "a", attributes = [], children = [], innerText = "a", id = "a", classList = [])
  let arg_className = "test"
  let edge_className = "a"
  let resNom = recv_self.getElementsByClassName(arg_className)
  let resEdge = edge_self.getElementsByClassName(edge_className)
  assertEqInt(resNom.len(), 0, "getElementsByClassName nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "getElementsByClassName boundary resEdge.len() == 0")
  ret 0
```

---

### `escapeHtml` (`std/encoding/html_dom.aipl`)

- **Signature**: `pub fn escapeHtml(s: str): str:`
- **Import**: `import * from "std/encoding/html_dom"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/html_dom_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `escapeHtml` (`free fn`) HTML5 DOM tree parser, void elements (`<img>`, `<br>`), CSS selector queries (`#id`, `.class`, `tag`), and XSS `javascript:` URL sanitization. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `s.replace("&", "&amp;").replace("<", "&lt;").replace(">", "&gt;").replace("\"", "&quot;").replace("'", "&#39;")`.

```aipl
module tests.functions.encoding.html_dom_z11_test
import * from "std/encoding/html_dom"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_html_dom_escapeHtml_11(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = escapeHtml(arg_s)
  let resEdge = escapeHtml(edge_s)
  assertEqStr(resNom, "test", "escapeHtml nominal string matches")
  assertEqStr(resEdge, "a", "escapeHtml boundary string matches")
  ret 0
```

---

### `htmlEscape` (`std/encoding/html_dom.aipl`)

- **Signature**: `pub fn htmlEscape(s: str): str:`
- **Import**: `import * from "std/encoding/html_dom"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/html_dom_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `htmlEscape` (`free fn`) HTML5 DOM tree parser, void elements (`<img>`, `<br>`), CSS selector queries (`#id`, `.class`, `tag`), and XSS `javascript:` URL sanitization. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `escapeHtml(s)`.

```aipl
module tests.functions.encoding.html_dom_z12_test
import * from "std/encoding/html_dom"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_html_dom_htmlEscape_12(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = htmlEscape(arg_s)
  let resEdge = htmlEscape(edge_s)
  assertEqStr(resNom, "test", "htmlEscape nominal string matches")
  assertEqStr(resEdge, "a", "htmlEscape boundary string matches")
  ret 0
```

---

### `htmlUnescape` (`std/encoding/html_dom.aipl`)

- **Signature**: `pub fn htmlUnescape(s: str): str:`
- **Import**: `import * from "std/encoding/html_dom"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/html_dom_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `htmlUnescape` (`free fn`) HTML5 DOM tree parser, void elements (`<img>`, `<br>`), CSS selector queries (`#id`, `.class`, `tag`), and XSS `javascript:` URL sanitization. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `s.replace("&lt;", "<").replace("&gt;", ">").replace("&quot;", "\"").replace("&#39;", "'").replace("&apos;", "'").replace("&amp;", "&")`.

```aipl
module tests.functions.encoding.html_dom_z13_test
import * from "std/encoding/html_dom"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_html_dom_htmlUnescape_13(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = htmlUnescape(arg_s)
  let resEdge = htmlUnescape(edge_s)
  assertEqStr(resNom, "test", "htmlUnescape nominal string matches")
  assertEqStr(resEdge, "a", "htmlUnescape boundary string matches")
  ret 0
```

---

### `unescapeHtml` (`std/encoding/html_dom.aipl`)

- **Signature**: `pub fn unescapeHtml(s: str): str:`
- **Import**: `import * from "std/encoding/html_dom"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/html_dom_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `unescapeHtml` (`free fn`) HTML5 DOM tree parser, void elements (`<img>`, `<br>`), CSS selector queries (`#id`, `.class`, `tag`), and XSS `javascript:` URL sanitization. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `htmlUnescape(s)`.

```aipl
module tests.functions.encoding.html_dom_z14_test
import * from "std/encoding/html_dom"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_html_dom_unescapeHtml_14(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = unescapeHtml(arg_s)
  let resEdge = unescapeHtml(edge_s)
  assertEqStr(resNom, "test", "unescapeHtml nominal string matches")
  assertEqStr(resEdge, "a", "unescapeHtml boundary string matches")
  ret 0
```

---

### `sanitizeUrl` (`std/encoding/html_dom.aipl`)

- **Signature**: `pub fn sanitizeUrl(url: str): str:`
- **Import**: `import * from "std/encoding/html_dom"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `url: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/html_dom_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `sanitizeUrl` (`free fn`) HTML5 DOM tree parser, void elements (`<img>`, `<br>`), CSS selector queries (`#id`, `.class`, `tag`), and XSS `javascript:` URL sanitization. Concrete nominal inputs: `url: str = "https://example.com/api"`; exercises core body path returning/computing `trimmed`.

```aipl
module tests.functions.encoding.html_dom_z15_test
import * from "std/encoding/html_dom"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_html_dom_sanitizeUrl_15(): int:
  let arg_url = "http://localhost/test"
  let edge_url = "http://localhost/test"
  let resNom = sanitizeUrl(arg_url)
  let resEdge = sanitizeUrl(edge_url)
  assertEqStr(resNom, "http://localhost/test", "sanitizeUrl nominal string matches")
  assertEqStr(resEdge, "http://localhost/test", "sanitizeUrl boundary string matches")
  ret 0
```

---

### `innerText` (`std/encoding/html_dom.aipl`)

- **Signature**: `pub fn innerText(node: HtmlNode): str:`
- **Import**: `import * from "std/encoding/html_dom"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `node: HtmlNode` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/html_dom_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `innerText` (`free fn`) HTML5 DOM tree parser, void elements (`<img>`, `<br>`), CSS selector queries (`#id`, `.class`, `tag`), and XSS `javascript:` URL sanitization. Concrete nominal inputs: `node: HtmlNode = HtmlNode(tag = "aipl_test", attributes = [(str, str)()], children = [HtmlNode(tag = 0, attributes = 0, children = 0, innerText = 0, id = 0, classList = 0)], innerText = "aipl_test", id = "aipl_test", classList = ["aipl_test"])`; exercises core body path returning/computing `parts.join(" ").trim()`.

```aipl
module tests.functions.encoding.html_dom_z16_test
import * from "std/encoding/html_dom"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_html_dom_innerText_16(): int:
  let arg_node = HtmlNode(tag = "test", attributes = [], children = [], innerText = "test", id = "test", classList = [])
  let edge_node = HtmlNode(tag = "a", attributes = [], children = [], innerText = "a", id = "a", classList = [])
  let resNom = innerText(arg_node)
  let resEdge = innerText(edge_node)
  assertEqStr(resNom, "test", "innerText nominal string matches")
  assertEqStr(resEdge, "a", "innerText boundary string matches")
  ret 0
```

---

### `htmlToPlainText` (`std/encoding/html_dom.aipl`)

- **Signature**: `pub fn htmlToPlainText(html: str): str:`
- **Import**: `import * from "std/encoding/html_dom"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `html: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/html_dom_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `htmlToPlainText` (`free fn`) HTML5 DOM tree parser, void elements (`<img>`, `<br>`), CSS selector queries (`#id`, `.class`, `tag`), and XSS `javascript:` URL sanitization. Concrete nominal inputs: `html: str = "aipl_test"`; exercises core body path returning/computing `innerText(doc.root)`.

```aipl
module tests.functions.encoding.html_dom_z17_test
import * from "std/encoding/html_dom"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_html_dom_htmlToPlainText_17(): int:
  let arg_html = "42"
  let edge_html = "0"
  let resNom = htmlToPlainText(arg_html)
  let resEdge = htmlToPlainText(edge_html)
  assertEqStr(resNom, "42", "htmlToPlainText nominal string matches")
  assertEqStr(resEdge, "0", "htmlToPlainText boundary string matches")
  ret 0
```

---

### `htmlNodeAttr` (`std/encoding/html_dom.aipl`)

- **Signature**: `pub fn htmlNodeAttr(node: HtmlNode, attrName: str): Option[str]:`
- **Import**: `import * from "std/encoding/html_dom"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `node: HtmlNode, attrName: str` | **Returns**: `Option[str]`
- **Unit Test**: `tests/functions/encoding/html_dom_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `htmlNodeAttr` (`free fn`) HTML5 DOM tree parser, void elements (`<img>`, `<br>`), CSS selector queries (`#id`, `.class`, `tag`), and XSS `javascript:` URL sanitization. Concrete nominal inputs: `node: HtmlNode = HtmlNode(tag = "aipl_test", attributes = [(str, str)()], children = [HtmlNode(tag = 0, attributes = 0, children = 0, innerText = 0, id = 0, classList = 0)], innerText = "aipl_test", id = "aipl_test", classList = ["aipl_test"])`, `attrName: str = "aipl_test"`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.encoding.html_dom_z18_test
import * from "std/encoding/html_dom"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_html_dom_htmlNodeAttr_18(): int:
  let arg_node = HtmlNode(tag = "test", attributes = [], children = [], innerText = "test", id = "test", classList = [])
  let edge_node = HtmlNode(tag = "a", attributes = [], children = [], innerText = "a", id = "a", classList = [])
  let arg_attrName = "test"
  let edge_attrName = "a"
  let resNom = htmlNodeAttr(arg_node, arg_attrName)
  let resEdge = htmlNodeAttr(edge_node, edge_attrName)
  assert(resNom.isSome() == false, "htmlNodeAttr nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "htmlNodeAttr boundary resEdge.isSome() == false")
  ret 0
```

---

### `formatHtml` (`std/encoding/html_dom.aipl`)

- **Signature**: `pub fn formatHtml(node: HtmlNode): str:`
- **Import**: `import * from "std/encoding/html_dom"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `node: HtmlNode` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/html_dom_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `formatHtml` (`free fn`) HTML5 DOM tree parser, void elements (`<img>`, `<br>`), CSS selector queries (`#id`, `.class`, `tag`), and XSS `javascript:` URL sanitization. Concrete nominal inputs: `node: HtmlNode = HtmlNode(tag = "aipl_test", attributes = [(str, str)()], children = [HtmlNode(tag = 0, attributes = 0, children = 0, innerText = 0, id = 0, classList = 0)], innerText = "aipl_test", id = "aipl_test", classList = ["aipl_test"])`; exercises core body path returning/computing `openTag + childParts.join("") + closeTag`.

```aipl
module tests.functions.encoding.html_dom_z19_test
import * from "std/encoding/html_dom"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_html_dom_formatHtml_19(): int:
  let arg_node = HtmlNode(tag = "test", attributes = [], children = [], innerText = "test", id = "test", classList = [])
  let edge_node = HtmlNode(tag = "a", attributes = [], children = [], innerText = "a", id = "a", classList = [])
  let resNom = formatHtml(arg_node)
  let resEdge = formatHtml(edge_node)
  assertEqStr(resNom, "<test>test</test>", "formatHtml nominal string matches")
  assertEqStr(resEdge, "<a>a</a>", "formatHtml boundary string matches")
  ret 0
```

---

### `toHtml` (`std/encoding/html_dom.aipl`)

- **Signature**: `pub fn toHtml(doc: HtmlDocument): str:`
- **Import**: `import * from "std/encoding/html_dom"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `doc: HtmlDocument` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/html_dom_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `toHtml` (`free fn`) HTML5 DOM tree parser, void elements (`<img>`, `<br>`), CSS selector queries (`#id`, `.class`, `tag`), and XSS `javascript:` URL sanitization. Concrete nominal inputs: `doc: HtmlDocument = HtmlDocument(root = HtmlNode(tag = "aipl_test", attributes = [0], children = [0], innerText = "aipl_test", id = "aipl_test", classList = [0]))`; exercises core body path returning/computing `formatHtml(doc.root)`.

```aipl
module tests.functions.encoding.html_dom_z20_test
import * from "std/encoding/html_dom"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_html_dom_toHtml_20(): int:
  let arg_doc = HtmlDocument(root = HtmlNode(tag = "test", attributes = [], children = [], innerText = "test", id = "test", classList = []))
  let edge_doc = HtmlDocument(root = HtmlNode(tag = "a", attributes = [], children = [], innerText = "a", id = "a", classList = []))
  let resNom = toHtml(arg_doc)
  let resEdge = toHtml(edge_doc)
  assertEqStr(resNom, "<test>test</test>", "toHtml nominal string matches")
  assertEqStr(resEdge, "<a>a</a>", "toHtml boundary string matches")
  ret 0
```

---

### `stripIniInlineComment` (`std/encoding/ini_dotenv.aipl`)

- **Signature**: `fn stripIniInlineComment(line: str): str:`
- **Import**: `import * from "std/encoding/ini_dotenv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `line: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/ini_dotenv_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `stripIniInlineComment` (`free fn`) INI section and `.env` `export KEY=VAL` loader, quote unwrapping, and required-key schema validation. Concrete nominal inputs: `line: str = "aipl_test"`; exercises core body path returning/computing `line.trim()`.

```aipl
module tests.functions.encoding.ini_dotenv_z1_test
import * from "std/encoding/ini_dotenv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ini_dotenv_stripIniInlineComment_1(): int:
  let arg_line = "[s]\nk=v"
  let edge_line = "[s]\nk=v"
  let resNom = stripIniInlineComment(arg_line)
  let resEdge = stripIniInlineComment(edge_line)
  assertEqInt(resNom.len(), 7, "stripIniInlineComment nominal string length == 7")
  assertEqInt(resEdge.len(), 7, "stripIniInlineComment boundary string length == 7")
  ret 0
```

---

### `unquoteIniVal` (`std/encoding/ini_dotenv.aipl`)

- **Signature**: `fn unquoteIniVal(v: str): str:`
- **Import**: `import * from "std/encoding/ini_dotenv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/ini_dotenv_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `unquoteIniVal` (`free fn`) INI section and `.env` `export KEY=VAL` loader, quote unwrapping, and required-key schema validation. Concrete nominal inputs: `v: str = "aipl_test"`; exercises core body path returning/computing `t`.

```aipl
module tests.functions.encoding.ini_dotenv_z2_test
import * from "std/encoding/ini_dotenv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ini_dotenv_unquoteIniVal_2(): int:
  let arg_v = "[s]\nk=v"
  let edge_v = "[s]\nk=v"
  let resNom = unquoteIniVal(arg_v)
  let resEdge = unquoteIniVal(edge_v)
  assertEqInt(resNom.len(), 7, "unquoteIniVal nominal string length == 7")
  assertEqInt(resEdge.len(), 7, "unquoteIniVal boundary string length == 7")
  ret 0
```

---

### `parseIni` (`std/encoding/ini_dotenv.aipl`)

- **Signature**: `pub fn parseIni(text: str): Result[IniDocument, str]:`
- **Import**: `import * from "std/encoding/ini_dotenv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str` | **Returns**: `Result[IniDocument, str]`
- **Unit Test**: `tests/functions/encoding/ini_dotenv_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `parseIni` (`free fn`) INI section and `.env` `export KEY=VAL` loader, quote unwrapping, and required-key schema validation. Concrete nominal inputs: `text: str = "aipl_test"`; exercises core body path returning/computing `Ok(IniDocument(sections = sections))`.

```aipl
module tests.functions.encoding.ini_dotenv_z3_test
import * from "std/encoding/ini_dotenv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ini_dotenv_parseIni_3(): int:
  let arg_text = "[s]\nk=v"
  let edge_text = "[s]\nk=v"
  let resNom = parseIni(arg_text)
  let resEdge = parseIni(edge_text)
  assert(resNom.isOk() == true, "parseIni nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "parseIni boundary resEdge.isOk() == true")
  ret 0
```

---

### `get` (`std/encoding/ini_dotenv.aipl`)

- **Signature**: `pub fn (self: IniDocument) get(section: str, key: str): Option[str]:`
- **Import**: `import * from "std/encoding/ini_dotenv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `self: IniDocument` | **Parameters**: `section: str, key: str` | **Returns**: `Option[str]`
- **Unit Test**: `tests/functions/encoding/ini_dotenv_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `get` (`self: IniDocument`) INI section and `.env` `export KEY=VAL` loader, quote unwrapping, and required-key schema validation. Concrete nominal inputs: receiver `recvObj: IniDocument = IniDocument(sections = [(str, [(str, str)])()])`, `section: str = "aipl_test"`, `key: str = "aipl_test"`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.encoding.ini_dotenv_z4_test
import * from "std/encoding/ini_dotenv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ini_dotenv_IniDocument_get_4(): int:
  let recv_self = IniDocument(sections = [])
  let edge_self = IniDocument(sections = [])
  let arg_section = "test"
  let edge_section = "a"
  let arg_key = "test"
  let edge_key = "a"
  let resNom = recv_self.get(arg_section, arg_key)
  let resEdge = edge_self.get(edge_section, edge_key)
  assert(resNom.isSome() == false, "get nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "get boundary resEdge.isSome() == false")
  ret 0
```

---

### `serializeIni` (`std/encoding/ini_dotenv.aipl`)

- **Signature**: `pub fn serializeIni(doc: IniDocument): str:`
- **Import**: `import * from "std/encoding/ini_dotenv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `doc: IniDocument` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/ini_dotenv_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `serializeIni` (`free fn`) INI section and `.env` `export KEY=VAL` loader, quote unwrapping, and required-key schema validation. Concrete nominal inputs: `doc: IniDocument = IniDocument(sections = [(str, [(str, str)])()])`; exercises core body path returning/computing `lines.join("\n")`.

```aipl
module tests.functions.encoding.ini_dotenv_z5_test
import * from "std/encoding/ini_dotenv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ini_dotenv_serializeIni_5(): int:
  let arg_doc = IniDocument(sections = [])
  let edge_doc = IniDocument(sections = [])
  let resNom = serializeIni(arg_doc)
  let resEdge = serializeIni(edge_doc)
  assertEqStr(resNom, "", "serializeIni nominal string matches")
  assertEqStr(resEdge, "", "serializeIni boundary string matches")
  ret 0
```

---

### `parseDotEnv` (`std/encoding/ini_dotenv.aipl`)

- **Signature**: `pub fn parseDotEnv(text: str): DotEnvMap:`
- **Import**: `import * from "std/encoding/ini_dotenv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str` | **Returns**: `DotEnvMap`
- **Unit Test**: `tests/functions/encoding/ini_dotenv_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `parseDotEnv` (`free fn`) INI section and `.env` `export KEY=VAL` loader, quote unwrapping, and required-key schema validation. Concrete nominal inputs: `text: str = "aipl_test"`; exercises core body path returning/computing `DotEnvMap(entries = entries)`.

```aipl
module tests.functions.encoding.ini_dotenv_z6_test
import * from "std/encoding/ini_dotenv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ini_dotenv_parseDotEnv_6(): int:
  let arg_text = "test"
  let edge_text = "a"
  let resNom = parseDotEnv(arg_text)
  let resEdge = parseDotEnv(edge_text)
  assertEqInt(resNom.entries.len(), 0, "parseDotEnv nominal resNom.entries.len() == 0")
  assertEqInt(resEdge.entries.len(), 0, "parseDotEnv boundary resEdge.entries.len() == 0")
  ret 0
```

---

### `get` (`std/encoding/ini_dotenv.aipl`)

- **Signature**: `pub fn (self: DotEnvMap) get(key: str, fallback: str = ""): str:`
- **Import**: `import * from "std/encoding/ini_dotenv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `self: DotEnvMap` | **Parameters**: `key: str, fallback: str = ""` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/ini_dotenv_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `get` (`self: DotEnvMap`) INI section and `.env` `export KEY=VAL` loader, quote unwrapping, and required-key schema validation. Concrete nominal inputs: receiver `recvObj: DotEnvMap = DotEnvMap(entries = [(str, str)()])`, `key: str = "aipl_test"`, `fallback: str = "aipl_test"`; exercises core body path returning/computing `fallback`.

```aipl
module tests.functions.encoding.ini_dotenv_z7_test
import * from "std/encoding/ini_dotenv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ini_dotenv_DotEnvMap_get_7(): int:
  let recv_self = DotEnvMap(entries = [])
  let edge_self = DotEnvMap(entries = [])
  let arg_key = "test"
  let edge_key = "a"
  let arg_fallback = "test"
  let edge_fallback = "a"
  let resNom = recv_self.get(arg_key, arg_fallback)
  let resEdge = edge_self.get(edge_key, edge_fallback)
  assertEqStr(resNom, "test", "get nominal string matches")
  assertEqStr(resEdge, "a", "get boundary string matches")
  ret 0
```

---

### `containsKey` (`std/encoding/ini_dotenv.aipl`)

- **Signature**: `pub fn (self: DotEnvMap) containsKey(key: str): bool:`
- **Import**: `import * from "std/encoding/ini_dotenv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `self: DotEnvMap` | **Parameters**: `key: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/encoding/ini_dotenv_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `containsKey` (`self: DotEnvMap`) INI section and `.env` `export KEY=VAL` loader, quote unwrapping, and required-key schema validation. Concrete nominal inputs: receiver `recvObj: DotEnvMap = DotEnvMap(entries = [(str, str)()])`, `key: str = "aipl_test"`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.encoding.ini_dotenv_z8_test
import * from "std/encoding/ini_dotenv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ini_dotenv_DotEnvMap_containsKey_8(): int:
  let recv_self = DotEnvMap(entries = [])
  let edge_self = DotEnvMap(entries = [])
  let arg_key = "test"
  let edge_key = "a"
  let resNom = recv_self.containsKey(arg_key)
  let resEdge = edge_self.containsKey(edge_key)
  assert(resNom == false, "containsKey nominal resNom == false")
  assert(resEdge == false, "containsKey boundary resEdge == false")
  ret 0
```

---

### `fastIniGetValue` (`std/encoding/ini_dotenv.aipl`)

- **Signature**: `pub fn fastIniGetValue(iniText: str, section: str, key: str, defaultVal: str): str:`
- **Import**: `import * from "std/encoding/ini_dotenv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `iniText: str, section: str, key: str, defaultVal: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/ini_dotenv_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `fastIniGetValue` (`free fn`) INI section and `.env` `export KEY=VAL` loader, quote unwrapping, and required-key schema validation. Concrete nominal inputs: `iniText: str = "aipl_test"`, `section: str = "aipl_test"`, `key: str = "aipl_test"`, `defaultVal: str = "aipl_test"`; exercises core body path returning/computing `valOpt.unwrap()`.

```aipl
module tests.functions.encoding.ini_dotenv_z9_test
import * from "std/encoding/ini_dotenv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ini_dotenv_fastIniGetValue_9(): int:
  let arg_iniText = "[s]\nk=v"
  let edge_iniText = "[s]\nk=v"
  let arg_section = "[s]\nk=v"
  let edge_section = "[s]\nk=v"
  let arg_key = "[s]\nk=v"
  let edge_key = "[s]\nk=v"
  let arg_defaultVal = "[s]\nk=v"
  let edge_defaultVal = "[s]\nk=v"
  let resNom = fastIniGetValue(arg_iniText, arg_section, arg_key, arg_defaultVal)
  let resEdge = fastIniGetValue(edge_iniText, edge_section, edge_key, edge_defaultVal)
  assertEqInt(resNom.len(), 7, "fastIniGetValue nominal string length == 7")
  assertEqInt(resEdge.len(), 7, "fastIniGetValue boundary string length == 7")
  ret 0
```

---

### `parseDotenv` (`std/encoding/ini_dotenv.aipl`)

- **Signature**: `pub fn parseDotenv(text: str): Map[str, str]:`
- **Import**: `import * from "std/encoding/ini_dotenv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str` | **Returns**: `Map[str, str]`
- **Unit Test**: `tests/functions/encoding/ini_dotenv_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `parseDotenv` (`free fn`) INI section and `.env` `export KEY=VAL` loader, quote unwrapping, and required-key schema validation. Concrete nominal inputs: `text: str = "aipl_test"`; exercises core body path returning/computing `m`.

```aipl
module tests.functions.encoding.ini_dotenv_z10_test
import * from "std/encoding/ini_dotenv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ini_dotenv_parseDotenv_10(): int:
  let arg_text = "test"
  let edge_text = "a"
  let resNom = parseDotenv(arg_text)
  let resEdge = parseDotenv(edge_text)
  assertEqInt(resNom.len(), 0, "parseDotenv nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "parseDotenv boundary resEdge.len() == 0")
  ret 0
```

---

### `loadDotEnv` (`std/encoding/ini_dotenv.aipl`)

- **Signature**: `pub fn loadDotEnv(text: str): Map[str, str]:`
- **Import**: `import * from "std/encoding/ini_dotenv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str` | **Returns**: `Map[str, str]`
- **Unit Test**: `tests/functions/encoding/ini_dotenv_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `loadDotEnv` (`free fn`) INI section and `.env` `export KEY=VAL` loader, quote unwrapping, and required-key schema validation. Concrete nominal inputs: `text: str = "aipl_test"`; exercises core body path returning/computing `parseDotenv(text)`.

```aipl
module tests.functions.encoding.ini_dotenv_z11_test
import * from "std/encoding/ini_dotenv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ini_dotenv_loadDotEnv_11(): int:
  let arg_text = "test"
  let edge_text = "a"
  let resNom = loadDotEnv(arg_text)
  let resEdge = loadDotEnv(edge_text)
  assertEqInt(resNom.len(), 0, "loadDotEnv nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "loadDotEnv boundary resEdge.len() == 0")
  ret 0
```

---

### `loadDotenv` (`std/encoding/ini_dotenv.aipl`)

- **Signature**: `pub fn loadDotenv(text: str): Map[str, str]:`
- **Import**: `import * from "std/encoding/ini_dotenv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str` | **Returns**: `Map[str, str]`
- **Unit Test**: `tests/functions/encoding/ini_dotenv_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `loadDotenv` (`free fn`) INI section and `.env` `export KEY=VAL` loader, quote unwrapping, and required-key schema validation. Concrete nominal inputs: `text: str = "aipl_test"`; exercises core body path returning/computing `parseDotenv(text)`.

```aipl
module tests.functions.encoding.ini_dotenv_z12_test
import * from "std/encoding/ini_dotenv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ini_dotenv_loadDotenv_12(): int:
  let arg_text = "test"
  let edge_text = "a"
  let resNom = loadDotenv(arg_text)
  let resEdge = loadDotenv(edge_text)
  assertEqInt(resNom.len(), 0, "loadDotenv nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "loadDotenv boundary resEdge.len() == 0")
  ret 0
```

---

### `validateDotEnvSchema` (`std/encoding/ini_dotenv.aipl`)

- **Signature**: `pub fn validateDotEnvSchema(envMap: Map[str, str], requiredKeys: [str]): Result[bool, [str]]:`
- **Import**: `import * from "std/encoding/ini_dotenv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `envMap: Map[str, str], requiredKeys: [str]` | **Returns**: `Result[bool, [str]]`
- **Unit Test**: `tests/functions/encoding/ini_dotenv_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `validateDotEnvSchema` (`free fn`) INI section and `.env` `export KEY=VAL` loader, quote unwrapping, and required-key schema validation. Concrete nominal inputs: `envMap: Map[str, str] = Map()`, `requiredKeys: [str] = ["aipl_test"]`; exercises core body path returning/computing `Ok(true)`.

```aipl
module tests.functions.encoding.ini_dotenv_z13_test
import * from "std/encoding/ini_dotenv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ini_dotenv_validateDotEnvSchema_13(): int:
  let arg_envMap = {}
  let edge_envMap = {}
  let arg_requiredKeys = ["test"]
  let edge_requiredKeys = []
  let resNom = validateDotEnvSchema(arg_envMap, arg_requiredKeys)
  let resEdge = validateDotEnvSchema(edge_envMap, edge_requiredKeys)
  assert(resNom.isOk() == false, "validateDotEnvSchema nominal resNom.isOk() == false")
  assert(resEdge.isOk() == true, "validateDotEnvSchema boundary resEdge.isOk() == true")
  ret 0
```

---

### `validateSchema` (`std/encoding/ini_dotenv.aipl`)

- **Signature**: `pub fn validateSchema(envMap: Map[str, str], requiredKeys: [str]): Result[bool, [str]]:`
- **Import**: `import * from "std/encoding/ini_dotenv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `envMap: Map[str, str], requiredKeys: [str]` | **Returns**: `Result[bool, [str]]`
- **Unit Test**: `tests/functions/encoding/ini_dotenv_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `validateSchema` (`free fn`) INI section and `.env` `export KEY=VAL` loader, quote unwrapping, and required-key schema validation. Concrete nominal inputs: `envMap: Map[str, str] = Map()`, `requiredKeys: [str] = ["aipl_test"]`; exercises core body path returning/computing `validateDotEnvSchema(envMap, requiredKeys)`.

```aipl
module tests.functions.encoding.ini_dotenv_z14_test
import * from "std/encoding/ini_dotenv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ini_dotenv_validateSchema_14(): int:
  let arg_envMap = {}
  let edge_envMap = {}
  let arg_requiredKeys = ["test"]
  let edge_requiredKeys = []
  let resNom = validateSchema(arg_envMap, arg_requiredKeys)
  let resEdge = validateSchema(edge_envMap, edge_requiredKeys)
  assert(resNom.isOk() == false, "validateSchema nominal resNom.isOk() == false")
  assert(resEdge.isOk() == true, "validateSchema boundary resEdge.isOk() == true")
  ret 0
```

---

### `parseIniSection` (`std/encoding/ini_dotenv.aipl`)

- **Signature**: `pub fn parseIniSection(src: str, section: str): Map[str, str]:`
- **Import**: `import * from "std/encoding/ini_dotenv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `src: str, section: str` | **Returns**: `Map[str, str]`
- **Unit Test**: `tests/functions/encoding/ini_dotenv_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `parseIniSection` (`free fn`) INI section and `.env` `export KEY=VAL` loader, quote unwrapping, and required-key schema validation. Concrete nominal inputs: `src: str = "aipl_test"`, `section: str = "aipl_test"`; exercises core body path returning/computing `m`.

```aipl
module tests.functions.encoding.ini_dotenv_z15_test
import * from "std/encoding/ini_dotenv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ini_dotenv_parseIniSection_15(): int:
  let arg_src = "[s]\nk=v"
  let edge_src = "[s]\nk=v"
  let arg_section = "[s]\nk=v"
  let edge_section = "[s]\nk=v"
  let resNom = parseIniSection(arg_src, arg_section)
  let resEdge = parseIniSection(edge_src, edge_section)
  assertEqInt(resNom.len(), 0, "parseIniSection nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "parseIniSection boundary resEdge.len() == 0")
  ret 0
```

---

### `parseIniSections` (`std/encoding/ini_dotenv.aipl`)

- **Signature**: `pub fn parseIniSections(src: str): [str]:`
- **Import**: `import * from "std/encoding/ini_dotenv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `src: str` | **Returns**: `[str]`
- **Unit Test**: `tests/functions/encoding/ini_dotenv_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `parseIniSections` (`free fn`) INI section and `.env` `export KEY=VAL` loader, quote unwrapping, and required-key schema validation. Concrete nominal inputs: `src: str = "aipl_test"`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.encoding.ini_dotenv_z16_test
import * from "std/encoding/ini_dotenv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ini_dotenv_parseIniSections_16(): int:
  let arg_src = "[s]\nk=v"
  let edge_src = "[s]\nk=v"
  let resNom = parseIniSections(arg_src)
  let resEdge = parseIniSections(edge_src)
  assertEqInt(resNom.len(), 1, "parseIniSections nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "parseIniSections boundary resEdge.len() == 1")
  ret 0
```

---

### `getIniValue` (`std/encoding/ini_dotenv.aipl`)

- **Signature**: `pub fn getIniValue(src: str, section: str, key: str, defaultVal: str): str:`
- **Import**: `import * from "std/encoding/ini_dotenv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `src: str, section: str, key: str, defaultVal: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/ini_dotenv_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `getIniValue` (`free fn`) INI section and `.env` `export KEY=VAL` loader, quote unwrapping, and required-key schema validation. Concrete nominal inputs: `src: str = "aipl_test"`, `section: str = "aipl_test"`, `key: str = "aipl_test"`, `defaultVal: str = "aipl_test"`; exercises core body path returning/computing `fastIniGetValue(src, section, key, defaultVal)`.

```aipl
module tests.functions.encoding.ini_dotenv_z17_test
import * from "std/encoding/ini_dotenv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ini_dotenv_getIniValue_17(): int:
  let arg_src = "[s]\nk=v"
  let edge_src = "[s]\nk=v"
  let arg_section = "[s]\nk=v"
  let edge_section = "[s]\nk=v"
  let arg_key = "[s]\nk=v"
  let edge_key = "[s]\nk=v"
  let arg_defaultVal = "[s]\nk=v"
  let edge_defaultVal = "[s]\nk=v"
  let resNom = getIniValue(arg_src, arg_section, arg_key, arg_defaultVal)
  let resEdge = getIniValue(edge_src, edge_section, edge_key, edge_defaultVal)
  assertEqInt(resNom.len(), 7, "getIniValue nominal string length == 7")
  assertEqInt(resEdge.len(), 7, "getIniValue boundary string length == 7")
  ret 0
```

---

### `toIni` (`std/encoding/ini_dotenv.aipl`)

- **Signature**: `pub fn toIni(section: str, m: Map[str, str]): str:`
- **Import**: `import * from "std/encoding/ini_dotenv"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `section: str, m: Map[str, str]` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/ini_dotenv_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `toIni` (`free fn`) INI section and `.env` `export KEY=VAL` loader, quote unwrapping, and required-key schema validation. Concrete nominal inputs: `section: str = "aipl_test"`, `m: Map[str, str] = Map()`; exercises core body path returning/computing `lines.join("\n")`.

```aipl
module tests.functions.encoding.ini_dotenv_z18_test
import * from "std/encoding/ini_dotenv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ini_dotenv_toIni_18(): int:
  let arg_section = "[s]\nk=v"
  let edge_section = "[s]\nk=v"
  let arg_m = {}
  let edge_m = {}
  let resNom = toIni(arg_section, arg_m)
  let resEdge = toIni(edge_section, edge_m)
  assertEqInt(resNom.len(), 9, "toIni nominal string length == 9")
  assertEqInt(resEdge.len(), 9, "toIni boundary string length == 9")
  ret 0
```

---

### `jsonNull` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonNull(): JsonValue:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `JsonValue`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `jsonNull` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `JsonValue(kind = "null", numVal = 0.0, strVal = "", boolVal = false, arrayVal = emptyArr, objectVal = emptyObj)`.

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

---

### `jsonBool` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonBool(b: bool): JsonValue:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `b: bool` | **Returns**: `JsonValue`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `jsonBool` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `b: bool = true`; exercises core body path returning/computing `JsonValue(kind = "bool", numVal = if b: 1.0 else: 0.0, strVal = "", boolVal = b, arrayVal = emptyArr, objectVal = emptyObj)`.

```aipl
module tests.functions.encoding.json_z2_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonBool_2(): int:
  let arg_b = true
  let edge_b = false
  let resNom = jsonBool(arg_b)
  let resEdge = jsonBool(edge_b)
  assertEqStr(resNom.kind, "bool", "jsonBool nominal string matches")
  assertEqStr(resEdge.kind, "bool", "jsonBool boundary string matches")
  ret 0
```

---

### `jsonNumber` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonNumber(n: float): JsonValue:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `n: float` | **Returns**: `JsonValue`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `jsonNumber` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `n: float = 1.0`; exercises core body path returning/computing `JsonValue(kind = "number", numVal = n, strVal = "", boolVal = false, arrayVal = emptyArr, objectVal = emptyObj)`.

```aipl
module tests.functions.encoding.json_z3_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonNumber_3(): int:
  let arg_n = 1.0
  let edge_n = 0.5
  let resNom = jsonNumber(arg_n)
  let resEdge = jsonNumber(edge_n)
  assertEqStr(resNom.kind, "number", "jsonNumber nominal string matches")
  assertEqStr(resEdge.kind, "number", "jsonNumber boundary string matches")
  ret 0
```

---

### `jsonString` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonString(s: str): JsonValue:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `JsonValue`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `jsonString` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `JsonValue(kind = "string", numVal = 0.0, strVal = s, boolVal = false, arrayVal = emptyArr, objectVal = emptyObj)`.

```aipl
module tests.functions.encoding.json_z4_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonString_4(): int:
  let arg_s = "{\"a\":1}"
  let edge_s = "{}"
  let resNom = jsonString(arg_s)
  let resEdge = jsonString(edge_s)
  assertEqStr(resNom.kind, "string", "jsonString nominal string matches")
  assertEqStr(resEdge.kind, "string", "jsonString boundary string matches")
  ret 0
```

---

### `jsonArray` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonArray(items: [JsonValue]): JsonValue:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `items: [JsonValue]` | **Returns**: `JsonValue`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `jsonArray` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `items: [JsonValue] = [JsonValue(kind = "aipl_test", numVal = 1.0, strVal = "aipl_test", boolVal = true, arrayVal = [0], objectVal = [0])]`; exercises core body path returning/computing `JsonValue(kind = "array", numVal = 0.0, strVal = "", boolVal = false, arrayVal = items, objectVal = emptyObj)`.

```aipl
module tests.functions.encoding.json_z5_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonArray_5(): int:
  let arg_items = [JsonValue(kind = "{\"a\":1}", numVal = 1.0, strVal = "{\"a\":1}", boolVal = true, arrayVal = [], objectVal = [])]
  let edge_items = []
  let resNom = jsonArray(arg_items)
  let resEdge = jsonArray(edge_items)
  assertEqStr(resNom.kind, "array", "jsonArray nominal string matches")
  assertEqStr(resEdge.kind, "array", "jsonArray boundary string matches")
  ret 0
```

---

### `jsonObject` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonObject(entries: [(str, JsonValue)]): JsonValue:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `entries: [(str, JsonValue)]` | **Returns**: `JsonValue`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `jsonObject` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `entries: [(str, JsonValue)] = [(str, JsonValue)()]`; exercises core body path returning/computing `JsonValue(kind = "object", numVal = 0.0, strVal = "", boolVal = false, arrayVal = emptyArr, objectVal = entries)`.

```aipl
module tests.functions.encoding.json_z6_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonObject_6(): int:
  let arg_entries = [("{\"a\":1}", JsonValue(kind = "{\"a\":1}", numVal = 1.0, strVal = "{\"a\":1}", boolVal = true, arrayVal = [], objectVal = []))]
  let edge_entries = []
  let resNom = jsonObject(arg_entries)
  let resEdge = jsonObject(edge_entries)
  assertEqStr(resNom.kind, "object", "jsonObject nominal string matches")
  assertEqStr(resEdge.kind, "object", "jsonObject boundary string matches")
  ret 0
```

---

### `skipJsonWs` (`std/encoding/json.aipl`)

- **Signature**: `fn skipJsonWs(text: str, start: int): int:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str, start: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `skipJsonWs` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `text: str = "aipl_test"`, `start: int = 1`; exercises core body path returning/computing `p`.

```aipl
module tests.functions.encoding.json_z7_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_skipJsonWs_7(): int:
  let arg_text = "{\"a\":1}"
  let edge_text = "{}"
  let arg_start = 1
  let edge_start = 0
  let resNom = skipJsonWs(arg_text, arg_start)
  let resEdge = skipJsonWs(edge_text, edge_start)
  assertEqInt(resNom, 1, "skipJsonWs nominal resNom == 1")
  assertEqInt(resEdge, 0, "skipJsonWs boundary resEdge == 0")
  ret 0
```

---

### `parseJsonStringAt` (`std/encoding/json.aipl`)

- **Signature**: `fn parseJsonStringAt(text: str, start: int): (int, str, str):`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str, start: int` | **Returns**: `(int, str, str)`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `parseJsonStringAt` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `text: str = "aipl_test"`, `start: int): (int = int): (int()`, `str: any = 42`, `str: any = 42`; exercises core body path returning/computing `(p, "", "unterminated JSON string")`.

```aipl
module tests.functions.encoding.json_z8_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_parseJsonStringAt_8(): int:
  let arg_text = "{\"a\":1}"
  let edge_text = "{}"
  let arg_start = 1
  let edge_start = 0
  let resNom = parseJsonStringAt(arg_text, arg_start)
  let resEdge = parseJsonStringAt(edge_text, edge_start)
  let (n_t0, n_t1, n_t2) = resNom
  let (e_t0, e_t1, e_t2) = resEdge
  assertEqInt(n_t0, 4, "parseJsonStringAt nominal n_t0 == 4")
  assertEqInt(e_t0, 0, "parseJsonStringAt boundary e_t0 == 0")
  ret 0
```

---

### `parseJsonNumberAt` (`std/encoding/json.aipl`)

- **Signature**: `fn parseJsonNumberAt(text: str, start: int): JsonParseCursor:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str, start: int` | **Returns**: `JsonParseCursor`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `parseJsonNumberAt` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `text: str = "aipl_test"`, `start: int = 1`; exercises core body path returning/computing `JsonParseCursor(pos = p, val = jsonNumber(fVal), err = "")`.

```aipl
module tests.functions.encoding.json_z9_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_parseJsonNumberAt_9(): int:
  let arg_text = "{\"a\":1}"
  let edge_text = "{}"
  let arg_start = 1
  let edge_start = 0
  let resNom = parseJsonNumberAt(arg_text, arg_start)
  let resEdge = parseJsonNumberAt(edge_text, edge_start)
  assertEqInt(resNom.pos, 1, "parseJsonNumberAt nominal resNom.pos == 1")
  assertEqInt(resEdge.pos, 0, "parseJsonNumberAt boundary resEdge.pos == 0")
  ret 0
```

---

### `parseJsonValueAt` (`std/encoding/json.aipl`)

- **Signature**: `fn parseJsonValueAt(text: str, start: int): JsonParseCursor:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str, start: int` | **Returns**: `JsonParseCursor`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `parseJsonValueAt` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `text: str = "aipl_test"`, `start: int = 1`; exercises core body path returning/computing `JsonParseCursor(pos = p, val = jsonNull(), err = "unexpected character in JSON at offset " + str(p))`.

```aipl
module tests.functions.encoding.json_z10_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_parseJsonValueAt_10(): int:
  let arg_text = "{\"a\":1}"
  let edge_text = "{}"
  let arg_start = 1
  let edge_start = 0
  let resNom = parseJsonValueAt(arg_text, arg_start)
  let resEdge = parseJsonValueAt(edge_text, edge_start)
  assertEqInt(resNom.pos, 4, "parseJsonValueAt nominal resNom.pos == 4")
  assertEqInt(resEdge.pos, 2, "parseJsonValueAt boundary resEdge.pos == 2")
  ret 0
```

---

### `jsonParse` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonParse(text: str): Result[JsonValue, str]:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str` | **Returns**: `Result[JsonValue, str]`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `jsonParse` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `text: str = "aipl_test"`; exercises core body path returning/computing `Ok(res.val)`.

```aipl
module tests.functions.encoding.json_z11_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonParse_11(): int:
  let arg_text = "{\"a\":1}"
  let edge_text = "{}"
  let resNom = jsonParse(arg_text)
  let resEdge = jsonParse(edge_text)
  assert(resNom.isOk() == true, "jsonParse nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "jsonParse boundary resEdge.isOk() == true")
  ret 0
```

---

### `escapeJsonString` (`std/encoding/json.aipl`)

- **Signature**: `pub fn escapeJsonString(s: str): str:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `escapeJsonString` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `parts.join("")`.

```aipl
module tests.functions.encoding.json_z12_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_escapeJsonString_12(): int:
  let arg_s = "{\"a\":1}"
  let edge_s = "{}"
  let resNom = escapeJsonString(arg_s)
  let resEdge = escapeJsonString(edge_s)
  assertEqInt(resNom.len(), 9, "escapeJsonString nominal string length == 9")
  assertEqInt(resEdge.len(), 2, "escapeJsonString boundary string length == 2")
  ret 0
```

---

### `formatJsonNumber` (`std/encoding/json.aipl`)

- **Signature**: `fn formatJsonNumber(n: float): str:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `n: float` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `formatJsonNumber` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `n: float = 1.0`; exercises core body path returning/computing `str(n)`.

```aipl
module tests.functions.encoding.json_z13_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_formatJsonNumber_13(): int:
  let arg_n = 1.0
  let edge_n = 0.5
  let resNom = formatJsonNumber(arg_n)
  let resEdge = formatJsonNumber(edge_n)
  assertEqStr(resNom, "1", "formatJsonNumber nominal string matches")
  assertEqStr(resEdge, "0.5", "formatJsonNumber boundary string matches")
  ret 0
```

---

### `jsonStringify` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonStringify(val: JsonValue): str:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: JsonValue` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `jsonStringify` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `val: JsonValue = JsonValue(kind = "aipl_test", numVal = 1.0, strVal = "aipl_test", boolVal = true, arrayVal = [JsonValue(kind = 0, numVal = 0, strVal = 0, boolVal = 0, arrayVal = 0, objectVal = 0)], objectVal = [(str, JsonValue)()])`; exercises core body path returning/computing `"null"`.

```aipl
module tests.functions.encoding.json_z14_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonStringify_14(): int:
  let arg_val = JsonValue(kind = "{\"a\":1}", numVal = 1.0, strVal = "{\"a\":1}", boolVal = true, arrayVal = [], objectVal = [])
  let edge_val = JsonValue(kind = "{}", numVal = 0.5, strVal = "{}", boolVal = false, arrayVal = [], objectVal = [])
  let resNom = jsonStringify(arg_val)
  let resEdge = jsonStringify(edge_val)
  assertEqStr(resNom, "null", "jsonStringify nominal string matches")
  assertEqStr(resEdge, "null", "jsonStringify boundary string matches")
  ret 0
```

---

### `makeSpaces` (`std/encoding/json.aipl`)

- **Signature**: `fn makeSpaces(count: int): str:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `count: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `makeSpaces` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `count: int = 64`; exercises core body path returning/computing `parts.join("")`.

```aipl
module tests.functions.encoding.json_z15_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_makeSpaces_15(): int:
  let arg_count = 4
  let edge_count = 1
  let resNom = makeSpaces(arg_count)
  let resEdge = makeSpaces(edge_count)
  assertEqStr(resNom, "    ", "makeSpaces nominal string matches")
  assertEqStr(resEdge, " ", "makeSpaces boundary string matches")
  ret 0
```

---

### `jsonStringifyIndent` (`std/encoding/json.aipl`)

- **Signature**: `fn jsonStringifyIndent(val: JsonValue, indent: int, depth: int): str:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: JsonValue, indent: int, depth: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `jsonStringifyIndent` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `val: JsonValue = JsonValue(kind = "aipl_test", numVal = 1.0, strVal = "aipl_test", boolVal = true, arrayVal = [JsonValue(kind = 0, numVal = 0, strVal = 0, boolVal = 0, arrayVal = 0, objectVal = 0)], objectVal = [(str, JsonValue)()])`, `indent: int = 1`, `depth: int = 1`; exercises core body path returning/computing `jsonStringify(val)`.

```aipl
module tests.functions.encoding.json_z16_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonStringifyIndent_16(): int:
  let arg_val = JsonValue(kind = "{\"a\":1}", numVal = 1.0, strVal = "{\"a\":1}", boolVal = true, arrayVal = [], objectVal = [])
  let edge_val = JsonValue(kind = "{}", numVal = 0.5, strVal = "{}", boolVal = false, arrayVal = [], objectVal = [])
  let arg_indent = 4
  let edge_indent = 1
  let arg_depth = 4
  let edge_depth = 1
  let resNom = jsonStringifyIndent(arg_val, arg_indent, arg_depth)
  let resEdge = jsonStringifyIndent(edge_val, edge_indent, edge_depth)
  assertEqStr(resNom, "null", "jsonStringifyIndent nominal string matches")
  assertEqStr(resEdge, "null", "jsonStringifyIndent boundary string matches")
  ret 0
```

---

### `jsonStringifyPretty` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonStringifyPretty(val: JsonValue, indent: int = 2): str:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: JsonValue, indent: int = 2` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `jsonStringifyPretty` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `val: JsonValue = JsonValue(kind = "aipl_test", numVal = 1.0, strVal = "aipl_test", boolVal = true, arrayVal = [JsonValue(kind = 0, numVal = 0, strVal = 0, boolVal = 0, arrayVal = 0, objectVal = 0)], objectVal = [(str, JsonValue)()])`, `indent: int = 1`; exercises core body path returning/computing `jsonStringifyIndent(val, step, 0)`.

```aipl
module tests.functions.encoding.json_z17_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonStringifyPretty_17(): int:
  let arg_val = JsonValue(kind = "{\"a\":1}", numVal = 1.0, strVal = "{\"a\":1}", boolVal = true, arrayVal = [], objectVal = [])
  let edge_val = JsonValue(kind = "{}", numVal = 0.5, strVal = "{}", boolVal = false, arrayVal = [], objectVal = [])
  let arg_indent = 4
  let edge_indent = 1
  let resNom = jsonStringifyPretty(arg_val, arg_indent)
  let resEdge = jsonStringifyPretty(edge_val, edge_indent)
  assertEqStr(resNom, "null", "jsonStringifyPretty nominal string matches")
  assertEqStr(resEdge, "null", "jsonStringifyPretty boundary string matches")
  ret 0
```

---

### `get` (`std/encoding/json.aipl`)

- **Signature**: `pub fn (self: JsonValue) get(key: str): Option[JsonValue]:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `self: JsonValue` | **Parameters**: `key: str` | **Returns**: `Option[JsonValue]`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `get` (`self: JsonValue`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: receiver `recvObj: JsonValue = JsonValue(kind = "aipl_test", numVal = 1.0, strVal = "aipl_test", boolVal = true, arrayVal = [JsonValue(kind = 0, numVal = 0, strVal = 0, boolVal = 0, arrayVal = 0, objectVal = 0)], objectVal = [(str, JsonValue)()])`, `key: str = "aipl_test"`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.encoding.json_z18_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_JsonValue_get_18(): int:
  let recv_self = JsonValue(kind = "test", numVal = 1.0, strVal = "test", boolVal = true, arrayVal = [], objectVal = [])
  let edge_self = JsonValue(kind = "a", numVal = 0.5, strVal = "a", boolVal = false, arrayVal = [], objectVal = [])
  let arg_key = "test"
  let edge_key = "a"
  let resNom = recv_self.get(arg_key)
  let resEdge = edge_self.get(edge_key)
  assert(resNom.isSome() == false, "get nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "get boundary resEdge.isSome() == false")
  ret 0
```

---

### `getIndex` (`std/encoding/json.aipl`)

- **Signature**: `pub fn (self: JsonValue) getIndex(idx: int): Option[JsonValue]:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `self: JsonValue` | **Parameters**: `idx: int` | **Returns**: `Option[JsonValue]`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `getIndex` (`self: JsonValue`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: receiver `recvObj: JsonValue = JsonValue(kind = "aipl_test", numVal = 1.0, strVal = "aipl_test", boolVal = true, arrayVal = [JsonValue(kind = 0, numVal = 0, strVal = 0, boolVal = 0, arrayVal = 0, objectVal = 0)], objectVal = [(str, JsonValue)()])`, `idx: int = 0`; exercises core body path returning/computing `Some(self.arrayVal[idx])`.

```aipl
module tests.functions.encoding.json_z19_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_JsonValue_getIndex_19(): int:
  let recv_self = JsonValue(kind = "test", numVal = 1.0, strVal = "test", boolVal = true, arrayVal = [], objectVal = [])
  let edge_self = JsonValue(kind = "a", numVal = 0.5, strVal = "a", boolVal = false, arrayVal = [], objectVal = [])
  let arg_idx = 1
  let edge_idx = 0
  let resNom = recv_self.getIndex(arg_idx)
  let resEdge = edge_self.getIndex(edge_idx)
  assert(resNom.isSome() == false, "getIndex nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "getIndex boundary resEdge.isSome() == false")
  ret 0
```

---

### `asStr` (`std/encoding/json.aipl`)

- **Signature**: `pub fn (self: JsonValue) asStr(): Option[str]:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `self: JsonValue` | **Parameters**: `none` | **Returns**: `Option[str]`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `asStr` (`self: JsonValue`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: receiver `recvObj: JsonValue = JsonValue(kind = "aipl_test", numVal = 1.0, strVal = "aipl_test", boolVal = true, arrayVal = [JsonValue(kind = 0, numVal = 0, strVal = 0, boolVal = 0, arrayVal = 0, objectVal = 0)], objectVal = [(str, JsonValue)()])`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.encoding.json_z20_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_JsonValue_asStr_20(): int:
  let recv_self = JsonValue(kind = "test", numVal = 1.0, strVal = "test", boolVal = true, arrayVal = [], objectVal = [])
  let edge_self = JsonValue(kind = "a", numVal = 0.5, strVal = "a", boolVal = false, arrayVal = [], objectVal = [])
  let resNom = recv_self.asStr()
  let resEdge = edge_self.asStr()
  assert(resNom.isSome() == false, "asStr nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "asStr boundary resEdge.isSome() == false")
  ret 0
```

---

### `asInt` (`std/encoding/json.aipl`)

- **Signature**: `pub fn (self: JsonValue) asInt(): Option[int]:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `self: JsonValue` | **Parameters**: `none` | **Returns**: `Option[int]`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `asInt` (`self: JsonValue`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: receiver `recvObj: JsonValue = JsonValue(kind = "aipl_test", numVal = 1.0, strVal = "aipl_test", boolVal = true, arrayVal = [JsonValue(kind = 0, numVal = 0, strVal = 0, boolVal = 0, arrayVal = 0, objectVal = 0)], objectVal = [(str, JsonValue)()])`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.encoding.json_z21_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_JsonValue_asInt_21(): int:
  let recv_self = JsonValue(kind = "42", numVal = 1.0, strVal = "42", boolVal = true, arrayVal = [], objectVal = [])
  let edge_self = JsonValue(kind = "0", numVal = 0.5, strVal = "0", boolVal = false, arrayVal = [], objectVal = [])
  let resNom = recv_self.asInt()
  let resEdge = edge_self.asInt()
  assert(resNom.isSome() == false, "asInt nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "asInt boundary resEdge.isSome() == false")
  ret 0
```

---

### `asFloat` (`std/encoding/json.aipl`)

- **Signature**: `pub fn (self: JsonValue) asFloat(): Option[float]:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `self: JsonValue` | **Parameters**: `none` | **Returns**: `Option[float]`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `asFloat` (`self: JsonValue`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: receiver `recvObj: JsonValue = JsonValue(kind = "aipl_test", numVal = 1.0, strVal = "aipl_test", boolVal = true, arrayVal = [JsonValue(kind = 0, numVal = 0, strVal = 0, boolVal = 0, arrayVal = 0, objectVal = 0)], objectVal = [(str, JsonValue)()])`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.encoding.json_z22_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_JsonValue_asFloat_22(): int:
  let recv_self = JsonValue(kind = "42", numVal = 1.0, strVal = "42", boolVal = true, arrayVal = [], objectVal = [])
  let edge_self = JsonValue(kind = "0", numVal = 0.5, strVal = "0", boolVal = false, arrayVal = [], objectVal = [])
  let resNom = recv_self.asFloat()
  let resEdge = edge_self.asFloat()
  assert(resNom.isSome() == false, "asFloat nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "asFloat boundary resEdge.isSome() == false")
  ret 0
```

---

### `asBool` (`std/encoding/json.aipl`)

- **Signature**: `pub fn (self: JsonValue) asBool(): Option[bool]:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `self: JsonValue` | **Parameters**: `none` | **Returns**: `Option[bool]`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `asBool` (`self: JsonValue`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: receiver `recvObj: JsonValue = JsonValue(kind = "aipl_test", numVal = 1.0, strVal = "aipl_test", boolVal = true, arrayVal = [JsonValue(kind = 0, numVal = 0, strVal = 0, boolVal = 0, arrayVal = 0, objectVal = 0)], objectVal = [(str, JsonValue)()])`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.encoding.json_z23_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_JsonValue_asBool_23(): int:
  let recv_self = JsonValue(kind = "test", numVal = 1.0, strVal = "test", boolVal = true, arrayVal = [], objectVal = [])
  let edge_self = JsonValue(kind = "a", numVal = 0.5, strVal = "a", boolVal = false, arrayVal = [], objectVal = [])
  let resNom = recv_self.asBool()
  let resEdge = edge_self.asBool()
  assert(resNom.isSome() == false, "asBool nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "asBool boundary resEdge.isSome() == false")
  ret 0
```

---

### `jsonQueryPath` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonQueryPath(val: JsonValue, path: str): Option[JsonValue]:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: JsonValue, path: str` | **Returns**: `Option[JsonValue]`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `jsonQueryPath` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `val: JsonValue = JsonValue(kind = "aipl_test", numVal = 1.0, strVal = "aipl_test", boolVal = true, arrayVal = [JsonValue(kind = 0, numVal = 0, strVal = 0, boolVal = 0, arrayVal = 0, objectVal = 0)], objectVal = [(str, JsonValue)()])`, `path: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `Some(cur)`.

```aipl
module tests.functions.encoding.json_z24_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonQueryPath_24(): int:
  let arg_val = JsonValue(kind = "{\"a\":1}", numVal = 1.0, strVal = "{\"a\":1}", boolVal = true, arrayVal = [], objectVal = [])
  let edge_val = JsonValue(kind = "{}", numVal = 0.5, strVal = "{}", boolVal = false, arrayVal = [], objectVal = [])
  let arg_path = "{\"a\":1}"
  let edge_path = "{}"
  let resNom = jsonQueryPath(arg_val, arg_path)
  let resEdge = jsonQueryPath(edge_val, edge_path)
  assert(resNom.isSome() == false, "jsonQueryPath nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "jsonQueryPath boundary resEdge.isSome() == false")
  ret 0
```

---

### `fastJsonGetInt` (`std/encoding/json.aipl`)

- **Signature**: `pub fn fastJsonGetInt(jsonStr: str, key: str, defaultVal: int): int:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `jsonStr: str, key: str, defaultVal: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `fastJsonGetInt` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `jsonStr: str = "{\"ok\":true}"`, `key: str = "aipl_test"`, `defaultVal: int = 1`; exercises core body path returning/computing `iOpt.unwrap()`.

```aipl
module tests.functions.encoding.json_z25_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_fastJsonGetInt_25(): int:
  let arg_jsonStr = "{\"a\":1}"
  let edge_jsonStr = "{}"
  let arg_key = "{\"a\":1}"
  let edge_key = "{}"
  let arg_defaultVal = 2
  let edge_defaultVal = 0
  let resNom = fastJsonGetInt(arg_jsonStr, arg_key, arg_defaultVal)
  let resEdge = fastJsonGetInt(edge_jsonStr, edge_key, edge_defaultVal)
  assertEqInt(resNom, 2, "fastJsonGetInt nominal resNom == 2")
  assertEqInt(resEdge, 0, "fastJsonGetInt boundary resEdge == 0")
  ret 0
```

---

### `fastJsonGetFloat` (`std/encoding/json.aipl`)

- **Signature**: `pub fn fastJsonGetFloat(jsonStr: str, key: str, defaultVal: float): float:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `jsonStr: str, key: str, defaultVal: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `fastJsonGetFloat` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `jsonStr: str = "{\"ok\":true}"`, `key: str = "aipl_test"`, `defaultVal: float = 1.0`; exercises core body path returning/computing `fOpt.unwrap()`.

```aipl
module tests.functions.encoding.json_z26_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_fastJsonGetFloat_26(): int:
  let arg_jsonStr = "{\"a\":1}"
  let edge_jsonStr = "{}"
  let arg_key = "{\"a\":1}"
  let edge_key = "{}"
  let arg_defaultVal = 1.0
  let edge_defaultVal = 0.5
  let resNom = fastJsonGetFloat(arg_jsonStr, arg_key, arg_defaultVal)
  let resEdge = fastJsonGetFloat(edge_jsonStr, edge_key, edge_defaultVal)
  assertApproxEq(resNom, 1.0, 0.001, "fastJsonGetFloat nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "fastJsonGetFloat boundary resEdge ~= 0.5")
  ret 0
```

---

### `fastJsonGetStr` (`std/encoding/json.aipl`)

- **Signature**: `pub fn fastJsonGetStr(jsonStr: str, key: str, defaultVal: str): str:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `jsonStr: str, key: str, defaultVal: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `fastJsonGetStr` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `jsonStr: str = "{\"ok\":true}"`, `key: str = "aipl_test"`, `defaultVal: str = "aipl_test"`; exercises core body path returning/computing `sOpt.unwrap()`.

```aipl
module tests.functions.encoding.json_z27_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_fastJsonGetStr_27(): int:
  let arg_jsonStr = "{\"a\":1}"
  let edge_jsonStr = "{}"
  let arg_key = "{\"a\":1}"
  let edge_key = "{}"
  let arg_defaultVal = "{\"a\":1}"
  let edge_defaultVal = "{}"
  let resNom = fastJsonGetStr(arg_jsonStr, arg_key, arg_defaultVal)
  let resEdge = fastJsonGetStr(edge_jsonStr, edge_key, edge_defaultVal)
  assertEqInt(resNom.len(), 7, "fastJsonGetStr nominal string length == 7")
  assertEqInt(resEdge.len(), 2, "fastJsonGetStr boundary string length == 2")
  ret 0
```

---

### `fastJsonGetIntArray` (`std/encoding/json.aipl`)

- **Signature**: `pub fn fastJsonGetIntArray(jsonStr: str, key: str): [int]:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `jsonStr: str, key: str` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `fastJsonGetIntArray` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `jsonStr: str = "{\"ok\":true}"`, `key: str = "aipl_test"`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.encoding.json_z28_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_fastJsonGetIntArray_28(): int:
  let arg_jsonStr = "{\"a\":1}"
  let edge_jsonStr = "{}"
  let arg_key = "{\"a\":1}"
  let edge_key = "{}"
  let resNom = fastJsonGetIntArray(arg_jsonStr, arg_key)
  let resEdge = fastJsonGetIntArray(edge_jsonStr, edge_key)
  assertEqInt(resNom.len(), 0, "fastJsonGetIntArray nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "fastJsonGetIntArray boundary resEdge.len() == 0")
  ret 0
```

---

### `jsonGet` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonGet(jsonStr: str, key: str): Option[str]:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `jsonStr: str, key: str` | **Returns**: `Option[str]`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `jsonGet` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `jsonStr: str = "{\"ok\":true}"`, `key: str = "aipl_test"`; exercises core body path returning/computing `Some(jsonStringify(v))`.

```aipl
module tests.functions.encoding.json_z29_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonGet_29(): int:
  let arg_jsonStr = "{\"a\":1}"
  let edge_jsonStr = "{}"
  let arg_key = "{\"a\":1}"
  let edge_key = "{}"
  let resNom = jsonGet(arg_jsonStr, arg_key)
  let resEdge = jsonGet(edge_jsonStr, edge_key)
  assert(resNom.isSome() == false, "jsonGet nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "jsonGet boundary resEdge.isSome() == false")
  ret 0
```

---

### `formatJsonPrettyString` (`std/encoding/json.aipl`)

- **Signature**: `pub fn formatJsonPrettyString(jsonStr: str, indent: int = 2): str:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `jsonStr: str, indent: int = 2` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `formatJsonPrettyString` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `jsonStr: str = "{\"ok\":true}"`, `indent: int = 1`; exercises core body path returning/computing `jsonStringifyPretty(pRes.unwrap(), indent)`.

```aipl
module tests.functions.encoding.json_z30_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_formatJsonPrettyString_30(): int:
  let arg_jsonStr = "{\"a\":1}"
  let edge_jsonStr = "{}"
  let arg_indent = 4
  let edge_indent = 1
  let resNom = formatJsonPrettyString(arg_jsonStr, arg_indent)
  let resEdge = formatJsonPrettyString(edge_jsonStr, edge_indent)
  assertEqInt(resNom.len(), 14, "formatJsonPrettyString nominal string length == 14")
  assertEqInt(resEdge.len(), 2, "formatJsonPrettyString boundary string length == 2")
  ret 0
```

---

### `skipJsonWs` (`std/encoding/json.aipl`)

- **Signature**: `fn skipJsonWs(s: str, idx: int): int:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, idx: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `skipJsonWs` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `s: str = "aipl_test"`, `idx: int = 0`; exercises core body path returning/computing `i`.

```aipl
module tests.functions.encoding.json_z31_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_skipJsonWs_31(): int:
  let arg_s = "{\"a\":1}"
  let edge_s = "{}"
  let arg_idx = 1
  let edge_idx = 0
  let resNom = skipJsonWs(arg_s, arg_idx)
  let resEdge = skipJsonWs(edge_s, edge_idx)
  assertEqInt(resNom, 1, "skipJsonWs nominal resNom == 1")
  assertEqInt(resEdge, 0, "skipJsonWs boundary resEdge == 0")
  ret 0
```

---

### `findJsonValueEnd` (`std/encoding/json.aipl`)

- **Signature**: `fn findJsonValueEnd(s: str, startIdx: int): int:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, startIdx: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `findJsonValueEnd` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `s: str = "aipl_test"`, `startIdx: int = 0`; exercises core body path returning/computing `n`.

```aipl
module tests.functions.encoding.json_z32_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_findJsonValueEnd_32(): int:
  let arg_s = "{\"a\":1}"
  let edge_s = "{}"
  let arg_startIdx = 1
  let edge_startIdx = 0
  let resNom = findJsonValueEnd(arg_s, arg_startIdx)
  let resEdge = findJsonValueEnd(edge_s, edge_startIdx)
  assertEqInt(resNom, 4, "findJsonValueEnd nominal resNom == 4")
  assertEqInt(resEdge, 2, "findJsonValueEnd boundary resEdge == 2")
  ret 0
```

---

### `unquoteJsonValue` (`std/encoding/json.aipl`)

- **Signature**: `fn unquoteJsonValue(raw: str): str:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `raw: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `unquoteJsonValue` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `raw: str = "aipl_test"`; exercises core body path returning/computing `t`.

```aipl
module tests.functions.encoding.json_z33_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_unquoteJsonValue_33(): int:
  let arg_raw = "{\"a\":1}"
  let edge_raw = "{}"
  let resNom = unquoteJsonValue(arg_raw)
  let resEdge = unquoteJsonValue(edge_raw)
  assertEqInt(resNom.len(), 7, "unquoteJsonValue nominal string length == 7")
  assertEqInt(resEdge.len(), 2, "unquoteJsonValue boundary string length == 2")
  ret 0
```

---

### `extractObjectKeyRaw` (`std/encoding/json.aipl`)

- **Signature**: `fn extractObjectKeyRaw(jsonObj: str, targetKey: str): Option[str]:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `jsonObj: str, targetKey: str` | **Returns**: `Option[str]`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `extractObjectKeyRaw` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `jsonObj: str = "{\"ok\":true}"`, `targetKey: str = "aipl_test"`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.encoding.json_z34_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_extractObjectKeyRaw_34(): int:
  let arg_jsonObj = "{\"a\":1}"
  let edge_jsonObj = "{}"
  let arg_targetKey = "test"
  let edge_targetKey = "a"
  let resNom = extractObjectKeyRaw(arg_jsonObj, arg_targetKey)
  let resEdge = extractObjectKeyRaw(edge_jsonObj, edge_targetKey)
  assert(resNom.isSome() == false, "extractObjectKeyRaw nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "extractObjectKeyRaw boundary resEdge.isSome() == false")
  ret 0
```

---

### `extractArrayIndexRaw` (`std/encoding/json.aipl`)

- **Signature**: `fn extractArrayIndexRaw(jsonArr: str, targetIdx: int): Option[str]:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `jsonArr: str, targetIdx: int` | **Returns**: `Option[str]`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `extractArrayIndexRaw` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `jsonArr: str = "{\"ok\":true}"`, `targetIdx: int = 0`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.encoding.json_z35_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_extractArrayIndexRaw_35(): int:
  let arg_jsonArr = "{\"a\":1}"
  let edge_jsonArr = "{}"
  let arg_targetIdx = 1
  let edge_targetIdx = 0
  let resNom = extractArrayIndexRaw(arg_jsonArr, arg_targetIdx)
  let resEdge = extractArrayIndexRaw(edge_jsonArr, edge_targetIdx)
  assert(resNom.isSome() == false, "extractArrayIndexRaw nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "extractArrayIndexRaw boundary resEdge.isSome() == false")
  ret 0
```

---

### `parseNonNegInt` (`std/encoding/json.aipl`)

- **Signature**: `fn parseNonNegInt(s: str): Option[int]:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `Option[int]`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `parseNonNegInt` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `Some(acc)`.

```aipl
module tests.functions.encoding.json_z36_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_parseNonNegInt_36(): int:
  let arg_s = "42"
  let edge_s = "0"
  let resNom = parseNonNegInt(arg_s)
  let resEdge = parseNonNegInt(edge_s)
  assert(resNom.isSome() == true, "parseNonNegInt nominal resNom.isSome() == true")
  assert(resEdge.isSome() == true, "parseNonNegInt boundary resEdge.isSome() == true")
  ret 0
```

---

### `jsonQueryRaw` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonQueryRaw(jsonText: str, queryPath: str): Option[str]:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `jsonText: str, queryPath: str` | **Returns**: `Option[str]`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `jsonQueryRaw` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `jsonText: str = "{\"ok\":true}"`, `queryPath: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `Some(cur)`.

```aipl
module tests.functions.encoding.json_z37_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonQueryRaw_37(): int:
  let arg_jsonText = "{\"a\":1}"
  let edge_jsonText = "{}"
  let arg_queryPath = "{\"a\":1}"
  let edge_queryPath = "{}"
  let resNom = jsonQueryRaw(arg_jsonText, arg_queryPath)
  let resEdge = jsonQueryRaw(edge_jsonText, edge_queryPath)
  assert(resNom.isSome() == false, "jsonQueryRaw nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "jsonQueryRaw boundary resEdge.isSome() == false")
  ret 0
```

---

### `jsonQuery` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonQuery(jsonText: str, path: str): Option[str]:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `jsonText: str, path: str` | **Returns**: `Option[str]`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `jsonQuery` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `jsonText: str = "{\"ok\":true}"`, `path: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `Some(unquoteJsonValue(rawOpt.unwrap()))`.

```aipl
module tests.functions.encoding.json_z38_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonQuery_38(): int:
  let arg_jsonText = "{\"a\":1}"
  let edge_jsonText = "{}"
  let arg_path = "{\"a\":1}"
  let edge_path = "{}"
  let resNom = jsonQuery(arg_jsonText, arg_path)
  let resEdge = jsonQuery(edge_jsonText, edge_path)
  assert(resNom.isSome() == false, "jsonQuery nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "jsonQuery boundary resEdge.isSome() == false")
  ret 0
```

---

### `jsonGetPathStr` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonGetPathStr(jsonText: str, path: str, defaultVal: str): str:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `jsonText: str, path: str, defaultVal: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `jsonGetPathStr` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `jsonText: str = "{\"ok\":true}"`, `path: str = "/tmp/aipl_test_artifact.tmp"`, `defaultVal: str = "aipl_test"`; exercises core body path returning/computing `opt.unwrap()`.

```aipl
module tests.functions.encoding.json_z39_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonGetPathStr_39(): int:
  let arg_jsonText = "{\"a\":1}"
  let edge_jsonText = "{}"
  let arg_path = "{\"a\":1}"
  let edge_path = "{}"
  let arg_defaultVal = "{\"a\":1}"
  let edge_defaultVal = "{}"
  let resNom = jsonGetPathStr(arg_jsonText, arg_path, arg_defaultVal)
  let resEdge = jsonGetPathStr(edge_jsonText, edge_path, edge_defaultVal)
  assertEqInt(resNom.len(), 7, "jsonGetPathStr nominal string length == 7")
  assertEqInt(resEdge.len(), 2, "jsonGetPathStr boundary string length == 2")
  ret 0
```

---

### `jsonGetPathFloat` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonGetPathFloat(jsonText: str, path: str, defaultVal: float): float:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `jsonText: str, path: str, defaultVal: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `jsonGetPathFloat` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `jsonText: str = "{\"ok\":true}"`, `path: str = "/tmp/aipl_test_artifact.tmp"`, `defaultVal: float = 1.0`; exercises core body path returning/computing `fOpt.unwrap()`.

```aipl
module tests.functions.encoding.json_z40_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonGetPathFloat_40(): int:
  let arg_jsonText = "{\"a\":1}"
  let edge_jsonText = "{}"
  let arg_path = "{\"a\":1}"
  let edge_path = "{}"
  let arg_defaultVal = 1.0
  let edge_defaultVal = 0.5
  let resNom = jsonGetPathFloat(arg_jsonText, arg_path, arg_defaultVal)
  let resEdge = jsonGetPathFloat(edge_jsonText, edge_path, edge_defaultVal)
  assertApproxEq(resNom, 1.0, 0.001, "jsonGetPathFloat nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "jsonGetPathFloat boundary resEdge ~= 0.5")
  ret 0
```

---

### `jsonGetPathInt` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonGetPathInt(jsonText: str, path: str, defaultVal: int): int:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `jsonText: str, path: str, defaultVal: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `jsonGetPathInt` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `jsonText: str = "{\"ok\":true}"`, `path: str = "/tmp/aipl_test_artifact.tmp"`, `defaultVal: int = 1`; exercises core body path returning/computing `iOpt.unwrap()`.

```aipl
module tests.functions.encoding.json_z41_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonGetPathInt_41(): int:
  let arg_jsonText = "{\"a\":1}"
  let edge_jsonText = "{}"
  let arg_path = "{\"a\":1}"
  let edge_path = "{}"
  let arg_defaultVal = 2
  let edge_defaultVal = 0
  let resNom = jsonGetPathInt(arg_jsonText, arg_path, arg_defaultVal)
  let resEdge = jsonGetPathInt(edge_jsonText, edge_path, edge_defaultVal)
  assertEqInt(resNom, 2, "jsonGetPathInt nominal resNom == 2")
  assertEqInt(resEdge, 0, "jsonGetPathInt boundary resEdge == 0")
  ret 0
```

---

### `jsonStringifyIntArray` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonStringifyIntArray(arr: [int]): str:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `arr: [int]` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `jsonStringifyIntArray` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `arr: [int] = [1]`; exercises core body path returning/computing `"[" + parts.join(",") + "]"`.

```aipl
module tests.functions.encoding.json_z42_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonStringifyIntArray_42(): int:
  let arg_arr = [2]
  let edge_arr = []
  let resNom = jsonStringifyIntArray(arg_arr)
  let resEdge = jsonStringifyIntArray(edge_arr)
  assertEqStr(resNom, "[2]", "jsonStringifyIntArray nominal string matches")
  assertEqStr(resEdge, "[]", "jsonStringifyIntArray boundary string matches")
  ret 0
```

---

### `jsonGetPathIntArray` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonGetPathIntArray(jsonText: str, path: str): [int]:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `jsonText: str, path: str` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `jsonGetPathIntArray` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `jsonText: str = "{\"ok\":true}"`, `path: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.encoding.json_z43_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonGetPathIntArray_43(): int:
  let arg_jsonText = "{\"a\":1}"
  let edge_jsonText = "{}"
  let arg_path = "{\"a\":1}"
  let edge_path = "{}"
  let resNom = jsonGetPathIntArray(arg_jsonText, arg_path)
  let resEdge = jsonGetPathIntArray(edge_jsonText, edge_path)
  assertEqInt(resNom.len(), 0, "jsonGetPathIntArray nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "jsonGetPathIntArray boundary resEdge.len() == 0")
  ret 0
```

---

### `jsonFieldInt` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonFieldInt(key: str, val: int): str:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `key: str, val: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `jsonFieldInt` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `key: str = "aipl_test"`, `val: int = 1`; exercises core body path returning/computing `"\"" + escapeJsonString(key) + "\":" + str(val)`.

```aipl
module tests.functions.encoding.json_z44_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonFieldInt_44(): int:
  let arg_key = "{\"a\":1}"
  let edge_key = "{}"
  let arg_val = 2
  let edge_val = 0
  let resNom = jsonFieldInt(arg_key, arg_val)
  let resEdge = jsonFieldInt(edge_key, edge_val)
  assertEqInt(resNom.len(), 13, "jsonFieldInt nominal string length == 13")
  assertEqInt(resEdge.len(), 6, "jsonFieldInt boundary string length == 6")
  ret 0
```

---

### `jsonFieldFloat` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonFieldFloat(key: str, val: float): str:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `key: str, val: float` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `jsonFieldFloat` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `key: str = "aipl_test"`, `val: float = 1.0`; exercises core body path returning/computing `"\"" + escapeJsonString(key) + "\":" + str(val)`.

```aipl
module tests.functions.encoding.json_z45_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonFieldFloat_45(): int:
  let arg_key = "{\"a\":1}"
  let edge_key = "{}"
  let arg_val = 1.0
  let edge_val = 0.5
  let resNom = jsonFieldFloat(arg_key, arg_val)
  let resEdge = jsonFieldFloat(edge_key, edge_val)
  assertEqInt(resNom.len(), 13, "jsonFieldFloat nominal string length == 13")
  assertEqInt(resEdge.len(), 8, "jsonFieldFloat boundary string length == 8")
  ret 0
```

---

### `jsonFieldStr` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonFieldStr(key: str, val: str): str:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `key: str, val: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `jsonFieldStr` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `key: str = "aipl_test"`, `val: str = "aipl_test"`; exercises core body path returning/computing `"\"" + escapeJsonString(key) + "\":\"" + escapeJsonString(val) + "\""`.

```aipl
module tests.functions.encoding.json_z46_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonFieldStr_46(): int:
  let arg_key = "{\"a\":1}"
  let edge_key = "{}"
  let arg_val = "{\"a\":1}"
  let edge_val = "{}"
  let resNom = jsonFieldStr(arg_key, arg_val)
  let resEdge = jsonFieldStr(edge_key, edge_val)
  assertEqInt(resNom.len(), 23, "jsonFieldStr nominal string length == 23")
  assertEqInt(resEdge.len(), 9, "jsonFieldStr boundary string length == 9")
  ret 0
```

---

### `jsonFieldBool` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonFieldBool(key: str, val: bool): str:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `key: str, val: bool` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `jsonFieldBool` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `key: str = "aipl_test"`, `val: bool = true`; exercises core body path returning/computing `"\"" + escapeJsonString(key) + "\":" + bStr`.

```aipl
module tests.functions.encoding.json_z47_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonFieldBool_47(): int:
  let arg_key = "{\"a\":1}"
  let edge_key = "{}"
  let arg_val = true
  let edge_val = false
  let resNom = jsonFieldBool(arg_key, arg_val)
  let resEdge = jsonFieldBool(edge_key, edge_val)
  assertEqInt(resNom.len(), 16, "jsonFieldBool nominal string length == 16")
  assertEqInt(resEdge.len(), 10, "jsonFieldBool boundary string length == 10")
  ret 0
```

---

### `jsonObject2` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonObject2(f1: str, f2: str): str:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `f1: str, f2: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `jsonObject2` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `f1: str = "aipl_test"`, `f2: str = "aipl_test"`; exercises core body path returning/computing `"{" + f1 + "," + f2 + "}"`.

```aipl
module tests.functions.encoding.json_z48_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonObject2_48(): int:
  let arg_f1 = "{\"a\":1}"
  let edge_f1 = "{}"
  let arg_f2 = "{\"a\":1}"
  let edge_f2 = "{}"
  let resNom = jsonObject2(arg_f1, arg_f2)
  let resEdge = jsonObject2(edge_f1, edge_f2)
  assertEqInt(resNom.len(), 17, "jsonObject2 nominal string length == 17")
  assertEqInt(resEdge.len(), 7, "jsonObject2 boundary string length == 7")
  ret 0
```

---

### `jsonObject3` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonObject3(f1: str, f2: str, f3: str): str:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `f1: str, f2: str, f3: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `jsonObject3` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `f1: str = "aipl_test"`, `f2: str = "aipl_test"`, `f3: str = "aipl_test"`; exercises core body path returning/computing `"{" + f1 + "," + f2 + "," + f3 + "}"`.

```aipl
module tests.functions.encoding.json_z49_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonObject3_49(): int:
  let arg_f1 = "{\"a\":1}"
  let edge_f1 = "{}"
  let arg_f2 = "{\"a\":1}"
  let edge_f2 = "{}"
  let arg_f3 = "{\"a\":1}"
  let edge_f3 = "{}"
  let resNom = jsonObject3(arg_f1, arg_f2, arg_f3)
  let resEdge = jsonObject3(edge_f1, edge_f2, edge_f3)
  assertEqInt(resNom.len(), 25, "jsonObject3 nominal string length == 25")
  assertEqInt(resEdge.len(), 10, "jsonObject3 boundary string length == 10")
  ret 0
```

---

### `jsonObject4` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonObject4(f1: str, f2: str, f3: str, f4: str): str:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `f1: str, f2: str, f3: str, f4: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `jsonObject4` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `f1: str = "aipl_test"`, `f2: str = "aipl_test"`, `f3: str = "aipl_test"`, `f4: str = "aipl_test"`; exercises core body path returning/computing `"{" + f1 + "," + f2 + "," + f3 + "," + f4 + "}"`.

```aipl
module tests.functions.encoding.json_z50_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonObject4_50(): int:
  let arg_f1 = "{\"a\":1}"
  let edge_f1 = "{}"
  let arg_f2 = "{\"a\":1}"
  let edge_f2 = "{}"
  let arg_f3 = "{\"a\":1}"
  let edge_f3 = "{}"
  let arg_f4 = "{\"a\":1}"
  let edge_f4 = "{}"
  let resNom = jsonObject4(arg_f1, arg_f2, arg_f3, arg_f4)
  let resEdge = jsonObject4(edge_f1, edge_f2, edge_f3, edge_f4)
  assertEqInt(resNom.len(), 33, "jsonObject4 nominal string length == 33")
  assertEqInt(resEdge.len(), 13, "jsonObject4 boundary string length == 13")
  ret 0
```

---

### `jsonObject5` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonObject5(f1: str, f2: str, f3: str, f4: str, f5: str): str:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `f1: str, f2: str, f3: str, f4: str, f5: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `jsonObject5` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `f1: str = "aipl_test"`, `f2: str = "aipl_test"`, `f3: str = "aipl_test"`, `f4: str = "aipl_test"`, `f5: str = "aipl_test"`; exercises core body path returning/computing `"{" + f1 + "," + f2 + "," + f3 + "," + f4 + "," + f5 + "}"`.

```aipl
module tests.functions.encoding.json_z51_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonObject5_51(): int:
  let arg_f1 = "{\"a\":1}"
  let edge_f1 = "{}"
  let arg_f2 = "{\"a\":1}"
  let edge_f2 = "{}"
  let arg_f3 = "{\"a\":1}"
  let edge_f3 = "{}"
  let arg_f4 = "{\"a\":1}"
  let edge_f4 = "{}"
  let arg_f5 = "{\"a\":1}"
  let edge_f5 = "{}"
  let resNom = jsonObject5(arg_f1, arg_f2, arg_f3, arg_f4, arg_f5)
  let resEdge = jsonObject5(edge_f1, edge_f2, edge_f3, edge_f4, edge_f5)
  assertEqInt(resNom.len(), 41, "jsonObject5 nominal string length == 41")
  assertEqInt(resEdge.len(), 16, "jsonObject5 boundary string length == 16")
  ret 0
```

---

### `jsonObject6` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonObject6(f1: str, f2: str, f3: str, f4: str, f5: str, f6: str): str:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `f1: str, f2: str, f3: str, f4: str, f5: str, f6: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `jsonObject6` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `f1: str = "aipl_test"`, `f2: str = "aipl_test"`, `f3: str = "aipl_test"`, `f4: str = "aipl_test"`, `f5: str = "aipl_test"`, `f6: str = "aipl_test"`; exercises core body path returning/computing `"{" + f1 + "," + f2 + "," + f3 + "," + f4 + "," + f5 + "," + f6 + "}"`.

```aipl
module tests.functions.encoding.json_z52_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonObject6_52(): int:
  let arg_f1 = "{\"a\":1}"
  let edge_f1 = "{}"
  let arg_f2 = "{\"a\":1}"
  let edge_f2 = "{}"
  let arg_f3 = "{\"a\":1}"
  let edge_f3 = "{}"
  let arg_f4 = "{\"a\":1}"
  let edge_f4 = "{}"
  let arg_f5 = "{\"a\":1}"
  let edge_f5 = "{}"
  let arg_f6 = "{\"a\":1}"
  let edge_f6 = "{}"
  let resNom = jsonObject6(arg_f1, arg_f2, arg_f3, arg_f4, arg_f5, arg_f6)
  let resEdge = jsonObject6(edge_f1, edge_f2, edge_f3, edge_f4, edge_f5, edge_f6)
  assertEqInt(resNom.len(), 49, "jsonObject6 nominal string length == 49")
  assertEqInt(resEdge.len(), 19, "jsonObject6 boundary string length == 19")
  ret 0
```

---

### `jsonObject7` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonObject7(f1: str, f2: str, f3: str, f4: str, f5: str, f6: str, f7: str): str:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `f1: str, f2: str, f3: str, f4: str, f5: str, f6: str, f7: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `jsonObject7` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `f1: str = "aipl_test"`, `f2: str = "aipl_test"`, `f3: str = "aipl_test"`, `f4: str = "aipl_test"`, `f5: str = "aipl_test"`, `f6: str = "aipl_test"`, `f7: str = "aipl_test"`; exercises core body path returning/computing `"{" + f1 + "," + f2 + "," + f3 + "," + f4 + "," + f5 + "," + f6 + "," + f7 + "}"`.

```aipl
module tests.functions.encoding.json_z53_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonObject7_53(): int:
  let arg_f1 = "{\"a\":1}"
  let edge_f1 = "{}"
  let arg_f2 = "{\"a\":1}"
  let edge_f2 = "{}"
  let arg_f3 = "{\"a\":1}"
  let edge_f3 = "{}"
  let arg_f4 = "{\"a\":1}"
  let edge_f4 = "{}"
  let arg_f5 = "{\"a\":1}"
  let edge_f5 = "{}"
  let arg_f6 = "{\"a\":1}"
  let edge_f6 = "{}"
  let arg_f7 = "{\"a\":1}"
  let edge_f7 = "{}"
  let resNom = jsonObject7(arg_f1, arg_f2, arg_f3, arg_f4, arg_f5, arg_f6, arg_f7)
  let resEdge = jsonObject7(edge_f1, edge_f2, edge_f3, edge_f4, edge_f5, edge_f6, edge_f7)
  assertEqInt(resNom.len(), 57, "jsonObject7 nominal string length == 57")
  assertEqInt(resEdge.len(), 22, "jsonObject7 boundary string length == 22")
  ret 0
```

---

### `jsonObject8` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonObject8(f1: str, f2: str, f3: str, f4: str, f5: str, f6: str, f7: str, f8: str): str:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `f1: str, f2: str, f3: str, f4: str, f5: str, f6: str, f7: str, f8: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `jsonObject8` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `f1: str = "aipl_test"`, `f2: str = "aipl_test"`, `f3: str = "aipl_test"`, `f4: str = "aipl_test"`, `f5: str = "aipl_test"`, `f6: str = "aipl_test"`, `f7: str = "aipl_test"`, `f8: str = "aipl_test"`; exercises core body path returning/computing `"{" + f1 + "," + f2 + "," + f3 + "," + f4 + "," + f5 + "," + f6 + "," + f7 + "," + f8 + "}"`.

```aipl
module tests.functions.encoding.json_z54_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonObject8_54(): int:
  let arg_f1 = "{\"a\":1}"
  let edge_f1 = "{}"
  let arg_f2 = "{\"a\":1}"
  let edge_f2 = "{}"
  let arg_f3 = "{\"a\":1}"
  let edge_f3 = "{}"
  let arg_f4 = "{\"a\":1}"
  let edge_f4 = "{}"
  let arg_f5 = "{\"a\":1}"
  let edge_f5 = "{}"
  let arg_f6 = "{\"a\":1}"
  let edge_f6 = "{}"
  let arg_f7 = "{\"a\":1}"
  let edge_f7 = "{}"
  let arg_f8 = "{\"a\":1}"
  let edge_f8 = "{}"
  let resNom = jsonObject8(arg_f1, arg_f2, arg_f3, arg_f4, arg_f5, arg_f6, arg_f7, arg_f8)
  let resEdge = jsonObject8(edge_f1, edge_f2, edge_f3, edge_f4, edge_f5, edge_f6, edge_f7, edge_f8)
  assertEqInt(resNom.len(), 65, "jsonObject8 nominal string length == 65")
  assertEqInt(resEdge.len(), 25, "jsonObject8 boundary string length == 25")
  ret 0
```

---

### `jsonObjectFields` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonObjectFields(fields: [str]): str:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fields: [str]` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `jsonObjectFields` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `fields: [str] = ["aipl_test"]`; exercises core body path returning/computing `"{" + fields.join(",") + "}"`.

```aipl
module tests.functions.encoding.json_z55_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonObjectFields_55(): int:
  let arg_fields = ["{\"a\":1}"]
  let edge_fields = []
  let resNom = jsonObjectFields(arg_fields)
  let resEdge = jsonObjectFields(edge_fields)
  assertEqInt(resNom.len(), 9, "jsonObjectFields nominal string length == 9")
  assertEqInt(resEdge.len(), 2, "jsonObjectFields boundary string length == 2")
  ret 0
```

---

### `jsonArrayFields` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonArrayFields(items: [str]): str:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `items: [str]` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `jsonArrayFields` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `items: [str] = ["aipl_test"]`; exercises core body path returning/computing `"[" + items.join(",") + "]"`.

```aipl
module tests.functions.encoding.json_z56_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonArrayFields_56(): int:
  let arg_items = ["{\"a\":1}"]
  let edge_items = []
  let resNom = jsonArrayFields(arg_items)
  let resEdge = jsonArrayFields(edge_items)
  assertEqInt(resNom.len(), 9, "jsonArrayFields nominal string length == 9")
  assertEqStr(resEdge, "[]", "jsonArrayFields boundary string matches")
  ret 0
```

---

### `jsonArrayStr` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonArrayStr(items: [str]): str:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `items: [str]` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `jsonArrayStr` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `items: [str] = ["aipl_test"]`; exercises core body path returning/computing `"[" + parts.join(",") + "]"`.

```aipl
module tests.functions.encoding.json_z57_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonArrayStr_57(): int:
  let arg_items = ["{\"a\":1}"]
  let edge_items = []
  let resNom = jsonArrayStr(arg_items)
  let resEdge = jsonArrayStr(edge_items)
  assertEqInt(resNom.len(), 13, "jsonArrayStr nominal string length == 13")
  assertEqStr(resEdge, "[]", "jsonArrayStr boundary string matches")
  ret 0
```

---

### `jsonArrayInt` (`std/encoding/json.aipl`)

- **Signature**: `pub fn jsonArrayInt(items: [int]): str:`
- **Import**: `import * from "std/encoding/json"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `items: [int]` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/json_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `jsonArrayInt` (`free fn`) RFC 8259 JSON AST construction, recursive parser/pretty-printer round-trips, zero-allocation `fastJsonGet*` scanners, and dotted/indexed path queries. Concrete nominal inputs: `items: [int] = [1]`; exercises core body path returning/computing `jsonStringifyIntArray(items)`.

```aipl
module tests.functions.encoding.json_z58_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonArrayInt_58(): int:
  let arg_items = [4]
  let edge_items = []
  let resNom = jsonArrayInt(arg_items)
  let resEdge = jsonArrayInt(edge_items)
  assertEqStr(resNom, "[4]", "jsonArrayInt nominal string matches")
  assertEqStr(resEdge, "[]", "jsonArrayInt boundary string matches")
  ret 0
```

---

### `escapeMdHtml` (`std/encoding/markdown.aipl`)

- **Signature**: `fn escapeMdHtml(s: str): str:`
- **Import**: `import * from "std/encoding/markdown"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/markdown_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `escapeMdHtml` CommonMark block/inline parser, HTML renderer, TOC heading extractor, link extractor, and plain-text stripper. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `s.replace("&", "&amp;").replace("<", "&lt;").replace(">", "&gt;").replace("\"", "&quot;")`.

```aipl
module tests.functions.encoding.markdown_z1_test
import * from "std/encoding/markdown"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_markdown_escapeMdHtml_1(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = escapeMdHtml(arg_s)
  let resEdge = escapeMdHtml(edge_s)
  assertEqStr(resNom, "test", "escapeMdHtml nominal string matches")
  assertEqStr(resEdge, "a", "escapeMdHtml boundary string matches")
  ret 0
```

---

### `isHorizontalRuleLine` (`std/encoding/markdown.aipl`)

- **Signature**: `fn isHorizontalRuleLine(trimmed: str): bool:`
- **Import**: `import * from "std/encoding/markdown"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `trimmed: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/encoding/markdown_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `isHorizontalRuleLine` CommonMark block/inline parser, HTML renderer, TOC heading extractor, link extractor, and plain-text stripper. Concrete nominal inputs: `trimmed: str = "aipl_test"`; exercises core body path returning/computing `count >= 3`.

```aipl
module tests.functions.encoding.markdown_z2_test
import * from "std/encoding/markdown"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_markdown_isHorizontalRuleLine_2(): int:
  let arg_trimmed = "test"
  let edge_trimmed = "a"
  let resNom = isHorizontalRuleLine(arg_trimmed)
  let resEdge = isHorizontalRuleLine(edge_trimmed)
  assert(resNom == false, "isHorizontalRuleLine nominal resNom == false")
  assert(resEdge == false, "isHorizontalRuleLine boundary resEdge == false")
  ret 0
```

---

### `splitTableRowCells` (`std/encoding/markdown.aipl`)

- **Signature**: `fn splitTableRowCells(line: str): [str]:`
- **Import**: `import * from "std/encoding/markdown"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `line: str` | **Returns**: `[str]`
- **Unit Test**: `tests/functions/encoding/markdown_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `splitTableRowCells` CommonMark block/inline parser, HTML renderer, TOC heading extractor, link extractor, and plain-text stripper. Concrete nominal inputs: `line: str = "aipl_test"`; exercises core body path returning/computing `cells`.

```aipl
module tests.functions.encoding.markdown_z3_test
import * from "std/encoding/markdown"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_markdown_splitTableRowCells_3(): int:
  let arg_line = "test"
  let edge_line = "a"
  let resNom = splitTableRowCells(arg_line)
  let resEdge = splitTableRowCells(edge_line)
  assertEqInt(resNom.len(), 1, "splitTableRowCells nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "splitTableRowCells boundary resEdge.len() == 1")
  ret 0
```

---

### `isTableSeparatorLine` (`std/encoding/markdown.aipl`)

- **Signature**: `fn isTableSeparatorLine(line: str): bool:`
- **Import**: `import * from "std/encoding/markdown"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `line: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/encoding/markdown_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `isTableSeparatorLine` CommonMark block/inline parser, HTML renderer, TOC heading extractor, link extractor, and plain-text stripper. Concrete nominal inputs: `line: str = "aipl_test"`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.encoding.markdown_z4_test
import * from "std/encoding/markdown"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_markdown_isTableSeparatorLine_4(): int:
  let arg_line = "test"
  let edge_line = "a"
  let resNom = isTableSeparatorLine(arg_line)
  let resEdge = isTableSeparatorLine(edge_line)
  assert(resNom == false, "isTableSeparatorLine nominal resNom == false")
  assert(resEdge == false, "isTableSeparatorLine boundary resEdge == false")
  ret 0
```

---

### `isOrderedListPrefix` (`std/encoding/markdown.aipl`)

- **Signature**: `fn isOrderedListPrefix(trimmed: str): int:`
- **Import**: `import * from "std/encoding/markdown"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `trimmed: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/encoding/markdown_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `isOrderedListPrefix` CommonMark block/inline parser, HTML renderer, TOC heading extractor, link extractor, and plain-text stripper. Concrete nominal inputs: `trimmed: str = "aipl_test"`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.encoding.markdown_z5_test
import * from "std/encoding/markdown"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_markdown_isOrderedListPrefix_5(): int:
  let arg_trimmed = "test"
  let edge_trimmed = "a"
  let resNom = isOrderedListPrefix(arg_trimmed)
  let resEdge = isOrderedListPrefix(edge_trimmed)
  assertEqInt(resNom, 0, "isOrderedListPrefix nominal resNom == 0")
  assertEqInt(resEdge, 0, "isOrderedListPrefix boundary resEdge == 0")
  ret 0
```

---

### `renderInlineMarkdown` (`std/encoding/markdown.aipl`)

- **Signature**: `fn renderInlineMarkdown(text: str): str:`
- **Import**: `import * from "std/encoding/markdown"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/markdown_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `renderInlineMarkdown` CommonMark block/inline parser, HTML renderer, TOC heading extractor, link extractor, and plain-text stripper. Concrete nominal inputs: `text: str = "aipl_test"`; exercises core body path returning/computing `out.join("")`.

```aipl
module tests.functions.encoding.markdown_z6_test
import * from "std/encoding/markdown"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_markdown_renderInlineMarkdown_6(): int:
  let arg_text = "test"
  let edge_text = "a"
  let resNom = renderInlineMarkdown(arg_text)
  let resEdge = renderInlineMarkdown(edge_text)
  assertEqStr(resNom, "test", "renderInlineMarkdown nominal string matches")
  assertEqStr(resEdge, "a", "renderInlineMarkdown boundary string matches")
  ret 0
```

---

### `parseMarkdown` (`std/encoding/markdown.aipl`)

- **Signature**: `pub fn parseMarkdown(text: str): MdDocument:`
- **Import**: `import * from "std/encoding/markdown"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str` | **Returns**: `MdDocument`
- **Unit Test**: `tests/functions/encoding/markdown_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `parseMarkdown` CommonMark block/inline parser, HTML renderer, TOC heading extractor, link extractor, and plain-text stripper. Concrete nominal inputs: `text: str = "aipl_test"`; exercises core body path returning/computing `MdDocument(blocks = blocks)`.

```aipl
module tests.functions.encoding.markdown_z7_test
import * from "std/encoding/markdown"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_markdown_parseMarkdown_7(): int:
  let arg_text = "test"
  let edge_text = "a"
  let resNom = parseMarkdown(arg_text)
  let resEdge = parseMarkdown(edge_text)
  assertEqInt(resNom.blocks.len(), 1, "parseMarkdown nominal resNom.blocks.len() == 1")
  assertEqInt(resEdge.blocks.len(), 1, "parseMarkdown boundary resEdge.blocks.len() == 1")
  ret 0
```

---

### `renderMarkdownHtml` (`std/encoding/markdown.aipl`)

- **Signature**: `pub fn renderMarkdownHtml(doc: MdDocument): str:`
- **Import**: `import * from "std/encoding/markdown"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `doc: MdDocument` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/markdown_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `renderMarkdownHtml` CommonMark block/inline parser, HTML renderer, TOC heading extractor, link extractor, and plain-text stripper. Concrete nominal inputs: `doc: MdDocument = MdDocument(blocks = [MdBlock(kind = 0, level = 0, lang = 0, text = 0, items = 0, headers = 0, rows = 0)])`; exercises core body path returning/computing `out.join("\n")`.

```aipl
module tests.functions.encoding.markdown_z8_test
import * from "std/encoding/markdown"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_markdown_renderMarkdownHtml_8(): int:
  let arg_doc = MdDocument(blocks = [])
  let edge_doc = MdDocument(blocks = [])
  let resNom = renderMarkdownHtml(arg_doc)
  let resEdge = renderMarkdownHtml(edge_doc)
  assertEqStr(resNom, "", "renderMarkdownHtml nominal string matches")
  assertEqStr(resEdge, "", "renderMarkdownHtml boundary string matches")
  ret 0
```

---

### `markdownToHtml` (`std/encoding/markdown.aipl`)

- **Signature**: `pub fn markdownToHtml(text: str): str:`
- **Import**: `import * from "std/encoding/markdown"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/markdown_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `markdownToHtml` CommonMark block/inline parser, HTML renderer, TOC heading extractor, link extractor, and plain-text stripper. Concrete nominal inputs: `text: str = "aipl_test"`; exercises core body path returning/computing `renderMarkdownHtml(parseMarkdown(text))`.

```aipl
module tests.functions.encoding.markdown_z9_test
import * from "std/encoding/markdown"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_markdown_markdownToHtml_9(): int:
  let arg_text = "test"
  let edge_text = "a"
  let resNom = markdownToHtml(arg_text)
  let resEdge = markdownToHtml(edge_text)
  assertEqStr(resNom, "<p>test</p>", "markdownToHtml nominal string matches")
  assertEqStr(resEdge, "<p>a</p>", "markdownToHtml boundary string matches")
  ret 0
```

---

### `extractMarkdownHeadings` (`std/encoding/markdown.aipl`)

- **Signature**: `pub fn extractMarkdownHeadings(text: str): [MdBlock]:`
- **Import**: `import * from "std/encoding/markdown"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str` | **Returns**: `[MdBlock]`
- **Unit Test**: `tests/functions/encoding/markdown_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `extractMarkdownHeadings` CommonMark block/inline parser, HTML renderer, TOC heading extractor, link extractor, and plain-text stripper. Concrete nominal inputs: `text: str = "aipl_test"`; exercises core body path returning/computing `res`.

```aipl
module tests.functions.encoding.markdown_z10_test
import * from "std/encoding/markdown"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_markdown_extractMarkdownHeadings_10(): int:
  let arg_text = "test"
  let edge_text = "a"
  let resNom = extractMarkdownHeadings(arg_text)
  let resEdge = extractMarkdownHeadings(edge_text)
  assertEqInt(resNom.len(), 0, "extractMarkdownHeadings nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "extractMarkdownHeadings boundary resEdge.len() == 0")
  ret 0
```

---

### `extractMarkdownCodeBlocks` (`std/encoding/markdown.aipl`)

- **Signature**: `pub fn extractMarkdownCodeBlocks(text: str): [MdBlock]:`
- **Import**: `import * from "std/encoding/markdown"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str` | **Returns**: `[MdBlock]`
- **Unit Test**: `tests/functions/encoding/markdown_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `extractMarkdownCodeBlocks` CommonMark block/inline parser, HTML renderer, TOC heading extractor, link extractor, and plain-text stripper. Concrete nominal inputs: `text: str = "aipl_test"`; exercises core body path returning/computing `res`.

```aipl
module tests.functions.encoding.markdown_z11_test
import * from "std/encoding/markdown"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_markdown_extractMarkdownCodeBlocks_11(): int:
  let arg_text = "test"
  let edge_text = "a"
  let resNom = extractMarkdownCodeBlocks(arg_text)
  let resEdge = extractMarkdownCodeBlocks(edge_text)
  assertEqInt(resNom.len(), 0, "extractMarkdownCodeBlocks nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "extractMarkdownCodeBlocks boundary resEdge.len() == 0")
  ret 0
```

---

### `markdownStrip` (`std/encoding/markdown.aipl`)

- **Signature**: `pub fn markdownStrip(text: str): str:`
- **Import**: `import * from "std/encoding/markdown"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/markdown_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `markdownStrip` CommonMark block/inline parser, HTML renderer, TOC heading extractor, link extractor, and plain-text stripper. Concrete nominal inputs: `text: str = "aipl_test"`; exercises core body path returning/computing `out.join(" ")`.

```aipl
module tests.functions.encoding.markdown_z12_test
import * from "std/encoding/markdown"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_markdown_markdownStrip_12(): int:
  let arg_text = "127.0.0.1"
  let edge_text = "127.0.0.1"
  let resNom = markdownStrip(arg_text)
  let resEdge = markdownStrip(edge_text)
  assertEqStr(resNom, "127.0.0.1", "markdownStrip nominal string matches")
  assertEqStr(resEdge, "127.0.0.1", "markdownStrip boundary string matches")
  ret 0
```

---

### `markdownToPlainText` (`std/encoding/markdown.aipl`)

- **Signature**: `pub fn markdownToPlainText(text: str): str:`
- **Import**: `import * from "std/encoding/markdown"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/markdown_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `markdownToPlainText` CommonMark block/inline parser, HTML renderer, TOC heading extractor, link extractor, and plain-text stripper. Concrete nominal inputs: `text: str = "aipl_test"`; exercises core body path returning/computing `markdownStrip(text)`.

```aipl
module tests.functions.encoding.markdown_z13_test
import * from "std/encoding/markdown"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_markdown_markdownToPlainText_13(): int:
  let arg_text = "42"
  let edge_text = "0"
  let resNom = markdownToPlainText(arg_text)
  let resEdge = markdownToPlainText(edge_text)
  assertEqStr(resNom, "42", "markdownToPlainText nominal string matches")
  assertEqStr(resEdge, "0", "markdownToPlainText boundary string matches")
  ret 0
```

---

### `parseMarkdownHeadings` (`std/encoding/markdown.aipl`)

- **Signature**: `pub fn parseMarkdownHeadings(text: str): [(int, str)]:`
- **Import**: `import * from "std/encoding/markdown"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str` | **Returns**: `[(int, str)]`
- **Unit Test**: `tests/functions/encoding/markdown_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `parseMarkdownHeadings` CommonMark block/inline parser, HTML renderer, TOC heading extractor, link extractor, and plain-text stripper. Concrete nominal inputs: `text: str = "aipl_test"`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.encoding.markdown_z14_test
import * from "std/encoding/markdown"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_markdown_parseMarkdownHeadings_14(): int:
  let arg_text = "test"
  let edge_text = "a"
  let resNom = parseMarkdownHeadings(arg_text)
  let resEdge = parseMarkdownHeadings(edge_text)
  assertEqInt(resNom.len(), 0, "parseMarkdownHeadings nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "parseMarkdownHeadings boundary resEdge.len() == 0")
  ret 0
```

---

### `markdownWordCount` (`std/encoding/markdown.aipl`)

- **Signature**: `pub fn markdownWordCount(text: str): int:`
- **Import**: `import * from "std/encoding/markdown"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/encoding/markdown_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `markdownWordCount` CommonMark block/inline parser, HTML renderer, TOC heading extractor, link extractor, and plain-text stripper. Concrete nominal inputs: `text: str = "aipl_test"`; exercises core body path returning/computing `count`.

```aipl
module tests.functions.encoding.markdown_z15_test
import * from "std/encoding/markdown"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_markdown_markdownWordCount_15(): int:
  let arg_text = "test"
  let edge_text = "a"
  let resNom = markdownWordCount(arg_text)
  let resEdge = markdownWordCount(edge_text)
  assertEqInt(resNom, 1, "markdownWordCount nominal resNom == 1")
  assertEqInt(resEdge, 1, "markdownWordCount boundary resEdge == 1")
  ret 0
```

---

### `extractMarkdownLinks` (`std/encoding/markdown.aipl`)

- **Signature**: `pub fn extractMarkdownLinks(text: str): [(str, str)]:`
- **Import**: `import * from "std/encoding/markdown"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str` | **Returns**: `[(str, str)]`
- **Unit Test**: `tests/functions/encoding/markdown_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `extractMarkdownLinks` CommonMark block/inline parser, HTML renderer, TOC heading extractor, link extractor, and plain-text stripper. Concrete nominal inputs: `text: str = "aipl_test"`; exercises core body path returning/computing `links`.

```aipl
module tests.functions.encoding.markdown_z16_test
import * from "std/encoding/markdown"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_markdown_extractMarkdownLinks_16(): int:
  let arg_text = "test"
  let edge_text = "a"
  let resNom = extractMarkdownLinks(arg_text)
  let resEdge = extractMarkdownLinks(edge_text)
  assertEqInt(resNom.len(), 0, "extractMarkdownLinks nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "extractMarkdownLinks boundary resEdge.len() == 0")
  ret 0
```

---

### `parseNonNegInt` (`std/encoding/qrcode_semver.aipl`)

- **Signature**: `fn parseNonNegInt(s: str): int:`
- **Import**: `import * from "std/encoding/qrcode_semver"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/encoding/qrcode_semver_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `parseNonNegInt` SemVer 2.0.0 parsing/precedence/range matching (`^`, `~`) or QR Code Version 1 finder pattern, Reed-Solomon GF(256) ECC, and matrix/SVG/ASCII rendering. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `acc`.

```aipl
module tests.functions.encoding.qrcode_semver_z1_test
import * from "std/encoding/qrcode_semver"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_qrcode_semver_parseNonNegInt_1(): int:
  let arg_s = "42"
  let edge_s = "0"
  let resNom = parseNonNegInt(arg_s)
  let resEdge = parseNonNegInt(edge_s)
  assertEqInt(resNom, 42, "parseNonNegInt nominal resNom == 42")
  assertEqInt(resEdge, 0, "parseNonNegInt boundary resEdge == 0")
  ret 0
```

---

### `parseSemVer` (`std/encoding/qrcode_semver.aipl`)

- **Signature**: `pub fn parseSemVer(text: str): Result[SemVer, str]:`
- **Import**: `import * from "std/encoding/qrcode_semver"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str` | **Returns**: `Result[SemVer, str]`
- **Unit Test**: `tests/functions/encoding/qrcode_semver_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `parseSemVer` SemVer 2.0.0 parsing/precedence/range matching (`^`, `~`) or QR Code Version 1 finder pattern, Reed-Solomon GF(256) ECC, and matrix/SVG/ASCII rendering. Concrete nominal inputs: `text: str = "aipl_test"`; exercises core body path returning/computing `Ok(SemVer(major = maj, minor = min, patch = pat, prerelease = prerelease, build = build))`.

```aipl
module tests.functions.encoding.qrcode_semver_z2_test
import * from "std/encoding/qrcode_semver"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_qrcode_semver_parseSemVer_2(): int:
  let arg_text = "test"
  let edge_text = "a"
  let resNom = parseSemVer(arg_text)
  let resEdge = parseSemVer(edge_text)
  assert(resNom.isOk() == false, "parseSemVer nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "parseSemVer boundary resEdge.isOk() == false")
  ret 0
```

---

### `formatSemVer` (`std/encoding/qrcode_semver.aipl`)

- **Signature**: `pub fn formatSemVer(v: SemVer): str:`
- **Import**: `import * from "std/encoding/qrcode_semver"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: SemVer` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/qrcode_semver_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `formatSemVer` SemVer 2.0.0 parsing/precedence/range matching (`^`, `~`) or QR Code Version 1 finder pattern, Reed-Solomon GF(256) ECC, and matrix/SVG/ASCII rendering. Concrete nominal inputs: `v: SemVer = SemVer(major = 1, minor = 1, patch = 1, prerelease = str = ""(), build = str = ""())`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.encoding.qrcode_semver_z3_test
import * from "std/encoding/qrcode_semver"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_qrcode_semver_formatSemVer_3(): int:
  let arg_v = SemVer(major = 4, minor = 4, patch = 2, prerelease = "test", build = "test")
  let edge_v = SemVer(major = 1, minor = 1, patch = 0, prerelease = "a", build = "a")
  let resNom = formatSemVer(arg_v)
  let resEdge = formatSemVer(edge_v)
  assertEqStr(resNom, "4.4.2-test+test", "formatSemVer nominal string matches")
  assertEqStr(resEdge, "1.1.0-a+a", "formatSemVer boundary string matches")
  ret 0
```

---

### `comparePrerelease` (`std/encoding/qrcode_semver.aipl`)

- **Signature**: `fn comparePrerelease(preA: str, preB: str): int:`
- **Import**: `import * from "std/encoding/qrcode_semver"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `preA: str, preB: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/encoding/qrcode_semver_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `comparePrerelease` SemVer 2.0.0 parsing/precedence/range matching (`^`, `~`) or QR Code Version 1 finder pattern, Reed-Solomon GF(256) ECC, and matrix/SVG/ASCII rendering. Concrete nominal inputs: `preA: str = "aipl_test"`, `preB: str = "aipl_test"`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.encoding.qrcode_semver_z4_test
import * from "std/encoding/qrcode_semver"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_qrcode_semver_comparePrerelease_4(): int:
  let arg_preA = "test"
  let edge_preA = "a"
  let arg_preB = "test"
  let edge_preB = "a"
  let resNom = comparePrerelease(arg_preA, arg_preB)
  let resEdge = comparePrerelease(edge_preA, edge_preB)
  assertEqInt(resNom, 0, "comparePrerelease nominal resNom == 0")
  assertEqInt(resEdge, 0, "comparePrerelease boundary resEdge == 0")
  ret 0
```

---

### `compareSemVer` (`std/encoding/qrcode_semver.aipl`)

- **Signature**: `pub fn compareSemVer(a: SemVer, b: SemVer): int:`
- **Import**: `import * from "std/encoding/qrcode_semver"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: SemVer, b: SemVer` | **Returns**: `int`
- **Unit Test**: `tests/functions/encoding/qrcode_semver_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `compareSemVer` SemVer 2.0.0 parsing/precedence/range matching (`^`, `~`) or QR Code Version 1 finder pattern, Reed-Solomon GF(256) ECC, and matrix/SVG/ASCII rendering. Concrete nominal inputs: `a: SemVer = SemVer(major = 1, minor = 1, patch = 1, prerelease = str = ""(), build = str = ""())`, `b: SemVer = SemVer(major = 1, minor = 1, patch = 1, prerelease = str = ""(), build = str = ""())`; exercises core body path returning/computing `comparePrerelease(a.prerelease, b.prerelease)`.

```aipl
module tests.functions.encoding.qrcode_semver_z5_test
import * from "std/encoding/qrcode_semver"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_qrcode_semver_compareSemVer_5(): int:
  let arg_a = SemVer(major = 4, minor = 4, patch = 2, prerelease = "test", build = "test")
  let edge_a = SemVer(major = 1, minor = 1, patch = 0, prerelease = "a", build = "a")
  let arg_b = SemVer(major = 4, minor = 4, patch = 2, prerelease = "test", build = "test")
  let edge_b = SemVer(major = 1, minor = 1, patch = 0, prerelease = "a", build = "a")
  let resNom = compareSemVer(arg_a, arg_b)
  let resEdge = compareSemVer(edge_a, edge_b)
  assertEqInt(resNom, 0, "compareSemVer nominal resNom == 0")
  assertEqInt(resEdge, 0, "compareSemVer boundary resEdge == 0")
  ret 0
```

---

### `satisfiesSingleSemVer` (`std/encoding/qrcode_semver.aipl`)

- **Signature**: `fn satisfiesSingleSemVer(v: SemVer, single: str): bool:`
- **Import**: `import * from "std/encoding/qrcode_semver"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: SemVer, single: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/encoding/qrcode_semver_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `satisfiesSingleSemVer` SemVer 2.0.0 parsing/precedence/range matching (`^`, `~`) or QR Code Version 1 finder pattern, Reed-Solomon GF(256) ECC, and matrix/SVG/ASCII rendering. Concrete nominal inputs: `v: SemVer = SemVer(major = 1, minor = 1, patch = 1, prerelease = str = ""(), build = str = ""())`, `single: str = "aipl_test"`; exercises core body path returning/computing `compareSemVer(v, r.unwrap()) == 0`.

```aipl
module tests.functions.encoding.qrcode_semver_z6_test
import * from "std/encoding/qrcode_semver"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_qrcode_semver_satisfiesSingleSemVer_6(): int:
  let arg_v = SemVer(major = 4, minor = 4, patch = 2, prerelease = "test", build = "test")
  let edge_v = SemVer(major = 1, minor = 1, patch = 0, prerelease = "a", build = "a")
  let arg_single = "test"
  let edge_single = "a"
  let resNom = satisfiesSingleSemVer(arg_v, arg_single)
  let resEdge = satisfiesSingleSemVer(edge_v, edge_single)
  assert(resNom == false, "satisfiesSingleSemVer nominal resNom == false")
  assert(resEdge == false, "satisfiesSingleSemVer boundary resEdge == false")
  ret 0
```

---

### `satisfiesSemVer` (`std/encoding/qrcode_semver.aipl`)

- **Signature**: `pub fn satisfiesSemVer(v: SemVer, constraint: str): bool:`
- **Import**: `import * from "std/encoding/qrcode_semver"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: SemVer, constraint: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/encoding/qrcode_semver_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `satisfiesSemVer` SemVer 2.0.0 parsing/precedence/range matching (`^`, `~`) or QR Code Version 1 finder pattern, Reed-Solomon GF(256) ECC, and matrix/SVG/ASCII rendering. Concrete nominal inputs: `v: SemVer = SemVer(major = 1, minor = 1, patch = 1, prerelease = str = ""(), build = str = ""())`, `constraint: str = "aipl_test"`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.encoding.qrcode_semver_z7_test
import * from "std/encoding/qrcode_semver"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_qrcode_semver_satisfiesSemVer_7(): int:
  let arg_v = SemVer(major = 4, minor = 4, patch = 2, prerelease = "test", build = "test")
  let edge_v = SemVer(major = 1, minor = 1, patch = 0, prerelease = "a", build = "a")
  let arg_constraint = "test"
  let edge_constraint = "a"
  let resNom = satisfiesSemVer(arg_v, arg_constraint)
  let resEdge = satisfiesSemVer(edge_v, edge_constraint)
  assert(resNom == false, "satisfiesSemVer nominal resNom == false")
  assert(resEdge == false, "satisfiesSemVer boundary resEdge == false")
  ret 0
```

---

### `generateQrMatrix` (`std/encoding/qrcode_semver.aipl`)

- **Signature**: `pub fn generateQrMatrix(payload: str, ecLevel: int = 1): QrMatrix:`
- **Import**: `import * from "std/encoding/qrcode_semver"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `payload: str, ecLevel: int = 1` | **Returns**: `QrMatrix`
- **Unit Test**: `tests/functions/encoding/qrcode_semver_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `generateQrMatrix` SemVer 2.0.0 parsing/precedence/range matching (`^`, `~`) or QR Code Version 1 finder pattern, Reed-Solomon GF(256) ECC, and matrix/SVG/ASCII rendering. Concrete nominal inputs: `payload: str = "aipl_test"`, `ecLevel: int = 1`; exercises core body path returning/computing `QrMatrix(version = ver, size = sz, modules = mods)`.

```aipl
module tests.functions.encoding.qrcode_semver_z8_test
import * from "std/encoding/qrcode_semver"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_qrcode_semver_generateQrMatrix_8(): int:
  let arg_payload = "test"
  let edge_payload = "a"
  let arg_ecLevel = 2
  let edge_ecLevel = 0
  let resNom = generateQrMatrix(arg_payload, arg_ecLevel)
  let resEdge = generateQrMatrix(edge_payload, edge_ecLevel)
  assertEqInt(resNom.version, 1, "generateQrMatrix nominal resNom.version == 1")
  assertEqInt(resEdge.version, 1, "generateQrMatrix boundary resEdge.version == 1")
  ret 0
```

---

### `qrGetModule` (`std/encoding/qrcode_semver.aipl`)

- **Signature**: `pub fn qrGetModule(qr: QrMatrix, x: int, y: int): bool:`
- **Import**: `import * from "std/encoding/qrcode_semver"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `qr: QrMatrix, x: int, y: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/encoding/qrcode_semver_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `qrGetModule` SemVer 2.0.0 parsing/precedence/range matching (`^`, `~`) or QR Code Version 1 finder pattern, Reed-Solomon GF(256) ECC, and matrix/SVG/ASCII rendering. Concrete nominal inputs: `qr: QrMatrix = QrMatrix(version = 1, size = 64, modules = [true])`, `x: int = 1`, `y: int = 1`; exercises core body path returning/computing `qr.modules[y * qr.size + x]`.

```aipl
module tests.functions.encoding.qrcode_semver_z9_test
import * from "std/encoding/qrcode_semver"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_qrcode_semver_qrGetModule_9(): int:
  let arg_qr = QrMatrix(version = 4, size = 0, modules = [])
  let edge_qr = QrMatrix(version = 1, size = 0, modules = [])
  let arg_x = 1
  let edge_x = 0
  let arg_y = 1
  let edge_y = 0
  let resNom = qrGetModule(arg_qr, arg_x, arg_y)
  let resEdge = qrGetModule(edge_qr, edge_x, edge_y)
  assert(resNom == false, "qrGetModule nominal resNom == false")
  assert(resEdge == false, "qrGetModule boundary resEdge == false")
  ret 0
```

---

### `renderQrAscii` (`std/encoding/qrcode_semver.aipl`)

- **Signature**: `pub fn renderQrAscii(qr: QrMatrix): str:`
- **Import**: `import * from "std/encoding/qrcode_semver"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `qr: QrMatrix` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/qrcode_semver_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `renderQrAscii` SemVer 2.0.0 parsing/precedence/range matching (`^`, `~`) or QR Code Version 1 finder pattern, Reed-Solomon GF(256) ECC, and matrix/SVG/ASCII rendering. Concrete nominal inputs: `qr: QrMatrix = QrMatrix(version = 1, size = 64, modules = [true])`; exercises core body path returning/computing `lines.join("\n")`.

```aipl
module tests.functions.encoding.qrcode_semver_z10_test
import * from "std/encoding/qrcode_semver"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_qrcode_semver_renderQrAscii_10(): int:
  let arg_qr = QrMatrix(version = 4, size = 0, modules = [])
  let edge_qr = QrMatrix(version = 1, size = 0, modules = [])
  let resNom = renderQrAscii(arg_qr)
  let resEdge = renderQrAscii(edge_qr)
  assertEqStr(resNom, "", "renderQrAscii nominal string matches")
  assertEqStr(resEdge, "", "renderQrAscii boundary string matches")
  ret 0
```

---

### `renderQrSvg` (`std/encoding/qrcode_semver.aipl`)

- **Signature**: `pub fn renderQrSvg(qr: QrMatrix, moduleSizePx: int = 4): str:`
- **Import**: `import * from "std/encoding/qrcode_semver"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `qr: QrMatrix, moduleSizePx: int = 4` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/qrcode_semver_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `renderQrSvg` SemVer 2.0.0 parsing/precedence/range matching (`^`, `~`) or QR Code Version 1 finder pattern, Reed-Solomon GF(256) ECC, and matrix/SVG/ASCII rendering. Concrete nominal inputs: `qr: QrMatrix = QrMatrix(version = 1, size = 64, modules = [true])`, `moduleSizePx: int = 64`; exercises core body path returning/computing `rects.join("")`.

```aipl
module tests.functions.encoding.qrcode_semver_z11_test
import * from "std/encoding/qrcode_semver"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_qrcode_semver_renderQrSvg_11(): int:
  let arg_qr = QrMatrix(version = 4, size = 0, modules = [])
  let edge_qr = QrMatrix(version = 1, size = 0, modules = [])
  let arg_moduleSizePx = 4
  let edge_moduleSizePx = 1
  let resNom = renderQrSvg(arg_qr, arg_moduleSizePx)
  let resEdge = renderQrSvg(edge_qr, edge_moduleSizePx)
  assertEqInt(resNom.len(), 134, "renderQrSvg nominal string length == 134")
  assertEqInt(resEdge.len(), 134, "renderQrSvg boundary string length == 134")
  ret 0
```

---

### `qrGf256Mul` (`std/encoding/qrcode_semver.aipl`)

- **Signature**: `pub fn qrGf256Mul(a: int, b: int): int:`
- **Import**: `import * from "std/encoding/qrcode_semver"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: int, b: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/encoding/qrcode_semver_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `qrGf256Mul` SemVer 2.0.0 parsing/precedence/range matching (`^`, `~`) or QR Code Version 1 finder pattern, Reed-Solomon GF(256) ECC, and matrix/SVG/ASCII rendering. Concrete nominal inputs: `a: int = 1`, `b: int = 1`; exercises core body path returning/computing `res`.

```aipl
module tests.functions.encoding.qrcode_semver_z12_test
import * from "std/encoding/qrcode_semver"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_qrcode_semver_qrGf256Mul_12(): int:
  let arg_a = 2
  let edge_a = 0
  let arg_b = 4
  let edge_b = 1
  let resNom = qrGf256Mul(arg_a, arg_b)
  let resEdge = qrGf256Mul(edge_a, edge_b)
  assertEqInt(resNom, 8, "qrGf256Mul nominal resNom == 8")
  assertEqInt(resEdge, 0, "qrGf256Mul boundary resEdge == 0")
  ret 0
```

---

### `qrReedSolomonEncode` (`std/encoding/qrcode_semver.aipl`)

- **Signature**: `pub fn qrReedSolomonEncode(data: [int], ecCount: int): [int]:`
- **Import**: `import * from "std/encoding/qrcode_semver"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: [int], ecCount: int` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/encoding/qrcode_semver_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `qrReedSolomonEncode` SemVer 2.0.0 parsing/precedence/range matching (`^`, `~`) or QR Code Version 1 finder pattern, Reed-Solomon GF(256) ECC, and matrix/SVG/ASCII rendering. Concrete nominal inputs: `data: [int] = [1]`, `ecCount: int = 64`; exercises core body path returning/computing `rem`.

```aipl
module tests.functions.encoding.qrcode_semver_z13_test
import * from "std/encoding/qrcode_semver"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_qrcode_semver_qrReedSolomonEncode_13(): int:
  let arg_data = [2]
  let edge_data = []
  let arg_ecCount = 4
  let edge_ecCount = 1
  let resNom = qrReedSolomonEncode(arg_data, arg_ecCount)
  let resEdge = qrReedSolomonEncode(edge_data, edge_ecCount)
  assertEqInt(resNom.len(), 4, "qrReedSolomonEncode nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 1, "qrReedSolomonEncode boundary resEdge.len() == 1")
  ret 0
```

---

### `qrComputeBchFormatBits` (`std/encoding/qrcode_semver.aipl`)

- **Signature**: `pub fn qrComputeBchFormatBits(ecLevel: int, maskPattern: int): int:`
- **Import**: `import * from "std/encoding/qrcode_semver"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ecLevel: int, maskPattern: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/encoding/qrcode_semver_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `qrComputeBchFormatBits` SemVer 2.0.0 parsing/precedence/range matching (`^`, `~`) or QR Code Version 1 finder pattern, Reed-Solomon GF(256) ECC, and matrix/SVG/ASCII rendering. Concrete nominal inputs: `ecLevel: int = 1`, `maskPattern: int = 1`; exercises core body path returning/computing `((dataBits << 10) | (rem & 1023)) ^ 21522`.

```aipl
module tests.functions.encoding.qrcode_semver_z14_test
import * from "std/encoding/qrcode_semver"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_qrcode_semver_qrComputeBchFormatBits_14(): int:
  let arg_ecLevel = 2
  let edge_ecLevel = 0
  let arg_maskPattern = 4
  let edge_maskPattern = 1
  let resNom = qrComputeBchFormatBits(arg_ecLevel, arg_maskPattern)
  let resEdge = qrComputeBchFormatBits(edge_ecLevel, edge_maskPattern)
  assertEqInt(resNom, 1890, "qrComputeBchFormatBits nominal resNom == 1890")
  assertEqInt(resEdge, 20773, "qrComputeBchFormatBits boundary resEdge == 20773")
  ret 0
```

---

### `encodeQrCode` (`std/encoding/qrcode_semver.aipl`)

- **Signature**: `pub fn encodeQrCode(text: str): QrMatrix:`
- **Import**: `import * from "std/encoding/qrcode_semver"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str` | **Returns**: `QrMatrix`
- **Unit Test**: `tests/functions/encoding/qrcode_semver_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `encodeQrCode` SemVer 2.0.0 parsing/precedence/range matching (`^`, `~`) or QR Code Version 1 finder pattern, Reed-Solomon GF(256) ECC, and matrix/SVG/ASCII rendering. Concrete nominal inputs: `text: str = "aipl_test"`; exercises core body path returning/computing `generateQrMatrix(text, 1)`.

```aipl
module tests.functions.encoding.qrcode_semver_z15_test
import * from "std/encoding/qrcode_semver"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_qrcode_semver_encodeQrCode_15(): int:
  let arg_text = "test"
  let edge_text = "a"
  let resNom = encodeQrCode(arg_text)
  let resEdge = encodeQrCode(edge_text)
  assertEqInt(resNom.version, 1, "encodeQrCode nominal resNom.version == 1")
  assertEqInt(resEdge.version, 1, "encodeQrCode boundary resEdge.version == 1")
  ret 0
```

---

### `qrToAscii` (`std/encoding/qrcode_semver.aipl`)

- **Signature**: `pub fn qrToAscii(matrix: QrMatrix): str:`
- **Import**: `import * from "std/encoding/qrcode_semver"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `matrix: QrMatrix` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/qrcode_semver_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `qrToAscii` SemVer 2.0.0 parsing/precedence/range matching (`^`, `~`) or QR Code Version 1 finder pattern, Reed-Solomon GF(256) ECC, and matrix/SVG/ASCII rendering. Concrete nominal inputs: `matrix: QrMatrix = QrMatrix(version = 1, size = 64, modules = [true])`; exercises core body path returning/computing `renderQrAscii(matrix)`.

```aipl
module tests.functions.encoding.qrcode_semver_z16_test
import * from "std/encoding/qrcode_semver"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_qrcode_semver_qrToAscii_16(): int:
  let arg_matrix = QrMatrix(version = 4, size = 0, modules = [])
  let edge_matrix = QrMatrix(version = 1, size = 0, modules = [])
  let resNom = qrToAscii(arg_matrix)
  let resEdge = qrToAscii(edge_matrix)
  assertEqStr(resNom, "", "qrToAscii nominal string matches")
  assertEqStr(resEdge, "", "qrToAscii boundary string matches")
  ret 0
```

---

### `qrToSvg` (`std/encoding/qrcode_semver.aipl`)

- **Signature**: `pub fn qrToSvg(matrix: QrMatrix, scale: int = 4): str:`
- **Import**: `import * from "std/encoding/qrcode_semver"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `matrix: QrMatrix, scale: int = 4` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/qrcode_semver_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `qrToSvg` SemVer 2.0.0 parsing/precedence/range matching (`^`, `~`) or QR Code Version 1 finder pattern, Reed-Solomon GF(256) ECC, and matrix/SVG/ASCII rendering. Concrete nominal inputs: `matrix: QrMatrix = QrMatrix(version = 1, size = 64, modules = [true])`, `scale: int = 1`; exercises core body path returning/computing `renderQrSvg(matrix, scale)`.

```aipl
module tests.functions.encoding.qrcode_semver_z17_test
import * from "std/encoding/qrcode_semver"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_qrcode_semver_qrToSvg_17(): int:
  let arg_matrix = QrMatrix(version = 4, size = 0, modules = [])
  let edge_matrix = QrMatrix(version = 1, size = 0, modules = [])
  let arg_scale = 2
  let edge_scale = 0
  let resNom = qrToSvg(arg_matrix, arg_scale)
  let resEdge = qrToSvg(edge_matrix, edge_scale)
  assertEqInt(resNom.len(), 134, "qrToSvg nominal string length == 134")
  assertEqInt(resEdge.len(), 134, "qrToSvg boundary string length == 134")
  ret 0
```

---

### `parseSemver` (`std/encoding/qrcode_semver.aipl`)

- **Signature**: `pub fn parseSemver(text: str): Result[SemVer, str]:`
- **Import**: `import * from "std/encoding/qrcode_semver"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str` | **Returns**: `Result[SemVer, str]`
- **Unit Test**: `tests/functions/encoding/qrcode_semver_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `parseSemver` SemVer 2.0.0 parsing/precedence/range matching (`^`, `~`) or QR Code Version 1 finder pattern, Reed-Solomon GF(256) ECC, and matrix/SVG/ASCII rendering. Concrete nominal inputs: `text: str = "aipl_test"`; exercises core body path returning/computing `parseSemVer(text)`.

```aipl
module tests.functions.encoding.qrcode_semver_z18_test
import * from "std/encoding/qrcode_semver"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_qrcode_semver_parseSemver_18(): int:
  let arg_text = "test"
  let edge_text = "a"
  let resNom = parseSemver(arg_text)
  let resEdge = parseSemver(edge_text)
  assert(resNom.isOk() == false, "parseSemver nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "parseSemver boundary resEdge.isOk() == false")
  ret 0
```

---

### `formatSemver` (`std/encoding/qrcode_semver.aipl`)

- **Signature**: `pub fn formatSemver(v: SemVer): str:`
- **Import**: `import * from "std/encoding/qrcode_semver"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: SemVer` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/qrcode_semver_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `formatSemver` SemVer 2.0.0 parsing/precedence/range matching (`^`, `~`) or QR Code Version 1 finder pattern, Reed-Solomon GF(256) ECC, and matrix/SVG/ASCII rendering. Concrete nominal inputs: `v: SemVer = SemVer(major = 1, minor = 1, patch = 1, prerelease = str = ""(), build = str = ""())`; exercises core body path returning/computing `formatSemVer(v)`.

```aipl
module tests.functions.encoding.qrcode_semver_z19_test
import * from "std/encoding/qrcode_semver"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_qrcode_semver_formatSemver_19(): int:
  let arg_v = SemVer(major = 4, minor = 4, patch = 2, prerelease = "test", build = "test")
  let edge_v = SemVer(major = 1, minor = 1, patch = 0, prerelease = "a", build = "a")
  let resNom = formatSemver(arg_v)
  let resEdge = formatSemver(edge_v)
  assertEqStr(resNom, "4.4.2-test+test", "formatSemver nominal string matches")
  assertEqStr(resEdge, "1.1.0-a+a", "formatSemver boundary string matches")
  ret 0
```

---

### `compareSemver` (`std/encoding/qrcode_semver.aipl`)

- **Signature**: `pub fn compareSemver(a: SemVer, b: SemVer): int:`
- **Import**: `import * from "std/encoding/qrcode_semver"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: SemVer, b: SemVer` | **Returns**: `int`
- **Unit Test**: `tests/functions/encoding/qrcode_semver_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `compareSemver` SemVer 2.0.0 parsing/precedence/range matching (`^`, `~`) or QR Code Version 1 finder pattern, Reed-Solomon GF(256) ECC, and matrix/SVG/ASCII rendering. Concrete nominal inputs: `a: SemVer = SemVer(major = 1, minor = 1, patch = 1, prerelease = str = ""(), build = str = ""())`, `b: SemVer = SemVer(major = 1, minor = 1, patch = 1, prerelease = str = ""(), build = str = ""())`; exercises core body path returning/computing `compareSemVer(a, b)`.

```aipl
module tests.functions.encoding.qrcode_semver_z20_test
import * from "std/encoding/qrcode_semver"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_qrcode_semver_compareSemver_20(): int:
  let arg_a = SemVer(major = 4, minor = 4, patch = 2, prerelease = "test", build = "test")
  let edge_a = SemVer(major = 1, minor = 1, patch = 0, prerelease = "a", build = "a")
  let arg_b = SemVer(major = 4, minor = 4, patch = 2, prerelease = "test", build = "test")
  let edge_b = SemVer(major = 1, minor = 1, patch = 0, prerelease = "a", build = "a")
  let resNom = compareSemver(arg_a, arg_b)
  let resEdge = compareSemver(edge_a, edge_b)
  assertEqInt(resNom, 0, "compareSemver nominal resNom == 0")
  assertEqInt(resEdge, 0, "compareSemver boundary resEdge == 0")
  ret 0
```

---

### `bumpMajor` (`std/encoding/qrcode_semver.aipl`)

- **Signature**: `pub fn bumpMajor(v: SemVer): SemVer:`
- **Import**: `import * from "std/encoding/qrcode_semver"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: SemVer` | **Returns**: `SemVer`
- **Unit Test**: `tests/functions/encoding/qrcode_semver_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `bumpMajor` SemVer 2.0.0 parsing/precedence/range matching (`^`, `~`) or QR Code Version 1 finder pattern, Reed-Solomon GF(256) ECC, and matrix/SVG/ASCII rendering. Concrete nominal inputs: `v: SemVer = SemVer(major = 1, minor = 1, patch = 1, prerelease = str = ""(), build = str = ""())`; exercises core body path returning/computing `SemVer(major = v.major + 1, minor = 0, patch = 0, prerelease = "", build = "")`.

```aipl
module tests.functions.encoding.qrcode_semver_z21_test
import * from "std/encoding/qrcode_semver"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_qrcode_semver_bumpMajor_21(): int:
  let arg_v = SemVer(major = 4, minor = 4, patch = 2, prerelease = "test", build = "test")
  let edge_v = SemVer(major = 1, minor = 1, patch = 0, prerelease = "a", build = "a")
  let resNom = bumpMajor(arg_v)
  let resEdge = bumpMajor(edge_v)
  assertEqInt(resNom.major, 5, "bumpMajor nominal resNom.major == 5")
  assertEqInt(resEdge.major, 2, "bumpMajor boundary resEdge.major == 2")
  ret 0
```

---

### `bumpMinor` (`std/encoding/qrcode_semver.aipl`)

- **Signature**: `pub fn bumpMinor(v: SemVer): SemVer:`
- **Import**: `import * from "std/encoding/qrcode_semver"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: SemVer` | **Returns**: `SemVer`
- **Unit Test**: `tests/functions/encoding/qrcode_semver_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `bumpMinor` SemVer 2.0.0 parsing/precedence/range matching (`^`, `~`) or QR Code Version 1 finder pattern, Reed-Solomon GF(256) ECC, and matrix/SVG/ASCII rendering. Concrete nominal inputs: `v: SemVer = SemVer(major = 1, minor = 1, patch = 1, prerelease = str = ""(), build = str = ""())`; exercises core body path returning/computing `SemVer(major = v.major, minor = v.minor + 1, patch = 0, prerelease = "", build = "")`.

```aipl
module tests.functions.encoding.qrcode_semver_z22_test
import * from "std/encoding/qrcode_semver"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_qrcode_semver_bumpMinor_22(): int:
  let arg_v = SemVer(major = 4, minor = 4, patch = 2, prerelease = "test", build = "test")
  let edge_v = SemVer(major = 1, minor = 1, patch = 0, prerelease = "a", build = "a")
  let resNom = bumpMinor(arg_v)
  let resEdge = bumpMinor(edge_v)
  assertEqInt(resNom.major, 4, "bumpMinor nominal resNom.major == 4")
  assertEqInt(resEdge.major, 1, "bumpMinor boundary resEdge.major == 1")
  ret 0
```

---

### `bumpPatch` (`std/encoding/qrcode_semver.aipl`)

- **Signature**: `pub fn bumpPatch(v: SemVer): SemVer:`
- **Import**: `import * from "std/encoding/qrcode_semver"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: SemVer` | **Returns**: `SemVer`
- **Unit Test**: `tests/functions/encoding/qrcode_semver_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `bumpPatch` SemVer 2.0.0 parsing/precedence/range matching (`^`, `~`) or QR Code Version 1 finder pattern, Reed-Solomon GF(256) ECC, and matrix/SVG/ASCII rendering. Concrete nominal inputs: `v: SemVer = SemVer(major = 1, minor = 1, patch = 1, prerelease = str = ""(), build = str = ""())`; exercises core body path returning/computing `SemVer(major = v.major, minor = v.minor, patch = v.patch + 1, prerelease = "", build = "")`.

```aipl
module tests.functions.encoding.qrcode_semver_z23_test
import * from "std/encoding/qrcode_semver"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_qrcode_semver_bumpPatch_23(): int:
  let arg_v = SemVer(major = 4, minor = 4, patch = 2, prerelease = "test", build = "test")
  let edge_v = SemVer(major = 1, minor = 1, patch = 0, prerelease = "a", build = "a")
  let resNom = bumpPatch(arg_v)
  let resEdge = bumpPatch(edge_v)
  assertEqInt(resNom.major, 4, "bumpPatch nominal resNom.major == 4")
  assertEqInt(resEdge.major, 1, "bumpPatch boundary resEdge.major == 1")
  ret 0
```

---

### `bumpSemver` (`std/encoding/qrcode_semver.aipl`)

- **Signature**: `pub fn bumpSemver(v: SemVer, part: str): SemVer:`
- **Import**: `import * from "std/encoding/qrcode_semver"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: SemVer, part: str` | **Returns**: `SemVer`
- **Unit Test**: `tests/functions/encoding/qrcode_semver_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `bumpSemver` SemVer 2.0.0 parsing/precedence/range matching (`^`, `~`) or QR Code Version 1 finder pattern, Reed-Solomon GF(256) ECC, and matrix/SVG/ASCII rendering. Concrete nominal inputs: `v: SemVer = SemVer(major = 1, minor = 1, patch = 1, prerelease = str = ""(), build = str = ""())`, `part: str = "aipl_test"`; exercises core body path returning/computing `bumpPatch(v)`.

```aipl
module tests.functions.encoding.qrcode_semver_z24_test
import * from "std/encoding/qrcode_semver"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_qrcode_semver_bumpSemver_24(): int:
  let arg_v = SemVer(major = 4, minor = 4, patch = 2, prerelease = "test", build = "test")
  let edge_v = SemVer(major = 1, minor = 1, patch = 0, prerelease = "a", build = "a")
  let arg_part = "test"
  let edge_part = "a"
  let resNom = bumpSemver(arg_v, arg_part)
  let resEdge = bumpSemver(edge_v, edge_part)
  assertEqInt(resNom.major, 4, "bumpSemver nominal resNom.major == 4")
  assertEqInt(resEdge.major, 1, "bumpSemver boundary resEdge.major == 1")
  ret 0
```

---

### `satisfiesRange` (`std/encoding/qrcode_semver.aipl`)

- **Signature**: `pub fn satisfiesRange(v: SemVer, rangeStr: str): bool:`
- **Import**: `import * from "std/encoding/qrcode_semver"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: SemVer, rangeStr: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/encoding/qrcode_semver_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `satisfiesRange` SemVer 2.0.0 parsing/precedence/range matching (`^`, `~`) or QR Code Version 1 finder pattern, Reed-Solomon GF(256) ECC, and matrix/SVG/ASCII rendering. Concrete nominal inputs: `v: SemVer = SemVer(major = 1, minor = 1, patch = 1, prerelease = str = ""(), build = str = ""())`, `rangeStr: str = "aipl_test"`; exercises core body path returning/computing `satisfiesSemVer(v, rangeStr)`.

```aipl
module tests.functions.encoding.qrcode_semver_z25_test
import * from "std/encoding/qrcode_semver"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_qrcode_semver_satisfiesRange_25(): int:
  let arg_v = SemVer(major = 4, minor = 4, patch = 2, prerelease = "test", build = "test")
  let edge_v = SemVer(major = 1, minor = 1, patch = 0, prerelease = "a", build = "a")
  let arg_rangeStr = "test"
  let edge_rangeStr = "a"
  let resNom = satisfiesRange(arg_v, arg_rangeStr)
  let resEdge = satisfiesRange(edge_v, edge_rangeStr)
  assert(resNom == false, "satisfiesRange nominal resNom == false")
  assert(resEdge == false, "satisfiesRange boundary resEdge == false")
  ret 0
```

---

### `tomlStrVal` (`std/encoding/toml.aipl`)

- **Signature**: `fn tomlStrVal(s: str): TomlValue:`
- **Import**: `import * from "std/encoding/toml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `TomlValue`
- **Unit Test**: `tests/functions/encoding/toml_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `tomlStrVal` (`free fn`) TOML `[section]` table, inline `#` comment stripping, typed scalar/list parsing, and `TomlDocument` typed getters. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `TomlValue(kind = "string", strVal = s, intVal = 0, floatVal = 0.0, boolVal = false, listVal = emptyList, tableVal = emptyTable)`.

```aipl
module tests.functions.encoding.toml_z1_test
import * from "std/encoding/toml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_toml_tomlStrVal_1(): int:
  let arg_s = "a = 1"
  let edge_s = "a = 1"
  let resNom = tomlStrVal(arg_s)
  let resEdge = tomlStrVal(edge_s)
  assertEqStr(resNom.kind, "string", "tomlStrVal nominal string matches")
  assertEqStr(resEdge.kind, "string", "tomlStrVal boundary string matches")
  ret 0
```

---

### `tomlIntVal` (`std/encoding/toml.aipl`)

- **Signature**: `fn tomlIntVal(n: int): TomlValue:`
- **Import**: `import * from "std/encoding/toml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `n: int` | **Returns**: `TomlValue`
- **Unit Test**: `tests/functions/encoding/toml_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `tomlIntVal` (`free fn`) TOML `[section]` table, inline `#` comment stripping, typed scalar/list parsing, and `TomlDocument` typed getters. Concrete nominal inputs: `n: int = 1`; exercises core body path returning/computing `TomlValue(kind = "int", strVal = str(n), intVal = n, floatVal = float(n), boolVal = false, listVal = emptyList, tableVal = emptyTable)`.

```aipl
module tests.functions.encoding.toml_z2_test
import * from "std/encoding/toml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_toml_tomlIntVal_2(): int:
  let arg_n = 4
  let edge_n = 1
  let resNom = tomlIntVal(arg_n)
  let resEdge = tomlIntVal(edge_n)
  assertEqStr(resNom.kind, "int", "tomlIntVal nominal string matches")
  assertEqStr(resEdge.kind, "int", "tomlIntVal boundary string matches")
  ret 0
```

---

### `tomlFloatVal` (`std/encoding/toml.aipl`)

- **Signature**: `fn tomlFloatVal(f: float): TomlValue:`
- **Import**: `import * from "std/encoding/toml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `f: float` | **Returns**: `TomlValue`
- **Unit Test**: `tests/functions/encoding/toml_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `tomlFloatVal` (`free fn`) TOML `[section]` table, inline `#` comment stripping, typed scalar/list parsing, and `TomlDocument` typed getters. Concrete nominal inputs: `f: float = 1.0`; exercises core body path returning/computing `TomlValue(kind = "float", strVal = str(f), intVal = int(f), floatVal = f, boolVal = false, listVal = emptyList, tableVal = emptyTable)`.

```aipl
module tests.functions.encoding.toml_z3_test
import * from "std/encoding/toml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_toml_tomlFloatVal_3(): int:
  let arg_f = 1.0
  let edge_f = 0.5
  let resNom = tomlFloatVal(arg_f)
  let resEdge = tomlFloatVal(edge_f)
  assertEqStr(resNom.kind, "float", "tomlFloatVal nominal string matches")
  assertEqStr(resEdge.kind, "float", "tomlFloatVal boundary string matches")
  ret 0
```

---

### `tomlBoolVal` (`std/encoding/toml.aipl`)

- **Signature**: `fn tomlBoolVal(b: bool): TomlValue:`
- **Import**: `import * from "std/encoding/toml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `b: bool` | **Returns**: `TomlValue`
- **Unit Test**: `tests/functions/encoding/toml_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `tomlBoolVal` (`free fn`) TOML `[section]` table, inline `#` comment stripping, typed scalar/list parsing, and `TomlDocument` typed getters. Concrete nominal inputs: `b: bool = true`; exercises core body path returning/computing `TomlValue(kind = "bool", strVal = if b: "true" else: "false", intVal = if b: 1 else: 0, floatVal = if b: 1.0 else: 0.0, boolVal = b, listVal = emptyList, tableVal = emptyTable)`.

```aipl
module tests.functions.encoding.toml_z4_test
import * from "std/encoding/toml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_toml_tomlBoolVal_4(): int:
  let arg_b = true
  let edge_b = false
  let resNom = tomlBoolVal(arg_b)
  let resEdge = tomlBoolVal(edge_b)
  assertEqStr(resNom.kind, "bool", "tomlBoolVal nominal string matches")
  assertEqStr(resEdge.kind, "bool", "tomlBoolVal boundary string matches")
  ret 0
```

---

### `tomlListVal` (`std/encoding/toml.aipl`)

- **Signature**: `fn tomlListVal(items: [TomlValue]): TomlValue:`
- **Import**: `import * from "std/encoding/toml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `items: [TomlValue]` | **Returns**: `TomlValue`
- **Unit Test**: `tests/functions/encoding/toml_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `tomlListVal` (`free fn`) TOML `[section]` table, inline `#` comment stripping, typed scalar/list parsing, and `TomlDocument` typed getters. Concrete nominal inputs: `items: [TomlValue] = [TomlValue(kind = "aipl_test", strVal = "aipl_test", intVal = 1, floatVal = 1.0, boolVal = true, listVal = [0], tableVal = [0])]`; exercises core body path returning/computing `TomlValue(kind = "list", strVal = "", intVal = 0, floatVal = 0.0, boolVal = false, listVal = items, tableVal = emptyTable)`.

```aipl
module tests.functions.encoding.toml_z5_test
import * from "std/encoding/toml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_toml_tomlListVal_5(): int:
  let arg_items = [TomlValue(kind = "a = 1", strVal = "a = 1", intVal = 4, floatVal = 0.0, boolVal = true, listVal = [], tableVal = [])]
  let edge_items = []
  let resNom = tomlListVal(arg_items)
  let resEdge = tomlListVal(edge_items)
  assertEqStr(resNom.kind, "list", "tomlListVal nominal string matches")
  assertEqStr(resEdge.kind, "list", "tomlListVal boundary string matches")
  ret 0
```

---

### `stripTomlComment` (`std/encoding/toml.aipl`)

- **Signature**: `fn stripTomlComment(line: str): str:`
- **Import**: `import * from "std/encoding/toml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `line: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/toml_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `stripTomlComment` (`free fn`) TOML `[section]` table, inline `#` comment stripping, typed scalar/list parsing, and `TomlDocument` typed getters. Concrete nominal inputs: `line: str = "aipl_test"`; exercises core body path returning/computing `line.trim()`.

```aipl
module tests.functions.encoding.toml_z6_test
import * from "std/encoding/toml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_toml_stripTomlComment_6(): int:
  let arg_line = "a = 1"
  let edge_line = "a = 1"
  let resNom = stripTomlComment(arg_line)
  let resEdge = stripTomlComment(edge_line)
  assertEqStr(resNom, "a = 1", "stripTomlComment nominal string matches")
  assertEqStr(resEdge, "a = 1", "stripTomlComment boundary string matches")
  ret 0
```

---

### `parseTomlScalar` (`std/encoding/toml.aipl`)

- **Signature**: `fn parseTomlScalar(raw: str): TomlValue:`
- **Import**: `import * from "std/encoding/toml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `raw: str` | **Returns**: `TomlValue`
- **Unit Test**: `tests/functions/encoding/toml_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `parseTomlScalar` (`free fn`) TOML `[section]` table, inline `#` comment stripping, typed scalar/list parsing, and `TomlDocument` typed getters. Concrete nominal inputs: `raw: str = "aipl_test"`; exercises core body path returning/computing `tomlIntVal(int(cleanNum))`.

```aipl
module tests.functions.encoding.toml_z7_test
import * from "std/encoding/toml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_toml_parseTomlScalar_7(): int:
  let arg_raw = "a = 1"
  let edge_raw = "a = 1"
  let resNom = parseTomlScalar(arg_raw)
  let resEdge = parseTomlScalar(edge_raw)
  assertEqStr(resNom.kind, "int", "parseTomlScalar nominal string matches")
  assertEqStr(resEdge.kind, "int", "parseTomlScalar boundary string matches")
  ret 0
```

---

### `parseToml` (`std/encoding/toml.aipl`)

- **Signature**: `pub fn parseToml(text: str): Result[TomlDocument, str]:`
- **Import**: `import * from "std/encoding/toml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str` | **Returns**: `Result[TomlDocument, str]`
- **Unit Test**: `tests/functions/encoding/toml_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `parseToml` (`free fn`) TOML `[section]` table, inline `#` comment stripping, typed scalar/list parsing, and `TomlDocument` typed getters. Concrete nominal inputs: `text: str = "aipl_test"`; exercises core body path returning/computing `Ok(TomlDocument(rootTable = entries))`.

```aipl
module tests.functions.encoding.toml_z8_test
import * from "std/encoding/toml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_toml_parseToml_8(): int:
  let arg_text = "a = 1"
  let edge_text = "a = 1"
  let resNom = parseToml(arg_text)
  let resEdge = parseToml(edge_text)
  assert(resNom.isOk() == true, "parseToml nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "parseToml boundary resEdge.isOk() == true")
  ret 0
```

---

### `getString` (`std/encoding/toml.aipl`)

- **Signature**: `pub fn (self: TomlDocument) getString(key: str): Option[str]:`
- **Import**: `import * from "std/encoding/toml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `self: TomlDocument` | **Parameters**: `key: str` | **Returns**: `Option[str]`
- **Unit Test**: `tests/functions/encoding/toml_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `getString` (`self: TomlDocument`) TOML `[section]` table, inline `#` comment stripping, typed scalar/list parsing, and `TomlDocument` typed getters. Concrete nominal inputs: receiver `recvObj: TomlDocument = TomlDocument(rootTable = [(str, TomlValue)()])`, `key: str = "aipl_test"`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.encoding.toml_z9_test
import * from "std/encoding/toml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_toml_TomlDocument_getString_9(): int:
  let recv_self = TomlDocument(rootTable = [])
  let edge_self = TomlDocument(rootTable = [])
  let arg_key = "test"
  let edge_key = "a"
  let resNom = recv_self.getString(arg_key)
  let resEdge = edge_self.getString(edge_key)
  assert(resNom.isSome() == false, "getString nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "getString boundary resEdge.isSome() == false")
  ret 0
```

---

### `getInt` (`std/encoding/toml.aipl`)

- **Signature**: `pub fn (self: TomlDocument) getInt(key: str): Option[int]:`
- **Import**: `import * from "std/encoding/toml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `self: TomlDocument` | **Parameters**: `key: str` | **Returns**: `Option[int]`
- **Unit Test**: `tests/functions/encoding/toml_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `getInt` (`self: TomlDocument`) TOML `[section]` table, inline `#` comment stripping, typed scalar/list parsing, and `TomlDocument` typed getters. Concrete nominal inputs: receiver `recvObj: TomlDocument = TomlDocument(rootTable = [(str, TomlValue)()])`, `key: str = "aipl_test"`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.encoding.toml_z10_test
import * from "std/encoding/toml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_toml_TomlDocument_getInt_10(): int:
  let recv_self = TomlDocument(rootTable = [])
  let edge_self = TomlDocument(rootTable = [])
  let arg_key = "42"
  let edge_key = "0"
  let resNom = recv_self.getInt(arg_key)
  let resEdge = edge_self.getInt(edge_key)
  assert(resNom.isSome() == false, "getInt nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "getInt boundary resEdge.isSome() == false")
  ret 0
```

---

### `getBool` (`std/encoding/toml.aipl`)

- **Signature**: `pub fn (self: TomlDocument) getBool(key: str): Option[bool]:`
- **Import**: `import * from "std/encoding/toml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `self: TomlDocument` | **Parameters**: `key: str` | **Returns**: `Option[bool]`
- **Unit Test**: `tests/functions/encoding/toml_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `getBool` (`self: TomlDocument`) TOML `[section]` table, inline `#` comment stripping, typed scalar/list parsing, and `TomlDocument` typed getters. Concrete nominal inputs: receiver `recvObj: TomlDocument = TomlDocument(rootTable = [(str, TomlValue)()])`, `key: str = "aipl_test"`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.encoding.toml_z11_test
import * from "std/encoding/toml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_toml_TomlDocument_getBool_11(): int:
  let recv_self = TomlDocument(rootTable = [])
  let edge_self = TomlDocument(rootTable = [])
  let arg_key = "test"
  let edge_key = "a"
  let resNom = recv_self.getBool(arg_key)
  let resEdge = edge_self.getBool(edge_key)
  assert(resNom.isSome() == false, "getBool nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "getBool boundary resEdge.isSome() == false")
  ret 0
```

---

### `formatTomlValue` (`std/encoding/toml.aipl`)

- **Signature**: `fn formatTomlValue(v: TomlValue): str:`
- **Import**: `import * from "std/encoding/toml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: TomlValue` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/toml_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `formatTomlValue` (`free fn`) TOML `[section]` table, inline `#` comment stripping, typed scalar/list parsing, and `TomlDocument` typed getters. Concrete nominal inputs: `v: TomlValue = TomlValue(kind = "aipl_test", strVal = "aipl_test", intVal = 1, floatVal = 1.0, boolVal = true, listVal = [TomlValue(kind = 0, strVal = 0, intVal = 0, floatVal = 0, boolVal = 0, listVal = 0, tableVal = 0)], tableVal = [(str, TomlValue)()])`; exercises core body path returning/computing `"\"" + v.strVal + "\""`.

```aipl
module tests.functions.encoding.toml_z12_test
import * from "std/encoding/toml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_toml_formatTomlValue_12(): int:
  let arg_v = TomlValue(kind = "a = 1", strVal = "a = 1", intVal = 4, floatVal = 0.0, boolVal = true, listVal = [], tableVal = [])
  let edge_v = TomlValue(kind = "a = 1", strVal = "a = 1", intVal = 1, floatVal = 0.0, boolVal = false, listVal = [], tableVal = [])
  let resNom = formatTomlValue(arg_v)
  let resEdge = formatTomlValue(edge_v)
  assertEqInt(resNom.len(), 7, "formatTomlValue nominal string length == 7")
  assertEqInt(resEdge.len(), 7, "formatTomlValue boundary string length == 7")
  ret 0
```

---

### `serializeToml` (`std/encoding/toml.aipl`)

- **Signature**: `pub fn serializeToml(doc: TomlDocument): str:`
- **Import**: `import * from "std/encoding/toml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `doc: TomlDocument` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/toml_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `serializeToml` (`free fn`) TOML `[section]` table, inline `#` comment stripping, typed scalar/list parsing, and `TomlDocument` typed getters. Concrete nominal inputs: `doc: TomlDocument = TomlDocument(rootTable = [(str, TomlValue)()])`; exercises core body path returning/computing `lines.join("\n")`.

```aipl
module tests.functions.encoding.toml_z13_test
import * from "std/encoding/toml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_toml_serializeToml_13(): int:
  let arg_doc = TomlDocument(rootTable = [])
  let edge_doc = TomlDocument(rootTable = [])
  let resNom = serializeToml(arg_doc)
  let resEdge = serializeToml(edge_doc)
  assertEqStr(resNom, "", "serializeToml nominal string matches")
  assertEqStr(resEdge, "", "serializeToml boundary string matches")
  ret 0
```

---

### `tomlGetFloat` (`std/encoding/toml.aipl`)

- **Signature**: `pub fn tomlGetFloat(doc: TomlDocument, key: str): Option[float]:`
- **Import**: `import * from "std/encoding/toml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `doc: TomlDocument, key: str` | **Returns**: `Option[float]`
- **Unit Test**: `tests/functions/encoding/toml_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `tomlGetFloat` (`free fn`) TOML `[section]` table, inline `#` comment stripping, typed scalar/list parsing, and `TomlDocument` typed getters. Concrete nominal inputs: `doc: TomlDocument = TomlDocument(rootTable = [(str, TomlValue)()])`, `key: str = "aipl_test"`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.encoding.toml_z14_test
import * from "std/encoding/toml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_toml_tomlGetFloat_14(): int:
  let arg_doc = TomlDocument(rootTable = [])
  let edge_doc = TomlDocument(rootTable = [])
  let arg_key = "a = 1"
  let edge_key = "a = 1"
  let resNom = tomlGetFloat(arg_doc, arg_key)
  let resEdge = tomlGetFloat(edge_doc, edge_key)
  assert(resNom.isSome() == false, "tomlGetFloat nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "tomlGetFloat boundary resEdge.isSome() == false")
  ret 0
```

---

### `parseTomlSection` (`std/encoding/toml.aipl`)

- **Signature**: `pub fn parseTomlSection(src: str, section: str): Map[str, str]:`
- **Import**: `import * from "std/encoding/toml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `src: str, section: str` | **Returns**: `Map[str, str]`
- **Unit Test**: `tests/functions/encoding/toml_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `parseTomlSection` (`free fn`) TOML `[section]` table, inline `#` comment stripping, typed scalar/list parsing, and `TomlDocument` typed getters. Concrete nominal inputs: `src: str = "aipl_test"`, `section: str = "aipl_test"`; exercises core body path returning/computing `m`.

```aipl
module tests.functions.encoding.toml_z15_test
import * from "std/encoding/toml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_toml_parseTomlSection_15(): int:
  let arg_src = "a = 1"
  let edge_src = "a = 1"
  let arg_section = "a = 1"
  let edge_section = "a = 1"
  let resNom = parseTomlSection(arg_src, arg_section)
  let resEdge = parseTomlSection(edge_src, edge_section)
  assertEqInt(resNom.len(), 0, "parseTomlSection nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "parseTomlSection boundary resEdge.len() == 0")
  ret 0
```

---

### `parseTomlSections` (`std/encoding/toml.aipl`)

- **Signature**: `pub fn parseTomlSections(src: str): [str]:`
- **Import**: `import * from "std/encoding/toml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `src: str` | **Returns**: `[str]`
- **Unit Test**: `tests/functions/encoding/toml_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `parseTomlSections` (`free fn`) TOML `[section]` table, inline `#` comment stripping, typed scalar/list parsing, and `TomlDocument` typed getters. Concrete nominal inputs: `src: str = "aipl_test"`; exercises core body path returning/computing `sections`.

```aipl
module tests.functions.encoding.toml_z16_test
import * from "std/encoding/toml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_toml_parseTomlSections_16(): int:
  let arg_src = "a = 1"
  let edge_src = "a = 1"
  let resNom = parseTomlSections(arg_src)
  let resEdge = parseTomlSections(edge_src)
  assertEqInt(resNom.len(), 0, "parseTomlSections nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "parseTomlSections boundary resEdge.len() == 0")
  ret 0
```

---

### `getTomlValue` (`std/encoding/toml.aipl`)

- **Signature**: `pub fn getTomlValue(src: str, section: str, key: str, defaultVal: str): str:`
- **Import**: `import * from "std/encoding/toml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `src: str, section: str, key: str, defaultVal: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/toml_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `getTomlValue` (`free fn`) TOML `[section]` table, inline `#` comment stripping, typed scalar/list parsing, and `TomlDocument` typed getters. Concrete nominal inputs: `src: str = "aipl_test"`, `section: str = "aipl_test"`, `key: str = "aipl_test"`, `defaultVal: str = "aipl_test"`; exercises core body path returning/computing `defaultVal`.

```aipl
module tests.functions.encoding.toml_z17_test
import * from "std/encoding/toml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_toml_getTomlValue_17(): int:
  let arg_src = "a = 1"
  let edge_src = "a = 1"
  let arg_section = "a = 1"
  let edge_section = "a = 1"
  let arg_key = "a = 1"
  let edge_key = "a = 1"
  let arg_defaultVal = "a = 1"
  let edge_defaultVal = "a = 1"
  let resNom = getTomlValue(arg_src, arg_section, arg_key, arg_defaultVal)
  let resEdge = getTomlValue(edge_src, edge_section, edge_key, edge_defaultVal)
  assertEqStr(resNom, "a = 1", "getTomlValue nominal string matches")
  assertEqStr(resEdge, "a = 1", "getTomlValue boundary string matches")
  ret 0
```

---

### `toToml` (`std/encoding/toml.aipl`)

- **Signature**: `pub fn toToml(section: str, m: Map[str, str]): str:`
- **Import**: `import * from "std/encoding/toml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `section: str, m: Map[str, str]` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/toml_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `toToml` (`free fn`) TOML `[section]` table, inline `#` comment stripping, typed scalar/list parsing, and `TomlDocument` typed getters. Concrete nominal inputs: `section: str = "aipl_test"`, `m: Map[str, str] = Map()`; exercises core body path returning/computing `lines.join("\n")`.

```aipl
module tests.functions.encoding.toml_z18_test
import * from "std/encoding/toml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_toml_toToml_18(): int:
  let arg_section = "a = 1"
  let edge_section = "a = 1"
  let arg_m = {}
  let edge_m = {}
  let resNom = toToml(arg_section, arg_m)
  let resEdge = toToml(edge_section, edge_m)
  assertEqStr(resNom, "[a = 1]", "toToml nominal string matches")
  assertEqStr(resEdge, "[a = 1]", "toToml boundary string matches")
  ret 0
```

---

### `decodeXmlEntities` (`std/encoding/xml.aipl`)

- **Signature**: `pub fn decodeXmlEntities(s: str): str:`
- **Import**: `import * from "std/encoding/xml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/xml_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `decodeXmlEntities` (`free fn`) XML element/attribute tree parsing, entity escaping (`&lt;`, `&gt;`, `&amp;`, `&quot;`, `&apos;`), self-closing tags, `xmlFindAll`, and serialization. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `s.replace("&lt;", "<").replace("&gt;", ">").replace("&quot;", "\"").replace("&apos;", "'").replace("&amp;", "&")`.

```aipl
module tests.functions.encoding.xml_z1_test
import * from "std/encoding/xml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_xml_decodeXmlEntities_1(): int:
  let arg_s = "<r></r>"
  let edge_s = "<r></r>"
  let resNom = decodeXmlEntities(arg_s)
  let resEdge = decodeXmlEntities(edge_s)
  assertEqStr(resNom, "<r></r>", "decodeXmlEntities nominal string matches")
  assertEqStr(resEdge, "<r></r>", "decodeXmlEntities boundary string matches")
  ret 0
```

---

### `encodeXmlEntities` (`std/encoding/xml.aipl`)

- **Signature**: `pub fn encodeXmlEntities(s: str): str:`
- **Import**: `import * from "std/encoding/xml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/xml_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `encodeXmlEntities` (`free fn`) XML element/attribute tree parsing, entity escaping (`&lt;`, `&gt;`, `&amp;`, `&quot;`, `&apos;`), self-closing tags, `xmlFindAll`, and serialization. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `s.replace("&", "&amp;").replace("<", "&lt;").replace(">", "&gt;").replace("\"", "&quot;").replace("'", "&apos;")`.

```aipl
module tests.functions.encoding.xml_z2_test
import * from "std/encoding/xml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_xml_encodeXmlEntities_2(): int:
  let arg_s = "<r></r>"
  let edge_s = "<r></r>"
  let resNom = encodeXmlEntities(arg_s)
  let resEdge = encodeXmlEntities(edge_s)
  assertEqStr(resNom, "&lt;r&gt;&lt;/r&gt;", "encodeXmlEntities nominal string matches")
  assertEqStr(resEdge, "&lt;r&gt;&lt;/r&gt;", "encodeXmlEntities boundary string matches")
  ret 0
```

---

### `parseXmlAttributes` (`std/encoding/xml.aipl`)

- **Signature**: `fn parseXmlAttributes(header: str): [XmlAttribute]:`
- **Import**: `import * from "std/encoding/xml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `header: str` | **Returns**: `[XmlAttribute]`
- **Unit Test**: `tests/functions/encoding/xml_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `parseXmlAttributes` (`free fn`) XML element/attribute tree parsing, entity escaping (`&lt;`, `&gt;`, `&amp;`, `&quot;`, `&apos;`), self-closing tags, `xmlFindAll`, and serialization. Concrete nominal inputs: `header: str = "aipl_test"`; exercises core body path returning/computing `attrs`.

```aipl
module tests.functions.encoding.xml_z3_test
import * from "std/encoding/xml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_xml_parseXmlAttributes_3(): int:
  let arg_header = "<r></r>"
  let edge_header = "<r></r>"
  let resNom = parseXmlAttributes(arg_header)
  let resEdge = parseXmlAttributes(edge_header)
  assertEqInt(resNom.len(), 1, "parseXmlAttributes nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "parseXmlAttributes boundary resEdge.len() == 1")
  ret 0
```

---

### `parseXmlNodeAt` (`std/encoding/xml.aipl`)

- **Signature**: `fn parseXmlNodeAt(text: str, startPos: int): (int, XmlNode, str):`
- **Import**: `import * from "std/encoding/xml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str, startPos: int` | **Returns**: `(int, XmlNode, str)`
- **Unit Test**: `tests/functions/encoding/xml_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `parseXmlNodeAt` (`free fn`) XML element/attribute tree parsing, entity escaping (`&lt;`, `&gt;`, `&amp;`, `&quot;`, `&apos;`), self-closing tags, `xmlFindAll`, and serialization. Concrete nominal inputs: `text: str = "aipl_test"`, `startPos: int): (int = int): (int()`, `XmlNode: any = 42`, `str: any = 42`; exercises core body path returning/computing `(cur, XmlNode(tag = tagName, attributes = attrs, children = children, textContent = decodeXmlEntities(textParts.join("").trim()), isComment = false), "unclosed XML tag <" + tagName + ">")`.

```aipl
module tests.functions.encoding.xml_z4_test
import * from "std/encoding/xml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_xml_parseXmlNodeAt_4(): int:
  let arg_text = "<r></r>"
  let edge_text = "<r></r>"
  let arg_startPos = 1
  let edge_startPos = 0
  let resNom = parseXmlNodeAt(arg_text, arg_startPos)
  let resEdge = parseXmlNodeAt(edge_text, edge_startPos)
  let (n_t0, n_t1, n_t2) = resNom
  let (e_t0, e_t1, e_t2) = resEdge
  assertEqInt(n_t0, 1, "parseXmlNodeAt nominal n_t0 == 1")
  assertEqInt(e_t0, 7, "parseXmlNodeAt boundary e_t0 == 7")
  ret 0
```

---

### `parseXml` (`std/encoding/xml.aipl`)

- **Signature**: `pub fn parseXml(text: str): Result[XmlDocument, str]:`
- **Import**: `import * from "std/encoding/xml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str` | **Returns**: `Result[XmlDocument, str]`
- **Unit Test**: `tests/functions/encoding/xml_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `parseXml` (`free fn`) XML element/attribute tree parsing, entity escaping (`&lt;`, `&gt;`, `&amp;`, `&quot;`, `&apos;`), self-closing tags, `xmlFindAll`, and serialization. Concrete nominal inputs: `text: str = "aipl_test"`; exercises core body path returning/computing `Ok(XmlDocument(root = rootNode, declaration = decl, tag = rootNode.tag))`.

```aipl
module tests.functions.encoding.xml_z5_test
import * from "std/encoding/xml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_xml_parseXml_5(): int:
  let arg_text = "<r></r>"
  let edge_text = "<r></r>"
  let resNom = parseXml(arg_text)
  let resEdge = parseXml(edge_text)
  assert(resNom.isOk() == true, "parseXml nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "parseXml boundary resEdge.isOk() == true")
  ret 0
```

---

### `serializeXmlNode` (`std/encoding/xml.aipl`)

- **Signature**: `fn serializeXmlNode(node: XmlNode, pretty: bool, depth: int): str:`
- **Import**: `import * from "std/encoding/xml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `node: XmlNode, pretty: bool, depth: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/xml_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `serializeXmlNode` (`free fn`) XML element/attribute tree parsing, entity escaping (`&lt;`, `&gt;`, `&amp;`, `&quot;`, `&apos;`), self-closing tags, `xmlFindAll`, and serialization. Concrete nominal inputs: `node: XmlNode = XmlNode(tag = "aipl_test", attributes = [XmlAttribute(name = 0, value = 0)], children = [XmlNode(tag = 0, attributes = 0, children = 0, textContent = 0, isComment = 0)], textContent = "aipl_test", isComment = true)`, `pretty: bool = true`, `depth: int = 1`; exercises core body path returning/computing `openTag + childLines.join("") + closeTag`.

```aipl
module tests.functions.encoding.xml_z6_test
import * from "std/encoding/xml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_xml_serializeXmlNode_6(): int:
  let arg_node = XmlNode(tag = "<r></r>", attributes = [], children = [], textContent = "<r></r>", isComment = true)
  let edge_node = XmlNode(tag = "<r></r>", attributes = [], children = [], textContent = "<r></r>", isComment = false)
  let arg_pretty = true
  let edge_pretty = false
  let arg_depth = 4
  let edge_depth = 1
  let resNom = serializeXmlNode(arg_node, arg_pretty, arg_depth)
  let resEdge = serializeXmlNode(edge_node, edge_pretty, edge_depth)
  assertEqStr(resNom, "        <!--<r></r>-->", "serializeXmlNode nominal string matches")
  assertEqStr(resEdge, "<<r></r>>&lt;r&gt;&lt;/r&gt;</<r></r>>", "serializeXmlNode boundary string matches")
  ret 0
```

---

### `serializeXml` (`std/encoding/xml.aipl`)

- **Signature**: `pub fn serializeXml(doc: XmlDocument, pretty: bool = false): str:`
- **Import**: `import * from "std/encoding/xml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `doc: XmlDocument, pretty: bool = false` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/xml_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `serializeXml` (`free fn`) XML element/attribute tree parsing, entity escaping (`&lt;`, `&gt;`, `&amp;`, `&quot;`, `&apos;`), self-closing tags, `xmlFindAll`, and serialization. Concrete nominal inputs: `doc: XmlDocument = XmlDocument(root = XmlNode(tag = "aipl_test", attributes = [0], children = [0], textContent = "aipl_test", isComment = true), declaration = "aipl_test", tag = str = ""())`, `pretty: bool = true`; exercises core body path returning/computing `body`.

```aipl
module tests.functions.encoding.xml_z7_test
import * from "std/encoding/xml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_xml_serializeXml_7(): int:
  let arg_doc = XmlDocument(root = XmlNode(tag = "<r></r>", attributes = [], children = [], textContent = "<r></r>", isComment = true), declaration = "<r></r>", tag = "<r></r>")
  let edge_doc = XmlDocument(root = XmlNode(tag = "<r></r>", attributes = [], children = [], textContent = "<r></r>", isComment = false), declaration = "<r></r>", tag = "<r></r>")
  let arg_pretty = true
  let edge_pretty = false
  let resNom = serializeXml(arg_doc, arg_pretty)
  let resEdge = serializeXml(edge_doc, edge_pretty)
  assertEqInt(resNom.len(), 22, "serializeXml nominal string length == 22")
  assertEqStr(resEdge, "<r></r><<r></r>>&lt;r&gt;&lt;/r&gt;</<r></r>>", "serializeXml boundary string matches")
  ret 0
```

---

### `findChild` (`std/encoding/xml.aipl`)

- **Signature**: `pub fn (self: XmlNode) findChild(tag: str): Option[XmlNode]:`
- **Import**: `import * from "std/encoding/xml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `self: XmlNode` | **Parameters**: `tag: str` | **Returns**: `Option[XmlNode]`
- **Unit Test**: `tests/functions/encoding/xml_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `findChild` (`self: XmlNode`) XML element/attribute tree parsing, entity escaping (`&lt;`, `&gt;`, `&amp;`, `&quot;`, `&apos;`), self-closing tags, `xmlFindAll`, and serialization. Concrete nominal inputs: receiver `recvObj: XmlNode = XmlNode(tag = "aipl_test", attributes = [XmlAttribute(name = 0, value = 0)], children = [XmlNode(tag = 0, attributes = 0, children = 0, textContent = 0, isComment = 0)], textContent = "aipl_test", isComment = true)`, `tag: str = "aipl_test"`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.encoding.xml_z8_test
import * from "std/encoding/xml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_xml_XmlNode_findChild_8(): int:
  let recv_self = XmlNode(tag = "test", attributes = [], children = [], textContent = "test", isComment = true)
  let edge_self = XmlNode(tag = "a", attributes = [], children = [], textContent = "a", isComment = false)
  let arg_tag = "test"
  let edge_tag = "a"
  let resNom = recv_self.findChild(arg_tag)
  let resEdge = edge_self.findChild(edge_tag)
  assert(resNom.isSome() == false, "findChild nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "findChild boundary resEdge.isSome() == false")
  ret 0
```

---

### `getAttr` (`std/encoding/xml.aipl`)

- **Signature**: `pub fn (self: XmlNode) getAttr(name: str): Option[str]:`
- **Import**: `import * from "std/encoding/xml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `self: XmlNode` | **Parameters**: `name: str` | **Returns**: `Option[str]`
- **Unit Test**: `tests/functions/encoding/xml_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `getAttr` (`self: XmlNode`) XML element/attribute tree parsing, entity escaping (`&lt;`, `&gt;`, `&amp;`, `&quot;`, `&apos;`), self-closing tags, `xmlFindAll`, and serialization. Concrete nominal inputs: receiver `recvObj: XmlNode = XmlNode(tag = "aipl_test", attributes = [XmlAttribute(name = 0, value = 0)], children = [XmlNode(tag = 0, attributes = 0, children = 0, textContent = 0, isComment = 0)], textContent = "aipl_test", isComment = true)`, `name: str = "aipl_test"`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.encoding.xml_z9_test
import * from "std/encoding/xml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_xml_XmlNode_getAttr_9(): int:
  let recv_self = XmlNode(tag = "test", attributes = [], children = [], textContent = "test", isComment = true)
  let edge_self = XmlNode(tag = "a", attributes = [], children = [], textContent = "a", isComment = false)
  let arg_name = "test"
  let edge_name = "a"
  let resNom = recv_self.getAttr(arg_name)
  let resEdge = edge_self.getAttr(edge_name)
  assert(resNom.isSome() == false, "getAttr nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "getAttr boundary resEdge.isSome() == false")
  ret 0
```

---

### `escapeXml` (`std/encoding/xml.aipl`)

- **Signature**: `pub fn escapeXml(s: str): str:`
- **Import**: `import * from "std/encoding/xml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/xml_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `escapeXml` (`free fn`) XML element/attribute tree parsing, entity escaping (`&lt;`, `&gt;`, `&amp;`, `&quot;`, `&apos;`), self-closing tags, `xmlFindAll`, and serialization. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `encodeXmlEntities(s)`.

```aipl
module tests.functions.encoding.xml_z10_test
import * from "std/encoding/xml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_xml_escapeXml_10(): int:
  let arg_s = "<r></r>"
  let edge_s = "<r></r>"
  let resNom = escapeXml(arg_s)
  let resEdge = escapeXml(edge_s)
  assertEqStr(resNom, "&lt;r&gt;&lt;/r&gt;", "escapeXml nominal string matches")
  assertEqStr(resEdge, "&lt;r&gt;&lt;/r&gt;", "escapeXml boundary string matches")
  ret 0
```

---

### `unescapeXml` (`std/encoding/xml.aipl`)

- **Signature**: `pub fn unescapeXml(s: str): str:`
- **Import**: `import * from "std/encoding/xml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/xml_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `unescapeXml` (`free fn`) XML element/attribute tree parsing, entity escaping (`&lt;`, `&gt;`, `&amp;`, `&quot;`, `&apos;`), self-closing tags, `xmlFindAll`, and serialization. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `decodeXmlEntities(s)`.

```aipl
module tests.functions.encoding.xml_z11_test
import * from "std/encoding/xml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_xml_unescapeXml_11(): int:
  let arg_s = "<r></r>"
  let edge_s = "<r></r>"
  let resNom = unescapeXml(arg_s)
  let resEdge = unescapeXml(edge_s)
  assertEqStr(resNom, "<r></r>", "unescapeXml nominal string matches")
  assertEqStr(resEdge, "<r></r>", "unescapeXml boundary string matches")
  ret 0
```

---

### `collectXmlElements` (`std/encoding/xml.aipl`)

- **Signature**: `fn collectXmlElements(node: XmlNode, tagName: str, mut acc: [XmlNode]): [XmlNode]:`
- **Import**: `import * from "std/encoding/xml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `node: XmlNode, tagName: str, mut acc: [XmlNode]` | **Returns**: `[XmlNode]`
- **Unit Test**: `tests/functions/encoding/xml_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `collectXmlElements` (`free fn`) XML element/attribute tree parsing, entity escaping (`&lt;`, `&gt;`, `&amp;`, `&quot;`, `&apos;`), self-closing tags, `xmlFindAll`, and serialization. Concrete nominal inputs: `node: XmlNode = XmlNode(tag = "aipl_test", attributes = [XmlAttribute(name = 0, value = 0)], children = [XmlNode(tag = 0, attributes = 0, children = 0, textContent = 0, isComment = 0)], textContent = "aipl_test", isComment = true)`, `tagName: str = "aipl_test"`, `acc: [XmlNode] = [XmlNode(tag = "aipl_test", attributes = [0], children = [0], textContent = "aipl_test", isComment = true)]`; exercises core body path returning/computing `acc`.

```aipl
module tests.functions.encoding.xml_z12_test
import * from "std/encoding/xml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_xml_collectXmlElements_12(): int:
  let arg_node = XmlNode(tag = "<r></r>", attributes = [], children = [], textContent = "<r></r>", isComment = true)
  let edge_node = XmlNode(tag = "<r></r>", attributes = [], children = [], textContent = "<r></r>", isComment = false)
  let arg_tagName = "<r></r>"
  let edge_tagName = "<r></r>"
  let arg_acc = [XmlNode(tag = "<r></r>", attributes = [], children = [], textContent = "<r></r>", isComment = true)]
  let edge_acc = []
  let resNom = collectXmlElements(arg_node, arg_tagName, arg_acc)
  let resEdge = collectXmlElements(edge_node, edge_tagName, edge_acc)
  assertEqInt(resNom.len(), 1, "collectXmlElements nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "collectXmlElements boundary resEdge.len() == 1")
  ret 0
```

---

### `xmlFindElements` (`std/encoding/xml.aipl`)

- **Signature**: `pub fn xmlFindElements(node: XmlNode, tagName: str): [XmlNode]:`
- **Import**: `import * from "std/encoding/xml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `node: XmlNode, tagName: str` | **Returns**: `[XmlNode]`
- **Unit Test**: `tests/functions/encoding/xml_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `xmlFindElements` (`free fn`) XML element/attribute tree parsing, entity escaping (`&lt;`, `&gt;`, `&amp;`, `&quot;`, `&apos;`), self-closing tags, `xmlFindAll`, and serialization. Concrete nominal inputs: `node: XmlNode = XmlNode(tag = "aipl_test", attributes = [XmlAttribute(name = 0, value = 0)], children = [XmlNode(tag = 0, attributes = 0, children = 0, textContent = 0, isComment = 0)], textContent = "aipl_test", isComment = true)`, `tagName: str = "aipl_test"`; exercises core body path returning/computing `collectXmlElements(node, tagName, acc)`.

```aipl
module tests.functions.encoding.xml_z13_test
import * from "std/encoding/xml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_xml_xmlFindElements_13(): int:
  let arg_node = XmlNode(tag = "<r></r>", attributes = [], children = [], textContent = "<r></r>", isComment = true)
  let edge_node = XmlNode(tag = "<r></r>", attributes = [], children = [], textContent = "<r></r>", isComment = false)
  let arg_tagName = "<r></r>"
  let edge_tagName = "<r></r>"
  let resNom = xmlFindElements(arg_node, arg_tagName)
  let resEdge = xmlFindElements(edge_node, edge_tagName)
  assertEqInt(resNom.len(), 0, "xmlFindElements nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 1, "xmlFindElements boundary resEdge.len() == 1")
  ret 0
```

---

### `xmlFindAll` (`std/encoding/xml.aipl`)

- **Signature**: `pub fn xmlFindAll(doc: XmlDocument, tagName: str): [XmlNode]:`
- **Import**: `import * from "std/encoding/xml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `doc: XmlDocument, tagName: str` | **Returns**: `[XmlNode]`
- **Unit Test**: `tests/functions/encoding/xml_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `xmlFindAll` (`free fn`) XML element/attribute tree parsing, entity escaping (`&lt;`, `&gt;`, `&amp;`, `&quot;`, `&apos;`), self-closing tags, `xmlFindAll`, and serialization. Concrete nominal inputs: `doc: XmlDocument = XmlDocument(root = XmlNode(tag = "aipl_test", attributes = [0], children = [0], textContent = "aipl_test", isComment = true), declaration = "aipl_test", tag = str = ""())`, `tagName: str = "aipl_test"`; exercises core body path returning/computing `xmlFindElements(doc.root, tagName)`.

```aipl
module tests.functions.encoding.xml_z14_test
import * from "std/encoding/xml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_xml_xmlFindAll_14(): int:
  let arg_doc = XmlDocument(root = XmlNode(tag = "<r></r>", attributes = [], children = [], textContent = "<r></r>", isComment = true), declaration = "<r></r>", tag = "<r></r>")
  let edge_doc = XmlDocument(root = XmlNode(tag = "<r></r>", attributes = [], children = [], textContent = "<r></r>", isComment = false), declaration = "<r></r>", tag = "<r></r>")
  let arg_tagName = "<r></r>"
  let edge_tagName = "<r></r>"
  let resNom = xmlFindAll(arg_doc, arg_tagName)
  let resEdge = xmlFindAll(edge_doc, edge_tagName)
  assertEqInt(resNom.len(), 0, "xmlFindAll nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 1, "xmlFindAll boundary resEdge.len() == 1")
  ret 0
```

---

### `xmlText` (`std/encoding/xml.aipl`)

- **Signature**: `pub fn xmlText(node: XmlNode): str:`
- **Import**: `import * from "std/encoding/xml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `node: XmlNode` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/xml_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `xmlText` (`free fn`) XML element/attribute tree parsing, entity escaping (`&lt;`, `&gt;`, `&amp;`, `&quot;`, `&apos;`), self-closing tags, `xmlFindAll`, and serialization. Concrete nominal inputs: `node: XmlNode = XmlNode(tag = "aipl_test", attributes = [XmlAttribute(name = 0, value = 0)], children = [XmlNode(tag = 0, attributes = 0, children = 0, textContent = 0, isComment = 0)], textContent = "aipl_test", isComment = true)`; exercises core body path returning/computing `parts.join(" ").trim()`.

```aipl
module tests.functions.encoding.xml_z15_test
import * from "std/encoding/xml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_xml_xmlText_15(): int:
  let arg_node = XmlNode(tag = "<r></r>", attributes = [], children = [], textContent = "<r></r>", isComment = true)
  let edge_node = XmlNode(tag = "<r></r>", attributes = [], children = [], textContent = "<r></r>", isComment = false)
  let resNom = xmlText(arg_node)
  let resEdge = xmlText(edge_node)
  assertEqStr(resNom, "<r></r>", "xmlText nominal string matches")
  assertEqStr(resEdge, "<r></r>", "xmlText boundary string matches")
  ret 0
```

---

### `xmlAttr` (`std/encoding/xml.aipl`)

- **Signature**: `pub fn xmlAttr(node: XmlNode, name: str): Option[str]:`
- **Import**: `import * from "std/encoding/xml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `node: XmlNode, name: str` | **Returns**: `Option[str]`
- **Unit Test**: `tests/functions/encoding/xml_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `xmlAttr` (`free fn`) XML element/attribute tree parsing, entity escaping (`&lt;`, `&gt;`, `&amp;`, `&quot;`, `&apos;`), self-closing tags, `xmlFindAll`, and serialization. Concrete nominal inputs: `node: XmlNode = XmlNode(tag = "aipl_test", attributes = [XmlAttribute(name = 0, value = 0)], children = [XmlNode(tag = 0, attributes = 0, children = 0, textContent = 0, isComment = 0)], textContent = "aipl_test", isComment = true)`, `name: str = "aipl_test"`; exercises core body path returning/computing `node.getAttr(name)`.

```aipl
module tests.functions.encoding.xml_z16_test
import * from "std/encoding/xml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_xml_xmlAttr_16(): int:
  let arg_node = XmlNode(tag = "<r></r>", attributes = [], children = [], textContent = "<r></r>", isComment = true)
  let edge_node = XmlNode(tag = "<r></r>", attributes = [], children = [], textContent = "<r></r>", isComment = false)
  let arg_name = "<r></r>"
  let edge_name = "<r></r>"
  let resNom = xmlAttr(arg_node, arg_name)
  let resEdge = xmlAttr(edge_node, edge_name)
  assert(resNom.isSome() == false, "xmlAttr nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "xmlAttr boundary resEdge.isSome() == false")
  ret 0
```

---

### `formatXml` (`std/encoding/xml.aipl`)

- **Signature**: `pub fn formatXml(doc: XmlDocument): str:`
- **Import**: `import * from "std/encoding/xml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `doc: XmlDocument` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/xml_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `formatXml` (`free fn`) XML element/attribute tree parsing, entity escaping (`&lt;`, `&gt;`, `&amp;`, `&quot;`, `&apos;`), self-closing tags, `xmlFindAll`, and serialization. Concrete nominal inputs: `doc: XmlDocument = XmlDocument(root = XmlNode(tag = "aipl_test", attributes = [0], children = [0], textContent = "aipl_test", isComment = true), declaration = "aipl_test", tag = str = ""())`; exercises core body path returning/computing `serializeXml(doc, true)`.

```aipl
module tests.functions.encoding.xml_z17_test
import * from "std/encoding/xml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_xml_formatXml_17(): int:
  let arg_doc = XmlDocument(root = XmlNode(tag = "<r></r>", attributes = [], children = [], textContent = "<r></r>", isComment = true), declaration = "<r></r>", tag = "<r></r>")
  let edge_doc = XmlDocument(root = XmlNode(tag = "<r></r>", attributes = [], children = [], textContent = "<r></r>", isComment = false), declaration = "<r></r>", tag = "<r></r>")
  let resNom = formatXml(arg_doc)
  let resEdge = formatXml(edge_doc)
  assertEqInt(resNom.len(), 22, "formatXml nominal string length == 22")
  assertEqInt(resEdge.len(), 46, "formatXml boundary string length == 46")
  ret 0
```

---

### `stringifyXml` (`std/encoding/xml.aipl`)

- **Signature**: `pub fn stringifyXml(doc: XmlDocument): str:`
- **Import**: `import * from "std/encoding/xml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `doc: XmlDocument` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/xml_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `stringifyXml` (`free fn`) XML element/attribute tree parsing, entity escaping (`&lt;`, `&gt;`, `&amp;`, `&quot;`, `&apos;`), self-closing tags, `xmlFindAll`, and serialization. Concrete nominal inputs: `doc: XmlDocument = XmlDocument(root = XmlNode(tag = "aipl_test", attributes = [0], children = [0], textContent = "aipl_test", isComment = true), declaration = "aipl_test", tag = str = ""())`; exercises core body path returning/computing `serializeXml(doc, false)`.

```aipl
module tests.functions.encoding.xml_z18_test
import * from "std/encoding/xml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_xml_stringifyXml_18(): int:
  let arg_doc = XmlDocument(root = XmlNode(tag = "<r></r>", attributes = [], children = [], textContent = "<r></r>", isComment = true), declaration = "<r></r>", tag = "<r></r>")
  let edge_doc = XmlDocument(root = XmlNode(tag = "<r></r>", attributes = [], children = [], textContent = "<r></r>", isComment = false), declaration = "<r></r>", tag = "<r></r>")
  let resNom = stringifyXml(arg_doc)
  let resEdge = stringifyXml(edge_doc)
  assertEqStr(resNom, "<r></r><!--<r></r>-->", "stringifyXml nominal string matches")
  assertEqStr(resEdge, "<r></r><<r></r>>&lt;r&gt;&lt;/r&gt;</<r></r>>", "stringifyXml boundary string matches")
  ret 0
```

---

### `toXml` (`std/encoding/xml.aipl`)

- **Signature**: `pub fn toXml(doc: XmlDocument): str:`
- **Import**: `import * from "std/encoding/xml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `doc: XmlDocument` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/xml_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `toXml` (`free fn`) XML element/attribute tree parsing, entity escaping (`&lt;`, `&gt;`, `&amp;`, `&quot;`, `&apos;`), self-closing tags, `xmlFindAll`, and serialization. Concrete nominal inputs: `doc: XmlDocument = XmlDocument(root = XmlNode(tag = "aipl_test", attributes = [0], children = [0], textContent = "aipl_test", isComment = true), declaration = "aipl_test", tag = str = ""())`; exercises core body path returning/computing `serializeXml(doc, false)`.

```aipl
module tests.functions.encoding.xml_z19_test
import * from "std/encoding/xml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_xml_toXml_19(): int:
  let arg_doc = XmlDocument(root = XmlNode(tag = "<r></r>", attributes = [], children = [], textContent = "<r></r>", isComment = true), declaration = "<r></r>", tag = "<r></r>")
  let edge_doc = XmlDocument(root = XmlNode(tag = "<r></r>", attributes = [], children = [], textContent = "<r></r>", isComment = false), declaration = "<r></r>", tag = "<r></r>")
  let resNom = toXml(arg_doc)
  let resEdge = toXml(edge_doc)
  assertEqStr(resNom, "<r></r><!--<r></r>-->", "toXml nominal string matches")
  assertEqStr(resEdge, "<r></r><<r></r>>&lt;r&gt;&lt;/r&gt;</<r></r>>", "toXml boundary string matches")
  ret 0
```

---

### `yamlScalar` (`std/encoding/yaml.aipl`)

- **Signature**: `fn yamlScalar(s: str): YamlNode:`
- **Import**: `import * from "std/encoding/yaml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `YamlNode`
- **Unit Test**: `tests/functions/encoding/yaml_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `yamlScalar` indented YAML mapping/sequence parsing, scalar unquoting, depth-indented serialization, and `yamlToJson` cross-conversion. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `YamlNode(kind = "scalar", scalar = s, sequence = emptySeq, mapping = emptyMap)`.

```aipl
module tests.functions.encoding.yaml_z1_test
import * from "std/encoding/yaml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_yaml_yamlScalar_1(): int:
  let arg_s = "a: 1"
  let edge_s = "a: 1"
  let resNom = yamlScalar(arg_s)
  let resEdge = yamlScalar(edge_s)
  assertEqStr(resNom.kind, "scalar", "yamlScalar nominal string matches")
  assertEqStr(resEdge.kind, "scalar", "yamlScalar boundary string matches")
  ret 0
```

---

### `yamlSequence` (`std/encoding/yaml.aipl`)

- **Signature**: `fn yamlSequence(items: [YamlNode]): YamlNode:`
- **Import**: `import * from "std/encoding/yaml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `items: [YamlNode]` | **Returns**: `YamlNode`
- **Unit Test**: `tests/functions/encoding/yaml_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `yamlSequence` indented YAML mapping/sequence parsing, scalar unquoting, depth-indented serialization, and `yamlToJson` cross-conversion. Concrete nominal inputs: `items: [YamlNode] = [YamlNode(kind = "aipl_test", scalar = "aipl_test", sequence = [0], mapping = [0])]`; exercises core body path returning/computing `YamlNode(kind = "sequence", scalar = "", sequence = items, mapping = emptyMap)`.

```aipl
module tests.functions.encoding.yaml_z2_test
import * from "std/encoding/yaml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_yaml_yamlSequence_2(): int:
  let arg_items = [YamlNode(kind = "a: 1", scalar = "a: 1", sequence = [], mapping = [])]
  let edge_items = []
  let resNom = yamlSequence(arg_items)
  let resEdge = yamlSequence(edge_items)
  assertEqStr(resNom.kind, "sequence", "yamlSequence nominal string matches")
  assertEqStr(resEdge.kind, "sequence", "yamlSequence boundary string matches")
  ret 0
```

---

### `yamlMapping` (`std/encoding/yaml.aipl`)

- **Signature**: `fn yamlMapping(entries: [(str, YamlNode)]): YamlNode:`
- **Import**: `import * from "std/encoding/yaml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `entries: [(str, YamlNode)]` | **Returns**: `YamlNode`
- **Unit Test**: `tests/functions/encoding/yaml_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `yamlMapping` indented YAML mapping/sequence parsing, scalar unquoting, depth-indented serialization, and `yamlToJson` cross-conversion. Concrete nominal inputs: `entries: [(str, YamlNode)] = [(str, YamlNode)()]`; exercises core body path returning/computing `YamlNode(kind = "mapping", scalar = "", sequence = emptySeq, mapping = entries)`.

```aipl
module tests.functions.encoding.yaml_z3_test
import * from "std/encoding/yaml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_yaml_yamlMapping_3(): int:
  let arg_entries = [("a: 1", YamlNode(kind = "a: 1", scalar = "a: 1", sequence = [], mapping = []))]
  let edge_entries = []
  let resNom = yamlMapping(arg_entries)
  let resEdge = yamlMapping(edge_entries)
  assertEqStr(resNom.kind, "mapping", "yamlMapping nominal string matches")
  assertEqStr(resEdge.kind, "mapping", "yamlMapping boundary string matches")
  ret 0
```

---

### `countLeadingSpaces` (`std/encoding/yaml.aipl`)

- **Signature**: `fn countLeadingSpaces(line: str): int:`
- **Import**: `import * from "std/encoding/yaml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `line: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/encoding/yaml_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `countLeadingSpaces` indented YAML mapping/sequence parsing, scalar unquoting, depth-indented serialization, and `yamlToJson` cross-conversion. Concrete nominal inputs: `line: str = "aipl_test"`; exercises core body path returning/computing `n`.

```aipl
module tests.functions.encoding.yaml_z4_test
import * from "std/encoding/yaml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_yaml_countLeadingSpaces_4(): int:
  let arg_line = "test"
  let edge_line = "a"
  let resNom = countLeadingSpaces(arg_line)
  let resEdge = countLeadingSpaces(edge_line)
  assertEqInt(resNom, 0, "countLeadingSpaces nominal resNom == 0")
  assertEqInt(resEdge, 0, "countLeadingSpaces boundary resEdge == 0")
  ret 0
```

---

### `cleanYamlScalarText` (`std/encoding/yaml.aipl`)

- **Signature**: `fn cleanYamlScalarText(raw: str): str:`
- **Import**: `import * from "std/encoding/yaml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `raw: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/yaml_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `cleanYamlScalarText` indented YAML mapping/sequence parsing, scalar unquoting, depth-indented serialization, and `yamlToJson` cross-conversion. Concrete nominal inputs: `raw: str = "aipl_test"`; exercises core body path returning/computing `t`.

```aipl
module tests.functions.encoding.yaml_z5_test
import * from "std/encoding/yaml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_yaml_cleanYamlScalarText_5(): int:
  let arg_raw = "a: 1"
  let edge_raw = "a: 1"
  let resNom = cleanYamlScalarText(arg_raw)
  let resEdge = cleanYamlScalarText(edge_raw)
  assertEqStr(resNom, "a: 1", "cleanYamlScalarText nominal string matches")
  assertEqStr(resEdge, "a: 1", "cleanYamlScalarText boundary string matches")
  ret 0
```

---

### `parseYamlLines` (`std/encoding/yaml.aipl`)

- **Signature**: `fn parseYamlLines(lines: [str], startIdx: int, minIndent: int): (int, YamlNode):`
- **Import**: `import * from "std/encoding/yaml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `lines: [str], startIdx: int, minIndent: int` | **Returns**: `(int, YamlNode)`
- **Unit Test**: `tests/functions/encoding/yaml_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `parseYamlLines` indented YAML mapping/sequence parsing, scalar unquoting, depth-indented serialization, and `yamlToJson` cross-conversion. Concrete nominal inputs: `lines: [str] = ["aipl_test"]`, `startIdx: int = 0`, `minIndent: int): (int = int): (int()`, `YamlNode: any = 42`; exercises core body path returning/computing `(idx, yamlMapping(entries))`.

```aipl
module tests.functions.encoding.yaml_z6_test
import * from "std/encoding/yaml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_yaml_parseYamlLines_6(): int:
  let arg_lines = ["a: 1"]
  let edge_lines = []
  let arg_startIdx = 1
  let edge_startIdx = 0
  let arg_minIndent = 4
  let edge_minIndent = 1
  let resNom = parseYamlLines(arg_lines, arg_startIdx, arg_minIndent)
  let resEdge = parseYamlLines(edge_lines, edge_startIdx, edge_minIndent)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqInt(n_t0, 1, "parseYamlLines nominal n_t0 == 1")
  assertEqInt(e_t0, 0, "parseYamlLines boundary e_t0 == 0")
  ret 0
```

---

### `parseYaml` (`std/encoding/yaml.aipl`)

- **Signature**: `pub fn parseYaml(text: str): Result[YamlNode, str]:`
- **Import**: `import * from "std/encoding/yaml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str` | **Returns**: `Result[YamlNode, str]`
- **Unit Test**: `tests/functions/encoding/yaml_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `parseYaml` indented YAML mapping/sequence parsing, scalar unquoting, depth-indented serialization, and `yamlToJson` cross-conversion. Concrete nominal inputs: `text: str = "aipl_test"`; exercises core body path returning/computing `Ok(root)`.

```aipl
module tests.functions.encoding.yaml_z7_test
import * from "std/encoding/yaml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_yaml_parseYaml_7(): int:
  let arg_text = "a: 1"
  let edge_text = "a: 1"
  let resNom = parseYaml(arg_text)
  let resEdge = parseYaml(edge_text)
  assert(resNom.isOk() == true, "parseYaml nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "parseYaml boundary resEdge.isOk() == true")
  ret 0
```

---

### `makeYamlPad` (`std/encoding/yaml.aipl`)

- **Signature**: `fn makeYamlPad(spaces: int): str:`
- **Import**: `import * from "std/encoding/yaml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `spaces: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/yaml_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `makeYamlPad` indented YAML mapping/sequence parsing, scalar unquoting, depth-indented serialization, and `yamlToJson` cross-conversion. Concrete nominal inputs: `spaces: int = 1`; exercises core body path returning/computing `out.join("")`.

```aipl
module tests.functions.encoding.yaml_z8_test
import * from "std/encoding/yaml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_yaml_makeYamlPad_8(): int:
  let arg_spaces = 2
  let edge_spaces = 0
  let resNom = makeYamlPad(arg_spaces)
  let resEdge = makeYamlPad(edge_spaces)
  assertEqStr(resNom, "  ", "makeYamlPad nominal string matches")
  assertEqStr(resEdge, "", "makeYamlPad boundary string matches")
  ret 0
```

---

### `serializeYamlDepth` (`std/encoding/yaml.aipl`)

- **Signature**: `fn serializeYamlDepth(node: YamlNode, indentStep: int, depth: int): str:`
- **Import**: `import * from "std/encoding/yaml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `node: YamlNode, indentStep: int, depth: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/yaml_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `serializeYamlDepth` indented YAML mapping/sequence parsing, scalar unquoting, depth-indented serialization, and `yamlToJson` cross-conversion. Concrete nominal inputs: `node: YamlNode = YamlNode(kind = "aipl_test", scalar = "aipl_test", sequence = [YamlNode(kind = 0, scalar = 0, sequence = 0, mapping = 0)], mapping = [(str, YamlNode)()])`, `indentStep: int = 1`, `depth: int = 1`; exercises core body path returning/computing `""`.

```aipl
module tests.functions.encoding.yaml_z9_test
import * from "std/encoding/yaml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_yaml_serializeYamlDepth_9(): int:
  let arg_node = YamlNode(kind = "a: 1", scalar = "a: 1", sequence = [], mapping = [])
  let edge_node = YamlNode(kind = "a: 1", scalar = "a: 1", sequence = [], mapping = [])
  let arg_indentStep = 4
  let edge_indentStep = 1
  let arg_depth = 4
  let edge_depth = 1
  let resNom = serializeYamlDepth(arg_node, arg_indentStep, arg_depth)
  let resEdge = serializeYamlDepth(edge_node, edge_indentStep, edge_depth)
  assertEqStr(resNom, "", "serializeYamlDepth nominal string matches")
  assertEqStr(resEdge, "", "serializeYamlDepth boundary string matches")
  ret 0
```

---

### `serializeYaml` (`std/encoding/yaml.aipl`)

- **Signature**: `pub fn serializeYaml(node: YamlNode, indent: int = 2): str:`
- **Import**: `import * from "std/encoding/yaml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `node: YamlNode, indent: int = 2` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/yaml_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `serializeYaml` indented YAML mapping/sequence parsing, scalar unquoting, depth-indented serialization, and `yamlToJson` cross-conversion. Concrete nominal inputs: `node: YamlNode = YamlNode(kind = "aipl_test", scalar = "aipl_test", sequence = [YamlNode(kind = 0, scalar = 0, sequence = 0, mapping = 0)], mapping = [(str, YamlNode)()])`, `indent: int = 1`; exercises core body path returning/computing `serializeYamlDepth(node, step, 0)`.

```aipl
module tests.functions.encoding.yaml_z10_test
import * from "std/encoding/yaml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_yaml_serializeYaml_10(): int:
  let arg_node = YamlNode(kind = "a: 1", scalar = "a: 1", sequence = [], mapping = [])
  let edge_node = YamlNode(kind = "a: 1", scalar = "a: 1", sequence = [], mapping = [])
  let arg_indent = 4
  let edge_indent = 1
  let resNom = serializeYaml(arg_node, arg_indent)
  let resEdge = serializeYaml(edge_node, edge_indent)
  assertEqStr(resNom, "", "serializeYaml nominal string matches")
  assertEqStr(resEdge, "", "serializeYaml boundary string matches")
  ret 0
```

---

### `parseYamlEntries` (`std/encoding/yaml.aipl`)

- **Signature**: `pub fn parseYamlEntries(src: str): [YamlEntry]:`
- **Import**: `import * from "std/encoding/yaml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `src: str` | **Returns**: `[YamlEntry]`
- **Unit Test**: `tests/functions/encoding/yaml_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `parseYamlEntries` indented YAML mapping/sequence parsing, scalar unquoting, depth-indented serialization, and `yamlToJson` cross-conversion. Concrete nominal inputs: `src: str = "aipl_test"`; exercises core body path returning/computing `entries`.

```aipl
module tests.functions.encoding.yaml_z11_test
import * from "std/encoding/yaml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_yaml_parseYamlEntries_11(): int:
  let arg_src = "a: 1"
  let edge_src = "a: 1"
  let resNom = parseYamlEntries(arg_src)
  let resEdge = parseYamlEntries(edge_src)
  assertEqInt(resNom.len(), 1, "parseYamlEntries nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "parseYamlEntries boundary resEdge.len() == 1")
  ret 0
```

---

### `parseYamlMap` (`std/encoding/yaml.aipl`)

- **Signature**: `pub fn parseYamlMap(src: str): Map[str, str]:`
- **Import**: `import * from "std/encoding/yaml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `src: str` | **Returns**: `Map[str, str]`
- **Unit Test**: `tests/functions/encoding/yaml_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `parseYamlMap` indented YAML mapping/sequence parsing, scalar unquoting, depth-indented serialization, and `yamlToJson` cross-conversion. Concrete nominal inputs: `src: str = "aipl_test"`; exercises core body path returning/computing `m`.

```aipl
module tests.functions.encoding.yaml_z12_test
import * from "std/encoding/yaml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_yaml_parseYamlMap_12(): int:
  let arg_src = "a: 1"
  let edge_src = "a: 1"
  let resNom = parseYamlMap(arg_src)
  let resEdge = parseYamlMap(edge_src)
  assertEqInt(resNom.len(), 1, "parseYamlMap nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "parseYamlMap boundary resEdge.len() == 1")
  ret 0
```

---

### `getYamlValue` (`std/encoding/yaml.aipl`)

- **Signature**: `pub fn getYamlValue(src: str, key: str, defaultVal: str): str:`
- **Import**: `import * from "std/encoding/yaml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `src: str, key: str, defaultVal: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/yaml_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `getYamlValue` indented YAML mapping/sequence parsing, scalar unquoting, depth-indented serialization, and `yamlToJson` cross-conversion. Concrete nominal inputs: `src: str = "aipl_test"`, `key: str = "aipl_test"`, `defaultVal: str = "aipl_test"`; exercises core body path returning/computing `defaultVal`.

```aipl
module tests.functions.encoding.yaml_z13_test
import * from "std/encoding/yaml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_yaml_getYamlValue_13(): int:
  let arg_src = "a: 1"
  let edge_src = "a: 1"
  let arg_key = "a: 1"
  let edge_key = "a: 1"
  let arg_defaultVal = "a: 1"
  let edge_defaultVal = "a: 1"
  let resNom = getYamlValue(arg_src, arg_key, arg_defaultVal)
  let resEdge = getYamlValue(edge_src, edge_key, edge_defaultVal)
  assertEqStr(resNom, "a: 1", "getYamlValue nominal string matches")
  assertEqStr(resEdge, "a: 1", "getYamlValue boundary string matches")
  ret 0
```

---

### `parseYamlList` (`std/encoding/yaml.aipl`)

- **Signature**: `pub fn parseYamlList(src: str): [str]:`
- **Import**: `import * from "std/encoding/yaml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `src: str` | **Returns**: `[str]`
- **Unit Test**: `tests/functions/encoding/yaml_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `parseYamlList` indented YAML mapping/sequence parsing, scalar unquoting, depth-indented serialization, and `yamlToJson` cross-conversion. Concrete nominal inputs: `src: str = "aipl_test"`; exercises core body path returning/computing `items`.

```aipl
module tests.functions.encoding.yaml_z14_test
import * from "std/encoding/yaml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_yaml_parseYamlList_14(): int:
  let arg_src = "a: 1"
  let edge_src = "a: 1"
  let resNom = parseYamlList(arg_src)
  let resEdge = parseYamlList(edge_src)
  assertEqInt(resNom.len(), 0, "parseYamlList nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "parseYamlList boundary resEdge.len() == 0")
  ret 0
```

---

### `toYamlMap` (`std/encoding/yaml.aipl`)

- **Signature**: `pub fn toYamlMap(m: Map[str, str]): str:`
- **Import**: `import * from "std/encoding/yaml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `m: Map[str, str]` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/yaml_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `toYamlMap` indented YAML mapping/sequence parsing, scalar unquoting, depth-indented serialization, and `yamlToJson` cross-conversion. Concrete nominal inputs: `m: Map[str, str] = Map()`; exercises core body path returning/computing `lines.join("\n")`.

```aipl
module tests.functions.encoding.yaml_z15_test
import * from "std/encoding/yaml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_yaml_toYamlMap_15(): int:
  let arg_m = {}
  let edge_m = {}
  let resNom = toYamlMap(arg_m)
  let resEdge = toYamlMap(edge_m)
  assertEqStr(resNom, "", "toYamlMap nominal string matches")
  assertEqStr(resEdge, "", "toYamlMap boundary string matches")
  ret 0
```

---

### `toYamlList` (`std/encoding/yaml.aipl`)

- **Signature**: `pub fn toYamlList(items: [str]): str:`
- **Import**: `import * from "std/encoding/yaml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `items: [str]` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/yaml_test.aipl` | **Example**: `examples/ex_070_encoding_json_jq_query_cli.aipl`
- **Behavioral Summary**: Verify `toYamlList` indented YAML mapping/sequence parsing, scalar unquoting, depth-indented serialization, and `yamlToJson` cross-conversion. Concrete nominal inputs: `items: [str] = ["aipl_test"]`; exercises core body path returning/computing `lines.join("\n")`.

```aipl
module tests.functions.encoding.yaml_z16_test
import * from "std/encoding/yaml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_yaml_toYamlList_16(): int:
  let arg_items = ["a: 1"]
  let edge_items = []
  let resNom = toYamlList(arg_items)
  let resEdge = toYamlList(edge_items)
  assertEqStr(resNom, "- a: 1", "toYamlList nominal string matches")
  assertEqStr(resEdge, "", "toYamlList boundary string matches")
  ret 0
```

---

### `yamlNodeToJsonStr` (`std/encoding/yaml.aipl`)

- **Signature**: `fn yamlNodeToJsonStr(node: YamlNode): str:`
- **Import**: `import * from "std/encoding/yaml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `node: YamlNode` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/yaml_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Verify `yamlNodeToJsonStr` indented YAML mapping/sequence parsing, scalar unquoting, depth-indented serialization, and `yamlToJson` cross-conversion. Concrete nominal inputs: `node: YamlNode = YamlNode(kind = "aipl_test", scalar = "aipl_test", sequence = [YamlNode(kind = 0, scalar = 0, sequence = 0, mapping = 0)], mapping = [(str, YamlNode)()])`; exercises core body path returning/computing `"null"`.

```aipl
module tests.functions.encoding.yaml_z17_test
import * from "std/encoding/yaml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_yaml_yamlNodeToJsonStr_17(): int:
  let arg_node = YamlNode(kind = "{\"a\":1}", scalar = "{\"a\":1}", sequence = [], mapping = [])
  let edge_node = YamlNode(kind = "{}", scalar = "{}", sequence = [], mapping = [])
  let resNom = yamlNodeToJsonStr(arg_node)
  let resEdge = yamlNodeToJsonStr(edge_node)
  assertEqStr(resNom, "null", "yamlNodeToJsonStr nominal string matches")
  assertEqStr(resEdge, "null", "yamlNodeToJsonStr boundary string matches")
  ret 0
```

---

### `yamlToJson` (`std/encoding/yaml.aipl`)

- **Signature**: `pub fn yamlToJson(src: str): str:`
- **Import**: `import * from "std/encoding/yaml"` (or barrel `import * from "std/encoding/encoding_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `src: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/encoding/yaml_test.aipl` | **Example**: `examples/ex_069_time_frame_pacer_hud_window.aipl`
- **Behavioral Summary**: Verify `yamlToJson` indented YAML mapping/sequence parsing, scalar unquoting, depth-indented serialization, and `yamlToJson` cross-conversion. Concrete nominal inputs: `src: str = "aipl_test"`; exercises core body path returning/computing `yamlNodeToJsonStr(res.unwrap())`.

```aipl
module tests.functions.encoding.yaml_z18_test
import * from "std/encoding/yaml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_yaml_yamlToJson_18(): int:
  let arg_src = "{\"a\":1}"
  let edge_src = "{}"
  let resNom = yamlToJson(arg_src)
  let resEdge = yamlToJson(edge_src)
  assertEqInt(resNom.len(), 15, "yamlToJson nominal string length == 15")
  assertEqInt(resEdge.len(), 4, "yamlToJson boundary string length == 4")
  ret 0
```

---

### `patchAxmlPackageName` (`std/encoding/axml_manifest.aipl`)

- **Signature**: `pub fn patchAxmlPackageName(rawPackageId: str): Result[(str, int), str] requires rawPackageId.len() >= 0 ensures rawPackageId.len() > 0 or result.isErr():`
- **Import**: `import { patchAxmlPackageName } from "std/encoding/axml_manifest"`
- **Receiver**: `None (free function)` | **Parameters**: `rawPackageId: str` | **Returns**: `Result[(str, int), str]`
- **Unit Test**: `tests/functions/encoding/axml_manifest_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Validates an Android application package identifier (requiring dot-separated domain parts without spaces) and calculates the required 4-byte aligned UTF-16LE string pool byte length.

```aipl
module tests.functions.encoding.axml_ref_01_test
import { patchAxmlPackageName } from "std/encoding/axml_manifest"
import { assert, assertEqInt, assertEqStr } from "std/prelude"
pub fn test_patchAxmlPackageName_ref(): int:
  let res = patchAxmlPackageName("com.aipl.app.neon_grid")
  assert(res.isOk() == true, "valid package ID accepted")
  let (pkg, poolBytes) = res.unwrap()
  assertEqStr(pkg, "com.aipl.app.neon_grid", "package matches")
  assertEqInt(poolBytes % 4, 0, "pool size is 4-byte aligned")
  ret 0
```

---

### `patchAxmlAppLabel` (`std/encoding/axml_manifest.aipl`)

- **Signature**: `pub fn patchAxmlAppLabel(baseAxmlSizeBytes: int, oldLabel: str, newLabel: str): (str, int) requires baseAxmlSizeBytes >= 64 ensures result[0].len() > 0 and result[1] >= 64:`
- **Import**: `import { patchAxmlAppLabel } from "std/encoding/axml_manifest"`
- **Receiver**: `None (free function)` | **Parameters**: `baseAxmlSizeBytes: int, oldLabel: str, newLabel: str` | **Returns**: `(str, int)`
- **Unit Test**: `tests/functions/encoding/axml_manifest_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Computes updated binary `AndroidManifest.xml` chunk size after replacing `android:label` with a new UTF-16LE string pool entry, ensuring 4-byte alignment and clamping minimum size to 64 bytes.

```aipl
module tests.functions.encoding.axml_ref_02_test
import { patchAxmlAppLabel } from "std/encoding/axml_manifest"
import { assert, assertEqStr } from "std/prelude"
pub fn test_patchAxmlAppLabel_ref(): int:
  let (label, newSize) = patchAxmlAppLabel(2048, "OldApp", "NewAiplApp")
  assertEqStr(label, "NewAiplApp", "app label updated")
  assert(newSize >= 64, "chunk size satisfies invariant")
  ret 0
```

---

### `patchAxmlVersionCode` (`std/encoding/axml_manifest.aipl`)

- **Signature**: `pub fn patchAxmlVersionCode(versionCode: int, versionName: str): (int, str, [int]) requires versionName.len() >= 0 ensures result[0] >= 1 and result[1].len() > 0 and result[2].len() == 4:`
- **Import**: `import { patchAxmlVersionCode } from "std/encoding/axml_manifest"`
- **Receiver**: `None (free function)` | **Parameters**: `versionCode: int, versionName: str` | **Returns**: `(int, str, [int])`
- **Unit Test**: `tests/functions/encoding/axml_manifest_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Formats Android `versionCode` and `versionName`, returning the clamped integer version code (>= 1), non-empty name string, and 4-byte little-endian binary encoding for direct binary manifest injection.

```aipl
module tests.functions.encoding.axml_ref_03_test
import { patchAxmlVersionCode } from "std/encoding/axml_manifest"
import { assertEqInt, assertEqStr } from "std/prelude"
pub fn test_patchAxmlVersionCode_ref(): int:
  let (code, name, le) = patchAxmlVersionCode(102, "1.2.0")
  assertEqInt(code, 102, "version code matches")
  assertEqStr(name, "1.2.0", "version name matches")
  assertEqInt(le.len(), 4, "little endian length == 4")
  ret 0
```

---

### `patchAxmlScreenOrientation` (`std/encoding/axml_manifest.aipl`)

- **Signature**: `pub fn patchAxmlScreenOrientation(orientationMode: str): int requires orientationMode.len() >= 0 ensures result == 0 or result == 1 or result == 4 or result == 6:`
- **Import**: `import { patchAxmlScreenOrientation, SCREEN_ORIENTATION_LANDSCAPE, SCREEN_ORIENTATION_PORTRAIT } from "std/encoding/axml_manifest"`
- **Receiver**: `None (free function)` | **Parameters**: `orientationMode: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/encoding/axml_manifest_test.aipl` | **Example**: `examples/ex_071_encoding_toml_manifest_cli.aipl`
- **Behavioral Summary**: Resolves human-readable screen orientation configuration (`"landscape"`, `"portrait"`, `"sensorlandscape"`, `"sensor"`) to the canonical Android `android:screenOrientation` attribute integer constant.

```aipl
module tests.functions.encoding.axml_ref_04_test
import { patchAxmlScreenOrientation, SCREEN_ORIENTATION_LANDSCAPE, SCREEN_ORIENTATION_PORTRAIT } from "std/encoding/axml_manifest"
import { assertEqInt } from "std/prelude"
pub fn test_patchAxmlScreenOrientation_ref(): int:
  let land = patchAxmlScreenOrientation("landscape")
  let port = patchAxmlScreenOrientation("portrait")
  assertEqInt(land, SCREEN_ORIENTATION_LANDSCAPE, "landscape orientation == 0")
  assertEqInt(port, SCREEN_ORIENTATION_PORTRAIT, "portrait orientation == 1")
  ret 0
```
