# Greedy Algorithms Master Roadmap & Problem Sheet

Welcome to the **Greedy Algorithms** paradigm. While Dynamic Programming explores every possible parallel universe to guarantee the optimal outcome, Greedy algorithms make the locally optimal choice at each step without backtracking, trusting that the choice leads to the global optimum.

This sheet organizes **24 high-frequency problems** across **5 core greedy patterns** tested in top-tier coding assessments.

---

## 1. Interval & Scheduling Greedy
*Focus: Sorting intervals by start or end times to maximize throughput or minimize overlap conflicts.*

* **[Problem 1: Non-overlapping Intervals](interval_and_scheduling/non_overlapping_intervals.md)** ([C++ Code](interval_and_scheduling/non_overlapping_intervals.cpp)): Classic Activity Selection. Sorting by earliest finish time to maximize future timeline availability.
* **[N Meetings in One Room](interval_and_scheduling/n_meetings_in_one_room.md)** ([C++ Code](interval_and_scheduling/n_meetings_in_one_room.cpp)): Greedy activity selection sorting by finish time to accommodate maximum disjoint meetings in $O(N \log N)$ time.
* **[Insert Interval](interval_and_scheduling/insert_interval.md)** ([C++ Code](interval_and_scheduling/insert_interval.cpp)): 3-phase linear scan (left disjoint, overlapping merge, right disjoint) inserting and merging in $O(N)$ time.
* **[Problem 8: Merge Intervals](interval_and_scheduling/merge_intervals.md)** ([C++ Code](interval_and_scheduling/merge_intervals.cpp)): Sorting by start time and greedy linear sweep merging overlapping time slots in $O(N \log N)$ time.
* **[Minimum Number of Platforms Required for a Railway](interval_and_scheduling/minimum_platforms.md)** ([C++ Code](interval_and_scheduling/minimum_platforms.cpp)): Chronological sweep-line sorting arrival and departure events independently to find maximum concurrent trains in $O(N \log N)$ time.
* **[Shortest Job First (SJF) Scheduling](interval_and_scheduling/shortest_job_first.md)** ([C++ Code](interval_and_scheduling/shortest_job_first.cpp)): Rearrangement inequality proof demonstrating that executing jobs in ascending burst time minimizes total waiting time.
* **[Job Sequencing Problem](interval_and_scheduling/job_sequencing_problem.md)** ([C++ Code](interval_and_scheduling/job_sequencing_problem.cpp)): Profit maximization placing jobs at their latest possible deadline slot via both linear scan and DSU fast-slot finding in $O(N \log N)$ time.
* **[Problem 4: Task Scheduler](interval_and_scheduling/task_scheduler.md)** ([C++ Code](interval_and_scheduling/task_scheduler.cpp)): CPU cooldown cycles. Solved via both Max-Heap + Cooldown Queue simulation and an optimal closed-form math formula.

---

## 2. Array & Jump Greedy
*Focus: Tracking rolling boundaries, maximum reach, and greedy leaps to bypass redundant states.*

* **[Problem 2: Jump Game](array_and_jump_greedy/jump_game.md)** ([C++ Code](array_and_jump_greedy/jump_game.cpp)): Forward rolling maximum reach and backwards goal-shrinking in $O(N)$ time and $O(1)$ space.
* **[Problem 3: Jump Game II](array_and_jump_greedy/jump_game_ii.md)** ([C++ Code](array_and_jump_greedy/jump_game_ii.cpp)): Minimum jumps to reach the destination using an implicit level-by-level BFS window in $O(N)$ time.
* **[Problem 5: Gas Station](array_and_jump_greedy/gas_station.md)** ([C++ Code](array_and_jump_greedy/gas_station.cpp)): Circular circuit traversal; global feasibility check and the "Failed Reach" greedy leap proof.

---

## 3. Math & Constructive Greedy
*Focus: Two-pass rule isolation, rearrangement inequalities, value density sorting, and optimal pairing.*

* **[Assign Cookies](math_and_constructive_greedy/assign_cookies.md)** ([C++ Code](math_and_constructive_greedy/assign_cookies.cpp)): Satisfying the least greedy child with the smallest sufficient cookie via two sorted pointers in $O(N \log N)$ time.
* **[Lemonade Change](math_and_constructive_greedy/lemonade_change.md)** ([C++ Code](math_and_constructive_greedy/lemonade_change.cpp)): Prioritizing reserved $\$5$ bills by giving $\$10 + \$5$ for $\$20$ bills in a single $O(N)$ pass.
* **[Fractional Knapsack](math_and_constructive_greedy/fractional_knapsack.md)** ([C++ Code](math_and_constructive_greedy/fractional_knapsack.cpp)): Greedily selecting items in descending value-to-weight density ratio $\frac{v_i}{w_i}$ taking fractions for residual capacity in $O(N \log N)$ time.
* **[Problem 7: Candy](math_and_constructive_greedy/candy.md)** ([C++ Code](math_and_constructive_greedy/candy.cpp)): Decoupling left and right slope rules into two independent passes with `max` merge, plus an optimal $O(1)$ space peak/valley slope algorithm.
* **[Minimum Processing Time](math_and_constructive_greedy/min_processing_time.md)** ([C++ Code](math_and_constructive_greedy/min_processing_time.cpp)): Rearrangement inequality: pairing earliest available processors with longest task durations.
* **[Minimum Steps to Clear Array](math_and_constructive_greedy/min_steps_to_clear_array.md)** ([C++ Code](math_and_constructive_greedy/min_steps_to_clear_array.cpp)): Distinct pair removal; majority bottleneck vs. physical limit: $\max(\text{max\_freq}, \lceil N / 2 \rceil)$.
* **[Two City Scheduling with Transit Cost](math_and_constructive_greedy/two_city_scheduling.md)** ([C++ Code](math_and_constructive_greedy/two_city_scheduling.cpp)): Opportunity cost differences $\Delta[i] = \text{cost\_B}[i] - A[i]$ with sorting and Quickselect $O(N)$ optimization.
* **[Auction Revenue Calculation](math_and_constructive_greedy/auction_revenue_calculation.md)** ([C++ Code](math_and_constructive_greedy/auction_revenue_calculation.cpp)): Sequential auction simulation with budget feasibility checks, tie-breaking, and winner state-tracking in $O(N \times M)$ time.
* **[Defeat the Maximum Number of Monsters](math_and_constructive_greedy/defeat_max_monsters.md)** ([C++ Code](math_and_constructive_greedy/defeat_max_monsters.cpp)): Greedy RPG combat prioritizing weakest power requirement to harvest health bonus points in $O(N \log N)$ time.

---

## 4. Priority Queue / Heap Greedy
*Focus: Dynamically extracting the current maximum or minimum element as parameters and states update.*

* **[Data Center Cooling Optimization](priority_queue_and_heap_greedy/data_center_cooling.md)** ([C++ Code](priority_queue_and_heap_greedy/data_center_cooling.cpp), [Python Code](priority_queue_and_heap_greedy/data_center_cooling.py)): Dynamic heat load scheduling with minimum index separation constraints ($|i - j| \ge d$) and turbo multiplier thresholds.
* **[Task Assignment Optimization](priority_queue_and_heap_greedy/task_assignment_optimization.md)** ([C++ Code](priority_queue_and_heap_greedy/task_assignment_optimization.cpp)): Assigning tasks to workers with skill eligibility using two-pointer sorting and max-heap profit prioritization.

---

## 5. Greedy on Strings
*Focus: Range invariants, wildcard elasticity, and character frequency deduplication.*

* **[Valid Parenthesis Checker](string_greedy/valid_parenthesis_checker.md)** ([C++ Code](string_greedy/valid_parenthesis_checker.cpp)): Elastic open bracket interval tracking $[\text{cmin}, \text{cmax}]$ handling `'*'` wildcards in $O(N)$ time and $O(1)$ space.
* **[Problem 6: Minimum Deletions to Make Character Frequencies Unique](string_greedy/min_deletions_to_make_character_frequencies_unique.md)** ([C++ Code](string_greedy/min_deletions_to_make_character_frequencies_unique.cpp)): Resolving frequency conflicts using hash sets, sorting, and max-heaps in $O(N)$ time.
