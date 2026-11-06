# Build Heap From a Given Array ($O(N)$ Proof)

## Problem Overview
Given an arbitrary unsorted array of $N$ integers, rearrange its elements in-place so that it satisfies the Min-Heap (or Max-Heap) property.

---

## The $O(N)$ Bottom-Up Algorithm
Instead of inserting elements one-by-one from the top (which takes $O(N \log N)$):
1. Observe that all leaf nodes in the index range $[\lfloor N / 2 \rfloor, \; N - 1]$ are **already trivially valid heaps of size 1**!
2. Start at the **last non-leaf node**:
   $$\text{startIdx} = \lfloor N / 2 \rfloor - 1$$
3. Iterate backwards from `startIdx` down to `0`, calling `downHeapify(i)` on each node:
   ```cpp
   for (int i = n / 2 - 1; i >= 0; --i) {
       downHeapify(arr, n, i);
   }
   ```
Because children are processed before parents, when `downHeapify(i)` runs, both subtrees are mathematically guaranteed to be valid heaps!

---

## Mathematical Proof of $O(N)$ Complexity
Why does bottom-up `buildHeap` take $O(N)$ rather than $O(N \log N)$?
- A node at height $h$ can sink down at most $h$ steps.
- In a complete binary tree with $N$ nodes, there are at most $\lceil \frac{N}{2^{h + 1}} \rceil$ nodes at height $h$.
The total operations across all heights $h \in [0, \log N]$ is:
$$\text{Total Work} = \sum_{h=0}^{\log N} \left( \frac{N}{2^{h + 1}} \times O(h) \right) = \frac{N}{2} \sum_{h=0}^{\infty} \frac{h}{2^h}$$
Recall the classic convergent arithmetico-geometric series:
$$\sum_{h=0}^{\infty} \frac{h}{2^h} = \frac{1/2}{(1 - 1/2)^2} = 2$$
Therefore:
$$\text{Total Work} \le \frac{N}{2} \times 2 = O(N)$$

---

## Complexity Analysis
- **Time Complexity:** **$O(N)$** strictly linear!
- **Space Complexity:** $O(1)$ auxiliary space (in-place rearrangement).

