# Word Ladder I (LeetCode 127)

## Problem Overview
A **transformation sequence** from word `beginWord` to word `endWord` using a dictionary `wordList` is a sequence of words `beginWord -> s1 -> s2 -> ... -> sk` such that:
- Every adjacent pair of words differs by exactly **one letter**.
- Every $s_i$ for $1 \le i \le k$ is in `wordList`. (Note that `beginWord` does not need to be in `wordList`).
- $s_k == endWord$.

Given two words, `beginWord` and `endWord`, and a dictionary `wordList`, return the **number of words in the shortest transformation sequence**, or `0` if no such sequence exists.

---

## State-Space BFS on Word Graphs
Because edge weights are uniform (1 character alteration = 1 step), **BFS guarantees finding the shortest path**.
1. Store all words of `wordList` in an `unordered_set<string> dict` for $O(1)$ lookups.
2. If `endWord` is not in `dict`, return `0` immediately.
3. Push `{beginWord, 1}` to a BFS queue and erase `beginWord` from `dict`.
4. While queue is not empty:
   - Pop `{word, steps}`.
   - If `word == endWord`, return `steps`.
   - For each character index $i \in [0, L-1]$:
     - Try replacing `word[i]` with every character from `'a'` to `'z'`.
     - If the newly formed word exists in `dict`:
       - Push `{newWord, steps + 1}`.
       - Erase `newWord` from `dict` (acting as the visited set to prevent revisiting).
5. If queue exhausts without reaching `endWord`, return `0`.

---

## Complexity Analysis
- **Time Complexity:** $O(N \times L \times 26 \times L) = O(N \times L^2)$ where $N = |wordList|$ and $L$ is word length.
- **Space Complexity:** $O(N \times L)$ for the hash set and queue.

