from dataclasses import dataclass, field

@dataclass
class Item:
    id: int
    name: str
    qty: int
    priceCents: int

@dataclass
class InventoryStore:
    items: list[Item] = field(default_factory=list)
    snapshot: list[Item] = field(default_factory=list)

def beginTx(store: InventoryStore):
    store.snapshot = [Item(i.id, i.name, i.qty, i.priceCents) for i in store.items]

def rollbackTx(store: InventoryStore):
    store.items = [Item(i.id, i.name, i.qty, i.priceCents) for i in store.snapshot]

def upsertItem(store: InventoryStore, id: int, name: str, qty: int, priceCents: int):
    for i, it in enumerate(store.items):
        if it.id == id:
            store.items[i] = Item(id, name, qty, priceCents)
            return
    store.items.append(Item(id, name, qty, priceCents))

def removeItem(store: InventoryStore, id: int):
    store.items = [i for i in store.items if i.id != id]

def totalValuationCents(store: InventoryStore) -> int:
    return sum(i.qty * i.priceCents for i in store.items)

store = InventoryStore()
upsertItem(store, 1, "GPU-Node", 4, 250000)
upsertItem(store, 2, "NVMe-4TB", 10, 30000)
upsertItem(store, 3, "Switch-100G", 2, 150000)
assert totalValuationCents(store) == 1600000
beginTx(store)
removeItem(store, 1)
upsertItem(store, 2, "NVMe-4TB", 1, 30000)
assert totalValuationCents(store) == 330000
rollbackTx(store)
assert len(store.items) == 3
assert totalValuationCents(store) == 1600000
print(f"Valuation={totalValuationCents(store)}\nBENCH_05_OK")
