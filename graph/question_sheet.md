# Graph Question Sheet

> [!NOTE]
> The comprehensive master index containing all 46 Graph problems, patterns, invariants, and runnable C++ implementations is available in **[Graph Master Sheet (SHEET.md)](SHEET.md)**.

---

### 1. The Exact Match (Multi-Source BFS / Two-Phase BFS)

* **[CSES Problem Set - Monsters](bfs/multi_source_bfs/monsters.md):** This problem is almost a 1:1 replica of the one you solved in [Laboratory Fire Escape](bfs/multi_source_bfs/laboratory_fire_escape.md). You are placed in a labyrinth with multiple monsters. The monsters move one step per turn, and if a monster can reach a cell before or at the same time as you, you are caught. Your goal is to reach the boundary.
* **[Distance of Nearest Cell Having 1](bfs/multi_source_bfs/distance_of_nearest_cell_having_one.md)** ([C++ Code](bfs/multi_source_bfs/distance_of_nearest_cell_having_one.cpp)): Multi-source BFS initializing from all 1s simultaneously.

---

### 2. Multi-Source BFS Fundamentals (LeetCode)

* **[LeetCode 994 - Rotting Oranges](bfs/multi_source_bfs/rotting_oranges.md):** A classic. You are given a grid of fresh and rotten oranges. Every minute, rotten oranges spread to adjacent fresh ones. You need to find the minimum time until all oranges are rotten.
* **[LeetCode 542 - 01 Matrix](bfs/multi_source_bfs/01_matrix.md):** Given a grid of 0s and 1s, find the distance from every 1 to the nearest 0.
* **[LeetCode 1162 - As Far from Land as Possible](bfs/multi_source_bfs/as_far_from_land_as_possible.md):** All land cells go into the queue at minute 0.

---

### 3. The "Boss Level" Variation (LeetCode)

* **[LeetCode 2258 - Escape the Spreading Fire](bfs/multi_source_bfs/escape_the_spreading_fire.md):** Combines Multi-Source BFS with Binary Search on maximum wait time.

---

### 4. Single Moving Entity / State-Space BFS (LeetCode)

* **[LeetCode 1293 - Shortest Path in a Grid with Obstacles Elimination](bfs/state_space_bfs/shortest_path_in_a_grid_with_obstacles_elimination.md):** 3D visited state: `visited[x][y][obstacles_eliminated]`.
* **[LeetCode 127 - Word Ladder I](bfs/state_space_bfs/word_ladder_i.md):** Level-by-level word transformations.
* **[LeetCode 126 - Word Ladder II](bfs/state_space_bfs/word_ladder_ii.md):** Reconstructing all shortest transformation paths without MLE.

---

### 5. Shortest Paths in Weighted & Unweighted Graphs

* **[Shortest Path in Unweighted Graph](shortest_paths/unweighted_bfs/shortest_path_in_unweighted_graph.md):** Single-source BFS on unit weights in $O(V + E)$ time.
* **[Dijkstra's Algorithm](shortest_paths/dijkstra/dijkstras_algorithm.md):** Min-heap single source shortest path.
* **[Bellman-Ford Algorithm](shortest_paths/bellman_ford/shortest_path_with_negative_weights.md):** Negative edge handling and negative cycle detection.
* **[Floyd-Warshall Algorithm](shortest_paths/floyd_warshall/all_pairs_shortest_path.md):** All-Pairs Shortest Path (APSP) in $O(V^3)$.
