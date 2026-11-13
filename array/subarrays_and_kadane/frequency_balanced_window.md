# Problem 17: Frequency Balanced Window

## Problem Statement

You receive an upstream of $n$ data packets from a satellite. Each packet has two attributes:
1. `category`: An identifier indicating the packet type ($1 \le \text{category}[i] \le C$).
2. `weight`: A signal weight / data density score (can be positive, negative, or zero).

A monitoring window consisting of a contiguous range of packets from index $L$ to $R$ ($0 \le L \le R < n$) is considered **"frequency balanced"** if **at least one category appears strictly more than half the time** in that window (i.e., the category forms a strict majority within $[L, R]$):

$$\exists c \quad \text{such that} \quad \text{count}(c, [L, R]) > \frac{R - L + 1}{2}$$

Your task is to find the **maximum total weight** among all possible frequency balanced windows:
$$\max_{\substack{0 \le L \le R < n \\ \text{window is balanced}}} \sum_{i = L}^R \text{weight}[i]$$

---

## Examples

### Example 1
- **Input:**
  - `categories = [1, 2, 1, 1, 3]`
  - `weights = [5, -2, 4, 3, -10]`
- **Output:** `10`
- **Explanation:**
  - Window $[0, 3]$ has packets: categories $[1, 2, 1, 1]$, weights $[5, -2, 4, 3]$.
  - Length = $4$. Category $1$ appears 3 times ($3 > 4/2 = 2$). Thus, it is frequency balanced.
  - Total weight = $5 + (-2) + 4 + 3 = 10$.
  - Window $[0, 4]$ includes $-10$, yielding weight $0$. The maximum weight is $10$.

### Example 2
- **Input:**
  - `categories = [2, 2, 2]`
  - `weights = [-5, -1, -3]`
- **Output:** `-1`
- **Explanation:**
  - Any single-element window has length 1 where category 2 is $100\%$ dominant.
  - The maximum single-element weight is $-1$ at index 1.

---

## Constraints

- $1 \le n \le 10^5$
- $1 \le C \le n$ (number of categories)
- $-10^9 \le \text{weight}[i] \le 10^9$

---

## Algorithmic Paradigm: Prefix Difference Transformation + Fenwick Tree

### 1. Mathematical Reformulation of Strict Majority
For a fixed category $c$, the condition that category $c$ is a strict majority in window $[L, R]$ is:
$$\text{count}(c, [L, R]) > \frac{R - L + 1}{2} \iff 2 \cdot \text{count}(c, [L, R]) - (R - L + 1) \ge 1$$

Assign each packet $i$ a difference value:
$$v_i(c) = \begin{cases} +1 & \text{if } \text{category}[i] = c \\ -1 & \text{if } \text{category}[i] \ne c \end{cases}$$

Then the majority condition translates to:
$$\sum_{i = L}^R v_i(c) \ge 1$$

### 2. Prefix Sum Transformation
Define prefix differences $P_{D, c}[x] = \sum_{i=0}^{x-1} v_i(c)$ with $P_{D, c}[0] = 0$.
The condition becomes:
$$P_{D, c}[R + 1] - P_{D, c}[L] \ge 1 \iff P_{D, c}[L] \le P_{D, c}[R + 1] - 1$$

We want to maximize:
$$P_W[R + 1] - P_W[L]$$
over all $L < R + 1$ satisfying $P_{D, c}[L] \le P_{D, c}[R + 1] - 1$, where $P_W[k] = \sum_{i=0}^{k-1} \text{weight}[i]$ is the standard prefix sum of weights.

Equivalently, for each candidate end position $R+1$, we must query:
$$\min_{L: P_{D, c}[L] \le P_{D, c}[R + 1] - 1} P_W[L]$$

### 3. Prefix Minimum via Fenwick Tree (Binary Indexed Tree)
- Notice $P_{D, c}[k]$ takes integer values in the range $[-n, n]$.
- By adding an offset $n + 1$, all indices map to positive values in $[1, 2n + 1]$.
- A Fenwick Tree supporting **Prefix Minimum Queries** dynamically maintains $\min P_W[L]$ for each difference level $d$:
  - Query: $\text{query}(P_{D, c}[R + 1] - 1 + \text{offset})$ returns the minimum prefix weight among all previous positions having difference $\le P_{D, c}[R + 1] - 1$.
  - Update: $\text{update}(P_{D, c}[R + 1] + \text{offset}, P_W[R + 1])$.
- Since queries are strictly prefix queries ($\le \text{threshold}$), the Fenwick tree operations take $O(\log n)$ time.

### 4. Category-Level Optimization
- We only need to run the search for categories that actually appear in the input array.
- For small number of distinct categories $U$, total time is $O(U \cdot n \log n)$.
- Every single packet $[i, i]$ is frequency balanced (category appears 1 time in length 1, $1 > 0.5$), providing an initial baseline $\max_i \text{weight}[i]$.

---

## Complexity Analysis

| Step | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Prefix Weight Table $P_W$** | $O(n)$ | $O(n)$ |
| **BIT Queries per Category** | $O(n \log n)$ | $O(n)$ |
| **Overall (for $U$ active categories)** | $\mathcal{O}(U \cdot n \log n)$ | $\mathcal{O}(n)$ |

