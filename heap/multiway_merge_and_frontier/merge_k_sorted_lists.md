# Merge K Sorted Lists (LeetCode 23)

## Problem Overview
You are given an array of $K$ linked-lists `lists`, each linked-list is sorted in **ascending order**.
Merge all the linked-lists into one sorted linked-list and return it.

---

## Min-Heap of Size $K$ Invariant
At any point during merging, the next globally smallest node **must be the minimum among the currently active heads of the $K$ lists**:
1. Initialize a **Min-Heap** with a custom comparator comparing `ListNode*` by `val`.
2. Push the head node of each non-empty list into the min-heap ($O(K \log K)$).
3. Create a `dummy` sentinel node and a pointer `tail = &dummy`.
4. While the min-heap is not empty:
   - Pop the smallest node `curr = minHeap.top()`.
   - Attach it to `tail->next = curr`, advance `tail = tail->next`.
   - If `curr->next != nullptr`, push `curr->next` into the min-heap!
5. When the heap empties, all $N$ nodes have been linked in globally sorted order.

---

## Complexity Analysis
- **Time Complexity:** $O(N \log K)$ where $N$ is the total number of nodes across all $K$ lists, and $K$ is the number of linked lists.
- **Space Complexity:** $O(K)$ for the min-heap priority queue.

