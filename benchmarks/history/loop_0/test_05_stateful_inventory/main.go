package main

import "fmt"

type Item struct {
	id, qty, priceCents int
	name                string
}

type InventoryStore struct {
	items, snapshot []Item
}

func (s *InventoryStore) beginTx() {
	s.snapshot = append([]Item(nil), s.items...)
}
func (s *InventoryStore) rollbackTx() {
	s.items = append([]Item(nil), s.snapshot...)
}
func (s *InventoryStore) upsert(id int, name string, qty, price int) {
	for i := range s.items {
		if s.items[i].id == id {
			s.items[i] = Item{id, qty, price, name}
			return
		}
	}
	s.items = append(s.items, Item{id, qty, price, name})
}
func (s *InventoryStore) remove(id int) {
	var next []Item
	for _, it := range s.items {
		if it.id != id {
			next = append(next, it)
		}
	}
	s.items = next
}
func (s *InventoryStore) valuation() int {
	total := 0
	for _, it := range s.items {
		total += it.qty * it.priceCents
	}
	return total
}

func main() {
	var st InventoryStore
	st.upsert(1, "GPU-Node", 4, 250000)
	st.upsert(2, "NVMe-4TB", 10, 30000)
	st.upsert(3, "Switch-100G", 2, 150000)
	st.beginTx()
	st.remove(1)
	st.upsert(2, "NVMe-4TB", 1, 30000)
	st.rollbackTx()
	if len(st.items) != 3 || st.valuation() != 1600000 {
		panic("assert")
	}
	fmt.Printf("Valuation=%d\nBENCH_05_OK\n", st.valuation())
}
