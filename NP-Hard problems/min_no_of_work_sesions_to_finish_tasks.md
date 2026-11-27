
# LC 1986. Minimum Number of Work Sessions to Finish the Tasks

## Problem Statement

There are `n` tasks assigned to you. The task times are represented by an integer array `tasks` of length `n`, where `tasks[i]` represents the number of hours required to finish the `i-th` task.

A work session is a period during which you work for at most `sessionTime` consecutive hours and then take a break.

You must finish all tasks while satisfying the following conditions:

1. If you start a task in a work session, you must complete it in the same work session.
2. You can start a new task immediately after finishing the previous one.
3. You may complete the tasks in any order.

Given `tasks` and `sessionTime`, return the **minimum number of work sessions** needed to finish all the tasks.

It is guaranteed that `sessionTime` is greater than or equal to the maximum task duration.

---

## Examples

### Example 1

**Input:**
```cpp
tasks = [1, 2, 3]
sessionTime = 3
````

**Output:**

```
2
```

**Explanation:**

You can finish all tasks in two work sessions.

- First work session: Finish the first and second tasks in `1 + 2 = 3` hours.
- Second work session: Finish the third task in `3` hours.

### **Example 2**

**Input:**

```
tasks = [3, 1, 3, 1, 1]
sessionTime = 8
```

**Output:**

```
2
```

**Explanation:**

You can finish all tasks in two work sessions.

- First work session: Finish all tasks except the last one in `3 + 1 + 3 + 1 = 8` hours.
- Second work session: Finish the last task in `1` hour.

### **Example 3**

**Input:**

```
tasks = [1, 2, 3, 4, 5]
sessionTime = 15
```

**Output:**

```
1
```

**Explanation:**

You can finish all tasks in one work session because the total duration is `1 + 2 + 3 + 4 + 5 = 15` hours.

## **Constraints**

- `n == tasks.length`
- `1 <= n <= 14`
- `1 <= tasks[i] <= 10`
- `max(tasks[i]) <= sessionTime <= 15`
