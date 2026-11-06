# Alien Dictionary (LeetCode 269)

## Problem Overview
There is a new alien language that uses the Latin alphabet. However, the order of letters is unknown.
You are given a list of strings `words` from the alien language's dictionary, where the strings are claimed to be **sorted lexicographically** by the rules of this new language.
Derive the order of letters in this language. If the order is invalid, return `""`. If there are multiple valid orders, return any of them.

---

## Pairwise Prefix Comparison & Topological Sort
1. Identify all unique characters appearing across all words.
2. Compare adjacent word pairs $(w_1, w_2)$:
   - **Prefix Invalidation Check:** If $w_1$ is strictly longer than $w_2$ and $w_2$ is a prefix of $w_1$ (e.g. `["abc", "ab"]`), the dictionary ordering is inherently **illegal** $\implies$ return `""`.
   - Find the **first differing character**: at index $j$ where $w_1[j] \ne w_2[j]$.
   - This difference dictates the ordering: character $w_1[j]$ must precede $w_2[j] \implies$ add directed edge $w_1[j] \to w_2[j]$.
   - Break immediately to the next word pair (subsequent characters give no ordering information).
3. Run **Kahn's Topological Sort** over the character DAG:
   - If the resulting string contains all unique characters, return it.
   - If a cycle exists, topological sort length $<$ total unique characters $\implies$ return `""`.

---

## Complexity Analysis
- **Time Complexity:** $O(C + \sum |w_i|)$ where $C$ is the alphabet size (at most 26).
- **Space Complexity:** $O(C + E) = O(1)$ since alphabet size $C \le 26$.

