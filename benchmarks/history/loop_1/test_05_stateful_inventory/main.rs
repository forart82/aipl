#[derive(Clone)]
struct Item { id: i32, name: String, qty: i32, price_cents: i32 }
struct InventoryStore { items: Vec<Item>, snapshot: Vec<Item> }

impl InventoryStore {
    fn new() -> Self { Self { items: Vec::new(), snapshot: Vec::new() } }
    fn begin_tx(&mut self) { self.snapshot = self.items.clone(); }
    fn rollback_tx(&mut self) { self.items = self.snapshot.clone(); }
    fn upsert(&mut self, id: i32, name: &str, qty: i32, price: i32) {
        if let Some(it) = self.items.iter_mut().find(|i| i.id == id) {
            it.name = name.to_string(); it.qty = qty; it.price_cents = price;
        } else {
            self.items.push(Item { id, name: name.to_string(), qty, price_cents: price });
        }
    }
    fn remove(&mut self, id: i32) { self.items.retain(|i| i.id != id); }
    fn valuation(&self) -> i32 { self.items.iter().map(|i| i.qty * i.price_cents).sum() }
}

fn main() {
    let mut st = InventoryStore::new();
    st.upsert(1, "GPU-Node", 4, 250000);
    st.upsert(2, "NVMe-4TB", 10, 30000);
    st.upsert(3, "Switch-100G", 2, 150000);
    assert_eq!(st.valuation(), 1600000);
    st.begin_tx();
    st.remove(1);
    st.upsert(2, "NVMe-4TB", 1, 30000);
    assert_eq!(st.valuation(), 330000);
    st.rollback_tx();
    assert!(st.items.len() == 3 && st.valuation() == 1600000);
    println!("Valuation={}\nBENCH_05_OK", st.valuation());
}
