# Tries (Prefix Trees) Master Roadmap & Problem Sheet

A **Trie** (derived from "re**trie**val" and pronounced "try") is a multi-way tree data structure used for high-efficiency prefix searches, autocomplete lookups, dictionary validations, and bitwise XOR maximizations. 

By representing characters or bits as edges and sharing common prefixes across keys, Tries eliminate redundant comparisons, reducing string lookups from $O(N \cdot L)$ down to optimal $O(L)$ time independent of dataset size.

This roadmap organizes all **8 core Trie topics and problems** across **3 algorithmic patterns**.

---

## 1. Theory & Core Implementations
*Focus: Alphabet branching, prefix vs word termination invariants, frequency counting, and bitwise prerequisites.*

* **[Bit Prerequisites for Trie Problems](theory_and_fundamentals/bit_prerequisites_for_trie.md)**: Bitwise operations (`&`, `|`, `^`, `<<`, `>>`), extracting the $i$-th bit `(num >> i) & 1`, setting bits, XOR maximization properties, and 32-bit Binary Trie node design.
* **[Trie Implementation and Operations (Trie I)](theory_and_fundamentals/trie_implementation_i.md)** ([C++ Code](theory_and_fundamentals/trie_implementation_i.cpp)): Complete Trie class implementing `insert(word)`, `search(word)`, and `startsWith(prefix)` in $O(L)$ time.
* **[Trie Implementation with Advanced Operations (Trie II)](theory_and_fundamentals/trie_implementation_ii.md)** ([C++ Code](theory_and_fundamentals/trie_implementation_ii.cpp)): Frequency-tracking Trie supporting `countWordsEqualTo(word)`, `countWordsStartingWith(prefix)`, and `erase(word)` via `countEndsWith` and `countPrefix` counters.

---

## 2. String Prefix & Substring Problems
*Focus: Prefix chaining, suffix-to-prefix bijection, and multi-word 2D board traversal.*

* **[Longest Word with All Prefixes (Complete String)](string_problems/longest_word_with_all_prefixes.md)** ([C++ Code](string_problems/longest_word_with_all_prefixes.cpp)): Identifying the longest word whose every prefix is also a valid word in the dataset using Trie prefix validation.
* **[Number of Distinct Substrings in a String](string_problems/number_of_distinct_substrings.md)** ([C++ Code](string_problems/number_of_distinct_substrings.cpp)): Converting substring generation to suffix-prefix node insertion in $O(N^2)$ time with zero string hashing or allocation overhead.
* **[Word Search II](string_problems/word_search_ii.md)** ([C++ Code](string_problems/word_search_ii.cpp)): 2D grid backtracking accelerated by a Trie with in-place leaf pruning to prevent redundant path searches.

---

## 3. Bitwise Trie & XOR Maximization
*Focus: 32-bit binary decision trees, opposite-bit greedy search, and offline query processing.*

* **[Maximum XOR of Two Numbers in an Array](bitwise_trie/maximum_xor_of_two_numbers.md)** ([C++ Code](bitwise_trie/maximum_xor_of_two_numbers.cpp)): Greedy bitwise tree traversal looking for opposite bits $(1 - b)$ at each bit position from MSB 31 down to 0 in $O(32N) = O(N)$ time.
* **[Maximum XOR With an Element From Array](bitwise_trie/maximum_xor_with_an_element.md)** ([C++ Code](bitwise_trie/maximum_xor_with_an_element.cpp)): Offline query processing: sorting queries by upper bound $m_i$ and monotonically inserting numbers $\le m_i$ into a dynamic Binary Trie.

---

## Algorithmic Complexity Reference Table

| Pattern | Topic / Problem | Time Complexity | Auxiliary Space | Core Invariant |
|---|---|:---:|:---:|---|
| **Theory** | Bit Prerequisites | — | — | Extracting $i$-th bit `(num >> i) & 1` & greedy opposite bit pairing |
| **Theory** | Trie Implementation I | $O(L)$ per op | $O(N \cdot L \cdot 26)$ | 26 child pointers + boolean `isEnd` flag |
| **Theory** | Trie Implementation II | $O(L)$ per op | $O(N \cdot L \cdot 26)$ | `countPrefix` along path + `countEndsWith` at terminal node |
| **String Trie** | Longest Word with All Prefixes | $O(\sum \|W_i\|)$ | $O(\sum \|W_i\| \cdot 26)$ | Every node along word path must have `isEnd == true` |
| **String Trie** | Number of Distinct Substrings | $O(N^2)$ | $O(N^2 \cdot 26)$ | Total distinct substrings = Total Trie nodes allocated |
| **String Trie** | Word Search II | $O(M \cdot N \cdot 4^L)$ | $O(\sum \|W_i\|)$ | Trie prefix pruning + node decoupling on match |
| **Bitwise Trie** | Maximum XOR of Two Numbers | $O(32 \cdot N)$ | $O(32 \cdot N)$ | 32-bit Binary Trie + greedy $1 - \text{bit}$ branching |
| **Bitwise Trie** | Maximum XOR with an Element | $O(N \log N + Q \log Q + 32(N + Q))$ | $O(32N + Q)$ | Offline queries sorted by $m_i$ + monotonic Trie insertion |

