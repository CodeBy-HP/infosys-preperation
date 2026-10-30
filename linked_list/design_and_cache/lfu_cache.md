# Problem 23: LFU Cache (LeetCode 460)

## Problem Statement

Design and implement a data structure for a **Least Frequently Used (LFU)** cache.

Implement the `LFUCache` class:
- `LFUCache(int capacity)` Initializes the object with the `capacity` of the data structure.
- `int get(int key)` Gets the value of the `key` if the `key` exists in the cache. Otherwise, returns `-1`.
- `void put(int key, int value)` Update the value of the `key` if present, or inserts the key if not already present. When the cache reaches its `capacity`, it should invalidate and remove the **least frequently used key** before inserting a new item. For this problem, when there is a **tie** (i.e., two or more keys with the same frequency), the **least recently used** key would be evicted.

To determine the least frequently used key, a use counter is maintained for each key. The use counter with the smallest value is the least frequently used key.

All methods must run in **$O(1)$ average time complexity**.

---

## Constraints

- $1 \le \text{capacity} \le 10^4$
- $0 \le \text{key} \le 10^5$
- $0 \le \text{value} \le 10^9$
- At most $2 \times 10^5$ calls will be made to `get` and `put`.

---

## High-Frequency OA Pattern: Two-Tier Hash Table + DLL

To achieve $O(1)$ evictions and updates:
1. `keyTable`: Maps `key` $\to$ iterator to its entry in the frequency list.
2. `freqTable`: Maps `freq` $\to$ Doubly Linked List of keys sharing that frequency (maintains LRU order among keys with the exact same frequency).
3. `minFreq`: Tracks the absolute minimum frequency across all stored items.
   - When a node frequency increases from $f$ to $f + 1$: if `freqTable[minFreq]` becomes empty, increment `minFreq = minFreq + 1`.
   - On eviction: remove from the tail of `freqTable[minFreq]`.

---

## Complexity Analysis

| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **`get(key)`** | $O(1)$ | $O(1)$ |
| **`put(key, value)`** | $O(1)$ | $O(1)$ |
| **Total Cache Space** | - | $O(\text{capacity})$ |
