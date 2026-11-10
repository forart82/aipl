#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

struct Item {
    int id;
    std::string name;
    int qty;
    int priceCents;
};

struct InventoryStore {
    std::vector<Item> items;
    std::vector<Item> snapshot;
};

void beginTx(InventoryStore& st) {
    st.snapshot = st.items;
}

void rollbackTx(InventoryStore& st) {
    st.items = st.snapshot;
}

void upsertItem(InventoryStore& st, int id, const std::string& name, int qty, int price) {
    for (auto& it : st.items) {
        if (it.id == id) {
            it.name = name;
            it.qty = qty;
            it.priceCents = price;
            return;
        }
    }
    st.items.push_back({id, name, qty, price});
}

void removeItem(InventoryStore& st, int id) {
    st.items.erase(
        std::remove_if(st.items.begin(), st.items.end(), [id](const Item& i) {
            return i.id == id;
        }),
        st.items.end()
    );
}

int totalValuationCents(const InventoryStore& st) {
    int sum = 0;
    for (const auto& it : st.items) {
        sum += it.qty * it.priceCents;
    }
    return sum;
}

int main() {
    InventoryStore st;
    upsertItem(st, 1, "GPU-Node", 4, 250000);
    upsertItem(st, 2, "NVMe-4TB", 10, 30000);
    upsertItem(st, 3, "Switch-100G", 2, 150000);
    assert(totalValuationCents(st) == 1600000);
    beginTx(st);
    removeItem(st, 1);
    upsertItem(st, 2, "NVMe-4TB", 1, 30000);
    assert(totalValuationCents(st) == 330000);
    rollbackTx(st);
    assert(st.items.size() == 3);
    assert(totalValuationCents(st) == 1600000);
    std::cout << "Valuation=" << totalValuationCents(st) << "\nBENCH_05_OK\n";
    return 0;
}
