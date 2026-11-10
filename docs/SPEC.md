# AIPL v0.9.0 Language Specification
**Single Source of Truth (SSOT)**

---

## 1. Introduction & Design Philosophy

The AI-Programming Language (AIPL) is the first systems and application programming language co-designed from the tokenomics level up for artificial intelligence coding agents and deterministic dual-backend compilation (TypeScript/WebGL vs. Wasm standalone).

Standard programming languages (Python, TypeScript, Rust, C++) impose substantial token overhead on Large Language Models (LLMs) due to keyword fragmentation, non-uniform casing, excessive punctuation, and ambiguous grammatical constructs. Furthermore, standard language runtimes rely either on nondeterministic garbage collection (GC pauses) or complex manual borrow semantics that impede rapid autonomous synthesis.

AIPL solves these challenges via three foundational tenets:
1. **Machine-Tractable Tokenomics**: Every keyword, primitive, and syntactic idiom is aligned with SentencePiece 256k subword tokenizers (e.g., Gemini, Gemma) to achieve a 60%+ empirical token reduction.
2. **Canonical Strictness**: Zero implicit coercion, strict boolean invariants, strict case conventions (`camelCase` for values, `PascalCase` for types), and explicit algebraic error propagation.
3. **Dual-Backend Determinism**: A unified frontend compiles to a Canonical High-Level Intermediate Representation (Canonical HIR) that bifurcates into high-fidelity TypeScript/React 19 or high-performance Linear WebAssembly with zero runtime GC pauses.

---

## 2. SentencePiece 256k Lexical Invariants

AIPL syntax is co-optimized for the 256,000-token vocabulary of modern transformer tokenizers (e.g., SentencePiece unigram models used in Gemini and Gemma). All source files are encoded in UTF-8 without byte-order marks.

### 2.1 Atomic Keywords
Every keyword in AIPL is selected to guarantee encoding as a single, indivisible token in SentencePiece 256k models:

```
fn       struct   system   component  shader   server
let      mut      pub      ret        return   if
else     match    for      in         while    with
arena    import   export   as         from     module
type     enum     interface break     continue and
or       not      true     false      nil      Ok
Err      div
```

Compound keywords common in other languages (such as `async function`, `pub(crate)`, `typedef`, `constexpr`) are strictly forbidden.

### 2.2 Digit-Free Primitives
All primitive types are strictly digit-free words to prevent subword split penalties:

| AIPL Primitive | Bit Width / Representation | Disallowed Multi-Token Equivalents |
| :--- | :--- | :--- |
| `int` | 64-bit signed integer | `i32`, `int32`, `i64`, `int64`, `isize` |
| `float` | 64-bit IEEE 754 floating point | `f32`, `float32`, `f64`, `float64` |
| `num` | Arbitrary-precision numeric | `number`, `decimal`, `BigInt` |
| `str` | UTF-8 immutable string | `string`, `String`, `char*` |
| `bool` | Boolean (`true` or `false`) | `boolean`, `bool_t` |
| `byte` | 8-bit unsigned integer (`0..255`) | `u8`, `uint8`, `char`, `unsigned char` |
| `void` | Empty return type (no value) | `None`, `Unit`, `()` |
| `nil` | Unit / nullary pointer value | `null`, `None`, `undefined`, `nullptr` |

Fixed-width hardware representations for buffers, uniforms, and WebGPU vertex layouts use parameterization syntax: `int[32]`, `float[32]`, `byte[4]`.

### 2.3 Whitespace Absorption & 2-Space Indentation Offside Rule
AIPL utilizes the offside rule with strict 2-space indentation:
- Tab characters (`\t`) are strictly illegal in indentation or code and trigger diagnostic `AIPL_E0012_MIXED_INDENTATION` (or `E0001: TabCharacterForbidden`).
- Indentation must increase or decrease in increments of exactly 2 ASCII spaces (`0x20 0x20`). Odd numbers of spaces trigger diagnostic `E0002: InconsistentIndentation`.
- The lexer emits virtual tokens: `INDENT`, `DEDENT`, and `NEWLINE`.
- SentencePiece 256k unigram models naturally absorb leading spaces into subsequent tokens (e.g., `  let` is a single token `_ _let`). The 2-space rule maximizes this absorption efficiency, eliminating indentation whitespace token overhead.

#### Offside State Machine & Invariants
The lexer maintains an indentation stack initialized to `[0]`:
1. **LineStart State**:
   - Blank lines (containing solely spaces, tabs, or newlines) and comment-only lines (`// ...` or `/* ... */`) are skipped without modifying the indentation stack or synthesizing newlines.
   - Any tab character detected in leading indentation immediately halts scanning with diagnostic `AIPL_E0012_MIXED_INDENTATION`.
   - If leading space count $S$ is odd, compilation halts with `E0002: InconsistentIndentation`.
   - If $S > \text{top}$: the new level is pushed to the stack, and exactly one `INDENT` token is synthesized.
   - If $S < \text{top}$: $S$ must match a prior column on the stack. The lexer pops levels until matching $S$, emitting exactly one `DEDENT` token for each popped level. If $S$ is not on the stack, diagnostic `E0002` is emitted.
   - **Dedent-to-Zero Collapse**: Returning to column 0 from an indentation depth of $N$ levels collapses the stack down to `[0]`, synthesizing exactly $N$ `DEDENT` tokens.
2. **InLine State**:
   - Horizontal spaces are skipped using SIMD vector scanning.
   - Comments (`//`) skip to the end of the line using SIMD `memchr(b'\n')`.
   - Physical newlines (`\n` or `\r\n`) synthesize a `NEWLINE` token if non-empty code appeared on the line and the nested delimiter stack is empty.

### 2.4 Nested Delimiter Suppression Invariant
Multi-line expressions inside parentheses `( ... )`, square brackets `[ ... ]`, or curly braces `{ ... }` do not require line-continuation backslashes:
- Enclosing delimiters push onto a nested delimiter stack (`Paren`, `Bracket`, `Brace`, `Interpolation`).
- While the delimiter stack is non-empty, logical `NEWLINE` synthesis is suppressed, and leading whitespace on subsequent lines does NOT synthesize `INDENT` or `DEDENT` tokens.
- Closing delimiters pop their matching frame. Mismatched delimiters emit diagnostic `E0009`.

### 2.5 String Literals, Multiline Strings & Interpolation Format Specifiers
Strings in AIPL are enclosed in double quotes (`"`). Expressions within strings are enclosed in single curly braces (`{` and `}`):
```aipl
let greeting = "Hello {userName}, your balance is {balance} tokens."
```
- Literal curly braces are escaped by doubling: `{{` produces `{`, and `}}` produces `}`.
- Regex repetition quantifiers beginning with a digit and containing only digits, commas, and spaces (e.g., `"{2,4}"`, `"a{3}"`, `"x{1,}"`) are automatically disambiguated by the lexer and preserved as literal characters without requiring `{{` or `r"..."`.
- Single-brace interpolation avoids the token penalty of Python's `f"..."` prefix and TypeScript's backtick template literal syntax `` `${...}` ``.

#### Format Specifiers
Interpolated expressions support optional format specifiers declared with a colon syntax `{expr:spec}`:
- `{x:02x}`, `{x:04x}`, `{x:08x}`: Hexadecimal integer formatting with zero-padding.
- `{v:>8}`, `{v:<8}`: String or numeric alignment (right or left) with minimum column width.
- `{f:.2f}`, `{f:.4f}`: Fixed-point floating-point precision formatting.
- `{b:bytes}`: Human-readable byte size formatting (`B`, `KB`, `MB`, `GB`).

```aipl
let formatted = "Hex: {42:02x}, Align: {10:>8}, Float: {3.1415:.2f}"
```

#### Multiline & Raw String Literals
- **Multiline Strings (`"""..."""`)**: Enclosed in triple double quotes. Preserves internal line breaks, automatically strips leading common 2-space indentation, and supports full expression interpolation `{expr}`.
- **Raw Multiline Strings (`r"""..."""`)**: Disables escape sequence processing, preserving backslashes (`\`) and delimiters verbatim.

```aipl
let query = """
  SELECT id, name
  FROM users
  WHERE active = true
"""
```

#### Numeric Literal Bases (0x and 0b)
AIPL supports decimal, hexadecimal, and binary integer literals:
- **Hexadecimal**: Prefixed by `0x` or `0X` (e.g., `0xFF`, `0x7FFF`).
- **Binary**: Prefixed by `0b` or `0B` (e.g., `0b1010`, `0b11110000`).

```aipl
let bitmask = 0b10101100
let hexValue = 0xFF00
```

#### Interpolation Lexer State Machine
1. When encountering opening `"`, the lexer checks whether the string literal contains unescaped single curly braces `{`.
2. If no unescaped braces exist, the literal is scanned directly into `StringLiteral(content)`.
3. If unescaped single braces exist, the lexer transitions into `InInterpolatedString`:
   - Emits `InterpolatedStringStart` at the opening `"`.
   - Scans literal text up to the unescaped `{`, emitting `StringChunk(text)` (with `{{` and `}}` unescaped).
   - Emits `LBrace` at `{` and pushes `Delimiter::Interpolation` to the layout stack.
   - Transitions to `InLine`, allowing standard expression tokenization inside `{ ... }` (e.g. `score + 10`).
   - Upon encountering optional `:`, scans the format specifier string.
   - Upon encountering the matching `}`, the lexer pops `Delimiter::Interpolation`, emits `RBrace`, and resumes scanning the next string chunk.
   - Upon reaching the closing `"`, emits any remaining non-empty `StringChunk` followed by `InterpolatedStringEnd`.

### 2.6 Semicolon Elision & Statement Boundaries
In AIPL, semicolons (`;`) are strictly optional. Logical statement boundaries are delimited by synthetic `NEWLINE` tokens. Multiple statements on a single physical line may be separated by an explicit semicolon `;` token.

### 2.7 Casing & Tokenomics Invariants
AIPL enforces strict lexical casing conventions:
- **`camelCase` Invariant**: All variable names, function names, parameter names, and record fields MUST match the regular expression `^[a-z][a-zA-Z0-9]*$`.
- **`PascalCase` Invariant**: All type names, struct names, component names, system names, shader names, and enum variants MUST match the regular expression `^[A-Z][a-zA-Z0-9]*$`.
- **`snake_case` Ban, Token Penalty & Automated Self-Healing (`AIPL_W1003_SNAKE_CASE_AUTOFIX` / `AIPL_W0041`)**: The underscore character `_` is strictly forbidden in identifier names, except as an anonymous wildcard discard (`_`). Identifiers in `snake_case` trigger warning `AIPL_W1003_SNAKE_CASE_AUTOFIX`. The toolchain's `aipl fmt` and `aipl fix` commands automatically invoke `normalizeSnakeCaseSource` to heal symbols into canonical `camelCase` (`userName`, `getData`) or `PascalCase` (`UserProfile`, `HttpRequest`) while preserving `@extern` C-FFI call signatures and string interpolation literals.
- **Digit-Free Primitive Enforcement (`AIPL_E0042_DIGIT_PRIMITIVE_FORBIDDEN`)**: Numeric types such as `i32`, `u64`, `f32`, `int32`, `uint64` are strictly forbidden. The compiler emits diagnostic `AIPL_E0042_DIGIT_PRIMITIVE_FORBIDDEN` (short code `E0042`) and recommends `int`, `float`, `byte`, or `num`.
- **Sigil Fragmentation Rejection (`AIPL_E0043_BANNED_SIGIL_FRAGMENTATION`)**: Multi-character operators such as `::=`, `!s`, `->>`, `|*|` that fragment into multiple tokens in SentencePiece are strictly rejected with diagnostic `AIPL_E0043_BANNED_SIGIL_FRAGMENTATION` (short code `E0043`).
- **Pipe Operator Avoidance (`AIPL_W0044_PIPE_OPERATOR_AVOIDANCE`)**: The pipe operator `|>` is discouraged in favor of standard method dot-chaining (`.map().filter()`), triggering warning `AIPL_W0044_PIPE_OPERATOR_AVOIDANCE` (short code `W0044`).

### 2.8 Complete Token Kinds Reference Table

| Category | Token Kinds | Example Representation |
| :--- | :--- | :--- |
| **Keywords** | `fn`, `struct`, `system`, `component`, `shader`, `server`, `div`, `let`, `mut`, `pub`, `ret`, `return`, `if`, `else`, `match`, `for`, `in`, `while`, `with`, `arena`, `import`, `export`, `as`, `from`, `module`, `type`, `enum`, `interface`, `break`, `continue`, `and`, `or`, `not`, `true`, `false`, `nil`, `Ok`, `Err`, `step`, `by` | `fn`, `let`, `mut`, `struct`, `step` |
| **Primitives** | `int`, `float`, `num`, `str`, `bool`, `byte`, `void` | `int`, `float`, `str` |
| **Shader & HTTP** | `vertex`, `fragment`, `compute`, `GET`, `POST`, `PUT`, `DELETE`, `PATCH` | `vertex`, `POST` |
| **Identifiers** | `Ident`, `Wildcard` | `userName`, `Vec3`, `_` |
| **Literals** | `IntLiteral`, `FloatLiteral`, `StringLiteral` | `42`, `0xFF`, `0b1010`, `3.1415`, `"hello"` |
| **Interpolation** | `InterpolatedStringStart`, `StringChunk`, `InterpolatedStringEnd` | `"`, `Score: `, `"` |
| **Operators** | `=`, `+=`, `-=`, `*=`, `/=`, `%=`, `==`, `!=`, `<`, `<=`, `>`, `>=`, `+`, `-`, `*`, `/`, `%`, `&`, `\|`, `^`, `~`, `<<`, `>>`, `..`, `..=`, `->`, `=>`, `?`, `:`, `::`, `;`, `,`, `.` | `+=`, `->`, `=>`, `?`, `&`, `..=` |
| **Delimiters** | `LParen` `(`, `RParen` `)`, `LBracket` `[`, `RBracket` `]`, `LBrace` `{`, `RBrace` `}` | `(`, `)`, `[`, `]`, `{`, `}` |
| **Layout Tokens** | `INDENT`, `DEDENT`, `NEWLINE`, `EOF` | Virtual offside tokens |

### 2.9 Dot-Class UI Selector Expressions
AIPL natively models reactive and declarative user interfaces using dot-class selector expressions:
```aipl
div.card.p4.flexRow [
  span.fontBold [ "User Profile" ],
  button.btnPrimary [ "Save" ]
]
```
The token sequence `div.card.p4.flexRow` is lexed and parsed as an element tag `div` with camelCase class identifiers `["card", "p4", "flexRow"]`. This eliminates verbose JSX syntax (`<div className="card p4 flexRow">...</div>`) and cuts UI token consumption by over 65%.

### 2.10 Tokenomics & Vocabulary Guarantee Table

AIPL co-designs all keywords, primitives, and syntax against the empirical tokenization dictionaries of frontier LLMs. The table below documents empirical token counts across Google SentencePiece 256k (Gemini 1.5/2.0, Gemma), OpenAI `cl100k_base` (GPT-4), and OpenAI `o200k_base` (GPT-4o), demonstrating guaranteed 1-token encoding with leading whitespace and empirical savings over traditional multi-token equivalents:

| Keyword / Primitive | Leading Space Syntax | SP 256k (Gemini/Gemma) | OpenAI `cl100k_base` | OpenAI `o200k_base` | Conventional Multi-Token Alternative | Conventional Tokens | Token Savings |
| :--- | :--- | :---: | :---: | :---: | :--- | :---: | :---: |
| `fn` | `" fn"` | **1 token** | **1 token** | **1 token** | `async function`, `def` | 2-3 tokens | -50.0% to -66.7% |
| `struct` | `" struct"` | **1 token** | **1 token** | **1 token** | `export interface`, `class` | 2-3 tokens | -50.0% to -66.7% |
| `system` | `" system"` | **1 token** | **1 token** | **1 token** | `export system` | 2 tokens | -50.0% |
| `type` | `" type"` | **1 token** | **1 token** | **1 token** | `typedef`, `type alias` | 2-3 tokens | -50.0% to -66.7% |
| `let` | `" let"` | **1 token** | **1 token** | **1 token** | `const let`, `var` | 1-2 tokens | 0.0% to -50.0% |
| `mut` | `" mut"` | **1 token** | **1 token** | **1 token** | `mutable`, `mut` | 1-2 tokens | 0.0% to -50.0% |
| `pub` | `" pub"` | **1 token** | **1 token** | **1 token** | `pub(crate)`, `public` | 2-4 tokens | -50.0% to -75.0% |
| `ret` | `" ret"` | **1 token** | **1 token** | **1 token** | `return` | 1 token | 0.0% |
| `if` | `" if"` | **1 token** | **1 token** | **1 token** | `if` | 1 token | 0.0% |
| `else` | `" else"` | **1 token** | **1 token** | **1 token** | `else` | 1 token | 0.0% |
| `match` | `" match"` | **1 token** | **1 token** | **1 token** | `switch case` | 2 tokens | -50.0% |
| `for` | `" for"` | **1 token** | **1 token** | **1 token** | `for` | 1 token | 0.0% |
| `in` | `" in"` | **1 token** | **1 token** | **1 token** | `in` | 1 token | 0.0% |
| `while` | `" while"` | **1 token** | **1 token** | **1 token** | `while` | 1 token | 0.0% |
| `component` | `" component"` | **1 token** | **1 token** | **1 token** | `React.FC<Props>` | 5 tokens | -80.0% |
| `shader` | `" shader"` | **1 token** | **1 token** | **1 token** | `@compute @workgroup` | 4 tokens | -75.0% |
| `server` | `" server"` | **1 token** | **1 token** | **1 token** | `express.Application` | 4 tokens | -75.0% |
| `div` | `" div"` | **1 token** | **1 token** | **1 token** | `<div className="...">` | 6 tokens | -83.3% |
| `int` | `" int"` | **1 token** | **1 token** | **1 token** | `int32`, `i64`, `int64` | 2 tokens | -50.0% |
| `float` | `" float"` | **1 token** | **1 token** | **1 token** | `float32`, `f64`, `double` | 2 tokens | -50.0% |
| `str` | `" str"` | **1 token** | **1 token** | **1 token** | `std::string`, `String` | 2-3 tokens | -50.0% to -66.7% |
| `bool` | `" bool"` | **1 token** | **1 token** | **1 token** | `boolean`, `bool_t` | 2 tokens | -50.0% |
| `byte` | `" byte"` | **1 token** | **1 token** | **1 token** | `uint8`, `unsigned char` | 2-3 tokens | -50.0% to -66.7% |
| `void` | `" void"` | **1 token** | **1 token** | **1 token** | `None`, `()`, `Unit` | 1-2 tokens | 0.0% to -50.0% |
| `nil` | `" nil"` | **1 token** | **1 token** | **1 token** | `undefined`, `nullptr` | 2-3 tokens | -50.0% to -66.7% |

#### Identifier Casing Guarantee Table

| Identifier Syntax | Casing Convention | SP 256k Tokens | OpenAI cl100k | OpenAI o200k | Subwords Decomposed | Net Token Savings |
| :--- | :--- | :---: | :---: | :---: | :--- | :---: |
| `userName` | **AIPL camelCase** | **1 token** | **1 token** | **1 token** | `["userName"]` | **-66.7%** |
| `user_name` | snake_case | 3 tokens | 3 tokens | 3 tokens | `["user", "_", "name"]` | Baseline |
| `getUserById` | **AIPL camelCase** | **2 tokens** | **2 tokens** | **2 tokens** | `["getUser", "ById"]` | **-71.4%** |
| `get_user_by_id` | snake_case | 7 tokens | 7 tokens | 7 tokens | `["get", "_", "user", "_", "by", "_", "id"]` | Baseline |
| `UserAccountProfile` | **AIPL PascalCase** | **3 tokens** | **3 tokens** | **3 tokens** | `["User", "Account", "Profile"]` | **-57.1%** |
| `user_account_profile` | snake_case | 5 tokens | 5 tokens | 5 tokens | `["user", "_", "account", "_", "profile"]` | Baseline |

---

## 3. Formal EBNF Grammar

The grammar below is specified in standard Extended Backus-Naur Form (ISO/IEC 14977 compatible).

```ebnf
(* =========================================================================
   AIPL ISO/IEC 14977 EXTENDED BACKUS-NAUR FORM GRAMMAR
   Single Source of Truth (SSOT)
   ========================================================================= *)

(* ---------------- Lexical Terminals & Tokens ---------------- *)

letter             = "A" | "B" | "C" | "D" | "E" | "F" | "G" | "H" | "I" | "J"
                   | "K" | "L" | "M" | "N" | "O" | "P" | "Q" | "R" | "S" | "T"
                   | "U" | "V" | "W" | "X" | "Y" | "Z"
                   | "a" | "b" | "c" | "d" | "e" | "f" | "g" | "h" | "i" | "j"
                   | "k" | "l" | "m" | "n" | "o" | "p" | "q" | "r" | "s" | "t"
                   | "u" | "v" | "w" | "x" | "y" | "z" ;

digit              = "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9" ;

binary_digit       = "0" | "1" ;

hex_digit          = digit | "a" | "b" | "c" | "d" | "e" | "f"
                           | "A" | "B" | "C" | "D" | "E" | "F" ;

pascal_identifier  = ("A" .. "Z") , { letter | digit } ;
camel_identifier   = ("a" .. "z") , { letter | digit } ;
wildcard           = "_" ;

identifier         = camel_identifier | pascal_identifier ;

integer_literal    = [ "-" ] , digit , { digit }
                   | "0x" , hex_digit , { hex_digit }
                   | "0X" , hex_digit , { hex_digit }
                   | "0b" , binary_digit , { binary_digit }
                   | "0B" , binary_digit , { binary_digit } ;

float_literal      = [ "-" ] , digit , { digit } , "." , digit , { digit } , [ ( "e" | "E" ) , [ "+" | "-" ] , digit , { digit } ] ;

format_specifier   = ":" , { letter | digit | ">" | "<" | "^" | "." } ;
Interpolation      = "{" , Expr , [ format_specifier ] , "}" ;

string_character   = ? any Unicode character except '"', '\', '{', or '}' ? ;
string_escape      = "\\" , ( ? any escape character: '"', '\', '/', 'b', 'f', 'n', 'r', 't', '{', or '}' ? ) ;
string_part        = { string_character | string_escape | "{{" | "}}" } ;

single_line_string = '"' , { string_part | Interpolation } , '"' ;
multiline_string   = '"""' , { ? multiline character ? | Interpolation } , '"""' ;
raw_string         = 'r"""' , { ? raw character ? } , '"""' ;
string_literal     = single_line_string | multiline_string | raw_string ;

boolean_literal    = "true" | "false" ;
nil_literal        = "nil" ;

primitive_type     = "int" | "float" | "num" | "bool" | "str" | "byte" | "void" | "nil" | "any" | "never" | "vec2" | "vec3" | "vec4" | "mat4" ;

(* Virtual Tokens emitted by SIMD Lexer *)
INDENT             = ? virtual token: increase indentation by 2 spaces ? ;
DEDENT             = ? virtual token: decrease indentation by 2 spaces ? ;
NEWLINE            = ? virtual token: end of logical line ? ;

(* ---------------- Syntactic Structure ---------------- *)

CompilationUnit    = { ModuleItem } ;

ModuleItem         = ModuleDecl
                   | ImportDecl
                   | ExportDecl
                   | TopLevelDef ;

ModuleDecl         = "module" , pascal_identifier , NEWLINE ;

ModulePath         = identifier , { "." , identifier } ;
ImportDecl         = "import" , ModulePath , [ "as" , identifier ] , NEWLINE
                   | "import" , "{" , ImportSpecList , "}" , "from" , string_literal , NEWLINE ;

ImportSpecList     = ImportSpec , { "," , ImportSpec } ;
ImportSpec         = identifier , [ "as" , identifier ] ;

ExportDecl         = "export" , TopLevelDef ;

TopLevelDef        = [ "pub" ] , ( FunctionDef | StructDef | EnumDef | TypeAliasDef | ComponentDef | SystemDef | ShaderDef | ServerDef | InterfaceDef | LetStmt ) ;

(* ---------------- Type System ---------------- *)

TypeExpr           = OptionTypeShorthand
                   | PrimitiveTypeExpr
                   | NamedTypeExpr
                   | ArrayTypeExpr
                   | ResultTypeExpr
                   | RefinementTypeExpr
                   | TupleTypeExpr
                   | FunctionTypeExpr ;

OptionTypeShorthand = "?" , TypeExpr ;
PrimitiveTypeExpr  = primitive_type , [ "[" , integer_literal , "]" ] ;
NamedTypeExpr      = [ camel_identifier , "." ] , pascal_identifier , [ "[" , TypeList , "]" ] , [ "!" , TypeExpr ] ;
ArrayTypeExpr      = "[" , TypeExpr , [ ";" , integer_literal ] , "]" ;
ResultTypeExpr     = "Result" , "[" , TypeExpr , "," , TypeExpr , "]" ;
RefinementTypeExpr = "{" , camel_identifier , ":" , TypeExpr , "|" , RefinementPred , "}" ;
TupleTypeExpr      = "(" , TypeExpr , "," , TypeList , ")" ;
FunctionTypeExpr   = "fn" , "(" , [ TypeList ] , ")" , "->" , TypeExpr ;

TypeList           = TypeExpr , { "," , TypeExpr } ;

RefinementPred     = RefinementTerm , { ( "and" | "or" ) , RefinementTerm } ;
RefinementTerm     = [ "not" ] , RefinementAtom ;
RefinementAtom     = RefinementComparison
                   | "(" , RefinementPred , ")" ;
RefinementComparison = Expr , ( "==" | "!=" | "<" | "<=" | ">" | ">=" ) , Expr ;

(* ---------------- Definitions ---------------- *)

FunctionDef        = "fn" , camel_identifier , [ "[" , TypeParamList , "]" ] ,
                     "(" , [ ParameterList ] , ")" , [ ":" , TypeExpr ] ,
                     ( ( "=" , Expr , NEWLINE ) | ( ":" , Block ) ) ;

TypeParamList      = pascal_identifier , { "," , pascal_identifier } ;

ParameterList      = Parameter , { "," , Parameter } ;
Parameter          = [ "mut" ] , [ "&" ] , camel_identifier , [ ":" , TypeExpr ] , [ "=" , Expr ] ;

StructDef          = "struct" , pascal_identifier , [ "[" , TypeParamList , "]" ] ,
                     ( ( "(" , [ ParameterList ] , ")" , NEWLINE )
                     | ( ":" , ParameterList , NEWLINE )
                     | ( ":" , NEWLINE , INDENT , StructMemberList , DEDENT ) ) ;

StructMemberList   = StructMember , { StructMember } ;
StructMember       = [ "pub" ] , camel_identifier , [ ":" , TypeExpr ] , [ "=" , Expr ] , NEWLINE ;

ComponentDef       = "component" , pascal_identifier , ":" , NEWLINE ,
                     INDENT , StructMemberList , DEDENT ;

SystemDef          = "system" , pascal_identifier , "(" , SystemQueryList , ")" , ":" , NEWLINE ,
                     INDENT , StatementBlock , DEDENT ;

SystemQueryList    = SystemQuery , { "," , SystemQuery } ;
SystemQuery        = [ "mut" ] , pascal_identifier ;

ShaderDef          = "shader" , pascal_identifier , "(" , ShaderStage , ")" , [ ShaderLang ] , ":" , NEWLINE ,
                     INDENT , ShaderBody , DEDENT ;

ShaderStage        = "vertex" | "fragment" | "compute" ;
ShaderLang         = "glsl" | "wgsl" ;
ShaderBody         = ? raw embedded GLSL or WGSL shader block source text ? ;

ServerDef          = "server" , pascal_identifier , ":" , NEWLINE ,
                     INDENT , ServerRouteList , DEDENT ;

ServerRouteList    = ServerRoute , { ServerRoute } ;
ServerRoute        = HttpMethod , string_literal , "->" , camel_identifier , NEWLINE ;
HttpMethod         = "GET" | "POST" | "PUT" | "DELETE" | "PATCH" ;

TypeAliasDef       = "type" , pascal_identifier , [ "[" , TypeParamList , "]" ] , "=" , TypeExpr , NEWLINE ;

EnumDef            = "enum" , pascal_identifier , ":" , NEWLINE ,
                     INDENT , EnumVariantList , DEDENT ;

EnumVariantList    = EnumVariant , { EnumVariant } ;
EnumVariant        = pascal_identifier , [ "(" , TypeList , ")" ] , NEWLINE ;

InterfaceDef       = "interface" , pascal_identifier , ":" , NEWLINE ,
                     INDENT , InterfaceMemberList , DEDENT ;

InterfaceMemberList = InterfaceMember , { InterfaceMember } ;
InterfaceMember    = "fn" , camel_identifier , "(" , [ ParameterList ] , ")" , ":" , TypeExpr , NEWLINE ;

(* ---------------- Statements & Blocks ---------------- *)

Block              = NEWLINE , INDENT , StatementBlock , DEDENT ;
StatementBlock     = Statement , { Statement } ;

Statement          = LetStmt
                   | MutStmt
                   | AssignStmt
                   | IfStmt
                   | MatchStmt
                   | ForStmt
                   | WhileStmt
                   | ReturnStmt
                   | BreakStmt
                   | ContinueStmt
                   | DiscardStmt
                   | PassStmt
                   | ArenaBlock
                   | ExprStmt ;

LetStmt            = "let" , Pattern , [ ":" , TypeExpr ] , "=" , Expr , NEWLINE ;
MutStmt            = "mut" , camel_identifier , [ ":" , TypeExpr ] , "=" , Expr , NEWLINE ;
AssignStmt         = TargetExpr , AssignOp , Expr , NEWLINE ;
AssignOp           = "=" | "+=" | "-=" | "*=" | "/=" | "//=" | "%=" ;

IfCondition        = [ "let" , Pattern , "=" ] , Expr ;
IfStmt             = "if" , IfCondition , ":" , Block ,
                     { "else" , "if" , IfCondition , ":" , Block } ,
                     [ "else" , ":" , Block ] ;

MatchStmt          = "match" , Expr , ":" , NEWLINE ,
                     INDENT , MatchArmList , DEDENT ;

MatchArmList       = MatchArm , { MatchArm } ;
MatchArm           = Pattern , [ "if" , Expr ] , "=>" , ( Expr , NEWLINE | Block ) ;

ForStmt            = "for" , [ "mut" ] , Pattern , "in" , Expr , [ ( "by" | "step" ) , Expr ] , ":" , Block ;
WhileStmt          = "while" , Expr , ":" , Block ;
ReturnStmt         = ( "ret" | "return" ) , [ Expr ] , NEWLINE ;
BreakStmt          = "break" , NEWLINE ;
ContinueStmt       = "continue" , NEWLINE ;
DiscardStmt        = "discard" , Expr , NEWLINE ;
PassStmt           = "pass" , NEWLINE ;

ArenaBlock         = "with" , "arena" , [ "(" , camel_identifier , ")" ] , ":" , Block ;

ExprStmt           = Expr , NEWLINE ;

(* ---------------- Patterns ---------------- *)

Pattern            = LiteralPattern
                   | WildcardPattern
                   | IdentPattern
                   | VariantPattern
                   | TuplePattern
                   | StructPattern ;

LiteralPattern     = integer_literal | float_literal | string_literal | boolean_literal | nil_literal ;
WildcardPattern    = wildcard ;
IdentPattern       = camel_identifier ;
VariantPattern     = [ pascal_identifier , ( "::" | "." ) ] , pascal_identifier , [ "(" , PatternList , ")" ] ;
TuplePattern       = "(" , Pattern , "," , PatternList , ")" ;
StructPattern      = pascal_identifier , "{" , StructFieldPatList , "}" ;
StructFieldPatList = StructFieldPat , { "," , StructFieldPat } ;
StructFieldPat     = camel_identifier , [ ":" , Pattern ] ;
PatternList        = Pattern , { "," , Pattern } ;

(* ---------------- Expressions & Pratt Grammar ---------------- *)

Expr               = TernaryExpr ;

TernaryExpr        = BinaryExpr , [ "?" , Expr , ":" , TernaryExpr ] ;

BinaryExpr         = UnaryExpr , { BinaryOp , UnaryExpr } ;
BinaryOp           = "??" | "or" | "and" | "==" | "!=" | "<" | "<=" | ">" | ">=" | "in"
                   | "+" | "-" | "*" | "/" | "//" | "%" | "**" | "|>" | ".." | "..="
                   | "&" | "|" | "^" | "<<" | ">>" ;

UnaryExpr          = [ UnaryOp ] , PostfixExpr ;
UnaryOp            = "-" | "not" | "!" | "~" ;

PostfixExpr        = PrimaryExpr , { PostfixOp } ;
PostfixOp          = MemberAccess
                   | CallOp
                   | IndexOp
                   | TryOp ;

MemberAccess       = "." , camel_identifier ;
CallOp             = "(" , [ ArgumentList ] , ")" ;
IndexOp            = "[" , ( SliceRange | Expr ) , "]" ;
SliceRange         = [ Expr ] , ( ".." | "..=" ) , [ Expr ] ;
TryOp              = "?" ;

ArgumentList       = Argument , { "," , Argument } ;
Argument           = [ camel_identifier , "=" ] , Expr ;

PrimaryExpr        = integer_literal
                   | float_literal
                   | string_literal
                   | boolean_literal
                   | nil_literal
                   | TypeCastExpr
                   | StructUpdateExpr
                   | ScopedVariantExpr
                   | TupleExpr
                   | ClosureExpr
                   | camel_identifier
                   | pascal_identifier
                   | GroupedExpr
                   | ListExpr
                   | UiLiteralExpr ;

TypeCastExpr       = primitive_type , "(" , Expr , ")" ;
GroupedExpr        = "(" , Expr , ")" ;
TupleExpr          = "(" , Expr , "," , ExprList , ")" ;

StructUpdateExpr   = ( [ pascal_identifier ] , "{" , ".." , Expr , { "," , StructFieldInit } , "}" )
                   | ( pascal_identifier , "(" , ".." , Expr , { "," , StructFieldInit } , ")" ) ;
StructFieldInit    = camel_identifier , ( "=" | ":" ) , Expr ;

ScopedVariantExpr  = pascal_identifier , ( "::" | "." ) , pascal_identifier , [ "(" , [ ArgumentList ] , ")" ] ;

ClosureExpr        = ( "|" , [ ClosureParamList ] , "|" , ( Expr | Block ) )
                   | ( "fn" , "(" , [ ParameterList ] , ")" , [ "->" , TypeExpr ] , "=>" , ( Expr | Block ) ) ;
ClosureParamList   = ClosureParam , { "," , ClosureParam } ;
ClosureParam       = camel_identifier , [ ":" , TypeExpr ] ;

ListExpr           = "[" , ( ArrayRepeatExpr | ListComprehension | [ ExprList ] ) , "]" ;
ArrayRepeatExpr    = Expr , ";" , Expr ;
ListComprehension  = Expr , "for" , [ "mut" ] , Pattern , "in" , Expr , [ "if" , Expr ] ;
ExprList           = Expr , { "," , Expr } ;

(* UI Tree Declarative Syntax *)
UiLiteralExpr      = ( ui_tag | pascal_identifier ) , { "." , camel_identifier } , "[" , [ UiChildList ] , "]" ;
ui_tag             = "div" | camel_identifier ;
UiChildList        = UiChild , { "," , UiChild } ;
UiChild            = UiLiteralExpr
                   | Expr ;

TargetExpr         = camel_identifier , { MemberAccess | IndexOp } ;
```

---

## 4. Operator Precedence & Pratt Binding Powers

The AIPL parser employs a high-performance Top-Down Operator Precedence (Pratt) parser implemented in `compiler/parser.aipl`. Binding powers are defined as integer pairs `(LeftBindingPower, RightBindingPower)`:

| Operator | Syntax | Associativity | Left Binding Power (LBP) | Right Binding Power (RBP) |
| :--- | :--- | :--- | :---: | :---: |
| **Member Access** | `expr.field` | Left | 90 | 91 |
| **Call / Index** | `expr(args)`, `expr[idx]` | Left | 80 | 81 |
| **Error Propagation (Try)**| `expr?` | Postfix | 80 | 81 |
| **Unary Prefix** | `-expr`, `!expr`, `not expr`, `~expr` | Prefix | - | 70 |
| **Power** | `**` | Right | 66 | 65 |
| **Multiplicative** | `*`, `/`, `%` | Left | 60 | 61 |
| **Additive** | `+`, `-` | Left | 50 | 51 |
| **Bitwise Shift** | `<<`, `>>` | Left | 48 | 49 |
| **Bitwise AND** | `&` | Left | 46 | 47 |
| **Bitwise XOR** | `^` | Left | 44 | 45 |
| **Bitwise OR** | `\|` | Left | 42 | 43 |
| **Range** | `..`, `..=` | Left | 40 | 41 |
| **Relational** | `<`, `<=`, `>`, `>=`, `in` | Left | 35 | 36 |
| **Equality** | `==`, `!=` | Left | 30 | 31 |
| **Logical AND** | `and` | Left | 25 | 26 |
| **Logical OR** | `or` | Left | 20 | 21 |
| **Pipeline** | `\|>` | Left | 18 | 19 |
| **Coalescing** | `??` (`a ?? b`) | Right | 16 | 15 |
| **Ternary Conditional** | `cond ? then : else` | Right | 14 | 13 |
| **Assignment** | `=`, `+=`, `-=`, `*=`, `/=`, `%=` | Right | 10 | 9 |

### 4.1 Postfix Try vs. Ternary Disambiguation
The token `?` is context-sensitively disambiguated at zero backtracking cost:
- `?` acts as **Ternary Conditional** if and only if the immediately subsequent token can initiate a primary expression (null denotation) and an unnested `:` delimiter appears before an expression terminator (`\n`, `;`, `EOF`).
- In all other cases (e.g. `fetch(url)?.status`, `record?`), `?` binds at postfix precedence (80) as the **Error Propagation (Try)** operator.

### 4.2 Postfix Error Propagation Desugaring
The postfix question mark operator `?` is valid only inside functions returning `Result[T, E]`.

The expression:
```aipl
let record = readDatabase(recordId)?
```
is desugared at Canonical HIR lowering into:
```aipl
let record = match readDatabase(recordId):
  Ok(val) => val
  Err(err) => return Err(err)
```

---

## 5. Strict Type System & Semantic Rules

The AIPL type system is a sound, bidirectional Hindley-Milner-derived type system designed specifically for machine-tractability and zero runtime ambiguity. It strictly eliminates runtime type errors, hidden coercions, and truthiness ambiguities through deterministic compile-time enforcement.

### 5.1 Sound Bidirectional Type Checking
AIPL operates via bidirectional type checking structured into two complementary judgments:
1. **Inference Mode (`infer(expr) -> HirType`)**: Synthesizes the unique canonical type of an expression from its subterms without external type expectations.
2. **Checking Mode (`check(expr, expected_type)`)**: Verifies that an expression conforms to a propagated expected type, guiding literal typing and constructor arguments.

### 5.2 Zero Implicit Coercion Invariant (`AIPL_E2002_TYPE_MISMATCH`)
AIPL enforces a strict **Zero Implicit Coercion** policy. Uncontextualized silent conversions across strings or pointers are rejected at compile time:

#### 5.2.1 Directional Lossless Numeric Lattice (`byte <: int <: float`)
- **Lossless Widening Subtyping**: AIPL establishes a strict directional lattice `byte <: int <: float`:
  - An unsigned 8-bit `byte` (`0..255`) widens losslessly to a 64-bit signed `int` (`let b: byte = 42; let i: int = b`).
  - A 64-bit signed `int` widens losslessly to a 64-bit IEEE-754 `float` (`let i: int = 42; let f: float = i`).
- **Compile-Time Truncation Rejection (`[AIPL312]`)**: Silent narrowing from `float` to `int` is strictly rejected at compile time (`AIPL_E0312_SILENT_FLOAT_TRUNCATION` / `[AIPL312]`). Expressions such as `let i: int = 3.9` or `let i: int = floatVar` halt compilation, requiring explicit `.i` postfix truncation, `.round`, `.floor`, `.ceil`, or `//` integer floor division.
- **Contextual Arithmetic Widening**: In binary arithmetic (`+`, `-`, `*`, `/`) and comparisons (`<`, `>`, `<=`, `>=`, `==`, `!=`), integer operands (`int`, `i8`..`i64`, `u8`..`u64`) are contextually widened to `float` when paired with a `float` operand, producing a `float` arithmetic result or `bool` comparison result (e.g., `let x: float = 2.5; let y = x + 10` produces `12.5: float`; `2.5 < 10` evaluates to `true`).

#### 5.2.2 Postfix Numeric Conversions (`.i`, `.f`, `.round`, `.floor`, `.ceil`)
To eliminate verbose function call boilerplate (`float(...)`, `int(...)`) across mathematical and graphics codebases, AIPL provides concise postfix numeric conversion methods:
- **`expr.f`**: Converts an integer (`int`, `byte`, `u8`..`u64`, `i8`..`i64`) or boolean to a 64-bit IEEE-754 `float` (`42.f == 42.0`).
- **`expr.i`**: Converts a `float` (truncating towards zero) or boolean to a 64-bit signed `int` (`3.7.i == 3`, `-2.3.i == -2`).
- **`expr.round`**: Rounds a `float` to the nearest integer (`3.7.round == 4`, `-2.3.round == -2`).
- **`expr.floor`**: Floors a `float` toward negative infinity (`3.7.floor == 3`, `-2.3.floor == -3`).
- **`expr.ceil`**: Ceils a `float` toward positive infinity (`3.7.ceil == 4`, `-2.3.ceil == -2`).
- **Direct Backend Inlining**: Lowers directly to hardware cast instructions (`(double)x`, `(int64_t)x` in C99; `Number(x)`, `Math.trunc(x)`, `Math.round(x)`, `Math.floor(x)`, `Math.ceil(x)` in TypeScript; `f64.convert_i32_s`, `i32.trunc_f64_s` in WebAssembly) with zero runtime function call overhead.

#### 5.2.3 No String Auto-Coercion
- The binary addition operator `+` on strings requires both operands to evaluate to `str`.
- Concatenation with non-strings (`"count: " + 5`) is rejected at compile time with `AIPL_E2002_TYPE_MISMATCH`.
- String formatting must use single-brace interpolation (`"count: {5}"`) or explicit conversions (`"count: " + str(5)`).

#### 5.2.4 Float vs. Integer Division & Floor-Division (`/`, `//`)
AIPL provides explicit division semantics without ambiguity:
- **Truncating Division (`/`)**: When both operands are `int` (`int / int`), `/` performs truncating integer division toward zero (e.g. `7 / 2 -> 3`, `-7 / 2 -> -3`), yielding `HirType::Int`. When both operands are `float` or mixed (`float / float`, `float / int`, `int / float`), `/` performs IEEE-754 double-precision division (`7.0 / 2.0 -> 3.5`).
- **Integer Floor-Division Operator (`//`)**: The `//` operator performs deterministic integer floor division rounded toward negative infinity (`7 // 2 == 3`, `-7 // 2 == -4`, `7.9 // 2.0 == 3`, `-7.1 // 2.0 == -4`). It is supported in all statement and expression positions including `.push(...)` arguments and `if`-conditions.

```aipl-invalid
// Compile Error AIPL_E2002_TYPE_MISMATCH: No uncontextualized literal widening
let x: float = 42

// Compile Error AIPL_E2002_TYPE_MISMATCH: No string auto-coercion
let score = 100
let message = "Score: " + score
```

```aipl
// Correct: Explicit float literal, postfix cast, or contextual widening
let x: float = 42.0
let y: float = 42.f
let z: float = x + 10

// Correct: Single-brace interpolation
let score = 100
let message = "Score: {score}"
```

### 5.3 Strict Boolean Conditional Invariant (`AIPL_E2004_NON_BOOLEAN_CONDITION`)
In AIPL, condition expressions in `if`, `else if`, `while`, and ternary expressions (`cond ? then : else`) MUST evaluate strictly to `HirType::Bool`.

Non-boolean "truthiness" (common in JavaScript and Python) is strictly banned:
- Integers do not coerce to boolean (`if 1:` or `if count:` triggers `AIPL_E2004_NON_BOOLEAN_CONDITION`).
- Strings do not coerce based on content or length (`if "hello":` or `if name:` triggers `AIPL_E2004_NON_BOOLEAN_CONDITION`).
- Arrays and collections do not coerce (`if items:` triggers `AIPL_E2004_NON_BOOLEAN_CONDITION`).
- Pointers and references do not coerce (`if ptr:` triggers `AIPL_E2004_NON_BOOLEAN_CONDITION`).

#### Automated Candidate Repairs
When `AIPL_E2004_NON_BOOLEAN_CONDITION` is emitted, the compiler automatically synthesizes candidate repairs with unified diffs:
- Integer conditions: suggests `count != 0` or `count > 0`.
- Collection conditions: suggests `items.len() > 0`.
- String conditions: suggests `text.len() > 0` or `text != ""`.
- Option conditions: suggests `val != nil`.

### 5.4 Exhaustive Pattern Matching Invariant (`AIPL_E2005_NON_EXHAUSTIVE_MATCH`)
Pattern matching with `match` over sum types (tagged unions, nominal enums, `Result[T, E]`, `Option[T]`, and `bool`) must be provably exhaustive at compile time:
- **Variant Coverage**: Every declared variant of an enum MUST be handled by at least one arm, OR an unguarded wildcard arm (`_ => ...`) or variable binding arm must be present.
- **Guard Soundness**: Match arms containing guards (`if condition => ...`) do NOT guarantee variant coverage, because the guard condition may evaluate to `false` at runtime. Guarded arms must be accompanied by an unguarded fallback.
- **Incomplete Matches**: If any variant is omitted without an unguarded fallback, compilation fails with `AIPL_E2005_NON_EXHAUSTIVE_MATCH`, detailing all unhandled variants and synthesizing candidate repair diffs.

```aipl-invalid
// Compile Error AIPL_E2005_NON_EXHAUSTIVE_MATCH: missing variant 'Rejected'
enum Status:
  Pending
  Approved
  Rejected

fn checkStatus(status: Status): int:
  match status:
    Pending => 1
    Approved => 2
```

```aipl
enum Status:
  Pending
  Approved
  Rejected

// Correct: Exhaustive match with all variants handled
fn checkStatusExhaustive(status: Status): int:
  match status:
    Pending => 1
    Approved => 2
    Rejected => 3

// Correct: Exhaustive match with wildcard fallback
fn checkStatusWildcard(status: Status): int:
  match status:
    Pending => 1
    _ => 0
```

### 5.5 Error Handling & Propagation

AIPL eliminates exceptions and `try / catch` blocks entirely. All recoverable failures and optional states are expressed through first-class algebraic sum types: `Result[T, E]` and `Option[T]`.

#### 5.5.1 Built-in Algebraic Sum Types
The language runtime defines canonical algebraic sum types directly recognized by `HirType`:
```aipl
// Standard Result Type for Fallible Operations
enum Result[T, E]:
  Ok(T)
  Err(E)

// Standard Option Type for Nullable / Optional Values
enum Option[T]:
  Some(T)
  None
```

##### Constructor Type Inference:
- `Ok(v)` where `v: T` infers `Result[T, Unknown]`, soundly unifying with expected return or binding type `Result[T, E]`.
- `Err(e)` where `e: E` infers `Result[Unknown, E]`, soundly unifying with expected `Result[T, E]`.
- `Some(v)` where `v: T` infers `Option[T]`.
- `None` (or `None()`) infers `Option[Unknown]`, unifying with any expected `Option[T]`.

#### 5.5.2 Mandatory Unhandled Result Checking (`AIL_E1004_UNHANDLED_RESULT`)
AIPL enforces that all fallible operations returning `Result[T, E]` must be explicitly handled. Dropping or ignoring a `Result` value as a standalone expression statement is strictly forbidden and triggers compiler diagnostic `AIL_E1004_UNHANDLED_RESULT`:

```aipl-invalid
fn writeLog(msg: str): Result[void, str]:
  // ... writes log ...
  Ok(nil)

fn main(): void:
  // Compile Error AIL_E1004_UNHANDLED_RESULT:
  // Unhandled result: expression evaluates to 'Result[void, str]' as a standalone statement without being handled.
  writeLog("Agent starting")
```

##### Permitted Handling Mechanisms:
1. **Postfix `?` Operator**: Propagate early to enclosing caller (`writeLog("Agent starting")?`).
2. **Pattern Matching**: Exhaustively unpack both arms via `match writeLog(...)`:
```aipl
match writeLog("Agent starting"):
  Ok(_) => nil
  Err(e) => println("Log failed: {e}")
```
3. **Variable Binding**: Bind to a variable (`let res = writeLog(...)`).
4. **Explicit Discard**: Explicitly acknowledge intentional discard via wildcard pattern (`let _ = writeLog(...)`).

#### 5.5.3 Postfix `?` Operator Semantics & Incompatible Function Invariant (`AIPL_E2006_TRY_IN_INCOMPATIBLE_FN`)
The postfix operator `?` provides concise error propagation and option unwrapping without nested control flow:
- Given an expression `expr` evaluating to `Result[T, E]`:
  - `expr?` yields value `T`.
  - The enclosing function's declared return type MUST be a compatible `Result[R, E_ret]`, where error type `E` is compatible with `E_ret`.
  - If used inside a function returning `void`, `nil`, or an incompatible error type `E2`, compilation halts with `AIPL_E2006_TRY_IN_INCOMPATIBLE_FN` providing precise type mismatch details and candidate repairs.
- Given an expression `expr` evaluating to `Option[T]`:
  - `expr?` yields value `T`.
  - The enclosing function's declared return type MUST be `Option[R]`.
  - If used inside a function returning `void` or `Result`, diagnostic `AIPL_E2006_TRY_IN_INCOMPATIBLE_FN` is emitted.

```aipl-invalid
// Incompatible function rejection example:
fn run(): void:
  let val = parse()? // ERROR AIPL_E2006_TRY_IN_INCOMPATIBLE_FN:
                     // Cannot use '?' on 'Result' in function returning 'void'. Enclosing function must return 'Result'.
```

#### 5.5.4 Postfix `?` Canonical HIR Desugaring
In the Canonical HIR lowering and desugaring pipeline (`compiler/hir.aipl`), `let val = expr?` expands into an explicit branch:
```aipl
// Lowered / Desugared Form:
match expr:
  Err(err) => ret Err(err)
  Ok(val) =>
    let res = val
```
For `Option[T]`:
```aipl
match expr:
  None => ret None
  Some(val) =>
    let res = val
```

### 5.5.5 Chained Result Unwrapping
Chained member access and method calls with `?` short-circuit cleanly at the first failure without evaluating subsequent operations:
```aipl
fn getNestedKey(url: str): Result[str, Error]:
  let key = fetch(url)?.json()?.get("payload")?.asStr()?
  Ok(key)
```
If `fetch(url)` fails with `Err`, `json()`, `get()`, and `asStr()` are never invoked, and the error variant is returned immediately.

### 5.5.6 Option[T] and Result[T, E] Combinators

In addition to pattern matching and postfix `?` unwrapping, AIPL provides built-in UFCS combinators for ergonomic handling of fallible and optional values:

- **`Option[T]` Combinators**:
  - `opt.isSome() -> bool`: Returns `true` if `opt` contains `Some(val)`.
  - `opt.isNone() -> bool`: Returns `true` if `opt` is `None`.
  - `opt.unwrapOr(defaultVal: T) -> T`: Extracts the wrapped value if `Some`, returning `defaultVal` if `None`.
  - `opt.map(fn: |T| -> U) -> Option[U]`: Applies `fn` to the inner value if `Some`, returning `None` otherwise.

- **`Result[T, E]` Combinators**:
  - `res.isOk() -> bool`: Returns `true` if `res` contains `Ok(val)`.
  - `res.isErr() -> bool`: Returns `true` if `res` contains `Err(err)`.
  - `res.unwrapOr(defaultVal: T) -> T`: Extracts the wrapped value if `Ok`, returning `defaultVal` if `Err`.
  - `res.map(fn: |T| -> U) -> Result[U, E]`: Applies `fn` to the inner value if `Ok`, preserving `Err(e)` otherwise.
  - `res.andThen(fn: |T| -> Result[U, E]) -> Result[U, E]`: Chains fallible operations, short-circuiting on failure.

```text
let maybePort = parsePort("8080")
let port = maybePort.unwrapOr(3000)

let contentRes = readFile("data.json")
if contentRes.isOk():
  processContent(contentRes.unwrapOr("{}"))
```

### 5.6 Bitwise Operations & Shift Semantics
AIPL provides full support for bitwise manipulation over 64-bit signed integers (`int`) and parameterized buffers:
- **Binary Bitwise Operators**: `&` (AND), `|` (OR), `^` (XOR).
- **Bitwise Shifts**: `<<` (logical/arithmetic left shift), `>>` (arithmetic right shift with sign extension).
- **Unary Complement**: `~` (bitwise NOT / inversion).
- **Zero Coercion Rule**: Operands must be integers. Bitwise operations on floating-point values are rejected at compile time (`AIPL_E2002_TYPE_MISMATCH`).

```aipl
pub fn testBitwise(a: int, b: int): int:
  let andVal = a & b
  let orVal = a | b
  let xorVal = a ^ b
  let notVal = ~a
  let shlVal = a << 2
  let shrVal = b >> 1
  andVal + orVal + xorVal + notVal + shlVal + shrVal
```

### 5.7 Slicing & Sub-Collection Semantics
Array and string slicing is supported via range index syntax:
- **Half-Open Slice (`arr[start..end]`)**: Extracts items from index `start` up to but excluding `end`.
- **Inclusive Slice (`arr[start..=end]`)**: Extracts items from `start` up to and including `end`.
- **Open Boundaries**: `arr[..end]` defaults start to `0`; `arr[start..]` defaults end to `arr.len()`.

```aipl
pub fn testSlice(): void:
  let numbers = [10, 20, 30, 40, 50]
  let sub = numbers[1..4]
  let inclusive = numbers[0..=2]
```

### 5.8 Repeat Arrays & Contiguous Initialization
Fixed-capacity arrays and contiguous buffers can be initialized concisely using repeat array syntax `[element; count]`:
- `element` is evaluated once and copied across all `count` elements.
- `count` must evaluate to a non-negative integer.

```aipl
pub fn testRepeat(): void:
  let zeros = [0; 64]
  let flags = [false; 16]
```

### 5.9 Range Step Iteration & Mutable Loop Variables
Iterative `for` loops support explicit step increments and mutable loop variable bindings:
- **Step Increment Syntax**: `for i in start..end step S:` or `for i in start..end by S:`. Step `S` must be a positive integer.
- **Mutable Loop Bindings**: Declaring `for mut x in collection:` allows re-binding `x` within the loop body.

```aipl
pub fn testRangeStep(): int:
  mut total = 0
  for mut i in 0..10 step 2:
    total += i
  for j in 10..0 by 2:
    total += j
  total
```

### 5.10 Functional Struct Update Expressions
AIPL supports non-destructive functional record updates via struct copy-update syntax:
- `StructName(..orig, field1 = val1, field2 = val2)`
- `{ ..orig, field1 = val1, field2 = val2 }`
Copies all unspecified fields from `orig` while applying explicit field overrides, maintaining type safety and immutability invariants.

```aipl
struct Config:
  port: int
  host: str
  debug: bool

pub fn updateConfig(cfg: Config): Config:
  Config(..cfg, port = 8080, debug = true)
```

### 5.10.1 In-Place Chained Array-of-Struct Mutations
AIPL supports direct in-place mutation of struct fields nested within array elements via chained index and member access:
- **Direct Assignment**: `arr[i].field = val`
- **Compound Mutation Operators**: `arr[i].field += val`, `arr[i].field -= val`, `arr[i].field *= val`, `arr[i].field /= val`, `arr[i].field %= val`

#### Mechanics & Single-Index Guarantee
Rather than requiring repetitive 3-line unpack-mutate-repack boilerplate (`let mut tmp = arr[i]; tmp.x += dt; arr[i] = tmp`), the compiler generates direct interior pointer mutations:
1. Emits the runtime helper `aipl_array_member_op_set(arr, i, "field", val, op)`.
2. Evaluates the base array `arr` and index `i` exactly once, preventing double-indexing overhead and index recalculation bugs.
3. Mutates contiguous linear memory in-place without heap allocations or transient struct copies.

```aipl
struct Particle:
  x: float
  y: float
  vx: float
  vy: float

pub fn updateParticles(particles: [Particle], i: int, dt: float): float:
  particles[i].x += particles[i].vx * dt
  particles[i].y += particles[i].vy * dt
  ret particles[i].x
```

### 5.11 Qualified Enum Scoping
Enum variants can be explicitly qualified with their enclosing enum type:
- **Canonical Scoping**: `EnumName::Variant`
- **Dot Shorthand**: `EnumName.Variant`
Disambiguates variant names across distinct sum types without requiring global namespace unicity.

```aipl
enum Status:
  Pending
  Active
  Closed

pub fn getStatus(): Status:
  Status::Active
```

### 5.12 First-Class Tuples & Multi-Value Returns
Tuples provide lightweight, anonymous composite types with heterogeneous elements:
- **Type Declaration**: `(T1, T2, ...)`
- **Literal Syntax**: `(expr1, expr2, ...)`
- **Destructuring**: `let (a, b) = tupleVal`

```aipl
pub fn getCoords(): (int, int):
  (100, 200)

pub fn testTuples(): int:
  let pair = getCoords()
  let (x, y) = pair
  x + y
```

### 5.13 Conditional Pattern Binding (`if let`)
The `if let` construct combines conditional testing with pattern destructuring, streamlining option and result unpacking without verbose `match` blocks:

```aipl
pub fn testIfLet(opt: Option[int]): int:
  if let Some(val) = opt:
    val * 2
  else:
    0
```

### 5.14 First-Class Closures & Arrow Functions
AIPL provides first-class lambda expressions with full lexical environment capture:
- **Pipe Closure Syntax**: `|x: int, y: int| x + y` or `|x| x * 2`
- **Arrow Function Syntax**: `fn(x: int) -> int => x + 1`

```aipl
pub fn testClosures(): int:
  let addOne = |x: int| x + 1
  let double = fn(n: int) -> int => n * 2
  double(addOne(5))
```

### 5.15 Mutable and Reference Parameters (`mut param`, `&param`)
Function parameters are immutable by default. When in-body mutation or pass-by-reference semantics are required:
- `mut param: Type`: Marks the local parameter binding as mutable within the function body.
- `&mut param: Type`: Passes a mutable reference to the caller's storage for in-place mutation.

```aipl
pub fn increment(mut count: int): int:
  count += 1
  count

pub fn mutateRef(&mut target: int): void:
  target += 10
```

### 5.16 Compiler-Synthesized Struct & Enum JSON Schema and Serialization

Every nominal `struct` and `enum` declared in AIPL automatically receives compiler-synthesized reflection and serialization methods without manual boilerplate or external annotations:

1. **`TypeName.jsonSchema() -> str`**: Static method synthesizing a Draft 2020-12 compliant JSON Schema (`"$schema": "https://json-schema.org/draft/2020-12/schema"`). The schema reflects field names, types (`string`, `integer`, `number`, `boolean`, `array`, `object`), `required` property arrays, and `"additionalProperties": false`. Enums are synthesized as `"type": "string"` with an `"enum"` variant list.
2. **`instance.toJson() -> str`**: Instance method serializing the struct or enum instance to an RFC 8259 JSON string representation.
3. **`TypeName.fromJson(jsonStr: str) -> Result[TypeName, str]`**: Static deserialization method parsing a JSON payload into the target nominal struct or enum. Returns `Ok(val)` on success or `Err(errMsg)` if validation fails or fields are missing.

```aipl
pub struct TaskConfig:
  name: str
  priority: int
  active: bool

pub fn demonstrateTaskSerde(): int:
  let schema = TaskConfig.jsonSchema()
  let task = TaskConfig(name = "Deploy", priority = 1, active = true)
  let json = task.toJson()
  let decoded = TaskConfig.fromJson(json)
  match decoded:
    Ok(val) => ret val.priority
    Err(_) => ret 0
```

### 5.17 List and Array Comprehensions
AIPL supports concise array transformations and filtering through list comprehensions:
- **Syntax**: `[expr for item in iterable if condition]` or `[expr for item in iterable]`
- **Semantics**: The comprehension desugars into an array initialization loop in Canonical HIR. The `if` guard filter is optional.

```text
let numbers = [1, 2, 3, 4, 5, 6]
let squares = [x * x for x in numbers if x % 2 == 0]
// squares == [4, 16, 36]
```

### 5.18 Explicit Expression Discard and Pass Statements
AIPL provides dedicated syntactic forms for dropping values and handling no-op blocks:
1. **`discard <expr>`**: Explicitly evaluates an impure or fallible expression and discards its return value, avoiding compiler warnings and eliminating dummy `let _ = ...` wildcard bindings.
2. **`pass`**: A native no-op statement used in place of an empty statement body (e.g. In `if`, `else`, or `while` branches).

```text
fn processStream(): void:
  if shouldSkip():
    pass
  else:
    discard writeLog("processing event")
```

### 5.19 Module-Qualified Generic Type Annotations
AIPL allows type parameters and array element annotations to reference types qualified by imported module aliases:
- **Syntax**: `[mod.Type]`, `Map[mod.Key, mod.Val]`, `Result[mod.Record, mod.Error]`
- **Semantics**: The typechecker resolves the qualified symbol against the target module's exported `TypeEnv`, preserving module boundary encapsulation and namespace hygiene across generic containers.

```text
import std.fs as fs

pub struct DirectorySnapshot:
  entries: [fs.FileStat]
  metadata: Map[str, fs.FileStat]
```

### 5.20 Optional Module Headers and Automatic Standard Prelude
AIPL files may optionally declare a module header (`module ModName`). When omitted, the module name is inferred from the file basename. The compiler automatically injects an ambient standard prelude containing essential symbols:
- `std.cli`: `parseCliArgs`
- `std.grid`: `gridNew`, `gridSet`, `grid2dNew`, `grid2dSet`
- `std.pathfinding`: `gridAStar`

### 5.21 Compact Single-Line Structs and Positional Constructors
Structs can be declared concisely on a single line using tuple-parameter syntax or inline colon syntax:
```text
pub struct Point(x: float, y: float = 0.0)
pub struct ColorRgb: r: byte, g: byte, b: byte
```
Struct instances may be constructed positionally (`Point(1.0, 2.0)`) or via named fields (`Point(x = 1.0, y = 2.0)`). Unspecified trailing parameters are automatically filled with declared default expressions.

### 5.22 Range Slicing
Strings and arrays support Pythonic zero-allocation range slicing:
- **Syntax**: `collection[start..end]`, `collection[start..]`, `collection[..end]`
- **Semantics**: Evaluates half-open intervals `[start, end)`. Negative offsets or out-of-bounds indices are bounded safely.

### 5.23 Membership Operator `in`
The binary relational operator `in` evaluates element containment across standard collections:
- `x in array`: Linear scan or primitive membership test.
- `k in map`: $O(1)$ key existence check.
- `item in set`: $O(1)$ set membership check.
- `needle in haystack`: Substring search.

### 5.24 Null and Fallible Coalescing Operator `??`
The right-associative coalescing operator `??` provides concise default values for `nil`, `Option[T]`, and `Result[T, E]`:
```text
let name = optionalName ?? "DefaultName"
let port = parsePort(inputStr) ?? 8080
```

### 5.25 Intrinsic Annotations `@intrinsic`
Functions and symbols decorated with `@intrinsic` are lowered directly to target-specific hardware instructions, compiler intrinsics, or pure-runtime inline functions without function call overhead.

---

## 6. Refinements & Contracts

AIPL integrates native refinement types and formal contract verification directly into the core language semantics. Refinement types allow types to be constrained by arbitrary boolean predicate expressions drawn from Quantifier-Free Linear Integer Arithmetic (QF-LIA) and Equality with Uninterpreted Functions (EUF).

Refinement verification is discharged at compile time by the embedded, zero-dependency SMT solver (`compiler/smt.aipl`), guaranteeing memory safety, mathematical validity, and zero runtime penalty.

### 6.1 Syntax and Predicate Grammar

Refinement types are declared using set-builder notation `{ <param>: <BaseType> | <predicate> }`:

```aipl
type Port = { p: int | p >= 1 and p <= 65535 }
type Index = { i: int | i >= 0 and i < 1024 }
type NonZero = { n: int | n != 0 }
type Positive = { x: int | x > 0 }
type Normalized = { f: float | f >= 0.0 and f <= 1.0 }
```

The refinement predicate expression follows the grammar specified in Section 3:
- Boolean conjunction (`and`), disjunction (`or`), and negation (`not`).
- Relational comparisons (`==`, `!=`, `<`, `<=`, `>`, `>=`).
- Linear integer arithmetic terms ($a \cdot x + b \cdot y + c$).
- Equational terms over pure uninterpreted functions and constructors.

### 6.2 Refinement Subtyping Semantics ($R_1 <: R_2$)

Refinements in AIPL follow semantic subtyping:
1. **Base Type Subtyping**: Any refined type $\{ x: T \mid P(x) \}$ is a sound behavioral subtype of its unrefined base type $T$:
   $$\{ x: T \mid P(x) \} <: T$$
   A value of type `Port` can always be passed without conversion or runtime guards to a function expecting `int`.
2. **Refinement Subtyping Proof**: Given two refinement types $R_1 = \{ x: T \mid P_1(x) \}$ and $R_2 = \{ x: T \mid P_2(x) \}$, $R_1$ is a subtype of $R_2$ if and only if $P_1$ logically entails $P_2$:
   $$R_1 <: R_2 \iff \forall x \in T.\; P_1(x) \implies P_2(x)$$
   The embedded SMT solver verifies this entailment by checking the satisfiability of the negation:
   $$\text{Formula: } P_1(x) \land \neg P_2(x)$$
   - If **UNSAT**: The entailment holds universally. The subtyping relation $R_1 <: R_2$ is formally proven at compile time with zero runtime checks.
   - If **SAT**: A concrete counter-example $x = c$ is extracted from the model, and compilation halts with diagnostic `AIPL_E3001_REFINEMENT_VIOLATION`.

```aipl
type SmallPort = { p: int | p >= 80 and p <= 443 }
type Port = { p: int | p >= 1 and p <= 65535 }

fn serve(p: Port): void:
  // ... binds port ...

fn start(sp: SmallPort): void:
  // Formally proven at compile time: [80, 443] ⊆ [1, 65535] (UNSAT for p in [80,443] and (p < 1 or p > 65535))
  serve(sp) // OK! Zero runtime checks.
```

### 6.3 Compile-Time Division-by-Zero Refutation (`AIPL_E2007_POSSIBLE_DIVISION_BY_ZERO`)

Every integer division operation `a / b` generates a verification condition (VC) to prove that the divisor cannot be zero:
$$\text{VC: } \Gamma \land (b = 0)$$
where $\Gamma$ represents the path condition collected along the current execution path.

- If $\Gamma \land (b = 0)$ is **SAT**: The divisor can potentially evaluate to zero. Compilation is rejected at compile time with diagnostic `AIPL_E2007_POSSIBLE_DIVISION_BY_ZERO` (short code `E2007`), including a concrete counter-example and candidate repair diff:
  ```aipl-invalid
  fn calculateRatio(total: int, count: int): int:
    // ERROR AIPL_E2007_POSSIBLE_DIVISION_BY_ZERO:
    // Divisor 'count' may evaluate to zero. Counter-example: count = 0.
    total / count
  ```
- If $\Gamma \land (b = 0)$ is **UNSAT**: The path condition mathematically precludes zero (e.g. via an upstream guard `if count != 0:` or `if count > 0:`), and the division is accepted with zero runtime checks.

### 6.4 Static Buffer and Array Index Bounds Refutation (`AIPL_E2008_ARRAY_INDEX_OUT_OF_BOUNDS`)

Every indexing expression `buf[i]` into a buffer `Buffer[T, N]` or array `[T; N]` of capacity $N$ generates a bounds verification condition:
$$\text{VC: } \Gamma \land (i < 0 \lor i \ge N)$$

- If $\Gamma \land (i < 0 \lor i \ge N)$ is **SAT**: The index $i$ may fall outside the allocated buffer boundaries $[0, N-1]$. The compiler halts with diagnostic `AIPL_E2008_ARRAY_INDEX_OUT_OF_BOUNDS` (short code `E2008`), displaying the violating index expression, buffer capacity, and counter-example:
  ```aipl-invalid
  let buf: Buffer[float, 100] = Buffer()
  let idx = 150
  // ERROR AIPL_E2008_ARRAY_INDEX_OUT_OF_BOUNDS:
  // Array index out of bounds: index expression '150' exceeds buffer capacity 100.
  let val = buf[idx]
  ```
- If guarded by an explicit range assertion (e.g., `if idx >= 0 and idx < 100:`), the solver proves the VC is **UNSAT** and accepts the code without runtime bounds checks.

### 6.5 Inductive Loop Invariant Bounds Check Elimination

In iterative traversals using range expressions:
```aipl
for i in 0..100:
  buf[i] = 1.0
```
The range expression `0..100` establishes the loop invariant:
$$0 \le i < 100$$
During verification pass analysis, the loop invariant $i \in [0, 99]$ is asserted in a scoped solver context for the body of the loop.
For `buf[i]` (with `buf: Buffer[float, 100]`):
$$\Gamma = \{ 0 \le i, i < 100 \}$$
$$\text{VC: } \Gamma \land (i < 0 \lor i \ge 100) \implies \text{UNSAT}$$
The solver mathematically refutes out-of-bounds access. The index check is eliminated statically at compile time, achieving C/Rust-level memory access speeds with total safety.

### 6.6 Embedded Lightweight SMT Architecture

Refinement solving in AIPL is executed entirely by an embedded, deterministic self-hosted solver engine (`compiler/smt.aipl`) without invoking external solver binaries (e.g. Z3, CVC5) or dynamic linking:
- **Quantifier-Free Linear Integer Arithmetic (QF-LIA)**: Solved using Interval Constraint Propagation (ICP) over saturated intervals $[L, U] \subseteq \mathbb{Z} \cup \{-\infty, +\infty\}$.
- **Equality with Uninterpreted Functions (EUF)**: Solved via Nelson-Oppen congruence closure over a signature table with Union-Find (rank and path compression), alongside algebraic normalization ($z - z \to 0$).
- **Footprint & Performance SLA**:
  - Code size: $<3,000$ lines of self-hosted AIPL.
  - Memory footprint: $<2$ MB resident memory.
  - Query latency: $<0.1$ ms average query latency ($>10,000$ queries/sec).

---

## 7. Systems, Components, and Shaders (ECS Architecture)

AIPL natively treats high-performance Entity Component System (ECS) patterns and WebGL/WebGPU shaders as first-class language constructs.

### 7.1 Component Declarations
A `component` defines contiguous, cache-aligned data layout without behavior:
```aipl
component Transform:
  x: float
  y: float
  z: float
  rotation: float
```
Components are guaranteed to be stored in Structure-of-Arrays (SoA) layouts across memory pages.

### 7.2 System Declarations
A `system` declares query-driven iteration over components:
```aipl
system MovementSystem(mut Transform, Velocity):
  for entity in query:
    entity.Transform.x += entity.Velocity.vx * dt
    entity.Transform.y += entity.Velocity.vy * dt
```

### 7.3 First-Class Embedded Shader Declarations
AIPL treats GPU pipeline shaders as first-class language items. Shaders are declared using the `shader` keyword with mandatory pipeline stage annotations (`vertex`, `fragment`, `compute`) and optional shading dialect specifiers (`glsl`, `wgsl`):

```aipl
// GLSL Vertex Shader Block
shader ParticleVert(vertex) glsl:
  layout(location = 0) in vec2 a_pos;
  layout(location = 1) in vec2 a_vel;
  layout(binding = 0) uniform CameraBlock {
    mat4 u_view_proj;
  };
  void main() {
    gl_Position = u_view_proj * vec4(a_pos, 0.0, 1.0);
  }

// WGSL Fragment Shader Block
shader QuadFrag(fragment) wgsl:
  struct FragInput {
    @location(0) uv: vec2<f32>,
  }

  @fragment
  fn fs_main(in: FragInput) -> @location(0) vec4<f32> {
    return vec4<f32>(in.uv, 0.0, 1.0);
  }
```

Embedded shader blocks undergo compile-time static reflection (`compiler/ast.aipl` and `compiler/codegen_ts.aipl`), extracting vertex attribute locations, uniform block definitions, and entry points into Canonical `HirShader` representations.

### 7.4 Static Vertex Attribute Contract Verification (`AIPL_E0503_VERTEX_ATTRIBUTE_MISMATCH`)
Vertex input attributes declared in a vertex shader establish an explicit contract with the host CPU struct layout (`compiler/ast.aipl` and `compiler/types.aipl`). The compiler statically verifies that:
1. **Field-to-Attribute Correspondence**: Every field in the host struct matches a vertex attribute by name (e.g. `pos` matches `a_pos`, `in_pos`, or `pos`) and 0-indexed location (`layout(location = i)` or `@location(i)`).
2. **Type Compatibility**: Host types match shader attribute types (`HirType::Vec2` $\leftrightarrow$ `vec2` / `vec2<f32>`, `HirType::Vec4` $\leftrightarrow$ `vec4` / `vec4<f32>`).
3. **No Extraneous Attributes**: The shader does not declare vertex inputs unbacked by host buffer storage.

If a mismatch occurs, compilation halts with `AIPL_E0503_VERTEX_ATTRIBUTE_MISMATCH` with exact AST coordinates and automated candidate repair diffs.

### 7.5 std140 & WGSL Uniform Buffer Alignment Invariant (`AIPL_E0501_STD140_PADDING_HAZARD`)
Uniform buffers bound to GPU pipelines operate under strict memory alignment rules mandated by OpenGL std140 and WebGPU WGSL specifications:
- **Base Alignment Rules**: Scalars (`float`, `int`) require 4-byte alignment; `vec2` requires 8-byte alignment; `vec4` and matrices require 16-byte alignment.
- **The `vec3` Padding Hazard**: Standalone 3-component vectors (`vec3`, `vec3<f32>`) have a size of 12 bytes but mandate a **16-byte base alignment** (rounded up to the size of a `vec4`). This inserts an implicit 4-byte padding hole after every `vec3` field. When host arrays (`Float32Array` or C-style structs) pack fields contiguously without this hole, CPU-GPU data transfer causes silent memory misalignment and corrupted shader uniforms.
- **Compile-Time Ban**: AIPL statically bans `vec3` fields in uniform structs and shader uniform blocks, emitting diagnostic `AIPL_E0501_STD140_PADDING_HAZARD`.
- **Recommended Resolution**: Replace hazardous `vec3` fields with 16-byte `vec4` (or `vec4<f32>`), packing scalar components (e.g. lifetime, speed, flags) into the `.w` component.

```aipl-invalid
// Compile Error AIPL_E0501_STD140_PADDING_HAZARD:
// Field 'pos' in uniform struct 'ParticleData' has 12-byte size but requires 16-byte alignment.
struct ParticleData:
  pos: vec3
  speed: float
```

```aipl
// Correct: Explicit 16-byte vec4 with .w packing
struct ParticleData:
  posAndSpeed: vec4  // xyz = pos, w = speed
```

### 7.6 Dynamic Uniform Buffer 256-Byte Offset Alignment (`AIPL_E0502_UNIFORM_OFFSET_NOT_ALIGNED_256`)
Modern GPU backends (specifically WebGPU's `minUniformBufferOffsetAlignment` and Vulkan physical device limits) mandate that dynamic uniform buffer offsets MUST be aligned to **256 bytes**:
$$\text{offset} \pmod{256} = 0$$

Passing an offset not divisible by 256 triggers compile-time diagnostic `AIPL_E0502_UNIFORM_OFFSET_NOT_ALIGNED_256`. The diagnostic calculates the next valid aligned boundary $\lceil \text{offset} / 256 \rceil \times 256$ and synthesizes an automated candidate repair patch.

---

## 8. Lossless Concrete Syntax Tree & Bidirectional Lens Laws

The AIPL compiler infrastructure (`compiler/parser.aipl` and `compiler/ast.aipl`) implements a mathematically proven, lossless Concrete Syntax Tree (CST) and bidirectional lens engine. This architecture empowers autonomous AI coding agents to inspect, refactor, and mutate source code while guaranteeing zero diff drift and preserving 100% of formatting, comments, and spacing.

### 8.1 Lossless Concrete Syntax Tree (CST) Data Architecture
Unlike traditional Abstract Syntax Trees (ASTs) which discard non-semantic tokens, the AIPL CST captures 100% of input bytes:

1. **Full Trivia Preservation**:
   - **Horizontal Whitespace**: Exact contiguous space (` `) and tab (`\t`) sequences.
   - **Vertical Line Endings**: Unix LF (`\n`) and Windows CRLF (`\r\n`) preserved without normalization.
   - **Line Comments**: Single-line comments (`// ...`) retained in place.
   - **Doc Comments**: Triple-slash documentation comments (`/// ...`) attached directly to the following item.
   - **Block Comments**: Multi-line comments (`/* ... */`) preserved with internal line breaks.
   - **Vertical Blank Lines**: Contiguous blank lines between top-level items, functions, and blocks are preserved verbatim.
2. **Unified Tree Representation**:
   - `CstToken`: Leaf token with `kind: CstTokenKind`, `text: String`, and byte-exact `span: Span`.
   - `CstNode`: Interior syntax node with `kind: CstNodeKind`, `children: Vec<CstElement>`, and `span: Span`.
   - `CstElement`: Sum type of either `CstElement::Node(CstNode)` or `CstElement::Token(CstToken)`.
   - `CstView`: Root encapsulation of the compilation unit `Module` node.
3. **Linear $O(N)$ Coordinate Recomputation**:
   Following any tree mutation, `recompute_spans()` walks the tree depth-first from offset 0, updating `[start, end)` byte offsets and 1-indexed `(line, column)` coordinates across all tokens and nodes in $O(N)$ time.

### 8.2 Formal Bidirectional Lens Equations
The lens engine exposes two primitive mathematical operators:
- $\text{get}: \text{SourceText} \to \text{CstView}$
- $\text{put}: \text{SourceText} \times \text{CstView} \to \text{SourceText}$

The engine formally enforces the two classical bidirectional lens laws (Foster et al., 2007):

#### Law 1: GetPut (Zero-Diff Identity)
$$\forall s \in \text{SourceText}, \quad \text{Put}(s, \text{Get}(s)) \equiv s$$

Roundtripping unmodified source code through the CST produces byte-for-byte identical output. The git diff of this operation is strictly 0 bytes:
$$\Delta(\text{Source}, \text{Synthesized}) = 0 \text{ bytes}$$

#### Law 2: PutGet (View Roundtrip Consistency)
$$\forall s \in \text{SourceText}, \forall v \in \text{CstView}, \quad \text{Get}(\text{Put}(s, v)) \equiv v$$

Synthesizing updated source text from a modified CST view $v$ and subsequently re-parsing it yields an identical CST view in tree structure, node kinds, tokens, and coordinates.

### 8.3 Surgical Node Replacement & Zero Diff Drift Invariant
When an autonomous AI agent mutates a function, statement, or node spanning byte range $[A, B)$ with replacement $N'$ spanning $[A, B')$:
1. **Targeted Range Mutation**: Modifications are strictly confined to the targeted node.
2. **Prefix Invariance**:
   $$\text{Updated}[0..A) \equiv \text{Source}[0..A)$$
3. **Suffix Invariance**:
   $$\text{Updated}[B'..\text{Len}') \equiv \text{Source}[B..\text{Len})$$
4. **Surrounding Trivia Invariance**:
   All docstrings, inline comments, intermediate block comments, and blank lines preceding $A$ or succeeding $B$ remain byte-for-byte untouched.

### 8.4 AI Agent Refactoring Interface
The `CstView` and `lens` APIs provide high-level transactional methods for autonomous refactoring:
- `view.replace_function(name: &str, new_fn: CstNode) -> bool`: Replaces an entire function node by name.
- `view.replace_function_body(name: &str, new_body: CstNode) -> bool`: Replaces only the body block of a function, preserving signatures and docstrings.
- `view.replace_statement(fn_name: &str, stmt_index: usize, new_stmt: CstNode) -> bool`: Replaces a single statement within a function body.
- `view.replace_node(target_span: Span, replacement: CstNode) -> bool`: Replaces an arbitrary node by exact source byte span.
- `compute_replacement_range(original: &str, updated: &str) -> Option<(usize, usize, usize, usize)>`: Computes the minimal common prefix/suffix diff range to verify zero drift outside edited regions.

---

## 9. Compiler Diagnostics & Poisoned Cascade Suppression Specification

The AIPL compiler (`aipl`) implements a formal machine-readable diagnostics protocol tailored for autonomous AI coding agents, defined in `docs/DIAGNOSTICS_SCHEMA.md` and implemented across `compiler/diag.aipl`, `compiler/hir.aipl`, and `compiler/types.aipl`.

### 9.1 Single-Root JSON Document Invariant
All compiler diagnostic passes (lexical, grammatical, name resolution, type inference, and SMT refinement solving) emit output conforming to schema `https://aipl.dev/schemas/diagnostic-v1.json`:
- **Single-Root Structure**: Emitted as a unified `AiplDiagnosticReport` including `file`, SHA-256 `file_hash`, compilation `status`, `summary` metrics, and `diagnostics` array.
- **Exact Coordinates**: Every diagnostic location defines a 0-indexed byte span `[start_byte, end_byte)`, 1-indexed `(line, column)` coordinates, and `utf16_offset`.
- **Zero ANSI Guarantee**: Diagnostics contain strictly 0 bytes matching ANSI escape sequences (`\x1b[`).

### 9.2 Poisoned Symbol Semantics & Propagation Rules
When an identifier, type, or expression fails validation, the compiler initiates semantic tainting:
1. **Primary Fault Isolation**: The initial failure is assigned a fresh diagnostic ID (`ERR-1001`) with `"role": "primary_fault"`, `"cascade": false`, and `"root_cause_id": null`.
2. **Scope-Aware Registry (`TaintedSymbolRegistry`)**:
   - **Module-Level Poisoning**: Missing nominal types or unimported top-level symbols are registered globally in the module registry.
   - **Lexical Scope Poisoning**: Invalid local variables or parameters are recorded only in the active lexical scope stack frame, preventing taint leakage across sibling blocks or outer functions.
3. **Type Lowering & Inference Short-Circuiting**:
   - Referencing an undeclared nominal type returns `HirType::Error`.
   - Variable bindings initialized from `HirType::Error` automatically poison the bound identifier.
   - Downstream operations on `HirType::Error` or tainted identifiers short-circuit redundant error emission and emit cascading consequences.
4. **Referential Causal Linkage**: Cascading errors must declare `"role": "cascading_consequence"`, `"cascade": true`, and link directly to `"root_cause_id"`.
5. **Independent Error Non-Suppression Invariant**: Real, independent syntax or type errors on unrelated lines must NOT be suppressed and must be reported as primary faults.

### 9.3 Autonomous Agent Filtering Mode
To optimize LLM context window consumption, the diagnostic report supports agent filtering (`filter_cascades = true`):
- When enabled, cascading secondary diagnostics are excluded from the `diagnostics` array, reducing output size by up to 98%.
- The `summary` object tracks exact global counts:
  $$\text{total\_diagnostics} = \text{primary\_errors} + \text{cascading\_suppressed}$$

---

## 10. Standard Library Reference (`std/*.aipl` & `std/sys/*.aipl`)

AIPL ships with a comprehensive standard library structured into a 3-Layer Stratified Package Hierarchy with zero external third-party dependencies: Layer 0 Runtime Intrinsics (`std/sys`), Layer 1 Universal Core (`std/core`, `std/math`, `std/collections`, `std/time`, `std/text`, `std/serde`, `std/io`, `std/net`), and Layer 2 Engine Kits (`std/gfx`, `std/ui`, `std/sim`, `std/audio`) with backward-compatible re-export facades (see [docs/STDLIB_REFERENCE.md](STDLIB_REFERENCE.md) for the complete reference). Modules can be imported via hierarchical dot syntax (`import std.<domain>.<mod>`, e.g. `import std.core.math`, `import std.gfx.canvas`, `import std.sys.mem`) or canonical path strings (`import { symbol } from "std/<domain>/<mod>"`).

### 10.1 Collections & Data Structures (8 Modules)

| Module | File Path | Description & Core API |
| :--- | :--- | :--- |
| `array` | `std/array.aipl` | Contiguous dynamic arrays, resizing, slicing, searching, and higher-order array helpers. |
| `collections` | `std/collections.aipl` | Standard high-level collections: `Map[K, V]` (hash map), `Set[T]`, `Queue[T]`, `Stack[T]`, `PriorityQueue[T]`, `RingBuffer` (delegating to `std/buffer`). |
| `ecs` | `std/ecs.aipl` | Entity Component System (ECS) archetype world registry, generational entity IDs, component bitmasks, and deterministic queries. |
| `grid` | `std/grid.aipl` | 2D discrete spatial grid layout, coordinate translation `(x, y) <-> index`, 4-way/8-way neighbour iteration, boundary clamping, flood-fill. |
| `heap` | `std/heap.aipl` | Binary min-heap and max-heap priority queues with $O(\log N)$ push/pop and $O(1)$ peek. |
| `pool` | `std/pool.aipl` | Zero-allocation object pool, generational reusable handles, free-list recycled storage for high-frequency entity allocation. |
| `sort` | `std/sort.aipl` | In-place quicksort, mergesort, insertion sort for small slices, custom comparator callbacks, stable sort variants. |
| `string` | `std/string.aipl` | UTF-8 string manipulation, `StringBuilder`, splitting, joining, trimming, padding, and search helpers. |

### 10.2 Math, Physics & Geometry (17 Modules)

| Module | File Path | Description & Core API |
| :--- | :--- | :--- |
| `analytics` | `std/analytics.aipl` | Financial and RevOps analytics, tiered commission accelerators, quota attainment, and cohort metrics. |
| `geom2d` | `std/geom2d.aipl` | Canonical 2D vector mathematics (`Vec2`), bounding rectangles (`Rect2D`), circles, `SweptHit`/`sweptAabb`, line and ray intersection testing. |
| `geom3d` | `std/geom3d.aipl` | 3D vectors (`Vec3`), quaternions (`Quat`), 4x4 transformation matrices (`Mat4`), rays, axis-aligned bounding boxes (`AABB3D`), view frustum culling. |
| `gravity` | `std/gravity.aipl` | N-body point-mass gravitational wells, softened inverse-square acceleration fields, and radial blast falloff. |
| `iso` | `std/iso.aipl` | 2.5D isometric projection, axial hex coordinate math, heightfield prisms, depth sorting, and portal geometry. |
| `math` | `std/math.aipl` | Fundamental math & SIMD functions: `sin`, `cos`, `tan`, `atan2`, `sqrt`, `pow`, `abs`, `min`, `max`, `clamp`, `lerp`, 8-wide SIMD dot/AXPY, bitboards. |
| `navgrid` | `std/navgrid.aipl` | Octile grid navigation heuristics, Bresenham line-of-sight, bunny-hop air acceleration, and cellular step rules. |
| `pathfinding` | `std/pathfinding.aipl` | Grid-based A* (A-Star) search, Dijkstra shortest path, heuristic cost functions (Manhattan, Euclidean, Chebyshev), path smoothing. |
| `physics` | `std/physics.aipl` | 2D rigid body dynamics, semi-implicit Euler & Verlet integrators, circle-AABB collision detection, impulse resolution, and raycasts. |
| `physics2d3d` | `std/physics2d3d.aipl` | Unified 2D/3D symplectic Euler kinematics, 3D AABB/sphere overlap, elastic impulses, Sobel normal maps, and toroidal wrapping. |
| `procgen` | `std/procgen.aipl` | Deterministic seeded PRNG, 2D Value noise, Fractal Brownian Motion (fBm), BSP dungeon rooms, and cellular cave generation. |
| `random` | `std/random.aipl` | Deterministic pseudo-random number generation (PCG32, Xorshift128+), uniform integers/floats, gaussian distributions, seed management. |
| `sim/cellular` | `std/sim/cellular.aipl` | Generic 2D cellular automata stepping (`cellularStepDensitySwap`), pairwise reaction matrix, Laplacian scalar diffusion, dirty chunks. |
| `sim/inventory` | `std/sim/inventory.aipl` | Generic 2D grid/bin container packing (`gridContainerCreate`), weighted modifier tables, recipe matching, DAG unlocks. |
| `spline` | `std/spline.aipl` | Parametric curve generation: cubic Bézier curves, Catmull-Rom splines, Hermite interpolation, arc-length lookup tables. |
| `spring` | `std/spring.aipl` | Second-order damped harmonic oscillator physics, critically damped springs for UI micro-affordances and fluid camera smoothing. |
| `transform` | `std/transform.aipl` | Hierarchical 2D/3D coordinate transformations, parent-child scene graph propagation, local vs. world matrix synchronization. |

### 10.3 Graphics, Audio, World & UI (24 Modules)

| Module | File Path | Description & Core API |
| :--- | :--- | :--- |
| `anim` | `std/anim.aipl` | Sprite-sheet animation state machines, keyframe timelines, and 2D forward/inverse kinematics (`solveChainFK2D`, `solveTwoBoneIK2D`). |
| `asset` | `std/asset.aipl` | Multi-format asset loader and cache manager: image bitmaps, audio buffers, font glyphs, and binary blobs with progress tracking. |
| `audio` | `std/audio.aipl` | Procedural Web Audio and native PCM sound synthesis, multi-voice mixer, ADSR envelopes, pitch ladders, voice pooling. |
| `aura` | `std/aura.aipl` | AuraDS Material Design 3 immediate-mode vector UI, 24-theme palette engine, collision-free `AuraFlowContainer`, OS clipboard/text selection (`auraTextField` with `Ctrl+C`/`X`/`V`/`A` & `Delete`), combobox dropdowns (`auraSelectDropdown`), OS multi-selection (`AuraMultiSelectState`, `auraMultiSelectHandleClick` with `Click`/`Ctrl+Click`/`Shift+Click`/`Ctrl+A`), telemetry charts, and Game HUDs. |
| `canvas` | `std/canvas.aipl` | Immediate-mode 2D hardware-accelerated drawing API: paths, arcs, beziers, fills, strokes, SoA batching, subpixel AA, and frame pacing. |
| `charbody` | `std/charbody.aipl` | Procedural articulated multi-limb character rigs, 8-way/4-way pose interpolation, first-person weapon viewmodels, and melee swing trails. |
| `color` | `std/color.aipl` | Color space conversion (RGB, RGBA, HSL, Hex `#RRGGBB`), alpha blending, photometric Weber contrast calculation, color palettes. |
| `fx` | `std/fx.aipl` | Dynamic game-feel juiciness engine: Trauma² screen shake (Squirrel Eiserloh model), decoupled hit-stops, cyber-graze near-miss particle emitters. |
| `game` | `std/game.aipl` | Cross-platform game loop runtime: `Camera2D`, `SpriteAnimator`, `PlatformerFeel`, steering behaviors (`steerSeek`, `steerFlee`, `steerArrive`), and genre telemetry. |
| `gpu` | `std/gpu.aipl` | WebGPU WGSL compute shader pipeline generation, workgroup shared memory, triple-buffered staging rings, and SWAR bitboard intrinsics. |
| `image` | `std/image.aipl` | Universal 12-format image detection, raw RGBA pixel buffer manipulation, PNG/BMP/PPM I/O, blitting, sprite-sheet slicing, and convolution filters. |
| `lighting` | `std/lighting.aipl` | Dynamic 2D/3D point and spot light attenuation, Lambertian diffuse shading, 2D shadow visibility raycasting, and NVG phosphor gain. |
| `lut` | `std/lut.aipl` | 3D color-grading lookup tables (LUT), cubic tone curves, gamma levels, gradient stop mapping, and night-vision scanlines. |
| `particles` | `std/particles.aipl` | Multi-perspective particle emitters, parabolic ribbon arcs, jagged lightning ribbons, spiral missile wakes, surface decals, and 30-bit spectrum dispersion. |
| `skeletal` | `std/skeletal.aipl` | 2D/3D bone hierarchy forward kinematics, analytical two-bone IK solver, Hermite keyframe interpolation, and articulated biped rendering. |
| `spatial_audio` | `std/spatial_audio.aipl` | 3D distance gain attenuation, 2D stereo panning, relativistic Doppler pitch shift, wall occlusion low-pass filters, and RT60 room reverb. |
| `tilemap` | `std/tilemap.aipl` | 2D orthogonal tilemaps, ASCII level loading, kinematic `tilemapMoveAndSlide`, branching RPG dialogue trees, and item inventories. |
| `tween` | `std/tween.aipl` | Easing functions (linear, quad, cubic, elastic, bounce, back), tween timeline sequencing, interpolation state transitions. |
| `ui` | `std/ui.aipl` | Declarative and immediate-mode UI panels, KPI cards, tabs, progress bars, waterfall step bars, and pointer/touch event dispatch. |
| `ui/datagrid` | `std/ui/datagrid.aipl` | Generic virtualized data tables, column sorting/filtering, inline sparklines, swimlane boards, command palette fuzzy search. |
| `ui/nodegraph` | `std/ui/nodegraph.aipl` | Generic cubic Bezier node-graph editor, port hit-testing, topological evaluation, split dock layout, undo/redo stack. |
| `viewport` | `std/viewport.aipl` | Aspect-ratio preserving viewport scaling, letterbox/pillarbox framing, mouse coordinate unprojection, perspective vanishing guides, and liquify mesh warp. |
| `weather` | `std/weather.aipl` | Procedural rain/snow wind turbulence, fractal step-leader lightning bolts, 2D value/fBm terrain noise, and precipitation overlays. |
| `worldgen` | `std/worldgen.aipl` | Multi-perspective 2D/2.5D/Isometric/3D world projection, sky/floor horizons, 3D blocks, corridors, heightmap sampling, and portals. |

### 10.4 I/O, Filesystem & Operating System (9 Modules)

| Module | File Path | Description & Core API |
| :--- | :--- | :--- |
| `buffer` | `std/buffer.aipl` | Contiguous linear `ByteBuffer`, endian-aware primitives (`byteBufWriteU16BE`, `byteBufWriteU32BE`), and canonical `RingBuffer` circular queues. |
| `cli` | `std/cli.aipl` | Command-line interface argument parser: flag options (`--opt`, `-o`), subcommands, required positional arguments, auto-generated help. |
| `dotenv` | `std/dotenv.aipl` | Environment file `.env` parser, variable substitution, multi-line quoted values, system environment merging. |
| `env` | `std/env.aipl` | Process environment inspection, variable get/set, working directory retrieval, platform architecture and OS detection. |
| `fs` | `std/fs.aipl` | Safe filesystem operations: `readFile`, `writeFile`, `appendFile`, `removeFile`, `makeDir`, `listDir`, atomic file replacement. |
| `io` | `std/io.aipl` | Standard input/output streams (`stdin`, `stdout`, `stderr`), line-by-line buffered reader, formatted stream printing. |
| `path` | `std/path.aipl` | Cross-platform filesystem path normalization, joining (`join`), directory name (`dirName`), base name (`baseName`), extension extraction. |
| `process` | `std/process.aipl` | Subprocess execution, piped stdin/stdout/stderr capture, process exit status inspection, process kill signals. |
| `term` | `std/term.aipl` | Terminal ANSI escape sequences: 24-bit truecolor text styling, cursor repositioning, screen clearing, raw terminal input mode. |

### 10.5 Networking & Web (4 Modules)

| Module | File Path | Description & Core API |
| :--- | :--- | :--- |
| `dns` | `std/dns.aipl` | Domain Name System resolver: IPv4 (A) and IPv6 (AAAA) query lookups, reverse address mapping, DNS packet parsing. |
| `html` | `std/html.aipl` | HTML5 document generation, DOM node serialization, entity encoding/escaping (`&amp;`, `&lt;`, `&gt;`), template sanitization. |
| `http` | `std/http.aipl` | Canonical HTTP 1.1 client and router: `HttpRequest`, `HttpResponse`, `httpGet`, `httpPost`, `httpFetch`, `Route`, and URL encoding (via `std/encoding`). |
| `net` | `std/net.aipl` | Raw IPv4/IPv6 address validation, `SocketAddr`, `Url` parsing, and TCP/UDP socket abstractions (`tcpConnect`, `tcpSend`, `tcpClose`). |

### 10.6 Data Formats, Documents, Serialization & Parsing (14 Modules)

| Module | File Path | Description & Core API |
| :--- | :--- | :--- |
| `compress` | `std/compress.aipl` | Lossless data compression and decompression: DEFLATE bitstream decoding, RFC 1950 zlib, RFC 1952 gzip wrapper handling. |
| `csv` | `std/csv.aipl` | Comma-Separated Values parser and serializer: custom delimiters, quote escaping, tabular header mapping. |
| `diff` | `std/diff.aipl` | Myers text diff algorithm, unified diff format generation (`--- / +++`), hunk calculation, patch application. |
| `doc` | `std/doc.aipl` | Universal document model (`UniversalDocument`), spec-compliant `%PDF-1.4` emitter/extractor, RTF/LaTeX/HTML exporters, relational table queries, and slide decks. |
| `encoding` | `std/encoding.aipl` | Binary-to-text encoding: Base64 encoding/decoding, hexadecimal conversion, canonical URL percent encoding/decoding (`urlEncode`, `urlDecode`). |
| `ini` | `std/ini.aipl` | INI configuration parser and serializer with `[section]` hierarchy and typed key-value getters. |
| `json` | `std/json.aipl` | RFC 8259 JSON parser and serializer: recursive `JsonValue` tagged sum type, stringification, key extraction. |
| `markdown` | `std/markdown.aipl` | CommonMark markdown parser: headings, bullet/numbered lists, inline bold/italic, fenced code blocks, HTML emission. |
| `qrcode` | `std/qrcode.aipl` | QR Code 2D barcode generator: Reed-Solomon error correction, version/mask selection, binary matrix pixel rendering. |
| `regex` | `std/regex.aipl` | Regular expression engine: Thompson NFA construction, DFA simulation, character classes, repetitions (`*`, `+`, `?`), capture groups. |
| `tar` | `std/tar.aipl` | TAR tape archive creation and extraction: 512-byte UStar header parsing, checksum verification, file entry extraction. |
| `toml` | `std/toml.aipl` | TOML v1.0.0 configuration parser and serializer supporting `[table]` sections and key-value extraction. |
| `xml` | `std/xml.aipl` | XML 1.0 parser and DOM tree builder: element tags, attributes, CDATA blocks, hierarchical node query traversal. |
| `yaml` | `std/yaml.aipl` | YAML 1.2 subset parser and emitter supporting mappings, lists, and JSON conversion (`yamlToJson`). |

### 10.7 Security, Cryptography & Database (3 Modules)

| Module | File Path | Description & Core API |
| :--- | :--- | :--- |
| `crypto` | `std/crypto.aipl` | Cryptographic primitives: SHA-256 and SHA-512 hashing, HMAC message authentication, constant-time equality comparison, ChaCha20/AES-GCM encryption. |
| `db` | `std/db.aipl` | Embedded relational SQLite3 database engine, parameterized queries, schema migrations, and ACID transactions. |
| `uuid` | `std/uuid.aipl` | Universally Unique Identifier generation and parsing: RFC 4122 UUID v4 (random entropy) and UUID v5 (SHA-1 namespace hashed). |

### 10.8 Time, Testing & Utilities (6 Modules)

| Module | File Path | Description & Core API |
| :--- | :--- | :--- |
| `cron` | `std/cron.aipl` | Cron expression scheduler: 5-field/6-field crontab parsing (minute, hour, dom, month, dow), next execution matching. |
| `date` | `std/date.aipl` | Calendar date calculations (`Date`): `isLeapYear`, `daysInMonth`, `dateToEpochDays`, `epochDaysToDate`, `dateAddDays`, `dateDiffDays`, `dateDayOfWeek`. |
| `datetime` | `std/datetime.aipl` | Civil timestamps (`DateTime`, `CivilDateTime`), Hinnant `unixToCivil`/`civilToUnix`, ISO-8601 (`parseIso8601`, `formatIso8601`), RFC-2822/822, and duration formatting. |
| `semver` | `std/semver.aipl` | Semantic Versioning 2.0.0 parser and evaluator: `major.minor.patch`, prerelease tags, build metadata, version range matching (`^`, `~`, `>=`). |
| `test` | `std/test.aipl` | Built-in unit testing and assertion framework: `assert`, `assertEqual`, `assertTrue`, benchmark execution, test suite runner. |
| `time` | `std/time.aipl` | High-resolution monotonic timers, wall-clock time, sleep execution delays, duration formatting and stopwatch measurements. |

### 10.9 Systems, Concurrency, Memory, FFI & Pure-AIPL Runtime (14 Modules)

| Module | File Path | Description & Core API |
| :--- | :--- | :--- |
| `arena` | `std/arena.aipl` | Scoped regional scratch arena allocation and deterministic zero-overhead bulk reclamation (`arenaMark`, `arenaReset`, `withScratchArena`). |
| `async` | `std/async.aipl` | Asynchronous task scheduling, futures/promises, event loop timers, and non-blocking combinators. |
| `ffi` | `std/ffi.aipl` | Zero-FFI dynamic C library loading and symbol execution via host dynamic linkers (`dlopen`/`dlsym`/`dlclose`). |
| `syscall` | `std/syscall.aipl` | Direct Linux kernel syscall ABI (`x86_64` `syscall` and `arm64` `svc #0`) for Zero-C native execution (`sysRead`, `sysWrite`, `sysMmap`, `sysExit`). |
| `thread` | `std/thread.aipl` | Multi-core work-stealing threadpool, lock-free MPSC channels, `hardwareConcurrency()`, and parallel process execution (`execParallel`). |
| `rt/alloc` | `std/rt/alloc.aipl` | Pure-AIPL bump arena and free-list memory allocator (`rtAlloc`, `rtFree`, `rtArenaPush`, `rtArenaPop`). |
| `rt/array` | `std/rt/array.aipl` | Pure-AIPL contiguous dynamically growable vector buffer (`rtArrayNew`, `rtArrayPush`, `rtArrayGet`). |
| `rt/audio` | `std/rt/audio.aipl` | Pure-AIPL 44.1kHz 16-bit PCM RIFF WAV loader and audio mixer (`rtAudioInit`, `rtAudioMixPcm`) + C runtime multi-backend polyphonic synthesizer (`PulseAudio` / `ALSA` / `SDL2`, `ex_256`–`ex_258`). |
| `rt/canvas_x11` | `std/rt/canvas_x11.aipl` | Pure-AIPL Linux X11 wire-protocol client + Dual Window Modes (`setWindowMode("x11" \| "glx")`, `getWindowMode()`: X11 MIT-SHM `XShmPutImage` and GLX `libGL.so.1` hardware batch renderer, `ex_251`–`ex_255`). |
| `rt/crypto_compress` | `std/rt/crypto_compress.aipl` | Pure-AIPL SHA-256, ChaCha20, CRC32, and Deflate/Inflate compression (`rtSha256`, `rtChaCha20`, `rtDeflate`). |
| `rt/json` | `std/rt/json.aipl` | Pure-AIPL RFC 8259 JSON parser, serializer, and schema validator (`rtJsonParse`, `rtJsonStringify`). |
| `rt/map` | `std/rt/map.aipl` | Pure-AIPL open-addressed SwissTable hash map with FNV-1a 64-bit hashing (`rtMapNew`, `rtMapGet`, `rtMapSet`). |
| `rt/ptr` | `std/rt/ptr.aipl` | Low-level memory pointer, `PtrSlice`, and IEEE-754 bitcast intrinsics (`ptrReadU8`, `ptrWriteI64`, `bitcastF64ToI64`). |
| `rt/string` | `std/rt/string.aipl` | Pure-AIPL UTF-8 string slice manipulation, concatenation, and search (`rtStrFromRaw`, `rtStrConcat`, `rtStrSlice`). |

### 10.10 AI & LLM Tooling (1 Module)

| Module | File Path | Description & Core API |
| :--- | :--- | :--- |
| `ai` | `std/ai.aipl` | Multi-provider AI request generation, JSON schema validation, tool call extraction, prompt template rendering, and token estimation: `buildGeminiRequest`, `buildOpenAiRequest`, `buildAnthropicRequest`, `buildOllamaRequest`, `parseAiToolCall`, `validateJsonAgainstSchema`, `renderPromptTemplate`, `estimateTokenCount`. |
