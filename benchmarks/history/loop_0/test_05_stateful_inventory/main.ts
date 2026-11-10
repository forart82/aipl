interface Item { id: number; name: string; qty: number; priceCents: number; }
class InventoryStore {
  items: Item[] = [];
  snapshot: Item[] = [];
  beginTx(): void { this.snapshot = this.items.map((i) => ({ ...i })); }
  rollbackTx(): void { this.items = this.snapshot.map((i) => ({ ...i })); }
  upsert(id: number, name: string, qty: number, priceCents: number): void {
    const idx = this.items.findIndex((i) => i.id === id);
    if (idx >= 0) this.items[idx] = { id, name, qty, priceCents };
    else this.items.push({ id, name, qty, priceCents });
  }
  remove(id: number): void { this.items = this.items.filter((i) => i.id !== id); }
  valuation(): number { return this.items.reduce((s, i) => s + i.qty * i.priceCents, 0); }
}
const st = new InventoryStore();
st.upsert(1, "GPU-Node", 4, 250000);
st.upsert(2, "NVMe-4TB", 10, 30000);
st.upsert(3, "Switch-100G", 2, 150000);
st.beginTx();
st.remove(1);
st.upsert(2, "NVMe-4TB", 1, 30000);
if (st.valuation() !== 330000) throw new Error("assert");
st.rollbackTx();
if (st.items.length !== 3 || st.valuation() !== 1600000) throw new Error("assert");
console.log(`Valuation=${st.valuation()}\nBENCH_05_OK`);
