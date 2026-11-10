import * as fs from "fs";
class NotepadDoc {
  text: string; cursor: number; undoStack: string[] = []; redoStack: string[] = [];
  constructor(t: string) { this.text = t; this.cursor = t.length; }
  insert(ins: string): void {
    this.undoStack.push(this.text); this.redoStack = [];
    this.text = this.text.slice(0, this.cursor) + ins + this.text.slice(this.cursor);
    this.cursor += ins.length;
  }
  replaceAll(target: string, repl: string): void {
    this.undoStack.push(this.text); this.redoStack = [];
    this.text = this.text.split(target).join(repl);
    this.cursor = this.text.length;
  }
  undo(): void { this.redoStack.push(this.text); this.text = this.undoStack.pop()!; this.cursor = this.text.length; }
  redo(): void { this.undoStack.push(this.text); this.text = this.redoStack.pop()!; this.cursor = this.text.length; }
}
const doc = new NotepadDoc("Hello World");
doc.insert(" AIPL");
doc.replaceAll("World", "Studio");
doc.undo();
doc.redo();
const p = "/tmp/ts_bench09.txt";
fs.writeFileSync(p, doc.text);
const loaded = fs.readFileSync(p, "utf8");
if (loaded !== "Hello Studio AIPL") throw new Error("assert");
console.log(`${loaded}\nBENCH_09_OK`);
