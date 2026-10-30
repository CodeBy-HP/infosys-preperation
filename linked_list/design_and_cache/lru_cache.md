# Problem 22: LRU Cache (LeetCode 146)

## Problem Statement

Design a data structure that follows the constraints of a **Least Recently Used (LRU) Cache**.

Implement the `LRUCache` class:
- `LRUCache(int capacity)` Initialize the LRU cache with positive size `capacity`.
- `int get(int key)` Return the value of the `key` if the key exists, otherwise return `-1`.
- `void put(int key, int value)` Update the value of the `key` if the `key` exists. Otherwise, add the `key-value` pair to the cache. If the number of keys exceeds the `capacity` from this operation, **evict the least recently used key**.

The functions `get` and `put` must each run in **$O(1)$ average time complexity**.

---

## Examples

```cpp
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
```

---

## Constraints

- $1 \le \text{capacity} \le 3000$
- $0 \le \text{key} \le 10^4$
- $0 \le \text{value} \le 10^5$
- At most $2 \times 10^5$ calls will be made to `get` and `put`.

---

## Core Architecture: Doubly Linked List + Hash Map

To achieve strictly $O(1)$ operations:
1. **Hash Map (`unordered_map<int, Node*>`):** Provides $O(1)$ key lookup to find the corresponding Doubly Linked List node.
2. **Doubly Linked List with Pseudo Head & Tail:**
   - Most recently accessed nodes are placed directly behind `head`.
   - Least recently accessed nodes naturally sit in front of `tail`.
   - Node deletion (`removeNode`) and insertion (`addNode` at head) are strictly $O(1)$ pointer operations.

```
head <-> [Most Recent] <-> ... <-> [Least Recent] <-> tail
```

---

## Complexity Analysis

| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **`get(key)`** | $O(1)$ | $O(1)$ |
| **`put(key, value)`** | $O(1)$ | $O(1)$ |
| **Total Space** | - | $O(\text{capacity})$ |
