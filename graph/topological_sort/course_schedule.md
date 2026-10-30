### Problem 9: Course Schedule (Topological Sort)

We are officially leaving the 2D grid. Instead of moving up, down, left, and right, we are now moving along strictly one-way streets: **Directed Graphs**.

**Problem Statement:**
You have to take `N` courses, labeled from `0` to `N-1`. You are given an array of `prerequisites` where `prerequisites[i] = [A, B]` means you **must** take course `B` before you can take course `A`.

**Your Task:**
Return `true` if it is possible for you to finish all courses. Otherwise, return `false`.

**Sample Input 1:**

```text
N = 2, Prerequisites = [[1, 0]]

```

**Sample Output 1:**

```text
true

```

*(Explanation: To take course 1, you must first take course 0. You can take 0, then 1. Perfectly valid.)*

**Sample Input 2:**

```text
N = 2, Prerequisites = [[1, 0], [0, 1]]

```

**Sample Output 2:**

```text
false

```

*(Explanation: To take 1, you need 0. But to take 0, you need 1. This creates a Mexican standoff (a Cycle). Neither can be taken.)*

---

### The Paradigm Shift: Indegrees

In grid problems, you cared about coordinates `(x, y)`. In Directed Graphs, you care about dependencies. The most powerful way to solve this is using **Kahn's Algorithm** (which is just a specialized BFS).

Instead of a `visited` array, we introduce a brilliant new concept: the **Indegree Array**.
The "Indegree" of a node is exactly how many arrows are pointing *at* it. In this problem, a course's Indegree is simply its number of unfinished prerequisites.

**The Strategy:**

1. **Count Indegrees:** Scan the prerequisites and count how many dependencies every course has.
2. **The Queue of Freedom:** Find every course with an Indegree of `0` (meaning it requires nothing) and push it into a standard BFS queue.
3. **The Chain Reaction:** Pop a course from the queue. You just "graduated" from it! Now, look at every advanced course that depended on it, and decrease their Indegree by 1.
4. **Unlock:** If any advanced course drops to an Indegree of `0`, it is now unlocked! Push it into the queue.

If you finish this process and you were able to take all `N` courses, you win. If some courses are left with Indegrees $> 0$, it means they were trapped in a cycle and could never be unlocked.