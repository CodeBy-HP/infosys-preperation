# Problem 3: Jump Game II (LeetCode 45)

## Problem Statement

You are given a 0-indexed array of integers `nums` of length $n$. You are initially positioned at `nums[0]`.

Each element `nums[i]` represents the maximum length of a forward jump from index `i`. In other words, if you are at `nums[i]`, you can jump to any `nums[i + j]` where:
- $0 \le j \le \text{nums}[i]$ and
- $i + j < n$.

Return the **minimum number of jumps** to reach `nums[n - 1]`. The test cases are generated such that you can always reach `nums[n - 1]`.

---

## Examples

### Example 1
- **Input:** `nums = [2, 3, 1, 1, 4]`
- **Output:** `2`
- **Explanation:** The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

### Example 2
- **Input:** `nums = [2, 3, 0, 1, 4]`
- **Output:** `2`

---

## Constraints

- $1 \le \text{nums.length} \le 10^4$
- $0 \le \text{nums}[i] \le 1000$
- It's guaranteed that you can reach `nums[n - 1]`.

---

## The Greedy "BFS Window" Paradigm

Instead of testing all paths with Dynamic Programming ($O(N^2)$), Greedy simulates a Breadth-First Search (BFS) level-by-level in $O(N)$ time without using a queue.

### State & Variables:
1. `jumps`: Total jump transitions committed so far.
2. `current_end`: The boundary of the current jump level/window.
3. `farthest`: The farthest index reachable among all launchpads visited in the current window.

### Transitions:
- As $i$ iterates from $0$ up to $N - 2$:
  - Greedily scan for the best next launchpad: `farthest = max(farthest, i + nums[i])`.
  - When $i == current\_end$, momentum for the current jump is exhausted:
    - We must commit to a jump: `jumps++`.
    - Set the new window boundary: `current_end = farthest`.
    - If `current_end >= n - 1`, we can break early.
- **Why loop up to $N - 2$?**
  - If we looped up to $N - 1$ and reached the finish line when $i == current\_end$, the algorithm would erroneously increment `jumps` an extra time at the destination.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Greedy (BFS Level Window)** | $O(N)$ | $O(1)$ | Optimal linear pass |
| **Dynamic Programming (Bottom-Up)** | $O(N^2)$ | $O(N)$ | Standard DP baseline |
| **Top-Down Memoized DP** | $O(N^2)$ | $O(N)$ | Recursion with cache |

