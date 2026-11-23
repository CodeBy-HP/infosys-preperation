# Linked List Master Roadmap & Problem Sheet

Welcome to the **Linked List** algorithmic paradigm. Unlike contiguous arrays, linked lists rely on dynamic memory pointers. Mastering linked lists requires internalizing strict **pointer invariants**, recognizing **structural symmetries**, and avoiding undefined behavior (such as dangling pointers, memory leaks, and cyclic reference traps).

This sheet organizes **60 high-frequency problems & fundamental building blocks** across **11 core patterns** tested in technical assessments and coding interviews.

---

## The Core Invariants of Linked List Engineering

1. **The Sentinel (Dummy) Node Technique:**
   - Always instantiate a dummy head (`ListNode dummy(0); dummy.next = head;`) whenever the head node itself might be modified, deleted, or inserted before. This eliminates edge-case conditionals for empty lists and single-node head shifts.
2. **The Lookahead Rule:**
   - When deleting or swapping nodes, your pointer must always sit at the **preceding node** (`curr->next` is the node being affected).
3. **The Severe & Terminate Rule:**
   - When splitting lists or partitioning chains, you **must explicitly terminate tails with `nullptr`** (`tail->next = nullptr`). Failing to do so creates silent infinite cycles.
4. **Bidirectional Symmetry in Doubly Linked Lists:**
   - In a DLL, every non-boundary node satisfies `node->next->prev == node` and `node->prev->next == node`. Boundary operations must decouple both directions.
5. **Memory Hygiene:**
   - In production C++, always decouple nodes before deleting. Deleted nodes must not leave dangling references.

---

## 1. Singly Linked List Fundamentals
*Focus: Node memory representation, basic iteration, pointerlookahead, and $O(1)$/$O(N)$ insertion and deletion primitives.*

* **[Problem 1: Introduction to Singly Linked List](singly_linked_list_fundamentals/introduction_to_singly_linked_list.md)** ([C++ Code](singly_linked_list_fundamentals/introduction_to_singly_linked_list.cpp)): Converting an array into a singly linked list using tail pointers and dummy heads.
* **[Problem 2: Traversal in Linked List](singly_linked_list_fundamentals/traversal_in_linked_list.md)** ([C++ Code](singly_linked_list_fundamentals/traversal_in_linked_list.cpp)): Iterative and recursive traversal visiting all nodes without losing the head pointer.
* **[Problem 3: Find the Length of Linked List](singly_linked_list_fundamentals/find_length_of_linked_list.md)** ([C++ Code](singly_linked_list_fundamentals/find_length_of_linked_list.cpp)): Iterative and recursive counting of nodes in $O(N)$ time.
* **[Problem 4: Search in Linked List](singly_linked_list_fundamentals/search_in_linked_list.md)** ([C++ Code](singly_linked_list_fundamentals/search_in_linked_list.cpp)): Linear search for a target value $X$ in $O(N)$ time.
* **[Problem 5: Deletion of the Head of LL](singly_linked_list_fundamentals/deletion_of_head_of_linked_list.md)** ([C++ Code](singly_linked_list_fundamentals/deletion_of_head_of_linked_list.cpp)): $O(1)$ head deletion with memory deallocation.
* **[Problem 6: Deletion of the Tail of Linked List](singly_linked_list_fundamentals/deletion_of_tail_of_linked_list.md)** ([C++ Code](singly_linked_list_fundamentals/deletion_of_tail_of_linked_list.cpp)): Lookahead traversal stopping at the second-to-last node in $O(N)$ time.
* **[Problem 7: Deletion of the K-th Element](singly_linked_list_fundamentals/deletion_of_kth_element_of_linked_list.md)** ([C++ Code](singly_linked_list_fundamentals/deletion_of_kth_element_of_linked_list.cpp)): Deleting the $k$-th node ($1$-based index) using sentinel dummy nodes.
* **[Problem 8: Delete the Element with Value X](singly_linked_list_fundamentals/delete_element_with_value_x.md)** ([C++ Code](singly_linked_list_fundamentals/delete_element_with_value_x.cpp)): Finding and splicing out the first occurrence of node with value $X$.
* **[Problem 9: Deletion in Linked List (Master Suite)](singly_linked_list_fundamentals/deletion_in_linked_list.md)** ([C++ Code](singly_linked_list_fundamentals/deletion_in_linked_list.cpp)): Comprehensive suite of head, tail, $k$-th, and value-based deletion routines.
* **[Problem 10: Insertion at the Head of LL](singly_linked_list_fundamentals/insertion_at_head_of_linked_list.md)** ([C++ Code](singly_linked_list_fundamentals/insertion_at_head_of_linked_list.cpp)): Strict $O(1)$ front insertion.
* **[Problem 11: Insertion at the Tail of Linked List](singly_linked_list_fundamentals/insertion_at_tail_of_linked_list.md)** ([C++ Code](singly_linked_list_fundamentals/insertion_at_tail_of_linked_list.cpp)): Appending to the tail in $O(N)$ time.
* **[Problem 12: Insertion at the K-th Position](singly_linked_list_fundamentals/insertion_at_kth_position_of_linked_list.md)** ([C++ Code](singly_linked_list_fundamentals/insertion_at_kth_position_of_linked_list.cpp)): Splicing a new node into position $k$ via sentinel pointer advancement.
* **[Problem 13: Insertion Before Value X](singly_linked_list_fundamentals/insertion_before_value_x_in_linked_list.md)** ([C++ Code](singly_linked_list_fundamentals/insertion_before_value_x_in_linked_list.cpp)): Locating value $X$ and inserting immediately prior to it.
* **[Problem 14: Insertion in Linked List (Master Suite)](singly_linked_list_fundamentals/insertion_in_linked_list.md)** ([C++ Code](singly_linked_list_fundamentals/insertion_in_linked_list.cpp)): Unified collection of all singly linked list insertion techniques.

---

## 2. Doubly Linked List Fundamentals & Operations
*Focus: Forward and backward pointer manipulation, bidirectional traversal, and $O(1)$ node removal.*

* **[Problem 15: Introduction to Doubly LL](doubly_linked_list/introduction_to_doubly_linked_list.md)** ([C++ Code](doubly_linked_list/introduction_to_doubly_linked_list.cpp)): DLL node layout and bidirectional construction.
* **[Problem 16: Convert Array to Doubly Linked List](doubly_linked_list/convert_array_to_doubly_linked_list.md)** ([C++ Code](doubly_linked_list/convert_array_to_doubly_linked_list.cpp)): Linear construction from array establishing adjacent `prev` and `next` bonds.
* **[Problem 17: Delete Head of Doubly Linked List](doubly_linked_list/delete_head_of_doubly_linked_list.md)** ([C++ Code](doubly_linked_list/delete_head_of_doubly_linked_list.cpp)): Advancing head and severing `head->prev = nullptr` in $O(1)$ time.
* **[Problem 18: Delete Tail of Doubly Linked List](doubly_linked_list/delete_tail_of_doubly_linked_list.md)** ([C++ Code](doubly_linked_list/delete_tail_of_doubly_linked_list.cpp)): Directly accessing tail and decoupling predecessor's `next = nullptr`.
* **[Problem 19: Delete K-th Element of DLL](doubly_linked_list/delete_kth_element_of_doubly_linked_list.md)** ([C++ Code](doubly_linked_list/delete_kth_element_of_doubly_linked_list.cpp)): Splicing both forward and backward links when removing node $k$.
* **[Problem 20: Removing Given Node in DLL](doubly_linked_list/remove_given_node_in_doubly_linked_list.md)** ([C++ Code](doubly_linked_list/remove_given_node_in_doubly_linked_list.cpp)): Removing a non-head node in strict $O(1)$ time without access to head.
* **[Problem 21: Deletion in Doubly LL (Master Suite)](doubly_linked_list/deletion_in_doubly_linked_list.md)** ([C++ Code](doubly_linked_list/deletion_in_doubly_linked_list.cpp)): Unified DLL deletion suite for head, tail, $k$-th, and node references.
* **[Problem 22: Insert Node Before Head in DLL](doubly_linked_list/insert_node_before_head_in_doubly_linked_list.md)** ([C++ Code](doubly_linked_list/insert_node_before_head_in_doubly_linked_list.cpp)): Prepending node and rewiring previous head in $O(1)$ time.
* **[Problem 23: Insert Node Before Tail in DLL](doubly_linked_list/insert_node_before_tail_in_doubly_linked_list.md)** ([C++ Code](doubly_linked_list/insert_node_before_tail_in_doubly_linked_list.cpp)): Splicing before tail with 4 pointer assignments.
* **[Problem 24: Insert Node Before K-th Node in DLL](doubly_linked_list/insert_node_before_kth_node_in_doubly_linked_list.md)** ([C++ Code](doubly_linked_list/insert_node_before_kth_node_in_doubly_linked_list.cpp)): Navigating to $k$-th node and inserting prior to it.
* **[Problem 25: Insert Before Given Node in DLL](doubly_linked_list/insert_before_given_node_in_doubly_linked_list.md)** ([C++ Code](doubly_linked_list/insert_before_given_node_in_doubly_linked_list.cpp)): $O(1)$ insertion before any given non-head node.
* **[Problem 26: Insertion in DLL (Master Suite)](doubly_linked_list/insertion_in_doubly_linked_list.md)** ([C++ Code](doubly_linked_list/insertion_in_doubly_linked_list.cpp)): Unified DLL insertion operations.
* **[Problem 27: Reverse a Doubly Linked List](doubly_linked_list/reverse_a_doubly_linked_list.md)** ([C++ Code](doubly_linked_list/reverse_a_doubly_linked_list.cpp)): In-place pointer swapping (`std::swap(curr->prev, curr->next)`) reversing directionality in $O(N)$ time.

---

## 3. Fast & Slow Pointers (Floyd's Tortoise and Hare)
*Focus: Cycle detection, loop length calculation, meeting points, and palindrome verification.*

* **[Problem 28: Middle of the Linked List](fast_and_slow_pointers/middle_of_the_linked_list.md)** ([C++ Code](fast_and_slow_pointers/middle_of_the_linked_list.cpp)): Floyd's 2-speed traversal stopping at upper vs. lower middle in $O(N)$ time.
* **[Problem 29: Detect a Loop in LL](fast_and_slow_pointers/detect_cycle_in_linked_list.md)** ([C++ Code](fast_and_slow_pointers/detect_cycle_in_linked_list.cpp)): Boolean loop detection in $O(N)$ time and $O(1)$ space.
* **[Problem 30: Find the Starting Point of Loop in LL](fast_and_slow_pointers/linked_list_cycle_ii.md)** ([C++ Code](fast_and_slow_pointers/linked_list_cycle_ii.cpp)): Mathematical proof of cycle entrance collision ($L = nC - x$).
* **[Problem 31: Length of Loop in Linked List](fast_and_slow_pointers/length_of_loop_in_linked_list.md)** ([C++ Code](fast_and_slow_pointers/length_of_loop_in_linked_list.cpp)): Freezing meeting point and counting cycle nodes in $O(N)$ time and $O(1)$ space.
* **[Problem 32: Palindrome Linked List](fast_and_slow_pointers/palindrome_linked_list.md)** ([C++ Code](fast_and_slow_pointers/palindrome_linked_list.cpp)): 3-phase algorithm (Find middle $\to$ Reverse second half $\to$ Compare & restore) in $O(1)$ auxiliary space.

---

## 4. In-Place Reversal & Sublist Manipulation
*Focus: Pointer inversion, maintaining predecessor/successor links, and iterative vs. recursive transformations.*

* **[Problem 33: Reverse Linked List](in_place_reversal/reverse_linked_list.md)** ([C++ Code](in_place_reversal/reverse_linked_list.cpp)): Foundational 3-pointer state inversion (`prev`, `curr`, `nextNode`) alongside recursive formulation.
* **[Problem 34: Reverse Linked List II](in_place_reversal/reverse_linked_list_ii.md)** ([C++ Code](in_place_reversal/reverse_linked_list_ii.cpp)): Subsegment $[left, right]$ reversal in a single pass using sentinel head-insertion.
* **[Problem 35: Reverse Nodes in k-Group](in_place_reversal/reverse_nodes_in_k_group.md)** ([C++ Code](in_place_reversal/reverse_nodes_in_k_group.cpp)): Lookahead validation of $k$ nodes, block reversal in-place, and handling leftover nodes.
* **[Problem 36: Swap Nodes in Pairs](in_place_reversal/swap_nodes_in_pairs.md)** ([C++ Code](in_place_reversal/swap_nodes_in_pairs.cpp)): Adjacent pairwise node swapping using sentinel rewiring and recursive formulations.

---

## 5. Two Pointers & Sliding Gap
*Focus: Relative distance offsets, boundary cycling, and circular list operations.*

* **[Problem 37: Remove Nth Node From End of List](two_pointers_and_sliding_gap/remove_nth_node_from_end.md)** ([C++ Code](two_pointers_and_sliding_gap/remove_nth_node_from_end.cpp)): Fixed sliding gap of $(n + 1)$ with dummy node to stop at predecessor of target.
* **[Problem 38: Intersection of Two Linked Lists](two_pointers_and_sliding_gap/intersection_of_two_linked_lists.md)** ([C++ Code](two_pointers_and_sliding_gap/intersection_of_two_linked_lists.cpp)): Path equalization mathematical deduction ($a + c + b = b + c + a$) without calculating explicit lengths.
* **[Problem 39: Rotate List](two_pointers_and_sliding_gap/rotate_list.md)** ([C++ Code](two_pointers_and_sliding_gap/rotate_list.cpp)): Modulo normalization $k \pmod L$, forming a circular ring, and severing the link at position $(L - k)$.

---

## 6. Merging & Sorting
*Focus: Merge sort on linked lists, divide-and-conquer, and heap-based multi-way consolidation.*

* **[Problem 40: Merge Two Sorted Lists](merging_and_sorting/merge_two_sorted_lists.md)** ([C++ Code](merging_and_sorting/merge_two_sorted_lists.cpp)): Two-way sorted splicing with sentinel node and recursive merge formulation.
* **[Problem 41: Merge k Sorted Lists](merging_and_sorting/merge_k_sorted_lists.md)** ([C++ Code](merging_and_sorting/merge_k_sorted_lists.cpp)): Min-Heap ($O(N \log K)$ time, $O(K)$ space) vs. Divide-and-Conquer pairwise merging ($O(N \log K)$ time, strictly $O(1)$ space).
* **[Problem 42: Sort List](merging_and_sorting/sort_list.md)** ([C++ Code](merging_and_sorting/sort_list.cpp)): Top-Down Merge Sort ($O(N \log N)$ time, $O(\log N)$ stack) vs. Bottom-Up Iterative Merge Sort ($O(N \log N)$ time, strictly $O(1)$ space).

---

## 7. List Partitioning & Rearrangement
*Focus: Maintaining relative order (stability) while regrouping, leapfrogging, and multi-stage interweaving.*

* **[Problem 43: Sort a Linked List of 0s, 1s, and 2s](partition_and_rearrangement/sort_linked_list_of_0s_1s_2s.md)** ([C++ Code](partition_and_rearrangement/sort_linked_list_of_0s_1s_2s.cpp)): Three dummy chains (`zeroDummy`, `oneDummy`, `twoDummy`) connecting in-place in $O(N)$ time and $O(1)$ space.
* **[Problem 44: Partition List](partition_and_rearrangement/partition_list.md)** ([C++ Code](partition_and_rearrangement/partition_list.cpp)): Dual-sentinel chains (`lessDummy`, `greaterDummy`), preserving original stability, and severing greater tail.
* **[Problem 45: Odd Even Linked List](partition_and_rearrangement/odd_even_linked_list.md)** ([C++ Code](partition_and_rearrangement/odd_even_linked_list.cpp)): Parallel pointer leapfrog uncoupling odd and even indices in $O(1)$ extra space.
* **[Problem 46: Reorder List](partition_and_rearrangement/reorder_list.md)** ([C++ Code](partition_and_rearrangement/reorder_list.cpp)): Master pipeline combining middle-splitting, second-half reversal, and zigzag interweaving ($L_0 \to L_n \to L_1 \to L_{n-1} \dots$).

---

## 8. Deep Copy & Multilevel Pointers
*Focus: Complex node topologies with random, child, and bottom pointers.*

* **[Problem 47: Copy List with Random Pointer](deep_copy_and_multilevel/copy_list_with_random_pointer.md)** ([C++ Code](deep_copy_and_multilevel/copy_list_with_random_pointer.cpp)): 3-pass node weaving ($A \to A' \to B \to B'$) achieving deep copying in strictly $O(1)$ auxiliary space.
* **[Problem 48: Flatten a Multilevel Doubly Linked List](deep_copy_and_multilevel/flatten_multilevel_doubly_linked_list.md)** ([C++ Code](deep_copy_and_multilevel/flatten_multilevel_doubly_linked_list.cpp)): Multilevel doubly linked list traversal using iterative child splicing and DFS preorder ordering.
* **[Problem 49: Flattening a Linked List](deep_copy_and_multilevel/flattening_a_linked_list.md)** ([C++ Code](deep_copy_and_multilevel/flattening_a_linked_list.cpp)): Classic GFG problem flattening bottom-sorted sub-lists via recursive merge / priority queue in $O(N \cdot M)$ time.

---

## 9. Arithmetic & Number Representation
*Focus: Representing large integers via linked lists, carry propagation, and stack/recursion digit alignment.*

* **[Problem 50: Add Two Numbers](arithmetic_and_numbers/add_two_numbers.md)** ([C++ Code](arithmetic_and_numbers/add_two_numbers.cpp)): Reverse-order digit addition with carry propagation and sentinel node.
* **[Problem 51: Add Two Numbers II](arithmetic_and_numbers/add_two_numbers_ii.md)** ([C++ Code](arithmetic_and_numbers/add_two_numbers_ii.cpp)): Most significant digit first addition solved using dual LIFO stacks without mutating original lists.
* **[Problem 52: Add One to a Number Represented by LL](arithmetic_and_numbers/plus_one_linked_list.md)** ([C++ Code](arithmetic_and_numbers/plus_one_linked_list.cpp)): Single-pass $O(1)$ space: tracking the rightmost non-9 node and cascading zero-fills.

---

## 10. Deletion & Modification Quirks
*Focus: Edge-case deletions without head access, duplicate drains, and middle node elimination.*

* **[Problem 53: Delete Node in a Linked List](deletion_and_modification/delete_node_in_a_linked_list.md)** ([C++ Code](deletion_and_modification/delete_node_in_a_linked_list.cpp)): Deleting target node when head pointer is unavailable via value overwriting and successor deletion.
* **[Problem 54: Delete the Middle Node of a Linked List](deletion_and_modification/delete_the_middle_node.md)** ([C++ Code](deletion_and_modification/delete_the_middle_node.cpp)): Single-pass fast & slow pointer with offset stopping before middle node in $O(N)$ time.
* **[Problem 55: Remove Duplicates from Sorted List II](deletion_and_modification/remove_duplicates_from_sorted_list_ii.md)** ([C++ Code](deletion_and_modification/remove_duplicates_from_sorted_list_ii.cpp)): Discarding entire duplicate clusters to retain only strictly unique elements.

---

## 11. Doubly Linked List FAQs & Advanced Two-Pointers
*Focus: In-place duplicate elimination, key removal, and bidirectional target sum searches.*

* **[Problem 56: Delete All Occurrences of a Key in DLL](doubly_linked_list/delete_all_occurrences_of_key_in_dll.md)** ([C++ Code](doubly_linked_list/delete_all_occurrences_of_key_in_dll.cpp)): Splicing out all nodes matching target `key` in a single pass in $O(N)$ time.
* **[Problem 57: Remove Duplicates from Sorted DLL](doubly_linked_list/remove_duplicates_from_sorted_dll.md)** ([C++ Code](doubly_linked_list/remove_duplicates_from_sorted_dll.cpp)): Contiguous duplicate cluster skipping and pointer reconnection in $O(N)$ time and $O(1)$ space.
* **[Problem 58: Find Pairs with Given Sum in DLL](doubly_linked_list/find_pairs_with_given_sum_in_dll.md)** ([C++ Code](doubly_linked_list/find_pairs_with_given_sum_in_dll.cpp)): Two-pointer bidirectional inward scan on sorted DLL finding all sum pairs in $O(N)$ time and $O(1)$ space.
* **[Problem 59: LRU Cache](design_and_cache/lru_cache.md)** ([C++ Code](design_and_cache/lru_cache.cpp)): Doubly Linked List + Hash Map providing strictly $O(1)$ `get` and `put` with pseudo head and tail sentinels.
* **[Problem 60: LFU Cache](design_and_cache/lfu_cache.md)** ([C++ Code](design_and_cache/lfu_cache.cpp)): Two-tier hash map (`keyTable` + `freqTable` of Doubly Linked Lists) and dynamic `minFreq` tracking for $O(1)$ eviction with LRU tie-breaking.

---

## Quick Reference Summary Table

| Category | Problem | Time Complexity | Space Complexity | Core Invariant / Pattern |
| :--- | :--- | :--- | :--- | :--- |
| **Single LL Fundamentals** | [Intro to Singly LL](singly_linked_list_fundamentals/introduction_to_singly_linked_list.md) | $O(N)$ | $O(1)$ | Array to LL construction via tail pointer |
| **Single LL Fundamentals** | [Traversal in LL](singly_linked_list_fundamentals/traversal_in_linked_list.md) | $O(N)$ | $O(1)$ | Non-null pointer traversal |
| **Single LL Fundamentals** | [Length of LL](singly_linked_list_fundamentals/find_length_of_linked_list.md) | $O(N)$ | $O(1)$ | Counter loop to nullptr |
| **Single LL Fundamentals** | [Search in LL](singly_linked_list_fundamentals/search_in_linked_list.md) | $O(N)$ | $O(1)$ | Linear value search |
| **Single LL Fundamentals** | [Delete Head](singly_linked_list_fundamentals/deletion_of_head_of_linked_list.md) | $O(1)$ | $O(1)$ | Head advance and memory freeing |
| **Single LL Fundamentals** | [Delete Tail](singly_linked_list_fundamentals/deletion_of_tail_of_linked_list.md) | $O(N)$ | $O(1)$ | Two-node lookahead (`curr->next->next`) |
| **Single LL Fundamentals** | [Delete K-th Node](singly_linked_list_fundamentals/deletion_of_kth_element_of_linked_list.md) | $O(N)$ | $O(1)$ | Sentinel dummy with $k-1$ steps |
| **Single LL Fundamentals** | [Delete Value X](singly_linked_list_fundamentals/delete_element_with_value_x.md) | $O(N)$ | $O(1)$ | Predecessor pointer target splicing |
| **Single LL Fundamentals** | [Insert Head](singly_linked_list_fundamentals/insertion_at_head_of_linked_list.md) | $O(1)$ | $O(1)$ | Prepend and point to old head |
| **Single LL Fundamentals** | [Insert Tail](singly_linked_list_fundamentals/insertion_at_tail_of_linked_list.md) | $O(N)$ | $O(1)$ | Advance to last node and link |
| **Single LL Fundamentals** | [Insert at K-th Position](singly_linked_list_fundamentals/insertion_at_kth_position_of_linked_list.md) | $O(\min(k, N))$ | $O(1)$ | Sentinel dummy traversal to $k-1$ |
| **Single LL Fundamentals** | [Insert Before Value X](singly_linked_list_fundamentals/insertion_before_value_x_in_linked_list.md) | $O(N)$ | $O(1)$ | Predecessor lookahead splicing |
| **Doubly LL Fundamentals** | [Intro to Doubly LL](doubly_linked_list/introduction_to_doubly_linked_list.md) | $O(N)$ | $O(1)$ | Array to DLL with `prev` and `next` |
| **Doubly LL Fundamentals** | [Convert Array to DLL](doubly_linked_list/convert_array_to_doubly_linked_list.md) | $O(N)$ | $O(1)$ | Sequential bidirectional wiring |
| **Doubly LL Fundamentals** | [Delete Head of DLL](doubly_linked_list/delete_head_of_doubly_linked_list.md) | $O(1)$ | $O(1)$ | Advance head and set `head->prev = nullptr` |
| **Doubly LL Fundamentals** | [Delete Tail of DLL](doubly_linked_list/delete_tail_of_doubly_linked_list.md) | $O(N)$ / $O(1)$ | $O(1)$ | Tail access and predecessor decoupling |
| **Doubly LL Fundamentals** | [Delete K-th of DLL](doubly_linked_list/delete_kth_element_of_doubly_linked_list.md) | $O(\min(k, N))$ | $O(1)$ | Dual-link splice (`back->next` & `front->prev`) |
| **Doubly LL Fundamentals** | [Remove Given Node DLL](doubly_linked_list/remove_given_node_in_doubly_linked_list.md) | $O(1)$ | $O(1)$ | In-place removal without head pointer |
| **Doubly LL Fundamentals** | [Insert Before Head DLL](doubly_linked_list/insert_node_before_head_in_doubly_linked_list.md) | $O(1)$ | $O(1)$ | Prepend with bidirectional wiring |
| **Doubly LL Fundamentals** | [Insert Before Tail DLL](doubly_linked_list/insert_node_before_tail_in_doubly_linked_list.md) | $O(N)$ / $O(1)$ | $O(1)$ | 4-pointer splice before tail |
| **Doubly LL Fundamentals** | [Insert Before K-th DLL](doubly_linked_list/insert_node_before_kth_node_in_doubly_linked_list.md) | $O(\min(k, N))$ | $O(1)$ | Navigate to $k$ and splice before |
| **Doubly LL Fundamentals** | [Insert Before Node DLL](doubly_linked_list/insert_before_given_node_in_doubly_linked_list.md) | $O(1)$ | $O(1)$ | $O(1)$ splice before given node |
| **Doubly LL Fundamentals** | [Reverse a DLL](doubly_linked_list/reverse_a_doubly_linked_list.md) | $O(N)$ | $O(1)$ | `std::swap(curr->prev, curr->next)` |
| **Logic & Partitioning** | [Sort 0s, 1s, 2s](partition_and_rearrangement/sort_linked_list_of_0s_1s_2s.md) | $O(N)$ | $O(1)$ | Three dummy chains and cycle termination |
| **Logic & Partitioning** | [Odd Even LL](partition_and_rearrangement/odd_even_linked_list.md) | $O(N)$ | $O(1)$ | Leapfrog pointer uncoupling |
| **Fast & Slow Pointers** | [Middle of LL](fast_and_slow_pointers/middle_of_the_linked_list.md) | $O(N)$ | $O(1)$ | Floyd's 2-speed traversal |
| **Fast & Slow Pointers** | [Detect Loop in LL](fast_and_slow_pointers/detect_cycle_in_linked_list.md) | $O(N)$ | $O(1)$ | Tortoise and Hare collision |
| **Fast & Slow Pointers** | [Starting Point of Loop](fast_and_slow_pointers/linked_list_cycle_ii.md) | $O(N)$ | $O(1)$ | Distance equality $L = nC - x$ |
| **Fast & Slow Pointers** | [Length of Loop in LL](fast_and_slow_pointers/length_of_loop_in_linked_list.md) | $O(N)$ | $O(1)$ | Freeze meeting point and count loop |
| **Fast & Slow Pointers** | [Palindrome LL](fast_and_slow_pointers/palindrome_linked_list.md) | $O(N)$ | $O(1)$ | Middle split + reverse + compare |
| **Deletion & Modification**| [Delete Middle Node](deletion_and_modification/delete_the_middle_node.md) | $O(N)$ | $O(1)$ | Fast & slow with offset stop |
| **Two Pointers & Gap** | [Remove Nth from End](two_pointers_and_sliding_gap/remove_nth_node_from_end.md) | $O(N)$ | $O(1)$ | Sliding gap of $(n + 1)$ |
| **Two Pointers & Gap** | [Intersection Point](two_pointers_and_sliding_gap/intersection_of_two_linked_lists.md) | $O(N)$ | $O(1)$ | Path length equalization ($a+b+c$) |
| **Two Pointers & Gap** | [Rotate List](two_pointers_and_sliding_gap/rotate_list.md) | $O(N)$ | $O(1)$ | Modulo circular ring severing |
| **In-Place Reversal** | [Reverse Linked List](in_place_reversal/reverse_linked_list.md) | $O(N)$ | $O(1)$ | 3-pointer state inversion |
| **In-Place Reversal** | [Reverse Nodes in k-Group](in_place_reversal/reverse_nodes_in_k_group.md) | $O(N)$ | $O(1)$ | Lookahead $k$-validation and block reverse |
| **Arithmetic** | [Add Two Numbers](arithmetic_and_numbers/add_two_numbers.md) | $O(\max(N, M))$ | $O(1)$ | Reverse digit addition with carry |
| **Arithmetic** | [Plus One to LL](arithmetic_and_numbers/plus_one_linked_list.md) | $O(N)$ | $O(1)$ | Rightmost non-9 node carry propagation |
| **Merging & Sorting** | [Merge Two Sorted Lists](merging_and_sorting/merge_two_sorted_lists.md) | $O(N + M)$ | $O(1)$ | Two-way sorted splicing with sentinel |
| **Merging & Sorting** | [Sort List](merging_and_sorting/sort_list.md) | $O(N \log N)$ | $O(1)$ / $O(\log N)$ | Top-Down / Bottom-Up Merge Sort |
| **Multilevel & Deep Copy** | [Flattening of LL](deep_copy_and_multilevel/flattening_a_linked_list.md) | $O(N \cdot M)$ | $O(N)$ / $O(K)$ | Recursive merge / Min-Heap on bottom ptrs |
| **Multilevel & Deep Copy** | [Clone LL with Random Ptr](deep_copy_and_multilevel/copy_list_with_random_pointer.md) | $O(N)$ | $O(1)$ | 3-pass node weaving ($A \to A' \to B$) |
| **DLL FAQs** | [Delete All Key Occurrences](doubly_linked_list/delete_all_occurrences_of_key_in_dll.md) | $O(N)$ | $O(1)$ | Single-pass node removal in DLL |
| **DLL FAQs** | [Remove Duplicates from DLL](doubly_linked_list/remove_duplicates_from_sorted_dll.md) | $O(N)$ | $O(1)$ | Contiguous duplicate cluster skipping |
| **DLL FAQs** | [Find Pairs with Sum in DLL](doubly_linked_list/find_pairs_with_given_sum_in_dll.md) | $O(N)$ | $O(1)$ | Two-pointer bidirectional inward scan |
