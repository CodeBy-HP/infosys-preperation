# Course Schedule II (LeetCode 210)

## Problem Overview
There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`. You are given an array `prerequisites` where `prerequisites[i] = [a_i, b_i]` indicates that you must take course $b_i$ first if you want to take course $a_i$ (directed edge $b_i \to a_i$).
Return the **ordering of courses** you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an **empty array**.

---

## Kahn's Algorithm Invariant
1. Build adjacency list `adj` and compute `inDegree` for every course.
2. Initialize a queue with all courses having `inDegree[c] == 0`.
3. Process courses in FIFO order, appending each to a vector `order`.
4. Decrement prerequisites of adjacent courses; if any reaches 0, push into queue.
5. **Cycle Guard:** If `order.size() == numCourses`, return `order`. Otherwise, a prerequisite cycle exists $\implies$ return `{}`.

---

## Complexity Analysis
- **Time Complexity:** $O(V + E)$ where $V = numCourses$ and $E = |prerequisites|$.
- **Space Complexity:** $O(V + E)$ for adjacency list and queue.

