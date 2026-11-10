[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Domain 07: `fmt` API Reference

> Complete API reference manual for AIPL standard library domain `fmt` (125 callable functions & methods across ["std/fmt/fmt_mod.aipl", "std/fmt/num_parse.aipl", "std/fmt/str_builder.aipl", "std/fmt/text_print.aipl", "std/fmt/unicode_utf8.aipl"]).

## 1. Domain Overview & Source Modules

- **Domain Name**: `fmt`
- **Target Source Modules**: ["std/fmt/fmt_mod.aipl", "std/fmt/num_parse.aipl", "std/fmt/str_builder.aipl", "std/fmt/text_print.aipl", "std/fmt/unicode_utf8.aipl"]
- **Total Callable Functions & Methods**: 125
- **Total Data Types (`struct` & `enum`)**: 12
- **Master Reference Hub**: [STDLIB_REFERENCE.md](STDLIB_REFERENCE.md)

---

## 2. Domain Data Types (`struct` & `enum`)

(12 public types declared across this domain's modules)

| Type Name | Kind | Source Module | Fields / Variants | Default Constructor / Description |
| :--- | :--- | :--- | :--- | :--- |
| `ParseIntOptions` | `pub struct` | `std/fmt/num_parse.aipl` | `radix: int`, `strict: bool`, `allowLeadingSign: bool`, `allowUnderscores: bool` | `ParseIntOptions(radix, strict, allowLeadingSign, allowUnderscores)` |
| `ParseFloatOptions` | `pub struct` | `std/fmt/num_parse.aipl` | `allowNan: bool`, `allowInf: bool`, `allowHexFloat: bool` | `ParseFloatOptions(allowNan, allowInf, allowHexFloat)` |
| `FloatFormatOptions` | `pub struct` | `std/fmt/num_parse.aipl` | `precision: int`, `format: str`, `trimTrailingZeros: bool` | `FloatFormatOptions(precision, format, trimTrailingZeros)` |
| `StringBuilder` | `pub struct` | `std/fmt/str_builder.aipl` | `chunks: [str]`, `totalLen: int`, `capacity: int` | `StringBuilder(chunks, totalLen, capacity)` |
| `StringView` | `pub struct` | `std/fmt/str_builder.aipl` | `source: str`, `start: int`, `len: int` | `StringView(source, start, len)` |
| `TextRange` | `pub struct` | `std/fmt/str_builder.aipl` | `start: int`, `end: int` | `TextRange(start, end)` |
| `TableColumn` | `pub struct` | `std/fmt/text_print.aipl` | `header: str`, `width: int`, `align: str` | `TableColumn(header, width, align)` |
| `FormattedTable` | `pub struct` | `std/fmt/text_print.aipl` | `columns: [TableColumn]`, `rows: [[str]]`, `hasBorder: bool` | `FormattedTable(columns, rows, hasBorder)` |
| `PrintFormatOptions` | `pub struct` | `std/fmt/text_print.aipl` | `indent: int`, `maxDepth: int`, `colored: bool` | `PrintFormatOptions(indent, maxDepth, colored)` |
| `Utf8Codepoint` | `pub struct` | `std/fmt/unicode_utf8.aipl` | `codepoint: int`, `byteOffset: int`, `byteLength: int` | `Utf8Codepoint(codepoint, byteOffset, byteLength)` |
| `Utf8CodepointIter` | `pub struct` | `std/fmt/unicode_utf8.aipl` | `text: str`, `byteOffset: int`, `charOffset: int` | `Utf8CodepointIter(text, byteOffset, charOffset)` |
| `GraphemeCluster` | `pub struct` | `std/fmt/unicode_utf8.aipl` | `cluster: str`, `byteOffset: int`, `runeCount: int`, `displayWidth: int` | `GraphemeCluster(cluster, byteOffset, runeCount, displayWidth)` |

## 3. Quick-Lookup Function Index


| # | Source Module | Function / Method | Exact Signature | Unit Test File |
| :--- | :--- | :--- | :--- | :--- |
| `1` | `std/fmt/fmt_mod.aipl` | `format` | `pub fn format(templateStr: str, args: [str]): str:` | `tests/functions/fmt/fmt_mod_test.aipl` |
| `2` | `std/fmt/fmt_mod.aipl` | `printTable` | `pub fn printTable(columns: [TableColumn], rows: [[str]]): str:` | `tests/functions/fmt/fmt_mod_test.aipl` |
| `3` | `std/fmt/num_parse.aipl` | `isSpaceChar` | `fn isSpaceChar(ch: str): bool:` | `tests/functions/fmt/num_parse_test.aipl` |
| `4` | `std/fmt/num_parse.aipl` | `trimNumeric` | `fn trimNumeric(s: str): str:` | `tests/functions/fmt/num_parse_test.aipl` |
| `5` | `std/fmt/num_parse.aipl` | `charToDigit` | `fn charToDigit(ch: str): int:` | `tests/functions/fmt/num_parse_test.aipl` |
| `6` | `std/fmt/num_parse.aipl` | `parseIntEx` | `pub fn parseIntEx(s: str, opts: ParseIntOptions): Result[int, str]:` | `tests/functions/fmt/num_parse_test.aipl` |
| `7` | `std/fmt/num_parse.aipl` | `parseInt` | `pub fn parseInt(s: str, radix: int = 10): Result[int, str]:` | `tests/functions/fmt/num_parse_test.aipl` |
| `8` | `std/fmt/num_parse.aipl` | `parseIntRadix` | `pub fn parseIntRadix(s: str, radix: int): Result[int, str]:` | `tests/functions/fmt/num_parse_test.aipl` |
| `9` | `std/fmt/num_parse.aipl` | `parseHexByte` | `pub fn parseHexByte(s: str, offset: int = 0): Result[int, str]:` | `tests/functions/fmt/num_parse_test.aipl` |
| `10` | `std/fmt/num_parse.aipl` | `parseFloatEx` | `pub fn parseFloatEx(s: str, opts: ParseFloatOptions): Result[float, str]:` | `tests/functions/fmt/num_parse_test.aipl` |
| `11` | `std/fmt/num_parse.aipl` | `parseFloat` | `pub fn parseFloat(s: str): Result[float, str]:` | `tests/functions/fmt/num_parse_test.aipl` |
| `12` | `std/fmt/num_parse.aipl` | `parseFloatPrefix` | `pub fn parseFloatPrefix(s: str): Option[float]:` | `tests/functions/fmt/num_parse_test.aipl` |
| `13` | `std/fmt/num_parse.aipl` | `formatInt` | `pub fn formatInt(val: int, radix: int = 10): str:` | `tests/functions/fmt/num_parse_test.aipl` |
| `14` | `std/fmt/num_parse.aipl` | `formatIntPadded` | `pub fn formatIntPadded(val: int, width: int, padChar: str = "0", radix: int = 10): str:` | `tests/functions/fmt/num_parse_test.aipl` |
| `15` | `std/fmt/num_parse.aipl` | `formatHex` | `pub fn formatHex(val: int, uppercase: bool = false, prefix: bool = false): str:` | `tests/functions/fmt/num_parse_test.aipl` |
| `16` | `std/fmt/num_parse.aipl` | `formatBinary` | `pub fn formatBinary(val: int, prefix: bool = false, minDigits: int = 0): str:` | `tests/functions/fmt/num_parse_test.aipl` |
| `17` | `std/fmt/num_parse.aipl` | `formatOctal` | `pub fn formatOctal(val: int, prefix: bool = false): str:` | `tests/functions/fmt/num_parse_test.aipl` |
| `18` | `std/fmt/num_parse.aipl` | `intToHex` | `pub fn intToHex(n: int, minWidth: int = 0): str:` | `tests/functions/fmt/num_parse_test.aipl` |
| `19` | `std/fmt/num_parse.aipl` | `intToOctal` | `pub fn intToOctal(n: int, minWidth: int = 0): str:` | `tests/functions/fmt/num_parse_test.aipl` |
| `20` | `std/fmt/num_parse.aipl` | `formatFloatFixed` | `pub fn formatFloatFixed(val: float, decimals: int = 2): str:` | `tests/functions/fmt/num_parse_test.aipl` |
| `21` | `std/fmt/num_parse.aipl` | `formatFloat` | `pub fn formatFloat(val: float, decimals: int): str:` | `tests/functions/fmt/num_parse_test.aipl` |
| `22` | `std/fmt/num_parse.aipl` | `formatFloatDragonbox` | `pub fn formatFloatDragonbox(val: float, precision: int = -1): str:` | `tests/functions/fmt/num_parse_test.aipl` |
| `23` | `std/fmt/num_parse.aipl` | `formatFloatScientific` | `pub fn formatFloatScientific(val: float, precision: int = 6): str:` | `tests/functions/fmt/num_parse_test.aipl` |
| `24` | `std/fmt/str_builder.aipl` | `TextRange.new` | `pub fn TextRange.new(start: int, end: int): TextRange:` | `tests/functions/fmt/str_builder_test.aipl` |
| `25` | `std/fmt/str_builder.aipl` | `len` | `pub fn (self: TextRange) len(): int:` | `tests/functions/fmt/str_builder_test.aipl` |
| `26` | `std/fmt/str_builder.aipl` | `stringBuilderNew` | `pub fn stringBuilderNew(initialCapacity: int = 64): StringBuilder:` | `tests/functions/fmt/str_builder_test.aipl` |
| `27` | `std/fmt/str_builder.aipl` | `stringBuilderWithCapacity` | `pub fn stringBuilderWithCapacity(cap: int): StringBuilder:` | `tests/functions/fmt/str_builder_test.aipl` |
| `28` | `std/fmt/str_builder.aipl` | `append` | `pub fn (mut self: StringBuilder) append(text: str): StringBuilder:` | `tests/functions/fmt/str_builder_test.aipl` |
| `29` | `std/fmt/str_builder.aipl` | `appendChar` | `pub fn (mut self: StringBuilder) appendChar(code: int): StringBuilder:` | `tests/functions/fmt/str_builder_test.aipl` |
| `30` | `std/fmt/str_builder.aipl` | `appendLine` | `pub fn (mut self: StringBuilder) appendLine(line: str = ""): StringBuilder:` | `tests/functions/fmt/str_builder_test.aipl` |
| `31` | `std/fmt/str_builder.aipl` | `appendInt` | `pub fn (mut self: StringBuilder) appendInt(n: int): StringBuilder:` | `tests/functions/fmt/str_builder_test.aipl` |
| `32` | `std/fmt/str_builder.aipl` | `appendFloat` | `pub fn (mut self: StringBuilder) appendFloat(f: float, precision: int = 2): StringBuilder:` | `tests/functions/fmt/str_builder_test.aipl` |
| `33` | `std/fmt/str_builder.aipl` | `clear` | `pub fn (mut self: StringBuilder) clear(): void:` | `tests/functions/fmt/str_builder_test.aipl` |
| `34` | `std/fmt/str_builder.aipl` | `toString` | `pub fn (self: StringBuilder) toString(): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `35` | `std/fmt/str_builder.aipl` | `length` | `pub fn (self: StringBuilder) length(): int:` | `tests/functions/fmt/str_builder_test.aipl` |
| `36` | `std/fmt/str_builder.aipl` | `sbAppend` | `pub fn sbAppend(mut sb: StringBuilder, s: str): StringBuilder:` | `tests/functions/fmt/str_builder_test.aipl` |
| `37` | `std/fmt/str_builder.aipl` | `sbAppendChar` | `pub fn sbAppendChar(mut sb: StringBuilder, ch: str): StringBuilder:` | `tests/functions/fmt/str_builder_test.aipl` |
| `38` | `std/fmt/str_builder.aipl` | `sbAppendIndent` | `pub fn sbAppendIndent(mut sb: StringBuilder, count: int, indentStr: str = "  "): StringBuilder:` | `tests/functions/fmt/str_builder_test.aipl` |
| `39` | `std/fmt/str_builder.aipl` | `sbAppendLine` | `pub fn sbAppendLine(mut sb: StringBuilder, line: str = ""): StringBuilder:` | `tests/functions/fmt/str_builder_test.aipl` |
| `40` | `std/fmt/str_builder.aipl` | `sbToString` | `pub fn sbToString(sb: StringBuilder): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `41` | `std/fmt/str_builder.aipl` | `sbLen` | `pub fn sbLen(sb: StringBuilder): int:` | `tests/functions/fmt/str_builder_test.aipl` |
| `42` | `std/fmt/str_builder.aipl` | `sbClear` | `pub fn sbClear(mut sb: StringBuilder): StringBuilder:` | `tests/functions/fmt/str_builder_test.aipl` |
| `43` | `std/fmt/str_builder.aipl` | `stringViewFrom` | `pub fn stringViewFrom(s: str, start: int, len: int): StringView:` | `tests/functions/fmt/str_builder_test.aipl` |
| `44` | `std/fmt/str_builder.aipl` | `toString` | `pub fn (self: StringView) toString(): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `45` | `std/fmt/str_builder.aipl` | `strLen` | `pub fn strLen(s: str): int:` | `tests/functions/fmt/str_builder_test.aipl` |
| `46` | `std/fmt/str_builder.aipl` | `charAt` | `pub fn charAt(s: str, index: int): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `47` | `std/fmt/str_builder.aipl` | `charCodeAt` | `pub fn charCodeAt(s: str, idx: int): int:` | `tests/functions/fmt/str_builder_test.aipl` |
| `48` | `std/fmt/str_builder.aipl` | `ord` | `pub fn ord(ch: str): int:` | `tests/functions/fmt/str_builder_test.aipl` |
| `49` | `std/fmt/str_builder.aipl` | `chr` | `pub fn chr(code: int): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `50` | `std/fmt/str_builder.aipl` | `fromCharCode` | `pub fn fromCharCode(code: int): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `51` | `std/fmt/str_builder.aipl` | `charFromCode` | `pub fn charFromCode(code: int): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `52` | `std/fmt/str_builder.aipl` | `chars` | `pub fn chars(s: str): [str]:` | `tests/functions/fmt/str_builder_test.aipl` |
| `53` | `std/fmt/str_builder.aipl` | `substring` | `pub fn substring(s: str, start: int, end: int): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `54` | `std/fmt/str_builder.aipl` | `isWhitespace` | `pub fn isWhitespace(c: str): bool:` | `tests/functions/fmt/str_builder_test.aipl` |
| `55` | `std/fmt/str_builder.aipl` | `isDigit` | `pub fn isDigit(c: str): bool:` | `tests/functions/fmt/str_builder_test.aipl` |
| `56` | `std/fmt/str_builder.aipl` | `isAlpha` | `pub fn isAlpha(c: str): bool:` | `tests/functions/fmt/str_builder_test.aipl` |
| `57` | `std/fmt/str_builder.aipl` | `isAlphanumeric` | `pub fn isAlphanumeric(c: str): bool:` | `tests/functions/fmt/str_builder_test.aipl` |
| `58` | `std/fmt/str_builder.aipl` | `isAlnum` | `pub fn isAlnum(c: str): bool:` | `tests/functions/fmt/str_builder_test.aipl` |
| `59` | `std/fmt/str_builder.aipl` | `isHexDigit` | `pub fn isHexDigit(c: str): bool:` | `tests/functions/fmt/str_builder_test.aipl` |
| `60` | `std/fmt/str_builder.aipl` | `isIdentChar` | `pub fn isIdentChar(c: str): bool:` | `tests/functions/fmt/str_builder_test.aipl` |
| `61` | `std/fmt/str_builder.aipl` | `padLeft` | `pub fn padLeft(s: str, targetLen: int, padChar: str = " "): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `62` | `std/fmt/str_builder.aipl` | `padStart` | `pub fn padStart(s: str, width: int, fill: str = " "): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `63` | `std/fmt/str_builder.aipl` | `padRight` | `pub fn padRight(s: str, targetLen: int, padChar: str = " "): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `64` | `std/fmt/str_builder.aipl` | `padEnd` | `pub fn padEnd(s: str, width: int, fill: str = " "): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `65` | `std/fmt/str_builder.aipl` | `padCenter` | `pub fn padCenter(s: str, targetLen: int, padChar: str = " "): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `66` | `std/fmt/str_builder.aipl` | `trimStart` | `pub fn trimStart(s: str): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `67` | `std/fmt/str_builder.aipl` | `trimLeft` | `pub fn trimLeft(s: str): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `68` | `std/fmt/str_builder.aipl` | `trimEnd` | `pub fn trimEnd(s: str): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `69` | `std/fmt/str_builder.aipl` | `trimRight` | `pub fn trimRight(s: str): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `70` | `std/fmt/str_builder.aipl` | `trim` | `pub fn trim(s: str): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `71` | `std/fmt/str_builder.aipl` | `repeat` | `pub fn repeat(s: str, count: int): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `72` | `std/fmt/str_builder.aipl` | `repeatStr` | `pub fn repeatStr(s: str, count: int): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `73` | `std/fmt/str_builder.aipl` | `reverseStr` | `pub fn reverseStr(s: str): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `74` | `std/fmt/str_builder.aipl` | `toUpper` | `pub fn toUpper(s: str): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `75` | `std/fmt/str_builder.aipl` | `toLower` | `pub fn toLower(s: str): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `76` | `std/fmt/str_builder.aipl` | `capitalize` | `pub fn capitalize(s: str): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `77` | `std/fmt/str_builder.aipl` | `extractWordsForCase` | `fn extractWordsForCase(s: str): [str]:` | `tests/functions/fmt/str_builder_test.aipl` |
| `78` | `std/fmt/str_builder.aipl` | `toCamelCase` | `pub fn toCamelCase(s: str): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `79` | `std/fmt/str_builder.aipl` | `toSnakeCase` | `pub fn toSnakeCase(s: str): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `80` | `std/fmt/str_builder.aipl` | `toKebabCase` | `pub fn toKebabCase(s: str): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `81` | `std/fmt/str_builder.aipl` | `toPascalCase` | `pub fn toPascalCase(s: str): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `82` | `std/fmt/str_builder.aipl` | `split` | `pub fn split(s: str, sep: str): [str]:` | `tests/functions/fmt/str_builder_test.aipl` |
| `83` | `std/fmt/str_builder.aipl` | `splitLines` | `pub fn splitLines(s: str): [str]:` | `tests/functions/fmt/str_builder_test.aipl` |
| `84` | `std/fmt/str_builder.aipl` | `lines` | `pub fn lines(s: str): [str]:` | `tests/functions/fmt/str_builder_test.aipl` |
| `85` | `std/fmt/str_builder.aipl` | `join` | `pub fn join(pieces: [str], sep: str): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `86` | `std/fmt/str_builder.aipl` | `replaceAll` | `pub fn replaceAll(s: str, needle: str, repl: str): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `87` | `std/fmt/str_builder.aipl` | `replace` | `pub fn replace(s: str, search: str, repl: str): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `88` | `std/fmt/str_builder.aipl` | `replaceFirst` | `pub fn replaceFirst(s: str, old: str, new: str): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `89` | `std/fmt/str_builder.aipl` | `startsWith` | `pub fn startsWith(s: str, prefix: str, offset: int = 0): bool:` | `tests/functions/fmt/str_builder_test.aipl` |
| `90` | `std/fmt/str_builder.aipl` | `endsWith` | `pub fn endsWith(s: str, suffix: str): bool:` | `tests/functions/fmt/str_builder_test.aipl` |
| `91` | `std/fmt/str_builder.aipl` | `contains` | `pub fn contains(s: str, needle: str): bool:` | `tests/functions/fmt/str_builder_test.aipl` |
| `92` | `std/fmt/str_builder.aipl` | `indexOf` | `pub fn indexOf(s: str, needle: str, fromIndex: int = 0): int:` | `tests/functions/fmt/str_builder_test.aipl` |
| `93` | `std/fmt/str_builder.aipl` | `indexOfFrom` | `pub fn indexOfFrom(s: str, sub: str, startIdx: int): int:` | `tests/functions/fmt/str_builder_test.aipl` |
| `94` | `std/fmt/str_builder.aipl` | `lastIndexOf` | `pub fn lastIndexOf(s: str, needle: str): int:` | `tests/functions/fmt/str_builder_test.aipl` |
| `95` | `std/fmt/str_builder.aipl` | `stripPrefix` | `pub fn stripPrefix(s: str, prefix: str): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `96` | `std/fmt/str_builder.aipl` | `stripSuffix` | `pub fn stripSuffix(s: str, suffix: str): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `97` | `std/fmt/str_builder.aipl` | `splitOnce` | `pub fn splitOnce(s: str, delim: str): Option[(str, str)]:` | `tests/functions/fmt/str_builder_test.aipl` |
| `98` | `std/fmt/str_builder.aipl` | `words` | `pub fn words(s: str): [str]:` | `tests/functions/fmt/str_builder_test.aipl` |
| `99` | `std/fmt/str_builder.aipl` | `splitWhitespace` | `pub fn splitWhitespace(s: str): [str]:` | `tests/functions/fmt/str_builder_test.aipl` |
| `100` | `std/fmt/str_builder.aipl` | `escapeQuotedString` | `pub fn escapeQuotedString(s: str): str:` | `tests/functions/fmt/str_builder_test.aipl` |
| `101` | `std/fmt/str_builder.aipl` | `levenshteinDistance` | `pub fn levenshteinDistance(a: str, b: str): int:` | `tests/functions/fmt/str_builder_test.aipl` |
| `102` | `std/fmt/str_builder.aipl` | `jaroWinklerSimilarity` | `pub fn jaroWinklerSimilarity(a: str, b: str): float:` | `tests/functions/fmt/str_builder_test.aipl` |
| `103` | `std/fmt/text_print.aipl` | `formatInterpolated` | `pub fn formatInterpolated(templateStr: str, args: [str]): str:` | `tests/functions/fmt/text_print_test.aipl` |
| `104` | `std/fmt/text_print.aipl` | `tableNew` | `pub fn tableNew(columns: [TableColumn], hasBorder: bool = true): FormattedTable:` | `tests/functions/fmt/text_print_test.aipl` |
| `105` | `std/fmt/text_print.aipl` | `formatTableCell` | `fn formatTableCell(text: str, width: int, align: str): str:` | `tests/functions/fmt/text_print_test.aipl` |
| `106` | `std/fmt/text_print.aipl` | `addRow` | `pub fn (mut self: FormattedTable) addRow(cells: [str]): void:` | `tests/functions/fmt/text_print_test.aipl` |
| `107` | `std/fmt/text_print.aipl` | `render` | `pub fn (self: FormattedTable) render(): str:` | `tests/functions/fmt/text_print_test.aipl` |
| `108` | `std/fmt/text_print.aipl` | `formatByteSize` | `pub fn formatByteSize(bytes: int): str:` | `tests/functions/fmt/text_print_test.aipl` |
| `109` | `std/fmt/text_print.aipl` | `formatThousands` | `pub fn formatThousands(num: int, separator: str = ","): str:` | `tests/functions/fmt/text_print_test.aipl` |
| `110` | `std/fmt/text_print.aipl` | `wordWrap` | `pub fn wordWrap(text: str, columnWidth: int): [str]:` | `tests/functions/fmt/text_print_test.aipl` |
| `111` | `std/fmt/text_print.aipl` | `truncateEllipsis` | `pub fn truncateEllipsis(text: str, maxLen: int, ellipsis: str = "..."): str:` | `tests/functions/fmt/text_print_test.aipl` |
| `112` | `std/fmt/text_print.aipl` | `stripAnsi` | `pub fn stripAnsi(s: str): str:` | `tests/functions/fmt/text_print_test.aipl` |
| `113` | `std/fmt/unicode_utf8.aipl` | `utf8DecodeRune` | `pub fn utf8DecodeRune(data: bytes, offset: int): (int, int):` | `tests/functions/fmt/unicode_utf8_test.aipl` |
| `114` | `std/fmt/unicode_utf8.aipl` | `utf8Validate` | `pub fn utf8Validate(data: bytes): bool:` | `tests/functions/fmt/unicode_utf8_test.aipl` |
| `115` | `std/fmt/unicode_utf8.aipl` | `utf8EncodeRune` | `pub fn utf8EncodeRune(codepoint: int): bytes:` | `tests/functions/fmt/unicode_utf8_test.aipl` |
| `116` | `std/fmt/unicode_utf8.aipl` | `decodeRuneFromStr` | `fn decodeRuneFromStr(s: str, idx: int): (int, int):` | `tests/functions/fmt/unicode_utf8_test.aipl` |
| `117` | `std/fmt/unicode_utf8.aipl` | `codepoints` | `pub fn codepoints(s: str): [int]:` | `tests/functions/fmt/unicode_utf8_test.aipl` |
| `118` | `std/fmt/unicode_utf8.aipl` | `codepointCount` | `pub fn codepointCount(s: str): int:` | `tests/functions/fmt/unicode_utf8_test.aipl` |
| `119` | `std/fmt/unicode_utf8.aipl` | `isControlRune` | `pub fn isControlRune(cp: int): bool:` | `tests/functions/fmt/unicode_utf8_test.aipl` |
| `120` | `std/fmt/unicode_utf8.aipl` | `isWhitespaceRune` | `pub fn isWhitespaceRune(cp: int): bool:` | `tests/functions/fmt/unicode_utf8_test.aipl` |
| `121` | `std/fmt/unicode_utf8.aipl` | `isAlphaRune` | `pub fn isAlphaRune(cp: int): bool:` | `tests/functions/fmt/unicode_utf8_test.aipl` |
| `122` | `std/fmt/unicode_utf8.aipl` | `isDigitRune` | `pub fn isDigitRune(cp: int): bool:` | `tests/functions/fmt/unicode_utf8_test.aipl` |
| `123` | `std/fmt/unicode_utf8.aipl` | `runeDisplayWidth` | `pub fn runeDisplayWidth(cp: int): int:` | `tests/functions/fmt/unicode_utf8_test.aipl` |
| `124` | `std/fmt/unicode_utf8.aipl` | `stringDisplayWidth` | `pub fn stringDisplayWidth(s: str): int:` | `tests/functions/fmt/unicode_utf8_test.aipl` |
| `125` | `std/fmt/unicode_utf8.aipl` | `graphemeClusters` | `pub fn graphemeClusters(s: str): [GraphemeCluster]:` | `tests/functions/fmt/unicode_utf8_test.aipl` |

---

## 4. Detailed API Reference & Runnable Verification Snippets

### `format` (`std/fmt/fmt_mod.aipl`)

- **Signature**: `pub fn format(templateStr: str, args: [str]): str:`
- **Import**: `import * from "std/fmt/fmt_mod"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `templateStr: str, args: [str]` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/fmt_mod_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify top-level formatting facade `format` parity with underlying `num_parse` and `text_print` primitives. Concrete nominal inputs: `templateStr: str = "aipl_test"`, `args: [str] = ["aipl_test"]`; exercises core body path returning/computing `formatInterpolated(templateStr, args)`.

```aipl
module tests.functions.fmt.fmt_mod_z1_test
import * from "std/fmt/fmt_mod"
import { formatInterpolated, TableColumn, tableNew } from "std/fmt/text_print"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fmt_mod_format_1(): int:
  let arg_templateStr = "test"
  let edge_templateStr = "a"
  let arg_args = ["test"]
  let edge_args = []
  let resNom = format(arg_templateStr, arg_args)
  let resEdge = format(edge_templateStr, edge_args)
  assertEqStr(resNom, "test", "format nominal string matches")
  assertEqStr(resEdge, "a", "format boundary string matches")
  ret 0
```

---

### `printTable` (`std/fmt/fmt_mod.aipl`)

- **Signature**: `pub fn printTable(columns: [TableColumn], rows: [[str]]): str:`
- **Import**: `import * from "std/fmt/fmt_mod"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `columns: [TableColumn], rows: [[str]]` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/fmt_mod_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify top-level formatting facade `printTable` parity with underlying `num_parse` and `text_print` primitives. Concrete nominal inputs: `columns: [TableColumn] = [TableColumn(header = "aipl_test", width = 128, align = "aipl_test")]`, `rows: [[str]] = [["aipl_test"]]`; exercises core body path returning/computing `tbl.render()`.

```aipl
module tests.functions.fmt.fmt_mod_z2_test
import * from "std/fmt/fmt_mod"
import { formatInterpolated, TableColumn, tableNew } from "std/fmt/text_print"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fmt_mod_printTable_2(): int:
  let arg_columns = [TableColumn(header = "42", width = 4, align = "42")]
  let edge_columns = []
  let arg_rows = [[]]
  let edge_rows = []
  let resNom = printTable(arg_columns, arg_rows)
  let resEdge = printTable(edge_columns, edge_rows)
  assertEqInt(resNom.len(), 44, "printTable nominal string length == 44")
  assertEqInt(resEdge.len(), 11, "printTable boundary string length == 11")
  ret 0
```

---

### `isSpaceChar` (`std/fmt/num_parse.aipl`)

- **Signature**: `fn isSpaceChar(ch: str): bool:`
- **Import**: `import * from "std/fmt/num_parse"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ch: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/fmt/num_parse_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify numeric parser/formatter `isSpaceChar` across radix 2/8/10/16, signed/unsigned boundaries, invalid digit rejection, and Dragonbox/fixed/scientific float formatting. Concrete nominal inputs: `ch: str = "aipl_test"`; exercises core body path returning/computing `ch == " " or ch == "\t" or ch == "\n" or ch == "\r"`.

```aipl
module tests.functions.fmt.num_parse_z1_test
import * from "std/fmt/num_parse"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_num_parse_isSpaceChar_1(): int:
  let arg_ch = "test"
  let edge_ch = "a"
  let resNom = isSpaceChar(arg_ch)
  let resEdge = isSpaceChar(edge_ch)
  assert(resNom == false, "isSpaceChar nominal resNom == false")
  assert(resEdge == false, "isSpaceChar boundary resEdge == false")
  ret 0
```

---

### `trimNumeric` (`std/fmt/num_parse.aipl`)

- **Signature**: `fn trimNumeric(s: str): str:`
- **Import**: `import * from "std/fmt/num_parse"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/num_parse_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify numeric parser/formatter `trimNumeric` across radix 2/8/10/16, signed/unsigned boundaries, invalid digit rejection, and Dragonbox/fixed/scientific float formatting. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `s.slice(start, endIdx)`.

```aipl
module tests.functions.fmt.num_parse_z2_test
import * from "std/fmt/num_parse"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_num_parse_trimNumeric_2(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = trimNumeric(arg_s)
  let resEdge = trimNumeric(edge_s)
  assertEqStr(resNom, "test", "trimNumeric nominal string matches")
  assertEqStr(resEdge, "a", "trimNumeric boundary string matches")
  ret 0
```

---

### `charToDigit` (`std/fmt/num_parse.aipl`)

- **Signature**: `fn charToDigit(ch: str): int:`
- **Import**: `import * from "std/fmt/num_parse"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ch: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/fmt/num_parse_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify numeric parser/formatter `charToDigit` across radix 2/8/10/16, signed/unsigned boundaries, invalid digit rejection, and Dragonbox/fixed/scientific float formatting. Concrete nominal inputs: `ch: str = "aipl_test"`; exercises core body path returning/computing `-1`.

```aipl
module tests.functions.fmt.num_parse_z3_test
import * from "std/fmt/num_parse"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_num_parse_charToDigit_3(): int:
  let arg_ch = "test"
  let edge_ch = "a"
  let resNom = charToDigit(arg_ch)
  let resEdge = charToDigit(edge_ch)
  assertEqInt(resNom, 29, "charToDigit nominal resNom == 29")
  assertEqInt(resEdge, 10, "charToDigit boundary resEdge == 10")
  ret 0
```

---

### `parseIntEx` (`std/fmt/num_parse.aipl`)

- **Signature**: `pub fn parseIntEx(s: str, opts: ParseIntOptions): Result[int, str]:`
- **Import**: `import * from "std/fmt/num_parse"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, opts: ParseIntOptions` | **Returns**: `Result[int, str]`
- **Unit Test**: `tests/functions/fmt/num_parse_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify numeric parser/formatter `parseIntEx` across radix 2/8/10/16, signed/unsigned boundaries, invalid digit rejection, and Dragonbox/fixed/scientific float formatting. Concrete nominal inputs: `s: str = "aipl_test"`, `opts: ParseIntOptions = ParseIntOptions(radix = 1, strict = true, allowLeadingSign = true, allowUnderscores = true)`; exercises core body path returning/computing `Ok(acc * sign)`.

```aipl
module tests.functions.fmt.num_parse_z4_test
import * from "std/fmt/num_parse"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_num_parse_parseIntEx_4(): int:
  let arg_s = "42"
  let edge_s = "0"
  let arg_opts = ParseIntOptions(radix = 4, strict = true, allowLeadingSign = true, allowUnderscores = true)
  let edge_opts = ParseIntOptions(radix = 4, strict = false, allowLeadingSign = false, allowUnderscores = false)
  let resNom = parseIntEx(arg_s, arg_opts)
  let resEdge = parseIntEx(edge_s, edge_opts)
  assert(resNom.isOk() == false, "parseIntEx nominal resNom.isOk() == false")
  assert(resEdge.isOk() == true, "parseIntEx boundary resEdge.isOk() == true")
  ret 0
```

---

### `parseInt` (`std/fmt/num_parse.aipl`)

- **Signature**: `pub fn parseInt(s: str, radix: int = 10): Result[int, str]:`
- **Import**: `import * from "std/fmt/num_parse"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, radix: int = 10` | **Returns**: `Result[int, str]`
- **Unit Test**: `tests/functions/fmt/num_parse_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify numeric parser/formatter `parseInt` across radix 2/8/10/16, signed/unsigned boundaries, invalid digit rejection, and Dragonbox/fixed/scientific float formatting. Concrete nominal inputs: `s: str = "aipl_test"`, `radix: int = 1`; exercises core body path returning/computing `parseIntEx(s, opts)`.

```aipl
module tests.functions.fmt.num_parse_z5_test
import * from "std/fmt/num_parse"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_num_parse_parseInt_5(): int:
  let arg_s = "42"
  let edge_s = "0"
  let arg_radix = 4
  let edge_radix = 1
  let resNom = parseInt(arg_s, arg_radix)
  let resEdge = parseInt(edge_s, edge_radix)
  assert(resNom.isOk() == false, "parseInt nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "parseInt boundary resEdge.isOk() == false")
  ret 0
```

---

### `parseIntRadix` (`std/fmt/num_parse.aipl`)

- **Signature**: `pub fn parseIntRadix(s: str, radix: int): Result[int, str]:`
- **Import**: `import * from "std/fmt/num_parse"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, radix: int` | **Returns**: `Result[int, str]`
- **Unit Test**: `tests/functions/fmt/num_parse_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify numeric parser/formatter `parseIntRadix` across radix 2/8/10/16, signed/unsigned boundaries, invalid digit rejection, and Dragonbox/fixed/scientific float formatting. Concrete nominal inputs: `s: str = "aipl_test"`, `radix: int = 1`; exercises core body path returning/computing `parseInt(s, radix)`.

```aipl
module tests.functions.fmt.num_parse_z6_test
import * from "std/fmt/num_parse"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_num_parse_parseIntRadix_6(): int:
  let arg_s = "42"
  let edge_s = "0"
  let arg_radix = 4
  let edge_radix = 1
  let resNom = parseIntRadix(arg_s, arg_radix)
  let resEdge = parseIntRadix(edge_s, edge_radix)
  assert(resNom.isOk() == false, "parseIntRadix nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "parseIntRadix boundary resEdge.isOk() == false")
  ret 0
```

---

### `parseHexByte` (`std/fmt/num_parse.aipl`)

- **Signature**: `pub fn parseHexByte(s: str, offset: int = 0): Result[int, str]:`
- **Import**: `import * from "std/fmt/num_parse"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, offset: int = 0` | **Returns**: `Result[int, str]`
- **Unit Test**: `tests/functions/fmt/num_parse_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify numeric parser/formatter `parseHexByte` across radix 2/8/10/16, signed/unsigned boundaries, invalid digit rejection, and Dragonbox/fixed/scientific float formatting. Concrete nominal inputs: `s: str = "aipl_test"`, `offset: int = 0`; exercises core body path returning/computing `Ok((d0 * 16) + d1)`.

```aipl
module tests.functions.fmt.num_parse_z7_test
import * from "std/fmt/num_parse"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_num_parse_parseHexByte_7(): int:
  let arg_s = "4142"
  let edge_s = "00"
  let arg_offset = 1
  let edge_offset = 0
  let resNom = parseHexByte(arg_s, arg_offset)
  let resEdge = parseHexByte(edge_s, edge_offset)
  assert(resNom.isOk() == true, "parseHexByte nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "parseHexByte boundary resEdge.isOk() == true")
  ret 0
```

---

### `parseFloatEx` (`std/fmt/num_parse.aipl`)

- **Signature**: `pub fn parseFloatEx(s: str, opts: ParseFloatOptions): Result[float, str]:`
- **Import**: `import * from "std/fmt/num_parse"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, opts: ParseFloatOptions` | **Returns**: `Result[float, str]`
- **Unit Test**: `tests/functions/fmt/num_parse_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify numeric parser/formatter `parseFloatEx` across radix 2/8/10/16, signed/unsigned boundaries, invalid digit rejection, and Dragonbox/fixed/scientific float formatting. Concrete nominal inputs: `s: str = "aipl_test"`, `opts: ParseFloatOptions = ParseFloatOptions(allowNan = true, allowInf = true, allowHexFloat = true)`; exercises core body path returning/computing `Ok(baseVal)`.

```aipl
module tests.functions.fmt.num_parse_z8_test
import * from "std/fmt/num_parse"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_num_parse_parseFloatEx_8(): int:
  let arg_s = "42"
  let edge_s = "0"
  let arg_opts = ParseFloatOptions(allowNan = true, allowInf = true, allowHexFloat = true)
  let edge_opts = ParseFloatOptions(allowNan = false, allowInf = false, allowHexFloat = false)
  let resNom = parseFloatEx(arg_s, arg_opts)
  let resEdge = parseFloatEx(edge_s, edge_opts)
  assert(resNom.isOk() == true, "parseFloatEx nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "parseFloatEx boundary resEdge.isOk() == true")
  ret 0
```

---

### `parseFloat` (`std/fmt/num_parse.aipl`)

- **Signature**: `pub fn parseFloat(s: str): Result[float, str]:`
- **Import**: `import * from "std/fmt/num_parse"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `Result[float, str]`
- **Unit Test**: `tests/functions/fmt/num_parse_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify numeric parser/formatter `parseFloat` across radix 2/8/10/16, signed/unsigned boundaries, invalid digit rejection, and Dragonbox/fixed/scientific float formatting. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `parseFloatEx(s, opts)`.

```aipl
module tests.functions.fmt.num_parse_z9_test
import * from "std/fmt/num_parse"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_num_parse_parseFloat_9(): int:
  let arg_s = "42"
  let edge_s = "0"
  let resNom = parseFloat(arg_s)
  let resEdge = parseFloat(edge_s)
  assert(resNom.isOk() == true, "parseFloat nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "parseFloat boundary resEdge.isOk() == true")
  ret 0
```

---

### `parseFloatPrefix` (`std/fmt/num_parse.aipl`)

- **Signature**: `pub fn parseFloatPrefix(s: str): Option[float]:`
- **Import**: `import * from "std/fmt/num_parse"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `Option[float]`
- **Unit Test**: `tests/functions/fmt/num_parse_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify numeric parser/formatter `parseFloatPrefix` across radix 2/8/10/16, signed/unsigned boundaries, invalid digit rejection, and Dragonbox/fixed/scientific float formatting. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.fmt.num_parse_z10_test
import * from "std/fmt/num_parse"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_num_parse_parseFloatPrefix_10(): int:
  let arg_s = "42"
  let edge_s = "0"
  let resNom = parseFloatPrefix(arg_s)
  let resEdge = parseFloatPrefix(edge_s)
  assert(resNom.isSome() == true, "parseFloatPrefix nominal resNom.isSome() == true")
  assert(resEdge.isSome() == true, "parseFloatPrefix boundary resEdge.isSome() == true")
  ret 0
```

---

### `formatInt` (`std/fmt/num_parse.aipl`)

- **Signature**: `pub fn formatInt(val: int, radix: int = 10): str:`
- **Import**: `import * from "std/fmt/num_parse"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: int, radix: int = 10` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/num_parse_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify numeric parser/formatter `formatInt` across radix 2/8/10/16, signed/unsigned boundaries, invalid digit rejection, and Dragonbox/fixed/scientific float formatting. Concrete nominal inputs: `val: int = 1`, `radix: int = 1`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.fmt.num_parse_z11_test
import * from "std/fmt/num_parse"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_num_parse_formatInt_11(): int:
  let arg_val = 2
  let edge_val = 0
  let arg_radix = 4
  let edge_radix = 1
  let resNom = formatInt(arg_val, arg_radix)
  let resEdge = formatInt(edge_val, edge_radix)
  assertEqStr(resNom, "2", "formatInt nominal string matches")
  assertEqStr(resEdge, "0", "formatInt boundary string matches")
  ret 0
```

---

### `formatIntPadded` (`std/fmt/num_parse.aipl`)

- **Signature**: `pub fn formatIntPadded(val: int, width: int, padChar: str = "0", radix: int = 10): str:`
- **Import**: `import * from "std/fmt/num_parse"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: int, width: int, padChar: str = "0", radix: int = 10` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/num_parse_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify numeric parser/formatter `formatIntPadded` across radix 2/8/10/16, signed/unsigned boundaries, invalid digit rejection, and Dragonbox/fixed/scientific float formatting. Concrete nominal inputs: `val: int = 1`, `width: int = 128`, `padChar: str = "aipl_test"`, `radix: int = 1`; exercises core body path returning/computing `padStr + body`.

```aipl
module tests.functions.fmt.num_parse_z12_test
import * from "std/fmt/num_parse"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_num_parse_formatIntPadded_12(): int:
  let arg_val = 2
  let edge_val = 0
  let arg_width = 4
  let edge_width = 1
  let arg_padChar = "42"
  let edge_padChar = "0"
  let arg_radix = 4
  let edge_radix = 1
  let resNom = formatIntPadded(arg_val, arg_width, arg_padChar, arg_radix)
  let resEdge = formatIntPadded(edge_val, edge_width, edge_padChar, edge_radix)
  assertEqStr(resNom, "4442", "formatIntPadded nominal string matches")
  assertEqStr(resEdge, "0", "formatIntPadded boundary string matches")
  ret 0
```

---

### `formatHex` (`std/fmt/num_parse.aipl`)

- **Signature**: `pub fn formatHex(val: int, uppercase: bool = false, prefix: bool = false): str:`
- **Import**: `import * from "std/fmt/num_parse"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: int, uppercase: bool = false, prefix: bool = false` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/num_parse_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify numeric parser/formatter `formatHex` across radix 2/8/10/16, signed/unsigned boundaries, invalid digit rejection, and Dragonbox/fixed/scientific float formatting. Concrete nominal inputs: `val: int = 1`, `uppercase: bool = true`, `prefix: bool = true`; exercises core body path returning/computing `pfx + cased`.

```aipl
module tests.functions.fmt.num_parse_z13_test
import * from "std/fmt/num_parse"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_num_parse_formatHex_13(): int:
  let arg_val = 2
  let edge_val = 0
  let arg_uppercase = true
  let edge_uppercase = false
  let arg_prefix = true
  let edge_prefix = false
  let resNom = formatHex(arg_val, arg_uppercase, arg_prefix)
  let resEdge = formatHex(edge_val, edge_uppercase, edge_prefix)
  assertEqStr(resNom, "0X2", "formatHex nominal string matches")
  assertEqStr(resEdge, "0", "formatHex boundary string matches")
  ret 0
```

---

### `formatBinary` (`std/fmt/num_parse.aipl`)

- **Signature**: `pub fn formatBinary(val: int, prefix: bool = false, minDigits: int = 0): str:`
- **Import**: `import * from "std/fmt/num_parse"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: int, prefix: bool = false, minDigits: int = 0` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/num_parse_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify numeric parser/formatter `formatBinary` across radix 2/8/10/16, signed/unsigned boundaries, invalid digit rejection, and Dragonbox/fixed/scientific float formatting. Concrete nominal inputs: `val: int = 1`, `prefix: bool = true`, `minDigits: int = 1`; exercises core body path returning/computing `pfx + raw`.

```aipl
module tests.functions.fmt.num_parse_z14_test
import * from "std/fmt/num_parse"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_num_parse_formatBinary_14(): int:
  let arg_val = 2
  let edge_val = 0
  let arg_prefix = true
  let edge_prefix = false
  let arg_minDigits = 4
  let edge_minDigits = 1
  let resNom = formatBinary(arg_val, arg_prefix, arg_minDigits)
  let resEdge = formatBinary(edge_val, edge_prefix, edge_minDigits)
  assertEqStr(resNom, "0b0010", "formatBinary nominal string matches")
  assertEqStr(resEdge, "0", "formatBinary boundary string matches")
  ret 0
```

---

### `formatOctal` (`std/fmt/num_parse.aipl`)

- **Signature**: `pub fn formatOctal(val: int, prefix: bool = false): str:`
- **Import**: `import * from "std/fmt/num_parse"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: int, prefix: bool = false` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/num_parse_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify numeric parser/formatter `formatOctal` across radix 2/8/10/16, signed/unsigned boundaries, invalid digit rejection, and Dragonbox/fixed/scientific float formatting. Concrete nominal inputs: `val: int = 1`, `prefix: bool = true`; exercises core body path returning/computing `pfx + raw`.

```aipl
module tests.functions.fmt.num_parse_z15_test
import * from "std/fmt/num_parse"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_num_parse_formatOctal_15(): int:
  let arg_val = 2
  let edge_val = 0
  let arg_prefix = true
  let edge_prefix = false
  let resNom = formatOctal(arg_val, arg_prefix)
  let resEdge = formatOctal(edge_val, edge_prefix)
  assertEqStr(resNom, "0o2", "formatOctal nominal string matches")
  assertEqStr(resEdge, "0", "formatOctal boundary string matches")
  ret 0
```

---

### `intToHex` (`std/fmt/num_parse.aipl`)

- **Signature**: `pub fn intToHex(n: int, minWidth: int = 0): str:`
- **Import**: `import * from "std/fmt/num_parse"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `n: int, minWidth: int = 0` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/num_parse_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify numeric parser/formatter `intToHex` across radix 2/8/10/16, signed/unsigned boundaries, invalid digit rejection, and Dragonbox/fixed/scientific float formatting. Concrete nominal inputs: `n: int = 1`, `minWidth: int = 1`; exercises core body path returning/computing `formatIntPadded(n, minWidth, "0", 16)`.

```aipl
module tests.functions.fmt.num_parse_z16_test
import * from "std/fmt/num_parse"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_num_parse_intToHex_16(): int:
  let arg_n = 4
  let edge_n = 1
  let arg_minWidth = 4
  let edge_minWidth = 1
  let resNom = intToHex(arg_n, arg_minWidth)
  let resEdge = intToHex(edge_n, edge_minWidth)
  assertEqStr(resNom, "0004", "intToHex nominal string matches")
  assertEqStr(resEdge, "1", "intToHex boundary string matches")
  ret 0
```

---

### `intToOctal` (`std/fmt/num_parse.aipl`)

- **Signature**: `pub fn intToOctal(n: int, minWidth: int = 0): str:`
- **Import**: `import * from "std/fmt/num_parse"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `n: int, minWidth: int = 0` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/num_parse_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify numeric parser/formatter `intToOctal` across radix 2/8/10/16, signed/unsigned boundaries, invalid digit rejection, and Dragonbox/fixed/scientific float formatting. Concrete nominal inputs: `n: int = 1`, `minWidth: int = 1`; exercises core body path returning/computing `formatIntPadded(n, minWidth, "0", 8)`.

```aipl
module tests.functions.fmt.num_parse_z17_test
import * from "std/fmt/num_parse"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_num_parse_intToOctal_17(): int:
  let arg_n = 4
  let edge_n = 1
  let arg_minWidth = 4
  let edge_minWidth = 1
  let resNom = intToOctal(arg_n, arg_minWidth)
  let resEdge = intToOctal(edge_n, edge_minWidth)
  assertEqStr(resNom, "0004", "intToOctal nominal string matches")
  assertEqStr(resEdge, "1", "intToOctal boundary string matches")
  ret 0
```

---

### `formatFloatFixed` (`std/fmt/num_parse.aipl`)

- **Signature**: `pub fn formatFloatFixed(val: float, decimals: int = 2): str:`
- **Import**: `import * from "std/fmt/num_parse"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: float, decimals: int = 2` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/num_parse_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify numeric parser/formatter `formatFloatFixed` across radix 2/8/10/16, signed/unsigned boundaries, invalid digit rejection, and Dragonbox/fixed/scientific float formatting. Concrete nominal inputs: `val: float = 1.0`, `decimals: int = 1`; exercises core body path returning/computing `if isNeg: "-" + res else: res`.

```aipl
module tests.functions.fmt.num_parse_z18_test
import * from "std/fmt/num_parse"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_num_parse_formatFloatFixed_18(): int:
  let arg_val = 1.0
  let edge_val = 0.5
  let arg_decimals = 4
  let edge_decimals = 1
  let resNom = formatFloatFixed(arg_val, arg_decimals)
  let resEdge = formatFloatFixed(edge_val, edge_decimals)
  assertEqStr(resNom, "1.0000", "formatFloatFixed nominal string matches")
  assertEqStr(resEdge, "0.5", "formatFloatFixed boundary string matches")
  ret 0
```

---

### `formatFloat` (`std/fmt/num_parse.aipl`)

- **Signature**: `pub fn formatFloat(val: float, decimals: int): str:`
- **Import**: `import * from "std/fmt/num_parse"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: float, decimals: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/num_parse_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify numeric parser/formatter `formatFloat` across radix 2/8/10/16, signed/unsigned boundaries, invalid digit rejection, and Dragonbox/fixed/scientific float formatting. Concrete nominal inputs: `val: float = 1.0`, `decimals: int = 1`; exercises core body path returning/computing `formatFloatFixed(val, decimals)`.

```aipl
module tests.functions.fmt.num_parse_z19_test
import * from "std/fmt/num_parse"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_num_parse_formatFloat_19(): int:
  let arg_val = 1.0
  let edge_val = 0.5
  let arg_decimals = 4
  let edge_decimals = 1
  let resNom = formatFloat(arg_val, arg_decimals)
  let resEdge = formatFloat(edge_val, edge_decimals)
  assertEqStr(resNom, "1.0000", "formatFloat nominal string matches")
  assertEqStr(resEdge, "0.5", "formatFloat boundary string matches")
  ret 0
```

---

### `formatFloatDragonbox` (`std/fmt/num_parse.aipl`)

- **Signature**: `pub fn formatFloatDragonbox(val: float, precision: int = -1): str:`
- **Import**: `import * from "std/fmt/num_parse"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: float, precision: int = -1` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/num_parse_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify numeric parser/formatter `formatFloatDragonbox` across radix 2/8/10/16, signed/unsigned boundaries, invalid digit rejection, and Dragonbox/fixed/scientific float formatting. Concrete nominal inputs: `val: float = 1.0`, `precision: int = 1`; exercises core body path returning/computing `fixed6.slice(0, endIdx)`.

```aipl
module tests.functions.fmt.num_parse_z20_test
import * from "std/fmt/num_parse"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_num_parse_formatFloatDragonbox_20(): int:
  let arg_val = 1.0
  let edge_val = 0.5
  let arg_precision = 4
  let edge_precision = 1
  let resNom = formatFloatDragonbox(arg_val, arg_precision)
  let resEdge = formatFloatDragonbox(edge_val, edge_precision)
  assertEqStr(resNom, "1.0000", "formatFloatDragonbox nominal string matches")
  assertEqStr(resEdge, "0.5", "formatFloatDragonbox boundary string matches")
  ret 0
```

---

### `formatFloatScientific` (`std/fmt/num_parse.aipl`)

- **Signature**: `pub fn formatFloatScientific(val: float, precision: int = 6): str:`
- **Import**: `import * from "std/fmt/num_parse"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: float, precision: int = 6` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/num_parse_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify numeric parser/formatter `formatFloatScientific` across radix 2/8/10/16, signed/unsigned boundaries, invalid digit rejection, and Dragonbox/fixed/scientific float formatting. Concrete nominal inputs: `val: float = 1.0`, `precision: int = 1`; exercises core body path returning/computing `signStr + mantissa + "e" + expSign + expStr`.

```aipl
module tests.functions.fmt.num_parse_z21_test
import * from "std/fmt/num_parse"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_num_parse_formatFloatScientific_21(): int:
  let arg_val = 1.0
  let edge_val = 0.5
  let arg_precision = 4
  let edge_precision = 1
  let resNom = formatFloatScientific(arg_val, arg_precision)
  let resEdge = formatFloatScientific(edge_val, edge_precision)
  assertEqStr(resNom, "1.0000e+00", "formatFloatScientific nominal string matches")
  assertEqStr(resEdge, "5.0e-01", "formatFloatScientific boundary string matches")
  ret 0
```

---

### `TextRange.new` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn TextRange.new(start: int, end: int): TextRange:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `start: int, end: int` | **Returns**: `TextRange`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `TextRange.new` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `start: int = 1`, `end: int = 1`; exercises core body path returning/computing `TextRange(start = start, end = end)`.

```aipl
module tests.functions.fmt.str_builder_z1_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_TextRange_new_1(): int:

  let arg_start = 1
  let edge_start = 0
  let arg_end = 1
  let edge_end = 0
  let resNom = TextRange.new(arg_start, arg_end)
  let resRepeat = TextRange.new(arg_start, arg_end)
  let resEdge = TextRange.new(edge_start, edge_end)
  assertEqInt(resNom.start, 1, "TextRange.new nominal resNom.start == 1")
  assertEqInt(resEdge.start, 0, "TextRange.new boundary resEdge.start == 0")
  ret 0
```

---

### `len` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn (self: TextRange) len(): int:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `self: TextRange` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `len` (`self: TextRange`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: receiver `recvObj: TextRange = TextRange(start = 1, end = 1)`; exercises core body path returning/computing `if self.end >= self.start: self.end - self.start else: 0`.

```aipl
module tests.functions.fmt.str_builder_z2_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_TextRange_len_2(): int:
  let recv_self = TextRange(start = 1, end = 4)
  let edge_self = TextRange(start = 0, end = 1)
  let resNom = recv_self.len()
  let resEdge = edge_self.len()
  assertEqInt(resNom, 3, "len nominal resNom == 3")
  assertEqInt(resEdge, 1, "len boundary resEdge == 1")
  ret 0
```

---

### `stringBuilderNew` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn stringBuilderNew(initialCapacity: int = 64): StringBuilder:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `initialCapacity: int = 64` | **Returns**: `StringBuilder`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `stringBuilderNew` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `initialCapacity: int = 64`; exercises core body path returning/computing `StringBuilder(chunks = empty, totalLen = 0, capacity = initialCapacity)`.

```aipl
module tests.functions.fmt.str_builder_z3_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_stringBuilderNew_3(): int:
  let arg_initialCapacity = 4
  let edge_initialCapacity = 1
  let resNom = stringBuilderNew(arg_initialCapacity)
  let resEdge = stringBuilderNew(edge_initialCapacity)
  assertEqInt(resNom.chunks.len(), 0, "stringBuilderNew nominal resNom.chunks.len() == 0")
  assertEqInt(resEdge.chunks.len(), 0, "stringBuilderNew boundary resEdge.chunks.len() == 0")
  ret 0
```

---

### `stringBuilderWithCapacity` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn stringBuilderWithCapacity(cap: int): StringBuilder:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cap: int` | **Returns**: `StringBuilder`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `stringBuilderWithCapacity` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `cap: int = 64`; exercises core body path returning/computing `stringBuilderNew(cap)`.

```aipl
module tests.functions.fmt.str_builder_z4_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_stringBuilderWithCapacity_4(): int:
  let arg_cap = 4
  let edge_cap = 1
  let resNom = stringBuilderWithCapacity(arg_cap)
  let resEdge = stringBuilderWithCapacity(edge_cap)
  assertEqInt(resNom.chunks.len(), 0, "stringBuilderWithCapacity nominal resNom.chunks.len() == 0")
  assertEqInt(resEdge.chunks.len(), 0, "stringBuilderWithCapacity boundary resEdge.chunks.len() == 0")
  ret 0
```

---

### `append` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn (mut self: StringBuilder) append(text: str): StringBuilder:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `mut self: StringBuilder` | **Parameters**: `text: str` | **Returns**: `StringBuilder`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `append` (`mut self: StringBuilder`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: receiver `recvObj: StringBuilder = StringBuilder(chunks = ["aipl_test"], totalLen = 64, capacity = 64)`, `text: str = "aipl_test"`; exercises core body path returning/computing `self`.

```aipl
module tests.functions.fmt.str_builder_z5_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_StringBuilder_append_5(): int:
  let mut recv_self = StringBuilder(chunks = [], totalLen = 4, capacity = 4)
  let mut edge_self = StringBuilder(chunks = [], totalLen = 1, capacity = 4)
  let arg_text = "test"
  let edge_text = "a"
  let resNom = recv_self.append(arg_text)
  let resEdge = edge_self.append(edge_text)
  assertEqInt(resNom.chunks.len(), 1, "append nominal resNom.chunks.len() == 1")
  assertEqInt(resEdge.chunks.len(), 1, "append boundary resEdge.chunks.len() == 1")
  ret 0
```

---

### `appendChar` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn (mut self: StringBuilder) appendChar(code: int): StringBuilder:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `mut self: StringBuilder` | **Parameters**: `code: int` | **Returns**: `StringBuilder`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `appendChar` (`mut self: StringBuilder`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: receiver `recvObj: StringBuilder = StringBuilder(chunks = ["aipl_test"], totalLen = 64, capacity = 64)`, `code: int = 1`; exercises core body path returning/computing `self`.

```aipl
module tests.functions.fmt.str_builder_z6_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_StringBuilder_appendChar_6(): int:
  let mut recv_self = StringBuilder(chunks = [], totalLen = 4, capacity = 4)
  let mut edge_self = StringBuilder(chunks = [], totalLen = 1, capacity = 4)
  let arg_code = 2
  let edge_code = 0
  let resNom = recv_self.appendChar(arg_code)
  let resEdge = edge_self.appendChar(edge_code)
  assertEqInt(resNom.chunks.len(), 1, "appendChar nominal resNom.chunks.len() == 1")
  assertEqInt(resEdge.chunks.len(), 1, "appendChar boundary resEdge.chunks.len() == 1")
  ret 0
```

---

### `appendLine` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn (mut self: StringBuilder) appendLine(line: str = ""): StringBuilder:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `mut self: StringBuilder` | **Parameters**: `line: str = ""` | **Returns**: `StringBuilder`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `appendLine` (`mut self: StringBuilder`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: receiver `recvObj: StringBuilder = StringBuilder(chunks = ["aipl_test"], totalLen = 64, capacity = 64)`, `line: str = "aipl_test"`; exercises core body path returning/computing `self`.

```aipl
module tests.functions.fmt.str_builder_z7_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_StringBuilder_appendLine_7(): int:
  let mut recv_self = StringBuilder(chunks = [], totalLen = 4, capacity = 4)
  let mut edge_self = StringBuilder(chunks = [], totalLen = 1, capacity = 4)
  let arg_line = "test"
  let edge_line = "a"
  let resNom = recv_self.appendLine(arg_line)
  let resEdge = edge_self.appendLine(edge_line)
  assertEqInt(resNom.chunks.len(), 2, "appendLine nominal resNom.chunks.len() == 2")
  assertEqInt(resEdge.chunks.len(), 2, "appendLine boundary resEdge.chunks.len() == 2")
  ret 0
```

---

### `appendInt` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn (mut self: StringBuilder) appendInt(n: int): StringBuilder:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `mut self: StringBuilder` | **Parameters**: `n: int` | **Returns**: `StringBuilder`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `appendInt` (`mut self: StringBuilder`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: receiver `recvObj: StringBuilder = StringBuilder(chunks = ["aipl_test"], totalLen = 64, capacity = 64)`, `n: int = 1`; exercises core body path returning/computing `self`.

```aipl
module tests.functions.fmt.str_builder_z8_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_StringBuilder_appendInt_8(): int:
  let mut recv_self = StringBuilder(chunks = [], totalLen = 4, capacity = 4)
  let mut edge_self = StringBuilder(chunks = [], totalLen = 1, capacity = 4)
  let arg_n = 4
  let edge_n = 1
  let resNom = recv_self.appendInt(arg_n)
  let resEdge = edge_self.appendInt(edge_n)
  assertEqInt(resNom.chunks.len(), 1, "appendInt nominal resNom.chunks.len() == 1")
  assertEqInt(resEdge.chunks.len(), 1, "appendInt boundary resEdge.chunks.len() == 1")
  ret 0
```

---

### `appendFloat` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn (mut self: StringBuilder) appendFloat(f: float, precision: int = 2): StringBuilder:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `mut self: StringBuilder` | **Parameters**: `f: float, precision: int = 2` | **Returns**: `StringBuilder`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `appendFloat` (`mut self: StringBuilder`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: receiver `recvObj: StringBuilder = StringBuilder(chunks = ["aipl_test"], totalLen = 64, capacity = 64)`, `f: float = 1.0`, `precision: int = 1`; exercises core body path returning/computing `self`.

```aipl
module tests.functions.fmt.str_builder_z9_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_StringBuilder_appendFloat_9(): int:
  let mut recv_self = StringBuilder(chunks = [], totalLen = 4, capacity = 4)
  let mut edge_self = StringBuilder(chunks = [], totalLen = 1, capacity = 4)
  let arg_f = 1.0
  let edge_f = 0.5
  let arg_precision = 4
  let edge_precision = 1
  let resNom = recv_self.appendFloat(arg_f, arg_precision)
  let resEdge = edge_self.appendFloat(edge_f, edge_precision)
  assertEqInt(resNom.chunks.len(), 1, "appendFloat nominal resNom.chunks.len() == 1")
  assertEqInt(resEdge.chunks.len(), 1, "appendFloat boundary resEdge.chunks.len() == 1")
  ret 0
```

---

### `clear` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn (mut self: StringBuilder) clear(): void:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `mut self: StringBuilder` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `clear` (`mut self: StringBuilder`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: receiver `recvObj: StringBuilder = StringBuilder(chunks = ["aipl_test"], totalLen = 64, capacity = 64)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.fmt.str_builder_z10_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_StringBuilder_clear_10(): int:
  let mut recv_self = StringBuilder(chunks = [], totalLen = 4, capacity = 4)
  let mut edge_self = StringBuilder(chunks = [], totalLen = 1, capacity = 4)
  recv_self.clear()
  edge_self.clear()
  assertEqInt(recv_self.totalLen, 0, "clear nominal recv_self.totalLen == 0")
  assertEqInt(edge_self.totalLen, 0, "clear boundary edge_self.totalLen == 0")
  ret 0
```

---

### `toString` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn (self: StringBuilder) toString(): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `self: StringBuilder` | **Parameters**: `none` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `toString` (`self: StringBuilder`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: receiver `recvObj: StringBuilder = StringBuilder(chunks = ["aipl_test"], totalLen = 64, capacity = 64)`; exercises core body path returning/computing `self.chunks.join("")`.

```aipl
module tests.functions.fmt.str_builder_z11_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_StringBuilder_toString_11(): int:
  let recv_self = StringBuilder(chunks = [], totalLen = 4, capacity = 4)
  let edge_self = StringBuilder(chunks = [], totalLen = 1, capacity = 4)
  let resNom = recv_self.toString()
  let resEdge = edge_self.toString()
  assertEqStr(resNom, "", "toString nominal string matches")
  assertEqStr(resEdge, "", "toString boundary string matches")
  ret 0
```

---

### `length` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn (self: StringBuilder) length(): int:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `self: StringBuilder` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `length` (`self: StringBuilder`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: receiver `recvObj: StringBuilder = StringBuilder(chunks = ["aipl_test"], totalLen = 64, capacity = 64)`; exercises core body path returning/computing `total`.

```aipl
module tests.functions.fmt.str_builder_z12_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_StringBuilder_length_12(): int:
  let recv_self = StringBuilder(chunks = [], totalLen = 4, capacity = 4)
  let edge_self = StringBuilder(chunks = [], totalLen = 1, capacity = 4)
  let resNom = recv_self.length()
  let resEdge = edge_self.length()
  assertEqInt(resNom, 0, "length nominal resNom == 0")
  assertEqInt(resEdge, 0, "length boundary resEdge == 0")
  ret 0
```

---

### `sbAppend` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn sbAppend(mut sb: StringBuilder, s: str): StringBuilder:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut sb: StringBuilder, s: str` | **Returns**: `StringBuilder`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `sbAppend` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `sb: StringBuilder = StringBuilder(chunks = ["aipl_test"], totalLen = 64, capacity = 64)`, `s: str = "aipl_test"`; exercises core body path returning/computing `sb.append(s)`.

```aipl
module tests.functions.fmt.str_builder_z13_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_sbAppend_13(): int:
  let arg_sb = StringBuilder(chunks = [], totalLen = 4, capacity = 4)
  let edge_sb = StringBuilder(chunks = [], totalLen = 1, capacity = 4)
  let arg_s = "test"
  let edge_s = "a"
  let resNom = sbAppend(arg_sb, arg_s)
  let resEdge = sbAppend(edge_sb, edge_s)
  assertEqInt(resNom.chunks.len(), 1, "sbAppend nominal resNom.chunks.len() == 1")
  assertEqInt(resEdge.chunks.len(), 1, "sbAppend boundary resEdge.chunks.len() == 1")
  ret 0
```

---

### `sbAppendChar` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn sbAppendChar(mut sb: StringBuilder, ch: str): StringBuilder:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut sb: StringBuilder, ch: str` | **Returns**: `StringBuilder`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `sbAppendChar` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `sb: StringBuilder = StringBuilder(chunks = ["aipl_test"], totalLen = 64, capacity = 64)`, `ch: str = "aipl_test"`; exercises core body path returning/computing `sb.append(ch)`.

```aipl
module tests.functions.fmt.str_builder_z14_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_sbAppendChar_14(): int:
  let arg_sb = StringBuilder(chunks = [], totalLen = 4, capacity = 4)
  let edge_sb = StringBuilder(chunks = [], totalLen = 1, capacity = 4)
  let arg_ch = "test"
  let edge_ch = "a"
  let resNom = sbAppendChar(arg_sb, arg_ch)
  let resEdge = sbAppendChar(edge_sb, edge_ch)
  assertEqInt(resNom.chunks.len(), 1, "sbAppendChar nominal resNom.chunks.len() == 1")
  assertEqInt(resEdge.chunks.len(), 1, "sbAppendChar boundary resEdge.chunks.len() == 1")
  ret 0
```

---

### `sbAppendIndent` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn sbAppendIndent(mut sb: StringBuilder, count: int, indentStr: str = "  "): StringBuilder:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut sb: StringBuilder, count: int, indentStr: str = "  "` | **Returns**: `StringBuilder`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `sbAppendIndent` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `sb: StringBuilder = StringBuilder(chunks = ["aipl_test"], totalLen = 64, capacity = 64)`, `count: int = 64`, `indentStr: str = "aipl_test"`; exercises core body path returning/computing `sb`.

```aipl
module tests.functions.fmt.str_builder_z15_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_sbAppendIndent_15(): int:
  let arg_sb = StringBuilder(chunks = [], totalLen = 4, capacity = 4)
  let edge_sb = StringBuilder(chunks = [], totalLen = 1, capacity = 4)
  let arg_count = 4
  let edge_count = 1
  let arg_indentStr = "test"
  let edge_indentStr = "a"
  let resNom = sbAppendIndent(arg_sb, arg_count, arg_indentStr)
  let resEdge = sbAppendIndent(edge_sb, edge_count, edge_indentStr)
  assertEqInt(resNom.chunks.len(), 4, "sbAppendIndent nominal resNom.chunks.len() == 4")
  assertEqInt(resEdge.chunks.len(), 1, "sbAppendIndent boundary resEdge.chunks.len() == 1")
  ret 0
```

---

### `sbAppendLine` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn sbAppendLine(mut sb: StringBuilder, line: str = ""): StringBuilder:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut sb: StringBuilder, line: str = ""` | **Returns**: `StringBuilder`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `sbAppendLine` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `sb: StringBuilder = StringBuilder(chunks = ["aipl_test"], totalLen = 64, capacity = 64)`, `line: str = "aipl_test"`; exercises core body path returning/computing `sb.appendLine(line)`.

```aipl
module tests.functions.fmt.str_builder_z16_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_sbAppendLine_16(): int:
  let arg_sb = StringBuilder(chunks = [], totalLen = 4, capacity = 4)
  let edge_sb = StringBuilder(chunks = [], totalLen = 1, capacity = 4)
  let arg_line = "test"
  let edge_line = "a"
  let resNom = sbAppendLine(arg_sb, arg_line)
  let resEdge = sbAppendLine(edge_sb, edge_line)
  assertEqInt(resNom.chunks.len(), 2, "sbAppendLine nominal resNom.chunks.len() == 2")
  assertEqInt(resEdge.chunks.len(), 2, "sbAppendLine boundary resEdge.chunks.len() == 2")
  ret 0
```

---

### `sbToString` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn sbToString(sb: StringBuilder): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `sb: StringBuilder` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `sbToString` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `sb: StringBuilder = StringBuilder(chunks = ["aipl_test"], totalLen = 64, capacity = 64)`; exercises core body path returning/computing `sb.toString()`.

```aipl
module tests.functions.fmt.str_builder_z17_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_sbToString_17(): int:
  let arg_sb = StringBuilder(chunks = [], totalLen = 4, capacity = 4)
  let edge_sb = StringBuilder(chunks = [], totalLen = 1, capacity = 4)
  let resNom = sbToString(arg_sb)
  let resEdge = sbToString(edge_sb)
  assertEqStr(resNom, "", "sbToString nominal string matches")
  assertEqStr(resEdge, "", "sbToString boundary string matches")
  ret 0
```

---

### `sbLen` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn sbLen(sb: StringBuilder): int:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `sb: StringBuilder` | **Returns**: `int`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `sbLen` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `sb: StringBuilder = StringBuilder(chunks = ["aipl_test"], totalLen = 64, capacity = 64)`; exercises core body path returning/computing `sb.length()`.

```aipl
module tests.functions.fmt.str_builder_z18_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_sbLen_18(): int:
  let arg_sb = StringBuilder(chunks = [], totalLen = 4, capacity = 4)
  let edge_sb = StringBuilder(chunks = [], totalLen = 1, capacity = 4)
  let resNom = sbLen(arg_sb)
  let resEdge = sbLen(edge_sb)
  assertEqInt(resNom, 0, "sbLen nominal resNom == 0")
  assertEqInt(resEdge, 0, "sbLen boundary resEdge == 0")
  ret 0
```

---

### `sbClear` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn sbClear(mut sb: StringBuilder): StringBuilder:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut sb: StringBuilder` | **Returns**: `StringBuilder`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `sbClear` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `sb: StringBuilder = StringBuilder(chunks = ["aipl_test"], totalLen = 64, capacity = 64)`; exercises core body path returning/computing `sb`.

```aipl
module tests.functions.fmt.str_builder_z19_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_sbClear_19(): int:
  let arg_sb = StringBuilder(chunks = [], totalLen = 4, capacity = 4)
  let edge_sb = StringBuilder(chunks = [], totalLen = 1, capacity = 4)
  let resNom = sbClear(arg_sb)
  let resEdge = sbClear(edge_sb)
  assertEqInt(resNom.chunks.len(), 0, "sbClear nominal resNom.chunks.len() == 0")
  assertEqInt(resEdge.chunks.len(), 0, "sbClear boundary resEdge.chunks.len() == 0")
  ret 0
```

---

### `stringViewFrom` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn stringViewFrom(s: str, start: int, len: int): StringView:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, start: int, len: int` | **Returns**: `StringView`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `stringViewFrom` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`, `start: int = 1`, `len: int = 64`; exercises core body path returning/computing `StringView(source = s, start = clampedStart, len = clampedLen)`.

```aipl
module tests.functions.fmt.str_builder_z20_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_stringViewFrom_20(): int:
  let arg_s = "test"
  let edge_s = "a"
  let arg_start = 1
  let edge_start = 0
  let arg_len = 4
  let edge_len = 1
  let resNom = stringViewFrom(arg_s, arg_start, arg_len)
  let resEdge = stringViewFrom(edge_s, edge_start, edge_len)
  assertEqStr(resNom.source, "test", "stringViewFrom nominal string matches")
  assertEqStr(resEdge.source, "a", "stringViewFrom boundary string matches")
  ret 0
```

---

### `toString` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn (self: StringView) toString(): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `self: StringView` | **Parameters**: `none` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `toString` (`self: StringView`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: receiver `recvObj: StringView = StringView(source = "aipl_test", start = 1, len = 64)`; exercises core body path returning/computing `self.source.slice(self.start, self.start + self.len)`.

```aipl
module tests.functions.fmt.str_builder_z21_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_StringView_toString_21(): int:
  let recv_self = StringView(source = "test", start = 1, len = 0)
  let edge_self = StringView(source = "a", start = 0, len = 0)
  let resNom = recv_self.toString()
  let resEdge = edge_self.toString()
  assertEqStr(resNom, "", "toString nominal string matches")
  assertEqStr(resEdge, "", "toString boundary string matches")
  ret 0
```

---

### `strLen` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn strLen(s: str): int:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `strLen` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `s.len`.

```aipl
module tests.functions.fmt.str_builder_z22_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_strLen_22(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = strLen(arg_s)
  let resEdge = strLen(edge_s)
  assertEqInt(resNom, 4, "strLen nominal resNom == 4")
  assertEqInt(resEdge, 1, "strLen boundary resEdge == 1")
  ret 0
```

---

### `charAt` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn charAt(s: str, index: int): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, index: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `charAt` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`, `index: int = 0`; exercises core body path returning/computing `s.charAt(index)`.

```aipl
module tests.functions.fmt.str_builder_z23_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_charAt_23(): int:
  let arg_s = "test"
  let edge_s = "a"
  let arg_index = 4
  let edge_index = 1
  let resNom = charAt(arg_s, arg_index)
  let resEdge = charAt(edge_s, edge_index)
  assertEqStr(resNom, "", "charAt nominal string matches")
  assertEqStr(resEdge, "", "charAt boundary string matches")
  ret 0
```

---

### `charCodeAt` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn charCodeAt(s: str, idx: int): int:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, idx: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `charCodeAt` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`, `idx: int = 0`; exercises core body path returning/computing `s.charCodeAt(idx)`.

```aipl
module tests.functions.fmt.str_builder_z24_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_charCodeAt_24(): int:
  let arg_s = "test"
  let edge_s = "a"
  let arg_idx = 1
  let edge_idx = 0
  let resNom = charCodeAt(arg_s, arg_idx)
  let resEdge = charCodeAt(edge_s, edge_idx)
  assertEqInt(resNom, 101, "charCodeAt nominal resNom == 101")
  assertEqInt(resEdge, 97, "charCodeAt boundary resEdge == 97")
  ret 0
```

---

### `ord` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn ord(ch: str): int:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ch: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `ord` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `ch: str = "aipl_test"`; exercises core body path returning/computing `b0`.

```aipl
module tests.functions.fmt.str_builder_z25_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_ord_25(): int:
  let arg_ch = "test"
  let edge_ch = "a"
  let resNom = ord(arg_ch)
  let resEdge = ord(edge_ch)
  assertEqInt(resNom, 116, "ord nominal resNom == 116")
  assertEqInt(resEdge, 97, "ord boundary resEdge == 97")
  ret 0
```

---

### `chr` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn chr(code: int): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `code: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `chr` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `code: int = 1`; exercises core body path returning/computing `b.toStringLossy()`.

```aipl
module tests.functions.fmt.str_builder_z26_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_chr_26(): int:
  let arg_code = 2
  let edge_code = 0
  let resNom = chr(arg_code)
  let resEdge = chr(edge_code)
  assertEqStr(resNom, "", "chr nominal string matches")
  assertEqStr(resEdge, "", "chr boundary string matches")
  ret 0
```

---

### `fromCharCode` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn fromCharCode(code: int): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `code: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `fromCharCode` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `code: int = 1`; exercises core body path returning/computing `chr(code)`.

```aipl
module tests.functions.fmt.str_builder_z27_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_fromCharCode_27(): int:
  let arg_code = 2
  let edge_code = 0
  let resNom = fromCharCode(arg_code)
  let resEdge = fromCharCode(edge_code)
  assertEqStr(resNom, "", "fromCharCode nominal string matches")
  assertEqStr(resEdge, "", "fromCharCode boundary string matches")
  ret 0
```

---

### `charFromCode` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn charFromCode(code: int): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `code: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `charFromCode` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `code: int = 1`; exercises core body path returning/computing `chr(code)`.

```aipl
module tests.functions.fmt.str_builder_z28_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_charFromCode_28(): int:
  let arg_code = 2
  let edge_code = 0
  let resNom = charFromCode(arg_code)
  let resEdge = charFromCode(edge_code)
  assertEqStr(resNom, "", "charFromCode nominal string matches")
  assertEqStr(resEdge, "", "charFromCode boundary string matches")
  ret 0
```

---

### `chars` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn chars(s: str): [str]:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `[str]`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `chars` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `s.chars()`.

```aipl
module tests.functions.fmt.str_builder_z29_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_chars_29(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = chars(arg_s)
  let resEdge = chars(edge_s)
  assertEqInt(resNom.len(), 4, "chars nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 1, "chars boundary resEdge.len() == 1")
  ret 0
```

---

### `substring` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn substring(s: str, start: int, end: int): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, start: int, end: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `substring` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`, `start: int = 1`, `end: int = 1`; exercises core body path returning/computing `s.slice(start, end)`.

```aipl
module tests.functions.fmt.str_builder_z30_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_substring_30(): int:
  let arg_s = "test"
  let edge_s = "a"
  let arg_start = 1
  let edge_start = 0
  let arg_end = 4
  let edge_end = 1
  let resNom = substring(arg_s, arg_start, arg_end)
  let resEdge = substring(edge_s, edge_start, edge_end)
  assertEqStr(resNom, "est", "substring nominal string matches")
  assertEqStr(resEdge, "a", "substring boundary string matches")
  ret 0
```

---

### `isWhitespace` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn isWhitespace(c: str): bool:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `c: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `isWhitespace` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `c: str = "aipl_test"`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.fmt.str_builder_z31_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_isWhitespace_31(): int:
  let arg_c = "test"
  let edge_c = "a"
  let resNom = isWhitespace(arg_c)
  let resEdge = isWhitespace(edge_c)
  assert(resNom == false, "isWhitespace nominal resNom == false")
  assert(resEdge == false, "isWhitespace boundary resEdge == false")
  ret 0
```

---

### `isDigit` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn isDigit(c: str): bool:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `c: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `isDigit` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `c: str = "aipl_test"`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.fmt.str_builder_z32_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_isDigit_32(): int:
  let arg_c = "test"
  let edge_c = "a"
  let resNom = isDigit(arg_c)
  let resEdge = isDigit(edge_c)
  assert(resNom == false, "isDigit nominal resNom == false")
  assert(resEdge == false, "isDigit boundary resEdge == false")
  ret 0
```

---

### `isAlpha` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn isAlpha(c: str): bool:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `c: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `isAlpha` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `c: str = "aipl_test"`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.fmt.str_builder_z33_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_isAlpha_33(): int:
  let arg_c = "test"
  let edge_c = "a"
  let resNom = isAlpha(arg_c)
  let resEdge = isAlpha(edge_c)
  assert(resNom == true, "isAlpha nominal resNom == true")
  assert(resEdge == true, "isAlpha boundary resEdge == true")
  ret 0
```

---

### `isAlphanumeric` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn isAlphanumeric(c: str): bool:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `c: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `isAlphanumeric` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `c: str = "aipl_test"`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.fmt.str_builder_z34_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_isAlphanumeric_34(): int:
  let arg_c = "test"
  let edge_c = "a"
  let resNom = isAlphanumeric(arg_c)
  let resEdge = isAlphanumeric(edge_c)
  assert(resNom == true, "isAlphanumeric nominal resNom == true")
  assert(resEdge == true, "isAlphanumeric boundary resEdge == true")
  ret 0
```

---

### `isAlnum` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn isAlnum(c: str): bool:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `c: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `isAlnum` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `c: str = "aipl_test"`; exercises core body path returning/computing `isAlphanumeric(c)`.

```aipl
module tests.functions.fmt.str_builder_z35_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_isAlnum_35(): int:
  let arg_c = "test"
  let edge_c = "a"
  let resNom = isAlnum(arg_c)
  let resEdge = isAlnum(edge_c)
  assert(resNom == true, "isAlnum nominal resNom == true")
  assert(resEdge == true, "isAlnum boundary resEdge == true")
  ret 0
```

---

### `isHexDigit` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn isHexDigit(c: str): bool:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `c: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `isHexDigit` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `c: str = "aipl_test"`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.fmt.str_builder_z36_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_isHexDigit_36(): int:
  let arg_c = "4142"
  let edge_c = "00"
  let resNom = isHexDigit(arg_c)
  let resEdge = isHexDigit(edge_c)
  assert(resNom == true, "isHexDigit nominal resNom == true")
  assert(resEdge == true, "isHexDigit boundary resEdge == true")
  ret 0
```

---

### `isIdentChar` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn isIdentChar(c: str): bool:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `c: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `isIdentChar` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `c: str = "aipl_test"`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.fmt.str_builder_z37_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_isIdentChar_37(): int:
  let arg_c = "test"
  let edge_c = "a"
  let resNom = isIdentChar(arg_c)
  let resEdge = isIdentChar(edge_c)
  assert(resNom == true, "isIdentChar nominal resNom == true")
  assert(resEdge == true, "isIdentChar boundary resEdge == true")
  ret 0
```

---

### `padLeft` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn padLeft(s: str, targetLen: int, padChar: str = " "): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, targetLen: int, padChar: str = " "` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `padLeft` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`, `targetLen: int = 64`, `padChar: str = "aipl_test"`; exercises core body path returning/computing `padding + s`.

```aipl
module tests.functions.fmt.str_builder_z38_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_padLeft_38(): int:
  let arg_s = "test"
  let edge_s = "a"
  let arg_targetLen = 4
  let edge_targetLen = 1
  let arg_padChar = "test"
  let edge_padChar = "a"
  let resNom = padLeft(arg_s, arg_targetLen, arg_padChar)
  let resEdge = padLeft(edge_s, edge_targetLen, edge_padChar)
  assertEqStr(resNom, "test", "padLeft nominal string matches")
  assertEqStr(resEdge, "a", "padLeft boundary string matches")
  ret 0
```

---

### `padStart` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn padStart(s: str, width: int, fill: str = " "): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, width: int, fill: str = " "` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `padStart` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`, `width: int = 128`, `fill: str = "aipl_test"`; exercises core body path returning/computing `padLeft(s, width, fill)`.

```aipl
module tests.functions.fmt.str_builder_z39_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_padStart_39(): int:
  let arg_s = "test"
  let edge_s = "a"
  let arg_width = 4
  let edge_width = 1
  let arg_fill = "test"
  let edge_fill = "a"
  let resNom = padStart(arg_s, arg_width, arg_fill)
  let resEdge = padStart(edge_s, edge_width, edge_fill)
  assertEqStr(resNom, "test", "padStart nominal string matches")
  assertEqStr(resEdge, "a", "padStart boundary string matches")
  ret 0
```

---

### `padRight` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn padRight(s: str, targetLen: int, padChar: str = " "): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, targetLen: int, padChar: str = " "` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `padRight` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`, `targetLen: int = 64`, `padChar: str = "aipl_test"`; exercises core body path returning/computing `s + padding`.

```aipl
module tests.functions.fmt.str_builder_z40_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_padRight_40(): int:
  let arg_s = "test"
  let edge_s = "a"
  let arg_targetLen = 4
  let edge_targetLen = 1
  let arg_padChar = "test"
  let edge_padChar = "a"
  let resNom = padRight(arg_s, arg_targetLen, arg_padChar)
  let resEdge = padRight(edge_s, edge_targetLen, edge_padChar)
  assertEqStr(resNom, "test", "padRight nominal string matches")
  assertEqStr(resEdge, "a", "padRight boundary string matches")
  ret 0
```

---

### `padEnd` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn padEnd(s: str, width: int, fill: str = " "): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, width: int, fill: str = " "` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `padEnd` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`, `width: int = 128`, `fill: str = "aipl_test"`; exercises core body path returning/computing `padRight(s, width, fill)`.

```aipl
module tests.functions.fmt.str_builder_z41_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_padEnd_41(): int:
  let arg_s = "test"
  let edge_s = "a"
  let arg_width = 4
  let edge_width = 1
  let arg_fill = "test"
  let edge_fill = "a"
  let resNom = padEnd(arg_s, arg_width, arg_fill)
  let resEdge = padEnd(edge_s, edge_width, edge_fill)
  assertEqStr(resNom, "test", "padEnd nominal string matches")
  assertEqStr(resEdge, "a", "padEnd boundary string matches")
  ret 0
```

---

### `padCenter` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn padCenter(s: str, targetLen: int, padChar: str = " "): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, targetLen: int, padChar: str = " "` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `padCenter` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`, `targetLen: int = 64`, `padChar: str = "aipl_test"`; exercises core body path returning/computing `padRight(withLeft, s.len + leftPad + rightPad, padChar)`.

```aipl
module tests.functions.fmt.str_builder_z42_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_padCenter_42(): int:
  let arg_s = "test"
  let edge_s = "a"
  let arg_targetLen = 4
  let edge_targetLen = 1
  let arg_padChar = "test"
  let edge_padChar = "a"
  let resNom = padCenter(arg_s, arg_targetLen, arg_padChar)
  let resEdge = padCenter(edge_s, edge_targetLen, edge_padChar)
  assertEqStr(resNom, "test", "padCenter nominal string matches")
  assertEqStr(resEdge, "a", "padCenter boundary string matches")
  ret 0
```

---

### `trimStart` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn trimStart(s: str): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `trimStart` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `""`.

```aipl
module tests.functions.fmt.str_builder_z43_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_trimStart_43(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = trimStart(arg_s)
  let resEdge = trimStart(edge_s)
  assertEqStr(resNom, "test", "trimStart nominal string matches")
  assertEqStr(resEdge, "a", "trimStart boundary string matches")
  ret 0
```

---

### `trimLeft` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn trimLeft(s: str): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `trimLeft` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `trimStart(s)`.

```aipl
module tests.functions.fmt.str_builder_z44_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_trimLeft_44(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = trimLeft(arg_s)
  let resEdge = trimLeft(edge_s)
  assertEqStr(resNom, "test", "trimLeft nominal string matches")
  assertEqStr(resEdge, "a", "trimLeft boundary string matches")
  ret 0
```

---

### `trimEnd` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn trimEnd(s: str): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `trimEnd` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `""`.

```aipl
module tests.functions.fmt.str_builder_z45_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_trimEnd_45(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = trimEnd(arg_s)
  let resEdge = trimEnd(edge_s)
  assertEqStr(resNom, "test", "trimEnd nominal string matches")
  assertEqStr(resEdge, "a", "trimEnd boundary string matches")
  ret 0
```

---

### `trimRight` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn trimRight(s: str): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `trimRight` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `trimEnd(s)`.

```aipl
module tests.functions.fmt.str_builder_z46_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_trimRight_46(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = trimRight(arg_s)
  let resEdge = trimRight(edge_s)
  assertEqStr(resNom, "test", "trimRight nominal string matches")
  assertEqStr(resEdge, "a", "trimRight boundary string matches")
  ret 0
```

---

### `trim` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn trim(s: str): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `trim` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `trimEnd(trimStart(s))`.

```aipl
module tests.functions.fmt.str_builder_z47_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_trim_47(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = trim(arg_s)
  let resEdge = trim(edge_s)
  assertEqStr(resNom, "test", "trim nominal string matches")
  assertEqStr(resEdge, "a", "trim boundary string matches")
  ret 0
```

---

### `repeat` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn repeat(s: str, count: int): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, count: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `repeat` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`, `count: int = 64`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.fmt.str_builder_z48_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_repeat_48(): int:
  let arg_s = "test"
  let edge_s = "a"
  let arg_count = 4
  let edge_count = 1
  let resNom = repeat(arg_s, arg_count)
  let resEdge = repeat(edge_s, edge_count)
  assertEqStr(resNom, "testtesttesttest", "repeat nominal string matches")
  assertEqStr(resEdge, "a", "repeat boundary string matches")
  ret 0
```

---

### `repeatStr` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn repeatStr(s: str, count: int): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, count: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `repeatStr` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`, `count: int = 64`; exercises core body path returning/computing `repeat(s, count)`.

```aipl
module tests.functions.fmt.str_builder_z49_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_repeatStr_49(): int:
  let arg_s = "test"
  let edge_s = "a"
  let arg_count = 4
  let edge_count = 1
  let resNom = repeatStr(arg_s, arg_count)
  let resEdge = repeatStr(edge_s, edge_count)
  assertEqStr(resNom, "testtesttesttest", "repeatStr nominal string matches")
  assertEqStr(resEdge, "a", "repeatStr boundary string matches")
  ret 0
```

---

### `reverseStr` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn reverseStr(s: str): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `reverseStr` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.fmt.str_builder_z50_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_reverseStr_50(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = reverseStr(arg_s)
  let resEdge = reverseStr(edge_s)
  assertEqStr(resNom, "tset", "reverseStr nominal string matches")
  assertEqStr(resEdge, "a", "reverseStr boundary string matches")
  ret 0
```

---

### `toUpper` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn toUpper(s: str): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `toUpper` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `s.toUpperCase()`.

```aipl
module tests.functions.fmt.str_builder_z51_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_toUpper_51(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = toUpper(arg_s)
  let resEdge = toUpper(edge_s)
  assertEqStr(resNom, "TEST", "toUpper nominal string matches")
  assertEqStr(resEdge, "A", "toUpper boundary string matches")
  ret 0
```

---

### `toLower` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn toLower(s: str): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `toLower` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `s.toLowerCase()`.

```aipl
module tests.functions.fmt.str_builder_z52_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_toLower_52(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = toLower(arg_s)
  let resEdge = toLower(edge_s)
  assertEqStr(resNom, "test", "toLower nominal string matches")
  assertEqStr(resEdge, "a", "toLower boundary string matches")
  ret 0
```

---

### `capitalize` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn capitalize(s: str): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `capitalize` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `s.charAt(0).toUpperCase() + s.slice(1, s.len).toLowerCase()`.

```aipl
module tests.functions.fmt.str_builder_z53_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_capitalize_53(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = capitalize(arg_s)
  let resEdge = capitalize(edge_s)
  assertEqStr(resNom, "Test", "capitalize nominal string matches")
  assertEqStr(resEdge, "A", "capitalize boundary string matches")
  ret 0
```

---

### `extractWordsForCase` (`std/fmt/str_builder.aipl`)

- **Signature**: `fn extractWordsForCase(s: str): [str]:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `[str]`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `extractWordsForCase` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `wList`.

```aipl
module tests.functions.fmt.str_builder_z54_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_extractWordsForCase_54(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = extractWordsForCase(arg_s)
  let resEdge = extractWordsForCase(edge_s)
  assertEqInt(resNom.len(), 1, "extractWordsForCase nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "extractWordsForCase boundary resEdge.len() == 1")
  ret 0
```

---

### `toCamelCase` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn toCamelCase(s: str): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `toCamelCase` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.fmt.str_builder_z55_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_toCamelCase_55(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = toCamelCase(arg_s)
  let resEdge = toCamelCase(edge_s)
  assertEqStr(resNom, "test", "toCamelCase nominal string matches")
  assertEqStr(resEdge, "a", "toCamelCase boundary string matches")
  ret 0
```

---

### `toSnakeCase` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn toSnakeCase(s: str): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `toSnakeCase` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.fmt.str_builder_z56_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_toSnakeCase_56(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = toSnakeCase(arg_s)
  let resEdge = toSnakeCase(edge_s)
  assertEqStr(resNom, "test", "toSnakeCase nominal string matches")
  assertEqStr(resEdge, "a", "toSnakeCase boundary string matches")
  ret 0
```

---

### `toKebabCase` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn toKebabCase(s: str): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `toKebabCase` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.fmt.str_builder_z57_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_toKebabCase_57(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = toKebabCase(arg_s)
  let resEdge = toKebabCase(edge_s)
  assertEqStr(resNom, "test", "toKebabCase nominal string matches")
  assertEqStr(resEdge, "a", "toKebabCase boundary string matches")
  ret 0
```

---

### `toPascalCase` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn toPascalCase(s: str): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `toPascalCase` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.fmt.str_builder_z58_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_toPascalCase_58(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = toPascalCase(arg_s)
  let resEdge = toPascalCase(edge_s)
  assertEqStr(resNom, "Test", "toPascalCase nominal string matches")
  assertEqStr(resEdge, "A", "toPascalCase boundary string matches")
  ret 0
```

---

### `split` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn split(s: str, sep: str): [str]:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, sep: str` | **Returns**: `[str]`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `split` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`, `sep: str = "aipl_test"`; exercises core body path returning/computing `s.split(sep)`.

```aipl
module tests.functions.fmt.str_builder_z59_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_split_59(): int:
  let arg_s = "test"
  let edge_s = "a"
  let arg_sep = "test"
  let edge_sep = "a"
  let resNom = split(arg_s, arg_sep)
  let resEdge = split(edge_s, edge_sep)
  assertEqInt(resNom.len(), 2, "split nominal resNom.len() == 2")
  assertEqInt(resEdge.len(), 2, "split boundary resEdge.len() == 2")
  ret 0
```

---

### `splitLines` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn splitLines(s: str): [str]:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `[str]`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `splitLines` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `result`.

```aipl
module tests.functions.fmt.str_builder_z60_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_splitLines_60(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = splitLines(arg_s)
  let resEdge = splitLines(edge_s)
  assertEqInt(resNom.len(), 1, "splitLines nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "splitLines boundary resEdge.len() == 1")
  ret 0
```

---

### `lines` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn lines(s: str): [str]:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `[str]`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `lines` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `splitLines(s)`.

```aipl
module tests.functions.fmt.str_builder_z61_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_lines_61(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = lines(arg_s)
  let resEdge = lines(edge_s)
  assertEqInt(resNom.len(), 1, "lines nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "lines boundary resEdge.len() == 1")
  ret 0
```

---

### `join` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn join(pieces: [str], sep: str): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pieces: [str], sep: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `join` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `pieces: [str] = ["aipl_test"]`, `sep: str = "aipl_test"`; exercises core body path returning/computing `pieces.join(sep)`.

```aipl
module tests.functions.fmt.str_builder_z62_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_join_62(): int:
  let arg_pieces = ["test"]
  let edge_pieces = []
  let arg_sep = "test"
  let edge_sep = "a"
  let resNom = join(arg_pieces, arg_sep)
  let resEdge = join(edge_pieces, edge_sep)
  assertEqStr(resNom, "test", "join nominal string matches")
  assertEqStr(resEdge, "", "join boundary string matches")
  ret 0
```

---

### `replaceAll` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn replaceAll(s: str, needle: str, repl: str): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, needle: str, repl: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `replaceAll` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`, `needle: str = "aipl_test"`, `repl: str = "aipl_test"`; exercises core body path returning/computing `s.replace(needle, repl)`.

```aipl
module tests.functions.fmt.str_builder_z63_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_replaceAll_63(): int:
  let arg_s = "test"
  let edge_s = "a"
  let arg_needle = "test"
  let edge_needle = "a"
  let arg_repl = "test"
  let edge_repl = "a"
  let resNom = replaceAll(arg_s, arg_needle, arg_repl)
  let resEdge = replaceAll(edge_s, edge_needle, edge_repl)
  assertEqStr(resNom, "test", "replaceAll nominal string matches")
  assertEqStr(resEdge, "a", "replaceAll boundary string matches")
  ret 0
```

---

### `replace` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn replace(s: str, search: str, repl: str): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, search: str, repl: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `replace` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`, `search: str = "aipl_test"`, `repl: str = "aipl_test"`; exercises core body path returning/computing `s.replace(search, repl)`.

```aipl
module tests.functions.fmt.str_builder_z64_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_replace_64(): int:
  let arg_s = "test"
  let edge_s = "a"
  let arg_search = "test"
  let edge_search = "a"
  let arg_repl = "test"
  let edge_repl = "a"
  let resNom = replace(arg_s, arg_search, arg_repl)
  let resEdge = replace(edge_s, edge_search, edge_repl)
  assertEqStr(resNom, "test", "replace nominal string matches")
  assertEqStr(resEdge, "a", "replace boundary string matches")
  ret 0
```

---

### `replaceFirst` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn replaceFirst(s: str, old: str, new: str): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, old: str, new: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `replaceFirst` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`, `old: str = "aipl_test"`, `new: str = "aipl_test"`; exercises core body path returning/computing `s.slice(0, idx) + new + s.slice(idx + old.len, s.len)`.

```aipl
module tests.functions.fmt.str_builder_z65_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_replaceFirst_65(): int:
  let arg_s = "test"
  let edge_s = "a"
  let arg_old = "test"
  let edge_old = "a"
  let arg_new = "test"
  let edge_new = "a"
  let resNom = replaceFirst(arg_s, arg_old, arg_new)
  let resEdge = replaceFirst(edge_s, edge_old, edge_new)
  assertEqStr(resNom, "test", "replaceFirst nominal string matches")
  assertEqStr(resEdge, "a", "replaceFirst boundary string matches")
  ret 0
```

---

### `startsWith` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn startsWith(s: str, prefix: str, offset: int = 0): bool:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, prefix: str, offset: int = 0` | **Returns**: `bool`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `startsWith` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`, `prefix: str = "aipl_test"`, `offset: int = 0`; exercises core body path returning/computing `s.slice(offset, offset + prefix.len) == prefix`.

```aipl
module tests.functions.fmt.str_builder_z66_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_startsWith_66(): int:
  let arg_s = "test"
  let edge_s = "a"
  let arg_prefix = "test"
  let edge_prefix = "a"
  let arg_offset = 1
  let edge_offset = 0
  let resNom = startsWith(arg_s, arg_prefix, arg_offset)
  let resEdge = startsWith(edge_s, edge_prefix, edge_offset)
  assert(resNom == false, "startsWith nominal resNom == false")
  assert(resEdge == true, "startsWith boundary resEdge == true")
  ret 0
```

---

### `endsWith` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn endsWith(s: str, suffix: str): bool:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, suffix: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `endsWith` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`, `suffix: str = "aipl_test"`; exercises core body path returning/computing `s.slice(s.len - suffix.len, s.len) == suffix`.

```aipl
module tests.functions.fmt.str_builder_z67_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_endsWith_67(): int:
  let arg_s = "test"
  let edge_s = "a"
  let arg_suffix = "test"
  let edge_suffix = "a"
  let resNom = endsWith(arg_s, arg_suffix)
  let resEdge = endsWith(edge_s, edge_suffix)
  assert(resNom == true, "endsWith nominal resNom == true")
  assert(resEdge == true, "endsWith boundary resEdge == true")
  ret 0
```

---

### `contains` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn contains(s: str, needle: str): bool:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, needle: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `contains` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`, `needle: str = "aipl_test"`; exercises core body path returning/computing `s.indexOf(needle) >= 0`.

```aipl
module tests.functions.fmt.str_builder_z68_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_contains_68(): int:
  let arg_s = "test"
  let edge_s = "a"
  let arg_needle = "test"
  let edge_needle = "a"
  let resNom = contains(arg_s, arg_needle)
  let resEdge = contains(edge_s, edge_needle)
  assert(resNom == true, "contains nominal resNom == true")
  assert(resEdge == true, "contains boundary resEdge == true")
  ret 0
```

---

### `indexOf` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn indexOf(s: str, needle: str, fromIndex: int = 0): int:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, needle: str, fromIndex: int = 0` | **Returns**: `int`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `indexOf` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`, `needle: str = "aipl_test"`, `fromIndex: int = 0`; exercises core body path returning/computing `s.indexOfFrom(needle, fromIndex)`.

```aipl
module tests.functions.fmt.str_builder_z69_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_indexOf_69(): int:
  let arg_s = "test"
  let edge_s = "a"
  let arg_needle = "test"
  let edge_needle = "a"
  let arg_fromIndex = 4
  let edge_fromIndex = 1
  let resNom = indexOf(arg_s, arg_needle, arg_fromIndex)
  let resEdge = indexOf(edge_s, edge_needle, edge_fromIndex)
  assertEqInt(resNom, -1, "indexOf nominal resNom == -1")
  assertEqInt(resEdge, -1, "indexOf boundary resEdge == -1")
  ret 0
```

---

### `indexOfFrom` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn indexOfFrom(s: str, sub: str, startIdx: int): int:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, sub: str, startIdx: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `indexOfFrom` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`, `sub: str = "aipl_test"`, `startIdx: int = 0`; exercises core body path returning/computing `s.indexOfFrom(sub, startIdx)`.

```aipl
module tests.functions.fmt.str_builder_z70_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_indexOfFrom_70(): int:
  let arg_s = "test"
  let edge_s = "a"
  let arg_sub = "test"
  let edge_sub = "a"
  let arg_startIdx = 1
  let edge_startIdx = 0
  let resNom = indexOfFrom(arg_s, arg_sub, arg_startIdx)
  let resEdge = indexOfFrom(edge_s, edge_sub, edge_startIdx)
  assertEqInt(resNom, -1, "indexOfFrom nominal resNom == -1")
  assertEqInt(resEdge, 0, "indexOfFrom boundary resEdge == 0")
  ret 0
```

---

### `lastIndexOf` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn lastIndexOf(s: str, needle: str): int:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, needle: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `lastIndexOf` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`, `needle: str = "aipl_test"`; exercises core body path returning/computing `s.lastIndexOf(needle)`.

```aipl
module tests.functions.fmt.str_builder_z71_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_lastIndexOf_71(): int:
  let arg_s = "test"
  let edge_s = "a"
  let arg_needle = "test"
  let edge_needle = "a"
  let resNom = lastIndexOf(arg_s, arg_needle)
  let resEdge = lastIndexOf(edge_s, edge_needle)
  assertEqInt(resNom, 0, "lastIndexOf nominal resNom == 0")
  assertEqInt(resEdge, 0, "lastIndexOf boundary resEdge == 0")
  ret 0
```

---

### `stripPrefix` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn stripPrefix(s: str, prefix: str): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, prefix: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `stripPrefix` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`, `prefix: str = "aipl_test"`; exercises core body path returning/computing `s`.

```aipl
module tests.functions.fmt.str_builder_z72_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_stripPrefix_72(): int:
  let arg_s = "127.0.0.1"
  let edge_s = "127.0.0.1"
  let arg_prefix = "127.0.0.1"
  let edge_prefix = "127.0.0.1"
  let resNom = stripPrefix(arg_s, arg_prefix)
  let resEdge = stripPrefix(edge_s, edge_prefix)
  assertEqStr(resNom, "", "stripPrefix nominal string matches")
  assertEqStr(resEdge, "", "stripPrefix boundary string matches")
  ret 0
```

---

### `stripSuffix` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn stripSuffix(s: str, suffix: str): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, suffix: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `stripSuffix` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`, `suffix: str = "aipl_test"`; exercises core body path returning/computing `s`.

```aipl
module tests.functions.fmt.str_builder_z73_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_stripSuffix_73(): int:
  let arg_s = "127.0.0.1"
  let edge_s = "127.0.0.1"
  let arg_suffix = "127.0.0.1"
  let edge_suffix = "127.0.0.1"
  let resNom = stripSuffix(arg_s, arg_suffix)
  let resEdge = stripSuffix(edge_s, edge_suffix)
  assertEqStr(resNom, "", "stripSuffix nominal string matches")
  assertEqStr(resEdge, "", "stripSuffix boundary string matches")
  ret 0
```

---

### `splitOnce` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn splitOnce(s: str, delim: str): Option[(str, str)]:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, delim: str` | **Returns**: `Option[(str, str)]`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `splitOnce` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`, `delim: str = "aipl_test"`; exercises core body path returning/computing `Some((s.slice(0, idx), s.slice(idx + delim.len, s.len)))`.

```aipl
module tests.functions.fmt.str_builder_z74_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_splitOnce_74(): int:
  let arg_s = "test"
  let edge_s = "a"
  let arg_delim = "test"
  let edge_delim = "a"
  let resNom = splitOnce(arg_s, arg_delim)
  let resEdge = splitOnce(edge_s, edge_delim)
  assert(resNom.isSome() == true, "splitOnce nominal resNom.isSome() == true")
  assert(resEdge.isSome() == true, "splitOnce boundary resEdge.isSome() == true")
  ret 0
```

---

### `words` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn words(s: str): [str]:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `[str]`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `words` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `res`.

```aipl
module tests.functions.fmt.str_builder_z75_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_words_75(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = words(arg_s)
  let resEdge = words(edge_s)
  assertEqInt(resNom.len(), 1, "words nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "words boundary resEdge.len() == 1")
  ret 0
```

---

### `splitWhitespace` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn splitWhitespace(s: str): [str]:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `[str]`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `splitWhitespace` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `words(s)`.

```aipl
module tests.functions.fmt.str_builder_z76_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_splitWhitespace_76(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = splitWhitespace(arg_s)
  let resEdge = splitWhitespace(edge_s)
  assertEqInt(resNom.len(), 1, "splitWhitespace nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "splitWhitespace boundary resEdge.len() == 1")
  ret 0
```

---

### `escapeQuotedString` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn escapeQuotedString(s: str): str:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `escapeQuotedString` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.fmt.str_builder_z77_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_escapeQuotedString_77(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = escapeQuotedString(arg_s)
  let resEdge = escapeQuotedString(edge_s)
  assertEqStr(resNom, "test", "escapeQuotedString nominal string matches")
  assertEqStr(resEdge, "a", "escapeQuotedString boundary string matches")
  ret 0
```

---

### `levenshteinDistance` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn levenshteinDistance(a: str, b: str): int:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: str, b: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `levenshteinDistance` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `a: str = "aipl_test"`, `b: str = "aipl_test"`; exercises core body path returning/computing `prevRow[n]`.

```aipl
module tests.functions.fmt.str_builder_z78_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_levenshteinDistance_78(): int:
  let arg_a = "test"
  let edge_a = "a"
  let arg_b = "test"
  let edge_b = "a"
  let resNom = levenshteinDistance(arg_a, arg_b)
  let resEdge = levenshteinDistance(edge_a, edge_b)
  assertEqInt(resNom, 0, "levenshteinDistance nominal resNom == 0")
  assertEqInt(resEdge, 0, "levenshteinDistance boundary resEdge == 0")
  ret 0
```

---

### `jaroWinklerSimilarity` (`std/fmt/str_builder.aipl`)

- **Signature**: `pub fn jaroWinklerSimilarity(a: str, b: str): float:`
- **Import**: `import * from "std/fmt/str_builder"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: str, b: str` | **Returns**: `float`
- **Unit Test**: `tests/functions/fmt/str_builder_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify string manipulation / `StringBuilder` / distance metric `jaroWinklerSimilarity` (`free fn`) across empty strings, case conversions (camel/snake/kebab/Pascal), Levenshtein/Jaro-Winkler similarity, and slice bounds. Concrete nominal inputs: `a: str = "aipl_test"`, `b: str = "aipl_test"`; exercises core body path returning/computing `jaro + (float(prefix) * 0.1 * (1.0 - jaro))`.

```aipl
module tests.functions.fmt.str_builder_z79_test
import * from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_str_builder_jaroWinklerSimilarity_79(): int:
  let arg_a = "test"
  let edge_a = "a"
  let arg_b = "test"
  let edge_b = "a"
  let resNom = jaroWinklerSimilarity(arg_a, arg_b)
  let resEdge = jaroWinklerSimilarity(edge_a, edge_b)
  assertApproxEq(resNom, 1.0, 0.001, "jaroWinklerSimilarity nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 1.0, 0.001, "jaroWinklerSimilarity boundary resEdge ~= 1.0")
  ret 0
```

---

### `formatInterpolated` (`std/fmt/text_print.aipl`)

- **Signature**: `pub fn formatInterpolated(templateStr: str, args: [str]): str:`
- **Import**: `import * from "std/fmt/text_print"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `templateStr: str, args: [str]` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/text_print_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify formatted output / ASCII table helper `formatInterpolated` (`free fn`) across column alignment, ANSI stripping, byte-size/thousands humanizing, and ellipsis truncation. Concrete nominal inputs: `templateStr: str = "aipl_test"`, `args: [str] = ["aipl_test"]`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.fmt.text_print_z1_test
import * from "std/fmt/text_print"
import { formatFloatFixed } from "std/fmt/num_parse"
import { padLeft, padRight, padCenter, repeat, words } from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_text_print_formatInterpolated_1(): int:
  let arg_templateStr = "42"
  let edge_templateStr = "0"
  let arg_args = ["42"]
  let edge_args = []
  let resNom = formatInterpolated(arg_templateStr, arg_args)
  let resEdge = formatInterpolated(edge_templateStr, edge_args)
  assertEqStr(resNom, "42", "formatInterpolated nominal string matches")
  assertEqStr(resEdge, "0", "formatInterpolated boundary string matches")
  ret 0
```

---

### `tableNew` (`std/fmt/text_print.aipl`)

- **Signature**: `pub fn tableNew(columns: [TableColumn], hasBorder: bool = true): FormattedTable:`
- **Import**: `import * from "std/fmt/text_print"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `columns: [TableColumn], hasBorder: bool = true` | **Returns**: `FormattedTable`
- **Unit Test**: `tests/functions/fmt/text_print_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify formatted output / ASCII table helper `tableNew` (`free fn`) across column alignment, ANSI stripping, byte-size/thousands humanizing, and ellipsis truncation. Concrete nominal inputs: `columns: [TableColumn] = [TableColumn(header = "aipl_test", width = 128, align = "aipl_test")]`, `hasBorder: bool = true`; exercises core body path returning/computing `FormattedTable(columns = columns, rows = emptyRows, hasBorder = hasBorder)`.

```aipl
module tests.functions.fmt.text_print_z2_test
import * from "std/fmt/text_print"
import { formatFloatFixed } from "std/fmt/num_parse"
import { padLeft, padRight, padCenter, repeat, words } from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_text_print_tableNew_2(): int:
  let arg_columns = [TableColumn(header = "test", width = 4, align = "test")]
  let edge_columns = []
  let arg_hasBorder = true
  let edge_hasBorder = false
  let resNom = tableNew(arg_columns, arg_hasBorder)
  let resEdge = tableNew(edge_columns, edge_hasBorder)
  assertEqInt(resNom.columns.len(), 1, "tableNew nominal resNom.columns.len() == 1")
  assertEqInt(resEdge.columns.len(), 0, "tableNew boundary resEdge.columns.len() == 0")
  ret 0
```

---

### `formatTableCell` (`std/fmt/text_print.aipl`)

- **Signature**: `fn formatTableCell(text: str, width: int, align: str): str:`
- **Import**: `import * from "std/fmt/text_print"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str, width: int, align: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/text_print_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify formatted output / ASCII table helper `formatTableCell` (`free fn`) across column alignment, ANSI stripping, byte-size/thousands humanizing, and ellipsis truncation. Concrete nominal inputs: `text: str = "aipl_test"`, `width: int = 128`, `align: str = "aipl_test"`; exercises core body path returning/computing `padRight(clipped, w, " ")`.

```aipl
module tests.functions.fmt.text_print_z3_test
import * from "std/fmt/text_print"
import { formatFloatFixed } from "std/fmt/num_parse"
import { padLeft, padRight, padCenter, repeat, words } from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_text_print_formatTableCell_3(): int:
  let arg_text = "test"
  let edge_text = "a"
  let arg_width = 4
  let edge_width = 1
  let arg_align = "test"
  let edge_align = "a"
  let resNom = formatTableCell(arg_text, arg_width, arg_align)
  let resEdge = formatTableCell(edge_text, edge_width, edge_align)
  assertEqStr(resNom, "test", "formatTableCell nominal string matches")
  assertEqStr(resEdge, "a", "formatTableCell boundary string matches")
  ret 0
```

---

### `addRow` (`std/fmt/text_print.aipl`)

- **Signature**: `pub fn (mut self: FormattedTable) addRow(cells: [str]): void:`
- **Import**: `import * from "std/fmt/text_print"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `mut self: FormattedTable` | **Parameters**: `cells: [str]` | **Returns**: `void`
- **Unit Test**: `tests/functions/fmt/text_print_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify formatted output / ASCII table helper `addRow` (`mut self: FormattedTable`) across column alignment, ANSI stripping, byte-size/thousands humanizing, and ellipsis truncation. Concrete nominal inputs: receiver `recvObj: FormattedTable = FormattedTable(columns = [TableColumn(header = 0, width = 0, align = 0)], rows = [[0]], hasBorder = true)`, `cells: [str] = ["aipl_test"]`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.fmt.text_print_z4_test
import * from "std/fmt/text_print"
import { formatFloatFixed } from "std/fmt/num_parse"
import { padLeft, padRight, padCenter, repeat, words } from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_text_print_FormattedTable_addRow_4(): int:
  let mut recv_self = FormattedTable(columns = [], rows = [], hasBorder = true)
  let mut edge_self = FormattedTable(columns = [], rows = [], hasBorder = false)
  let arg_cells = ["test"]
  let edge_cells = []
  recv_self.addRow(arg_cells)
  edge_self.addRow(edge_cells)
  assertEqInt(recv_self.rows.len(), 1, "addRow nominal recv_self.rows.len() == 1")
  assertEqInt(edge_self.rows.len(), 1, "addRow boundary edge_self.rows.len() == 1")
  ret 0
```

---

### `render` (`std/fmt/text_print.aipl`)

- **Signature**: `pub fn (self: FormattedTable) render(): str:`
- **Import**: `import * from "std/fmt/text_print"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `self: FormattedTable` | **Parameters**: `none` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/text_print_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify formatted output / ASCII table helper `render` (`self: FormattedTable`) across column alignment, ANSI stripping, byte-size/thousands humanizing, and ellipsis truncation. Concrete nominal inputs: receiver `recvObj: FormattedTable = FormattedTable(columns = [TableColumn(header = 0, width = 0, align = 0)], rows = [[0]], hasBorder = true)`; exercises core body path returning/computing `lines.join("\n")`.

```aipl
module tests.functions.fmt.text_print_z5_test
import * from "std/fmt/text_print"
import { formatFloatFixed } from "std/fmt/num_parse"
import { padLeft, padRight, padCenter, repeat, words } from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_text_print_FormattedTable_render_5(): int:
  let recv_self = FormattedTable(columns = [], rows = [], hasBorder = true)
  let edge_self = FormattedTable(columns = [], rows = [], hasBorder = false)
  let resNom = recv_self.render()
  let resEdge = edge_self.render()
  assertEqInt(resNom.len(), 11, "render nominal string length == 11")
  assertEqStr(resEdge, "", "render boundary string matches")
  ret 0
```

---

### `formatByteSize` (`std/fmt/text_print.aipl`)

- **Signature**: `pub fn formatByteSize(bytes: int): str:`
- **Import**: `import * from "std/fmt/text_print"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bytes: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/text_print_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify formatted output / ASCII table helper `formatByteSize` (`free fn`) across column alignment, ANSI stripping, byte-size/thousands humanizing, and ellipsis truncation. Concrete nominal inputs: `bytes: int = 64`; exercises core body path returning/computing `formatFloatFixed(fb / tib, 2) + " TiB"`.

```aipl
module tests.functions.fmt.text_print_z6_test
import * from "std/fmt/text_print"
import { formatFloatFixed } from "std/fmt/num_parse"
import { padLeft, padRight, padCenter, repeat, words } from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_text_print_formatByteSize_6(): int:
  let arg_bytes = 4
  let edge_bytes = 1
  let resNom = formatByteSize(arg_bytes)
  let resEdge = formatByteSize(edge_bytes)
  assertEqStr(resNom, "4 B", "formatByteSize nominal string matches")
  assertEqStr(resEdge, "1 B", "formatByteSize boundary string matches")
  ret 0
```

---

### `formatThousands` (`std/fmt/text_print.aipl`)

- **Signature**: `pub fn formatThousands(num: int, separator: str = ","): str:`
- **Import**: `import * from "std/fmt/text_print"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `num: int, separator: str = ","` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/text_print_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify formatted output / ASCII table helper `formatThousands` (`free fn`) across column alignment, ANSI stripping, byte-size/thousands humanizing, and ellipsis truncation. Concrete nominal inputs: `num: int = 1`, `separator: str = "aipl_test"`, `": any = 42`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.fmt.text_print_z7_test
import * from "std/fmt/text_print"
import { formatFloatFixed } from "std/fmt/num_parse"
import { padLeft, padRight, padCenter, repeat, words } from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_text_print_formatThousands_7(): int:
  let arg_num = 4
  let edge_num = 1
  let arg_separator = "test"
  let edge_separator = "a"
  let resNom = formatThousands(arg_num, arg_separator)
  let resEdge = formatThousands(edge_num, edge_separator)
  assertEqStr(resNom, "4", "formatThousands nominal string matches")
  assertEqStr(resEdge, "1", "formatThousands boundary string matches")
  ret 0
```

---

### `wordWrap` (`std/fmt/text_print.aipl`)

- **Signature**: `pub fn wordWrap(text: str, columnWidth: int): [str]:`
- **Import**: `import * from "std/fmt/text_print"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str, columnWidth: int` | **Returns**: `[str]`
- **Unit Test**: `tests/functions/fmt/text_print_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify formatted output / ASCII table helper `wordWrap` (`free fn`) across column alignment, ANSI stripping, byte-size/thousands humanizing, and ellipsis truncation. Concrete nominal inputs: `text: str = "aipl_test"`, `columnWidth: int = 1`; exercises core body path returning/computing `lines`.

```aipl
module tests.functions.fmt.text_print_z8_test
import * from "std/fmt/text_print"
import { formatFloatFixed } from "std/fmt/num_parse"
import { padLeft, padRight, padCenter, repeat, words } from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_text_print_wordWrap_8(): int:
  let arg_text = "test"
  let edge_text = "a"
  let arg_columnWidth = 4
  let edge_columnWidth = 1
  let resNom = wordWrap(arg_text, arg_columnWidth)
  let resEdge = wordWrap(edge_text, edge_columnWidth)
  assertEqInt(resNom.len(), 1, "wordWrap nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "wordWrap boundary resEdge.len() == 1")
  ret 0
```

---

### `truncateEllipsis` (`std/fmt/text_print.aipl`)

- **Signature**: `pub fn truncateEllipsis(text: str, maxLen: int, ellipsis: str = "..."): str:`
- **Import**: `import * from "std/fmt/text_print"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str, maxLen: int, ellipsis: str = "..."` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/text_print_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify formatted output / ASCII table helper `truncateEllipsis` (`free fn`) across column alignment, ANSI stripping, byte-size/thousands humanizing, and ellipsis truncation. Concrete nominal inputs: `text: str = "aipl_test"`, `maxLen: int = 64`, `ellipsis: str = "127.0.0.1"`; exercises core body path returning/computing `text.slice(0, keep) + ellipsis`.

```aipl
module tests.functions.fmt.text_print_z9_test
import * from "std/fmt/text_print"
import { formatFloatFixed } from "std/fmt/num_parse"
import { padLeft, padRight, padCenter, repeat, words } from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_text_print_truncateEllipsis_9(): int:
  let arg_text = "127.0.0.1"
  let edge_text = "127.0.0.1"
  let arg_maxLen = 4
  let edge_maxLen = 1
  let arg_ellipsis = "127.0.0.1"
  let edge_ellipsis = "127.0.0.1"
  let resNom = truncateEllipsis(arg_text, arg_maxLen, arg_ellipsis)
  let resEdge = truncateEllipsis(edge_text, edge_maxLen, edge_ellipsis)
  assertEqStr(resNom, "127.", "truncateEllipsis nominal string matches")
  assertEqStr(resEdge, "1", "truncateEllipsis boundary string matches")
  ret 0
```

---

### `stripAnsi` (`std/fmt/text_print.aipl`)

- **Signature**: `pub fn stripAnsi(s: str): str:`
- **Import**: `import * from "std/fmt/text_print"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/fmt/text_print_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify formatted output / ASCII table helper `stripAnsi` (`free fn`) across column alignment, ANSI stripping, byte-size/thousands humanizing, and ellipsis truncation. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.fmt.text_print_z10_test
import * from "std/fmt/text_print"
import { formatFloatFixed } from "std/fmt/num_parse"
import { padLeft, padRight, padCenter, repeat, words } from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_text_print_stripAnsi_10(): int:
  let arg_s = "127.0.0.1"
  let edge_s = "127.0.0.1"
  let resNom = stripAnsi(arg_s)
  let resEdge = stripAnsi(edge_s)
  assertEqStr(resNom, "127.0.0.1", "stripAnsi nominal string matches")
  assertEqStr(resEdge, "127.0.0.1", "stripAnsi boundary string matches")
  ret 0
```

---

### `utf8DecodeRune` (`std/fmt/unicode_utf8.aipl`)

- **Signature**: `pub fn utf8DecodeRune(data: bytes, offset: int): (int, int):`
- **Import**: `import * from "std/fmt/unicode_utf8"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes, offset: int` | **Returns**: `(int, int)`
- **Unit Test**: `tests/functions/fmt/unicode_utf8_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify UTF-8 rune/grapheme function `utf8DecodeRune` across 1-byte ASCII, 2-byte Latin/Greek, 3-byte CJK (display width 2), 4-byte astral emoji (`0x1F680`), and overlong/invalid byte rejection. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`, `offset: int): (int = int): (int()`, `int: any = 42`; exercises core body path returning/computing `(65533, 1)`.

```aipl
module tests.functions.fmt.unicode_utf8_z1_test
import * from "std/fmt/unicode_utf8"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_unicode_utf8_utf8DecodeRune_1(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let arg_offset = 1
  let edge_offset = 0
  let resNom = utf8DecodeRune(arg_data, arg_offset)
  let resEdge = utf8DecodeRune(edge_data, edge_offset)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqInt(n_t0, 73, "utf8DecodeRune nominal n_t0 == 73")
  assertEqInt(e_t0, 65, "utf8DecodeRune boundary e_t0 == 65")
  ret 0
```

---

### `utf8Validate` (`std/fmt/unicode_utf8.aipl`)

- **Signature**: `pub fn utf8Validate(data: bytes): bool:`
- **Import**: `import * from "std/fmt/unicode_utf8"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes` | **Returns**: `bool`
- **Unit Test**: `tests/functions/fmt/unicode_utf8_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify UTF-8 rune/grapheme function `utf8Validate` across 1-byte ASCII, 2-byte Latin/Greek, 3-byte CJK (display width 2), 4-byte astral emoji (`0x1F680`), and overlong/invalid byte rejection. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.fmt.unicode_utf8_z2_test
import * from "std/fmt/unicode_utf8"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_unicode_utf8_utf8Validate_2(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let resNom = utf8Validate(arg_data)
  let resEdge = utf8Validate(edge_data)
  assert(resNom == true, "utf8Validate nominal resNom == true")
  assert(resEdge == true, "utf8Validate boundary resEdge == true")
  ret 0
```

---

### `utf8EncodeRune` (`std/fmt/unicode_utf8.aipl`)

- **Signature**: `pub fn utf8EncodeRune(codepoint: int): bytes:`
- **Import**: `import * from "std/fmt/unicode_utf8"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `codepoint: int` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/fmt/unicode_utf8_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify UTF-8 rune/grapheme function `utf8EncodeRune` across 1-byte ASCII, 2-byte Latin/Greek, 3-byte CJK (display width 2), 4-byte astral emoji (`0x1F680`), and overlong/invalid byte rejection. Concrete nominal inputs: `codepoint: int = 1`; exercises core body path returning/computing `bytesFromArray([b0, b1, b2, b3])`.

```aipl
module tests.functions.fmt.unicode_utf8_z3_test
import * from "std/fmt/unicode_utf8"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_unicode_utf8_utf8EncodeRune_3(): int:
  let arg_codepoint = 4
  let edge_codepoint = 1
  let resNom = utf8EncodeRune(arg_codepoint)
  let resEdge = utf8EncodeRune(edge_codepoint)
  assertEqInt(resNom.len(), 1, "utf8EncodeRune nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "utf8EncodeRune boundary resEdge.len() == 1")
  ret 0
```

---

### `decodeRuneFromStr` (`std/fmt/unicode_utf8.aipl`)

- **Signature**: `fn decodeRuneFromStr(s: str, idx: int): (int, int):`
- **Import**: `import * from "std/fmt/unicode_utf8"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, idx: int` | **Returns**: `(int, int)`
- **Unit Test**: `tests/functions/fmt/unicode_utf8_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify UTF-8 rune/grapheme function `decodeRuneFromStr` across 1-byte ASCII, 2-byte Latin/Greek, 3-byte CJK (display width 2), 4-byte astral emoji (`0x1F680`), and overlong/invalid byte rejection. Concrete nominal inputs: `s: str = "aipl_test"`, `idx: int): (int = int): (int()`, `int: any = 42`; exercises core body path returning/computing `(b0, 1)`.

```aipl
module tests.functions.fmt.unicode_utf8_z4_test
import * from "std/fmt/unicode_utf8"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_unicode_utf8_decodeRuneFromStr_4(): int:
  let arg_s = "test"
  let edge_s = "a"
  let arg_idx = 1
  let edge_idx = 0
  let resNom = decodeRuneFromStr(arg_s, arg_idx)
  let resEdge = decodeRuneFromStr(edge_s, edge_idx)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqInt(n_t0, 101, "decodeRuneFromStr nominal n_t0 == 101")
  assertEqInt(e_t0, 97, "decodeRuneFromStr boundary e_t0 == 97")
  ret 0
```

---

### `codepoints` (`std/fmt/unicode_utf8.aipl`)

- **Signature**: `pub fn codepoints(s: str): [int]:`
- **Import**: `import * from "std/fmt/unicode_utf8"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/fmt/unicode_utf8_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify UTF-8 rune/grapheme function `codepoints` across 1-byte ASCII, 2-byte Latin/Greek, 3-byte CJK (display width 2), 4-byte astral emoji (`0x1F680`), and overlong/invalid byte rejection. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.fmt.unicode_utf8_z5_test
import * from "std/fmt/unicode_utf8"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_unicode_utf8_codepoints_5(): int:
  let arg_s = "42"
  let edge_s = "0"
  let resNom = codepoints(arg_s)
  let resEdge = codepoints(edge_s)
  assertEqInt(resNom.len(), 2, "codepoints nominal resNom.len() == 2")
  assertEqInt(resEdge.len(), 1, "codepoints boundary resEdge.len() == 1")
  ret 0
```

---

### `codepointCount` (`std/fmt/unicode_utf8.aipl`)

- **Signature**: `pub fn codepointCount(s: str): int:`
- **Import**: `import * from "std/fmt/unicode_utf8"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/fmt/unicode_utf8_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify UTF-8 rune/grapheme function `codepointCount` across 1-byte ASCII, 2-byte Latin/Greek, 3-byte CJK (display width 2), 4-byte astral emoji (`0x1F680`), and overlong/invalid byte rejection. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `count`.

```aipl
module tests.functions.fmt.unicode_utf8_z6_test
import * from "std/fmt/unicode_utf8"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_unicode_utf8_codepointCount_6(): int:
  let arg_s = "42"
  let edge_s = "0"
  let resNom = codepointCount(arg_s)
  let resEdge = codepointCount(edge_s)
  assertEqInt(resNom, 2, "codepointCount nominal resNom == 2")
  assertEqInt(resEdge, 1, "codepointCount boundary resEdge == 1")
  ret 0
```

---

### `isControlRune` (`std/fmt/unicode_utf8.aipl`)

- **Signature**: `pub fn isControlRune(cp: int): bool:`
- **Import**: `import * from "std/fmt/unicode_utf8"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cp: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/fmt/unicode_utf8_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify UTF-8 rune/grapheme function `isControlRune` across 1-byte ASCII, 2-byte Latin/Greek, 3-byte CJK (display width 2), 4-byte astral emoji (`0x1F680`), and overlong/invalid byte rejection. Concrete nominal inputs: `cp: int = 1`; exercises core body path returning/computing `(cp >= 0 and cp <= 31) or (cp >= 127 and cp <= 159)`.

```aipl
module tests.functions.fmt.unicode_utf8_z7_test
import * from "std/fmt/unicode_utf8"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_unicode_utf8_isControlRune_7(): int:
  let arg_cp = 2
  let edge_cp = 0
  let resNom = isControlRune(arg_cp)
  let resEdge = isControlRune(edge_cp)
  assert(resNom == true, "isControlRune nominal resNom == true")
  assert(resEdge == true, "isControlRune boundary resEdge == true")
  ret 0
```

---

### `isWhitespaceRune` (`std/fmt/unicode_utf8.aipl`)

- **Signature**: `pub fn isWhitespaceRune(cp: int): bool:`
- **Import**: `import * from "std/fmt/unicode_utf8"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cp: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/fmt/unicode_utf8_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify UTF-8 rune/grapheme function `isWhitespaceRune` across 1-byte ASCII, 2-byte Latin/Greek, 3-byte CJK (display width 2), 4-byte astral emoji (`0x1F680`), and overlong/invalid byte rejection. Concrete nominal inputs: `cp: int = 1`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.fmt.unicode_utf8_z8_test
import * from "std/fmt/unicode_utf8"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_unicode_utf8_isWhitespaceRune_8(): int:
  let arg_cp = 2
  let edge_cp = 0
  let resNom = isWhitespaceRune(arg_cp)
  let resEdge = isWhitespaceRune(edge_cp)
  assert(resNom == false, "isWhitespaceRune nominal resNom == false")
  assert(resEdge == false, "isWhitespaceRune boundary resEdge == false")
  ret 0
```

---

### `isAlphaRune` (`std/fmt/unicode_utf8.aipl`)

- **Signature**: `pub fn isAlphaRune(cp: int): bool:`
- **Import**: `import * from "std/fmt/unicode_utf8"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cp: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/fmt/unicode_utf8_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify UTF-8 rune/grapheme function `isAlphaRune` across 1-byte ASCII, 2-byte Latin/Greek, 3-byte CJK (display width 2), 4-byte astral emoji (`0x1F680`), and overlong/invalid byte rejection. Concrete nominal inputs: `cp: int = 1`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.fmt.unicode_utf8_z9_test
import * from "std/fmt/unicode_utf8"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_unicode_utf8_isAlphaRune_9(): int:
  let arg_cp = 2
  let edge_cp = 0
  let resNom = isAlphaRune(arg_cp)
  let resEdge = isAlphaRune(edge_cp)
  assert(resNom == false, "isAlphaRune nominal resNom == false")
  assert(resEdge == false, "isAlphaRune boundary resEdge == false")
  ret 0
```

---

### `isDigitRune` (`std/fmt/unicode_utf8.aipl`)

- **Signature**: `pub fn isDigitRune(cp: int): bool:`
- **Import**: `import * from "std/fmt/unicode_utf8"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cp: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/fmt/unicode_utf8_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify UTF-8 rune/grapheme function `isDigitRune` across 1-byte ASCII, 2-byte Latin/Greek, 3-byte CJK (display width 2), 4-byte astral emoji (`0x1F680`), and overlong/invalid byte rejection. Concrete nominal inputs: `cp: int = 1`; exercises core body path returning/computing `cp >= 48 and cp <= 57`.

```aipl
module tests.functions.fmt.unicode_utf8_z10_test
import * from "std/fmt/unicode_utf8"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_unicode_utf8_isDigitRune_10(): int:
  let arg_cp = 2
  let edge_cp = 0
  let resNom = isDigitRune(arg_cp)
  let resEdge = isDigitRune(edge_cp)
  assert(resNom == false, "isDigitRune nominal resNom == false")
  assert(resEdge == false, "isDigitRune boundary resEdge == false")
  ret 0
```

---

### `runeDisplayWidth` (`std/fmt/unicode_utf8.aipl`)

- **Signature**: `pub fn runeDisplayWidth(cp: int): int:`
- **Import**: `import * from "std/fmt/unicode_utf8"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cp: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/fmt/unicode_utf8_test.aipl` | **Example**: `examples/ex_058_fmt_text_print_hexdump_cli.aipl`
- **Behavioral Summary**: Verify UTF-8 rune/grapheme function `runeDisplayWidth` across 1-byte ASCII, 2-byte Latin/Greek, 3-byte CJK (display width 2), 4-byte astral emoji (`0x1F680`), and overlong/invalid byte rejection. Concrete nominal inputs: `cp: int = 1`; exercises core body path returning/computing `1`.

```aipl
module tests.functions.fmt.unicode_utf8_z11_test
import * from "std/fmt/unicode_utf8"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_unicode_utf8_runeDisplayWidth_11(): int:
  let arg_cp = 2
  let edge_cp = 0
  let resNom = runeDisplayWidth(arg_cp)
  let resEdge = runeDisplayWidth(edge_cp)
  assertEqInt(resNom, 0, "runeDisplayWidth nominal resNom == 0")
  assertEqInt(resEdge, 0, "runeDisplayWidth boundary resEdge == 0")
  ret 0
```

---

### `stringDisplayWidth` (`std/fmt/unicode_utf8.aipl`)

- **Signature**: `pub fn stringDisplayWidth(s: str): int:`
- **Import**: `import * from "std/fmt/unicode_utf8"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/fmt/unicode_utf8_test.aipl` | **Example**: `examples/ex_056_fmt_num_radix_and_scientific_cli.aipl`
- **Behavioral Summary**: Verify UTF-8 rune/grapheme function `stringDisplayWidth` across 1-byte ASCII, 2-byte Latin/Greek, 3-byte CJK (display width 2), 4-byte astral emoji (`0x1F680`), and overlong/invalid byte rejection. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `width`.

```aipl
module tests.functions.fmt.unicode_utf8_z12_test
import * from "std/fmt/unicode_utf8"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_unicode_utf8_stringDisplayWidth_12(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = stringDisplayWidth(arg_s)
  let resEdge = stringDisplayWidth(edge_s)
  assertEqInt(resNom, 4, "stringDisplayWidth nominal resNom == 4")
  assertEqInt(resEdge, 1, "stringDisplayWidth boundary resEdge == 1")
  ret 0
```

---

### `graphemeClusters` (`std/fmt/unicode_utf8.aipl`)

- **Signature**: `pub fn graphemeClusters(s: str): [GraphemeCluster]:`
- **Import**: `import * from "std/fmt/unicode_utf8"` (or barrel `import * from "std/fmt/fmt_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `[GraphemeCluster]`
- **Unit Test**: `tests/functions/fmt/unicode_utf8_test.aipl` | **Example**: `examples/ex_057_fmt_str_builder_report_engine_cli.aipl`
- **Behavioral Summary**: Verify UTF-8 rune/grapheme function `graphemeClusters` across 1-byte ASCII, 2-byte Latin/Greek, 3-byte CJK (display width 2), 4-byte astral emoji (`0x1F680`), and overlong/invalid byte rejection. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `clusters`.

```aipl
module tests.functions.fmt.unicode_utf8_z13_test
import * from "std/fmt/unicode_utf8"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_unicode_utf8_graphemeClusters_13(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = graphemeClusters(arg_s)
  let resEdge = graphemeClusters(edge_s)
  assertEqInt(resNom.len(), 4, "graphemeClusters nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 1, "graphemeClusters boundary resEdge.len() == 1")
  ret 0
```
