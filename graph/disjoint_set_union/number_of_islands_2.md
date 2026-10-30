### Problem 7: Dynamic Grid Connectivity (Number of Islands II)

**Problem Statement:**
You are given an empty 2D grid of size $N \times M$ where all cells are initially water (`0`).

You are also given a list of `positions` representing queries. Each query `positions[i] = [row, col]` magically turns that specific water cell into land (`1`).

An **island** is a group of connected land cells (horizontal or vertical).

**Your Task:**
Return an array of integers, where the $i$-th integer is the number of islands on the grid **exactly after** the $i$-th cell is turned into land.

**Sample Input:**

```text
N = 3, M = 3
Positions: [[0,0], [0,2], [0,1], [2,2]]

```

**Sample Output:**

```text
[1, 2, 1, 2]

```

*(Explanation:

1. Turn `(0,0)` to land. Grid has 1 island. Answer: `1`
2. Turn `(0,2)` to land. Grid has 2 separate islands. Answer: `2`
3. Turn `(0,1)` to land. This connects `(0,0)` and `(0,2)` into a single large island! Answer: `1`
4. Turn `(2,2)` to land. A new disconnected island appears. Answer: `2`)*

If you just ran a standard BFS/DFS to count the islands from scratch every single time a new piece of land was added, what would the time complexity be, and can you think of a data structure specifically designed to merge sets together instantly without rescanning the whole grid?