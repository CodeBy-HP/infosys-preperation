# Find the Smallest Divisor Given a Threshold (LeetCode 1283)

## Problem Statement

Given an array of integers `nums` and an integer `threshold`, we will choose a positive integer `divisor`, divide all the array by it, and sum the division's result. Find the **smallest divisor** such that the result mentioned above is less than or equal to `threshold`.

Each result of division is rounded to the nearest integer greater than or equal to that element.
For example:
$$\lceil 7 / 3 \rceil = 3, \quad \lceil 10 / 2 \rceil = 5$$

---

## Examples

### Example 1
- **Input:** `nums = [1, 2, 5, 9]`, `threshold = 6`
- **Output:** `5`
- **Explanation:**
  - If divisor is 1: $1 + 2 + 5 + 9 = 17 > 6$.
  - If divisor is 4: $\lceil 1/4 \rceil + \lceil 2/4 \rceil + \lceil 5/4 \rceil + \lceil 9/4 \rceil = 1 + 1 + 2 + 3 = 7 > 6$.
  - If divisor is 5: $1 + 1 + 1 + 2 = 5 \le 6$.
  - The smallest valid divisor is `5`.

### Example 2
- **Input:** `nums = [44, 22, 33, 11, 1]`, `threshold = 5`
- **Output:** `44`

---

## Constraints

- $1 \le \text{nums.length} \le 5 \times 10^4$
- $1 \le \text{nums}[i] \le 10^6$
- $\text{nums.length} \le \text{threshold} \le 10^6$

---

## Predicate Monotonicity

Let $S(d) = \sum_{i=0}^{N-1} \lceil \text{nums}[i] / d \rceil$.
As divisor $d$ increases, each term $\lceil \text{nums}[i] / d \rceil$ non-increases. Thus, $S(d)$ is a **monotonically non-increasing** function with respect to $d$.

### Search Range
- **Minimum possible divisor:** $1$ (yields maximal sum $\sum nums[i]$).
- **Maximum necessary divisor:** $\max(nums)$ (yields minimal sum equal to $N$).

### Decision Invariant
- Ceiling division without floats:
  $$\lceil a / b \rceil = \frac{a + b - 1}{b}$$
- If $S(mid) \le \text{threshold}$: $mid$ is feasible! Save `ans = mid` and search for an even smaller divisor on the left: `right = mid - 1`.
- Else: Sum is too large; increase the divisor: `left = mid + 1`.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Binary Search on Answer** | $O(N \log(\max(nums)))$ | $O(1)$ |
| **Linear Search Divisor Scan** | $O(N \times \max(nums))$ | $O(1)$ |

