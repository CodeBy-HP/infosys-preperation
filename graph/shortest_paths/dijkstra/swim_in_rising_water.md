# Swim in Rising Water (LeetCode 778)

## Problem Overview
You are given an $N \times N$ integer matrix `grid` where each value `grid[i][j]` represents the elevation at that point $(i, j)$.
Rain starts falling at time $0$. At time $t$, the depth of water everywhere is $t$. You can swim from a square to any 4-directionally adjacent square if and only if the elevation of both squares is **at most $t$**.
You start at the top-left square `(0, 0)`.
Return the **least time until you can reach the bottom-right square `(N - 1, N - 1)`**.

---

## Modified Dijkstra (Minimax Path)
We wish to find a path from `(0, 0)` to `(N - 1, N - 1)` that **minimizes the maximum elevation encountered**:
1. Priority queue stores `{time, r, c}` ordered by smallest `time`.
2. Push `{grid[0][0], 0, 0}` to the min-heap.
3. Maintain a 2D `visited` array.
4. When popping cell $(r, c)$ with time $t$:
   - If $(r, c) == (N - 1, N - 1)$, return $t$.
   - For each 4-directional neighbor $(nr, nc)$ not yet visited:
     $$\text{nextTime} = \max(t, \; grid[nr][nc])$$
     Mark $(nr, nc)$ visited and push $\{\text{nextTime}, nr, nc\}$.
5. Because the min-heap always pops the cell reachable with the absolute smallest maximum water height, the first time `(N - 1, N - 1)` is popped, its time is **globally minimal**.

---

## Complexity Analysis
- **Time Complexity:** $O(N^2 \log(N^2)) = O(N^2 \log N)$
- **Space Complexity:** $O(N^2)$ for visited array and priority queue.

