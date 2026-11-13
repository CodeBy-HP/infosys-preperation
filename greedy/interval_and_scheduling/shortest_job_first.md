# Shortest Job First (SJF) Scheduling

## Problem Overview
Geek is a software engineer. He is given an array of integers `bt` representing the burst times of $N$ processes.
Under non-preemptive Shortest Job First (SJF) CPU scheduling, find the **average waiting time** for all processes (rounded down to the nearest integer).
The waiting time for the first process is `0`. The waiting time for any subsequent process is the sum of burst times of all preceding completed processes.

---

## Rearrangement Inequality Proof
Let $B_1, B_2, \dots, B_N$ be the order in which processes are executed.
- Waiting time of process 1: $0$
- Waiting time of process 2: $B_1$
- Waiting time of process 3: $B_1 + B_2$
- Waiting time of process $k$: $\sum_{j=1}^{k-1} B_j$

The **total waiting time** summed across all $N$ processes is:
$$\text{Total Wait} = (N - 1) B_1 + (N - 2) B_2 + \dots + 1 \cdot B_{N-1} + 0 \cdot B_N = \sum_{k=1}^{N} (N - k) B_k$$
By the **Rearrangement Inequality**, to minimize the sum of products $\sum (N - k) B_k$ where coefficients $(N - k)$ are strictly decreasing, the values $B_k$ must be sorted in **strictly non-decreasing (ascending) order**!

---

## Complexity Analysis
- **Time Complexity:** $O(N \log N)$ to sort burst times.
- **Space Complexity:** $O(1)$ auxiliary space.

