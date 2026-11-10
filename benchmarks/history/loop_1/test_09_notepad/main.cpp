#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>

struct NotepadDoc {
    std::string text;
    size_t cursor;
    std::vector<std::string> undoStack, redoStack;
    NotepadDoc(std::string t) : text(t), cursor(t.size()) {}
    void insert(const std::string& ins) {
        undoStack.push_back(text);
        redoStack.clear();
        text.insert(cursor, ins);
        cursor += ins.size();
    }
    void replaceAll(const std::string& target, const std::string& repl) {
        undoStack.push_back(text);
        redoStack.clear();
        size_t pos = 0;
        while ((pos = text.find(target, pos)) != std::string::npos) {
            text.replace(pos, target.size(), repl);
            pos += repl.size();
        }
        cursor = text.size();
    }
    void undo() {
        if (!undoStack.empty()) {
            redoStack.push_back(text);
            text = undoStack.back();
            undoStack.pop_back();
            cursor = text.size();
        }
    }
    void redo() {
        if (!redoStack.empty()) {
            undoStack.push_back(text);
            text = redoStack.back();
            redoStack.pop_back();
            cursor = text.size();
        }
    }
};

int main() {
    NotepadDoc doc("Hello World");
    doc.insert(" AIPL");
    assert(doc.text == "Hello World AIPL");
    doc.replaceAll("World", "Studio");
    assert(doc.text == "Hello Studio AIPL");
    doc.undo();
    assert(doc.text == "Hello World AIPL");
    doc.redo();
    assert(doc.text == "Hello Studio AIPL");
    std::string path = "/tmp/cpp_bench09.txt";
    { std::ofstream out(path); out << doc.text; }
    std::ifstream in(path); std::stringstream ss; ss << in.rdbuf();
    assert(ss.str() == "Hello Studio AIPL");
    std::cout << ss.str() << "\nBENCH_09_OK\n";
    return 0;
}
