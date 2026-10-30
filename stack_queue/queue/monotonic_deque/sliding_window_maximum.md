# Sliding Window Maximum (LeetCode 239)

## Problem Statement
You are given an array of integers `nums`, there is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

### Example 1:
```
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

### Constraints:
- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`
- `1 <= k <= nums.length`

---

## Pattern Insight: Monotonic Decreasing Deque
- A naive window scan takes $O(N \times k)$ time, which TLEs for $N=10^5, k=10^5$.
- A max-heap takes $O(N \log k)$, but removal requires lazy deletion.
- **Monotonic Deque ($O(N)$ optimal)**:
  - Maintain indices in `std::deque<int>` in strictly decreasing order of their corresponding values (`nums[dq.front()] > ... > nums[dq.back()]`).
  - For each new element `nums[i]`:
    1. **Expire outdated indices**: If `dq.front() <= i - k`, pop from the front.
    2. **Maintain monotonicity**: While `dq.back()` has value $\le$ `nums[i]`, it can never be the maximum of this or any future window that includes `nums[i]`. Pop from back!
    3. **Push current index**: `dq.push_back(i)`.
    4. **Record maximum**: Once $i \ge k - 1$, the maximum is always at `nums[dq.front()]`.

---

## Complexity
- **Time Complexity:** $O(N)$ — Every index is pushed and popped from the deque at most once.
- **Space Complexity:** $O(k)$ — Deque stores at most $k$ indices.
