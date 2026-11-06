# Graph Algorithms Master Roadmap & Problem Sheet

We systematically dismantle Graph Theory by **Traversal Paradigms, Cycle Topologies, Shortest Path Mechanics, and Connectivity/Partitioning Structures**.

This sheet organizes **46 high-frequency problems & techniques** across **7 core graph patterns** tested in top-tier coding assessments.

---

## 1. Graph Fundamentals & Connected Components
*Focus: Representations, BFS level-order expansions, DFS deep traversals, and component counting.*

* **[Introduction to Graphs](fundamentals/introduction_to_graph.md)** ([C++ Code](fundamentals/introduction_to_graph.cpp)): Adjacency matrix ($O(V^2)$) vs. Adjacency list ($O(V + E)$) trade-offs, storage paradigms, and density metrics.
* **[Graph Traversal Techniques](fundamentals/traversal_techniques.md)** ([C++ Code](fundamentals/traversal_techniques.cpp)): Canonical implementations of Breadth-First Search (BFS) and Depth-First Search (DFS) in $O(V + E)$ time.
* **[Connected Components](fundamentals/connected_components.md)** ([C++ Code](fundamentals/connected_components.cpp)): Outer traversal loop isolating all disjoint components in disconnected undirected graphs.
* **[Number of Provinces](bfs/grid_traversal/number_of_provinces.md)** ([C++ Code](bfs/grid_traversal/number_of_provinces.cpp)): Transitive friendship clustering modeled as component counting on $N \times N$ adjacency matrix in $O(N^2)$ time.

---

## 2. 2D Grid Traversals & Multi-Source BFS
*Focus: 4-directional spatial grids, boundary sinking, component shapes, and parallel wavefront expansions.*

* **[Number of Islands](bfs/grid_traversal/number_of_islands.md)** ([C++ Code](bfs/grid_traversal/number_of_islands.cpp)): In-place sinking BFS/DFS identifying 4-directionally connected land components in $O(M \times N)$ time.
* **[Flood Fill Algorithm](bfs/grid_traversal/flood_fill.md)** ([C++ Code](bfs/grid_traversal/flood_fill.cpp)): Guarding against infinite recursion when starting color equals target color in $O(M \times N)$ time.
* **[Number of Enclaves](bfs/grid_traversal/number_of_enclaves.md)** ([C++ Code](bfs/grid_traversal/number_of_enclaves.cpp)): Boundary-first inversion strategy sinking outer-connected land before counting enclosed enclaves.
* **[Rotting Oranges](bfs/multi_source_bfs/rotting_oranges.md)** ([C++ Code](bfs/multi_source_bfs/rotting_oranges.cpp)): Canonical multi-source BFS tracking minute-by-minute contagion spread until all oranges rot.
* **[Distance of Nearest Cell Having 1](bfs/multi_source_bfs/distance_of_nearest_cell_having_one.md)** ([C++ Code](bfs/multi_source_bfs/distance_of_nearest_cell_having_one.cpp)): Multi-source BFS initializing from all 1s simultaneously to compute shortest Manhattan distances in $O(M \times N)$ time.
* **[01 Matrix](bfs/multi_source_bfs/01_matrix.md)**: The dual of nearest 1: multi-source BFS starting from all 0s in the matrix.
* **[Surrounded Regions](bfs/grid_traversal/surrounded_regions.md)** ([C++ Code](bfs/grid_traversal/surrounded_regions.cpp)): Boundary `'O'` protection pass via temporary `'#'` conversion, flipping remaining isolated `'O'`s to `'X'`.
* **[Number of Distinct Islands](bfs/grid_traversal/number_of_distinct_islands.md)** ([C++ Code](bfs/grid_traversal/number_of_distinct_islands.cpp)): Invariant relative offset vectors $(r - r_0, c - c_0)$ serialized into a hash set to distinguish island shapes under translation.
* **[Monsters (CSES)](bfs/multi_source_bfs/monsters.md)**: Two-phase multi-source BFS simulating monster arrival times before computing human escape route.
* **[Escape the Spreading Fire](bfs/multi_source_bfs/escape_the_spreading_fire.md)**: Combining multi-source BFS with binary search on wait time to escape spreading fire.

---

## 3. Cycle Detection, Bipartition & Topological Sort
*Focus: Parent tracking, directed back-edges, 2-coloring, and prerequisite DAG linearizations.*

* **[Detect Cycle in an Undirected Graph](cycles/detect_cycle_undirected_graph.md)** ([C++ Code](cycles/detect_cycle_undirected_graph.cpp)): Checking if a visited neighbor is not the immediate parent in $O(V + E)$ time.
* **[Is Graph Bipartite?](bipartite_graph/is_graph_bipartite.md)** ([C++ Code](bipartite_graph/is_graph_bipartite.cpp)): 2-coloring BFS/DFS verifying that no odd-length cycle exists in the graph.
* **[Topological Sort (Kahn's Algorithm & DFS)](topological_sort/topological_sort_kahns_algorithm.md)** ([C++ Code](topological_sort/topological_sort_kahns_algorithm.cpp)): In-degree zero FIFO queue vs. DFS post-order stack reversal on DAGs in $O(V + E)$ time.
* **[Detect Cycle in a Directed Graph](cycles/detect_cycle_directed_graph.md)** ([C++ Code](cycles/detect_cycle_directed_graph.cpp)): Active recursion path-visited array (back-edge check) and Kahn's algorithm count verification ($\text{count} < V$).
* **[Course Schedule I](topological_sort/course_schedule.md)** ([C++ Code](topological_sort/course_schedule.cpp)): Cycle detection on course prerequisite DAG.
* **[Course Schedule II](topological_sort/course_schedule_ii.md)** ([C++ Code](topological_sort/course_schedule_ii.cpp)): Reconstructing a valid linear prerequisite sequence or returning `{}` on cycle.
* **[Find Eventual Safe States](topological_sort/find_eventual_safe_states.md)** ([C++ Code](topological_sort/find_eventual_safe_states.cpp)): Graph edge reversal combined with Kahn's algorithm / 3-state cycle DFS isolating safe terminal paths.
* **[Alien Dictionary](topological_sort/alien_dictionary.md)** ([C++ Code](topological_sort/alien_dictionary.cpp)): Deriving character DAG from adjacent word differences and resolving alphabet order via topological sort.

---

## 4. State-Space BFS & Shortest Paths in Unweighted Graphs
*Focus: Augmented visited states, transformation ladders, and unit-weight queue guarantees.*

* **[Shortest Path in Unweighted Graph](shortest_paths/unweighted_bfs/shortest_path_in_unweighted_graph.md)** ([C++ Code](shortest_paths/unweighted_bfs/shortest_path_in_unweighted_graph.cpp)): Single-source BFS guaranteeing shortest distance in $O(V + E)$ time.
* **[Word Ladder I](bfs/state_space_bfs/word_ladder_i.md)** ([C++ Code](bfs/state_space_bfs/word_ladder_i.cpp)): State-space BFS replacing each character across $26 \times L$ transitions in $O(N \cdot L^2)$ time.
* **[Word Ladder II](bfs/state_space_bfs/word_ladder_ii.md)** ([C++ Code](bfs/state_space_bfs/word_ladder_ii.cpp)): 2-phase architecture (forward BFS distance mapping + backward DFS backtracking) preventing MLE while collecting all shortest transformation paths.
* **[Shortest Path in Grid with Obstacles Elimination](bfs/state_space_bfs/shortest_path_in_a_grid_with_obstacles_elimination.md)** ([C++ Code](bfs/state_space_bfs/shortest_path_in_a_grid_with_obstacles_elimination.cpp)): 3D visited state space tracking remaining obstacle-clearing budget.

---

## 5. Shortest Path Algorithms (Weighted Graphs)
*Focus: Topological relaxations, min-heaps, negative edge detection, and all-pairs matrix dynamic programming.*

* **[Shortest Path in DAG](shortest_paths/dag/shortest_path_in_dag.md)** ([C++ Code](shortest_paths/dag/shortest_path_in_dag.cpp)): Linear $O(V + E)$ relaxation in topological order naturally handling negative weights.
* **[Dijkstra's Algorithm](shortest_paths/dijkstra/dijkstras_algorithm.md)** ([C++ Code](shortest_paths/dijkstra/dijkstras_algorithm.cpp)): Min-heap greedy relaxation for non-negative graphs in $O(E \log V)$ time.
* **[Print Shortest Path](shortest_paths/dijkstra/print_shortest_path.md)** ([C++ Code](shortest_paths/dijkstra/print_shortest_path.cpp)): Dijkstra with parent pointer tracking reconstructing exact path sequence from $1$ to $N$.
* **[Shortest Distance in a Binary Maze](shortest_paths/dijkstra/shortest_distance_in_binary_maze.md)** ([C++ Code](shortest_paths/dijkstra/shortest_distance_in_binary_maze.cpp)): Grid BFS on unit weights in $O(M \times N)$ time.
* **[Path with Minimum Effort](shortest_paths/dijkstra/path_with_min_effort.md)** ([C++ Code](shortest_paths/dijkstra/path_with_min_effort.cpp)): Minimax path optimization using modified Dijkstra on height difference deltas.
* **[Cheapest Flights Within K Stops](shortest_paths/dijkstra/cheapest_flights_within_k_stops.md)** ([C++ Code](shortest_paths/dijkstra/cheapest_flights_within_k_stops.cpp)): Stop-monotonic BFS / Bellman-Ford preventing premature pruning of cheaper multi-stop paths.
* **[Minimum Multiplications to Reach End](shortest_paths/dijkstra/minimum_multiplications_to_reach_end.md)** ([C++ Code](shortest_paths/dijkstra/minimum_multiplications_to_reach_end.cpp)): BFS over $10^5$ modulo integer states in $O(10^5 \times N)$ time.
* **[Number of Ways to Arrive at Destination](shortest_paths/dijkstra/number_of_ways_to_arrive_at_destination.md)** ([C++ Code](shortest_paths/dijkstra/number_of_ways_to_arrive_at_destination.cpp)): Dual-state Dijkstra maintaining distance and path combinatorics modulo $10^9 + 7$.
* **[Bellman-Ford Algorithm](shortest_paths/bellman_ford/shortest_path_with_negative_weights.md)** ([C++ Code](shortest_paths/bellman_ford/shortest_path_with_negative_weights.cpp)): Relaxing all edges $V - 1$ times to handle negative weights and detect negative weight cycles in $O(V \times E)$ time.
* **[Floyd-Warshall Algorithm](shortest_paths/floyd_warshall/all_pairs_shortest_path.md)** ([C++ Code](shortest_paths/floyd_warshall/all_pairs_shortest_path.cpp)): All-Pairs Shortest Path (APSP) dynamic programming via intermediate pivot vertices in $O(V^3)$ time.
* **[Find City with Smallest Number of Neighbors](shortest_paths/floyd_warshall/find_city_smallest_number_neighbors.md)** ([C++ Code](shortest_paths/floyd_warshall/find_city_smallest_number_neighbors.cpp)): Applying Floyd-Warshall to evaluate reachable neighbor thresholds across all cities in $O(N^3)$ time.
* **[Network Delay Time](shortest_paths/dijkstra/network_delay_time.md)** ([C++ Code](shortest_paths/dijkstra/network_delay_time.cpp)): Single-source Dijkstra computing max shortest-path arrival time across all nodes.
* **[Swim in Rising Water](shortest_paths/dijkstra/swim_in_rising_water.md)** ([C++ Code](shortest_paths/dijkstra/swim_in_rising_water.cpp)): Minimax priority queue navigation minimizing maximum water elevation encountered in $O(N^2 \log N)$ time.

---

## 6. Minimum Spanning Tree (MST) & Disjoint Set Union (DSU)
*Focus: Cut property, cycle property, path compression, union by rank/size, and coordinate unioning.*

* **[MST Theory](minimum_spanning_tree/mst_theory.md)**: Cut property, cycle property, and Kruskal's ($O(E \log E)$) vs. Prim's ($O(E \log V)$) comparative analysis.
* **[Disjoint Set Union (DSU)](disjoint_set_union/disjoint_set.md)** ([C++ Code](disjoint_set_union/disjoint_set.cpp)): Full implementation of Path Compression and Union by Rank/Size achieving amortized $O(\alpha(N))$ time per operation.
* **[Find the MST Weight](minimum_spanning_tree/find_mst_weight.md)** ([C++ Code](minimum_spanning_tree/find_mst_weight.cpp)): General graph implementations of both Kruskal's algorithm and Prim's algorithm.
* **[Number of Operations to Make Network Connected](disjoint_set_union/number_of_operations_to_make_network_connected.md)** ([C++ Code](disjoint_set_union/number_of_operations_to_make_network_connected.cpp)): Component counting via DSU verifying edge sufficiency ($E \ge N - 1$).
* **[Accounts Merge](disjoint_set_union/accounts_merge.md)** ([C++ Code](disjoint_set_union/accounts_merge.cpp)): Email-to-Account ID mapping and DSU grouping merging users with common emails.
* **[Number of Islands II](disjoint_set_union/number_of_islands_2.md)** ([C++ Code](disjoint_set_union/number_of_islands_2.cpp)): Dynamic land addition queries processing online island counts via 2D-to-1D DSU in $O(K \cdot \alpha(N \times M))$ time.
* **[Making a Large Island](disjoint_set_union/making_a_large_island.md)** ([C++ Code](disjoint_set_union/making_a_large_island.cpp)): DSU component sizing + evaluating unique root set sums around every flippable `'0'`.
* **[Most Stones Removed with Same Row or Column](disjoint_set_union/most_stones_removed_same_row_column.md)** ([C++ Code](disjoint_set_union/most_stones_removed_same_row_column.cpp)): Bipartite row-column coordinate unioning proving $\text{Removals} = N - C$.

---

## 7. Strongly Connected Components, Bridges & Articulation Points
*Focus: Tarjan's discovery and low-link values, back-edges, and Kosaraju's two-pass condensation.*

* **[Kosaraju's Algorithm (SCC)](strongly_connected_components/strongly_connected_components.md)** ([C++ Code](strongly_connected_components/strongly_connected_components.cpp)): Two-pass DFS with reversed graph isolating Strongly Connected Components in $O(V + E)$ time.
* **[Bridges in a Graph](bridges_and_articulation_points/bridge_in_a_graph.md)** ([C++ Code](bridges_and_articulation_points/bridge_in_a_graph.cpp)): Tarjan's algorithm checking condition `low[v] > disc[u]` to detect critical edges whose removal disconnects the graph.
* **[Articulation Points in a Graph](bridges_and_articulation_points/articulation_points.md)** ([C++ Code](bridges_and_articulation_points/articulation_points.cpp)): Detecting cut-vertices where `low[v] >= disc[u]` (non-root) or child count $\ge 2$ (root) in $O(V + E)$ time.

