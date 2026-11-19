# LRU Cache (LeetCode 146)

## Problem Statement

Design a data structure that follows the constraints of a **Least Recently Used (LRU) cache**.

Implement the `LRUCache` class:
- `LRUCache(int capacity)`: Initialize the LRU cache with positive size `capacity`.
- `int get(int key)`: Return the value of the `key` if the key exists, otherwise return `-1`.
- `void put(int key, int value)`: Update the value of the `key` if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the `capacity` from this operation, **evict the least recently used key**.

The functions `get` and `put` must each run in **$O(1)$ average time complexity**.

---

## Examples

### Example 1
- **Input:**
  `["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]`
  `[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]`
- **Output:**
  `[null, null, null, 1, null, -1, null, -1, 3, 4]`
- **Explanation:**
  - `LRUCache lRUCache = new LRUCache(2);`
  - `lRUCache.put(1, 1); // cache is {1=1}`
  - `lRUCache.put(2, 2); // cache is {1=1, 2=2}`
  - `lRUCache.get(1);    // return 1, cache is {2=2, 1=1}`
  - `lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}`
  - `lRUCache.get(2);    // returns -1 (not found)`
  - `lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {3=3, 4=4}`
  - `lRUCache.get(1);    // return -1 (not found)`
  - `lRUCache.get(3);    // return 3`
  - `lRUCache.get(4);    // return 4`

---

## Constraints

- $1 \le \text{capacity} \le 3000$
- $0 \le \text{key} \le 10^4$
- $0 \le \text{value} \le 10^5$
- At most $2 \times 10^5$ calls will be made to `get` and `put`.

---

## Core Invariant: Doubly-Linked List + Hash Map

To satisfy strict $O(1)$ time for both search and eviction:
1. **Hash Map (`unordered_map<int, Node*>`):**
   - Provides $O(1)$ lookup from `key` to its corresponding memory node.
2. **Doubly-Linked List (DLL) with Sentinel Head and Tail:**
   - Sentinel `head` represents the **Most Recently Used (MRU)** position.
   - Sentinel `tail` represents the **Least Recently Used (LRU)** position.
   - Any accessed or newly inserted node is extracted from its current position and spliced immediately after `head` in $O(1)$.
   - Eviction removes the node immediately preceding `tail` in $O(1)$ without scanning.

```text
head <---> [Most Recent] <---> [...] <---> [Least Recent] <---> tail
```

---

## Complexity Analysis

| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| `get(key)` | $O(1)$ average | $O(1)$ auxiliary |
| `put(key, value)` | $O(1)$ average | $O(1)$ auxiliary |
| **Total Memory** | — | $O(\text{capacity})$ |

