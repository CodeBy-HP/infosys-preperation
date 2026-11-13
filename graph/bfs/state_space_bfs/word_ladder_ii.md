# Word Ladder II (LeetCode 126)

## Problem Statement
A **transformation sequence** from word `beginWord` to word `endWord` using a dictionary `wordList` is a sequence of words `beginWord -> s_1 -> s_2 -> ... -> s_k` such that:
1. Every adjacent pair of words differs by exactly **one letter**.
2. Every $s_i$ for $1 \le i \le k$ is in `wordList` (`beginWord` does not need to be in `wordList`).
3. $s_k == \text{endWord}$.

Given two words, `beginWord` and `endWord`, and a dictionary `wordList`, return **all the shortest transformation sequences** from `beginWord` to `endWord`, or an empty list if no such sequence exists. Each sequence should be returned as a list of words `[beginWord, s_1, s_2, ..., s_k]`.

---

## Constraints
* `1 <= beginWord.length <= 5`
* `endWord.length == beginWord.length`
* `1 <= wordList.length <= 500`
* `wordList[i].length == beginWord.length`
* `beginWord`, `endWord`, and `wordList[i]` consist of lowercase English letters.
* `beginWord != endWord`
* All strings in `wordList` are **unique**.
* The sum of all shortest transformation sequences is at most $10^5$.

---

## Examples

### Example 1
**Input:**
```text
beginWord = "hit", endWord = "cog", 
wordList = ["hot", "dot", "dog", "lot", "log", "cog"]
```
**Output:**
```text
[
  ["hit", "hot", "dot", "dog", "cog"],
  ["hit", "hot", "lot", "log", "cog"]
]
```
**Explanation:**
There are 2 shortest transformation sequences of length 5:
- `"hit" -> "hot" -> "dot" -> "dog" -> "cog"`
- `"hit" -> "hot" -> "lot" -> "log" -> "cog"`

```
          "hot"
         /     \
      "dot"   "lot"
        |       |
      "dog"   "log"
         \     /
          "cog"
```

---

### Example 2
**Input:**
```text
beginWord = "hit", endWord = "cog", 
wordList = ["hot", "dot", "dog", "lot", "log"]
```
**Output:**
```text
[]
```

---

## Algorithmic Approaches

### Why Naive BFS with Path Lists Causes Memory Limit Exceeded (MLE)
Storing full vectors of paths inside the queue (`queue<vector<string>>`) duplicates strings exponentially on branching paths, causing $O(2^L)$ memory overflows.

### The Two-Phase Optimal Solution (BFS + DFS Backtracking)
1. **Phase 1: BFS Level-Mapping (Shortest Distance Graph Construction)**
   - Run a forward BFS from `beginWord` to compute the minimum distance level of each reachable word:
     `unordered_map<string, int> levelMap`.
   - Record `levelMap[beginWord] = 0`.
   - When a word mutates to `nextWord` in `wordSet`:
     - If `nextWord` has not been visited:
       - Set `levelMap[nextWord] = levelMap[curr] + 1`.
       - Push `nextWord` into queue.
   - Stop BFS once `endWord` level is finalized.
2. **Phase 2: Reverse DFS Backtracking (from `endWord` to `beginWord`)**
   - Start from `endWord` and backtrack backwards towards `beginWord`.
   - A step from `curr` to an adjacent predecessor `prev` is part of a valid shortest path **if and only if**:
     $$\text{levelMap}[\text{prev}] == \text{levelMap}[\text{curr}] - 1$$
   - Push `curr` to the path, recurse on `prev`, and backtrack (`pop_back()`).
   - When reaching `beginWord`, reverse the collected path and append to results.

---

## Complexity Analysis
- **Time Complexity:** $O(N \cdot L \cdot 26)$ for BFS level graph + $O(K \cdot L)$ for DFS path backtracking where $K$ is total shortest paths.
- **Space Complexity:** $O(N \cdot L)$ — Only integer levels are stored per word in Phase 1, entirely eliminating the MLE risk.
