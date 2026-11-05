# Problem 15: Number of Ways to Reorder Array to Get Same BST (LeetCode 1569)

## Problem Statement

Given an array `nums` that represents a permutation of integers from $1$ to $n$. We are constructing a binary search tree (BST) by inserting the elements of `nums` in order into an initially empty BST.

Return the **number of ways to reorder `nums`** such that the constructed BST is **identical** to that formed from the original array `nums`.

Since the answer may be very large, return it **modulo $10^9 + 7$**.

*(Note: The original order does not count as a reordering, so the final answer is $\text{Total Ways} - 1$).*

---

## Examples

### Example 1
- **Input:** `nums = [2, 1, 3]`
- **Output:** `1`
- **Explanation:** We can only reorder as `[2, 3, 1]`.

### Example 2
- **Input:** `nums = [3, 4, 5, 1, 2]`
- **Output:** `5`

---

## Mathematical Formulation: Subtree Interleaving Combinatorics

In any array that generates a BST:
1. The **first element** `root = nums[0]` must remain the root.
2. All subsequent elements smaller than `root` belong to the **left subtree**:
   $$\text{left} = \{x \in \text{nums} \mid x < \text{root}\}, \quad L = |\text{left}|$$
3. All subsequent elements greater than `root` belong to the **right subtree**:
   $$\text{right} = \{x \in \text{nums} \mid x > \text{root}\}, \quad R = |\text{right}|$$

### The Interleaving Principle:
- The relative internal order among elements in `left` only affects the left subtree.
- The relative internal order among elements in `right` only affects the right subtree.
- Any element from `left` can appear before or after any element from `right` in the overall sequence without changing the resulting BST!

Out of the $(L + R)$ total remaining positions, we choose $L$ positions for the left subtree elements:
$$\text{ways to interleave} = \binom{L + R}{L} = \binom{L + R}{R}$$

### Full Recurrence:
$$\text{ways}(\text{nums}) = \binom{L + R}{L} \times \text{ways}(\text{left}) \times \text{ways}(\text{right}) \pmod{10^9 + 7}$$

---

## Complexity Analysis

| Phase | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Pascal's Triangle Precomputation** | $\mathcal{O}(N^2)$ | $\mathcal{O}(N^2)$ |
| **Recursive Tree Decomposition** | $\mathcal{O}(N^2)$ worst case, $\mathcal{O}(N \log N)$ average | $\mathcal{O}(N)$ recursion stack |
| **Total** | $\mathcal{O}(N^2)$ | $\mathcal{O}(N^2)$ |

