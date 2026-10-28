**2895. Minimum Processing Time**

You have a certain number of processors, each having 4 cores. The number of tasks to be executed is four times the number of processors. Each task must be assigned to a unique core, and each core can only be used once.

You are given an array `processorTime` representing the time each processor becomes available and an array `tasks` representing how long each task takes to complete. Return the *minimum* time needed to complete all tasks.

---

### Examples

**Example 1:**

* **Input:** `processorTime = [8,10]`, `tasks = [2,2,3,1,8,7,4,5]`
* **Output:** `16`
* **Explanation:**
* Assign the tasks at indices $4, 5, 6, 7$ (times $8, 7, 4, 5$) to processor $0$ which becomes available at time $8$. The processor finishes when the longest task finishes: $\max(8 + 8, 8 + 7, 8 + 4, 8 + 5) = 16$.
* Assign the tasks at indices $0, 1, 2, 3$ (times $2, 2, 3, 1$) to processor $1$ which becomes available at time $10$. The processor finishes at: $\max(10 + 2, 10 + 2, 10 + 3, 10 + 1) = 13$.
* The total time to finish all tasks is $\max(16, 13) = 16$.



**Example 2:**

* **Input:** `processorTime = [10,20]`, `tasks = [2,3,1,2,5,8,4,3]`
* **Output:** `23`
* **Explanation:**
* Assign the 4 largest tasks ($8, 5, 4, 3$) to the processor available first (time $10$): $\max(10 + 8, 10 + 5, 10 + 4, 10 + 3) = 18$.
* Assign the remaining 4 tasks ($3, 2, 2, 1$) to the processor available at time $20$: $\max(20 + 3, 20 + 2, 20 + 2, 20 + 1) = 23$.
* The total time needed is $\max(18, 23) = 23$.



---

### Constraints

* `1 <= n == processorTime.length <= 25,000`
* `1 <= tasks.length <= 100,000`
* `tasks.length == 4 * n`
* `0 <= processorTime[i] <= 10^9`
* `1 <= tasks[i] <= 10^9`