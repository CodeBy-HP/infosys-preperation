# 19. Minimum Energy Transfer (Infosys SP OA Exact PYQ)

## Problem Statement

You need to transfer at least `N` units of energy using `K` available transmission channels.
For each channel `i` ($0 \le i < K$):
- `cnt[i]`: Maximum number of times channel `i` can be used.
- `d[i]`: Energy transferred per single use of channel `i`, **and** the one-time **activation cost** incurred if channel `i` is used at least once.
- **Per-Transfer Overhead:** Every single transfer action (each use of a channel) incurs an additional fixed cost of `1` unit of energy.

Thus, if channel `i` is used `c` times ($1 \le c \le cnt[i]$):
- Energy transferred = $c \times d[i]$
- Total cost incurred on channel `i` = $d[i] + c$

Find the **minimum total cost** required to transfer **at least `N`** units of energy (or exact `N` units depending on overflow allowance). If impossible, return `-1`.

---

## Examples

### Example 1
- **Input:** `N = 6`, `d = [2, 5]`, `cnt = [3, 1]`
- **Output:** `5`
- **Explanation:**
  - Option A: Use channel 0 three times ($3 \times 2 = 6$ energy). Cost = activation $2$ + $3$ uses = $2 + 3 = 5$.
  - Option B: Use channel 1 once ($5$ energy) + channel 0 once ($2$ energy) $\implies 7 \ge 6$ energy. Cost = $(5 + 1) + (2 + 1) = 9$.
  - Minimum cost = `5`.

### Example 2
- **Input:** `N = 10`, `d = [3]`, `cnt = [2]`
- **Output:** `-1`
- **Explanation:** Maximum energy transferable is $2 \times 3 = 6 < 10$.

---

## Constraints

- $1 \le N \le 10^4$
- $1 \le K \le 100$
- $1 \le d[i], cnt[i] \le 10^4$

---

## Pattern Insight: Bounded Knapsack with Activation Fee

Notice that if we maintain `dp[e]` = minimum cost to transfer `e` units of energy (capping `e` at `N`, meaning `dp[N]` tracks $\ge N$ energy):
For each channel `i`:
When deciding how many uses $c \in [1, cnt[i]]$ to take from channel `i`:
Because using channel `i` at least once pays an activation fee `d[i]` once, we can use a rolling auxiliary array `withAct[e]` representing states where channel `i` is already active:
1. Initialize `withAct[e] = dp[e] + d[i]` (paying the activation fee right before taking transfers).
2. Loop `step` or `use` forward (bounded by `cnt[i]`), OR simply use **monotonic queue / bounded copy** over remainders `e % d[i]`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Bounded Knapsack (Per-Use Sweep / Early Cap)** | $O(K \cdot N \cdot \min(cnt, \lceil N/d \rceil))$ | $O(N)$ |
| **Monotonic Queue Bounded Knapsack** | $O(K \cdot N)$ | $O(N)$ |
