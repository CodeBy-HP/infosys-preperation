# Problem 6: Subarray Sum Equals K (LeetCode 560)

## Problem Statement

Given an array of integers `nums` and an integer `k`, return the total number of subarrays whose sum equals to `k`.

A subarray is a contiguous non-empty sequence of elements within an array.

---

## Examples

### Example 1
- **Input:** `nums = [1, 1, 1], k = 2`
- **Output:** `2`

### Example 2
- **Input:** `nums = [1, 2, 3], k = 3`
- **Output:** `2`

---

## Constraints

- $1 \le \text{nums.length} \le 2 \times 10^4$
- $-1000 \le \text{nums}[i] \le 1000$
- $-10^7 \le k \le 10^7$

---

## Mathematical Principle: Prefix Sum Hash Map

Let $\text{prefix}[i] = \sum_{j=0}^{i} nums[j]$.
The sum of any subarray from $j + 1$ to $i$ is:
$$\text{sum}(j + 1, i) = \text{prefix}[i] - \text{prefix}[j] = k \implies \text{prefix}[j] = \text{prefix}[i] - k$$
Maintain a hash map `prefixCount` storing the occurrences of each prefix sum seen so far:
- Initialize `prefixCount[0] = 1` (handles subarrays starting at index 0).
- For each element, accumulate `currentSum += num`.
- Add `prefixCount[currentSum - k]` to the total count.
- Increment `prefixCount[currentSum]++`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Prefix Sum + Hash Map** | $O(N)$ | $O(N)$ |
