import java.nio.file.*;
import java.util.*;

public class Main {
    static class NotepadDoc {
        String text; int cursor;
        Deque<String> undo = new ArrayDeque<>(), redo = new ArrayDeque<>();
        NotepadDoc(String t) { text = t; cursor = t.length(); }
        void insert(String ins) {
            undo.push(text); redo.clear();
            text = text.substring(0, cursor) + ins + text.substring(cursor);
            cursor += ins.length();
        }
        void replaceAll(String target, String repl) {
            undo.push(text); redo.clear();
            text = text.replace(target, repl);
            cursor = text.length();
        }
        void undo() { redo.push(text); text = undo.pop(); cursor = text.length(); }
        void redo() { undo.push(text); text = redo.pop(); cursor = text.length(); }
    }
    public static void main(String[] args) throws Exception {
        NotepadDoc doc = new NotepadDoc("Hello World");
        doc.insert(" AIPL");
        doc.replaceAll("World", "Studio");
        doc.undo();
        if (!doc.text.equals("Hello World AIPL")) throw new AssertionError();
        doc.redo();
        Path p = Paths.get("/tmp/java_bench09.txt");
        Files.writeString(p, doc.text);
        String s = Files.readString(p);
        if (!s.equals("Hello Studio AIPL")) throw new AssertionError();
        System.out.println(s + "\nBENCH_09_OK");
    }
}
