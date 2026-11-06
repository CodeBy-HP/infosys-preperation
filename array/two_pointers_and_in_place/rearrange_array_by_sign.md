# Rearrange Array Elements by Sign (LeetCode 2149)

## Problem Statement

You are given a **0-indexed** integer array `nums` of **even length** $n$ containing an **equal number** of positive and negative integers.

Rearrange the elements of `nums` such that the modified array follows the given conditions:
1. Every consecutive pair of integers have **opposite signs**.
2. For all integers with the same sign, the **relative order** in which they were present in `nums` is preserved.
3. The rearranged array begins with a **positive** integer.

Return the modified array after rearranging the elements.

---

## Examples

### Example 1
- **Input:** `nums = [3, 1, -2, -5, 2, -4]`
- **Output:** `[3, -2, 1, -5, 2, -4]`
- **Explanation:**
  - Positive integers: `[3, 1, 2]`
  - Negative integers: `[-2, -5, -4]`
  - Alternating starting with positive: `[3, -2, 1, -5, 2, -4]`.

### Example 2
- **Input:** `nums = [-1, 1]`
- **Output:** `[1, -1]`

---

## Constraints

- $2 \le \text{nums.length} \le 2 \times 10^5$
- $\text{nums.length}$ is even.
- $1 \le |\text{nums}[i]| \le 10^5$
- `nums` consists of an equal number of positive and negative integers.

---

## Approaches

### Approach 1: Two Separate Arrays (Brute Force)
1. Split `nums` into two vectors `pos` and `neg`.
2. Interleave elements into `nums`:
   `nums[2 * i] = pos[i]` and `nums[2 * i + 1] = neg[i]`.
- **Time Complexity:** $\mathcal{O}(2N)$ (two passes)
- **Space Complexity:** $\mathcal{O}(N)$ extra auxiliary storage

### Approach 2: Single-Pass Two Pointer Placement (Optimal)
Initialize a result array of size $n$.
Maintain two write-pointers:
- `pos_idx = 0` (for even indices: $0, 2, 4, \dots$)
- `neg_idx = 1` (for odd indices: $1, 3, 5, \dots$)

Iterate through `nums` in a single pass:
- If `nums[i] > 0`: `result[pos_idx] = nums[i]`, then `pos_idx += 2`.
- Else: `result[neg_idx] = nums[i]`, then `neg_idx += 2`.
- **Time Complexity:** $\mathcal{O}(N)$ (strictly single pass)
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space (excluding result)

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Passes |
| :--- | :--- | :--- | :--- |
| **Two Buffer Arrays** | $\mathcal{O}(2N)$ | $\mathcal{O}(N)$ | 2 Passes |
| **Dual Index Pointers** | $\mathcal{O}(N)$ | $\mathcal{O}(1)$ auxiliary | **1 Pass** |

