# The Data Doubler Algorithm (Array Concatenation / LeetCode 1929)

## Problem Statement

You are building a "loop mode" feature for a music streaming company. Given an integer array representing a playlist of song IDs and its size $n$, the system needs to generate a new queue that plays the exact same playlist twice back-to-back.

Return an array of size $2n$ where the original elements are repeated sequentially:
$$\text{ans}[i] = \text{nums}[i] \quad \text{and} \quad \text{ans}[i + n] = \text{nums}[i] \quad \text{for } 0 \le i < n$$

---

## Examples

### Example 1
- **Input:** `nums = [1, 2, 1]`
- **Output:** `[1, 2, 1, 1, 2, 1]`
- **Explanation:** The array is concatenated with itself.

### Example 2
- **Input:** `nums = [1, 3, 2, 1]`
- **Output:** `[1, 3, 2, 1, 1, 3, 2, 1]`

---

## Constraints

- $n == \text{nums.length}$
- $1 \le n \le 1000$
- $1 \le \text{nums}[i] \le 1000$

---

## Modulo Traversal Technique

Rather than running two separate sequential copy loops, you can initialize a result vector of size $2n$ and populate it in a single loop from $0$ to $2n - 1$:
$$\text{result}[i] = \text{original}[i \pmod n]$$

This creates a clean, circular indexed traversal pattern widely used in circular queues and streaming buffer pipelines.

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $\mathcal{O}(N)$ single pass of length $2N$ |
| **Space Complexity** | $\mathcal{O}(N)$ to store the duplicated output array |

