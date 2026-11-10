package main

import (
	"fmt"
	"os"
	"strings"
)

type NotepadDoc struct {
	text      string
	cursor    int
	undoStack []string
	redoStack []string
}

func notepadNew(initial string) NotepadDoc {
	return NotepadDoc{
		text:   initial,
		cursor: len(initial),
	}
}

func notepadInsert(doc *NotepadDoc, ins string) {
	doc.undoStack = append(doc.undoStack, doc.text)
	doc.redoStack = nil
	if doc.cursor > len(doc.text) {
		doc.cursor = len(doc.text)
	}
	if doc.cursor < 0 {
		doc.cursor = 0
	}
	doc.text = doc.text[:doc.cursor] + ins + doc.text[doc.cursor:]
	doc.cursor += len(ins)
}

func notepadReplaceAll(doc *NotepadDoc, target, repl string) {
	doc.undoStack = append(doc.undoStack, doc.text)
	doc.redoStack = nil
	doc.text = strings.ReplaceAll(doc.text, target, repl)
	doc.cursor = len(doc.text)
}

func notepadUndo(doc *NotepadDoc) {
	if len(doc.undoStack) > 0 {
		doc.redoStack = append(doc.redoStack, doc.text)
		doc.text = doc.undoStack[len(doc.undoStack)-1]
		doc.undoStack = doc.undoStack[:len(doc.undoStack)-1]
		doc.cursor = len(doc.text)
	}
}

func notepadRedo(doc *NotepadDoc) {
	if len(doc.redoStack) > 0 {
		doc.undoStack = append(doc.undoStack, doc.text)
		doc.text = doc.redoStack[len(doc.redoStack)-1]
		doc.redoStack = doc.redoStack[:len(doc.redoStack)-1]
		doc.cursor = len(doc.text)
	}
}

func main() {
	doc := notepadNew("Hello World")
	notepadInsert(&doc, " AIPL")
	notepadReplaceAll(&doc, "World", "Studio")
	notepadUndo(&doc)
	if doc.text != "Hello World AIPL" {
		panic("assert")
	}
	notepadRedo(&doc)
	if doc.text != "Hello Studio AIPL" {
		panic("assert")
	}
	p := "/tmp/bench09_notepad.txt"
	os.WriteFile(p, []byte(doc.text), 0644)
	data, _ := os.ReadFile(p)
	if string(data) != "Hello Studio AIPL" {
		panic("assert")
	}
	fmt.Printf("%s\nBENCH_09_OK\n", string(data))
}
