# Problem: Minimum Amplifiers Coverage

## Problem Statement

There are $N$ posts located along a highway. The positions of the posts are given in a sorted integer array `posts[]`, where `posts[i]` represents the position of the $i$-th post.

Your task is to install amplifiers such that **every post is covered**.

There are two types of amplifiers available:
1. **Normal Amplifier:**
   - Can be installed at any position $x$ on the highway.
   - Covers all posts in the interval $[x - r, x + r]$ (span length $2r$).
   - Unlimited supply available.
2. **Super Amplifier:**
   - Can be installed at any position $x$ on the highway.
   - Covers all posts in the interval $[x - 2r, x + 2r]$ (span length $4r$).
   - **Only at most $K$ super amplifiers are available.**

An amplifier does not have to be placed at the exact position of a post; it can be installed anywhere along the highway to maximize coverage.

Return the **minimum total number of amplifiers** required to cover all the posts.

---

## Examples

### Example 1
- **Input:**
  ```text
  5
  1 5 10 15 20
  2 1
  ```
- **Explanation:**
  - $N = 5$, posts at $[1, 5, 10, 15, 20]$, radius $r = 2$, super amplifier budget $K = 1$.
  - Normal amplifier covers span $2r = 4$.
  - Super amplifier covers span $4r = 8$.
  - Greedily placing amplifiers starting at the leftmost uncovered post:
    - Post 1: place a super amplifier covering $[1, 1 + 8] = [1, 9]$, covering posts at $1$ and $5$. (1 super amplifier used)
    - Post 10: place a normal amplifier covering $[10, 10 + 4] = [10, 14]$, covering post $10$.
    - Post 15: place a normal amplifier covering $[15, 15 + 4] = [15, 19]$, covering post $15$.
    - Post 20: place a normal amplifier covering $[20, 24]$, covering post $20$.
    - Or place super amplifier covering $[10, 18]$ (posts 10 and 15), normal on post 1, normal on post 20 $\rightarrow$ total 3 amplifiers!

---

## Constraints

- $1 \le N \le 10^5$
- $1 \le \text{posts}[i] \le 10^9$
- $\text{posts}[]$ is sorted in non-decreasing order.
- $1 \le r \le 10^9$
- $0 \le K \le \min(N, 1000)$

---

## The Greedy-Choice & DP Formulation

Because posts are sorted along a line, an optimal amplifier must start its left boundary at the position of the first uncovered post $posts[i]$:
- Installing a **Normal Amplifier** covers all posts with position $\le posts[i] + 2r$. Let $j_1$ be the index of the first post $> posts[i] + 2r$ (found via binary search `bisect_right`).
- Installing a **Super Amplifier** covers all posts with position $\le posts[i] + 4r$. Let $j_2$ be the index of the first post $> posts[i] + 4r$ (found via binary search `bisect_right`).

1. **State:**
   - $\text{dp}[i][rem]$ is the minimum amplifiers to cover from post $i$ to $N - 1$ with $rem$ super amplifiers remaining.
2. **Transitions:**
   $$\text{dp}[i][rem] = \min \begin{cases}
   1 + \text{dp}[j_1][rem] & \text{(Use Normal)} \\
   1 + \text{dp}[j_2][rem - 1] & \text{(Use Super, if } rem > 0 \text{)}
   \end{cases}$$
3. **Base Case:**
   - $\text{dp}[N][rem] = 0$ (all posts covered).

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Top-Down (Recursion + Memoization)** | $O(N \cdot K)$ | $O(N \cdot K)$ |
| **Bottom-Up Tabulation** | $O(N \cdot K)$ | $O(N \cdot K)$ |
| **Space-Optimized Iterative** | $O(N \cdot K)$ | $O(N)$ or $O(K)$ |

