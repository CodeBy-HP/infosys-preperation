# Problem 2: Jump Game (LeetCode 55)

## Problem Statement

You are given an integer array `nums`. You are initially positioned at the array's **first index** ($0$), and each element in the array represents your **maximum jump length** at that position.

Return `true` if you can reach the **last index**, or `false` otherwise.

---

## Examples

### Example 1
- **Input:** `nums = [2, 3, 1, 1, 4]`
- **Output:** `true`
- **Explanation:** Jump 1 step from index 0 to 1, then 3 steps to the last index.

### Example 2
- **Input:** `nums = [3, 2, 1, 0, 4]`
- **Output:** `false`
- **Explanation:** You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

---

## Constraints

- $1 \le \text{nums.length} \le 10^4$
- $0 \le \text{nums}[i] \le 10^5$

---

## Greedy Logic: Rolling Maximum Reach

Instead of simulating all possible branch paths with DP or recursion (which takes $O(N^2)$ time), Greedy solves this in a single linear pass $O(N)$ with $O(1)$ space.

### The Rolling Maximum Variable (`farthest`):
1. Maintain `farthest` = the maximum index reachable from any previously visited valid tile.
2. Iterate through each index $i$:
   - **Gap Check:** If $i > farthest$, we are stranded on an unreachable index! Immediately return `false`.
   - **Update Reach:** Greedily extend $farthest = \max(farthest, i + nums[i])$.
   - **Early Exit:** If $farthest \ge N - 1$, the destination is already reachable; return `true`.

### The Backwards Greedy Approach (Alternative):
- Work backwards starting with $goal = N - 1$.
- For $i = N - 2$ down to $0$:
  - If $i + nums[i] \ge goal$, then index $i$ can reach $goal$. Move $goal = i$.
- At the end, return `goal == 0`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Forward Greedy (Rolling Max)** | $O(N)$ | $O(1)$ | Single pass with early termination |
| **Backward Greedy (Goal Shift)** | $O(N)$ | $O(1)$ | Single pass from right to left |
| **Dynamic Programming (Bottom-Up)** | $O(N^2)$ | $O(N)$ | Educational baseline |

