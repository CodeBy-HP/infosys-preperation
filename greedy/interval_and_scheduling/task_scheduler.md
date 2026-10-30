# Problem 4: Task Scheduler (LeetCode 621)

## Problem Statement

You are given an array of CPU `tasks`, each represented by a letter from `'A'` to `'Z'`, and an integer cooling interval `n`.

Each CPU cycle can execute exactly one task. Tasks may be completed in any order, with one condition:
**Identical tasks must be separated by at least $n$ cooling cycles**, during which the CPU can either execute different tasks or sit idle.

Return the **least number of units of time (CPU cycles)** required to finish all given tasks.

---

## Examples

### Example 1
- **Input:** `tasks = ["A", "A", "A", "B", "B", "B"], n = 2`
- **Output:** `8`
- **Explanation:**
  A possible sequence is: `A -> B -> idle -> A -> B -> idle -> A -> B`.
  Total time = 8 cycles.

### Example 2
- **Input:** `tasks = ["A", "C", "A", "B", "D", "B"], n = 1`
- **Output:** `6`
- **Explanation:**
  A possible sequence is: `A -> B -> C -> A -> D -> B`.
  No idle slots needed because different tasks naturally fill cooling gaps.

### Example 3
- **Input:** `tasks = ["A", "A", "A", "B", "B", "B"], n = 3`
- **Output:** `10`
- **Explanation:**
  `A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B`. Total = 10 cycles.

---

## Constraints

- $1 \le \text{tasks.length} \le 10^4$
- `tasks[i]` is an uppercase English letter.
- $0 \le n \le 100$

---

## The Two Approaches

### 1. Greedy Simulation (Max-Heap + Cooldown Queue)
- **Principle:** Always prioritize executing the task with the **highest remaining frequency** to prevent a bottleneck of high-frequency tasks clustering at the end.
- Use a **Max-Heap** to extract the task with the highest frequency.
- Decrement its count and place it in a **Cooldown Queue** with its unlock timestamp `current_time + n`.
- When `current_time == unlock_time`, push it back to the Max-Heap.
- If the heap is empty but the queue is not, the CPU sits idle.

### 2. Closed-Form Mathematical Formula ($O(N)$ Time, $O(1)$ Space)
Let `max_freq` be the maximum frequency of any task, and `count_max` be the number of tasks sharing that maximum frequency.
1. The most frequent task sets up `max_freq - 1` chunks of size `(n + 1)`.
2. The final chunk only contains the tasks that had `max_freq`:
   $$\text{Frame Size} = (\text{max\_freq} - 1) \times (n + 1) + \text{count\_max}$$
3. **The Abundant Tasks Catch:** If there are more than enough tasks to fill all idle slots, no idling is required at all:
   $$\text{Total Time} = \max(\text{Frame Size},\, \text{tasks.size()})$$

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Max-Heap + Queue Simulation** | $O(\text{Total Cycles} \log 26) \approx O(\text{Time})$ | $O(1)$ | Direct behavioral simulation |
| **Optimal Mathematical Formula** | $O(N)$ | $O(1)$ | $26$-element frequency array |

