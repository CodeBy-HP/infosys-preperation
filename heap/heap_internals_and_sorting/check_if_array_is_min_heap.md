# Check if an Array Represents a Min-Heap

## Problem Overview
Given an array `arr` of size $N$, determine whether the given array represents a valid **Min-Heap**.
Return `true` if it represents a Min-Heap, otherwise return `false`.

---

## Internal Node Verification Invariant
In a complete binary tree, only **internal nodes** have children.
The internal nodes reside strictly in the index range:
$$0 \le i \le \left\lfloor \frac{N - 2}{2} \right\rfloor$$
For every internal node $i$:
1. If the left child exists ($2i + 1 < N$):
   $$\text{Must satisfy: } arr[i] \le arr[2i + 1]$$
2. If the right child exists ($2i + 2 < N$):
   $$\text{Must satisfy: } arr[i] \le arr[2i + 2]$$
If any condition fails, the array violates the Min-Heap property $\implies$ return `false`.

---

## Complexity Analysis
- **Time Complexity:** $O(N)$ single linear pass checking at most $N/2$ internal nodes.
- **Space Complexity:** $O(1)$ auxiliary space.

