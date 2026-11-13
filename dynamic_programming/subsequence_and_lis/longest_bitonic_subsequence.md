# Longest Bitonic Subsequence (GFG)

## Problem Statement

Given an array of positive integers `arr`, find the length of the **Longest Bitonic Subsequence**.

A sequence is called **bitonic** if it is strictly increasing and then strictly decreasing.
Formally, a subsequence is bitonic if there exists an index $k$ such that:
$$x_0 < x_1 < \dots < x_k > x_{k+1} > \dots > x_m$$
(Note: Depending on problem variations, a strictly increasing or strictly decreasing sequence may or may not be considered bitonic; the standard formulation requires at least one element on each side or considers pure increasing/decreasing sequences as degenerate bitonic sequences).

---

## Examples

### Example 1:
```text
Input: arr = [1, 2, 5, 3, 2]
Output: 5
Explanation:
The entire array [1, 2, 5, 3, 2] is bitonic with peak at 5:
1 < 2 < 5 > 3 > 2.
Length = 5.
```

### Example 2:
```text
Input: arr = [1, 11, 2, 10, 4, 5, 2, 1]
Output: 6
Explanation:
A valid bitonic subsequence of maximum length is [1, 2, 10, 4, 2, 1] (length 6)
or [1, 2, 10, 5, 2, 1] (length 6).
```

### Example 3:
```text
Input: arr = [10, 20, 30]
Output: 3
Explanation:
[10, 20, 30] is strictly increasing (degenerate bitonic sequence). Length = 3.
```

---

## Constraints

- $1 \le N \le 1000$
- $1 \le arr[i] \le 10^5$

---

## Recurrence Formulation & Algorithmic Approaches

### 1. Dual LIS (Forward & Backward)
A bitonic sequence is uniquely identified by its peak element $arr[i]$:
1. An increasing sequence of elements ending at $arr[i]$.
2. A decreasing sequence of elements starting at $arr[i]$ (which is equivalent to an increasing sequence moving right-to-left ending at $arr[i]$).

### 2. State Formulation
- $dp_1[i]$: Length of the longest strictly increasing subsequence ending at index $i$ (scanned $0 \to N - 1$):
  $$dp_1[i] = 1 + \max_{\substack{0 \le j < i \\ arr[j] < arr[i]}} dp_1[j]$$
- $dp_2[i]$: Length of the longest strictly increasing subsequence starting at index $i$ and moving right (scanned $N - 1 \to 0$):
  $$dp_2[i] = 1 + \max_{\substack{i < j < N \\ arr[j] < arr[i]}} dp_2[j]$$

### 3. Combining at the Peak
If index $i$ serves as the peak element:
$$\text{Bitonic Length}(i) = dp_1[i] + dp_2[i] - 1$$
We subtract $1$ because element $arr[i]$ is counted in both $dp_1[i]$ and $dp_2[i]$.

The answer is:
$$\max_{0 \le i < N} (dp_1[i] + dp_2[i] - 1)$$

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Tabulation (Dual LIS)** | $O(N^2)$ | $O(N)$ for $dp_1$ and $dp_2$ |
| **Binary Search Patience Sort** | $O(N \log N)$ | $O(N)$ |
