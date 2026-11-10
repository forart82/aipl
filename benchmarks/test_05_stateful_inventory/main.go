package main

import "fmt"

type Item struct {
	id         int
	name       string
	qty        int
	priceCents int
}

type InventoryStore struct {
	items    []Item
	snapshot []Item
}

func beginTx(st *InventoryStore) {
	st.snapshot = append([]Item(nil), st.items...)
}

func rollbackTx(st *InventoryStore) {
	st.items = append([]Item(nil), st.snapshot...)
}

func upsertItem(st *InventoryStore, id int, name string, qty int, priceCents int) {
	for i := range st.items {
		if st.items[i].id == id {
			st.items[i] = Item{id, name, qty, priceCents}
			return
		}
	}
	st.items = append(st.items, Item{id, name, qty, priceCents})
}

func removeItem(st *InventoryStore, id int) {
	var next []Item
	for _, it := range st.items {
		if it.id != id {
			next = append(next, it)
		}
	}
	st.items = next
}

func totalValuationCents(st *InventoryStore) int {
	total := 0
	for _, it := range st.items {
		total += it.qty * it.priceCents
	}
	return total
}

func main() {
	var st InventoryStore
	upsertItem(&st, 1, "GPU-Node", 4, 250000)
	upsertItem(&st, 2, "NVMe-4TB", 10, 30000)
	upsertItem(&st, 3, "Switch-100G", 2, 150000)
	beginTx(&st)
	removeItem(&st, 1)
	upsertItem(&st, 2, "NVMe-4TB", 1, 30000)
	rollbackTx(&st)
	if len(st.items) != 3 || totalValuationCents(&st) != 1600000 {
		panic("assert")
	}
	fmt.Printf("Valuation=%d\nBENCH_05_OK\n", totalValuationCents(&st))
}
