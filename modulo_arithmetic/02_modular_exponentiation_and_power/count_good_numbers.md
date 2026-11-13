# Problem 5: Count Good Numbers (LeetCode 1922)

## Problem Statement

A digit string is **good** if the digits (0-indexed) satisfy:
- Digits at **even indices** are **even** ($0, 2, 4, 6, 8$ $\to$ 5 choices).
- Digits at **odd indices** are **prime** ($2, 3, 5, 7$ $\to$ 4 choices).

Given an integer $n$, return the **total number of good digit strings of length $n$**.
Since the answer may be very large, return it **modulo $10^9 + 7$**.

---

## Examples

### Example 1
- **Input:** `n = 1`
- **Output:** `5`
- **Explanation:** Only index 0 (even) exists: $5^1 = 5$ (`"0"`, `"2"`, `"4"`, `"6"`, `"8"`).

### Example 2
- **Input:** `n = 4`
- **Output:** `400`
- **Explanation:**
  - Even indices (0, 2): 2 positions $\to 5 \times 5 = 25$ choices.
  - Odd indices (1, 3): 2 positions $\to 4 \times 4 = 16$ choices.
  - Total = $25 \times 16 = 400$.

### Example 3
- **Input:** `n = 50`
- **Output:** `564908303`

---

## Constraints

- $1 \le n \le 10^{15}$

---

## Mathematical Formulation

For a string of length $n$:
1. **Count of even indices:**
   $$\text{even\_slots} = \lceil n / 2 \rceil = \frac{n + 1}{2}$$
2. **Count of odd indices:**
   $$\text{odd\_slots} = \lfloor n / 2 \rfloor = \frac{n}{2}$$

Because each position's choices are independent, the total number of combinations is:
$$\text{Total} = \Big( 5^{\text{even\_slots}} \times 4^{\text{odd\_slots}} \Big) \pmod{10^9 + 7}$$

Since $n$ can be as large as $10^{15}$, computing $5^{\text{even\_slots}}$ and $4^{\text{odd\_slots}}$ must be executed using **Binary Exponentiation** in $O(\log n)$ time.

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $\mathcal{O}(\log n)$ via binary exponentiation |
| **Space Complexity** | $\mathcal{O}(1)$ |

