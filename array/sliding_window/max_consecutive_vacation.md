# Problem 12: Maximum Consecutive Vacation Days

## Problem Statement

Andy wants to go on a vacation. He can take **only one continuous vacation** during the next $N$ days, where days are numbered from $1$ to $N$.

Andy has $M$ scheduled obligations. The $i^{\text{th}}$ obligation is on day $D[i]$. To extend his vacation, Andy is allowed to **cancel at most $K$ obligations**.

Determine the **maximum number of consecutive vacation days** Andy can take.

---

## Examples

### Example 1
- **Input:** $N = 10, M = 3, K = 1, D = [3, 5, 8]$
- **Output:** $5$
- **Explanation:** If Andy cancels obligation on day 5, he can take vacation from day 4 to day 8 (excluding 8, so days 4, 5, 6, 7 = 4 days; or days 1 to 4 with canceling day 3 = 4 days; or days 6 to 10 canceling day 8 = 5 days: days 6, 7, 8, 9, 10).

---

## Constraints

- $1 \le N \le 10^9$
- $0 \le M \le 2 \times 10^5$
- $0 \le K \le M$
- $1 \le D[i] \le N$

---

## Pattern: Sliding Window Over Sorted Obligations

Since $N \le 10^9$, we cannot simulate an array of size $N$. Instead, slide a window over the **obligations list**:
1. Sort obligations: $D[0 \dots M - 1]$.
2. Prepend boundary day $0$ and append boundary day $N + 1$:
   $$D = [0, D_1, D_2, \dots, D_M, N + 1]$$
3. A vacation spanning canceled obligations from index $i$ to $j$ ($j - i + 1 \le K$):
   - Leftmost uncancelled obligation is $D[i - 1]$.
   - Rightmost uncancelled obligation is $D[j + 1]$.
   - Continuous vacation days between them: $(D[j + 1] - 1) - (D[i - 1] + 1) + 1 = D[j + 1] - D[i - 1] - 1$.
4. Slide window of size at most $K$ across the obligations array in $O(M)$ time.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Obligation Window Scan** | $O(M \log M)$ | $O(M)$ |
