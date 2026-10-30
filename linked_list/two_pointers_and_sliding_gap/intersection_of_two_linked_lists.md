# Problem 9: Intersection of Two Linked Lists (LeetCode 160)

## Problem Statement

Given the heads of two singly linked-lists `headA` and `headB`, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return `null`.

The test cases are generated such that there are no cycles anywhere in the entire linked structure.

**Note:** The linked lists must retain their original structure after the function returns.

---

## Examples

### Example 1
```
A:          a1 -> a2 \
                      c1 -> c2 -> c3
B:    b1 -> b2 -> b3 /
```
- **Output:** Intersected at `c1`

---

## Constraints

- The number of nodes of `listA` is in the $m$.
- The number of nodes of `listB` is in the $n$.
- $1 \le m, n \le 3 \times 10^4$
- $1 \le \text{Node.val} \le 10^5$

---

## Mathematical Deduction: Path Equalization

Let:
- $a$ = length of unique prefix of list A.
- $b$ = length of unique prefix of list B.
- $c$ = length of shared common suffix.

If pointer `pA` traverses list A then switches to list B:
$$\text{Total distance} = a + c + b$$

If pointer `pB` traverses list B then switches to list A:
$$\text{Total distance} = b + c + a$$

Notice:
$$a + c + b = b + c + a$$

Both pointers traverse the exact same total distance!
- If the lists intersect, `pA` and `pB` will meet at the intersection node $c_1$ on their second pass.
- If the lists do not intersect ($c = 0$), both pointers reach `nullptr` simultaneously after $a + b$ steps, terminating the loop naturally.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Two-Pointer Equalization** | $O(M + N)$ | $O(1)$ | At most 2 passes, $O(1)$ auxiliary memory |
| **Length Difference Offset** | $O(M + N)$ | $O(1)$ | Advances longer list by $|M - N|$ |
| **Hash Set**                 | $O(M + N)$ | $O(M)$ or $O(N)$ | Stores visited pointers |
