# Binary Search Master Roadmap & Problem Sheet

Welcome to the **Binary Search Algorithms & Discrete Decision Search** paradigm. While often introduced as a simple search across a sorted array, Binary Search is in reality a universal mathematical strategy: **reducing any search space of monotonic states by half at each step**.

Mastering binary search requires seeing beyond simple array index lookups to:
1. **The Halving & Boundary Invariant:** Eliminating half the search space with guaranteed termination (`left <= right` vs `left < right`).
2. **Predicate Monotonicity ($P(x) \implies P(x+1)$):** Binary search on the answer space when direct construction is hard but verification is polynomial ($O(N)$ or $O(1)$).
3. **Rotated & Discontinuous Monotonicity:** Preserving $O(\log N)$ by identifying which half retains strict sorting.
4. **Partition Search (Dual-Array Medians):** Simultaneously binary searching partition cuts across two independent sorted streams.
5. **Continuous / Real-Number Search:** Finding floating-point extrema within precision thresholds ($\epsilon = 10^{-6}$).

This sheet organizes **21 high-frequency problems** across **6 core patterns** tested in top-tier technical assessments.

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
*Focus: Closed-interval invariants, lower/upper bounds, insertion indices, and monotonic integer root finding.*

* **[Problem 1: Binary Search](fundamentals_and_bounds/binary_search_basic.md)** ([C++ Code](fundamentals_and_bounds/binary_search_basic.cpp)): The foundational $O(\log N)$ closed-interval $[left, right]$ halving algorithm with overflow prevention.
* **[Problem 2: Find First and Last Position of Element](fundamentals_and_bounds/find_first_and_last_position.md)** ([C++ Code](fundamentals_and_bounds/find_first_and_last_position.cpp)): Exact implementations of Lower Bound and Upper Bound isolating duplicate contiguous ranges in $O(\log N)$.
* **[Problem 3: Search Insert Position](fundamentals_and_bounds/search_insert_position.md)** ([C++ Code](fundamentals_and_bounds/search_insert_position.cpp)): Direct index lower bound mapping where loop termination leaves `left` at the exact insertion point.
* **[Problem 4: Sqrt(x)](fundamentals_and_bounds/sqrt_x.md)** ([C++ Code](fundamentals_and_bounds/sqrt_x.cpp)): Monotonic function range search on $[1, x/2]$ utilizing 64-bit arithmetic to prevent intermediate overflow.

---

## 2. Rotated & Unimodal Arrays
*Focus: Identifying sorted partitions, handling duplicate ambiguities, and local slope gradients.*

* **[Problem 5: Search in Rotated Sorted Array I](rotated_and_unimodal_arrays/search_in_rotated_sorted_array_i.md)** ([C++ Code](rotated_and_unimodal_arrays/search_in_rotated_sorted_array_i.cpp)): Proving that at least one half is always sorted, enabling deterministic half-elimination in $O(\log N)$.
* **[Problem 6: Search in Rotated Sorted Array II](rotated_and_unimodal_arrays/search_in_rotated_sorted_array_ii.md)** ([C++ Code](rotated_and_unimodal_arrays/search_in_rotated_sorted_array_ii.cpp)): Resolving duplicate boundary ambiguity ($nums[L] == nums[M] == nums[R]$) via two-pointer shrinkage.
* **[Problem 7: Find Minimum in Rotated Sorted Array](rotated_and_unimodal_arrays/find_minimum_in_rotated_sorted_array.md)** ([C++ Code](rotated_and_unimodal_arrays/find_minimum_in_rotated_sorted_array.cpp)): Pivot inflection point detection comparing `nums[mid]` against `nums[right]`.
* **[Problem 8: Find Peak Element](rotated_and_unimodal_arrays/find_peak_element.md)** ([C++ Code](rotated_and_unimodal_arrays/find_peak_element.cpp)): Local gradient slope test ($nums[mid] < nums[mid + 1]$) navigating uphill slopes toward guaranteed peaks.

---

## 3. Binary Search on Answer (Monotonic Predicates)
*Focus: Minimax optimization, greedy feasibility functions, and capacity planning.*

* **[Problem 9: Koko Eating Bananas](binary_search_on_answer/koko_eating_bananas.md)** ([C++ Code](binary_search_on_answer/koko_eating_bananas.cpp)): Minimizing rate $k \in [1, \max]$ with ceiling division hours verification.
* **[Problem 10: Capacity To Ship Packages Within D Days](binary_search_on_answer/capacity_to_ship_packages.md)** ([C++ Code](binary_search_on_answer/capacity_to_ship_packages.cpp)): Minimizing conveyor capacity in search range $[\max(w), \sum w]$.
* **[Problem 11: Split Array Largest Sum](binary_search_on_answer/split_array_largest_sum.md)** ([C++ Code](binary_search_on_answer/split_array_largest_sum.cpp)): The classic Painter's Partition / Book Allocation problem minimizing maximum subarray sum.
* **[Problem 12: Magnetic Force Between Two Balls](binary_search_on_answer/magnetic_force_between_balls.md)** ([C++ Code](binary_search_on_answer/magnetic_force_between_balls.cpp)): Aggressive Cows archetype maximizing the minimum pairwise distance across sorted baskets.
* **[Problem 13: Minimum Days to Make m Bouquets](binary_search_on_answer/min_days_to_make_bouquets.md)** ([C++ Code](binary_search_on_answer/min_days_to_make_bouquets.cpp)): Adjacent flower cluster counting across bloom timeline.

---

## 4. Matrix Binary Search
*Focus: Virtual 1D index mapping, saddleback corner traversals, and value-space counting.*

* **[Problem 14: Search a 2D Matrix I](matrix_binary_search/search_a_2d_matrix_i.md)** ([C++ Code](matrix_binary_search/search_a_2d_matrix_i.cpp)): Virtual 1D flattening mapping $mid \to (mid / n, mid \% n)$ achieving $O(\log(m \cdot n))$ search.
* **[Problem 15: Search a 2D Matrix II](matrix_binary_search/search_a_2d_matrix_ii.md)** ([C++ Code](matrix_binary_search/search_a_2d_matrix_ii.cpp)): Top-right saddleback staircase search eliminating an entire row or column per step in $O(m + n)$.
* **[Problem 16: Kth Smallest Element in a Sorted Matrix](matrix_binary_search/kth_smallest_in_sorted_matrix.md)** ([C++ Code](matrix_binary_search/kth_smallest_in_sorted_matrix.cpp)): Binary search on value space $[matrix[0][0], matrix[n-1][n-1]]$ paired with $O(n)$ staircase counting.

---

## 5. Multi-Array & Partition Search
*Focus: Dual-array balanced cuts, median proofs, and general $k$-th element selection.*

* **[Problem 17: Median of Two Sorted Arrays](multi_array_and_partitions/median_of_two_sorted_arrays.md)** ([C++ Code](multi_array_and_partitions/median_of_two_sorted_arrays.cpp)): Binary search on partition cut in the shorter array achieving optimal $O(\log(\min(m, n)))$ time.
* **[Problem 18: K-th Element of Two Sorted Arrays](multi_array_and_partitions/kth_element_of_two_sorted_arrays.md)** ([C++ Code](multi_array_and_partitions/kth_element_of_two_sorted_arrays.cpp)): Clamped boundary partition search $i \in [\max(0, k - n), \min(k, m)]$ finding $k$-th element in $O(\log(\min(m, n)))$.

---

## 6. Advanced & Real-Number Search
*Focus: Window boundary binary search, floating-point precision loops, and index parity invariants.*

* **[Problem 19: Find K Closest Elements](advanced_and_real_number_search/find_k_closest_elements.md)** ([C++ Code](advanced_and_real_number_search/find_k_closest_elements.cpp)): Binary search on the starting index of the window in $O(\log(N - k) + k)$ optimal time.
* **[Problem 20: Minimize Max Distance to Gas Station](advanced_and_real_number_search/minimize_max_distance_to_gas_station.md)** ([C++ Code](advanced_and_real_number_search/minimize_max_distance_to_gas_station.cpp)): Continuous real-number binary search iterating to achieve $10^{-6}$ decimal precision.
* **[Problem 21: Single Element in a Sorted Array](advanced_and_real_number_search/single_element_in_sorted_array.md)** ([C++ Code](advanced_and_real_number_search/single_element_in_sorted_array.cpp)): Even-odd index pair parity disruption detection in $O(\log N)$ time and $O(1)$ space.

---

## Quick Reference Summary Table

| Category | Problem | Time | Space | Core Invariant / Pattern |
| :--- | :--- | :--- | :--- | :--- |
| **Fundamentals** | [Binary Search](fundamentals_and_bounds/binary_search_basic.md) | $O(\log N)$ | $O(1)$ | Closed interval $[L, R]$ halving |
| **Fundamentals** | [First & Last Position](fundamentals_and_bounds/find_first_and_last_position.md) | $O(\log N)$ | $O(1)$ | Lower & Upper bound templates |
| **Fundamentals** | [Search Insert Position](fundamentals_and_bounds/search_insert_position.md) | $O(\log N)$ | $O(1)$ | Lower bound termination invariant |
| **Fundamentals** | [Sqrt(x)](fundamentals_and_bounds/sqrt_x.md) | $O(\log x)$ | $O(1)$ | Monotonic integer square root |
| **Rotated Arrays** | [Search Rotated Array I](rotated_and_unimodal_arrays/search_in_rotated_sorted_array_i.md) | $O(\log N)$ | $O(1)$ | Sorted half boundary check |
| **Rotated Arrays** | [Search Rotated Array II](rotated_and_unimodal_arrays/search_in_rotated_sorted_array_ii.md) | $O(\log N)$ avg | $O(1)$ | Duplicate boundary shrinkage |
| **Rotated Arrays** | [Find Minimum Rotated](rotated_and_unimodal_arrays/find_minimum_in_rotated_sorted_array.md) | $O(\log N)$ | $O(1)$ | Inflection test against `nums[right]` |
| **Rotated Arrays** | [Find Peak Element](rotated_and_unimodal_arrays/find_peak_element.md) | $O(\log N)$ | $O(1)$ | Local gradient uphill navigation |
| **On Answer** | [Koko Eating Bananas](binary_search_on_answer/koko_eating_bananas.md) | $O(N \log M)$ | $O(1)$ | Ceiling division hours check |
| **On Answer** | [Capacity to Ship Packages](binary_search_on_answer/capacity_to_ship_packages.md) | $O(N \log \sum)$ | $O(1)$ | Greedy days simulation $[\max, \sum]$ |
| **On Answer** | [Split Array Largest Sum](binary_search_on_answer/split_array_largest_sum.md) | $O(N \log \sum)$ | $O(1)$ | Painter's Partition minimax search |
| **On Answer** | [Magnetic Force Balls](binary_search_on_answer/magnetic_force_between_balls.md) | $O(N \log N)$ | $O(1)$ | Aggressive Cows max-min distance |
| **On Answer** | [Make m Bouquets](binary_search_on_answer/min_days_to_make_bouquets.md) | $O(N \log M)$ | $O(1)$ | Consecutive adjacent flower clusters |
| **Matrix** | [Search 2D Matrix I](matrix_binary_search/search_a_2d_matrix_i.md) | $O(\log(MN))$ | $O(1)$ | Virtual 1D flattening $(mid/n, mid\%n)$ |
| **Matrix** | [Search 2D Matrix II](matrix_binary_search/search_a_2d_matrix_ii.md) | $O(M + N)$ | $O(1)$ | Top-right saddleback staircase |
| **Matrix** | [Kth Smallest in Matrix](matrix_binary_search/kth_smallest_in_sorted_matrix.md) | $O(N \log \Delta)$ | $O(1)$ | Value space search + staircase counting |
| **Multi-Array** | [Median of Two Arrays](multi_array_and_partitions/median_of_two_sorted_arrays.md) | $O(\log(\min(M, N)))$ | $O(1)$ | Balanced dual-array partition cuts |
| **Multi-Array** | [Kth of Two Arrays](multi_array_and_partitions/kth_element_of_two_sorted_arrays.md) | $O(\log(\min(M, N)))$ | $O(1)$ | Clamped boundary $k$-th selection |
| **Advanced** | [Find K Closest Elements](advanced_and_real_number_search/find_k_closest_elements.md) | $O(\log(N-k) + k)$ | $O(1)$ | Binary search on window left bound |
| **Advanced** | [Gas Station Max Distance](advanced_and_real_number_search/minimize_max_distance_to_gas_station.md) | $O(N \log(1/\epsilon))$ | $O(1)$ | Continuous real-number precision loop |
| **Advanced** | [Single Element Sorted](advanced_and_real_number_search/single_element_in_sorted_array.md) | $O(\log N)$ | $O(1)$ | Even-odd index pair parity disruption |

