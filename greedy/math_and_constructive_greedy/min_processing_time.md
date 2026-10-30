# Minimum Processing Time (LeetCode 2895)

## Problem Statement

You have $n$ processors, each having $4$ independent cores. The number of tasks to be executed is $4n$. Each task must be assigned to a unique core, and each core can only be used once.

You are given:
- An integer array `processorTime` representing the time each processor becomes available.
- An integer array `tasks` representing how long each task takes to complete.

Each processor executes its assigned 4 tasks concurrently across its 4 cores. Therefore, the time a processor finishes all 4 tasks is:
$$\text{processorTime}[i] + \max(\text{the 4 tasks assigned to processor } i)$$

Return the **minimum time needed to complete all tasks** across all processors:
$$\min \left( \max_{i=0}^{n-1} (\text{processorTime}[i] + \max(\text{assigned tasks})) \right)$$

---

## Examples

### Example 1
- **Input:** `processorTime = [8, 10]`, `tasks = [2, 2, 3, 1, 8, 7, 4, 5]`
- **Output:** `16`
- **Explanation:**
  - Assign the 4 largest tasks $[8, 7, 5, 4]$ to processor $0$ (available at time $8$). Max completion = $8 + 8 = 16$.
  - Assign the 4 remaining smaller tasks $[3, 2, 2, 1]$ to processor $1$ (available at time $10$). Max completion = $10 + 3 = 13$.
  - Total time = $\max(16, 13) = 16$.

### Example 2
- **Input:** `processorTime = [10, 20]`, `tasks = [2, 3, 1, 2, 5, 8, 4, 3]`
- **Output:** `23`
- **Explanation:**
  - Processor at time $10$: assigned $[8, 5, 4, 3] \implies 10 + 8 = 18$.
  - Processor at time $20$: assigned $[3, 2, 2, 1] \implies 20 + 3 = 23$.
  - Total time = $\max(18, 23) = 23$.

---

## Constraints

- $1 \le n == \text{processorTime.length} \le 25000$
- $\text{tasks.length} == 4n$
- $0 \le \text{processorTime}[i] \le 10^9$
- $1 \le \text{tasks}[i] \le 10^9$

---

## The Greedy Pairing Strategy

To minimize the overall maximum completion time, we apply the **Rearrangement Inequality**:
- Pair the **earliest available processors** with the **longest tasks**.
- Pair the **latest available processors** with the **shortest tasks**.

### Algorithm:
1. Sort `processorTime` in ascending order (earliest to latest).
2. Sort `tasks` in descending order (longest to shortest).
3. For processor $i \in [0, n - 1]$:
   - The 4 tasks assigned to it are at indices $[4i, 4i + 1, 4i + 2, 4i + 3]$.
   - Since `tasks` is sorted descending, the largest among the four is strictly `tasks[4 * i]`.
   - Completion time for processor $i$ is `processorTime[i] + tasks[4 * i]`.
4. Overall answer is $\max_{i=0}^{n-1} (\text{processorTime}[i] + \text{tasks}[4 * i])$.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Greedy Dual-Sort** | $O(N \log N + M \log M)$ where $M = 4N$ | $O(1)$ |

