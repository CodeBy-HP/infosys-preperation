# Heaps: Theory, Mechanics & Architecture

## What is a Heap?
A **Heap** is a specialized tree-based data structure that satisfies two defining invariants:
1. **Complete Binary Tree Property:** Every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible.
2. **Heap Order Property:**
   - **Min-Heap:** The key at each node is less than or equal to the keys of its children: $\text{key}(\text{parent}) \le \text{key}(\text{child})$. The minimum element is always at the root!
   - **Max-Heap:** The key at each node is greater than or equal to the keys of its children: $\text{key}(\text{parent}) \ge \text{key}(\text{child})$. The maximum element is always at the root!

---

## Zero-Based Array Indexing Invariants
Because a heap is a complete binary tree, it can be represented compactly in a **contiguous 1D array without pointers**:
For any node at index `i`:
- **Parent:** $\lfloor \frac{i - 1}{2} \rfloor$
- **Left Child:** $2i + 1$
- **Right Child:** $2i + 2$
- **Last Internal (Non-Leaf) Node:** $\lfloor \frac{N - 2}{2} \rfloor = \lfloor \frac{N}{2} \rfloor - 1$
- **Leaf Nodes:** Range $[\lfloor \frac{N}{2} \rfloor, \; N - 1]$

---

## Core Operations & Asymptotic Complexities
| Operation | Description | Time Complexity |
|---|---|---|
| `getMin()` / `getMax()` | Inspect root element | $O(1)$ |
| `insert(key)` | Add at end, Up-heapify (Swim) | $O(\log N)$ |
| `extractMin()` / `extractMax()` | Remove root, move last to root, Down-heapify (Sink) | $O(\log N)$ |
| `decreaseKey(i, val)` | Lower value, Up-heapify | $O(\log N)$ |
| `deleteKey(i)` | Set to $-\infty$, swim to root, extract | $O(\log N)$ |
| `buildHeap(arr)` | Bottom-up heap construction | **$O(N)$** |
| `heapSort(arr)` | In-place sorting | $O(N \log N)$ |

---

## Priority Queue: Heap vs Other Data Structures
| Data Structure | Insert | Extract-Min | Get-Min |
|---|---|---|---|
| Unsorted Array | $O(1)$ | $O(N)$ | $O(N)$ |
| Sorted Array | $O(N)$ | $O(1)$ | $O(1)$ |
| Balanced BST (`std::set`) | $O(\log N)$ | $O(\log N)$ | $O(\log N)$ |
| **Binary Heap (`std::priority_queue`)** | **$O(\log N)$** | **$O(\log N)$** | **$O(1)$** |

