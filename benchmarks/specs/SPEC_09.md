# SPEC_09: Simple Notepad Program (`test_09_notepad`)

- **Tier**: Complex
- **Category**: Stateful Text Buffer with Cursor, Undo/Redo Stacks & File Persistence

## 1. Functional Requirements
1. Define `NotepadDoc(text: str, cursor: int, undoStack: [str], redoStack: [str])`.
2. Implement operations:
   - `notepadNew(initial)`: initializes buffer with `cursor = initial.len` and empty undo/redo stacks.
   - `notepadInsert(doc, ins)`: pushes current `text` to `undoStack`, clears `redoStack`, clamps `cursor` to `[0, text.len]`, inserts `ins` at `cursor`, advances `cursor`.
   - `notepadReplaceAll(doc, target, repl)`: pushes current `text` to `undoStack`, clears `redoStack`, replaces all occurrences of `target` with `repl`, sets `cursor = text.len`.
   - `notepadUndo(doc)`: if `undoStack` is non-empty, pops previous state, pushes current `text` to `redoStack`, updates `text` and `cursor`.
   - `notepadRedo(doc)`: if `redoStack` is non-empty, pops next state, pushes current `text` to `undoStack`, updates `text` and `cursor`.
3. Execute sequence: `notepadNew("Hello World")` -> `notepadInsert(" AIPL")` -> `notepadReplaceAll("World", "Studio")` -> `notepadUndo()` (assert `"Hello World AIPL"`) -> `notepadRedo()` (assert `"Hello Studio AIPL"`).
4. Persist to `/tmp/bench09_notepad.txt`, reload from disk, assert equality, and print reloaded text followed by `BENCH_09_OK`.

## 2. Structural & Algorithmic Parity (Rule B)
- **Normalized Identifiers**: `NotepadDoc`, `notepadNew`, `notepadInsert`, `notepadReplaceAll`, `notepadUndo`, `notepadRedo`.

## 3. Expected Deterministic Stdout
```text
Hello Studio AIPL
BENCH_09_OK
```
