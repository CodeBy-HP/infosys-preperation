# Advanced Topics & Data Structures Master Roadmap

This repository covers specialized, high-performance data structures and algorithms designed for large-scale range queries, prefix retrieval, and linear-time text searching.

---

## 1. Advanced Range Query Structures
Focus: Overcoming the static array query vs. update bottleneck.

* **[Segment Tree](segment_tree/segment_tree.md)** ([C++ Code](segment_tree/segment_tree.cpp)): Balanced binary tree of intervals. Implements point updates, range sum queries, and $O(\log N)$ range updates with **Lazy Propagation**.
* **[Fenwick Tree (Binary Indexed Tree)](fenwick_tree/fenwick_tree.md)** ([C++ Code](fenwick_tree/fenwick_tree.cpp)): Elegant bitwise range accumulation using Lowest Set Bit (`i & -i`). Implements 1D point updates, range updates via difference arrays, and 2D submatrix sums.

---

## 2. Prefix Trees & Bitwise Tries
Focus: Compressing associative string dictionaries, substring frequency counting, and bitwise XOR maximization.

> [!NOTE]
> The comprehensive master index with all 8 Trie topics, bitwise prerequisites, and implementations is available in **[Trie Master Sheet](trie/SHEET.md)**.

* **[Bit Manipulation Prerequisites for Trie](trie/theory_and_fundamentals/bit_prerequisites_for_trie.md)**: Bitwise operators, extracting bits, and the greedy opposite-bit XOR maximization invariant.
* **[Implement Trie I](trie/theory_and_fundamentals/trie_implementation_i.md)** ([C++ Code](trie/theory_and_fundamentals/trie_implementation_i.cpp)): Core Trie supporting `insert`, `search`, and `startsWith`.
* **[Implement Trie II](trie/theory_and_fundamentals/trie_implementation_ii.md)** ([C++ Code](trie/theory_and_fundamentals/trie_implementation_ii.cpp)): Frequency tracking Trie with `countWordsEqualTo`, `countWordsStartingWith`, and `erase`.
* **[Longest Word with All Prefixes](trie/string_problems/longest_word_with_all_prefixes.md)** ([C++ Code](trie/string_problems/longest_word_with_all_prefixes.cpp)): Complete string verification via Trie prefix path validation.
* **[Number of Distinct Substrings](trie/string_problems/number_of_distinct_substrings.md)** ([C++ Code](trie/string_problems/number_of_distinct_substrings.cpp)): Converting substring generation to suffix-prefix node insertion in $O(N^2)$ time.
* **[Word Search II](trie/string_problems/word_search_ii.md)** ([C++ Code](trie/string_problems/word_search_ii.cpp)): Finding all dictionary words on an $M \times N$ grid simultaneously via Trie-guided DFS with dead-end branch pruning.
* **[Maximum XOR of Two Numbers](trie/bitwise_trie/maximum_xor_of_two_numbers.md)** ([C++ Code](trie/bitwise_trie/maximum_xor_of_two_numbers.cpp)): 32-bit Binary Trie with greedy opposite-bit branching in $O(32N) = O(N)$ time.
* **[Maximum XOR with an Element](trie/bitwise_trie/maximum_xor_with_an_element.md)** ([C++ Code](trie/bitwise_trie/maximum_xor_with_an_element.cpp)): Offline query processing: sorting queries by upper bound $m_i$ and monotonic Trie insertion.

---

## 3. Advanced String Matching
Focus: Substring pattern matching without wasteful pointer rewinding or $O(N \times M)$ worst cases.

* **[Knuth-Morris-Pratt (KMP) Algorithm](string_matching/kmp_algorithm.md)** ([C++ Code](string_matching/kmp_algorithm.cpp)): Deterministic finite automaton pattern matching using the **LPS (Longest Proper Prefix which is also a Suffix)** array to guarantee strictly $O(N + M)$ runtime.
* **[Rabin-Karp Algorithm](string_matching/rabin_karp.md)** ([C++ Code](string_matching/rabin_karp.cpp)): Polynomial rolling hash with $O(1)$ sliding window updates, collision verification, and competitive-programming double rolling hash.

