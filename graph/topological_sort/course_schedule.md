# Course Schedule I (LeetCode 207)

## Problem Statement
There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`. You are given an array `prerequisites` where `prerequisites[i] = [a_i, b_i]` indicates that you **must take course $b_i$ first** if you want to take course $a_i$.

- For example, the pair `[0, 1]` indicates that to take course `0` you have to first take course `1` (directed edge: $1 \to 0$).

Return `true` if you can finish all courses. Otherwise, return `false`.

---

## Constraints
* `1 <= numCourses <= 2000`
* `0 <= prerequisites.length <= 5000`
* `prerequisites[i].length == 2`
* `0 <= a_i, b_i < numCourses`
* All the pairs `prerequisites[i]` are **unique**.

---

## Examples

### Example 1
**Input:**
```text
numCourses = 2, prerequisites = [[1, 0]]
```
**Output:**
```text
true
```
**Explanation:**
There are 2 courses to take. To take course 1 you must first finish course 0 ($0 \to 1$). This is feasible: take course 0, then course 1.

---

### Example 2
**Input:**
```text
numCourses = 2, prerequisites = [[1, 0], [0, 1]]
```
**Output:**
```text
false
```
**Explanation:**
To take course 1 you must have finished course 0, and to take course 0 you must have finished course 1. This creates a circular dependency (directed cycle), making it impossible to complete all courses.

```
(0) <=====> (1)
  (Circular Dependency / Deadlock)
```

---

## Algorithmic Approaches

### Equivalence to Directed Cycle Detection
Completing all courses is possible **if and only if the dependency graph is a Directed Acyclic Graph (DAG)**.

### Approach 1: Kahn's Algorithm (BFS In-Degree)
1. Build adjacency list: For each `[a, b]`, add edge $b \to a$ and increment `inDegree[a]++`.
2. Push all courses with `inDegree[i] == 0` into queue.
3. Maintain `completedCourses = 0`.
4. While queue is non-empty:
   - Pop `curr`, increment `completedCourses++`.
   - For each neighbor `next` of `curr`:
     - Decrement `inDegree[next]--`.
     - If `inDegree[next] == 0`, push to queue.
5. Return `completedCourses == numCourses`.

### Approach 2: DFS 3-Coloring / Path Visited
Maintain `vis` and `pathVis`:
- If an adjacent node is currently on `pathVis`, return `false` (cycle detected).

---

## Complexity Analysis
- **Time Complexity:** $O(V + E)$ where $V = \text{numCourses}$ and $E = \text{prerequisites.length}$.
- **Space Complexity:** $O(V + E)$ for adjacency list and $O(V)$ for queue and in-degree tracking.
