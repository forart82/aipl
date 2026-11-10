package main

import (
	"fmt"
	"os"
	"strings"
)

type NotepadDoc struct {
	text        string
	cursor      int
	undo, redo  []string
}

func (d *NotepadDoc) insert(ins string) {
	d.undo = append(d.undo, d.text)
	d.redo = nil
	d.text = d.text[:d.cursor] + ins + d.text[d.cursor:]
	d.cursor += len(ins)
}
func (d *NotepadDoc) replaceAll(target, repl string) {
	d.undo = append(d.undo, d.text)
	d.redo = nil
	d.text = strings.ReplaceAll(d.text, target, repl)
	d.cursor = len(d.text)
}
func (d *NotepadDoc) doUndo() {
	d.redo = append(d.redo, d.text)
	d.text = d.undo[len(d.undo)-1]
	d.undo = d.undo[:len(d.undo)-1]
}
func (d *NotepadDoc) doRedo() {
	d.undo = append(d.undo, d.text)
	d.text = d.redo[len(d.redo)-1]
	d.redo = d.redo[:len(d.redo)-1]
}

func main() {
	doc := NotepadDoc{text: "Hello World", cursor: 11}
	doc.insert(" AIPL")
	doc.replaceAll("World", "Studio")
	doc.doUndo()
	doc.doRedo()
	p := "/tmp/go_bench09.txt"
	_ = os.WriteFile(p, []byte(doc.text), 0644)
	b, _ := os.ReadFile(p)
	fmt.Printf("%s\nBENCH_09_OK\n", string(b))
}
