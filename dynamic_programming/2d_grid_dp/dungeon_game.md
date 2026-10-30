# Problem 5: Dungeon Game (LeetCode 174)

## Problem Statement

The demons had captured the princess and imprisoned her in the bottom-right corner of a `dungeon`. The `dungeon` consists of $m \times n$ rooms laid out in a 2D grid. Our valiant knight was initially positioned in the top-left room $(0, 0)$ and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. **If at any point his health points drop to $0$ or below, he dies immediately.**

Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; other rooms are either empty (represented as $0$) or contain magic orbs that increase the knight's health (represented by positive integers).

To reach the princess as quickly as possible, the knight decides to move only **rightward** or **downward** in each step.

Return the **knight's minimum initial health** so that he can rescue the princess.

---

## Examples

### Example 1
```text
dungeon = [
  [-2, -3,  3],
  [-5, -10, 1],
  [10,  30, -5]
]
```
- **Output:** `7`
- **Explanation:** The initial health of the knight must be at least `7` if he follows the optimal path:
  `Right -> Right -> Down -> Down`.
  - $(0,0) \rightarrow$ enters with 7 HP, loses 2 HP $\rightarrow 5$ HP
  - $(0,1) \rightarrow$ enters with 5 HP, loses 3 HP $\rightarrow 2$ HP
  - $(0,2) \rightarrow$ enters with 2 HP, gains 3 HP $\rightarrow 5$ HP
  - $(1,2) \rightarrow$ enters with 5 HP, gains 1 HP $\rightarrow 6$ HP
  - $(2,2) \rightarrow$ enters with 6 HP, loses 5 HP $\rightarrow 1$ HP (survives!)

---

## Constraints

- $m == \text{dungeon.length}$
- $n == \text{dungeon}[i]\text{.length}$
- $1 \le m, n \le 200$
- $-1000 \le \text{dungeon}[i][j] \le 1000$

---

## The Paradigm Shift: Think Backwards

If you try to solve this from $(0, 0)$ forward to the princess, local greedy choices fail: picking a high health path now may trap you into an unavoidable massive boss later, and carrying "current health" as a DP state blows up the time complexity.

### The Backwards Formulation:
Start at the Princess's room $(m - 1, n - 1)$ and work backwards to the Knight at $(0, 0)$.

1. **State:**
   - $\text{dp}[r][c]$ represents the **minimum health the knight must possess immediately before entering room $(r, c)$** to safely reach and rescue the princess.
2. **Choice & Transitions:**
   - Future requirement: $\text{min\_future\_health} = \min(\text{dp}[r + 1][c],\, \text{dp}[r][c + 1])$.
   - Current room requirement: $\text{needed} = \text{min\_future\_health} - \text{dungeon}[r][c]$.
   - **The Survival Rule:** The knight must always be alive upon entering (at least 1 HP). If a room provides a massive heal such that $\text{needed} \le 0$, the knight still needs at least 1 HP to enter:
   $$\text{dp}[r][c] = \max(1,\, \min(\text{dp}[r + 1][c],\, \text{dp}[r][c + 1]) - \text{dungeon}[r][c])$$
3. **Base Case:**
   - Princess room: $\text{dp}[m - 1][n - 1] = \max(1,\, 1 - \text{dungeon}[m - 1][n - 1])$.

---

## Alternative Paradigm: Binary Search on Answer

- Range of initial health: $[1, \sum |\text{negative values}| + 1]$.
- For a guessed health `H`, run Forward DP or BFS to see if health remains $> 0$ all the way to the destination.
- Time Complexity: $O(M \times N \times \log(\text{Max HP}))$.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Backwards Top-Down (Memoization)** | $O(M \times N)$ | $O(M \times N)$ |
| **Backwards Bottom-Up (Tabulation)** | $O(M \times N)$ | $O(M \times N)$ |
| **Space-Optimized Iterative** | $O(M \times N)$ | $O(N)$ |
| **Binary Search on Answer** | $O(M \times N \log(\text{Range}))$ | $O(M \times N)$ |

