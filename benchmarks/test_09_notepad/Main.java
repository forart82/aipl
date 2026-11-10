import java.nio.file.*;
import java.util.*;

public class Main {
    static class NotepadDoc {
        String text;
        int cursor;
        List<String> undoStack = new ArrayList<>();
        List<String> redoStack = new ArrayList<>();
        NotepadDoc(String t) {
            text = t;
            cursor = t.length();
        }
    }

    static NotepadDoc notepadNew(String initial) {
        return new NotepadDoc(initial);
    }

    static void notepadInsert(NotepadDoc doc, String ins) {
        doc.undoStack.add(doc.text);
        doc.redoStack.clear();
        doc.cursor = Math.max(0, Math.min(doc.cursor, doc.text.length()));
        doc.text = doc.text.substring(0, doc.cursor) + ins + doc.text.substring(doc.cursor);
        doc.cursor += ins.length();
    }

    static void notepadReplaceAll(NotepadDoc doc, String target, String repl) {
        doc.undoStack.add(doc.text);
        doc.redoStack.clear();
        doc.text = doc.text.replace(target, repl);
        doc.cursor = doc.text.length();
    }

    static void notepadUndo(NotepadDoc doc) {
        if (!doc.undoStack.isEmpty()) {
            doc.redoStack.add(doc.text);
            doc.text = doc.undoStack.remove(doc.undoStack.size() - 1);
            doc.cursor = doc.text.length();
        }
    }

    static void notepadRedo(NotepadDoc doc) {
        if (!doc.redoStack.isEmpty()) {
            doc.undoStack.add(doc.text);
            doc.text = doc.redoStack.remove(doc.redoStack.size() - 1);
            doc.cursor = doc.text.length();
        }
    }

    public static void main(String[] args) throws Exception {
        NotepadDoc doc = notepadNew("Hello World");
        notepadInsert(doc, " AIPL");
        if (!doc.text.equals("Hello World AIPL")) throw new AssertionError();
        notepadReplaceAll(doc, "World", "Studio");
        if (!doc.text.equals("Hello Studio AIPL")) throw new AssertionError();
        notepadUndo(doc);
        if (!doc.text.equals("Hello World AIPL")) throw new AssertionError();
        notepadRedo(doc);
        if (!doc.text.equals("Hello Studio AIPL")) throw new AssertionError();
        Path p = Paths.get("/tmp/bench09_notepad.txt");
        Files.write(p, doc.text.getBytes());
        String loaded = new String(Files.readAllBytes(p));
        if (!loaded.equals("Hello Studio AIPL")) throw new AssertionError();
        System.out.println(loaded + "\nBENCH_09_OK");
    }
}
