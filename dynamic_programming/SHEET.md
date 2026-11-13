# Dynamic Programming Master Roadmap & Problem Sheet

We systematically dismantle Dynamic Programming by **Patterns**. Once you recognize the pattern, the recurrence and transitions emerge naturally.

This sheet organizes **58 high-frequency problems** across **8 core DP paradigms** tested in top-tier coding assessments.

---

## 1. 1D DP / Linear Formulations
*Focus: Making sequential choices (pick / skip / jump / color) where the state depends only on a local prefix or suffix.*

* **[Problem 1: House Robber](1d_dp/house_robber.md)** ([C++ Code](1d_dp/house_robber.cpp)): The gateway to 1D DP. Adjacent robbery alarms, choice between skipping vs. robbing with $O(1)$ space optimization.
* **[Problem 2: House Robber II](1d_dp/house_robber_ii.md)** ([C++ Code](1d_dp/house_robber_ii.cpp)): Breaking circular dependencies by branching into two linear universes ($0 \dots N-2$ vs. $1 \dots N-1$).
* **[Climbing Stairs](1d_dp/climbing_stairs.md)** ([C++ Code](1d_dp/climbing_stairs.cpp)): Classic Fibonacci recurrence $f(n) = f(n-1) + f(n-2)$ solved in $O(1)$ space and $O(\log N)$ matrix exponentiation.
* **[Frog Jump](1d_dp/frog_jump.md)** ([C++ Code](1d_dp/frog_jump.cpp)): Minimum energy consumed jumping 1 or 2 steps with cost $|h[i] - h[j]|$ optimized to $O(1)$ space.
* **[Frog Jump with K Distances](1d_dp/frog_jump_with_k_distances.md)** ([C++ Code](1d_dp/frog_jump_with_k_distances.cpp)): Generalization of Frog Jump allowing variable lookahead up to $K$ stairs in $O(N \cdot K)$ time.
* **[Maximum Sum of Non-Adjacent Elements](1d_dp/maximum_sum_of_non_adjacent_elements.md)** ([C++ Code](1d_dp/maximum_sum_of_non_adjacent_elements.cpp)): Canonical pick/not-pick recurrence on arrays optimized to $O(N)$ time and $O(1)$ space.
* **[Count Number of Texts](1d_dp/count_number_of_texts.md)** ([C++ Code](1d_dp/count_number_of_texts.cpp)): Decoding phone keypad presses with variable lookaheads (3 presses vs 4 presses) modulo $10^9 + 7$.
* **[Fibonacci Staircase Cost](1d_dp/fibonacci_staircase_cost.md)** ([Python Code](1d_dp/fibonacci_staircase_cost.py)): Staircase pathfinding with Fibonacci-sized jumps; connects 1D DP with Zeckendorf's greedy theorem.
* **[Paint House with Budget](1d_dp/paint_house_budget.md)** ([Python Code](1d_dp/paint_house_budget.py)): Multi-color adjacent constraints with total budget threshold; optimized with 1st and 2nd minimum tracking.

---

## 2. 2D Grid & Path DP
*Focus: Pathfinding, optimizing, and accumulating values through 2D grids with directional constraints.*

* **[Problem 3: Unique Paths](2d_grid_dp/unique_paths.md)** ([C++ Code](2d_grid_dp/unique_paths.cpp)): Counting path combinations on an $M \times N$ grid; compared with combinatorics.
* **[Unique Paths II](2d_grid_dp/unique_paths_ii.md)** ([C++ Code](2d_grid_dp/unique_paths_ii.cpp)): Path counting with obstacle barriers and space-optimized rolling row DP in $O(N)$ space.
* **[Problem 4: Minimum Path Sum](2d_grid_dp/minimum_path_sum.md)** ([C++ Code](2d_grid_dp/minimum_path_sum.cpp)): Moving from counting to cost optimization using $\min(\text{Up}, \text{Left}) + \text{grid}$.
* **[Minimum Falling Path Sum](2d_grid_dp/minimum_falling_path_sum.md)** ([C++ Code](2d_grid_dp/minimum_falling_path_sum.cpp)): Finding minimum cost path falling from any cell in top row down to bottom row in $O(N^2)$ time and $O(N)$ space.
* **[Triangle](2d_grid_dp/triangle.md)** ([C++ Code](2d_grid_dp/triangle.cpp)): Bottom-up triangular grid minimization in $O(N^2)$ time and $O(N)$ space.
* **[Ninja's Training](2d_grid_dp/ninjas_training.md)** ([C++ Code](2d_grid_dp/ninjas_training.cpp)): Multi-activity consecutive non-repeating choice optimization in $O(N)$ time and $O(1)$ space.
* **[Cherry Pickup II](2d_grid_dp/cherry_pickup_ii.md)** ([C++ Code](2d_grid_dp/cherry_pickup_ii.cpp)): Simultaneous dual-robot path optimization across 3D state space $(i, j_1, j_2)$ space-optimized to $O(C^2)$.
* **[Count Square Submatrices with All Ones](2d_grid_dp/count_square_submatrices_with_all_ones.md)** ([C++ Code](2d_grid_dp/count_square_submatrices_with_all_ones.cpp)): Counting squares ending at $(i, j)$ using $1 + \min(\text{up}, \text{left}, \text{diag})$ in $O(M \times N)$ time.
* **[Problem 5: Dungeon Game](2d_grid_dp/dungeon_game.md)** ([C++ Code](2d_grid_dp/dungeon_game.cpp)): The ultimate grid boss. Why forward DP fails, backwards DP formulation, and survival rule logic.

---

## 3. DP on Stocks (State Machine DP)
*Focus: Daily decision state graphs, holding vs cash states, and transaction constraints.*

* **[Best Time to Buy and Sell Stock](state_machine_dp/best_time_to_buy_and_sell_stock.md)** ([C++ Code](state_machine_dp/best_time_to_buy_and_sell_stock.cpp)): Single transaction profit maximization via running minimum prefix in $O(N)$ time and $O(1)$ space.
* **[Best Time to Buy and Sell Stock II](state_machine_dp/best_time_to_buy_and_sell_stock_ii.md)** ([C++ Code](state_machine_dp/best_time_to_buy_and_sell_stock_ii.cpp)): Unlimited transactions via Buy/Sell state transitions or greedy slope accumulation in $O(N)$ time and $O(1)$ space.
* **[Best Time to Buy and Sell Stock III](state_machine_dp/best_time_to_buy_and_sell_stock_iii.md)** ([C++ Code](state_machine_dp/best_time_to_buy_and_sell_stock_iii.cpp)): At most 2 transactions solved via 3D DP / 4-variable finite state machine in $O(N)$ time and $O(1)$ space.
* **[Best Time to Buy and Sell Stock IV](state_machine_dp/best_time_to_buy_and_sell_stock_iv.md)** ([C++ Code](state_machine_dp/best_time_to_buy_and_sell_stock_iv.cpp)): At most $K$ transactions generalized in $O(N \cdot K)$ time and $O(K)$ auxiliary space.
* **[Best Time to Buy and Sell Stock with Transaction Fee](state_machine_dp/best_time_to_buy_and_sell_stock_with_transaction_fee.md)** ([C++ Code](state_machine_dp/best_time_to_buy_and_sell_stock_with_transaction_fee.cpp)): Incorporating per-transaction overhead into cash/hold states in $O(N)$ time and $O(1)$ space.
* **[Problem 15: Best Time to Buy and Sell Stock with Cooldown](state_machine_dp/stock_with_cooldown.md)** ([C++ Code](state_machine_dp/stock_with_cooldown.cpp)): Holding vs. Not Holding state transitions with forced $i + 2$ cooldown jumps.
* **[Maximum Score with Trigger-Based Subsequence](state_machine_dp/maximum_score_trigger_subsequence.md)** ([C++ Code](state_machine_dp/maximum_score_trigger_subsequence.cpp)): State machine DP tracking picked item count modulo $K$ to trigger double face-value earnings.

---

## 4. Knapsack & Subsequence Patterns
*Focus: Capacity constraints, subset selections, and finite (0/1) vs. infinite (unbounded) item reuse.*

* **[Subset Sum Equals Target](knapsack/subset_sum_equals_to_target.md)** ([C++ Code](knapsack/subset_sum_equals_to_target.cpp)): Identifying existence of subset with sum $K$ space-optimized to $O(K)$.
* **[Problem 9: Partition Equal Subset Sum (0/1 Knapsack)](knapsack/partition_equal_subset_sum.md)** ([C++ Code](knapsack/partition_equal_subset_sum.cpp)): Parity check + subset sum to $\text{Total}/2$; backward loop trick for 1D space optimization.
* **[Partition Set Into 2 Subsets With Min Absolute Sum Difference](knapsack/partition_set_min_difference.md)** ([C++ Code](knapsack/partition_set_min_difference.cpp)): Minimizing $|S_1 - S_2|$ by scanning achievable sums up to $\lfloor S_{tot} / 2 \rfloor$ in $O(N \cdot S_{tot})$ time.
* **[Count Subsets with Sum K](knapsack/count_subsets_with_sum_k.md)** ([C++ Code](knapsack/count_subsets_with_sum_k.cpp)): Counting subsets modulo $10^9 + 7$ with explicit handling for zeros.
* **[Count Partitions with Given Difference](knapsack/count_partitions_with_given_difference.md)** ([C++ Code](knapsack/count_partitions_with_given_difference.cpp)): Mathematical reduction of $S_1 - S_2 = D$ into target sum $(S_{tot} + D)/2$.
* **[0/1 Knapsack](knapsack/zero_one_knapsack.md)** ([C++ Code](knapsack/zero_one_knapsack.cpp)): Canonical capacity maximization with backward loop space optimization in $O(N \cdot W)$ time and $O(W)$ space.
* **[Target Sum](knapsack/target_sum.md)** ([C++ Code](knapsack/target_sum.cpp)): Assigning $+/-$ signs to achieve target mapped to subset partition difference.
* **[Problem 10: Coin Change (Minimum Coins)](knapsack/coin_change.md)** ([C++ Code](knapsack/coin_change.cpp)): Infinite item supply; forward loop transition for unbounded reuse.
* **[Coin Change II](knapsack/coin_change_ii.md)** ([C++ Code](knapsack/coin_change_ii.cpp)): Counting total combination ways to form target amount using unbounded coins in $O(N \cdot \text{amount})$ time and $O(\text{amount})$ space.
* **[Unbounded Knapsack](knapsack/unbounded_knapsack.md)** ([C++ Code](knapsack/unbounded_knapsack.cpp)): Maximum profit with infinite supply of items via forward 1D iteration in $O(N \cdot W)$ time.
* **[Rod Cutting Problem](knapsack/rod_cutting.md)** ([C++ Code](knapsack/rod_cutting.cpp)): Direct mapping to unbounded knapsack maximizing sales revenue from rod pieces in $O(N^2)$ time.
* **[Weighted Coin Change](knapsack/weighted_coin_change.md)** ([C++ Code](knapsack/weighted_coin_change.cpp)): Unbounded knapsack variation factoring in arbitrary coin weights and minimizing total accumulated weight.

---

## 5. Subsequence & LIS Patterns
*Focus: Order preservation, predecessor tracking, patience sorting, and sequence reconstruction.*

* **[Problem 11: Longest Increasing Subsequence (LIS)](subsequence_and_lis/longest_increasing_subsequence.md)** ([C++ Code](subsequence_and_lis/longest_increasing_subsequence.cpp)): State tracking with previous index shift, $O(N^2)$ tabulation, and $O(N \log N)$ patience sorting / binary search.
* **[Print Longest Increasing Subsequence](subsequence_and_lis/print_longest_increasing_subsequence.md)** ([C++ Code](subsequence_and_lis/print_longest_increasing_subsequence.cpp)): Path reconstruction using parent back-pointers in $O(N^2)$ time and $O(N)$ space.
* **[Largest Divisible Subset](subsequence_and_lis/largest_divisible_subset.md)** ([C++ Code](subsequence_and_lis/largest_divisible_subset.cpp)): Transitivity of divisibility under sorting transforming problem into LIS with subset reconstruction.
* **[Longest String Chain](subsequence_and_lis/longest_string_chain.md)** ([C++ Code](subsequence_and_lis/longest_string_chain.cpp)): Word predecessor matching via length sorting and hash-map lookups in $O(N \log N + N \cdot L^2)$ time.
* **[Longest Bitonic Subsequence](subsequence_and_lis/longest_bitonic_subsequence.md)** ([C++ Code](subsequence_and_lis/longest_bitonic_subsequence.cpp)): Dual forward LIS and backward LIS (LDS) peak combination $(dp_1[i] + dp_2[i] - 1)$ in $O(N^2)$ time.
* **[Number of Longest Increasing Subsequences](subsequence_and_lis/number_of_longest_increasing_subsequences.md)** ([C++ Code](subsequence_and_lis/number_of_longest_increasing_subsequences.cpp)): Parallel length and frequency counting tracking all distinct LIS paths in $O(N^2)$ time.

---

## 6. String DP
*Focus: Two-string comparisons, prefix alignment, edit transitions, and palindromic subsequences.*

* **[Problem 7: Longest Common Subsequence (LCS)](string_dp/longest_common_subsequence.md)** ([C++ Code](string_dp/longest_common_subsequence.cpp)): The foundational two-string DP pattern comparing characters and branching into parallel reduction universes.
* **[Longest Common Substring](string_dp/longest_common_substring.md)** ([C++ Code](string_dp/longest_common_substring.cpp)): Contiguous matching where mismatch resets state to 0 in $O(N \cdot M)$ time and $O(M)$ space.
* **[Longest Palindromic Subsequence](string_dp/longest_palindromic_subsequence.md)** ([C++ Code](string_dp/longest_palindromic_subsequence.cpp)): Canonical reduction of palindromes to $LCS(s, \text{reverse}(s))$ in $O(N^2)$ time.
* **[Minimum Insertions to Make String Palindrome](string_dp/min_insertions_to_make_palindrome.md)** ([C++ Code](string_dp/min_insertions_to_make_palindrome.cpp)): Preserving the core LPS and inserting counterparts for remaining $N - \text{LPS}$ characters.
* **[Minimum Insertions or Deletions to Convert String A to B](string_dp/min_insertions_deletions_a_to_b.md)** ([C++ Code](string_dp/min_insertions_deletions_a_to_b.cpp)): Preserving common subsequence and computing $(N - \text{LCS}) + (M - \text{LCS})$.
* **[Shortest Common Supersequence](string_dp/shortest_common_supersequence.md)** ([C++ Code](string_dp/shortest_common_supersequence.cpp)): Two-pointer backtracking through full LCS table reconstructing the shortest supersequence string.
* **[Distinct Subsequences](string_dp/distinct_subsequences.md)** ([C++ Code](string_dp/distinct_subsequences.cpp)): Counting occurrences of $T$ in $S$ with backwards 1D in-place traversal in $O(N \cdot M)$ time and $O(M)$ space.
* **[Problem 8: Edit Distance (Levenshtein Distance)](string_dp/edit_distance.md)** ([C++ Code](string_dp/edit_distance.cpp)): Multi-operation string transformation (Insert, Delete, Replace).
* **[Wildcard Matching](string_dp/wildcard_matching.md)** ([C++ Code](string_dp/wildcard_matching.cpp)): Matching strings with `'?'` and `'*'` wildcards in $O(N \cdot M)$ time and $O(M)$ space.
* **[Word Break](string_dp/word_break.md)** ([C++ Code](string_dp/word_break.cpp)): Dictionary segmentation via boolean prefix DP and max word length lookback in $O(N \cdot L_{\max}^2)$ time.
* **[Count Palindromic Subsequences](string_dp/count_palindromic_subsequences.md)** ([C++ Code](string_dp/count_palindromic_subsequences.cpp)): Principle of Inclusion-Exclusion interval DP counting all palindromic subsequences modulo $10^9 + 7$.

---

## 7. Interval & Partition DP (Matrix Chain Multiplication)
*Focus: Non-linear sequence division, collapsing intervals, last-survivor techniques, and boolean parenthesization.*

* **[Matrix Chain Multiplication (MCM)](interval_and_partition_dp/matrix_chain_multiplication.md)** ([C++ Code](interval_and_partition_dp/matrix_chain_multiplication.cpp)): Canonical MCM interval partitioning minimizing scalar multiplications in $O(N^3)$ time and $O(N^2)$ space.
* **[Problem 12: Burst Balloons](interval_and_partition_dp/burst_balloons.md)** ([C++ Code](interval_and_partition_dp/burst_balloons.cpp)): Why picking the first balloon fails; the "Last Survivor" interval DP technique.
* **[Problem 13: Palindrome Partitioning II](interval_and_partition_dp/palindrome_partitioning_ii.md)** ([C++ Code](interval_and_partition_dp/palindrome_partitioning_ii.cpp)): Front Partitioning optimization reducing $O(N^3)$ interval DP down to $O(N^2)$ with $O(1)$ precomputed palindromes.
* **[Partition Array for Maximum Sum](interval_and_partition_dp/partition_array_for_maximum_sum.md)** ([C++ Code](interval_and_partition_dp/partition_array_for_maximum_sum.cpp)): Front partitioning of size at most $K$ replacing elements with subarray maximum in $O(N \cdot K)$ time.
* **[Minimum Cost to Cut a Stick](interval_and_partition_dp/minimum_cost_to_cut_stick.md)** ([C++ Code](interval_and_partition_dp/minimum_cost_to_cut_stick.cpp)): Boundary-augmented interval DP evaluating sub-stick cut combinations in $O(M^3)$ time.
* **[Different Ways to Evaluate a Boolean Expression](interval_and_partition_dp/boolean_evaluation.md)** ([C++ Code](interval_and_partition_dp/boolean_evaluation.cpp)): Dual-matrix ($T/F$) interval DP parenthesizing boolean operators (`&`, `|`, `^`) modulo $10^9 + 7$.
* **[Maximum Dominance Partition](interval_and_partition_dp/max_dominance_partition.md)** ([Python Code](interval_and_partition_dp/max_dominance_partition.py)): Dividing an array into $K$ contiguous subarrays to maximize dominance score sum.
* **[Maximum Total Mode Frequency Score](interval_and_partition_dp/max_total_mode_frequency_score.md)** ([C++ Code](interval_and_partition_dp/max_total_mode_frequency_score.cpp)): Partitioning into $K$ contiguous groups to maximize the sum of group mode frequencies via $O(N^2)$ precomputation and partition DP.
* **[Minimum Amplifiers Coverage](interval_and_partition_dp/min_amplifiers_coverage.md)** ([Python Code](interval_and_partition_dp/min_amplifiers_coverage.py)): Interval covering with limited super upgrades; greedy jump binary search combined with DP.
* **[Minimum Cost to Make Array Zero](interval_and_partition_dp/min_cost_to_make_array_zero.md)** ([C++ Code](interval_and_partition_dp/min_cost_to_make_array_zero.cpp)): Subarray decrements vs point resets solved via Cartesian tree range-minimum divide & conquer.

---

## 8. Advanced DP Paradigms
*Focus: Trees, bitwise state compression, and digit constraints.*

* **[Problem 14: Binary Tree Maximum Path Sum (Tree DP)](tree_dp/binary_tree_maximum_path_sum.md)** ([C++ Code](tree_dp/binary_tree_maximum_path_sum.cpp)): Post-order DFS computing "The Arch" (local maximum) vs. "The Straight Line" (return value to parent).
* **[Problem 16: Traveling Salesperson Problem (Bitmask DP)](bitmask_dp/traveling_salesperson.md)** ([C++ Code](bitmask_dp/traveling_salesperson.cpp)): Compressing visited subsets into integer bitmasks to solve exponential permutations in $O(N^2 \cdot 2^N)$.
* **[Problem 17: Count Integers with Target Digit Sum (Digit DP)](digit_dp/count_integers_with_target_digit_sum.md)** ([C++ Code](digit_dp/count_integers_with_target_digit_sum.cpp)): Building numbers digit-by-digit under the "tight" upper bound in $O(\log N)$ time.
