# Problem 23: Maximum Cyclic Prefix XOR Sum

## Problem Statement

You are given an array `ARR` consisting of $N$ integers. The array is cyclic, meaning the element after the last index is the first index, and the element before the first index is the last index.

You construct a new array `RES` of size $N$ using the following algorithm:
1. Start at any index of `ARR`.
2. Choose a direction (left or right).
3. Traverse all $N$ elements of `ARR` starting from the chosen index in the chosen direction and add each iterated element to `RES`.

The **value** of `RES` is defined as the sum of prefix XOR values:
$$\text{value}(RES) = \sum_{i=0}^{N-1} (RES[0] \oplus RES[1] \oplus \dots \oplus RES[i])$$

Find the **maximum possible value** of `RES` across all possible starting indices and directions.

---

## Examples

### Example 1
- **Input:** $N = 5, ARR = [1, 2, 4, 5, 8]$
- **Output:** $53$

---

## Constraints

- $1 \le N \le 10^5$
- $0 \le ARR[i] \le 10^9$

---

## Pattern: Independent Bit Contribution + Prefix XOR Sliding Window

Bitwise XOR operates independently on each bit position $b \in [0, 29]$:
1. For each bit position $b$, compute the bit sequence $B[i] \in \{0, 1\}$.
2. The prefix XOR sequence of bits oscillates between $0$ and $1$.
3. By evaluating both forward and backward cyclic orderings and tracking prefix XOR bit contributions, we achieve optimal evaluation in $O(N \log(\max A))$.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Bit-Level Sliding Contribution** | $O(N \times 30)$ | $O(N)$ |
