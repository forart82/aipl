# AIPL Formal Grammar & Syntax Reference (v0.9.0)
**Single Source of Truth (SSOT) — Lexical & Grammatical Specifications**

[Home](../README.md) | [Docs Index](INDEX.md) | [Language Specification](SPEC.md) | [Build & Targets](BUILD_AND_TARGETS.md) | [Memory Model](MEMORY_MODEL.md) | [CLI Reference](CLI_REFERENCE.md)

> **When to Read This Document**: Read this document for a rigorous, token-optimal grammatical definition of the AIPL programming language. It covers formal EBNF syntax productions, the 2-space indentation offside rule, operator precedence tables, type syntax, and Design-by-Contract semantics.

---

## Canonical Project Architecture & Counts

- **38 Standard Library Domain Groups**: `2` root modules (`std/std_root.aipl`, `std/prelude.aipl`) + `37` canonical domain directories = **`299` `std/` modules** (`262` implementation/root modules + `37` barrel modules).
- **4,379 Total Callable Functions**: **`32` compiler built-ins + `4,347` `std/` functions, constructors & receiver methods**.
- **263 Curated, Fully-Tested Examples**: `examples/ex_001_*.aipl` through `examples/ex_263_*.aipl` with twin unit tests in `tests/examples/`.
- **37 Architecture Decision Records**: `docs/ADR/ADR-0001-*.md` through `docs/ADR/ADR-0037-*.md` indexed in [`docs/ADR/INDEX.md`](ADR/INDEX.md).
---

## 1. Lexical Grammar & Token Invariants

AIPL syntax is co-optimized for the 256,000-token vocabulary of modern transformer tokenizers (e.g., SentencePiece unigram models used in Gemini and Gemma). All source files are encoded in UTF-8 without byte-order marks.

### 1.1 Strict 2-Space Indentation Offside Rule
Blocks in AIPL are delineated by indentation rather than curly braces (`{}`) or `begin`/`end` markers:
- **Block Indentation Step**: Exactly **2 spaces** (`  `).
- **Tab Prohibition**: Tabs (`\t`) are strictly forbidden anywhere in indentation and cause compile error `AIPL_E1001_TAB_INDENT_FORBIDDEN`.
- **Block Header Delimiter**: Block heads (`fn`, `if`, `while`, `for`, `match`, `struct`, `with arena`) end with a colon (`:`).
- **Virtual Tokens**: The lexer emits virtual `INDENT` and `DEDENT` tokens when the leading whitespace changes by multiples of 2 spaces.

### 1.2 Strict camelCase Identifier Convention (ADR-0002)
- **Values, Variables & Functions**: Must be written in `camelCase` (e.g., `itemCount`, `calculateDistance`, `renderFrame`).
- **Types, Structs & Enums**: Must be written in `PascalCase` (e.g., `Point2d`, `HttpRequest`, `ColorRgba`).
- **Underscore Prohibition**: Underscores (`_`) are strictly forbidden in identifier names, except for the single-underscore wildcard `_`. Snake_case identifiers trigger `AIPL_W1003_SNAKE_CASE_AUTOFIX` and are automatically repaired by `aipl fix` and `aipl fmt`.

### 1.3 Literal Forms
- **Integers**: Decimal (`42`), Hexadecimal (`0x2A`), Binary (`0b101010`), and sized suffixes (`42i64`, `255u8`).
- **Floats**: Decimal with fraction (`3.14159`) or exponent (`1.0e-5`), and sized suffixes (`3.14f32`).
- **Booleans**: `true` and `false`.
- **Strings**:
  - Single-line: `"Hello, {name}!"` with inline interpolation `{expr}`.
  - Multiline: Triple quotes `"""..."""` preserving relative line breaks and indentation.
  - Escape sequences: `\n`, `\r`, `\t`, `\\`, `\"`, `\0`, and Unicode `\u{1F600}`.
- **Arrays**: `[1, 2, 3]` with contiguous Structure of Arrays (SoA) layout.
- **Maps**: `Map()` or `{ key: value }`.

---

## 2. Formal EBNF Syntax Specification

Below is the formal Extended Backus-Naur Form (EBNF) grammar defining the AIPL language syntax:

```ebnf
Module          ::= [ ModuleHeader ] { ImportStmt } { TopLevelDecl }

ModuleHeader    ::= "module" QualifiedIdent

ImportStmt      ::= "import" ( "*" | "{" IdentList "}" ) "from" StringLiteral

TopLevelDecl    ::= [ "pub" ] ( FunctionDecl | StructDecl | EnumDecl | ConstDecl )

FunctionDecl    ::= "fn" Ident "(" [ ParamList ] ")" [ ":" TypeExpr ] ":" Block

ParamList       ::= Param { "," Param }
Param           ::= [ "mut" ] Ident ":" TypeExpr [ "=" Expr ]

StructDecl      ::= "struct" PascalIdent [ "(" StructFieldList ")" ] [ ":" StructBody ]
StructBody      ::= INDENT { [ "pub" ] [ "mut" ] Ident ":" TypeExpr } DEDENT

EnumDecl        ::= "enum" PascalIdent ":" INDENT { EnumVariant } DEDENT
EnumVariant     ::= PascalIdent [ "(" [ TypeList ] ")" ]

Block           ::= INDENT { Stmt } DEDENT

Stmt            ::= LetStmt
                  | AssignStmt
                  | IfStmt
                  | WhileStmt
                  | ForStmt
                  | MatchStmt
                  | RetStmt
                  | WithArenaStmt
                  | ExprStmt

LetStmt         ::= "let" [ "mut" ] Ident [ ":" TypeExpr ] "=" Expr
AssignStmt      ::= LeftHandSide AssignOp Expr
AssignOp        ::= "=" | "+=" | "-=" | "*=" | "/=" | "%="

IfStmt          ::= "if" Expr ":" Block { "elif" Expr ":" Block } [ "else" ":" Block ]
WhileStmt       ::= "while" Expr ":" Block
ForStmt         ::= "for" Ident [ "," Ident ] "in" Expr [ "by" Expr ] ":" Block
WithArenaStmt   ::= "with" "arena" ":" Block
RetStmt         ::= ( "ret" | "return" ) [ Expr ]

MatchStmt       ::= "match" Expr ":" INDENT { MatchArm } DEDENT
MatchArm        ::= Pattern [ "if" Expr ] ":" Block
Pattern         ::= Literal | Ident | "_" | PascalIdent "::" PascalIdent [ "(" PatternList ")" ]

Expr            ::= LogicalOrExpr
LogicalOrExpr   ::= LogicalAndExpr { "or" LogicalAndExpr }
LogicalAndExpr  ::= EqualityExpr { "and" EqualityExpr }
EqualityExpr    ::= RelationalExpr { ( "==" | "!=" ) RelationalExpr }
RelationalExpr  ::= AdditiveExpr { ( "<" | "<=" | ">" | ">=" ) AdditiveExpr }
AdditiveExpr    ::= MultiplicativeExpr { ( "+" | "-" ) MultiplicativeExpr }
MultiplicativeExpr ::= UnaryExpr { ( "*" | "/" | "//" | "%" ) UnaryExpr }
UnaryExpr       ::= ( "-" | "not" | "!" | "~" ) UnaryExpr | PostfixExpr
PostfixExpr     ::= PrimaryExpr { CallSuffix | MemberSuffix | IndexSuffix | TrySuffix }
TrySuffix       ::= "?"
CallSuffix      ::= "(" [ ArgList ] ")"
MemberSuffix    ::= "." Ident
IndexSuffix     ::= "[" Expr [ ".." [ Expr ] ] "]"

PrimaryExpr     ::= Literal
                  | Ident
                  | "(" Expr ")"
                  | ArrayLiteral
                  | MapLiteral
                  | StructConstructor

ArrayLiteral    ::= "[" [ ExprList ] "]"
MapLiteral      ::= "Map" "(" ")" | "{" [ MapEntryList ] "}"
```

---

## 3. Operator Precedence & Associativity Table

Operators in AIPL follow strict, non-ambiguous precedence levels binding from highest (level 11) to lowest (level 1):

| Level | Operator | Description | Associativity | Example |
| :---: | :--- | :--- | :--- | :--- |
| **11** | `.` `()` `[]` `?` | Member access, call, indexing, slice, try | Left-to-right | `user.address.zip?` |
| **10** | `-` `not` `!` `~` | Unary negation, logical NOT, bitwise NOT | Right-to-left | `not isReady` |
| **9** | `**` | Exponentiation | Right-to-left | `base ** 2.0` |
| **8** | `*` `/` `//` `%` | Multiply, float div, floor div, modulo | Left-to-right | `total // pageSize` |
| **7** | `+` `-` | Addition, subtraction, string concatenation | Left-to-right | `count + 1` |
| **6** | `<<` `>>` | Bitwise left shift, right shift | Left-to-right | `flags << 2` |
| **5** | `&` `^` `\|` | Bitwise AND, XOR, OR | Left-to-right | `mask & 0xFF` |
| **4** | `==` `!=` `<` `<=` `>` `>=` | Comparison and relational operators | Non-associative | `x < max and y >= 0` |
| **3** | `and` | Logical conjunction (short-circuiting) | Left-to-right | `isValid and hasToken` |
| **2** | `or` | Logical disjunction (short-circuiting) | Left-to-right | `cached or fetch()` |
| **1** | `=` `+=` `-=` `*=` `/=` | Assignment and compound assignment | Right-to-left | `count += 1` |

---

## 4. Design-by-Contract (`req:` and `ens:`)

AIPL integrates first-class contract assertions into function signatures verified by the self-hosted compile-time SMT solver:

```aipl
pub fn clamp(val: int, minVal: int, maxVal: int): int:
  req: minVal <= maxVal
  ens: ret >= minVal and ret <= maxVal
  if val < minVal:
    ret minVal
  if val > maxVal:
    ret maxVal
  ret val
```

### Contract Execution Rules
- `req:` (Pre-condition): Must evaluate to `true` upon entry before function body execution. If the embedded SMT solver cannot statically prove the invariant, a zero-overhead runtime assertion is emitted.
- `ens:` (Post-condition): Must evaluate to `true` upon exit. The special keyword `ret` refers to the function's return value.

---

## 5. Receiver Methods & Nominal Structs

Methods are declared with receiver parameters matching the struct type:

```aipl
struct Vector2(x: float, y: float)

pub fn Vector2.length(self): float:
  ret sqrt(self.x * self.x + self.y * self.y)

pub fn Vector2.dot(self, other: Vector2): float:
  ret self.x * other.x + self.y * other.y
```

---

## 6. Runnable Verification Test

The following runnable AIPL test validates that nominal structs, receiver methods, contracts, and operator precedence evaluate with full fidelity:

```aipl
module tests.functions.core.grammar_and_syntax_test
import * from "std/prelude"

struct Counter(val: int)

pub fn Counter.inc(mut self, delta: int): int:
  req: delta >= 0
  ens: ret >= self.val
  self.val += delta
  ret self.val

pub fn test_grammar_counter_contract(): int:
  let mut c = Counter(10)
  let nextVal = c.inc(5)
  assertEqInt(nextVal, 15, "Counter incremented to 15")
  assertEqInt(c.val, 15, "Counter state preserved")
  ret 0
```
