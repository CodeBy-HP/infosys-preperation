# Problem 14: Partition List (LeetCode 86)

## Problem Statement

Given the `head` of a linked list and a value `x`, partition it such that all nodes **less than** `x` come before nodes **greater than or equal** to `x`.

You should **preserve the original relative order** of the nodes in each of the two partitions.

---

## Examples

### Example 1
- **Input:** `head = [1, 4, 3, 2, 5, 2], x = 3`
- **Output:** `[1, 2, 2, 4, 3, 5]`

### Example 2
- **Input:** `head = [2, 1], x = 2`
- **Output:** `[1, 2]`

---

## Constraints

- The number of nodes in the list is in the range $[0, 200]$.
- $-100 \le \text{Node.val} \le 100$
- $-200 \le x \le 200$

---

## Pattern: Two Sentinel Chains (Less & Greater)

To preserve the relative order (stability) without extra memory:
1. Initialize two dummy heads: `lessDummy` and `greaterDummy`.
2. Maintain tail pointers: `lessTail = &lessDummy` and `greaterTail = &greaterDummy`.
3. Iterate through original list:
   - If `curr->val < x`: link to `lessTail->next = curr; lessTail = curr;`
   - Else: link to `greaterTail->next = curr; greaterTail = curr;`
4. **Critical termination:** Set `greaterTail->next = nullptr` (preventing cyclic loops with previous links!).
5. Stitch the two chains: `lessTail->next = greaterDummy.next`.

```
Input: [1, 4, 3, 2, 5, 2], x = 3

Less Chain:     dummyLess    -> 1 -> 2 -> 2
Greater Chain:  dummyGreater -> 4 -> 3 -> 5 -> NULL

Stitch:
1 -> 2 -> 2 -> 4 -> 3 -> 5 -> NULL
```

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Two Sentinel Chains** | $O(N)$ | $O(1)$ | Single pass, strictly preserves stability |
