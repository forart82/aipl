from pathlib import Path

class NotepadDoc:
    def __init__(self, text: str):
        self.text = text
        self.cursor = len(text)
        self.undo_stack: list[str] = []
        self.redo_stack: list[str] = []
    def insert(self, ins: str):
        self.undo_stack.append(self.text)
        self.redo_stack.clear()
        self.text = self.text[:self.cursor] + ins + self.text[self.cursor:]
        self.cursor += len(ins)
    def replace_all(self, target: str, repl: str):
        self.undo_stack.append(self.text)
        self.redo_stack.clear()
        self.text = self.text.replace(target, repl)
        self.cursor = len(self.text)
    def undo(self):
        self.redo_stack.append(self.text)
        self.text = self.undo_stack.pop()
    def redo(self):
        self.undo_stack.append(self.text)
        self.text = self.redo_stack.pop()

doc = NotepadDoc("Hello World")
doc.insert(" AIPL")
doc.replace_all("World", "Studio")
doc.undo()
assert doc.text == "Hello World AIPL"
doc.redo()
p = Path("/tmp/py_bench09.txt")
p.write_text(doc.text)
loaded = p.read_text()
assert loaded == "Hello Studio AIPL"
print(f"{loaded}\nBENCH_09_OK")
