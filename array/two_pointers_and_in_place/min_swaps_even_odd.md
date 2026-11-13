# Minimum Swaps to Segregate Even and Odd Numbers

## Problem Statement

Given an integer array `nums` of size $n$, find the **minimum number of adjacent swaps** required to segregate the array such that all even numbers are on one side and all odd numbers are on the other.

You must evaluate both configurations:
1. **Evens first:** All even numbers appear on the left, followed by all odd numbers on the right.
2. **Odds first:** All odd numbers appear on the left, followed by all even numbers on the right.

Return the minimum swaps between these two configurations.

---

## Examples

### Example 1
- **Input:** `nums = [1, 2, 3, 4]`
- **Output:** `1`
- **Explanation:**
  - Evens first: To achieve `[2, 4, 1, 3]`, swap `1` with `2` (1 swap), then `4` with `3` and `1` (2 swaps), total = 3 swaps.
  - Odds first: Swap `2` with `3` to achieve `[1, 3, 2, 4]`, total = 1 swap.
  - The minimum is $\min(3, 1) = 1$.

### Example 2
- **Input:** `nums = [2, 4, 6, 1, 3]`
- **Output:** `0`
- **Explanation:** Already segregated with all evens on the left.

---

## Inversion Counting & Complementarity Theorem

### 1. Stable Segregation Minimizes Swaps
Swapping two elements of the *same* parity (e.g., even with even) only creates redundant operations without helping segregation. Thus, the relative order of evens among themselves and odds among themselves must be strictly preserved.

### 2. Computing Inversions for Even-First
For each even number encountered at index $i$, it must be swapped past every odd number that precedes it:
$$\text{swaps}(\text{even-first}) = \sum_{x \in \text{evens}} (\text{count of odds before } x)$$

### 3. Complementarity Property
Let $E$ be the total count of evens and $O$ be the total count of odds.
There are exactly $E \times O$ pairs consisting of one even and one odd element. In any array:
- If the even element comes after the odd element, it contributes $1$ swap to even-first.
- If the even element comes before the odd element, it contributes $1$ swap to odd-first.

Therefore, the two swap counts are complementary:
$$\text{swaps}(\text{even-first}) + \text{swaps}(\text{odd-first}) = E \times O$$
$$\text{swaps}(\text{odd-first}) = (E \times O) - \text{swaps}(\text{even-first})$$

This allows computing both configurations in a single $O(N)$ linear pass using $O(1)$ extra space!

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $\mathcal{O}(N)$ single pass |
| **Space Complexity** | $\mathcal{O}(1)$ auxiliary space |

