use std::fs;

struct NotepadDoc {
    text: String,
    cursor: usize,
    undo_stack: Vec<String>,
    redo_stack: Vec<String>,
}

#[allow(non_snake_case)]
fn notepadNew(initial: &str) -> NotepadDoc {
    NotepadDoc {
        text: initial.to_string(),
        cursor: initial.len(),
        undo_stack: Vec::new(),
        redo_stack: Vec::new(),
    }
}

#[allow(non_snake_case)]
fn notepadInsert(doc: &mut NotepadDoc, ins: &str) {
    doc.undo_stack.push(doc.text.clone());
    doc.redo_stack.clear();
    doc.cursor = doc.cursor.min(doc.text.len());
    doc.text.insert_str(doc.cursor, ins);
    doc.cursor += ins.len();
}

#[allow(non_snake_case)]
fn notepadReplaceAll(doc: &mut NotepadDoc, target: &str, repl: &str) {
    doc.undo_stack.push(doc.text.clone());
    doc.redo_stack.clear();
    doc.text = doc.text.replace(target, repl);
    doc.cursor = doc.text.len();
}

#[allow(non_snake_case)]
fn notepadUndo(doc: &mut NotepadDoc) {
    if let Some(prev) = doc.undo_stack.pop() {
        doc.redo_stack.push(doc.text.clone());
        doc.text = prev;
        doc.cursor = doc.text.len();
    }
}

#[allow(non_snake_case)]
fn notepadRedo(doc: &mut NotepadDoc) {
    if let Some(next) = doc.redo_stack.pop() {
        doc.undo_stack.push(doc.text.clone());
        doc.text = next;
        doc.cursor = doc.text.len();
    }
}

fn main() {
    let mut doc = notepadNew("Hello World");
    notepadInsert(&mut doc, " AIPL");
    assert_eq!(doc.text, "Hello World AIPL");
    notepadReplaceAll(&mut doc, "World", "Studio");
    assert_eq!(doc.text, "Hello Studio AIPL");
    notepadUndo(&mut doc);
    assert_eq!(doc.text, "Hello World AIPL");
    notepadRedo(&mut doc);
    assert_eq!(doc.text, "Hello Studio AIPL");
    let path = "/tmp/bench09_notepad.txt";
    fs::write(path, &doc.text).unwrap();
    let loaded = fs::read_to_string(path).unwrap();
    assert_eq!(loaded, "Hello Studio AIPL");
    println!("{}\nBENCH_09_OK", loaded);
}
