# Linked List Master Roadmap & Problem Sheet

Welcome to the **Linked List** algorithmic paradigm. Unlike contiguous arrays, linked lists rely on dynamic memory pointers. Mastering linked lists requires internalizing strict **pointer invariants**, recognizing **structural symmetries**, and avoiding undefined behavior (such as dangling pointers, memory leaks, and cyclic reference traps).

This sheet organizes **25 high-frequency problems** across **9 core patterns** frequently tested in technical assessments and coding interviews.

---

## The Core Invariants of Linked List Engineering

1. **The Sentinel (Dummy) Node Technique:**
   - Always instantiate a dummy head (`ListNode dummy(0); dummy.next = head;`) whenever the head node itself might be modified, deleted, or inserted before. This eliminates edge-case conditionals for empty lists and single-node head shifts.
2. **The Lookahead Rule:**
   - When deleting or swapping nodes, your pointer must always sit at the **preceding node** (`curr->next` is the node being affected).
3. **The Severe & Terminate Rule:**
   - When splitting lists or partitioning chains, you **must explicitly terminate tails with `nullptr`** (`tail->next = nullptr`). Failing to do so creates silent infinite cycles.
4. **Memory Hygiene:**
   - In production C++, always decouple nodes before deleting or use smart pointers. Deleted nodes must not leave dangling references.

---

## 1. Fast & Slow Pointers (Floyd's Tortoise and Hare)
*Focus: Cycle detection, meeting points, finding middle elements, and palindrome verification without extra auxiliary memory.*

* **[Problem 1: Middle of the Linked List](fast_and_slow_pointers/middle_of_the_linked_list.md)** ([C++ Code](fast_and_slow_pointers/middle_of_the_linked_list.cpp)): Floyd's 2-speed traversal. Even vs. odd length termination conditions stopping at upper vs. lower middle in $O(N)$ time and $O(1)$ space.
* **[Problem 2: Linked List Cycle II](fast_and_slow_pointers/linked_list_cycle_ii.md)** ([C++ Code](fast_and_slow_pointers/linked_list_cycle_ii.cpp)): Cycle detection and mathematical proof of entry point collision ($2(L+x) = L+x+nC \implies L = nC - x$).
* **[Problem 3: Palindrome Linked List](fast_and_slow_pointers/palindrome_linked_list.md)** ([C++ Code](fast_and_slow_pointers/palindrome_linked_list.cpp)): 3-phase algorithm (Find middle $\to$ Reverse second half $\to$ Compare & restore) achieving $O(1)$ auxiliary space while preserving original data structure.

---

## 2. In-Place Reversal & Sublist Manipulation
*Focus: Pointer inversion, maintaining predecessor/successor links, and iterative vs. recursive transformations.*

* **[Problem 4: Reverse Linked List](in_place_reversal/reverse_linked_list.md)** ([C++ Code](in_place_reversal/reverse_linked_list.cpp)): Foundational 3-pointer state inversion (`prev`, `curr`, `nextNode`) alongside recursive tail-link formulation.
* **[Problem 5: Reverse Linked List II](in_place_reversal/reverse_linked_list_ii.md)** ([C++ Code](in_place_reversal/reverse_linked_list_ii.cpp)): Subsegment $[left, right]$ reversal in a single pass using the sentinel head-insertion technique.
* **[Problem 6: Reverse Nodes in k-Group](in_place_reversal/reverse_nodes_in_k_group.md)** ([C++ Code](in_place_reversal/reverse_nodes_in_k_group.cpp)): High-frequency OA hard problem. Lookahead validation of $k$ nodes, block reversal in-place, and handling leftover nodes.
* **[Problem 7: Swap Nodes in Pairs](in_place_reversal/swap_nodes_in_pairs.md)** ([C++ Code](in_place_reversal/swap_nodes_in_pairs.cpp)): Adjacent pairwise node swapping using sentinel rewiring and recursive formulations.

---

## 3. Two Pointers & Sliding Gap
*Focus: Relative distance offsets, boundary cycling, and circular list operations.*

* **[Problem 8: Remove Nth Node From End of List](two_pointers_and_sliding_gap/remove_nth_node_from_end.md)** ([C++ Code](two_pointers_and_sliding_gap/remove_nth_node_from_end.cpp)): Fixed sliding gap of $(n + 1)$ between `fast` and `slow` with dummy node to stop at node preceding the target.
* **[Problem 9: Intersection of Two Linked Lists](two_pointers_and_sliding_gap/intersection_of_two_linked_lists.md)** ([C++ Code](two_pointers_and_sliding_gap/intersection_of_two_linked_lists.cpp)): Path equalization mathematical deduction ($a + c + b = b + c + a$) without calculating explicit lengths.
* **[Problem 10: Rotate List](two_pointers_and_sliding_gap/rotate_list.md)** ([C++ Code](two_pointers_and_sliding_gap/rotate_list.cpp)): Modulo normalization $k \pmod L$, forming a circular ring, and severing the link at position $(L - k)$.

---

## 4. Merging & Sorting
*Focus: Merge sort on linked lists, divide-and-conquer, and heap-based multi-way consolidation.*

* **[Problem 11: Merge Two Sorted Lists](merging_and_sorting/merge_two_sorted_lists.md)** ([C++ Code](merging_and_sorting/merge_two_sorted_lists.cpp)): Two-way sorted splicing with sentinel node and recursive merge formulation.
* **[Problem 12: Merge k Sorted Lists](merging_and_sorting/merge_k_sorted_lists.md)** ([C++ Code](merging_and_sorting/merge_k_sorted_lists.cpp)): Two primary assessment paradigms: Min-Heap ($O(N \log K)$ time, $O(K)$ space) vs. Divide-and-Conquer pairwise merging ($O(N \log K)$ time, strictly $O(1)$ space).
* **[Problem 13: Sort List](merging_and_sorting/sort_list.md)** ([C++ Code](merging_and_sorting/sort_list.cpp)): Top-Down Merge Sort ($O(N \log N)$ time, $O(\log N)$ stack) vs. Bottom-Up Iterative Merge Sort ($O(N \log N)$ time, strictly $O(1)$ space) using sublist sizes $1, 2, 4, 8 \dots$.

---

## 5. List Partitioning & Rearrangement
*Focus: Maintaining relative order (stability) while regrouping, leapfrogging, and multi-stage interweaving.*

* **[Problem 14: Partition List](partition_and_rearrangement/partition_list.md)** ([C++ Code](partition_and_rearrangement/partition_list.cpp)): Dual-sentinel chains (`lessDummy`, `greaterDummy`), preserving original stability, and severing greater tail to prevent infinite loops.
* **[Problem 15: Odd Even Linked List](partition_and_rearrangement/odd_even_linked_list.md)** ([C++ Code](partition_and_rearrangement/odd_even_linked_list.cpp)): Parallel pointer leapfrog uncoupling odd and even indices in $O(1)$ extra space.
* **[Problem 16: Reorder List](partition_and_rearrangement/reorder_list.md)** ([C++ Code](partition_and_rearrangement/reorder_list.cpp)): Master pipeline combining middle-splitting, second-half reversal, and zigzag interweaving ($L_0 \to L_n \to L_1 \to L_{n-1} \dots$).

---

## 6. Deep Copy & Multilevel Pointers
*Focus: Complex node topologies with random, child, and auxiliary pointers.*

* **[Problem 17: Copy List with Random Pointer](deep_copy_and_multilevel/copy_list_with_random_pointer.md)** ([C++ Code](deep_copy_and_multilevel/copy_list_with_random_pointer.cpp)): Hash map $O(N)$ approach vs. optimal 3-pass node weaving ($A \to A' \to B \to B'$) achieving deep copying in strictly $O(1)$ auxiliary space.
* **[Problem 18: Flatten a Multilevel Doubly Linked List](deep_copy_and_multilevel/flatten_multilevel_doubly_linked_list.md)** ([C++ Code](deep_copy_and_multilevel/flatten_multilevel_doubly_linked_list.cpp)): Multilevel doubly linked list traversal using iterative child splicing and DFS preorder ordering.

---

## 7. Arithmetic & Number Representation
*Focus: Representing large integers via linked lists, carry propagation, and stack/recursion digit alignment.*

* **[Problem 19: Add Two Numbers](arithmetic_and_numbers/add_two_numbers.md)** ([C++ Code](arithmetic_and_numbers/add_two_numbers.cpp)): Reverse-order digit addition with carry propagation and sentinel node.
* **[Problem 20: Add Two Numbers II](arithmetic_and_numbers/add_two_numbers_ii.md)** ([C++ Code](arithmetic_and_numbers/add_two_numbers_ii.cpp)): Most significant digit first addition solved using dual LIFO stacks without mutating or reversing the original lists.
* **[Problem 21: Plus One Linked List](arithmetic_and_numbers/plus_one_linked_list.md)** ([C++ Code](arithmetic_and_numbers/plus_one_linked_list.cpp)): Single-pass $O(1)$ space: tracking the rightmost non-9 node and cascading zero-fills.

---

## 8. Design & Specialized Caching (Doubly Linked List + Hash Map)
*Focus: System design building blocks, constant-time eviction policies, and frequency buckets.*

* **[Problem 22: LRU Cache](design_and_cache/lru_cache.md)** ([C++ Code](design_and_cache/lru_cache.cpp)): Doubly Linked List + Hash Map providing strictly $O(1)$ `get` and `put` with pseudo head and tail sentinels.
* **[Problem 23: LFU Cache](design_and_cache/lfu_cache.md)** ([C++ Code](design_and_cache/lfu_cache.cpp)): Two-tier hash map (`keyTable` + `freqTable` of Doubly Linked Lists) and dynamic `minFreq` tracking for $O(1)$ eviction with LRU tie-breaking.

---

## 9. Deletion & Modification Quirks
*Focus: Edge-case deletions without head access, duplicate drains, and sentinel bypasses.*

* **[Problem 24: Delete Node in a Linked List](deletion_and_modification/delete_node_in_a_linked_list.md)** ([C++ Code](deletion_and_modification/delete_node_in_a_linked_list.cpp)): Deleting target node when head pointer is unavailable via value overwriting and successor deletion.
* **[Problem 25: Remove Duplicates from Sorted List II](deletion_and_modification/remove_duplicates_from_sorted_list_ii.md)** ([C++ Code](deletion_and_modification/remove_duplicates_from_sorted_list_ii.cpp)): Discarding entire duplicate clusters to retain only strictly unique elements using sentinel duplicate draining.

