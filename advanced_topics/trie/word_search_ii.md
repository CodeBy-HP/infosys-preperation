# Problem 4: Word Search II (LeetCode 212)

## Problem Statement

Given an $m \times n$ `board` of characters and a list of strings `words`, return **all words on the board**.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. **The same letter cell may not be used more than once in a word**.

---

## Examples

### Example 1
```text
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]
```
- **Output:** `["eat","oath"]`

### Example 2
```text
board = [
  ['a','b'],
  ['c','d']
]
words = ["abcb"]
```
- **Output:** `[]`

---

## Constraints

- $m == \text{board.length}$
- $n == \text{board}[i]\text{.length}$
- $1 \le m, n \le 12$
- `board[i][j]` is a lowercase English letter.
- $1 \le \text{words.length} \le 3 \times 10^4$
- $1 \le \text{words}[i]\text{.length} \le 10$
- `words[i]` consists of lowercase English letters.
- All the strings of `words` are unique.

---

## The Paradigm: Trie-Guided DFS with Backtracking

If you run a separate DFS for each of the $30,000$ words, runtime is $O(W \times M \times N \times 4^L)$, resulting in an immediate **Time Limit Exceeded (TLE)**.

Instead, we insert all dictionary words into a **single Trie**, allowing the board's DFS to search for all $30,000$ words simultaneously in a single pass!

### The Two Major Optimizations:
1. **Store Word at Leaf (`node->word = word`):**
   - Eliminates string concatenation and tracking across DFS parameters.
   - When a word is matched, add `node->word` to `results` and clear `node->word = ""` to prevent duplicate entries if multiple paths form the same word.
2. **In-Situ Trie Pruning (Aggressive Optimization):**
   - Track `childCount` on each TrieNode.
   - Once a leaf word is harvested and has no remaining children, prune the node immediately from its parent, preventing subsequent DFS paths from ever traversing dead branches again!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Naive DFS per Word** | $O(W \cdot M \cdot N \cdot 4^L)$ $\rightarrow$ TLE | $O(L)$ stack |
| **Trie-Guided DFS** | $O(M \cdot N \cdot 4^{\min(L, MN)})$ | $O(\sum |W_i|)$ for Trie |
| **Trie-Guided DFS with Pruning** | Fastest in practice (prunes dead paths) | $O(\sum |W_i|)$ for Trie |

