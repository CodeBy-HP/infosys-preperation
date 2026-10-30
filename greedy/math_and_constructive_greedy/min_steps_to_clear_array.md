# Minimum Steps to Clear Array by Pairing Distinct Elements

## Problem Statement

You are given an integer array `nums`. You want to clear all elements from the array in the **minimum number of steps**.

In each step, you can perform one of the following operations:
1. **Pair Removal:** If the array contains at least two distinct elements ($X \ne Y$), choose and remove both $X$ and $Y$ together (removes 2 elements in 1 step).
2. **Single Removal:** If no two distinct elements can be paired (e.g., only 1 element remains or all remaining elements are identical), remove any single element $X$ (removes 1 element in 1 step).

Return the **minimum total number of steps** required to remove all elements from the array.

---

## Examples

### Example 1
- **Input:** `nums = [1, 2]`
- **Output:** `1`
- **Explanation:** $1 \ne 2$, so we can remove both in a single step.

### Example 2
- **Input:** `nums = [2, 2]`
- **Output:** `2`
- **Explanation:** Both elements are identical ($2 = 2$), so they cannot be paired. They must be removed individually in 2 steps.

### Example 3
- **Input:** `nums = [2, 2, 3, 3, 1]`
- **Output:** `3`
- **Explanation:**
  - Step 1: Pair and remove `(2, 3)` $\rightarrow$ remaining: `[2, 3, 1]`.
  - Step 2: Pair and remove `(2, 3)` $\rightarrow$ remaining: `[1]`.
  - Step 3: Remove `1`.
  - Total steps = 3.

---

## Constraints

- $1 \le \text{nums.length} \le 10^5$
- $1 \le \text{nums}[i] \le 10^9$

---

## Mathematical Logic & Paradigms

Let $N$ be the total length of the array, and let `max_freq` be the frequency of the most frequent element in `nums`.

### The Two Bottlenecks:
1. **Physical Capacity Bound ($\lceil N / 2 \rceil$):**
   - Each step can remove at most 2 elements.
   - Therefore, you can never clear $N$ elements in fewer than $\lceil N / 2 \rceil = (N + 1) / 2$ steps.

2. **Majority Bottleneck (`max_freq`):**
   - If an element appears `max_freq > N / 2` times, there are only $N - \text{max\_freq}$ other elements available to pair with it.
   - Even if every other element is paired with this majority element, the leftover majority elements must be removed one by one.
   - Total steps = $(N - \text{max\_freq}) + (\text{max\_freq} - (N - \text{max\_freq})) = \text{max\_freq}$.

### Closed-Form Formula:
$$\text{Minimum Steps} = \max\left(\text{max\_freq},\, \left\lceil \frac{N}{2} \right\rceil \right)$$

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Max-Heap Greedy Simulation** | $O(U \log U)$ where $U \le N$ is unique count | $O(U)$ | Simulates optimal pairing |
| **Optimal Frequency Math Formula** | $O(N)$ | $O(U)$ | Computes $\max(\text{max\_freq}, (N+1)/2)$ |

