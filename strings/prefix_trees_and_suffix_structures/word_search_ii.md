# Problem 19: Word Search II (LeetCode 212)

## Problem Statement

Given an $m \times n$ `board` of characters and a list of strings `words`, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

---

## Examples

### Example 1
- **Input:**
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

---

## Constraints

- $m == \text{board.length}$
- $n == \text{board}[i]\text{.length}$
- $1 \le m, n \le 12$
- $1 \le \text{words.length} \le 3 \times 10^4$

---

## Pattern: 2D Grid DFS with Trie Prefix Pruning

Instead of running DFS for every single word ($O(W \times M \times N \times 4^L)$), insert all words into a **Trie** and walk the grid **once**:
1. Store full word in `TrieNode::word` at terminal nodes.
2. Step onto `board[r][c]`. If character is not in current Trie node's children, backtrack immediately!
3. Mark visited in-place: `char temp = board[r][c]; board[r][c] = '#';`
4. Explore 4 directions.
5. Restore `board[r][c] = temp;`
6. Pruning optimization: Clear `node->word.clear()` once found to prevent duplicate entries.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Grid DFS + Trie Pruning** | $O(M \times N \times 4^{\min(L, M \times N)})$ | $O(\sum |W|)$ |
