# SPEC_05: Stateful Task/Inventory Engine (`test_05_stateful_inventory`)

- **Tier**: Medium
- **Category**: Transactional State Management, Snapshot & Rollback

## 1. Functional Requirements
1. Define `Item(id: int, name: str, qty: int, priceCents: int)` and `InventoryStore(items: [Item], snapshot: [Item])`.
2. Implement transactional operations:
   - `beginTx(store)`: deep-clones `items` into `snapshot`.
   - `rollbackTx(store)`: restores `items` from `snapshot`.
   - `upsertItem(store, id, name, qty, priceCents)`: updates existing item matching `id` in-place or appends new item if not found.
   - `removeItem(store, id)`: filters out item with `id`.
   - `totalValuationCents(store)`: sums `qty * priceCents` across all items.
3. Upsert 3 items (`(1, "GPU-Node", 4, 250000)`, `(2, "NVMe-4TB", 10, 30000)`, `(3, "Switch-100G", 2, 150000)`), assert valuation is `1600000`.
4. Call `beginTx`, remove item `1`, update item `2` to `qty = 1`, assert valuation is `330000`, call `rollbackTx`, and assert item count is `3` and valuation is restored to `1600000`.

## 2. Structural & Algorithmic Parity (Rule B)
- **Normalized Identifiers**: `Item`, `InventoryStore`, `beginTx`, `rollbackTx`, `upsertItem`, `removeItem`, `totalValuationCents`.

## 3. Expected Deterministic Stdout
```text
Valuation=1600000
BENCH_05_OK
```
