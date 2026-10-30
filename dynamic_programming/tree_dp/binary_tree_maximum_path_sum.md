# Problem 14: Binary Tree Maximum Path Sum (DP on Trees)

## Problem Statement

A **path** in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence **at most once**. Note that the path does **not** need to pass through the root.

The **path sum** of a path is the sum of the node's values in the path.

Given the `root` of a binary tree, return the **maximum path sum** of any non-empty path.

---

## Examples

### Example 1
```text
    1
   / \
  2   3
```
- **Input:** `root = [1, 2, 3]`
- **Output:** `6`
- **Explanation:** The optimal path is $2 \rightarrow 1 \rightarrow 3$ with path sum $2 + 1 + 3 = 6$.

### Example 2
```text
      -10
      /  \
     9   20
        /  \
       15   7
```
- **Input:** `root = [-10, 9, 20, null, null, 15, 7]`
- **Output:** `42`
- **Explanation:** The optimal path is $15 \rightarrow 20 \rightarrow 7$ with path sum $15 + 20 + 7 = 42$.

---

## Constraints

- The number of nodes in the tree is in the range $[1, 3 \times 10^4]$.
- $-1000 \le \text{Node.val} \le 1000$

---

## The Paradigm: "The Arch" vs. "The Straight Line"

At any given node in a binary tree, the role of a path splits into two key concepts:

1. **The Straight Line (Subproblem Return Value):**
   - The path comes up from either the left child or the right child, visits `node`, and extends upwards towards the parent.
   - It can only pick **one child branch** (either left or right) because a valid path cannot fork in three directions.
   - Any child returning a negative contribution is pruned using $\max(0, \text{gain})$.
   $$\text{Straight Line Gain} = \text{node.val} + \max(0,\, \max(\text{leftGain},\, \text{rightGain}))$$

2. **The Arch (The Local Maximum / Answer Candidate):**
   - The path connects the left subtree, passes through `node`, and continues into the right subtree:
   $$\text{Arch Sum} = \text{node.val} + \max(0, \text{leftGain}) + \max(0, \text{rightGain})$$
   - This "Arch" cannot be extended upwards to the parent, but it can be the globally optimal answer!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Top-Down Post-Order Traversal** | $O(N)$ | $O(H)$ | $N$ nodes visited once; $H$ is the tree height (call stack) |
| **Iterative Post-Order with Stack** | $O(N)$ | $O(N)$ | Post-order stack traversal simulation |

