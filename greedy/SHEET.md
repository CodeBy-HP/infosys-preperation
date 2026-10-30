# Greedy Algorithms Master Roadmap & Problem Sheet

Welcome to the **Greedy Algorithms** paradigm. While Dynamic Programming explores every possible parallel universe to guarantee the optimal outcome, Greedy algorithms make the locally optimal choice at each step without backtracking, trusting that the choice leads to the global optimum.

---

## 1. Interval / Scheduling Greedy
Focus: Sorting intervals by start or end times to maximize throughput or minimize overlap conflicts.

* **[Problem 1: Non-overlapping Intervals](interval_and_scheduling/non_overlapping_intervals.md)** ([C++ Code](interval_and_scheduling/non_overlapping_intervals.cpp)): Classic Activity Selection. Sorting by earliest finish time to maximize future timeline availability.
* **[Problem 4: Task Scheduler](interval_and_scheduling/task_scheduler.md)** ([C++ Code](interval_and_scheduling/task_scheduler.cpp)): CPU cooldown cycles. Solved via both Max-Heap + Cooldown Queue simulation and an optimal closed-form math formula.

---

## 2. Array / Jump Greedy
Focus: Tracking rolling boundaries, maximum reach, and greedy leaps to bypass redundant states.

* **[Problem 2: Jump Game](array_and_jump_greedy/jump_game.md)** ([C++ Code](array_and_jump_greedy/jump_game.cpp)): Forward rolling maximum reach and backwards goal-shrinking in $O(N)$ time and $O(1)$ space.
* **[Problem 3: Jump Game II](array_and_jump_greedy/jump_game_ii.md)** ([C++ Code](array_and_jump_greedy/jump_game_ii.cpp)): Minimum jumps to reach the destination using an implicit level-by-level BFS window.
* **[Problem 5: Gas Station](array_and_jump_greedy/gas_station.md)** ([C++ Code](array_and_jump_greedy/gas_station.cpp)): Circular circuit traversal; global feasibility check and the "Failed Reach" greedy leap proof.

---

## 3. Priority Queue / Heap Greedy
Focus: Dynamically extracting the current maximum or minimum element as parameters and states update.

* **[Data Center Cooling Optimization](priority_queue_and_heap_greedy/data_center_cooling.md)** ([C++ Code](priority_queue_and_heap_greedy/data_center_cooling.cpp), [Python Code](priority_queue_and_heap_greedy/data_center_cooling.py)): Dynamic heat load scheduling with minimum index separation constraints ($|i - j| \ge d$) and turbo multiplier thresholds.

---

## 4. Greedy on Strings
Focus: Character frequencies, lexicographical ordering, and aggressive collision resolution.

* **[Problem 6: Minimum Deletions to Make Character Frequencies Unique](string_greedy/min_deletions_to_make_character_frequencies_unique.md)** ([C++ Code](string_greedy/min_deletions_to_make_character_frequencies_unique.cpp)): Resolving frequency conflicts using hash sets, sorting, and max-heaps in $O(N)$ time.

---

## 5. Math & Constructive Greedy
Focus: Two-pass rule isolation, rearrangement inequalities, and optimal element pairing.

* **[Problem 7: Candy](math_and_constructive_greedy/candy.md)** ([C++ Code](math_and_constructive_greedy/candy.cpp)): Decoupling left and right slope rules into two independent passes with `max` merge, plus an optimal $O(1)$ space peak/valley slope algorithm.
* **[Minimum Processing Time](math_and_constructive_greedy/min_processing_time.md)** ([C++ Code](math_and_constructive_greedy/min_processing_time.cpp)): Rearrangement inequality: pairing earliest available processors with longest task durations.
* **[Minimum Steps to Clear Array](math_and_constructive_greedy/min_steps_to_clear_array.md)** ([C++ Code](math_and_constructive_greedy/min_steps_to_clear_array.cpp)): Distinct pair removal; majority bottleneck vs. physical limit: $\max(\text{max\_freq}, \lceil N / 2 \rceil)$.
* **[Two City Scheduling with Transit Cost](math_and_constructive_greedy/two_city_scheduling.md)** ([C++ Code](math_and_constructive_greedy/two_city_scheduling.cpp)): Opportunity cost differences $\Delta[i] = \text{cost\_B}[i] - A[i]$ with sorting and Quickselect $O(N)$ optimization.
