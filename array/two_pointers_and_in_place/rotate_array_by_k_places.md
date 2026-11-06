# Rotate Array by K Places (Left and Right)

## Problem Statement

Given an integer array `nums` of size $n$ and a non-negative integer $k$, rotate the array by $k$ places.

- **Left Rotation by $k$:** Elements shift left by $k$ positions; the first $k$ elements wrap around to the end.
- **Right Rotation by $k$ (LeetCode 189):** Elements shift right by $k$ positions; the last $k$ elements wrap around to the front.

---

## Examples

### Example 1 (Left Rotate by $k = 2$)
- **Input:** `nums = [1, 2, 3, 4, 5, 6, 7]`, `k = 2`
- **Output:** `[3, 4, 5, 6, 7, 1, 2]`

### Example 2 (Right Rotate by $k = 3$)
- **Input:** `nums = [1, 2, 3, 4, 5, 6, 7]`, `k = 3`
- **Output:** `[5, 6, 7, 1, 2, 3, 4]`

---

## Constraints

- $1 \le \text{nums.length} \le 10^5$
- $0 \le k \le 10^9$
- $-10^9 \le \text{nums}[i] \le 10^9$

---

## Approaches

### Approach 1: Brute Force (Shift by 1, K times)
Repeatedly shift the array by 1 position $k \pmod n$ times.
- **Time Complexity:** $\mathcal{O}(N \times K)$
- **Space Complexity:** $\mathcal{O}(1)$

### Approach 2: Better (Auxiliary Buffer of Size $K$)
Copy the first $k$ elements into a temporary buffer, shift the remaining $n - k$ elements, and copy the buffer back to the end.
- **Time Complexity:** $\mathcal{O}(N)$
- **Space Complexity:** $\mathcal{O}(K)$

### Approach 3: Optimal (The 3-Step Reversal Algorithm)
Normalize $k = k \pmod n$.

**For Left Rotation by $k$:**
1. Reverse prefix: `reverse(nums, 0, k - 1)`
2. Reverse suffix: `reverse(nums, k, n - 1)`
3. Reverse entire array: `reverse(nums, 0, n - 1)`

**For Right Rotation by $k$ (LeetCode 189):**
1. Reverse entire array: `reverse(nums, 0, n - 1)`
2. Reverse prefix of size $k$: `reverse(nums, 0, k - 1)`
3. Reverse suffix: `reverse(nums, k, n - 1)`

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Brute Force** | $\mathcal{O}(N \times K)$ | $\mathcal{O}(1)$ |
| **Auxiliary Buffer** | $\mathcal{O}(N)$ | $\mathcal{O}(K)$ |
| **3-Step Reversal** | $\mathcal{O}(N)$ | $\mathcal{O}(1)$ in-place |

