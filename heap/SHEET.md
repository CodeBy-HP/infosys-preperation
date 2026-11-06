# Heaps & Priority Queues Master Roadmap & Problem Sheet

A **Heap** is a specialized tree-based data structure satisfying the complete binary tree structural invariant and the heap ordering property. It enables $O(1)$ access to the extremal element (minimum or maximum) and $O(\log N)$ updates. Heaps serve as the primary backbone for **Priority Queues**, $K$-way stream merges, sliding window rank statistics, dual-heap running medians, and greedy scheduling.

This roadmap organizes all **20 problems and topics** into **5 foundational algorithmic patterns**.

---

## 1. Heap Internals, Mechanics & Sorting
*Focus: Array-to-tree coordinate mapping, sift operations, linear-time bottom-up construction, and in-place sorting.*

* **[Heap Theory & Architecture](heap_internals_and_sorting/heap_theory.md)**: Pointerless Complete Binary Tree structural property, 0-based and 1-based indexing formulas ($\text{left} = 2i+1, \text{right} = 2i+2, \text{parent} = \lfloor(i-1)/2\rfloor$), heap invariants, and height-bounded complexity proofs.
* **[Heapify Algorithm](heap_internals_and_sorting/heapify_algorithm.md)** ([C++ Code](heap_internals_and_sorting/heapify_algorithm.cpp)): Sift-Down (`heapifyDown`) and Sift-Up (`heapifyUp`) restoring invariants along the tree height in $O(\log N)$ time.
* **[Build Heap from Given Array](heap_internals_and_sorting/build_heap_from_array.md)** ([C++ Code](heap_internals_and_sorting/build_heap_from_array.cpp)): Why bottom-up heapification starting from $\lfloor N/2 \rfloor - 1$ runs in $O(N)$ time instead of $O(N \log N)$, with mathematical Taylor-series proof $\sum_{h=0}^\infty \frac{h}{2^h} = 2$.
* **[Implement Min Heap from Scratch](heap_internals_and_sorting/implement_min_heap.md)** ([C++ Code](heap_internals_and_sorting/implement_min_heap.cpp)): Complete vector-backed class supporting `insert`, `extractMin`, `peek`, `decreaseKey`, and `deleteKey` in $O(\log N)$ time.
* **[Implement Max Heap from Scratch](heap_internals_and_sorting/implement_max_heap.md)** ([C++ Code](heap_internals_and_sorting/implement_max_heap.cpp)): Complete vector-backed class supporting dynamic insertion, extraction, and in-place arbitrary key updates.
* **[Check if an Array Represents a Min Heap](heap_internals_and_sorting/check_if_array_is_min_heap.md)** ([C++ Code](heap_internals_and_sorting/check_if_array_is_min_heap.cpp)): Fast $O(N)$ single-pass parent-child invariant validation on all internal nodes.
* **[Convert Min Heap to Max Heap](heap_internals_and_sorting/convert_min_heap_to_max_heap.md)** ([C++ Code](heap_internals_and_sorting/convert_min_heap_to_max_heap.cpp)): Re-ordering a min-heap array into a valid max-heap in $O(N)$ time using bottom-up max-heapify.
* **[Heap Sort](heap_internals_and_sorting/heap_sort.md)** ([C++ Code](heap_internals_and_sorting/heap_sort.cpp)): In-place, $O(1)$ auxiliary space sorting algorithm achieving guaranteed $O(N \log N)$ worst-case time by repeatedly swapping the root with the boundary.

---

## 2. Top-K & Stream Processing
*Focus: Maintaining a bounded Min-Heap of size $K$ to track running order statistics, sliding windows, and frequency rankings.*

* **[K-th Largest Element in an Array](top_k_and_stream_processing/kth_largest_element_in_array.md)** ([C++ Code](top_k_and_stream_processing/kth_largest_element_in_array.cpp)): Size-$K$ Min-Heap streaming boundary ($O(N \log K)$) vs Hoare's Quickselect with Lomuto/3-way partitioning ($O(N)$ average time, $O(1)$ space).
* **[K-th Largest Element in a Stream of Running Integers](top_k_and_stream_processing/kth_largest_in_stream.md)** ([C++ Code](top_k_and_stream_processing/kth_largest_in_stream.cpp)): Maintaining an active size-$K$ min-heap window to answer streaming $K$-th largest queries in $O(\log K)$ time per addition.
* **[Sort a K-Sorted Array (Nearly Sorted Array)](top_k_and_stream_processing/sort_k_sorted_array.md)** ([C++ Code](top_k_and_stream_processing/sort_k_sorted_array.cpp)): Sliding size-$(K+1)$ min-heap window ensuring every element is extracted to its finalized position in $O(N \log K)$ time.
* **[Top K Frequent Elements](top_k_and_stream_processing/top_k_frequent_elements.md)** ([C++ Code](top_k_and_stream_processing/top_k_frequent_elements.cpp)): Frequency counting followed by a Size-$K$ Min-Heap ($O(N \log K)$) and an optimal $O(N)$ Bucket Sort distribution.
* **[Replace Elements by Their Rank](top_k_and_stream_processing/replace_elements_by_rank.md)** ([C++ Code](top_k_and_stream_processing/replace_elements_by_rank.cpp)): Mapping values to dense ranks using pair-based Min-Heap ordering or coordinate compression in $O(N \log N)$ time and $O(N)$ space.

---

## 3. Multi-Way Merging & Graph/Matrix Frontiers
*Focus: Priority-queue-driven frontier exploration across multiple ordered streams and 2D sorted coordinate spaces.*

* **[Merge K Sorted Lists](multiway_merge_and_frontier/merge_k_sorted_lists.md)** ([C++ Code](multiway_merge_and_frontier/merge_k_sorted_lists.cpp)): Priority-queue-driven $K$-way merge pulling the next smallest node in $O(N \log K)$ time; compared with pairwise Divide & Conquer.
* **[Design Twitter](multiway_merge_and_frontier/design_twitter.md)** ([C++ Code](multiway_merge_and_frontier/design_twitter.cpp)): Scalable social feed architecture pulling the 10 most recent posts across followees via dynamic $K$-way heap merge over user post streams.
* **[Maximum Sum Combination](multiway_merge_and_frontier/maximum_sum_combination.md)** ([C++ Code](multiway_merge_and_frontier/maximum_sum_combination.cpp)): Sorting arrays and running a 2D BFS frontier expansion on index pairs $(i, j)$ via a Max-Heap with visited coordinate deduplication in $O(C \log C)$ time.

---

## 4. Greedy Priority Queue & Scheduling
*Focus: Optimal prefix coding (Huffman reduction), bottleneck relaxation, and resource scheduling under cooldown constraints.*

* **[Minimum Cost to Connect Sticks](greedy_and_scheduling/minimum_cost_to_connect_sticks.md)** ([C++ Code](greedy_and_scheduling/minimum_cost_to_connect_sticks.cpp)): Huffman prefix-code greedy paradigm: repeatedly combining the two smallest sticks via a Min-Heap in $O(N \log N)$ time.
* **[Task Scheduler](greedy_and_scheduling/task_scheduler.md)** ([C++ Code](greedy_and_scheduling/task_scheduler.cpp)): Executing CPU tasks with mandatory cooldown intervals $n$ using a Max-Heap and a Cooldown FIFO queue alongside an optimal closed-form math solution.
* **[Hand of Straights](greedy_and_scheduling/hand_of_straights.md)** ([C++ Code](greedy_and_scheduling/hand_of_straights.cpp)): Grouping consecutive cards into sets of size $W$ using frequency maps and min-element extraction in $O(N \log N)$ time.

---

## 5. Two-Heaps Pattern (Running Partitioning)
*Focus: Dynamically partitioning a dataset into lower and upper halves to maintain order statistics at the split boundary.*

* **[Find Median from Data Stream](two_heaps_pattern/find_median_from_data_stream.md)** ([C++ Code](two_heaps_pattern/find_median_from_data_stream.cpp)): Classic Dual-Heap partition. Balancing a Max-Heap for the lower half and a Min-Heap for the upper half to achieve $O(\log N)$ inserts and $O(1)$ median queries.

---

## Algorithmic Complexity Reference Table

| Pattern | Topic / Problem | Time Complexity | Space Complexity | Core Strategy |
|---|---|---|---|---|
| **Heap Internals** | Heap Theory | — | — | Complete Binary Tree & Index arithmetic |
| **Heap Internals** | Heapify Algorithm | $O(\log N)$ | $O(1)$ | Sift-Down / Sift-Up |
| **Heap Internals** | Build Heap from Array | $O(N)$ | $O(1)$ | Bottom-up sift-down from $\lfloor N/2 \rfloor - 1$ |
| **Heap Internals** | Implement Min Heap | Insert/Extract: $O(\log N)$, Peek: $O(1)$ | $O(N)$ | Vector backing + sift mechanics |
| **Heap Internals** | Implement Max Heap | Insert/Extract: $O(\log N)$, Peek: $O(1)$ | $O(N)$ | Vector backing + sift mechanics |
| **Heap Internals** | Check if Array is Min Heap | $O(N)$ | $O(1)$ | Parent $\le$ Children validation scan |
| **Heap Internals** | Convert Min Heap to Max Heap | $O(N)$ | $O(1)$ | In-place bottom-up max-heapify |
| **Heap Internals** | Heap Sort | $O(N \log N)$ | $O(1)$ | In-place build heap + repetitive root swap |
| **Top-K & Streams** | K-th Largest Element in Array | $O(N \log K)$ heap / $O(N)$ quickselect | $O(K)$ heap / $O(1)$ quickselect | Bounded Min-Heap or Hoare Partitioning |
| **Top-K & Streams** | K-th Largest in Stream | $O(\log K)$ per query | $O(K)$ | Size-$K$ Min-Heap |
| **Top-K & Streams** | Sort K-Sorted Array | $O(N \log K)$ | $O(K)$ | Sliding $(K+1)$-sized Min-Heap |
| **Top-K & Streams** | Top K Frequent Elements | $O(N \log K)$ heap / $O(N)$ bucket sort | $O(N)$ | Size-$K$ Min-Heap or Bucket Sort |
| **Top-K & Streams** | Replace Elements by Rank | $O(N \log N)$ | $O(N)$ | Min-Heap or coordinate compression |
| **Multi-Way Merge** | Merge K Sorted Lists | $O(N \log K)$ | $O(K)$ | Min-Heap storing head pointers |
| **Multi-Way Merge** | Design Twitter | Tweet: $O(1)$, Feed: $O(K \log K)$ | $O(U + T)$ | K-Way priority merge across followees |
| **Multi-Way Merge** | Maximum Sum Combination | $O(C \log C)$ | $O(C)$ | Sort + Max-Heap 2D BFS frontier search |
| **Greedy & Scheduling** | Min Cost to Connect Sticks | $O(N \log N)$ | $O(N)$ | Greedy 2-smallest merge via Min-Heap (Huffman) |
| **Greedy & Scheduling** | Task Scheduler | $O(N \log \Sigma)$ heap / $O(N)$ math | $O(\Sigma)$ where $\Sigma \le 26$ | Max-Heap + Cooldown Queue or Max-Freq Math |
| **Greedy & Scheduling** | Hand of Straights | $O(N \log N)$ | $O(N)$ | Ordered Map / Min-Heap greedy deduction |
| **Two Heaps** | Find Median from Data Stream | Add: $O(\log N)$, Median: $O(1)$ | $O(N)$ | Dual-Heap (Max-Heap lower, Min-Heap upper) |
