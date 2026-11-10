import java.util.*;

public class Main {
    static class Item {
        int id, qty, priceCents; String name;
        Item(int i, String n, int q, int p) { id = i; name = n; qty = q; priceCents = p; }
        Item copy() { return new Item(id, name, qty, priceCents); }
    }
    static List<Item> cloneList(List<Item> src) {
        List<Item> out = new ArrayList<>();
        for (Item it : src) out.add(it.copy());
        return out;
    }
    static void upsert(List<Item> items, int id, String name, int qty, int price) {
        for (int i = 0; i < items.size(); i++) {
            if (items.get(i).id == id) { items.set(i, new Item(id, name, qty, price)); return; }
        }
        items.add(new Item(id, name, qty, price));
    }
    static int valuation(List<Item> items) {
        int sum = 0;
        for (Item it : items) sum += it.qty * it.priceCents;
        return sum;
    }
    public static void main(String[] args) {
        List<Item> items = new ArrayList<>();
        upsert(items, 1, "GPU-Node", 4, 250000);
        upsert(items, 2, "NVMe-4TB", 10, 30000);
        upsert(items, 3, "Switch-100G", 2, 150000);
        List<Item> snap = cloneList(items);
        items.removeIf(i -> i.id == 1);
        upsert(items, 2, "NVMe-4TB", 1, 30000);
        if (valuation(items) != 330000) throw new AssertionError();
        items = cloneList(snap);
        if (items.size() != 3 || valuation(items) != 1600000) throw new AssertionError();
        System.out.println("Valuation=" + valuation(items) + "\nBENCH_05_OK");
    }
}
