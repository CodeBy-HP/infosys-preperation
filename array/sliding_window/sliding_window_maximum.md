# Problem 10: Sliding Window Maximum (LeetCode 239)

## Problem Statement

You are given an array of integers `nums`, there is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.

Return the **max sliding window**.

---

## Examples

### Example 1
- **Input:** `nums = [1,3,-1,-3,5,3,6,7], k = 3`
- **Output:** `[3,3,5,5,6,7]`
- **Explanation:**
```text
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

---

## Constraints

- $1 \le \text{nums.length} \le 10^5$
- $-10^4 \le \text{nums}[i] \le 10^4$
- $1 \le k \le \text{nums.length}$

---

## Pattern: Monotonic Decreasing Deque

Maintain a `deque<int>` storing **indices** of elements in strictly decreasing order of their values:
1. **Evict Out-of-Window:** While `!dq.empty() && dq.front() <= i - k`, pop front.
2. **Maintain Monotonicity:** While `!dq.empty() && nums[dq.back()] <= nums[i]`, pop back (these smaller elements can never be the maximum of any window containing `nums[i]`).
3. Push current index `dq.push_back(i)`.
4. The maximum of the window is always `nums[dq.front()]`!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Monotonic Deque** | $O(N)$ | $O(K)$ | Each index pushed & popped at most once |
| **Max-Heap**        | $O(N \log K)$ | $O(K)$ | Slower heap updates |
