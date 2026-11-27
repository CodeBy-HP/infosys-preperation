# Infosys Specialist Programmer (SP) & DSE — Master Question Archive

This folder contains **all 54 Infosys Specialist Programmer (SP) / Digital Specialist Engineer (DSE) coding problems** from [list.csv](list.csv), reconstructed with full LeetCode-style problem statements, concrete examples, constraints, algorithmic pattern breakdowns, and compiled C++17 implementations.

---

## 1. DP — State & Counting (`dp_state/`)

| # | Problem | Closest Pattern / Twist | Markdown | C++ Code |
| :---: | :--- | :--- | :---: | :---: |
| 1 | Count Vowels Permutation | State-Machine DP + Matrix Expo | [MD](dp_state/01_count_vowels_permutation.md) | [CPP](dp_state/01_count_vowels_permutation.cpp) |
| 2 | Target Sum | Subset Sum Difference Reduction | [MD](dp_state/02_target_sum_state_dp.md) | [CPP](dp_state/02_target_sum_state_dp.cpp) |
| 3 | Custom Mod-State String Counting DP | Mod-State DP + Matrix Expo | [MD](dp_state/03_mod_state_digit_dp.md) | [CPP](dp_state/03_mod_state_digit_dp.cpp) |
| 4 | Count Strings `{0,1,2}` (`"00"`, `"111"`, `121`) | 3D Finite-State Constrained DP | [MD](dp_state/04_count_strings_012_constrained.md) | [CPP](dp_state/04_count_strings_012_constrained.cpp) |
| 5 | Number Construction (`a[i+1] = 2*a[i]` / Divisibility) | Harmonic Sieve Push-DP | [MD](dp_state/05_number_construction_divisibility_and_doubling.md) | [CPP](dp_state/05_number_construction_divisibility_and_doubling.cpp) |
| 6 | Alternating Vowel Paths | Directed Vowel Graph + Up/Down Alternation | [MD](dp_state/06_alternating_vowel_paths.md) | [CPP](dp_state/06_alternating_vowel_paths.cpp) |
| 7 | Count Strings `{a,b,c}` (First Char `'a'`) | Closed-Form Combinatorics & Adjacency DP | [MD](dp_state/07_count_strings_abc_first_char_a.md) | [CPP](dp_state/07_count_strings_abc_first_char_a.cpp) |
| 8 | Quantum Core Parity | Parity-Tracking State DP | [MD](dp_state/08_quantum_core_parity.md) | [CPP](dp_state/08_quantum_core_parity.cpp) |
| 9 | Binary Strings Without K Consecutive Ones | Sliding-Window Linear Recurrence | [MD](dp_state/09_binary_strings_no_k_consecutive_ones.md) | [CPP](dp_state/09_binary_strings_no_k_consecutive_ones.cpp) |
| 10 | Thermostat Schedule | Mode-Transition Slope Sweep DP | [MD](dp_state/10_thermostat_schedule.md) | [CPP](dp_state/10_thermostat_schedule.cpp) |

---

## 2. DP — Sequence & Kadane Variants (`dp_sequence/`)

| # | Problem | Closest Pattern / Twist | Markdown | C++ Code |
| :---: | :--- | :--- | :---: | :---: |
| 11 | Max Sum with Parity & Distance Constraint | Prefix-Best Parity Lag DP | [MD](dp_sequence/11_max_sum_parity_and_distance.md) | [CPP](dp_sequence/11_max_sum_parity_and_distance.cpp) |
| 12 | Max Profit / Subsequence with Cooldown | 3-State Finite State Machine | [MD](dp_sequence/12_max_length_subsequence_cooldown.md) | [CPP](dp_sequence/12_max_length_subsequence_cooldown.cpp) |
| 13 | Min Cost Climbing Stairs | Rolling 2-Variable 1D DP | [MD](dp_sequence/13_min_cost_climbing_stairs.md) | [CPP](dp_sequence/13_min_cost_climbing_stairs.cpp) |
| 14 | Max Subarray Sum with One Deletion / Negation | Dual-State Kadane DP | [MD](dp_sequence/14_max_subarray_one_deletion_or_negation.md) | [CPP](dp_sequence/14_max_subarray_one_deletion_or_negation.cpp) |
| 15 | Max Subarray Sum with One Bitwise NOT (`~`) | State-Machine Kadane (`~x = -x - 1`) | [MD](dp_sequence/15_max_subarray_one_bitwise_not.md) | [CPP](dp_sequence/15_max_subarray_one_bitwise_not.cpp) |

---

## 3. DP — String (`dp_string/`)

| # | Problem | Closest Pattern / Twist | Markdown | C++ Code |
| :---: | :--- | :--- | :---: | :---: |
| 16 | Minimum Cost String Transformation | Weighted Edit Distance (1D Space) | [MD](dp_string/16_min_cost_string_transformation.md) | [CPP](dp_string/16_min_cost_string_transformation.cpp) |
| 17 | Longest Common Substring with One Mismatch | Dual-Streak Diagonal DP ($O(NM)$) | [MD](dp_string/17_longest_common_substring_one_mismatch.md) | [CPP](dp_string/17_longest_common_substring_one_mismatch.cpp) |
| 18 | Special Decode Ways (Modified / `*` Wildcard) | Decode Ways I & II State DP | [MD](dp_string/18_special_decode_ways.md) | [CPP](dp_string/18_special_decode_ways.cpp) |

---

## 4. DP — Knapsack (`dp_knapsack/`)

| # | Problem | Closest Pattern / Twist | Markdown | C++ Code |
| :---: | :--- | :--- | :---: | :---: |
| 19 | Minimum Energy Transfer | Bounded Knapsack + Activation Fee + Monotonic Deque | [MD](dp_knapsack/19_minimum_energy_transfer.md) | [CPP](dp_knapsack/19_minimum_energy_transfer.cpp) |
| 20 | Bounded Coin Change with Scarcity & Gap $D$ | Sorted Prefix-Sum Bounded DP | [MD](dp_knapsack/20_bounded_coin_change_with_scarcity.md) | [CPP](dp_knapsack/20_bounded_coin_change_with_scarcity.cpp) |
| 21 | Last Stone Weight II | Subset Sum Min-Difference 0/1 Knapsack | [MD](dp_knapsack/21_last_stone_weight_ii.md) | [CPP](dp_knapsack/21_last_stone_weight_ii.cpp) |
| 22 | Last Stone Weight II + Resonance | Offset Balance DP with `prevSet` Bonus | [MD](dp_knapsack/22_last_stone_weight_ii_resonance.md) | [CPP](dp_knapsack/22_last_stone_weight_ii_resonance.cpp) |
| 23 | Combination Sum IV | Unbounded Ordered Permutation DP | [MD](dp_knapsack/23_combination_sum_iv.md) | [CPP](dp_knapsack/23_combination_sum_iv.cpp) |

---

## 5. DP — Partition & Interval (`dp_partition_interval/`)

| # | Problem | Closest Pattern / Twist | Markdown | C++ Code |
| :---: | :--- | :--- | :---: | :---: |
| 24 | Min Cost K-Partition (Range Cost) | $(\max - \min) + |first - last|$ Partition DP | [MD](dp_partition_interval/24_min_cost_k_partition_range_cost.md) | [CPP](dp_partition_interval/24_min_cost_k_partition_range_cost.cpp) |
| 25 | Min Cost K-Partition (`Sum × Endpoint Diff`) | Prefix-Sum Rolling Partition DP | [MD](dp_partition_interval/25_min_cost_k_partition_sum_endpoint_diff.md) | [CPP](dp_partition_interval/25_min_cost_k_partition_sum_endpoint_diff.cpp) |
| 26 | Max Profit with K Intervals | Weighted Interval Scheduling + Binary Search | [MD](dp_partition_interval/26_max_profit_k_intervals.md) | [CPP](dp_partition_interval/26_max_profit_k_intervals.cpp) |
| 27 | LIS Partition Count / Number of LIS | Dual `len + cnt` DP & Dilworth Patience Sorting | [MD](dp_partition_interval/27_lis_partition_count.md) | [CPP](dp_partition_interval/27_lis_partition_count.cpp) |

---

## 6. DP — Grid (`dp_grid/`)

| # | Problem | Closest Pattern / Twist | Markdown | C++ Code |
| :---: | :--- | :--- | :---: | :---: |
| 28 | Longest Increasing Path + One Dash Move | 3D Memoized DAG DFS (`usedDash`) | [MD](dp_grid/28_longest_increasing_path_one_dash.md) | [CPP](dp_grid/28_longest_increasing_path_one_dash.cpp) |
| 29 | Grid Path with One Row Skip | Layered Grid DP `dp[r][c][usedSkip]` | [MD](dp_grid/29_grid_path_one_row_skip.md) | [CPP](dp_grid/29_grid_path_one_row_skip.cpp) |
| 30 | Grid Path with Adjacency Gap Penalty | Rolling Row DP with Elevation Diff | [MD](dp_grid/30_grid_path_adjacency_gap_penalty.md) | [CPP](dp_grid/30_grid_path_adjacency_gap_penalty.cpp) |
| 31 | Frog Jump with Fatigue | River Crossing Map DP & K-Step Fatigue | [MD](dp_grid/31_frog_jump_with_fatigue.md) | [CPP](dp_grid/31_frog_jump_with_fatigue.cpp) |
| 32 | Longest Alternating Sign / Turbulent Subarray | Up/Down Parity State DP ($O(N)$) | [MD](dp_grid/32_longest_alternating_sign_subarray.md) | [CPP](dp_grid/32_longest_alternating_sign_subarray.cpp) |

---

## 7. DP — Tree (`dp_tree/`)

| # | Problem | Closest Pattern / Twist | Markdown | C++ Code |
| :---: | :--- | :--- | :---: | :---: |
| 33 | Tree DP (OA Version) — House Robber III | Post-Order `{take, skip}` Independent Set | [MD](dp_tree/33_tree_dp_house_robber_iii.md) | [CPP](dp_tree/33_tree_dp_house_robber_iii.cpp) |
| 34 | Tree DP (Interview Version) — Rerooting | Two-Pass In-Out Rerooting DP ($O(N)$) | [MD](dp_tree/34_tree_dp_rerooting_interview.md) | [CPP](dp_tree/34_tree_dp_rerooting_interview.cpp) |

---

## 8. Greedy Algorithms (`greedy/`)

| # | Problem | Closest Pattern / Twist | Markdown | C++ Code |
| :---: | :--- | :--- | :---: | :---: |
| 35 | Make Array Strictly Increasing (`arr[i] % (i+1) == 0`) | Minimal Valid Multiple Greedy | [MD](greedy/35_make_array_strictly_increasing_mod.md) | [CPP](greedy/35_make_array_strictly_increasing_mod.cpp) |
| 36 | Non-Overlapping Intervals | Earliest Finish Time Activity Selection | [MD](greedy/36_non_overlapping_intervals.md) | [CPP](greedy/36_non_overlapping_intervals.cpp) |
| 37 | Minimum Sum After One Swap (AP Indices) | Residue-Class Sliding Window + Multisets | [MD](greedy/37_minimum_sum_after_one_swap.md) | [CPP](greedy/37_minimum_sum_after_one_swap.cpp) |
| 38 | Minimum Cycles to Generate Required Power | Greedy Maximal Pair Extraction | [MD](greedy/38_min_cycles_required_power.md) | [CPP](greedy/38_min_cycles_required_power.cpp) |
| 39 | Reduce Array Size to Half (Range Variant) | Sorted Array Fixed-Window Width Minimization | [MD](greedy/39_reduce_array_size_half_range.md) | [CPP](greedy/39_reduce_array_size_half_range.cpp) |
| 40 | Tug of War Captain | Difference State `|d - x|` Bitmask DP | [MD](greedy/40_tug_of_war_captain.md) | [CPP](greedy/40_tug_of_war_captain.cpp) |
| 41 | Maximum Sum Selection by Index % K | Residue Bucket Greedy & Trigger Multiplier DP | [MD](greedy/41_max_sum_selection_index_mod_k.md) | [CPP](greedy/41_max_sum_selection_index_mod_k.cpp) |
| 42 | Equalize Temperature Regulators | Deficit Matching & Subarray Increment Math | [MD](greedy/42_equalize_temperature_regulators.md) | [CPP](greedy/42_equalize_temperature_regulators.cpp) |
| 43 | Minimum Operations to Make Array Empty | Frequency Map + $\lceil c/3 \rceil$ | [MD](greedy/43_min_operations_make_array_empty.md) | [CPP](greedy/43_min_operations_make_array_empty.cpp) |
| 44 | Minimum Number of Shuttles (Boats to Save People) | Sorting + Two Pointers Pairing | [MD](greedy/44_min_number_of_shuttles.md) | [CPP](greedy/44_min_number_of_shuttles.cpp) |

---

## 9. Graphs, Binary Search, Arrays, Bitmask & Modified Classics (`arrays_graph_bs_bit/`)

| # | Problem | Closest Pattern / Twist | Markdown | C++ Code |
| :---: | :--- | :--- | :---: | :---: |
| 45 | Dynamic Graph Path Queries (Parity / Alternating) | State-Space BFS `dist[node][state]` | [MD](arrays_graph_bs_bit/45_dynamic_graph_path_queries_parity.md) | [CPP](arrays_graph_bs_bit/45_dynamic_graph_path_queries_parity.cpp) |
| 46 | Max Value at Index in Bounded Array | Binary Search + Arithmetic Series Geometry | [MD](arrays_graph_bs_bit/46_max_value_at_index_bounded_array.md) | [CPP](arrays_graph_bs_bit/46_max_value_at_index_bounded_array.cpp) |
| 47 | Longest Consecutive Sequence | Hash Set Sequence-Start Expansion ($O(N)$) | [MD](arrays_graph_bs_bit/47_longest_consecutive_sequence.md) | [CPP](arrays_graph_bs_bit/47_longest_consecutive_sequence.cpp) |
| 48 | Rotated Array Shift | Three-Reversal In-Place ($O(1)$ Space) | [MD](arrays_graph_bs_bit/48_rotated_array_shift.md) | [CPP](arrays_graph_bs_bit/48_rotated_array_shift.cpp) |
| 49 | Car Pooling — Standing Passenger Kilometers | Sorted Sweep-Line Excess Accumulation | [MD](arrays_graph_bs_bit/49_car_pooling_standing_passenger_km.md) | [CPP](arrays_graph_bs_bit/49_car_pooling_standing_passenger_km.cpp) |
| 50 | Perfect Combinations (`AND = 0`, `OR % 3 == 0`) | Stratified Sum-Over-Subsets (SOS) DP | [MD](arrays_graph_bs_bit/50_perfect_combinations_bitmask.md) | [CPP](arrays_graph_bs_bit/50_perfect_combinations_bitmask.cpp) |
| 51 | 4Sum | Sorting + Two-Pointer Squeeze | [MD](arrays_graph_bs_bit/51_four_sum.md) | [CPP](arrays_graph_bs_bit/51_four_sum.cpp) |
| 52 | Buy/Sell Stock (Dynamic Settlement Delay) | Suffix Best Sell + `(price % 10) + 1` Delay | [MD](arrays_graph_bs_bit/52_stock_settlement_delay.md) | [CPP](arrays_graph_bs_bit/52_stock_settlement_delay.cpp) |
| 53 | Min Refueling Stops (No Consecutive Refuels) | Delayed Prefix Reachability DP ($O(N^2)$) | [MD](arrays_graph_bs_bit/53_min_refueling_stops_no_consecutive.md) | [CPP](arrays_graph_bs_bit/53_min_refueling_stops_no_consecutive.cpp) |
| 54 | Pizza With 3n Slices (K Tolerance Tokens) | Boundary-Fixed Circular Tolerance DP | [MD](arrays_graph_bs_bit/54_pizza_with_3n_slices_tolerance_tokens.md) | [CPP](arrays_graph_bs_bit/54_pizza_with_3n_slices_tolerance_tokens.cpp) |
