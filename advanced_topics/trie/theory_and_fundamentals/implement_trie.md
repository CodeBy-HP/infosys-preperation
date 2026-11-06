# Implement Trie / Prefix Tree (LeetCode 208)

## Problem Statement

A **trie** (pronounced as "try") or **prefix tree** is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the `Trie` class:
- `Trie()` Initializes the trie object.
- `void insert(String word)` Inserts the string `word` into the trie.
- `boolean search(String word)` Returns `true` if the string `word` is in the trie (i.e., was inserted before), and `false` otherwise.
- `boolean startsWith(String prefix)` Returns `true` if there is a previously inserted string `word` that has the prefix `prefix`, and `false` otherwise.

---

## Examples

### Example 1
- **Input:**
  ```cpp
  Trie trie;
  trie.insert("apple");
  trie.search("apple");   // return True
  trie.search("app");     // return False
  trie.startsWith("app"); // return True
  trie.insert("app");
  trie.search("app");     // return True
  ```

---

## Constraints

- $1 \le \text{word.length}, \text{prefix.length} \le 2000$
- `word` and `prefix` consist only of lowercase English letters.
- At most $3 \times 10^4$ calls in total will be made to `insert`, `search`, and `startsWith`.

---

## Architecture & Logic

A Trie node represents a character transition:
1. **Node Structure:**
   - Fixed array of 26 child pointers (`children[26]`) for lowercase English letters (or a hash map for arbitrary Unicode).
   - Boolean flag `isEndOfWord`: distinguishes complete words from mere prefixes.
2. **Operations:**
   - **`insert(word)`:** Traverse character-by-character starting at `root`. Allocate missing child nodes as needed. Set `isEndOfWord = true` at the final character's node.
   - **`search(word)`:** Traverse the path. If any character pointer is `null`, return `false`. Return `isEndOfWord` at the final node.
   - **`startsWith(prefix)`:** Traverse the path. If all characters exist, return `true` regardless of `isEndOfWord`.
   - **`remove(word)`:** Recursively delete nodes with zero remaining children to reclaim memory.

---

## Complexity Analysis

| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **`insert(word)`** | $O(L)$ where $L = |word|$ | $O(L \times \Sigma)$ in worst case |
| **`search(word)`** | $O(L)$ | $O(1)$ |
| **`startsWith(prefix)`** | $O(P)$ where $P = |prefix|$ | $O(1)$ |
| **Total Memory** | — | $O(\text{Total characters} \times \Sigma)$ |

