# Trie Implementation and Operations (Trie I)

## Problem Statement
Implement a **Trie (Prefix Tree)** data structure with the following fundamental operations:
1. `void insert(string word)`: Inserts the string `word` into the trie.
2. `bool search(string word)`: Returns `true` if the string `word` is in the trie (i.e., was previously inserted), and `false` otherwise.
3. `bool startsWith(string prefix)`: Returns `true` if there is a previously inserted string that has the prefix `prefix`, and `false` otherwise.

All inputs consist strictly of lowercase English letters (`'a'` through `'z'`).

---

## 1. Node Architecture & Invariants

```
                [Root]
               /      \
             'a'      'b'
             /          \
           'p'          'a'
           /              \
         'p'              't' (flag=true: "bat")
        /   \
      'l'   (flag=true: "app")
      /
    'e' (flag=true: "apple")
```

Each `TrieNode` represents a state transition for 26 possible character edges:
```cpp
struct TrieNode {
    TrieNode* links[26];
    bool flag = false; // Indicates if this node terminates a complete word

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, TrieNode* node) {
        links[ch - 'a'] = node;
    }

    TrieNode* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};
```

---

## 2. Operation Mechanics

### A. `insert(word)`
- Start at `root`.
- For each character `ch` in `word`:
  - If `!node->containsKey(ch)`, allocate a new `TrieNode` and link it.
  - Advance `node = node->get(ch)`.
- Mark the final node: `node->setEnd()`.
- **Complexity:** $O(L)$ time, where $L = \text{length}(word)$.

### B. `search(word)`
- Start at `root`.
- For each character `ch` in `word`:
  - If `!node->containsKey(ch)`, word was never inserted $\longrightarrow$ return `false`.
  - Advance `node = node->get(ch)`.
- Return `node->isEnd()`. (A prefix that wasn't explicitly marked as a word will return `false`).
- **Complexity:** $O(L)$ time.

### C. `startsWith(prefix)`
- Start at `root`.
- For each character `ch` in `prefix`:
  - If `!node->containsKey(ch)`, return `false`.
  - Advance `node = node->get(ch)`.
- If the entire prefix path exists, return `true` (regardless of whether `node->isEnd()` is true or false).
- **Complexity:** $O(P)$ time, where $P = \text{length}(prefix)$.

---

## 3. Complexity Analysis
- **Time Complexity:**
  - `insert`: $O(L)$
  - `search`: $O(L)$
  - `startsWith`: $O(P)$
- **Space Complexity:** $O(N \cdot L \cdot 26)$ worst-case for $N$ words of length $L$ with disjoint characters. Common prefixes share nodes, drastically compressing memory.

