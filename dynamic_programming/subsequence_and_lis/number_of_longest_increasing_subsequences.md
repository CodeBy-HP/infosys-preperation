# Number of Longest Increasing Subsequences (LeetCode 673)

## Problem Statement

Given an integer array `nums`, return the **number of longest increasing subsequences**.

Notice that the sequence has to be **strictly increasing**.

---

## Examples

### Example 1:
```text
Input: nums = [1, 3, 5, 4, 7]
Output: 2
Explanation:
The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
Both have length 4, so there are 2 longest increasing subsequences.
```

### Example 2:
```text
Input: nums = [2, 2, 2, 2, 2]
Output: 5
Explanation:
The length of the longest increasing subsequence is 1.
There are 5 such subsequences: [2], [2], [2], [2], [2].
```

### Example 3:
```text
Input: nums = [1, 2, 4, 3, 5, 4, 7, 2]
Output: 3
Explanation:
The longest increasing subsequences have length 5:
[1, 2, 4, 5, 7], [1, 2, 3, 5, 7], [1, 2, 3, 4, 7].
Count is 3.
```

---

## Constraints

- `1 <= nums.length <= 2000`
- `-10^6 <= nums[i] <= 10^6`

---

## Recurrence Formulation & Algorithmic Approaches

### 1. Dual DP Arrays (Length & Frequency)
Standard LIS tracks only the maximum length ending at each index. Here, we must maintain two parallel dynamic programming arrays:
- `len[i]`: Length of the longest strictly increasing subsequence ending at index $i$.
- `cnt[i]`: Number of distinct longest increasing subsequences of length `len[i]` ending at index $i$.

### 2. Initialization
- For each $0 \le i < N$:
  - `len[i] = 1` (a single element is an increasing subsequence of length 1)
  - `cnt[i] = 1` (exactly 1 such subsequence initially)

### 3. State Transitions
For every index $i$ and every predecessor $j < i$ with $nums[j] < nums[i]$:
1. **Case 1: A longer subsequence ending at $i$ is discovered ($len[j] + 1 > len[i]$):**
   - We update the length: $len[i] = len[j] + 1$.
   - The number of ways to reach this new maximum length resets to the number of ways to reach $j$:
     $$cnt[i] = cnt[j]$$
2. **Case 2: An alternative path of the same maximum length is found ($len[j] + 1 == len[i]$):**
   - The length remains unchanged.
   - We accumulate the ways from this alternative branch:
     $$cnt[i] += cnt[j]$$

### 4. Final Aggregation
1. Find the global maximum length:
   $$\text{maxLen} = \max_{0 \le i < N} len[i]$$
2. Sum the counts for all indices whose LIS length equals $\text{maxLen}$:
   $$\text{Total Count} = \sum_{\substack{0 \le i < N \\ len[i] == \text{maxLen}}} cnt[i]$$

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Tabulation (Dual Arrays)** | $O(N^2)$ | $O(N)$ for `len` and `cnt` arrays |
| **Segment Tree / Fenwick Tree** | $O(N \log N)$ | $O(N)$ |
