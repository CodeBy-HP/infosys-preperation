# Task Scheduler (LeetCode 621)

## Problem Overview
Given a characters array `tasks`, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.
However, there is a non-negative integer `n` that represents the **cooldown period** between two same tasks (i.e. if task `A` is done at time `t`, task `A` cannot be done until time `t + n + 1`).
Return the **least number of units of times** that the CPU will take to finish all the given tasks.

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

