# Sum of Subarray Minimums (LeetCode 907)

## Problem Statement

Given an array of integers `arr`, find the **sum of $\min(b)$**, where $b$ ranges over every (contiguous) subarray of `arr`.

Since the answer may be large, return the answer **modulo $10^9 + 7$**.

---

## Examples

### Example 1
- **Input:** `arr = [3, 1, 2, 4]`
- **Output:** `17`
- **Explanation:**
  - Subarrays of length 1: `[3] -> 3`, `[1] -> 1`, `[2] -> 2`, `[4] -> 4`
  - Subarrays of length 2: `[3,1] -> 1`, `[1,2] -> 1`, `[2,4] -> 2`
  - Subarrays of length 3: `[3,1,2] -> 1`, `[1,2,4] -> 1`
  - Subarrays of length 4: `[3,1,2,4] -> 1`
  - Sum = $3 + 1 + 2 + 4 + 1 + 1 + 2 + 1 + 1 + 1 = 17$.

### Example 2
- **Input:** `arr = [11, 81, 94, 43, 3]`
- **Output:** `444`

---

## Constraints

- $1 \le \text{arr.length} \le 3 \times 10^4$
- $1 \le \text{arr}[i] \le 3 \times 10^4$

---

## The Contribution Trick & Monotonic Stack

Instead of computing the minimum for all $O(N^2)$ subarrays, calculate **how many subarrays have $\text{arr}[i]$ as their minimum**:

For element $\text{arr}[i]$:
1. Find the distance to the **Previous Smaller Element (PSE)**: $left = i - \text{pse}[i]$.
2. Find the distance to the **Next Smaller Element (NSE)**: $right = \text{nse}[i] - i$.
3. Total subarrays where $\text{arr}[i]$ is minimum:
   $$\text{count} = left \times right$$
4. Contribution to total sum:
   $$\text{contribution}[i] = (\text{arr}[i] \times left \times right) \pmod{10^9 + 7}$$

### Handling Duplicate Elements:
To prevent duplicate counting when identical elements appear:
- Use strictly smaller (`<`) for Previous Smaller.
- Use smaller or equal (`<=`) for Next Smaller.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Monotonic Stack (Contribution Technique)** | $O(N)$ | $O(N)$ |
| **Brute Force Subarray Enumeration** | $O(N^2)$ | $O(1)$ |

