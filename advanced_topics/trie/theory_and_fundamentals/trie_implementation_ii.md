# Trie Implementation with Advanced Operations (Trie II)

## Problem Statement
Implement an **Advanced Trie (Prefix Tree)** supporting word frequency tracking, prefix counting, and word deletion:
1. `void insert(string word)`: Inserts `word` into the trie (allows duplicate words).
2. `int countWordsEqualTo(string word)`: Returns how many times `word` was inserted.
3. `int countWordsStartingWith(string prefix)`: Returns how many words in the trie have `prefix` as their prefix.
4. `void erase(string word)`: Erases one occurrence of `word` from the trie.

---

## 1. Node Architecture (Frequency Counters)

Instead of a binary boolean flag, each node tracks two integer counters:
```cpp
struct TrieNode {
    TrieNode* links[26];
    int countEndsWith = 0; // Number of inserted words ending exactly at this node
    int countPrefix = 0;   // Number of inserted words sharing this node as a prefix

    TrieNode() {
        for (int i = 0; i < 26; ++i) links[i] = nullptr;
    }
};
```

---

## 2. Operation Mechanics

### A. `insert(word)`
- Traverse `word` character-by-character.
- If a child node does not exist, allocate it.
- Advance to the child node, and increment its prefix counter:
  $$\text{node}\to\text{countPrefix}++$$
- Upon reaching the terminal node, increment the exact word counter:
  $$\text{node}\to\text{countEndsWith}++$$

### B. `countWordsEqualTo(word)`
- Traverse `word`.
- If any character link is `nullptr`, the word does not exist $\longrightarrow$ return `0`.
- At the end of the word, return `node->countEndsWith`.

### C. `countWordsStartingWith(prefix)`
- Traverse `prefix`.
- If any character link is `nullptr`, no such prefix exists $\longrightarrow$ return `0`.
- At the end of `prefix`, return `node->countPrefix`.

### D. `erase(word)`
- Precondition: `word` is assumed to exist in the Trie.
- Traverse `word` character-by-character.
- At each step, decrement the prefix count:
  $$\text{node}\to\text{countPrefix}--$$
- At the final node, decrement the word termination count:
  $$\text{node}\to\text{countEndsWith}--$$

---

## 3. Complexity Analysis
- **Time Complexity:**
  - `insert(word)`: $O(L)$
  - `countWordsEqualTo(word)`: $O(L)$
  - `countWordsStartingWith(prefix)`: $O(P)$
  - `erase(word)`: $O(L)$
- **Space Complexity:** $O(N \cdot L \cdot 26)$ worst-case.

