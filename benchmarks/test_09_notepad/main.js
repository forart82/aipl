const fs = require("fs");

class NotepadDoc {
  constructor(text) {
    this.text = text;
    this.cursor = text.length;
    this.undoStack = [];
    this.redoStack = [];
  }
}

function notepadNew(initial) {
  return new NotepadDoc(initial);
}

function notepadInsert(doc, ins) {
  doc.undoStack.push(doc.text);
  doc.redoStack = [];
  doc.cursor = Math.max(0, Math.min(doc.cursor, doc.text.length));
  doc.text = doc.text.slice(0, doc.cursor) + ins + doc.text.slice(doc.cursor);
  doc.cursor += ins.length;
}

function notepadReplaceAll(doc, target, repl) {
  doc.undoStack.push(doc.text);
  doc.redoStack = [];
  doc.text = doc.text.split(target).join(repl);
  doc.cursor = doc.text.length;
}

function notepadUndo(doc) {
  if (doc.undoStack.length > 0) {
    doc.redoStack.push(doc.text);
    doc.text = doc.undoStack.pop();
    doc.cursor = doc.text.length;
  }
}

function notepadRedo(doc) {
  if (doc.redoStack.length > 0) {
    doc.undoStack.push(doc.text);
    doc.text = doc.redoStack.pop();
    doc.cursor = doc.text.length;
  }
}

const doc = notepadNew("Hello World");
notepadInsert(doc, " AIPL");
if (doc.text !== "Hello World AIPL") {
  throw new Error("assert");
}
notepadReplaceAll(doc, "World", "Studio");
if (doc.text !== "Hello Studio AIPL") {
  throw new Error("assert");
}
notepadUndo(doc);
if (doc.text !== "Hello World AIPL") {
  throw new Error("assert");
}
notepadRedo(doc);
if (doc.text !== "Hello Studio AIPL") {
  throw new Error("assert");
}
const p = "/tmp/bench09_notepad.txt";
fs.writeFileSync(p, doc.text);
const loaded = fs.readFileSync(p, "utf8");
if (loaded !== "Hello Studio AIPL") {
  throw new Error("assert");
}
console.log(`${loaded}\nBENCH_09_OK`);
