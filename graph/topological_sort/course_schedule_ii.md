# Course Schedule II (LeetCode 210)

## Problem Statement
There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`. You are given an array `prerequisites` where `prerequisites[i] = [a_i, b_i]` indicates that you **must take course $b_i$ first** if you want to take course $a_i$.

Return the **ordering of courses** you should take to finish all courses.
- If there are many valid answers, return **any** of them.
- If it is impossible to finish all courses (due to a circular dependency), return an **empty array**.

---

## Constraints
* `1 <= numCourses <= 2000`
* `0 <= prerequisites.length <= numCourses * (numCourses - 1)`
* `prerequisites[i].length == 2`
* `0 <= a_i, b_i < numCourses`
* `a_i != b_i` (no self-loops).
* All pairs `[a_i, b_i]` are **distinct**.

---

## Examples

### Example 1
**Input:**
```text
numCourses = 2, prerequisites = [[1, 0]]
```
**Output:**
```text
[0, 1]
```
**Explanation:**
There are a total of 2 courses. To take course 1 you should have finished course 0. So the correct course order is `[0, 1]`.

---

### Example 2
**Input:**
```text
numCourses = 4, prerequisites = [[1, 0], [2, 0], [3, 1], [3, 2]]
```
**Output:**
```text
[0, 2, 1, 3]  (or [0, 1, 2, 3])
```
**Explanation:**
- Course 0 has no prerequisites, so it can be taken first.
- Courses 1 and 2 require course 0.
- Course 3 requires both courses 1 and 2.
Both `[0, 1, 2, 3]` and `[0, 2, 1, 3]` are valid topological orders.

```
      (1)
     ^   \
    /     v
  (0)     (3)
    \     ^
     v   /
      (2)
```

---

### Example 3
**Input:**
```text
numCourses = 2, prerequisites = [[0, 1], [1, 0]]
```
**Output:**
```text
[]
```
**Explanation:**
Circular dependency between 0 and 1. No valid course sequence exists.

---

## Algorithmic Approaches

### Kahn's Algorithm (Topological Sort via BFS)
1. Build adjacency list: For each `[a, b]`, add directed edge $b \to a$ and increment `inDegree[a]++`.
2. Push all nodes with `inDegree[i] == 0` into queue.
3. Maintain an `order` vector.
4. While queue is non-empty:
   - Pop `curr`.
   - `order.push_back(curr)`.
   - For each neighbor `next` of `curr`:
     - Decrement `inDegree[next]--`.
     - If `inDegree[next] == 0`, push `next` into queue.
5. If `order.size() == numCourses`, return `order`. Otherwise return `[]` (cycle detected).

---

## Complexity Analysis
- **Time Complexity:** $O(V + E)$ where $V = \text{numCourses}$ and $E = \text{prerequisites.length}$.
- **Space Complexity:** $O(V + E)$ for adjacency list, $O(V)$ for queue and in-degree tracking.
