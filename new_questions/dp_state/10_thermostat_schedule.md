# 10. Thermostat Schedule (Infosys OA State-Transition Scheduling)

## Problem Statement

A smart building HVAC thermostat operates over `n` consecutive hours. At each hour `i` ($0 \le i < n$), there is an ambient target temperature `target[i]`, and the thermostat can run in one of `m` discrete modes with temperature outputs `modes[0..m-1]` (or energy costs).

However:
1. Maintaining mode `j` at hour `i` incurs an operational discomfort/energy cost equal to $|target[i] - modes[j]|$ (or `cost[i][j]`).
2. Switching between modes from hour `i - 1` (`prevMode`) to hour `i` (`currMode`) incurs a **switching penalty** `switchCost * |prevMode - currMode|` (or forbidden rapid toggles).

Find the **minimum total cost** to schedule the thermostat across all `n` hours.

*(Reconstructed canonical formulation representing the Infosys Thermostat Schedule state-DP question.)*

---

## Examples

### Example 1
- **Input:** `target = [20, 25, 22]`, `modes = [18, 22, 26]`, `switchCost = 2`
- **Output:** `6`
- **Explanation:**
  - Hour 0: Pick mode 1 (`22`), discomfort = $|20 - 22| = 2$.
  - Hour 1: Pick mode 1 (`22`), discomfort = $|25 - 22| = 3$, switch = $0$. (Or switch to mode 2 (`26`): discomfort = $1$, switch = $2 \times |1 - 2| = 2 \implies$ total 3; then Hour 2 switch back to mode 1 (`22`): discomfort = $0$, switch = $2 \implies 2+3+2=7$ vs staying on mode 1: $2 + 3 + 0 = 5$!).
  - Staying on mode 1 (`22`) for all 3 hours gives $|20-22| + |25-22| + |22-22| = 2 + 3 + 0 = 5$.

---

## Constraints

- $1 \le n \le 10^4$
- $1 \le m \le 50$
- $0 \le \text{target}[i], \text{modes}[j] \le 10^4$

---

## Pattern Insight: State-Transition DP with Prefix/Suffix Slope Minimization

Basic DP transition:
$$dp[i][j] = \text{cost}(i, j) + \min_{0 \le p < m} \Big( dp[i-1][p] + switchCost \cdot |modes[j] - modes[p]| \Big)$$
Wait: Notice if `switchCost` is proportional to $|p - j|$ or $|modes[p] - modes[j]|$:
- Naive transition is $O(n \cdot m^2)$.
- By sorting `modes` and scanning left-to-right + right-to-left (similar to Min Falling Path Sum / Slope Trick), the inner minimum over all $p$ reduces to **$O(n \cdot m)$**!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Standard Rolling State DP** | $O(N \cdot M^2)$ | $O(M)$ |
| **Two-Pass Sweep Optimization** | $O(N \cdot M)$ | $O(M)$ |
