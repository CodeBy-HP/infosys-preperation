# Maximum Total Mode Frequency Score (Partition DP)

## Problem Statement

You are given an array of size $n$ and an integer $k$. You must partition the array into exactly $k$ non-empty contiguous groups:
$$P_1 = \text{nums}[0 \dots i_1 - 1], \quad P_2 = \text{nums}[i_1 \dots i_2 - 1], \quad \dots, \quad P_k = \text{nums}[i_{k-1} \dots n - 1]$$
where $0 < i_1 < i_2 < \dots < i_{k-1} < n$.

The **score** of a single group is defined by its **mode frequency** — the frequency of the most frequent element within that specific group.

Your task is to find the **maximum possible total mode frequency score** (the sum of the scores of all $k$ groups) across all valid partitions.

---

## Examples

### Example 1
- **Input:** `nums = [1, 2, 1, 2, 3, 3, 3]`, `k = 3`
- **Output:** `6`
- **Explanation:**
  - Group 1: `[1, 2, 1]` $\to$ element `1` appears twice, mode frequency = `2`.
  - Group 2: `[2]` $\to$ element `2` appears once, mode frequency = `1`.
  - Group 3: `[3, 3, 3]` $\to$ element `3` appears 3 times, mode frequency = `3`.
  - Total score = $2 + 1 + 3 = 6$.

### Example 2
- **Input:** `nums = [4, 4, 4, 4]`, `k = 2`
- **Output:** `4`
- **Explanation:**
  - Split as `[4, 4]` (freq 2) and `[4, 4]` (freq 2), total = $2 + 2 = 4$.
  - Any 2-group partition of identical elements yields $x + (4 - x) = 4$.

### Example 3
- **Input:** `nums = [1, 2, 3, 4]`, `k = 4`
- **Output:** `4`
- **Explanation:**
  - Each group has 1 element, frequency = 1 each, total = 4.

---

## Constraints

- $1 \le k \le n \le 1000$ (or up to $2000$)
- $1 \le \text{nums}[i] \le 10^9$ (or within $1 \le \text{nums}[i] \le n$ after coordinate compression)

---

## Algorithmic Paradigm: Partition Dynamic Programming

### 1. Cost Matrix Precomputation: $M[i][j]$
Let $M[i][j]$ denote the mode frequency of the subarray $\text{nums}[i \dots j]$ ($0 \le i \le j < n$).
For a fixed left boundary $i$, as $j$ increases from $i$ to $n-1$, we maintain a hash map (or frequency array) of counts and track the running maximum frequency:
$$M[i][j] = \max(M[i][j - 1], \text{freq}[\text{nums}[j]])$$
Precomputing $M[i][j]$ for all $0 \le i \le j < n$ takes $O(n^2)$ time and $O(n^2)$ memory.

### 2. DP State Formulation
Let $dp[g][j]$ be the maximum total mode frequency score from partitioning the prefix $\text{nums}[0 \dots j - 1]$ into exactly $g$ groups ($1 \le g \le k$ and $g \le j \le n$).

- **Base Case ($g = 1$):**
  $$dp[1][j] = M[0][j - 1] \quad \text{for all } 1 \le j \le n$$

- **Transition ($2 \le g \le k$):**
  To form $g$ groups ending at index $j - 1$, the $g$-th group begins at some pivot index $p$ ($g - 1 \le p < j$) and spans $\text{nums}[p \dots j - 1]$:
  $$dp[g][j] = \max_{g - 1 \le p < j} \Big( dp[g - 1][p] + M[p][j - 1] \Big)$$

- **Space Optimization:**
  Row $g$ depends only on row $g - 1$. We can maintain two 1D rows (`prev_dp` and `curr_dp`) of size $n + 1$, reducing DP space to $O(n)$.

---

## Complexity Analysis

| Step | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Cost Precomputation $M[i][j]$** | $O(n^2)$ | $O(n^2)$ |
| **DP Transitions** | $O(k \cdot n^2)$ | $O(n)$ |
| **Total** | $\mathcal{O}(k \cdot n^2)$ | $\mathcal{O}(n^2)$ |

