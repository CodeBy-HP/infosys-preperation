# Graph Question Sheet

### 1. The Exact Match (Multi-Source BFS / Two-Phase BFS)

* **[CSES Problem Set - Monsters](bfs/multi_source_bfs/monsters.md):** This problem is almost a 1:1 replica of the one you just solved in [Laboratory Fire Escape](bfs/multi_source_bfs/laboratory_fire_escape.md). You are placed in a labyrinth with multiple monsters. The monsters move one step per turn, and if a monster can reach a cell before or at the same time as you, you are caught. Your goal is to reach the boundary. It perfectly reinforces the two-phase BFS (or multi-source BFS) logic we discussed.

---

### 2. Multi-Source BFS Fundamentals (LeetCode)

* **[LeetCode 994 - Rotting Oranges](bfs/multi_source_bfs/rotting_oranges.md):** A classic. You are given a grid of fresh and rotten oranges. Every minute, rotten oranges spread to adjacent fresh ones. You need to find the minimum time until all oranges are rotten. This is the perfect practice for the "Fire" half of your problem.
* **[LeetCode 542 - 01 Matrix](bfs/multi_source_bfs/01_matrix.md):** Given a grid of 0s and 1s, find the distance from every 1 to the nearest 0. Instead of running a BFS from every single 1 (which would Time Limit Exceed), you put all the 0s into a queue at the start and spread outwards—exactly how you handle multiple fire sources.
* **[LeetCode 1162 - As Far from Land as Possible](bfs/multi_source_bfs/as_far_from_land_as_possible.md):** Similar to the 01 Matrix. You have land and water, and you must find a water cell that is maximally far from any land. All land cells go into the queue at minute 0.

---

### 3. The "Boss Level" Variation (LeetCode)

* **[LeetCode 2258 - Escape the Spreading Fire](bfs/multi_source_bfs/escape_the_spreading_fire.md):** This is the advanced, heavily constrained version of your problem. You are in a grid with fire spreading, but the exit is a specific safehouse, not just any boundary. The twist? You are allowed to *wait* in your starting cell for a few minutes before running. You have to find the maximum number of minutes you can wait and still successfully escape. It combines Multi-Source BFS with Binary Search.

---

### 4. Single Moving Entity / State-Space BFS (LeetCode)

* **[LeetCode 1293 - Shortest Path in a Grid with Obstacles Elimination](bfs/state_space_bfs/shortest_path_in_a_grid_with_obstacles_elimination.md):** While there is no fire here, this problem forces you to track a 3D visited state: `visited[x][y][obstacles_eliminated]`. If you want to practice what happens when "just marking the 2D cell as visited is not enough" (like we discussed with a moving guard), this is a phenomenal introduction to 3D BFS.
