from pathlib import Path
from dataclasses import dataclass, field

@dataclass
class NotepadDoc:
    text: str
    cursor: int
    undoStack: list[str] = field(default_factory=list)
    redoStack: list[str] = field(default_factory=list)

def notepadNew(initial: str) -> NotepadDoc:
    return NotepadDoc(text=initial, cursor=len(initial))

def notepadInsert(doc: NotepadDoc, ins: str):
    doc.undoStack.append(doc.text)
    doc.redoStack.clear()
    doc.cursor = max(0, min(doc.cursor, len(doc.text)))
    doc.text = doc.text[:doc.cursor] + ins + doc.text[doc.cursor:]
    doc.cursor += len(ins)

def notepadReplaceAll(doc: NotepadDoc, target: str, repl: str):
    doc.undoStack.append(doc.text)
    doc.redoStack.clear()
    doc.text = doc.text.replace(target, repl)
    doc.cursor = len(doc.text)

def notepadUndo(doc: NotepadDoc):
    if doc.undoStack:
        doc.redoStack.append(doc.text)
        doc.text = doc.undoStack.pop()
        doc.cursor = len(doc.text)

def notepadRedo(doc: NotepadDoc):
    if doc.redoStack:
        doc.undoStack.append(doc.text)
        doc.text = doc.redoStack.pop()
        doc.cursor = len(doc.text)

doc = notepadNew("Hello World")
notepadInsert(doc, " AIPL")
assert doc.text == "Hello World AIPL"
notepadReplaceAll(doc, "World", "Studio")
assert doc.text == "Hello Studio AIPL"
notepadUndo(doc)
assert doc.text == "Hello World AIPL"
notepadRedo(doc)
assert doc.text == "Hello Studio AIPL"
p = Path("/tmp/bench09_notepad.txt")
p.write_text(doc.text)
loaded = p.read_text()
assert loaded == "Hello Studio AIPL"
print(f"{loaded}\nBENCH_09_OK")
