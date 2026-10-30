# Problem 11: Path Sum III (LeetCode 437)

## Problem Statement

Given the `root` of a binary tree and an integer `targetSum`, return the number of paths where the sum of the values along the path equals `targetSum`.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

---

## Examples

### Example 1
```text
          10
         /  \
        5   -3
       / \    \
      3   2   11
     / \   \
    3  -2   1
```
- **Input:** `root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8`
- **Output:** `3`
- **Explanation:** The paths that sum to 8 are:
  1. `5 -> 3`
  2. `5 -> 2 -> 1`
  3. `-3 -> 11`

---

## Constraints

- The number of nodes in the tree is in the range $[0, 1000]$.
- $-10^9 \le \text{Node.val} \le 10^9$
- $-1000 \le \text{targetSum} \le 1000$

---

## Pattern: Prefix Sum Hash Map on Trees ($O(N)$ Time)

Just like the 1D array problem "Subarray Sum Equals K", we can track running prefix sums along the branch:
$$\text{currentSum} - \text{targetSum} = \text{previousPrefixSum}$$
1. Maintain `unordered_map<long long, int> prefixCount` where `prefixCount[0] = 1`.
2. As you visit node $u$, update `currentSum += u->val`.
3. Add `prefixCount[currentSum - targetSum]` to `totalPaths`.
4. Increment `prefixCount[currentSum]++`.
5. Recurse into children.
6. **Backtrack:** Decrement `prefixCount[currentSum]--` so the prefix sum doesn't leak into sibling subtrees!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Prefix Sum + Hash Map** | $O(N)$ | $O(H)$ | Strictly single pass with backtracking |
| **Brute Force (Double DFS)** | $O(N^2)$ | $O(H)$ | Tests every node as starting root |
