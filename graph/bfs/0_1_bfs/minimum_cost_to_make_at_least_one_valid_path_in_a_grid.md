### Problem 5: Minimum Cost to Make at Least One Valid Path in a Grid

**Problem Statement:**
You are given an $N \times M$ grid. Each cell in the grid contains a number from 1 to 4, representing a directional sign pointing to the next cell you should visit:

* `1` means point Right
* `2` means point Left
* `3` means point Down
* `4` means point Up

If you follow the sign in your current cell, it costs **0 steps/effort** to move to the next cell.
However, you can magically change the sign in your current cell to point in any other direction. Doing this costs **1 unit of effort/cost**.

**Your Task:**
Find the minimum cost to reach the bottom-right cell `(N-1, M-1)` starting from the top-left cell `(0, 0)`.

**Sample Input:**

```text
Grid:
1 1 1 1
2 2 2 3
1 1 1 1
2 2 2 3

```

**Sample Output:**

```text
3

```

*(Explanation: You start at (0,0). The first row is all 1s (Right), so you can slide all the way to the top-right corner (0, 3) for a cost of 0. But then you are stuck. You must pay a cost of 1 to change the sign at (0,3) to point Down. You slide down for free, then pay 1 to point Down again, etc. Total cost to reach the end is 3.)*