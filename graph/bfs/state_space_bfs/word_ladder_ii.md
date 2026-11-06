# Word Ladder II (LeetCode 126)

## Problem Overview
A transformation sequence from `beginWord` to `endWord` using a dictionary `wordList` changes exactly one letter per step, with all intermediate words existing in `wordList`.
Given `beginWord`, `endWord`, and `wordList`, return **all the shortest transformation sequences** from `beginWord` to `endWord`, or an empty list if no such sequence exists.

---

## 2-Phase Architecture: BFS Distances + DFS Backtracking
A naive BFS storing full paths (`queue<vector<string>>`) crashes with **Memory Limit Exceeded (MLE)** on large dictionaries due to exponential path cloning.
The production-grade optimal design splits the problem into two distinct phases:

### Phase 1: Forward Level BFS (Distance Mapping)
1. Maintain an `unordered_map<string, int> dist` recording the shortest distance from `beginWord` to every word.
2. Run standard BFS starting at `beginWord` (`dist[beginWord] = 0`).
3. Stop expanding when `endWord` is reached or the queue empties.

### Phase 2: Backward DFS Backtracking
1. Start at `endWord` and traverse **backwards** toward `beginWord`.
2. A predecessor word `prev` is on a shortest path if and only if:
   $$\text{dist}[prev] == \text{dist}[curr] - 1$$
3. When `beginWord` is reached, reverse the collected path and append to results.
4. This guarantees that **zero dead-end exploration occurs** during path reconstruction!

---

## Complexity Analysis
- **Time Complexity:** $O(N \times L^2 + K \times L)$ where $K$ is the number of valid shortest paths.
- **Space Complexity:** $O(N \times L)$ for dictionary and distance map (avoids MLE).

