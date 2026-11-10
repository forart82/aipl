import java.util.*;

public class Main {
    static class Item {
        int id;
        String name;
        int qty;
        int priceCents;
        Item(int id, String name, int qty, int priceCents) {
            this.id = id;
            this.name = name;
            this.qty = qty;
            this.priceCents = priceCents;
        }
        Item copy() {
            return new Item(id, name, qty, priceCents);
        }
    }

    static class InventoryStore {
        List<Item> items = new ArrayList<>();
        List<Item> snapshot = new ArrayList<>();
    }

    static void beginTx(InventoryStore st) {
        st.snapshot.clear();
        for (Item it : st.items) {
            st.snapshot.add(it.copy());
        }
    }

    static void rollbackTx(InventoryStore st) {
        st.items.clear();
        for (Item it : st.snapshot) {
            st.items.add(it.copy());
        }
    }

    static void upsertItem(InventoryStore st, int id, String name, int qty, int priceCents) {
        for (int i = 0; i < st.items.size(); i++) {
            if (st.items.get(i).id == id) {
                st.items.set(i, new Item(id, name, qty, priceCents));
                return;
            }
        }
        st.items.add(new Item(id, name, qty, priceCents));
    }

    static void removeItem(InventoryStore st, int id) {
        st.items.removeIf(i -> i.id == id);
    }

    static int totalValuationCents(InventoryStore st) {
        int sum = 0;
        for (Item it : st.items) {
            sum += it.qty * it.priceCents;
        }
        return sum;
    }

    public static void main(String[] args) {
        InventoryStore st = new InventoryStore();
        upsertItem(st, 1, "GPU-Node", 4, 250000);
        upsertItem(st, 2, "NVMe-4TB", 10, 30000);
        upsertItem(st, 3, "Switch-100G", 2, 150000);
        if (totalValuationCents(st) != 1600000) {
            throw new AssertionError();
        }
        beginTx(st);
        removeItem(st, 1);
        upsertItem(st, 2, "NVMe-4TB", 1, 30000);
        if (totalValuationCents(st) != 330000) {
            throw new AssertionError();
        }
        rollbackTx(st);
        if (st.items.size() != 3 || totalValuationCents(st) != 1600000) {
            throw new AssertionError();
        }
        System.out.println("Valuation=" + totalValuationCents(st) + "\nBENCH_05_OK");
    }
}
