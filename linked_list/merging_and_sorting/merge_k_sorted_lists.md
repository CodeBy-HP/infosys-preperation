# Problem 12: Merge k Sorted Lists (LeetCode 23)

## Problem Statement

You are given an array of $k$ linked-lists `lists`, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

---

## Examples

### Example 1
- **Input:** `lists = [[1,4,5],[1,3,4],[2,6]]`
- **Output:** `[1,1,2,3,4,4,5,6]`
- **Explanation:** The linked-lists are:
```
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
```

### Example 2
- **Input:** `lists = []`
- **Output:** `[]`

---

## Constraints

- $k == \text{lists.length}$
- $0 \le k \le 10^4$
- $0 \le \text{lists}[i]\text{.length} \le 500$
- $-10^4 \le \text{lists}[i][j] \le 10^4$
- `lists[i]` is sorted in ascending order.
- The total sum of nodes over all lists is $\le 10^4$.

---

## Two Major Assessment Paradigms

### 1. Divide and Conquer (Pairwise Merge)
Group the $k$ lists into pairs and merge each pair using the standard two-list merge.
After 1st pass: $k/2$ lists remain.
After 2nd pass: $k/4$ lists remain.
Total rounds: $\log_2 k$. Each round processes all $N$ nodes.
$$\text{Total Time} = O(N \log k), \quad \text{Space} = O(1)$$

### 2. Min-Heap (Priority Queue)
Insert the heads of all $k$ non-empty lists into a min-heap of size $k$.
Repeatedly extract the minimum node, append it to merged list, and push its `next` pointer into the heap.
$$\text{Total Time} = O(N \log k), \quad \text{Space} = O(k)$$

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Divide & Conquer** | $O(N \log k)$ | $O(1)$ | Strictly optimal space |
| **Min-Heap (Priority Queue)** | $O(N \log k)$ | $O(k)$ | Excellent for streaming data |
| **Sequential Merge** | $O(k \times N)$ | $O(1)$ | Slow: merges lists 1-by-1 |
