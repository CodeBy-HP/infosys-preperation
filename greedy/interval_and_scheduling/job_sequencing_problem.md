# Job Sequencing Problem

## Problem Overview
Given a set of $N$ jobs where every job $i$ has a deadline $D_i$ and a profit $P_i$.
Each job takes **1 unit of time** to complete, and only one job can be scheduled on the CPU at any single time unit.
A job can only earn profit if it completes **on or before its deadline** (i.e. scheduled at some discrete time slot $t \in [1, D_i]$).
Find the **number of jobs completed** and the **maximum profit achievable**.

---

## Greedy Maximum-Profit Invariant
To maximize profit:
1. Sort all jobs in **descending order of profit** ($P_i$).
2. For each job, we want to schedule it as **late as possible** (at the latest unoccupied time slot $t \le D_i$).
   - *Why late?* Placing job $i$ at its deadline $D_i$ leaves earlier slots ($1, \dots, D_i - 1$) free for other jobs with tighter, earlier deadlines!

---

## Two Implementation Approaches

### Approach 1: Slot Array Linear Scan
Maintain a boolean array `slot[1 ... maxDeadline]` initialized to false.
For each job, scan backwards from $\min(N, D_i)$ down to $1$ to find the first empty slot.
- **Time Complexity:** $O(N \log N + N \times D_{\max})$
- **Space Complexity:** $O(D_{\max})$

### Approach 2: DSU Fast Slot Finding
Treat time slots as nodes in a Disjoint Set Union where `parent[t]` points to the **greatest available empty slot $\le t$**:
- If `root = find(deadline) > 0`:
  - Schedule the job at slot `root`.
  - Re-point `parent[root] = find(root - 1)`.
- **Time Complexity:** $O(N \log N + N \cdot \alpha(D_{\max}))$
- **Space Complexity:** $O(D_{\max})$

