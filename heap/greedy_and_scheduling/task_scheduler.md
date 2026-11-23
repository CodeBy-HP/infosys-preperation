
# Task Scheduler (LeetCode 621)

## Problem Overview

Given a characters array `tasks`, representing the tasks a CPU needs to do, where each letter represents a different task.

Tasks can be executed in any order. Each task takes **one unit of time**. For each unit of time, the CPU can either:

- Execute one task.
- Remain idle.

However, there is a non-negative integer `n` representing the **cooldown period** between two executions of the same task.

For example, if task `A` is executed at time `t`, it cannot be executed again until time `t + n + 1`.

Return the **minimum number of time units** required for the CPU to finish all the given tasks.

---

## Examples

### Example 1

**Input:**
```python
tasks = ["A", "A", "A", "B", "B", "B"]
n = 2
```

**Output:**
```python
8
```

**Explanation:**

A possible execution sequence is:

`A -> B -> idle -> A -> B -> idle -> A -> B`

After completing task A, you must wait two intervals before executing A again. The same applies to task B.

In the third interval, neither A nor B can be executed, so the CPU remains idle. By the fourth interval, A can be executed again.

### Example 2

**Input:**
```python
tasks = ["A", "C", "A", "B", "D", "B"]
n = 1
```

**Output:**
```python
6
```

**Explanation:**

A possible execution sequence is:

`A -> B -> C -> D -> A -> B`

With a cooldown period of 1, a task can be repeated after just one other task.

### Example 3

**Input:**
```python
tasks = ["A", "A", "A", "B", "B", "B"]
n = 3
```

**Output:**
```python
10
```

**Explanation:**

A possible execution sequence is:

`A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B`

There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to two idle intervals between repetitions of these tasks.

---

## Constraints

- `1 <= tasks.length <= 10^4`
- `tasks[i]` is an uppercase English letter.
- `0 <= n <= 100`


---

## Max-Heap & Cooldown Queue Mechanics
To minimize idle time, the CPU must always prioritize executing the task with the **highest remaining frequency**:
1. Count the frequency of each task.
2. Push all positive frequencies into a **Max-Heap**.
3. Use a queue `cooldownQueue` storing `{remainingFreq, readyTime}`.
4. For each time step `time = 1, 2, ...`:
   - If the task at front of `cooldownQueue` has `readyTime <= time`, push its `remainingFreq` back into the max-heap.
   - If the max-heap is non-empty:
     - Pop `freq = maxHeap.top()`.
     - Decrement `freq--`.
     - If `freq > 0`, push `{freq, time + n + 1}` into `cooldownQueue`.
   - (If max-heap is empty, CPU sits idle for this cycle).
   - Stop when both the max-heap and the cooldown queue are empty!

---

## Mathematical Formula Equivalence
Let $f_{\max}$ be the maximum frequency among all tasks, and $count_{\max}$ be the count of tasks having this maximum frequency.
$$\text{Min Time} = \max\Big(|tasks|, \; (f_{\max} - 1) \times (n + 1) + count_{\max}\Big)$$

---

## Complexity Analysis
- **Heap Simulation:** $O(|tasks| \log 26) = O(|tasks|)$ Time, $O(26) = O(1)$ Space.
- **Math Formula:** $O(|tasks|)$ Time, $O(1)$ Space.

