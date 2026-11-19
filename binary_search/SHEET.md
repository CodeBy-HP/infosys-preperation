# Binary Search Master Roadmap & Problem Sheet

Welcome to the **Binary Search Algorithms & Discrete Decision Search** paradigm. While often introduced as a simple search across a sorted array, Binary Search is in reality a universal mathematical strategy: **reducing any search space of monotonic states by half at each step**.

Mastering binary search requires seeing beyond simple array index lookups to:
1. **The Halving & Boundary Invariant:** Eliminating half the search space with guaranteed termination (`left <= right` vs `left < right`).
2. **Predicate Monotonicity ($P(x) \implies P(x+1)$):** Binary search on the answer space when direct construction is hard but verification is polynomial ($O(N)$ or $O(1)$).
3. **Rotated & Discontinuous Monotonicity:** Preserving $O(\log N)$ by identifying which half retains strict sorting.
4. **Partition Search (Dual-Array Medians):** Simultaneously binary searching partition cuts across two independent sorted streams.
5. **Continuous / Real-Number Search:** Finding floating-point extrema within precision thresholds ($\epsilon = 10^{-6}$).

This sheet organizes **35 high-frequency problems** across **6 core patterns** tested in top-tier technical assessments.

---

## The Core Invariants of Binary Search

1. **Midpoint Overflow Prevention:**
   - Always calculate midpoint as:
     $$\text{mid} = left + \frac{right - left}{2}$$
   - Direct addition `(left + right) / 2` overflows standard 32-bit signed integers when $left + right \ge 2^{31}$.
2. **Lower Bound vs. Upper Bound Templates:**
   - **Lower Bound (`std::lower_bound`):** First index where $nums[i] \ge target$. If $nums[mid] \ge target$, `right = mid - 1`, `ans = mid`.
   - **Upper Bound (`std::upper_bound`):** First index where $nums[i] > target$. If $nums[mid] > target$, `right = mid - 1`, `ans = mid`.
3. **The Monotonic Predicate Invariant (Binary Search on Answer):**
   - Given a decision function $F(x) \in \{\text{True}, \text{False}\}$, if $F(x)$ is monotonic (e.g. $\text{False}, \text{False}, \dots, \text{True}, \text{True}$), we can binary search the transition boundary in $O(\log(\text{Range}) \times \text{Cost}(F))$ time.
4. **Saddleback Staircase Elimination in 2D:**
   - When rows and columns are independently sorted, starting at the top-right corner $(0, n - 1)$ or bottom-left corner $(m - 1, 0)$ allows eliminating an entire row or column in $O(1)$ time, yielding an optimal $O(m + n)$ traversal.
5. **Dual-Array Partition Balancing:**
   - To find the median or $k$-th element of two sorted arrays in $O(\log(\min(m, n)))$, cut the smaller array at $i$ and derive $j = \text{target} - i$. Balance is achieved when $L_1 \le R_2$ and $L_2 \le R_1$.

---

## 1. Fundamentals & Boundary Probing
*Focus: Closed-interval invariants, lower/upper bounds, insertion indices, frequency counting, and monotonic integer root finding.*

* **[Problem 1: Binary Search](fundamentals_and_bounds/binary_search_basic.md)** ([C++ Code](fundamentals_and_bounds/binary_search_basic.cpp)): The foundational $O(\log N)$ closed-interval $[left, right]$ halving algorithm with overflow prevention.
* **[Problem 2: Lower Bound](fundamentals_and_bounds/lower_bound.md)** ([C++ Code](fundamentals_and_bounds/lower_bound.cpp)): Smallest index where $arr[idx] \ge target$, with both iterative search and `std::lower_bound`.
* **[Problem 3: Upper Bound](fundamentals_and_bounds/upper_bound.md)** ([C++ Code](fundamentals_and_bounds/upper_bound.cpp)): Smallest index where $arr[idx] > target$, with both iterative search and `std::upper_bound`.
* **[Problem 4: Floor and Ceil in Sorted Array](fundamentals_and_bounds/floor_and_ceil_in_sorted_array.md)** ([C++ Code](fundamentals_and_bounds/floor_and_ceil_in_sorted_array.cpp)): Dual binary search identifying the largest element $\le x$ and smallest element $\ge x$.
* **[Problem 5: Search Insert Position](fundamentals_and_bounds/search_insert_position.md)** ([C++ Code](fundamentals_and_bounds/search_insert_position.cpp)): Direct index lower bound mapping where loop termination leaves `left` at the exact insertion point.
* **[Problem 6: Find First and Last Position of Element](fundamentals_and_bounds/find_first_and_last_position.md)** ([C++ Code](fundamentals_and_bounds/find_first_and_last_position.cpp)): Exact implementations of Lower Bound and Upper Bound isolating duplicate contiguous ranges in $O(\log N)$.
* **[Problem 7: Count Occurrences in a Sorted Array](fundamentals_and_bounds/count_occurrences_in_sorted_array.md)** ([C++ Code](fundamentals_and_bounds/count_occurrences_in_sorted_array.cpp)): Optimal $O(\log N)$ frequency calculation via bound subtraction: $\text{upper\_bound} - \text{lower\_bound}$.
* **[Problem 8: Sqrt(x)](fundamentals_and_bounds/sqrt_x.md)** ([C++ Code](fundamentals_and_bounds/sqrt_x.cpp)): Monotonic function range search on $[1, x/2]$ utilizing 64-bit arithmetic to prevent intermediate overflow.

---

## 2. Rotated & Unimodal Arrays
*Focus: Identifying sorted partitions, handling duplicate ambiguities, rotation count detection, and local slope gradients.*

* **[Problem 9: Search in Rotated Sorted Array I](rotated_and_unimodal_arrays/search_in_rotated_sorted_array_i.md)** ([C++ Code](rotated_and_unimodal_arrays/search_in_rotated_sorted_array_i.cpp)): Proving that at least one half is always sorted, enabling deterministic half-elimination in $O(\log N)$.
* **[Problem 10: Search in Rotated Sorted Array II](rotated_and_unimodal_arrays/search_in_rotated_sorted_array_ii.md)** ([C++ Code](rotated_and_unimodal_arrays/search_in_rotated_sorted_array_ii.cpp)): Resolving duplicate boundary ambiguity ($nums[L] == nums[M] == nums[R]$) via two-pointer shrinkage.
* **[Problem 11: Find Minimum in Rotated Sorted Array](rotated_and_unimodal_arrays/find_minimum_in_rotated_sorted_array.md)** ([C++ Code](rotated_and_unimodal_arrays/find_minimum_in_rotated_sorted_array.cpp)): Pivot inflection point detection comparing `nums[mid]` against `nums[right]`.
* **[Problem 12: Find Rotation Count](rotated_and_unimodal_arrays/find_rotation_count.md)** ([C++ Code](rotated_and_unimodal_arrays/find_rotation_count.cpp)): Determining how many times a sorted array has been rotated by finding the index of the minimum element in $O(\log N)$.
* **[Problem 13: Find Peak Element](rotated_and_unimodal_arrays/find_peak_element.md)** ([C++ Code](rotated_and_unimodal_arrays/find_peak_element.cpp)): Local gradient slope test ($nums[mid] < nums[mid + 1]$) navigating uphill slopes toward guaranteed peaks.

---

## 3. Binary Search on Answer (Monotonic Predicates)
*Focus: Minimax optimization, greedy feasibility functions, integer roots, capacity planning, and allocation problems.*

* **[Problem 14: Find Nth Root of a Number](binary_search_on_answer/nth_root_of_a_number.md)** ([C++ Code](binary_search_on_answer/nth_root_of_a_number.cpp)): Monotonic search on base space $[1, M]$ with term-by-term early overflow termination.
* **[Problem 15: Find the Smallest Divisor](binary_search_on_answer/find_smallest_divisor.md)** ([C++ Code](binary_search_on_answer/find_smallest_divisor.cpp)): Minimizing divisor $d \in [1, \max(nums)]$ such that sum of ceilings $\le \text{threshold}$.
* **[Problem 16: Koko Eating Bananas](binary_search_on_answer/koko_eating_bananas.md)** ([C++ Code](binary_search_on_answer/koko_eating_bananas.cpp)): Minimizing speed $k \in [1, \max]$ with ceiling division hours verification.
* **[Problem 17: Minimum Days to Make m Bouquets](binary_search_on_answer/min_days_to_make_bouquets.md)** ([C++ Code](binary_search_on_answer/min_days_to_make_bouquets.cpp)): Adjacent flower cluster counting across bloom timeline in $O(N \log(\max - \min))$.
* **[Problem 18: Capacity To Ship Packages Within D Days](binary_search_on_answer/capacity_to_ship_packages.md)** ([C++ Code](binary_search_on_answer/capacity_to_ship_packages.cpp)): Minimizing conveyor capacity in search range $[\max(w), \sum w]$.
* **[Problem 19: Kth Missing Positive Number](binary_search_on_answer/kth_missing_positive_number.md)** ([C++ Code](binary_search_on_answer/kth_missing_positive_number.cpp)): Binary search on monotonic missing count function $\text{arr}[i] - (i + 1)$ running in optimal $O(\log N)$ time.
* **[Problem 20: Painter's Partition](binary_search_on_answer/painters_partition.md)** ([C++ Code](binary_search_on_answer/painters_partition.cpp)): Minimizing maximum contiguous board length assigned to any of $K$ painters in $O(N \log(\sum \text{boards}))$.
* **[Problem 21: Book Allocation Problem](binary_search_on_answer/book_allocation_problem.md)** ([C++ Code](binary_search_on_answer/book_allocation_problem.cpp)): Classic page allocation minimizing the maximum pages per student with contiguous constraints.
* **[Problem 22: Aggressive Cows](binary_search_on_answer/aggressive_cows.md)** ([C++ Code](binary_search_on_answer/aggressive_cows.cpp)): Maximizing the minimum pairwise distance between $K$ cows in sorted stalls.
* **[Problem 23: Magnetic Force Between Two Balls](binary_search_on_answer/magnetic_force_between_balls.md)** ([C++ Code](binary_search_on_answer/magnetic_force_between_balls.cpp)): Aggressive Cows archetype maximizing minimum force across coordinate baskets in $O(N \log N + N \log(\max - \min))$.
* **[Problem 24: Split Array Largest Sum](binary_search_on_answer/split_array_largest_sum.md)** ([C++ Code](binary_search_on_answer/split_array_largest_sum.cpp)): The minimax partition problem minimizing maximum subarray sum into $k$ splits.

---

## 4. Matrix Binary Search
*Focus: Virtual 1D index mapping, saddleback corner traversals, 2D peak bisection, and value-space counting.*

* **[Problem 25: Row with Maximum 1's](matrix_binary_search/row_with_max_ones.md)** ([C++ Code](matrix_binary_search/row_with_max_ones.cpp)): Optimal $O(N + M)$ top-right saddleback staircase search and $O(N \log M)$ binary search lower bound.
* **[Problem 26: Search a 2D Matrix I](matrix_binary_search/search_a_2d_matrix_i.md)** ([C++ Code](matrix_binary_search/search_a_2d_matrix_i.cpp)): Virtual 1D flattening mapping $mid \to (mid / n, mid \% n)$ achieving $O(\log(m \cdot n))$ search.
* **[Problem 27: Search a 2D Matrix II](matrix_binary_search/search_a_2d_matrix_ii.md)** ([C++ Code](matrix_binary_search/search_a_2d_matrix_ii.cpp)): Top-right saddleback staircase search eliminating an entire row or column per step in $O(m + n)$.
* **[Problem 28: Find Peak Element II](matrix_binary_search/find_peak_element_ii.md)** ([C++ Code](matrix_binary_search/find_peak_element_ii.cpp)): Column-bisection binary search finding a 2D peak strictly greater than all 4 neighbors in $O(m \log n)$ time.
* **[Problem 29: Matrix Median](matrix_binary_search/matrix_median.md)** ([C++ Code](matrix_binary_search/matrix_median.cpp)): Value-space binary search counting elements $\le mid$ across row-wise sorted rows in $O(R \log C \cdot \log(\max - \min))$.
* **[Problem 30: Kth Smallest Element in a Sorted Matrix](matrix_binary_search/kth_smallest_in_sorted_matrix.md)** ([C++ Code](matrix_binary_search/kth_smallest_in_sorted_matrix.cpp)): Binary search on value space $[matrix[0][0], matrix[n-1][n-1]]$ paired with $O(n)$ staircase counting.

---

## 5. Multi-Array & Partition Search
*Focus: Dual-array balanced cuts, median proofs, and general $k$-th element selection.*

* **[Problem 31: Median of Two Sorted Arrays](multi_array_and_partitions/median_of_two_sorted_arrays.md)** ([C++ Code](multi_array_and_partitions/median_of_two_sorted_arrays.cpp)): Binary search on partition cut in the shorter array achieving optimal $O(\log(\min(m, n)))$ time.
* **[Problem 32: K-th Element of Two Sorted Arrays](multi_array_and_partitions/kth_element_of_two_sorted_arrays.md)** ([C++ Code](multi_array_and_partitions/kth_element_of_two_sorted_arrays.cpp)): Clamped boundary partition search $i \in [\max(0, k - n), \min(k, m)]$ finding $k$-th element in $O(\log(\min(m, n)))$.

---

## 6. Advanced & Real-Number Search
*Focus: Window boundary binary search, floating-point precision loops, and index parity invariants.*

* **[Problem 33: Find K Closest Elements](advanced_and_real_number_search/find_k_closest_elements.md)** ([C++ Code](advanced_and_real_number_search/find_k_closest_elements.cpp)): Binary search on the starting index of the window in $O(\log(N - k) + k)$ optimal time.
* **[Problem 34: Minimize Max Distance to Gas Station](advanced_and_real_number_search/minimize_max_distance_to_gas_station.md)** ([C++ Code](advanced_and_real_number_search/minimize_max_distance_to_gas_station.cpp)): Continuous real-number binary search iterating to achieve $10^{-6}$ decimal precision.
* **[Problem 35: Single Element in a Sorted Array](advanced_and_real_number_search/single_element_in_sorted_array.md)** ([C++ Code](advanced_and_real_number_search/single_element_in_sorted_array.cpp)): Even-odd index pair parity disruption detection in $O(\log N)$ time and $O(1)$ space.

---

## Quick Reference Summary Table

| Category | Problem | Time Complexity | Auxiliary Space | Core Invariant / Pattern |
| :--- | :--- | :--- | :--- | :--- |
| **Fundamentals** | [Binary Search](fundamentals_and_bounds/binary_search_basic.md) | $O(\log N)$ | $O(1)$ | Closed interval $[L, R]$ halving |
| **Fundamentals** | [Lower Bound](fundamentals_and_bounds/lower_bound.md) | $O(\log N)$ | $O(1)$ | Smallest index where $arr[idx] \ge target$ |
| **Fundamentals** | [Upper Bound](fundamentals_and_bounds/upper_bound.md) | $O(\log N)$ | $O(1)$ | Smallest index where $arr[idx] > target$ |
| **Fundamentals** | [Floor and Ceil in Sorted Array](fundamentals_and_bounds/floor_and_ceil_in_sorted_array.md) | $O(\log N)$ | $O(1)$ | Largest $\le x$ and smallest $\ge x$ |
| **Fundamentals** | [Search Insert Position](fundamentals_and_bounds/search_insert_position.md) | $O(\log N)$ | $O(1)$ | Lower bound termination invariant |
| **Fundamentals** | [First & Last Position](fundamentals_and_bounds/find_first_and_last_position.md) | $O(\log N)$ | $O(1)$ | Lower & Upper bound range isolation |
| **Fundamentals** | [Count Occurrences](fundamentals_and_bounds/count_occurrences_in_sorted_array.md) | $O(\log N)$ | $O(1)$ | $\text{upper\_bound} - \text{lower\_bound}$ |
| **Fundamentals** | [Sqrt(x)](fundamentals_and_bounds/sqrt_x.md) | $O(\log x)$ | $O(1)$ | Monotonic integer square root |
| **Rotated Arrays** | [Search Rotated Array I](rotated_and_unimodal_arrays/search_in_rotated_sorted_array_i.md) | $O(\log N)$ | $O(1)$ | Sorted half boundary check |
| **Rotated Arrays** | [Search Rotated Array II](rotated_and_unimodal_arrays/search_in_rotated_sorted_array_ii.md) | $O(\log N)$ avg | $O(1)$ | Duplicate boundary shrinkage |
| **Rotated Arrays** | [Find Minimum in Rotated Array](rotated_and_unimodal_arrays/find_minimum_in_rotated_sorted_array.md) | $O(\log N)$ | $O(1)$ | Pivot inflection point detection |
| **Rotated Arrays** | [Find Rotation Count](rotated_and_unimodal_arrays/find_rotation_count.md) | $O(\log N)$ | $O(1)$ | Index of minimum element |
| **Rotated Arrays** | [Find Peak Element](rotated_and_unimodal_arrays/find_peak_element.md) | $O(\log N)$ | $O(1)$ | Local gradient uphill slope navigation |
| **Binary Search on Answer** | [Find Nth Root](binary_search_on_answer/nth_root_of_a_number.md) | $O(N \log M)$ | $O(1)$ | Monotonic base search with overflow guard |
| **Binary Search on Answer** | [Find Smallest Divisor](binary_search_on_answer/find_smallest_divisor.md) | $O(N \log(\max))$ | $O(1)$ | Monotonic sum of division ceilings |
| **Binary Search on Answer** | [Koko Eating Bananas](binary_search_on_answer/koko_eating_bananas.md) | $O(N \log(\max))$ | $O(1)$ | Rate feasibility check |
| **Binary Search on Answer** | [Min Days for Bouquets](binary_search_on_answer/min_days_to_make_bouquets.md) | $O(N \log(\max - \min))$ | $O(1)$ | Bloom timeline window clustering |
| **Binary Search on Answer** | [Capacity to Ship Packages](binary_search_on_answer/capacity_to_ship_packages.md) | $O(N \log(\sum - \max))$ | $O(1)$ | Conveyor partition capacity search |
| **Binary Search on Answer** | [Kth Missing Positive Number](binary_search_on_answer/kth_missing_positive_number.md) | $O(\log N)$ | $O(1)$ | Monotonic missing count: $arr[i] - (i + 1)$ |
| **Binary Search on Answer** | [Painter's Partition](binary_search_on_answer/painters_partition.md) | $O(N \log(\sum))$ | $O(1)$ | Minimax board workload minimization |
| **Binary Search on Answer** | [Book Allocation Problem](binary_search_on_answer/book_allocation_problem.md) | $O(N \log(\sum))$ | $O(1)$ | Minimax pages per student allocation |
| **Binary Search on Answer** | [Aggressive Cows](binary_search_on_answer/aggressive_cows.md) | $O(N \log N + N \log(\Delta))$ | $O(1)$ | Maximizing minimum stall spacing |
| **Binary Search on Answer** | [Magnetic Force Between Balls](binary_search_on_answer/magnetic_force_between_balls.md) | $O(N \log N + N \log(\Delta))$ | $O(1)$ | Basket placement force maximization |
| **Binary Search on Answer** | [Split Array Largest Sum](binary_search_on_answer/split_array_largest_sum.md) | $O(N \log(\sum))$ | $O(1)$ | Minimax contiguous subarray sum |
| **Matrix Search** | [Row with Maximum 1's](matrix_binary_search/row_with_max_ones.md) | $O(N + M)$ | $O(1)$ | Saddleback staircase elimination |
| **Matrix Search** | [Search a 2D Matrix I](matrix_binary_search/search_a_2d_matrix_i.md) | $O(\log(M \cdot N))$ | $O(1)$ | Virtual 1D index mapping |
| **Matrix Search** | [Search a 2D Matrix II](matrix_binary_search/search_a_2d_matrix_ii.md) | $O(M + N)$ | $O(1)$ | Top-right saddleback staircase search |
| **Matrix Search** | [Find Peak Element II](matrix_binary_search/find_peak_element_ii.md) | $O(M \log N)$ | $O(1)$ | Column-bisection 2D peak search |
| **Matrix Search** | [Matrix Median](matrix_binary_search/matrix_median.md) | $O(R \log C \cdot \log(\Delta))$ | $O(1)$ | Value-space binary search + upper_bound |
| **Matrix Search** | [Kth Smallest in Matrix](matrix_binary_search/kth_smallest_in_sorted_matrix.md) | $O(N \log(\Delta))$ | $O(1)$ | Value-space binary search + staircase |
| **Partitions** | [Median of Two Sorted Arrays](multi_array_and_partitions/median_of_two_sorted_arrays.md) | $O(\log(\min(M, N)))$ | $O(1)$ | Balanced dual-partition cut |
| **Partitions** | [K-th Element of Two Arrays](multi_array_and_partitions/kth_element_of_two_sorted_arrays.md) | $O(\log(\min(M, N)))$ | $O(1)$ | Clamped dual-array partition cut |
| **Advanced Search** | [Find K Closest Elements](advanced_and_real_number_search/find_k_closest_elements.md) | $O(\log(N - k) + k)$ | $O(1)$ | Sliding window start-index binary search |
| **Advanced Search** | [Gas Station Distance](advanced_and_real_number_search/minimize_max_distance_to_gas_station.md) | $O(N \log(\text{Range}/\epsilon))$ | $O(1)$ | Continuous floating-point precision |
| **Advanced Search** | [Single Element in Sorted Array](advanced_and_real_number_search/single_element_in_sorted_array.md) | $O(\log N)$ | $O(1)$ | Even-odd index pair parity disruption |
