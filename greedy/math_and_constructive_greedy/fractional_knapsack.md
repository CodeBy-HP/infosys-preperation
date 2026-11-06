# Fractional Knapsack Problem

## Problem Overview
Given weights and values of $N$ items, we need to put these items in a knapsack of capacity $W$ to get the **maximum total value** in the knapsack.
Unlike the 0/1 Knapsack problem, in **Fractional Knapsack**, we are allowed to break items (i.e. take a fraction $\frac{w_{taken}}{w_i}$ of an item to earn proportional value $\frac{w_{taken}}{w_i} \times v_i$).

---

## Value Density Sorting Invariant
To maximize total value per unit weight consumed, we should greedily prioritize items with the **highest value density**:
$$\text{Density}_i = \frac{\text{value}_i}{\text{weight}_i}$$

### Algorithmic Steps:
1. Sort all items in **descending order of their value-to-weight ratio**:
   $$\frac{v_1}{w_1} \ge \frac{v_2}{w_2} \ge \dots \ge \frac{v_N}{w_N}$$
2. Initialize `totalValue = 0.0` and `currWeight = 0`.
3. For each item $i$:
   - If adding the entire item does not exceed capacity ($currWeight + w_i \le W$):
     $$\text{currWeight} += w_i, \quad \text{totalValue} += v_i$$
   - Else (knapsack cannot hold the full item):
     Take a fraction of item $i$ filling the remaining capacity:
     $$\text{remaining} = W - \text{currWeight}$$
     $$\text{totalValue} += v_i \times \frac{\text{remaining}}{w_i}$$
     $$\text{break}$$

---

## Complexity Analysis
- **Time Complexity:** $O(N \log N)$ to sort items by density.
- **Space Complexity:** $O(1)$ auxiliary space.

