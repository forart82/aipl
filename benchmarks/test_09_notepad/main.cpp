#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

struct NotepadDoc {
    std::string text;
    size_t cursor;
    std::vector<std::string> undoStack;
    std::vector<std::string> redoStack;
};

NotepadDoc notepadNew(const std::string& initial) {
    return {initial, initial.size(), {}, {}};
}

void notepadInsert(NotepadDoc& doc, const std::string& ins) {
    doc.undoStack.push_back(doc.text);
    doc.redoStack.clear();
    doc.cursor = std::min(doc.cursor, doc.text.size());
    doc.text.insert(doc.cursor, ins);
    doc.cursor += ins.size();
}

void notepadReplaceAll(NotepadDoc& doc, const std::string& target, const std::string& repl) {
    doc.undoStack.push_back(doc.text);
    doc.redoStack.clear();
    size_t pos = 0;
    while ((pos = doc.text.find(target, pos)) != std::string::npos) {
        doc.text.replace(pos, target.size(), repl);
        pos += repl.size();
    }
    doc.cursor = doc.text.size();
}

void notepadUndo(NotepadDoc& doc) {
    if (!doc.undoStack.empty()) {
        doc.redoStack.push_back(doc.text);
        doc.text = doc.undoStack.back();
        doc.undoStack.pop_back();
        doc.cursor = doc.text.size();
    }
}

void notepadRedo(NotepadDoc& doc) {
    if (!doc.redoStack.empty()) {
        doc.undoStack.push_back(doc.text);
        doc.text = doc.redoStack.back();
        doc.redoStack.pop_back();
        doc.cursor = doc.text.size();
    }
}

int main() {
    auto doc = notepadNew("Hello World");
    notepadInsert(doc, " AIPL");
    assert(doc.text == "Hello World AIPL");
    notepadReplaceAll(doc, "World", "Studio");
    assert(doc.text == "Hello Studio AIPL");
    notepadUndo(doc);
    assert(doc.text == "Hello World AIPL");
    notepadRedo(doc);
    assert(doc.text == "Hello Studio AIPL");
    std::string path = "/tmp/bench09_notepad.txt";
    {
        std::ofstream out(path);
        out << doc.text;
    }
    std::ifstream in(path);
    std::stringstream ss;
    ss << in.rdbuf();
    assert(ss.str() == "Hello Studio AIPL");
    std::cout << ss.str() << "\nBENCH_09_OK\n";
    return 0;
}
