# Painter's Partition Problem

## Problem Statement

Given an array `boards` of $N$ integers representing the lengths of $N$ wooden boards, and an integer $K$ representing the number of painters available.

Each painter takes $1$ unit of time to paint $1$ unit length of board. Any painter will only paint **contiguous** sections of boards. No board can be painted partly by one painter and partly by another.

Find the **minimum time** required to complete painting all boards.

---

## Examples

### Example 1
- **Input:** `boards = [10, 20, 30, 40]`, `K = 2`
- **Output:** `60`
- **Explanation:**
  - Painter 1 paints boards `[10, 20, 30]` (total length = 60).
  - Painter 2 paints board `[40]` (total length = 40).
  - Max time taken = $\max(60, 40) = 60$.

### Example 2
- **Input:** `boards = [5, 5, 5, 5]`, `K = 2`
- **Output:** `10`
- **Explanation:** Each painter paints 2 boards of length 5 each (total length = 10).

---

## Constraints

- $1 \le N \le 10^5$
- $1 \le K \le 10^5$
- $1 \le \text{boards}[i] \le 10^9$

---

## Minimax Invariant & Binary Search on Answer

The problem asks to **minimize the maximum** workload assigned to any painter.
This is identical in structure to the **Book Allocation Problem** and **Split Array Largest Sum**.

### Search Space Bounds
- **Minimum possible workload:** $\max(\text{boards})$ (a single painter must paint at least the largest individual board).
- **Maximum possible workload:** $\sum \text{boards}$ (all boards assigned to 1 painter).

### Greedy Verification
Given a target maximum time $mid$:
1. Sequentially assign boards to the current painter until adding the next board would exceed $mid$.
2. Once exceeded, allocate a new painter.
3. If total painters needed $\le K$: $mid$ is feasible! Try a smaller max time: `right = mid - 1`.
4. If total painters needed $> K$: $mid$ is too small; allow more time: `left = mid + 1`.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Binary Search on Answer** | $O(N \log(\sum \text{boards}))$ | $O(1)$ |
| **Dynamic Programming** | $O(K \times N^2)$ | $O(K \times N)$ |

