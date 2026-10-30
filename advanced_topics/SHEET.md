# Advanced Topics & Data Structures Master Roadmap

This repository covers specialized, high-performance data structures and algorithms designed for large-scale range queries, prefix retrieval, and linear-time text searching.

---

## 1. Advanced Range Query Structures
Focus: Overcoming the static array query vs. update bottleneck.

* **[Segment Tree](segment_tree/segment_tree.md)** ([C++ Code](segment_tree/segment_tree.cpp)): Balanced binary tree of intervals. Implements point updates, range sum queries, and $O(\log N)$ range updates with **Lazy Propagation**.
* **[Fenwick Tree (Binary Indexed Tree)](fenwick_tree/fenwick_tree.md)** ([C++ Code](fenwick_tree/fenwick_tree.cpp)): Elegant bitwise range accumulation using Lowest Set Bit (`i & -i`). Implements 1D point updates, range updates via difference arrays, and 2D submatrix sums.

---

## 2. Prefix Trees (Trie)
Focus: Compressing associative string dictionaries and multi-word simultaneous search.

* **[Implement Trie (Prefix Tree)](trie/implement_trie.md)** ([C++ Code](trie/implement_trie.cpp)): Alphabet-guided tree supporting `insert`, `search`, `startsWith`, and recursive memory reclamation (`remove`). Provides both contiguous 26-pointer array and hash map implementations.
* **[Word Search II](trie/word_search_ii.md)** ([C++ Code](trie/word_search_ii.cpp)): Finding all dictionary words on an $M \times N$ grid simultaneously via Trie-guided DFS with backtracking and in-situ dead-end branch pruning.

---

## 3. Advanced String Matching
Focus: Substring pattern matching without wasteful pointer rewinding or $O(N \times M)$ worst cases.

* **[Knuth-Morris-Pratt (KMP) Algorithm](string_matching/kmp_algorithm.md)** ([C++ Code](string_matching/kmp_algorithm.cpp)): Deterministic finite automaton pattern matching using the **LPS (Longest Proper Prefix which is also a Suffix)** array to guarantee strictly $O(N + M)$ runtime.
* **[Rabin-Karp Algorithm](string_matching/rabin_karp.md)** ([C++ Code](string_matching/rabin_karp.cpp)): Polynomial rolling hash with $O(1)$ sliding window updates, collision verification, and competitive-programming double rolling hash.

