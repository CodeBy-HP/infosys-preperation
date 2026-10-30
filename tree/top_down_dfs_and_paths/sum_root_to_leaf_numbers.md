# Problem 12: Sum Root to Leaf Numbers (LeetCode 129)

## Problem Statement

You are given the `root` of a binary tree containing digits from `0` to `9` only.

Each root-to-leaf path in the tree represents a number.
For example, the root-to-leaf path `1 -> 2 -> 3` represents the number `123`.

Return the **total sum** of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a **32-bit** integer.

---

## Examples

### Example 1
```text
    1
   / \
  2   3
```
- **Input:** `root = [1, 2, 3]`
- **Output:** `25` (`12 + 13 = 25`)

### Example 2
```text
      4
     / \
    9   0
   / \
  5   1
```
- **Input:** `root = [4, 9, 0, 5, 1]`
- **Output:** `1026` (`495 + 491 + 40 = 1026`)

---

## Constraints

- The number of nodes in the tree is in the range $[1, 1000]$.
- $0 \le \text{Node.val} \le 9$
- The depth of the tree will not exceed $10$.

---

## Base-10 Accumulation Recurrence

At any node $u$ with parent running value `currentSum`:
$$\text{nextSum} = \text{currentSum} \times 10 + u\to\text{val}$$
- If $u$ is a leaf: return `nextSum`.
- Else: return $\text{dfs}(u\to\text{left}, \text{nextSum}) + \text{dfs}(u\to\text{right}, \text{nextSum})$.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Top-Down Accumulation** | $O(N)$ | $O(H)$ recursion stack |
