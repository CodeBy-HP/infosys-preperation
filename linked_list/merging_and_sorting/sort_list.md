# Problem 13: Sort List (LeetCode 148)

## Problem Statement

Given the `head` of a linked list, return the list after sorting it in **ascending order**.

Can you sort the linked list in $O(n \log n)$ time and $O(1)$ memory (i.e. constant space)?

---

## Examples

### Example 1
- **Input:** `head = [4, 2, 1, 3]`
- **Output:** `[1, 2, 3, 4]`

### Example 2
- **Input:** `head = [-1, 5, 3, 4, 0]`
- **Output:** `[-1, 0, 3, 4, 5]`

---

## Constraints

- The number of nodes in the list is in the range $[0, 5 \times 10^4]$.
- $-10^5 \le \text{Node.val} \le 10^5$

---

## Algorithmic Mastery: Bottom-Up Iterative Merge Sort ($O(1)$ Space)

While Top-Down recursive merge sort takes $O(\log N)$ call stack space, **Bottom-Up Merge Sort** achieves strictly $O(1)$ auxiliary space:

1. Determine total length $N$ of list.
2. Iterate `step` size in powers of 2 ($1, 2, 4, 8, \dots < N$):
   - In each pass, split the list into pairs of sublists of size `step`:
     `split(head, step)` detaches the first `step` nodes and returns head of remaining list.
   - Merge the two sublists.
   - Append the merged result to current progress tail.

```
Initial:  [4] [2] [1] [3]
step = 1: [2 -> 4]  [1 -> 3]
step = 2: [1 -> 2 -> 3 -> 4]
```

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Bottom-Up Iterative Merge Sort** | $O(N \log N)$ | $O(1)$ | Truly $O(1)$ auxiliary memory |
| **Top-Down Recursive Merge Sort**  | $O(N \log N)$ | $O(\log N)$ | Call stack depth $\log N$ |
