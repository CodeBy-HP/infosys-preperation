# Defeat the Maximum Number of Monsters (Greedy RPG Combat)

## Problem Statement

You are playing an RPG video game where your character starts with an initial Health Point ($\text{HP}$) value. You are facing $N$ monsters and can choose to fight them in **any order**.

Each monster $i$ ($0 \le i < N$) has two attributes:
1. **Power Point ($P_i$):** The minimum health required to engage and defeat the monster.
2. **Bonus Point ($B_i$):** The permanent health increase granted to your character upon defeating the monster.

### Combat Mechanics:
- To defeat monster $i$, your current $\text{HP}$ must be greater than or equal to the monster's Power Point:
  $$\text{current\_HP} \ge P_i$$
- Upon victory, your $\text{HP}$ increases by the monster's bonus point:
  $$\text{current\_HP} \leftarrow \text{current\_HP} + B_i$$
- If your current $\text{HP}$ is strictly less than $P_i$, you cannot defeat this monster.

### Objective:
Find the optimal sequence to fight the monsters to **maximize the total number of monsters defeated**, and return that maximum count.

---

## Examples

### Example 1
- **Input:**
  - $\text{initial\_HP} = 10$
  - $\text{monsters} = [(P: 12, B: 5), (P: 10, B: 2), (P: 15, B: 10)]$
- **Output:** `3`
- **Explanation:**
  - Fight monster 1 ($P = 10, B = 2$): $10 \ge 10 \implies \text{HP} = 10 + 2 = 12$. Defeated = 1.
  - Fight monster 0 ($P = 12, B = 5$): $12 \ge 12 \implies \text{HP} = 12 + 5 = 17$. Defeated = 2.
  - Fight monster 2 ($P = 15, B = 10$): $17 \ge 15 \implies \text{HP} = 17 + 10 = 27$. Defeated = 3.
  - Total monsters defeated = 3.

### Example 2
- **Input:**
  - $\text{initial\_HP} = 5$
  - $\text{monsters} = [(P: 10, B: 100), (P: 20, B: 50)]$
- **Output:** `0`
- **Explanation:** Initial HP of 5 cannot defeat any monster.

---

## Constraints

- $1 \le N \le 10^5$
- $1 \le \text{initial\_HP} \le 10^9$
- $1 \le P_i, B_i \le 10^9$

---

## Algorithmic Paradigm: Greedy by Ascending Power Requirement

### Why Greedy is Globally Optimal
1. **Monotonic Health Growth:** Because every bonus point $B_i \ge 0$, defeating any monster only increases your HP or keeps it unchanged ($\text{HP}' \ge \text{HP}$).
2. **Weakest Monster Priority:** If you cannot defeat the monster with the lowest Power Point requirement, you mathematically cannot defeat any other monster with a higher Power Point requirement.
3. Therefore, sorting monsters in ascending order of Power Point:
   $$P_1 \le P_2 \le \dots \le P_N$$
   guarantees that you harvest bonus points as early as possible, maximizing your qualification for all subsequent monsters.
4. The first monster $i$ where $\text{current\_HP} < P_i$ terminates the process, as all remaining monsters $j > i$ satisfy $P_j \ge P_i > \text{current\_HP}$.

---

## Complexity Analysis

| Step | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Sorting Monsters** | $O(N \log N)$ | $O(1)$ auxiliary |
| **Linear Simulation** | $O(N)$ | $O(1)$ |
| **Total** | $\mathcal{O}(N \log N)$ | $\mathcal{O}(1)$ |

