# Auction Revenue Calculation (Greedy State-Tracking Simulation)

## Problem Statement

An auction features $N$ items auctioned sequentially in a strict order from $0$ to $N - 1$, with $M$ bidders participating.
- Each bidder $j$ ($0 \le j < M$) has a strict maximum budget $B_j$.
- Each bidder submits a bid for every single item, represented as a 2D matrix $\text{Bid}[M][N]$, where $\text{Bid}[j][i]$ is bidder $j$'s bid on item $i$.

### Rules & Constraints
1. **Validity:** A bid $\text{Bid}[j][i]$ is valid if and only if the bid amount does not exceed the bidder's budget:
   $$\text{Bid}[j][i] \le B_j$$
2. **Item Award:** Each item is awarded to the **highest valid bidder**. Ties are broken by the **lower bidder index** (i.e., bidder with smaller $j$ wins).
3. **Single Win Constraint:** Each bidder can win **at most one** item. Once a bidder wins an item, their budget is immediately exhausted, and they are removed from all subsequent item auctions.
4. **No Valid Bid:** If no available bidder submits a valid bid for an item, the item remains unsold and contributes $0$ to the revenue.

### Objective
Calculate the **total auction revenue** (the sum of all winning bids across the $N$ items).

---

## Examples

### Example 1
- **Input:**
  - `budgets = [100, 200, 150]` ($M = 3$ bidders)
  - `bids = [`
    - `[80, 90],`   (Bidder 0)
    - `[120, 150],` (Bidder 1)
    - `[70, 160]`   (Bidder 2)
  - `]` ($N = 2$ items)
- **Execution Trace:**
  - **Item 0:**
    - Bidder 0: bid 80 $\le 100$ (valid)
    - Bidder 1: bid 120 $\le 200$ (valid)
    - Bidder 2: bid 70 $\le 150$ (valid)
    - Highest valid bid: Bidder 1 with bid 120.
    - Bidder 1 wins Item 0 and is removed. Revenue = 120.
  - **Item 1:**
    - Bidder 0: bid 90 $\le 100$ (valid)
    - Bidder 1: already won, excluded.
    - Bidder 2: bid 160 $> 150$ (invalid, exceeds budget).
    - Highest valid bid: Bidder 0 with bid 90.
    - Bidder 0 wins Item 1. Revenue = $120 + 90 = 210$.
- **Output:** `210`

### Example 2
- **Input:**
  - `budgets = [50]`
  - `bids = [[60, 70]]`
- **Output:** `0` (all bids exceed budget)

---

## Constraints

- $1 \le N \le 1000$ (number of items)
- $1 \le M \le 1000$ (number of bidders)
- $1 \le B_j \le 10^9$
- $0 \le \text{Bid}[j][i] \le 10^9$

---

## Algorithmic Paradigm: Sequential State Tracking

Since items are auctioned sequentially in a strict predetermined order from $0$ to $N - 1$:
1. Maintain a boolean array `used[M]` initialized to `false`.
2. For each item $i \in [0, N - 1]$:
   - Initialize `best_bid = -1`, `winner = -1`.
   - Iterate over all bidders $j \in [0, M - 1]$:
     - If `!used[j]` and $\text{Bid}[j][i] \le B_j$:
       - If $\text{Bid}[j][i] > \text{best\_bid}$:
         - `best_bid = Bid[j][i]`
         - `winner = j`
   - If `winner != -1`:
     - `total_revenue += best_bid`
     - `used[winner] = true`
3. Return `total_revenue`.

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $\mathcal{O}(N \times M)$ |
| **Space Complexity** | $\mathcal{O}(M)$ for tracking used bidders |

