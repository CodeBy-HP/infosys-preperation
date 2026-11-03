# Bit Manipulation Master Roadmap & Problem Sheet

Welcome to the **Bit Manipulation Algorithms & Bitmasking** paradigm. While most algorithms operate at the level of high-level abstract data types, Bit Manipulation operates directly on the fundamental machine words and bit registers of modern hardware.

Mastering bit manipulation is indispensable for coding assessments at top tech companies. It unlocks **$O(1)$ arithmetic shortcuts, $O(N)$ frequency counters without hash maps, optimal $O(3^N)$ submask enumerations, Gosper's Hack for $K$-combination permutations, logarithmic prefix bitwise Trie optimizations, and $O(64 N)$ linear bases over $\mathbb{F}_2$**.

This sheet organizes **29 production-grade problems** across **9 core patterns** tested in competitive programming and technical interviews.

---

## The Core Invariants of Bit Manipulation

1. **Self-Inverse & Cancellation Invariant ($a \oplus a = 0$):**
   - The bitwise XOR operation $(\oplus)$ is commutative, associative, has identity $0$ ($a \oplus 0 = a$), and is its own inverse ($a \oplus a = 0$).
   - Used to eliminate duplicates, detect single elements, and compute range queries without inverses.
2. **Lowest Set Bit Isolation (`n & (-n)`):**
   - In two's complement, $-n = \sim n + 1$.
   - The bitwise AND `n & (-n)` isolates the lowest (least significant) set bit of `n`, clearing all higher bits.
   - Used for partitioning disjoint groups, Fenwick tree indexing, and power of two validations.
3. **Brian Kernighan's Bit Clearance (`n & (n - 1)`):**
   - Subtracting 1 flips the lowest set bit to 0 and all trailing zeroes to 1.
   - Performing `n &= (n - 1)` clears strictly the lowest set bit in $O(1)$ time, enabling $O(K)$ Hamming weight calculations where $K$ is the number of 1-bits.
4. **Submask Descending Enumeration (`(sub - 1) & mask`):**
   - Iterating over all submasks of a bitmask in descending order using `sub = (sub - 1) & mask` visits only valid submasks in $O(2^k)$ steps.
   - Across all $N$-bit masks, this guarantees $\sum_{k=0}^N \binom{N}{k} 2^k = 3^N$ operations instead of naive $4^N$.
5. **Gosper's Hack for $K$-Set Bit Combinations:**
   - Finds the next lexicographical integer with exactly $K$ set bits in $O(1)$ operations:
     $$c = \text{mask} \ \& \ (-\text{mask}), \quad r = \text{mask} + c, \quad \text{next} = (((r \oplus \text{mask}) \gg 2) / c) \mid r$$
   - Generates all $\binom{N}{K}$ combinations visiting **only valid states** without exploring $2^N$ numbers.
6. **Gray Code Invariant ($G(i) = i \oplus (i \gg 1)$):**
   - In a Gray code sequence, every adjacent pair differs by strictly 1 bit.
   - Inversion back to binary: $b = g \oplus (g \gg 1) \oplus (g \gg 2) \dots$
7. **String Presence Bitmasking:**
   - For an alphabet of 26 letters, a single 32-bit integer encodes presence: `mask |= (1 << (c - 'a'))`.
   - Checking whether two words share zero characters reduces to `(mask1 & mask2) == 0` in $O(1)$ time.
8. **Linear Basis over $\mathbb{F}_2$ (Gaussian Elimination):**
   - Any set of integers can be reduced to at most 64 linearly independent basis vectors.
   - Finding maximum subset XOR or querying target constructibility takes $O(64) = O(1)$ per query.

---

## 💡 Essential Low-Level Bitwise Cheatsheet

### 1. ASCII & Character Tricks (Bit 5 / Space / Underscore)
- `1 << 5 = 32`, which is the ASCII value of space `' '`.
- **To Lowercase:** `c | ' '` or `c | (1 << 5)` (e.g. `'A' | ' ' == 'a'`).
- **To Uppercase:** `c & '_'` or `c & ~(1 << 5)` (e.g. `'a' & '_' == 'A'`).
- **Toggle Case:** `c ^ ' '` (e.g. `'A' ^ ' ' == 'a'`, `'a' ^ ' ' == 'A'`).
- **Alphabet Position (1-26):** `c & 31` (e.g. `'A' & 31 == 1`, `'z' & 31 == 26`).

### 2. Branchless Arithmetic & Logic
- **Branchless Min:** $\min(x, y) = y \oplus ((x \oplus y) \ \& \ -(x < y))$
- **Branchless Max:** $\max(x, y) = x \oplus ((x \oplus y) \ \& \ -(x < y))$
- **Swap without Temp:** `a ^= b; b ^= a; a ^= b;`

### 3. Fundamental Algebraic Identities
- $a + b = (a \oplus b) + 2(a \ \& \ b) = (a \mid b) + (a \ \& \ b)$
- $a \mid b = (a \oplus b) + (a \ \& \ b)$
- $a \oplus (a \ \& \ b) = (a \mid b) \oplus b$

---

## 1. Bitwise Fundamentals & Low-Level Invariants
*Focus: Bit counting, Kernighan's trick, parallel divide-and-conquer bit swaps, and power detection.*

* **[Problem 1: Number of 1 Bits / Hamming Weight](bitwise_fundamentals/number_of_1_bits.md)** ([C++ Code](bitwise_fundamentals/number_of_1_bits.cpp)): Brian Kernighan's algorithm `n &= (n - 1)` clearing lowest set bit in $O(K)$ time.
* **[Problem 2: Counting Bits](bitwise_fundamentals/counting_bits.md)** ([C++ Code](bitwise_fundamentals/counting_bits.cpp)): Single-pass dynamic programming transition $dp[i] = dp[i >> 1] + (i \& 1)$ in $O(N)$ time.
* **[Problem 3: Reverse Bits](bitwise_fundamentals/reverse_bits.md)** ([C++ Code](bitwise_fundamentals/reverse_bits.cpp)): Divide-and-conquer parallel mask swapping in 5 constant-time operations vs linear 32-bit shift.
* **[Problem 4: Power of Two and Power of Four](bitwise_fundamentals/power_of_two_and_four.md)** ([C++ Code](bitwise_fundamentals/power_of_two_and_four.cpp)): Single-bit invariant `n & (n - 1) == 0` and even-position bitmask `0x55555555`.

---

## 2. XOR Properties & Mathematical Deductions
*Focus: Self-inverse cancellations, modulo-3 state machines, and lowest set bit partitioning.*

* **[Problem 5: Single Number I](xor_properties/single_number_i.md)** ([C++ Code](xor_properties/single_number_i.cpp)): Classical XOR cancellation isolating the single unique element in $O(N)$ time and $O(1)$ space.
* **[Problem 6: Single Number II](xor_properties/single_number_ii.md)** ([C++ Code](xor_properties/single_number_ii.cpp)): Modulo-3 bit summation and digital logic finite state machine (`ones`, `twos`).
* **[Problem 7: Single Number III](xor_properties/single_number_iii.md)** ([C++ Code](xor_properties/single_number_iii.cpp)): Isolating two unique numbers by partitioning array via lowest set bit of $a \oplus b$.
* **[Problem 8: XOR Queries of a Subarray](xor_properties/xor_queries_of_a_subarray.md)** ([C++ Code](xor_properties/xor_queries_of_a_subarray.cpp)): Prefix XOR precomputation answering arbitrary range queries $[L, R]$ in $O(1)$ time.
* **[Problem 9: Find The Original Array of Prefix XOR](xor_properties/find_the_original_array_of_prefix_xor.md)** ([C++ Code](xor_properties/find_the_original_array_of_prefix_xor.cpp)): Algebraic inverse recovery $arr[i] = pref[i] \oplus pref[i - 1]$.
* **[Problem 10: Count Triplets of Equal XOR](xor_properties/count_triplets_equal_xor.md)** ([C++ Code](xor_properties/count_triplets_equal_xor.cpp)): Zero-sum XOR subarray reduction $a == b \iff P[k+1] == P[i]$ in $O(N)$ with hash map.

---

## 3. Bitmasking & Subset Enumeration
*Focus: Power sets, SOS DP submask iterations, Gosper's Hack, state-space BFS, and Meet-in-the-Middle.*

* **[Problem 11: Subsets / Power Set Generation](bitmasking_and_subsets/subsets_generation.md)** ([C++ Code](bitmasking_and_subsets/subsets_generation.cpp)): Iterative binary characteristic vector enumeration generating all $2^N$ subsets.
* **[Problem 12: Submask Enumeration](bitmasking_and_subsets/submask_enumeration.md)** ([C++ Code](bitmasking_and_subsets/submask_enumeration.cpp)): The `(sub - 1) & mask` descending trick achieving $O(3^N)$ full submask DP complexity.
* **[Problem 13: Partition to K Equal Sum Subsets](bitmasking_and_subsets/can_partition_k_subsets.md)** ([C++ Code](bitmasking_and_subsets/can_partition_k_subsets.cpp)): Bitmask dynamic programming with remainder modulo tracking and greedy sorting prune.
* **[Problem 14: Shortest Path Visiting All Nodes](bitmasking_and_subsets/shortest_path_visiting_all_nodes.md)** ([C++ Code](bitmasking_and_subsets/shortest_path_visiting_all_nodes.cpp)): Multi-source breadth-first search on state space $(node, mask)$ with early termination.
* **[Problem 15: Partition Array to Minimize Difference](bitmasking_and_subsets/partition_array_minimize_difference.md)** ([C++ Code](bitmasking_and_subsets/partition_array_minimize_difference.cpp)): Meet-in-the-Middle splitting $N=30$ into two halves of 15 with bitmasks and `std::lower_bound`.
* **[Problem 16: Combinations of K Set Bits (Gosper's Hack)](bitmasking_and_subsets/k_set_bits_combinations_gospers_hack.md)** ([C++ Code](bitmasking_and_subsets/k_set_bits_combinations_gospers_hack.cpp)): Generating all $\binom{N}{K}$ masks in $O(1)$ operations per state using Gosper's Hack vs $O(2^N)$ brute force.

---

## 4. Bitwise Arithmetic & Range Operations
*Focus: Digital circuits, exponential bit-shifting divisions, and common binary prefixes.*

* **[Problem 17: Sum of Two Integers](bitwise_arithmetic_and_ranges/sum_of_two_integers.md)** ([C++ Code](bitwise_arithmetic_and_ranges/sum_of_two_integers.cpp)): Half-adder digital circuit simulation using XOR for sum and AND-shift for carry.
* **[Problem 18: Divide Two Integers](bitwise_arithmetic_and_ranges/divide_two_integers.md)** ([C++ Code](bitwise_arithmetic_and_ranges/divide_two_integers.cpp)): Exponential bit-shift doubling division simulating quotient subtraction in $O(32)$ time.
* **[Problem 19: Bitwise AND of Numbers Range](bitwise_arithmetic_and_ranges/bitwise_and_of_numbers_range.md)** ([C++ Code](bitwise_arithmetic_and_ranges/bitwise_and_of_numbers_range.cpp)): Identifying the common binary prefix of `left` and `right` by zeroing differing suffixes.

---

## 5. Bitwise Trie (Prefix Bit Trees)
*Focus: 31-bit binary tries, greedy opposite-bit traversal, and bounded offline queries.*

* **[Problem 20: Maximum XOR of Two Numbers in an Array](bitwise_trie/maximum_xor_of_two_numbers.md)** ([C++ Code](bitwise_trie/maximum_xor_of_two_numbers.cpp)): 31-bit Binary Trie with greedy branch selection achieving $O(N)$ pair maximization.
* **[Problem 21: Maximum XOR With an Element From Array](bitwise_trie/maximum_xor_with_element_bound.md)** ([C++ Code](bitwise_trie/maximum_xor_with_element_bound.cpp)): Offline query sorting by upper threshold $m_i$ combined with dynamic Trie insertion.

---

## 6. Bit Contribution & Hamming Techniques
*Focus: Column-by-column independent contributions, combinatorial OR sums, and truth table minimization.*

* **[Problem 22: Total Hamming Distance](bit_contribution_and_hamming/total_hamming_distance.md)** ([C++ Code](bit_contribution_and_hamming/total_hamming_distance.cpp)): Independent column-by-column pair counting $c \times (N - c)$ in $O(32 N)$ linear time.
* **[Problem 23: Sum of All Subset XOR Totals](bit_contribution_and_hamming/sum_of_all_subset_xor_totals.md)** ([C++ Code](bit_contribution_and_hamming/sum_of_all_subset_xor_totals.cpp)): Mathematical proof reducing subset XOR sum to $(\text{OR sum}) \times 2^{N-1}$ in $O(N)$ time.
* **[Problem 24: Minimum Flips to Make a OR b Equal to c](bit_contribution_and_hamming/minimum_flips_or_equal_to_target.md)** ([C++ Code](bit_contribution_and_hamming/minimum_flips_or_equal_to_target.cpp)): Bitwise truth table evaluation determining minimal bit flips in $O(1)$ time.

---

## 7. String Bitmasks & Character Presence Hashing
*Focus: 26-bit alphabet signatures, disjoint string pairs, and word puzzle validation.*

* **[Problem 25: Maximum Product of Word Lengths](string_bitmasks_and_hashing/maximum_product_of_word_lengths.md)** ([C++ Code](string_bitmasks_and_hashing/maximum_product_of_word_lengths.cpp)): Encoding words as 26-bit integers to check disjointness in $O(1)$ via `(mask1 & mask2) == 0`.
* **[Problem 26: Number of Valid Words for Each Puzzle](string_bitmasks_and_hashing/number_of_valid_words_for_each_puzzle.md)** ([C++ Code](string_bitmasks_and_hashing/number_of_valid_words_for_each_puzzle.cpp)): Mandatory first-letter bitmask coupled with submask enumeration over 6 remaining letters ($2^6 = 64$).

---

## 8. Gray Code & Parity Sequences
*Focus: 1-bit adjacent transitions, circular permutations, and Thue-Morse parity sequences.*

* **[Problem 27: Gray Code & Circular Permutations](gray_code_and_parity/gray_code.md)** ([C++ Code](gray_code_and_parity/gray_code.cpp)): $G(i) = i \oplus (i \gg 1)$, reverse Gray decoding, and target-shifted circular permutations.
* **[Problem 28: K-th Symbol in Grammar](gray_code_and_parity/kth_symbol_in_grammar.md)** ([C++ Code](gray_code_and_parity/kth_symbol_in_grammar.cpp)): Thue-Morse sequence deduction where symbol at $k$ is given by `__builtin_popcount(k - 1) & 1`.

---

## 9. Linear Basis (Gaussian Elimination over $\mathbb{F}_2$)
*Focus: Vector space spanning over Galois Field 2, maximum subset XOR, and target span verification.*

* **[Problem 29: Maximum XOR Subset via Linear Basis](linear_basis/maximum_xor_subset_linear_basis.md)** ([C++ Code](linear_basis/maximum_xor_subset_linear_basis.cpp)): 64-slot basis array insertion and greedy maximum XOR extraction in $O(64 N)$ time.

---

## Quick Reference Summary Table

| Category | Problem | Time | Space | Core Invariant / Trick |
| :--- | :--- | :--- | :--- | :--- |
| **Fundamentals** | [Number of 1 Bits](bitwise_fundamentals/number_of_1_bits.md) | $O(K)$ | $O(1)$ | Brian Kernighan `n &= (n - 1)` |
| **Fundamentals** | [Counting Bits](bitwise_fundamentals/counting_bits.md) | $O(N)$ | $O(1)$ | $dp[i] = dp[i >> 1] + (i \& 1)$ |
| **Fundamentals** | [Reverse Bits](bitwise_fundamentals/reverse_bits.md) | $O(1)$ | $O(1)$ | 5-step divide-and-conquer bit swaps |
| **Fundamentals** | [Power of Two & Four](bitwise_fundamentals/power_of_two_and_four.md) | $O(1)$ | $O(1)$ | `n & (n - 1) == 0` & `0x55555555` |
| **XOR Properties** | [Single Number I](xor_properties/single_number_i.md) | $O(N)$ | $O(1)$ | $a \oplus a = 0$ self-inverse |
| **XOR Properties** | [Single Number II](xor_properties/single_number_ii.md) | $O(N)$ | $O(1)$ | Modulo-3 FSM (`ones`, `twos`) |
| **XOR Properties** | [Single Number III](xor_properties/single_number_iii.md) | $O(N)$ | $O(1)$ | Lowest set bit partition `diff & (-diff)` |
| **XOR Properties** | [XOR Queries of Subarray](xor_properties/xor_queries_of_a_subarray.md) | $O(N + Q)$ | $O(N)$ | Prefix XOR array $P[R+1] \oplus P[L]$ |
| **XOR Properties** | [Original Array of Prefix XOR](xor_properties/find_the_original_array_of_prefix_xor.md) | $O(N)$ | $O(1)$ | Algebraic inverse $pref[i] \oplus pref[i-1]$ |
| **XOR Properties** | [Count Triplets Equal XOR](xor_properties/count_triplets_equal_xor.md) | $O(N)$ | $O(N)$ | Zero-sum prefix match $P[k+1] == P[i]$ |
| **Bitmasking** | [Subsets / Power Set](bitmasking_and_subsets/subsets_generation.md) | $O(N \cdot 2^N)$ | $O(1)$ | Integer mask characteristic vector |
| **Bitmasking** | [Submask Enumeration](bitmasking_and_subsets/submask_enumeration.md) | $O(3^N)$ | $O(1)$ | `(sub - 1) & mask` descending trick |
| **Bitmasking** | [Partition K Subsets](bitmasking_and_subsets/can_partition_k_subsets.md) | $O(N \cdot 2^N)$ | $O(2^N)$ | Bitmask DP with remainder memoization |
| **Bitmasking** | [Shortest Path All Nodes](bitmasking_and_subsets/shortest_path_visiting_all_nodes.md) | $O(N^2 \cdot 2^N)$ | $O(N \cdot 2^N)$ | Multi-source BFS on $(u, mask)$ |
| **Bitmasking** | [Partition Minimize Diff](bitmasking_and_subsets/partition_array_minimize_difference.md) | $O(2^{N/2} \cdot N)$ | $O(2^{N/2})$ | Meet-in-the-Middle + Binary Search |
| **Bitmasking** | [K Set Bits (Gosper's Hack)](bitmasking_and_subsets/k_set_bits_combinations_gospers_hack.md) | $O(\binom{N}{K})$ | $O(1)$ | Next bit permutation in $O(1)$ per state |
| **Arithmetic** | [Sum of Two Integers](bitwise_arithmetic_and_ranges/sum_of_two_integers.md) | $O(1)$ | $O(1)$ | Half adder: XOR sum + AND carry |
| **Arithmetic** | [Divide Two Integers](bitwise_arithmetic_and_ranges/divide_two_integers.md) | $O(1)$ | $O(1)$ | Exponential shift subtraction $(dvs \ll i)$ |
| **Arithmetic** | [Bitwise AND Range](bitwise_arithmetic_and_ranges/bitwise_and_of_numbers_range.md) | $O(1)$ | $O(1)$ | Common binary prefix of `left` & `right` |
| **Bitwise Trie** | [Maximum XOR of Two Numbers](bitwise_trie/maximum_xor_of_two_numbers.md) | $O(N)$ | $O(N)$ | 31-bit Trie with greedy opposite bit |
| **Bitwise Trie** | [Maximum XOR with Bound](bitwise_trie/maximum_xor_with_element_bound.md) | $O(N \log N + Q \log Q)$ | $O(N + Q)$ | Offline sorting + dynamic Trie insertion |
| **Contribution** | [Total Hamming Distance](bit_contribution_and_hamming/total_hamming_distance.md) | $O(N)$ | $O(1)$ | Column-by-column $c \times (N - c)$ |
| **Contribution** | [Subset XOR Totals](bit_contribution_and_hamming/sum_of_all_subset_xor_totals.md) | $O(N)$ | $O(1)$ | $(\text{OR sum}) \times 2^{N-1}$ |
| **Contribution** | [Min Flips OR Target](bit_contribution_and_hamming/minimum_flips_or_equal_to_target.md) | $O(1)$ | $O(1)$ | Independent bit truth table evaluation |
| **String Masking** | [Max Product Word Lengths](string_bitmasks_and_hashing/maximum_product_of_word_lengths.md) | $O(\sum L + N^2)$ | $O(N)$ | 26-bit disjoint check `(m1 & m2) == 0` |
| **String Masking** | [Valid Words per Puzzle](string_bitmasks_and_hashing/number_of_valid_words_for_each_puzzle.md) | $O(\sum L + P \cdot 2^6)$ | $O(N)$ | First-bit lock + submask enumeration |
| **Gray & Parity** | [Gray Code Sequences](gray_code_and_parity/gray_code.md) | $O(2^N)$ | $O(1)$ | Formula $i \oplus (i \gg 1)$ & circular shift |
| **Gray & Parity** | [K-th Symbol in Grammar](gray_code_and_parity/kth_symbol_in_grammar.md) | $O(1)$ | $O(1)$ | Thue-Morse parity `__builtin_popcount(k-1) & 1` |
| **Linear Basis** | [Max XOR Subset Basis](linear_basis/maximum_xor_subset_linear_basis.md) | $O(64 N)$ | $O(64)$ | Gaussian elimination basis over $\mathbb{F}_2$ |
