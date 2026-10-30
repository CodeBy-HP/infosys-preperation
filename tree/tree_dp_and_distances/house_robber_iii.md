# Problem 25: House Robber III (LeetCode 337)

## Problem Statement

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called `root`.

Besides the `root`, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if **two directly-linked houses were broken into on the same night**.

Given the `root` of the binary tree, return the **maximum amount of money the thief can rob without alerting the police**.

---

## Examples

### Example 1
```text
     3
    / \
   2   3
    \   \
     3   1
```
- **Input:** `root = [3, 2, 3, null, 3, null, 1]`
- **Output:** `7` (`3 + 3 + 1 = 7`)

### Example 2
```text
     3
    / \
   4   5
  / \   \
 1   3   1
```
- **Input:** `root = [3, 4, 5, 1, 3, null, 1]`
- **Output:** `9` (`4 + 5 = 9`)

---

## Constraints

- The number of nodes in the tree is in the range $[1, 10^4]$.
- $0 \le \text{Node.val} \le 10^4$

---

## DP on Trees: Dual Choice State Tuple

For each node $u$, return a pair `pair<int, int> = {rob_u, skip_u}`:
1. **If we rob $u$ (`rob_u`):**
   - Cannot rob left or right children!
   $$\text{rob\_u} = u\to\text{val} + \text{skip\_left} + \text{skip\_right}$$
2. **If we skip $u$ (`skip_u`):**
   - We are free to either rob or skip each child independently:
   $$\text{skip\_u} = \max(\text{rob\_left}, \text{skip\_left}) + \max(\text{rob\_right}, \text{skip\_right})$$
3. Answer at root: $\max(\text{rob\_root}, \text{skip\_root})$.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Bottom-Up State Pair DFS** | $O(N)$ | $O(H)$ recursion stack |
