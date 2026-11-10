interface Item {
  id: number;
  name: string;
  qty: number;
  priceCents: number;
}

interface InventoryStore {
  items: Item[];
  snapshot: Item[];
}

function beginTx(store: InventoryStore): void {
  store.snapshot = store.items.map((i) => ({ ...i }));
}

function rollbackTx(store: InventoryStore): void {
  store.items = store.snapshot.map((i) => ({ ...i }));
}

function upsertItem(store: InventoryStore, id: number, name: string, qty: number, priceCents: number): void {
  const idx = store.items.findIndex((i) => i.id === id);
  if (idx >= 0) {
    store.items[idx] = { id, name, qty, priceCents };
  } else {
    store.items.push({ id, name, qty, priceCents });
  }
}

function removeItem(store: InventoryStore, id: number): void {
  store.items = store.items.filter((i) => i.id !== id);
}

function totalValuationCents(store: InventoryStore): number {
  return store.items.reduce((sum, i) => sum + i.qty * i.priceCents, 0);
}

const store: InventoryStore = { items: [], snapshot: [] };
upsertItem(store, 1, "GPU-Node", 4, 250000);
upsertItem(store, 2, "NVMe-4TB", 10, 30000);
upsertItem(store, 3, "Switch-100G", 2, 150000);
if (totalValuationCents(store) !== 1600000) {
  throw new Error("assert");
}
beginTx(store);
removeItem(store, 1);
upsertItem(store, 2, "NVMe-4TB", 1, 30000);
if (totalValuationCents(store) !== 330000) {
  throw new Error("assert");
}
rollbackTx(store);
if (store.items.length !== 3 || totalValuationCents(store) !== 1600000) {
  throw new Error("assert");
}
console.log(`Valuation=${totalValuationCents(store)}\nBENCH_05_OK`);
