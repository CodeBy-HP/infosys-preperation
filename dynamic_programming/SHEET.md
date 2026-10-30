# Dynamic Programming Master Roadmap & Problem Sheet

We systematically dismantle Dynamic Programming by **Patterns**. Once you recognize the pattern, the recurrence and transitions emerge naturally.

---

## 1. 1D DP / Linear Formulations
Focus: Making sequential choices (pick / skip / jump / color) where the state depends only on a local prefix or suffix.

* **[Problem 1: House Robber](1d_dp/house_robber.md)** ([C++ Code](1d_dp/house_robber.cpp)): The gateway to 1D DP. Adjacent robbery alarms, choice between skipping vs. robbing with $O(1)$ space optimization.
* **[Problem 2: House Robber II](1d_dp/house_robber_ii.md)** ([C++ Code](1d_dp/house_robber_ii.cpp)): Breaking circular dependencies by branching into two linear universes ($0 \dots N-2$ vs. $1 \dots N-1$).
* **[Count Number of Texts](1d_dp/count_number_of_texts.md)** ([C++ Code](1d_dp/count_number_of_texts.cpp)): Decoding phone keypad presses with variable lookaheads (3 presses vs 4 presses) modulo $10^9 + 7$.
* **[Fibonacci Staircase Cost](1d_dp/fibonacci_staircase_cost.md)** ([Python Code](1d_dp/fibonacci_staircase_cost.py)): Staircase pathfinding with Fibonacci-sized jumps; connects 1D DP with Zeckendorf's greedy theorem.
* **[Paint House with Budget](1d_dp/paint_house_budget.md)** ([Python Code](1d_dp/paint_house_budget.py)): Multi-color adjacent constraints with total budget threshold; optimized with 1st and 2nd minimum tracking.

---

## 2. 2D Grid & Path DP
Focus: Pathfinding, optimizing, and accumulating values through 2D grids with directional constraints (Right / Down).

* **[Problem 3: Unique Paths](2d_grid_dp/unique_paths.md)** ([C++ Code](2d_grid_dp/unique_paths.cpp)): Counting path combinations on an $M \times N$ grid; compared with combinatorics.
* **[Problem 4: Minimum Path Sum](2d_grid_dp/minimum_path_sum.md)** ([C++ Code](2d_grid_dp/minimum_path_sum.cpp)): Moving from counting to cost optimization using $\min(\text{Up}, \text{Left}) + \text{grid}$.
* **[Problem 5: Dungeon Game](2d_grid_dp/dungeon_game.md)** ([C++ Code](2d_grid_dp/dungeon_game.cpp)): The ultimate grid boss. Why forward DP fails, backwards DP formulation, and survival rule logic.

---

## 3. String DP
Focus: Two-pointer string comparisons, prefix alignment, and edit transitions.

* **[Problem 7: Longest Common Subsequence (LCS)](string_dp/longest_common_subsequence.md)** ([C++ Code](string_dp/longest_common_subsequence.cpp)): The foundational two-string DP pattern comparing characters and branching into parallel reduction universes.
* **[Problem 8: Edit Distance (Levenshtein Distance)](string_dp/edit_distance.md)** ([C++ Code](string_dp/edit_distance.cpp)): Multi-operation string transformation (Insert, Delete, Replace).

---

## 4. Knapsack Patterns
Focus: Capacity constraints, subset selections, and finite vs. infinite item reuse.

* **[Problem 9: Partition Equal Subset Sum (0/1 Knapsack)](knapsack/partition_equal_subset_sum.md)** ([C++ Code](knapsack/partition_equal_subset_sum.cpp)): Parity check + subset sum to $\text{Total}/2$; backward loop trick for 1D space optimization.
* **[Problem 10: Coin Change (Unbounded Knapsack)](knapsack/coin_change.md)** ([C++ Code](knapsack/coin_change.cpp)): Infinite item supply; forward loop transition for unbounded reuse.

---

## 5. Subsequence & LIS Patterns
Focus: Comparing the current element against past chosen elements to maintain order properties.

* **[Problem 11: Longest Increasing Subsequence (LIS)](subsequence_and_lis/longest_increasing_subsequence.md)** ([C++ Code](subsequence_and_lis/longest_increasing_subsequence.cpp)): State tracking with previous index shift, $O(N^2)$ tabulation, and $O(N \log N)$ patience sorting / binary search.

---

## 6. Interval & Partition DP (Matrix Chain Multiplication)
Focus: Non-linear sequence division, collapsing intervals, and front partitioning.

* **[Problem 12: Burst Balloons](interval_and_partition_dp/burst_balloons.md)** ([C++ Code](interval_and_partition_dp/burst_balloons.cpp)): Why picking the first balloon fails; the "Last Survivor" interval DP technique.
* **[Problem 13: Palindrome Partitioning II](interval_and_partition_dp/palindrome_partitioning_ii.md)** ([C++ Code](interval_and_partition_dp/palindrome_partitioning_ii.cpp)): Front Partitioning optimization reducing $O(N^3)$ interval DP down to $O(N^2)$ with $O(1)$ precomputed palindromes.
* **[Maximum Dominance Partition](interval_and_partition_dp/max_dominance_partition.md)** ([Python Code](interval_and_partition_dp/max_dominance_partition.py)): Dividing an array into $K$ contiguous subarrays to maximize dominance score sum.
* **[Minimum Amplifiers Coverage](interval_and_partition_dp/min_amplifiers_coverage.md)** ([Python Code](interval_and_partition_dp/min_amplifiers_coverage.py)): Interval covering with limited super upgrades; greedy jump binary search combined with DP.

---

## 7. State Machine DP
Focus: Daily decision state graphs and mandatory cooldowns.

* **[Problem 15: Best Time to Buy and Sell Stock with Cooldown](state_machine_dp/stock_with_cooldown.md)** ([C++ Code](state_machine_dp/stock_with_cooldown.cpp)): Holding vs. Not Holding state transitions with forced $i + 2$ cooldown jumps.

---

## 8. Advanced DP Paradigms
Focus: Trees, bitwise state compression, and digit constraints.

* **[Problem 14: Binary Tree Maximum Path Sum (Tree DP)](tree_dp/binary_tree_maximum_path_sum.md)** ([C++ Code](tree_dp/binary_tree_maximum_path_sum.cpp)): Post-order DFS computing "The Arch" (local maximum) vs. "The Straight Line" (return value to parent).
* **[Problem 16: Traveling Salesperson Problem (Bitmask DP)](bitmask_dp/traveling_salesperson.md)** ([C++ Code](bitmask_dp/traveling_salesperson.cpp)): Compressing visited subsets into integer bitmasks to solve exponential permutations in $O(N^2 \cdot 2^N)$.
* **[Problem 17: Count Integers with Target Digit Sum (Digit DP)](digit_dp/count_integers_with_target_digit_sum.md)** ([C++ Code](digit_dp/count_integers_with_target_digit_sum.cpp)): Building numbers digit-by-digit under the "tight" upper bound in $O(\log N)$ time.
