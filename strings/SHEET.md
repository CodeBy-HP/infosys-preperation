# Strings Master Roadmap & Problem Sheet

Welcome to the **String Algorithms** paradigm. Strings are one of the most heavily tested domains in technical assessments and coding interviews. Unlike simple integer arrays, string problems require mastering **pattern matching, sliding window frequency invariants, palindromic symmetry, finite state machines, and prefix tree structures**.

This sheet organizes **20 high-frequency problems** across **6 core patterns** frequently tested in technical assessments.

---

## The Core Invariants of String Engineering

1. **Sliding Window Boundary Invariant:**
   - In substring problems, expand the right pointer to capture elements, and only contract the left pointer when a condition is violated ($W - \text{maxFreq} > k$ or collision detected). Use direct array lookup tables (`lastSeen[128]`) for $O(1)$ pointer jumps.
2. **Palindromic Symmetry ($2N - 1$ Centers):**
   - Palindromes mirror across their midpoint. Rather than testing all $O(N^2)$ substrings in $O(N)$ time ($O(N^3)$), expand outward from $N$ odd centers `(i, i)` and $N - 1$ even centers `(i, i + 1)` in $O(N^2)$ time and $O(1)$ space.
3. **KMP Longest Prefix Suffix (LPS) Invariant:**
   - On mismatch, never rewind the main text pointer $i$. Use `lps[j - 1]` to fall back to the longest proper prefix of the pattern that is also a suffix, ensuring strictly linear $O(N + M)$ search.
4. **Lexicographically Smallest via Monotonic Stack:**
   - When building a unique sequence with smallest lexicographical order, greedily pop characters that are larger than the current character **only if** they are guaranteed to appear again later (`lastOccurrence[c] > i`).
5. **Prefix Trees (Tries):**
   - When searching across a dictionary of $W$ words in a grid or text, insert all words into a Trie. This allows pruning entire search branches immediately whenever a prefix is not present.

---

## 1. Sliding Window & Two Pointers
*Focus: Dynamic window expansion/contraction, last-seen index jumping, and character frequency mismatch tracking.*

* **[Problem 1: Longest Substring Without Repeating Characters](sliding_window_and_two_pointers/longest_substring_without_repeating_characters.md)** ([C++ Code](sliding_window_and_two_pointers/longest_substring_without_repeating_characters.cpp)): Direct index jumping using a 128-element `lastSeen` table in strictly single-pass $O(N)$ time.
* **[Problem 2: Minimum Window Substring](sliding_window_and_two_pointers/minimum_window_substring.md)** ([C++ Code](sliding_window_and_two_pointers/minimum_window_substring.cpp)): The quintessential hard sliding window problem: expanding to qualify (`formed == required`) and contracting to minimize.
* **[Problem 3: Longest Repeating Character Replacement](sliding_window_and_two_pointers/longest_repeating_character_replacement.md)** ([C++ Code](sliding_window_and_two_pointers/longest_repeating_character_replacement.cpp)): Monotonic non-shrinking window tracking $(W - \text{maxFreq} \le k)$ in $O(N)$ time and $O(26)$ space.
* **[Problem 4: Longest Contiguous Subarray with Bounded Adjacent Difference](sliding_window_and_two_pointers/longest_contiguous_subarray.md)** ([C++ Code](sliding_window_and_two_pointers/longest_contiguous_subarray.cpp)): Linear scan window reset tracking contiguous subarray lengths under adjacent difference bounds.

---

## 2. Palindrome & Center Expansion
*Focus: Exploiting mirror symmetry, two-pointer boundary checking, and single-deletion allowances.*

* **[Problem 5: Longest Palindromic Substring](palindrome_and_expansion/longest_palindromic_substring.md)** ([C++ Code](palindrome_and_expansion/longest_palindromic_substring.cpp)): Expanding around $2N - 1$ centers to find maximum palindrome length in $O(1)$ auxiliary space.
* **[Problem 6: Palindromic Substrings](palindrome_and_expansion/palindromic_substrings.md)** ([C++ Code](palindrome_and_expansion/palindromic_substrings.cpp)): Center-expansion counting every valid palindromic substring in $O(N^2)$ time and $O(1)$ space.
* **[Problem 7: Valid Palindrome II](palindrome_and_expansion/valid_palindrome_ii.md)** ([C++ Code](palindrome_and_expansion/valid_palindrome_ii.cpp)): Two-pointer mismatch branching testing deletion of left vs. right character in $O(N)$ time.

---

## 3. Pattern Matching & KMP
*Focus: Linear-time substring search without backtracking, rolling hashes, and prefix symmetry.*

* **[Problem 8: Find the Index of the First Occurrence in a String](pattern_matching_and_kmp/find_the_index_of_the_first_occurrence.md)** ([C++ Code](pattern_matching_and_kmp/find_the_index_of_the_first_occurrence.cpp)): The Knuth-Morris-Pratt (KMP) algorithm and precomputed LPS array achieving $O(N + M)$ guaranteed worst-case time.
* **[Problem 9: Repeated String Match](pattern_matching_and_kmp/repeated_string_match.md)** ([C++ Code](pattern_matching_and_kmp/repeated_string_match.cpp)): Theoretical repeat bounds ($\lceil L_b / L_a \rceil + 2$) and bounded string matching.
* **[Problem 10: Shortest Palindrome](pattern_matching_and_kmp/shortest_palindrome.md)** ([C++ Code](pattern_matching_and_kmp/shortest_palindrome.cpp)): KMP prefix symmetry on $s + \# + \text{reverse}(s)$ to find the longest palindromic prefix in $O(N)$ time.

---

## 4. String Manipulation & Simulation
*Focus: Deterministic state machines, overflow prevention, character fingerprinting, and zigzag trajectories.*

* **[Problem 11: String to Integer (atoi)](string_manipulation_and_simulation/string_to_integer_atoi.md)** ([C++ Code](string_manipulation_and_simulation/string_to_integer_atoi.cpp)): Deterministic finite state machine handling whitespace, sign detection, and 32-bit signed integer overflow clamping.
* **[Problem 12: Group Anagrams](string_manipulation_and_simulation/group_anagrams.md)** ([C++ Code](string_manipulation_and_simulation/group_anagrams.cpp)): Anagram grouping via canonical sorted keys and character count frequency fingerprints.
* **[Problem 13: Zigzag Conversion](string_manipulation_and_simulation/zigzag_conversion.md)** ([C++ Code](string_manipulation_and_simulation/zigzag_conversion.cpp)): Row trajectory bouncing simulation placing characters in $O(N)$ linear time.
* **[Problem 14: Split a String in Balanced Strings (with At Most 1 Swap)](string_manipulation_and_simulation/split_string_to_balance.md)** ([C++ Code](string_manipulation_and_simulation/split_string_to_balance.cpp)): Prefix difference balance tracking with adjacent character perturbation to maximize balanced splits.

---

## 5. String Greedy & Swaps
*Focus: Stride placement, pigeonhole majority bottlenecks, and monotonic stack ordering.*

* **[Problem 15: Minimum Swaps to Group All 1's or 0's](string_greedy_and_swaps/min_swaps_to_group_all_ones.md)** ([C++ Code](string_greedy_and_swaps/min_swaps_to_group_all_ones.cpp)): Obstacle barrier counting and median distance minimization for contiguous character grouping.
* **[Problem 16: Reorganize String](string_greedy_and_swaps/reorganize_string.md)** ([C++ Code](string_greedy_and_swaps/reorganize_string.cpp)): Pigeonhole bottleneck verification ($\text{maxFreq} \le \lceil N/2 \rceil$) and even/odd index stride placement.
* **[Problem 17: Remove Duplicate Letters](string_greedy_and_swaps/remove_duplicate_letters.md)** ([C++ Code](string_greedy_and_swaps/remove_duplicate_letters.cpp)): Monotonic stack with last-occurrence tracking producing the lexicographically smallest result.

---

## 6. Prefix Trees & Suffix Structures
*Focus: Fast multi-string retrieval, 2D grid branch pruning, and lexicographical suffix queries.*

* **[Problem 18: Implement Trie (Prefix Tree)](prefix_trees_and_suffix_structures/implement_trie_prefix_tree.md)** ([C++ Code](prefix_trees_and_suffix_structures/implement_trie_prefix_tree.cpp)): 26-ary tree implementation supporting $O(L)$ `insert`, `search`, and `startsWith`.
* **[Problem 19: Word Search II](prefix_trees_and_suffix_structures/word_search_ii.md)** ([C++ Code](prefix_trees_and_suffix_structures/word_search_ii.cpp)): Simultaneous multi-word 2D grid backtracking with Trie prefix pruning.
* **[Problem 20: Lexicographically Smallest Suffix with Matching Prefix](prefix_trees_and_suffix_structures/lexicographically_smallest_suffix.md)** ([C++ Code](prefix_trees_and_suffix_structures/lexicographically_smallest_suffix.cpp)): Suffix array binary search answering lexicographical suffix queries modulo $10^9 + 7$.

