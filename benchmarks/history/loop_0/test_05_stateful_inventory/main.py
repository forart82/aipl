class InventoryStore:
    def __init__(self):
        self.items: list[dict] = []
        self.snapshot: list[dict] = []
    def begin_tx(self):
        self.snapshot = [dict(i) for i in self.items]
    def rollback_tx(self):
        self.items = [dict(i) for i in self.snapshot]
    def upsert(self, item_id: int, name: str, qty: int, price: int):
        for i, it in enumerate(self.items):
            if it["id"] == item_id:
                self.items[i] = {"id": item_id, "name": name, "qty": qty, "price": price}
                return
        self.items.append({"id": item_id, "name": name, "qty": qty, "price": price})
    def remove(self, item_id: int):
        self.items = [i for i in self.items if i["id"] != item_id]
    def valuation(self) -> int:
        return sum(i["qty"] * i["price"] for i in self.items)

st = InventoryStore()
st.upsert(1, "GPU-Node", 4, 250000)
st.upsert(2, "NVMe-4TB", 10, 30000)
st.upsert(3, "Switch-100G", 2, 150000)
st.begin_tx()
st.remove(1)
st.upsert(2, "NVMe-4TB", 1, 30000)
assert st.valuation() == 330000
st.rollback_tx()
assert len(st.items) == 3 and st.valuation() == 1600000
print(f"Valuation={st.valuation()}\nBENCH_05_OK")
