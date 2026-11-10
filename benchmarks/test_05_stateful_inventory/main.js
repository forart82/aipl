class Item {
  constructor(id, name, qty, priceCents) {
    this.id = id;
    this.name = name;
    this.qty = qty;
    this.priceCents = priceCents;
  }
}

class InventoryStore {
  constructor() {
    this.items = [];
    this.snapshot = [];
  }
}

function beginTx(store) {
  store.snapshot = store.items.map((i) => new Item(i.id, i.name, i.qty, i.priceCents));
}

function rollbackTx(store) {
  store.items = store.snapshot.map((i) => new Item(i.id, i.name, i.qty, i.priceCents));
}

function upsertItem(store, id, name, qty, priceCents) {
  const idx = store.items.findIndex((i) => i.id === id);
  if (idx >= 0) {
    store.items[idx] = new Item(id, name, qty, priceCents);
  } else {
    store.items.push(new Item(id, name, qty, priceCents));
  }
}

function removeItem(store, id) {
  store.items = store.items.filter((i) => i.id !== id);
}

function totalValuationCents(store) {
  return store.items.reduce((sum, i) => sum + i.qty * i.priceCents, 0);
}

const store = new InventoryStore();
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
