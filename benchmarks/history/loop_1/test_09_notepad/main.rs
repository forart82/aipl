use std::fs;

struct NotepadDoc {
    text: String,
    cursor: usize,
    undo: Vec<String>,
    redo: Vec<String>,
}

impl NotepadDoc {
    fn new(init: &str) -> Self { Self { text: init.into(), cursor: init.len(), undo: Vec::new(), redo: Vec::new() } }
    fn insert(&mut self, ins: &str) {
        self.undo.push(self.text.clone());
        self.redo.clear();
        self.text.insert_str(self.cursor, ins);
        self.cursor += ins.len();
    }
    fn replace_all(&mut self, target: &str, repl: &str) {
        self.undo.push(self.text.clone());
        self.redo.clear();
        self.text = self.text.replace(target, repl);
        self.cursor = self.text.len();
    }
    fn undo(&mut self) {
        if let Some(prev) = self.undo.pop() {
            self.redo.push(self.text.clone());
            self.text = prev;
            self.cursor = self.text.len();
        }
    }
    fn redo(&mut self) {
        if let Some(next) = self.redo.pop() {
            self.undo.push(self.text.clone());
            self.text = next;
            self.cursor = self.text.len();
        }
    }
}

fn main() {
    let mut doc = NotepadDoc::new("Hello World");
    doc.insert(" AIPL");
    doc.replace_all("World", "Studio");
    doc.undo();
    assert_eq!(doc.text, "Hello World AIPL");
    doc.redo();
    let p = "/tmp/rs_bench09.txt";
    fs::write(p, &doc.text).unwrap();
    let loaded = fs::read_to_string(p).unwrap();
    assert_eq!(loaded, "Hello Studio AIPL");
    println!("{}\nBENCH_09_OK", loaded);
}
