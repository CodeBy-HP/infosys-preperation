# Problem 7: Candy (LeetCode 135)

## Problem Statement

There are $n$ children standing in a line. Each child is assigned a rating value given in the integer array `ratings`.

You are giving candies to these children subjected to the following requirements:
1. Each child must have **at least one candy**.
2. Children with a **strictly higher rating** get more candies than their immediate neighbors.

Return the **minimum number of candies** you need to have to distribute the candies to the children.

---

## Examples

### Example 1
- **Input:** `ratings = [1, 0, 2]`
- **Output:** `5`
- **Explanation:** You can allocate candies as `[2, 1, 2]`.
  - Child 0 has rating 1 > rating 0 (Child 1) $\implies$ gets 2 candies.
  - Child 1 has rating 0 (valley) $\implies$ gets 1 candy.
  - Child 2 has rating 2 > rating 0 (Child 1) $\implies$ gets 2 candies.
  - Total = $2 + 1 + 2 = 5$.

### Example 2
- **Input:** `ratings = [1, 2, 2]`
- **Output:** `4`
- **Explanation:** You can allocate candies as `[1, 2, 1]`.
  - Child 2 gets 1 candy because equal rating neighbors do not require strictly more candies.
  - Total = $1 + 2 + 1 = 4$.

---

## Constraints

- $n == \text{ratings.length}$
- $1 \le n \le 5 \times 10^4$
- $0 \le \text{ratings}[i] \le 5 \times 10^4$

---

## Algorithmic Paradigms

### 1. The Two-Pass Greedy Strategy ($O(N)$ Time, $O(N)$ Space)
Decompose the two-neighbor constraint into two independent single-direction passes:
1. **Initialize:** Give each child $1$ candy (`vector<int> candies(n, 1)`).
2. **Left-to-Right Pass:** Check the left neighbor.
   - If `ratings[i] > ratings[i - 1]`, set `candies[i] = candies[i - 1] + 1`.
   - This guarantees that every child with a higher rating than their left neighbor receives more candies.
3. **Right-to-Left Pass:** Check the right neighbor while preserving the left pass.
   - If `ratings[i] > ratings[i + 1]`, update `candies[i] = max(candies[i], candies[i + 1] + 1)`.
   - Taking the `max` ensures that satisfying the right neighbor does not violate the left neighbor condition!
4. **Result:** Sum all elements in `candies`.

### 2. Peak & Valley Slope Greedy ($O(N)$ Time, $O(1)$ Space)
- Interpret the ratings as mountain slopes: up-slopes, down-slopes, and flat plains.
- Track lengths of `up` and `down` runs.
- Accumulate candies directly as arithmetic progressions:
  - Climbing up: $1, 2, 3, \dots$
  - Sliding down: $1, 2, 3, \dots$
  - Adjust the peak to $\max(\text{up}, \text{down}) + 1$.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Two-Pass Greedy** | $O(N)$ | $O(N)$ | Highly intuitive and standard |
| **One-Pass Peak/Valley Slope** | $O(N)$ | $O(1)$ | Optimal space complexity |

