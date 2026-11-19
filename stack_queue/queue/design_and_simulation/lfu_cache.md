# LFU Cache (LeetCode 460)

## Problem Statement

Design and implement a data structure for a **Least Frequently Used (LFU) cache**.

Implement the `LFUCache` class:
- `LFUCache(int capacity)`: Initializes the object with the `capacity` of the data structure.
- `int get(int key)`: Gets the value of the `key` if the `key` exists in the cache. Otherwise, returns `-1`.
- `void put(int key, int value)`: Update the value of the `key` if present, or inserts the `key` if not already present. When the cache reaches its `capacity`, it should invalidate and remove the **least frequently used key** before inserting a new item.
- **Tie-Breaking Rule:** When two or more keys share the identical minimum frequency, invalidate the **least recently used (LRU)** key among them.

The functions `get` and `put` must each run in **$O(1)$ average time complexity**.

---

## Examples

### Example 1
- **Input:**
  `["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]`
  `[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]`
- **Output:**
  `[null, null, null, 1, null, -1, 3, null, -1, 3, 4]`
- **Explanation:**
  - `LFUCache lfu = new LFUCache(2);`
  - `lfu.put(1, 1);   // cache=[1,_], cnt(1)=1`
  - `lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1`
  - `lfu.get(1);      // return 1, cache=[1,2], cnt(1)=2, cnt(2)=1`
  - `lfu.put(3, 3);   // 2 is evicted (minFreq=1, LRU is 2), cache=[3,1], cnt(3)=1, cnt(1)=2`
  - `lfu.get(2);      // returns -1 (not found)`
  - `lfu.get(3);      // return 3, cache=[3,1], cnt(3)=2, cnt(1)=2`
  - `lfu.put(4, 4);   // both 1 and 3 have cnt=2, 1 is least recently used, evict 1. cache=[4,3], cnt(4)=1, cnt(3)=2`
  - `lfu.get(1);      // return -1 (not found)`
  - `lfu.get(3);      // return 3`
  - `lfu.get(4);      // return 4`

---

## Constraints

- $1 \le \text{capacity} \le 10^4$ (if capacity is 0, cache accepts nothing)
- $0 \le \text{key} \le 10^5$
- $0 \le \text{value} \le 10^9$
- At most $2 \times 10^5$ calls will be made to `get` and `put`.

---

## Core Invariant: Two Hash Maps + Frequency Doubly-Linked Lists

To maintain strict $O(1)$ complexity for $N \le 2 \times 10^5$:
1. **`keyTable` (`unordered_map<int, Node*>`):**
   - Maps `key` $\to$ pointer to Node containing `{key, value, freq}`.
2. **`freqTable` (`unordered_map<int, DoublyLinkedList*>`):**
   - Maps each frequency `freq` $\to$ a Doubly-Linked List containing all nodes accessed with that exact frequency.
   - Nodes inside each list are arranged in LRU order (front = MRU, back = LRU).
3. **`minFreq` Tracker:**
   - Tracks the current minimum frequency in the cache.
   - When a node's frequency increments from `f` to `f + 1`, it is spliced from `freqTable[f]` to `freqTable[f + 1]`.
   - If `freqTable[minFreq]` becomes empty after this move, increment `minFreq++`.
   - On inserting a brand-new key, `minFreq` is unconditionally reset to `1`.

```text
minFreq = 1
freqTable[1]: head <---> [Node(k=4)] <---> tail
freqTable[2]: head <---> [Node(k=3)] <---> [Node(k=1)] <---> tail
```

---

## Complexity Analysis

| Operation | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| `get(key)` | $O(1)$ average | $O(1)$ |
| `put(key, value)` | $O(1)$ average | $O(1)$ |
| **Total Memory** | — | $O(\text{capacity})$ |

