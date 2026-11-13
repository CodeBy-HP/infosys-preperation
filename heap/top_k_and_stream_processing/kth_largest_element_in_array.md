# K-th Largest Element in an Array (LeetCode 215)

## Problem Overview
Given an integer array `nums` and an integer `k`, return the $k^{\text{th}}$ largest element in the array.
Note that it is the $k^{\text{th}}$ largest element in the sorted order, not the $k^{\text{th}}$ distinct element.

---

## 1. Min-Heap of Size $K$
Maintain a **Min-Heap containing the $K$ largest elements seen so far**:
1. Push each element into the min-heap.
2. If `heap.size() > k`, pop the smallest element via `pop()`.
3. The smallest element among the $K$ largest elements will always sit at the top of the min-heap:
   $$\text{Answer} = \text{heap.top()}$$
- **Time Complexity:** $O(N \log K)$
- **Space Complexity:** $O(K)$

---

## 2. Quickselect Algorithm (Average $O(N)$)
Using Hoare's / Lomuto's partitioning around a random pivot:
- The $K^{\text{th}}$ largest element is the element that would appear at index $N - k$ in fully sorted ascending order.
- Partition the array around a pivot: if pivot lands at index $N - k$, we are done!
- If pivot index $< N - k$, recurse only on the right subarray; else recurse on the left subarray.
- **Time Complexity:** $O(N)$ average, $O(N^2)$ worst case (mitigated by randomized pivot).
- **Space Complexity:** $O(1)$ auxiliary space.

