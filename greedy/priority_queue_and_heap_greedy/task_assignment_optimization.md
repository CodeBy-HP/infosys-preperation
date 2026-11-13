# Task Assignment Optimization (Greedy + Max-Heap)

## Problem Statement

You are given $N$ tasks and $M$ workers.
- Each task $i$ ($0 \le i < N$) is defined by a minimum required skill level $D_i$ and a profit earned upon completion $W_i$.
- Each worker $j$ ($0 \le j < M$) possesses a specific skill level $S_j$.
- A worker $j$ can only complete a task $i$ if their skill level is greater than or equal to the task's required skill:
$$S_j \ge D_i$$

### Constraints
1. Each worker can be assigned to **at most one** task.
2. Each task can be assigned to **at most one** worker.

### Objective
Find the **maximum total profit** that can be achieved by optimally assigning tasks to workers.

---

## Examples

### Example 1
- **Input:**
  - `tasks = [(skill: 2, profit: 40), (skill: 4, profit: 100), (skill: 6, profit: 70), (skill: 8, profit: 60)]`
  - `workers = [4, 5, 8]`
- **Output:** `210`
- **Explanation:**
  - Worker with skill 4 performs task (skill: 4, profit: 100).
  - Worker with skill 5 performs task (skill: 2, profit: 40).
  - Worker with skill 8 performs task (skill: 6, profit: 70).
  - Total profit = $100 + 40 + 70 = 210$.

### Example 2
- **Input:**
  - `tasks = [(skill: 10, profit: 100)]`
  - `workers = [2, 3, 5]`
- **Output:** `0`
- **Explanation:** No worker has a skill level $\ge 10$.

---

## Constraints

- $1 \le N, M \le 10^5$
- $1 \le D_i, S_j \le 10^9$
- $1 \le W_i \le 10^9$

---

## Algorithmic Paradigm: Greedy with Max-Heap (Priority Queue)

### Why Greedy Works (Laminar / Nested Eligibility Sets)
1. Sort workers in ascending order of skill:
   $$S_1 \le S_2 \le \dots \le S_M$$
2. Let $E(j) = \{ \text{task } i \mid D_i \le S_j \}$ be the set of tasks that worker $j$ is qualified to perform.
3. Because skills are monotonically non-decreasing, the eligibility sets form a nested chain:
   $$E(1) \subseteq E(2) \subseteq \dots \subseteq E(M)$$
4. Any task eligible for worker $j$ is automatically eligible for all subsequent workers $j+1, \dots, M$. However, tasks in $E(j+1) \setminus E(j)$ can **only** be performed by worker $j+1$ or higher.
5. Therefore, allocating the **highest-profit eligible task** to worker $j$ from $E(j)$ via a Max-Heap is globally optimal by matroid theory and greedy choice exchange arguments.

---

## Step-by-Step Algorithm

1. **Sort Tasks:** Sort tasks in ascending order of difficulty $D_i$.
2. **Sort Workers:** Sort workers in ascending order of skill $S_j$.
3. **Iterate Workers:**
   - Maintain a pointer `task_idx = 0` and a max-heap `pq` storing task profits.
   - For each worker $j$:
     - While `task_idx < N` and $\text{tasks}[\text{task\_idx}].D \le S_j$, push $\text{tasks}[\text{task\_idx}].W$ into `pq` and advance `task_idx`.
     - If `pq` is not empty, pop the maximum profit task and add it to `total_profit`.
4. Return `total_profit`.

---

## Complexity Analysis

| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Sort Tasks & Workers** | $O(N \log N + M \log M)$ | $O(1)$ auxiliary |
| **Heap Operations** | $O((N + M) \log N)$ | $O(N)$ for max-heap |
| **Total** | $\mathcal{O}(N \log N + M \log M)$ | $\mathcal{O}(N)$ |

