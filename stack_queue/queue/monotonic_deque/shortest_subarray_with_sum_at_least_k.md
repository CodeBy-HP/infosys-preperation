# Shortest Subarray with Sum at Least K (LeetCode 862)

## Problem Statement
Given an integer array `nums` and an integer `k`, return the length of the shortest non-empty subarray of `nums` with a sum of at least `k`. If there is no such subarray, return `-1`.

A subarray is a contiguous part of an array.

### Example 1:
```
Input: nums = [1], k = 1
Output: 1
```

### Example 2:
```
Input: nums = [1,2], k = 4
Output: -1
```

### Example 3:
```
Input: nums = [2,-1,2], k = 3
Output: 3
```

### Constraints:
- `1 <= nums.length <= 10^5`
- `-10^5 <= nums[i] <= 10^5`
- `1 <= k <= 10^9`

---

## Pattern Insight: Prefix Sums + Monotonic Increasing Deque
- Subarray sum from index $i$ to $j-1$ is $P[j] - P[i]$. We want $P[j] - P[i] \ge k$ with $j > i$ minimizing $j - i$.
- Because `nums` contains **negative numbers**, $P$ is not monotonically increasing, so standard two pointers / sliding window fails!
- Maintain a deque of indices `dq` storing prefix sums in strictly increasing order:
  1. If $P[j] - P[dq.front()] \ge k$, this is a valid window of size $j - dq.front()$. Update our minimum length and `pop_front()`, because any future $j' > j$ will only produce a longer subarray with this same start index.
  2. While $P[j] \le P[dq.back()]$, `pop_back()`. Why? Because $j$ is greater than `dq.back()` AND $P[j]$ is smaller. For any future target $P[x]$, using $j$ will both yield a larger difference $P[x] - P[j]$ AND a shorter length $x - j$. Thus `dq.back()` is completely dominated!
  3. Push $j$ to the back of the deque.

---

## Complexity
- **Time Complexity:** $O(N)$ — Every index is added and removed from the deque at most once.
- **Space Complexity:** $O(N)$ — Prefix sum array and deque.
