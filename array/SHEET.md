# Arrays Master Roadmap & Problem Sheet

Welcome to the **Array Algorithms** paradigm. Arrays are the bedrock of all data structures. While conceptually simple, technical assessments frequently utilize arrays to evaluate **asymptotic optimization, pointer invariants, mathematical deductions, bitwise manipulation, and in-place transformations**.

This sheet organizes **24 high-frequency problems** across **7 core patterns** tested in top-tier coding assessments.

---

## The Core Paradigms of Array Engineering

1. **Two Pointers & In-Place Elimination:**
   - **Convergent Pointers:** On sorted arrays, shrink the boundary opposite to the bottleneck ($L++$ or $R--$) in strictly $O(N)$ time.
   - **Reader & Writer Pointers:** For in-place element filtering/compaction, use a slow `writer` pointer that only advances when a valid non-target element is swapped in.
2. **Prefix Sums & Difference Arrays:**
   - Subarray sums map to prefix differences: $\text{sum}(i \dots j) = \text{prefix}[j] - \text{prefix}[i - 1]$. Hash maps enable $O(1)$ lookup for target sums or remainder congruences.
   - For offline range additions $[L, R, +V]$, apply $O(1)$ boundary markers $+V$ at $L$ and $-V$ at $R + 1$, then take a single prefix sum pass.
3. **Monotonic Deques & Sliding Windows:**
   - For sliding window extrema of size $K$, store indices in a `deque` ordered strictly monotonically. Each element enters and exits at most once for $O(N)$ amortized time.
4. **Kadane's Algorithm & Sign Flips:**
   - For maximum subarray sums, discard negative prefixes: $\text{curr} = \max(\text{num}, \text{curr} + \text{num})$. For products, track both `min` and `max` to handle negative sign flips.
5. **Matrix Invariants ($O(1)$ Auxiliary Space):**
   - Rotating an image $90^\circ$ clockwise equals **Transpose** followed by **Horizontal Row Reversal**.
   - Zeroing matrices in $O(1)$ space uses the 1st row and 1st column as the flag registers.
6. **Partitioning & Voting:**
   - **Dutch National Flag:** 3-way partitioning dividing an array into $<, ==, >$ regions in a single pass.
   - **Boyer-Moore Voting:** Candidate battle cancellation isolating the majority element in $O(N)$ time and $O(1)$ space.

---

## 1. Two Pointers & In-Place Compaction
*Focus: Convergent boundary scanning, bottleneck elimination, and reader/writer in-place swapping.*

* **[Problem 1: Two Sum II - Input Array Is Sorted](two_pointers_and_in_place/two_sum_ii_input_array_sorted.md)** ([C++ Code](two_pointers_and_in_place/two_sum_ii_input_array_sorted.cpp)): Convergent two-pointer search on monotonically sorted arrays in $O(N)$ time and $O(1)$ space.
* **[Problem 2: 3Sum](two_pointers_and_in_place/three_sum.md)** ([C++ Code](two_pointers_and_in_place/three_sum.cpp)): Sorting plus fixed pivot two-pointer search with aggressive duplicate skipping.
* **[Problem 3: Container With Most Water](two_pointers_and_in_place/container_with_most_water.md)** ([C++ Code](two_pointers_and_in_place/container_with_most_water.cpp)): Proof of shrinking the shorter boundary to optimize $(R - L) \times \min(H_L, H_R)$.
* **[Problem 4: Move Zeroes](two_pointers_and_in_place/move_zeroes.md)** ([C++ Code](two_pointers_and_in_place/move_zeroes.cpp)): In-place reader and writer pointer swapping preserving relative order of non-zeroes.
* **[Problem 5: Max Consecutive Ones](two_pointers_and_in_place/max_consecutive_ones.md)** ([C++ Code](two_pointers_and_in_place/max_consecutive_ones.cpp)): Single-pass linear state machine tracking continuous runs.

---

## 2. Prefix Sum & Difference Array
*Focus: Range queries, zero-cost range updates, and hash-based remainder congruences.*

* **[Problem 6: Subarray Sum Equals K](prefix_sum_and_difference_array/subarray_sum_equals_k.md)** ([C++ Code](prefix_sum_and_difference_array/subarray_sum_equals_k.cpp)): Prefix sum frequency hash map identifying target differences $(\text{curr} - k)$ in $O(N)$ time.
* **[Problem 7: Continuous Subarray Sum](prefix_sum_and_difference_array/continuous_subarray_sum.md)** ([C++ Code](prefix_sum_and_difference_array/continuous_subarray_sum.cpp)): Modulo remainder hashing with earliest index tracking enforcing length $\ge 2$.
* **[Problem 8: Range Addition / Difference Array](prefix_sum_and_difference_array/range_addition.md)** ([C++ Code](prefix_sum_and_difference_array/range_addition.cpp)): Difference array boundary tagging transforming $O(K \times N)$ updates into $O(N + K)$ prefix recovery.
* **[Problem 9: Divisible Sum and Difference Pairs](prefix_sum_and_difference_array/divisible_sum_diff_pairs.md)** ([C++ Code](prefix_sum_and_difference_array/divisible_sum_diff_pairs.cpp)): Dual modulo remainder pairing solving $(a + b) \pmod D == 0$ and $|a - b| \pmod M == 0$.

---

## 3. Sliding Window
*Focus: Monotonic queue maintenance, value-bounded frequency buckets, and coordinate compression.*

* **[Problem 10: Sliding Window Maximum](sliding_window/sliding_window_maximum.md)** ([C++ Code](sliding_window/sliding_window_maximum.cpp)): Monotonic decreasing deque maintaining candidate maxima in $O(N)$ amortized time.
* **[Problem 11: Sliding Subarray Beauty](sliding_window/sliding_subarray_beauty.md)** ([C++ Code](sliding_window/sliding_subarray_beauty.cpp)): Bounded frequency buckets ($[-50, -1]$) tracking the $x^{\text{th}}$ smallest negative number in $O(1)$ space.
* **[Problem 12: Maximum Consecutive Vacation Days](sliding_window/max_consecutive_vacation.md)** ([C++ Code](sliding_window/max_consecutive_vacation.cpp)): Coordinate-compressed sliding window over sorted obligations up to $N = 10^9$.

---

## 4. Subarrays & Kadane's Algorithm
*Focus: Optimal contiguous subarray accumulation, sign flipping, and lexicographical successors.*

* **[Problem 13: Maximum Subarray (Kadane's)](subarrays_and_kadane/maximum_subarray.md)** ([C++ Code](subarrays_and_kadane/maximum_subarray.cpp)): Kadane's dynamic programming reset rule discarding negative accumulated prefixes.
* **[Problem 14: Maximum Product Subarray](subarrays_and_kadane/maximum_product_subarray.md)** ([C++ Code](subarrays_and_kadane/maximum_product_subarray.cpp)): Dual tracking of both `min` and `max` products to handle negative sign inversions.
* **[Problem 15: Next Permutation](subarrays_and_kadane/next_permutation.md)** ([C++ Code](subarrays_and_kadane/next_permutation.cpp)): 3-step pivot detection, smallest larger element swap, and suffix inversion.
* **[Problem 16: Product of Array Except Self](subarrays_and_kadane/product_of_array_except_self.md)** ([C++ Code](subarrays_and_kadane/product_of_array_except_self.cpp)): Prefix and suffix product sweeps achieving $O(1)$ auxiliary memory without division.

---

## 5. Matrix & 2D Arrays
*Focus: 2D spatial transformations, boundary contractions, and register reutilization.*

* **[Problem 17: Rotate Image](matrix_and_2d_arrays/rotate_image.md)** ([C++ Code](matrix_and_2d_arrays/rotate_image.cpp)): In-place $90^\circ$ clockwise rotation via Matrix Transpose + Horizontal Reflection.
* **[Problem 18: Spiral Matrix](matrix_and_2d_arrays/spiral_matrix.md)** ([C++ Code](matrix_and_2d_arrays/spiral_matrix.cpp)): 4-boundary shrinking loop traversing boundaries `top`, `bottom`, `left`, `right`.
* **[Problem 19: Set Matrix Zeroes](matrix_and_2d_arrays/set_matrix_zeroes.md)** ([C++ Code](matrix_and_2d_arrays/set_matrix_zeroes.cpp)): Using the 1st row and 1st column as bit registers for strictly $O(1)$ auxiliary space.

---

## 6. Partitioning & Voting
*Focus: Multi-way array partitioning and majority consensus algorithms.*

* **[Problem 20: Sort Colors / Dutch National Flag](partitioning_and_voting/sort_colors.md)** ([C++ Code](partitioning_and_voting/sort_colors.cpp)): 3-way pointer partitioning (`low`, `mid`, `high`) sorting $\{0, 1, 2\}$ in a single pass.
* **[Problem 21: Majority Element](partitioning_and_voting/majority_element.md)** ([C++ Code](partitioning_and_voting/majority_element.cpp)): Boyer-Moore voting algorithm finding elements appearing $> \lfloor n / 2 \rfloor$ times.
* **[Problem 22: Majority Element II](partitioning_and_voting/majority_element_ii.md)** ([C++ Code](partitioning_and_voting/majority_element_ii.cpp)): Extended Boyer-Moore tracking at most two survivors appearing $> \lfloor n / 3 \rfloor$ times.

---

## 7. Bitwise & Cyclic Arrays
*Focus: Bit contribution independence, cyclic array doubling, and modulo bit summations.*

* **[Problem 23: Maximum Cyclic Prefix XOR Sum](bitwise_and_cyclic_arrays/max_cyclic_prefix_xor_sum.md)** ([C++ Code](bitwise_and_cyclic_arrays/max_cyclic_prefix_xor_sum.cpp)): Cyclic array expansion and prefix XOR evaluation across forward and backward traversals.
* **[Problem 24: Single Number II](bitwise_and_cyclic_arrays/single_number_ii.md)** ([C++ Code](bitwise_and_cyclic_arrays/single_number_ii.cpp)): Bitwise summation modulo 3 isolating a unique element among triplets in $O(1)$ space.

