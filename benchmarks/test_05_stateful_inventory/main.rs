#[derive(Clone)]
struct Item {
    id: i32,
    name: String,
    qty: i32,
    price_cents: i32,
}

struct InventoryStore {
    items: Vec<Item>,
    snapshot: Vec<Item>,
}

#[allow(non_snake_case)]
fn beginTx(st: &mut InventoryStore) {
    st.snapshot = st.items.clone();
}

#[allow(non_snake_case)]
fn rollbackTx(st: &mut InventoryStore) {
    st.items = st.snapshot.clone();
}

#[allow(non_snake_case)]
fn upsertItem(st: &mut InventoryStore, id: i32, name: &str, qty: i32, price: i32) {
    for it in &mut st.items {
        if it.id == id {
            it.name = name.to_string();
            it.qty = qty;
            it.price_cents = price;
            return;
        }
    }
    st.items.push(Item {
        id,
        name: name.to_string(),
        qty,
        price_cents: price,
    });
}

#[allow(non_snake_case)]
fn removeItem(st: &mut InventoryStore, id: i32) {
    st.items.retain(|i| i.id != id);
}

#[allow(non_snake_case)]
fn totalValuationCents(st: &InventoryStore) -> i32 {
    st.items.iter().map(|i| i.qty * i.price_cents).sum()
}

fn main() {
    let mut st = InventoryStore {
        items: Vec::new(),
        snapshot: Vec::new(),
    };
    upsertItem(&mut st, 1, "GPU-Node", 4, 250000);
    upsertItem(&mut st, 2, "NVMe-4TB", 10, 30000);
    upsertItem(&mut st, 3, "Switch-100G", 2, 150000);
    assert_eq!(totalValuationCents(&st), 1600000);
    beginTx(&mut st);
    removeItem(&mut st, 1);
    upsertItem(&mut st, 2, "NVMe-4TB", 1, 30000);
    assert_eq!(totalValuationCents(&st), 330000);
    rollbackTx(&mut st);
    assert_eq!(st.items.len(), 3);
    assert_eq!(totalValuationCents(&st), 1600000);
    println!("Valuation={}\nBENCH_05_OK", totalValuationCents(&st));
}
