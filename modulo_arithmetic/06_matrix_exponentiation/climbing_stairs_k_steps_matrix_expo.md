# Problem 17: Climbing Stairs with K Steps (General Linear Recurrence Matrix Exponentiation)

## Problem Statement

You are climbing a staircase that has $N$ steps ($1 \le N \le 10^{18}$).
At each move, you can climb anywhere from $1$ up to $K$ steps ($1 \le K \le 10$).

Calculate the total number of distinct ways to reach the top of the staircase modulo $10^9 + 7$.

---

## Linear Recurrence Formulation

Let $dp[i]$ be the number of ways to reach step $i$:
$$dp[i] = dp[i - 1] + dp[i - 2] + \dots + dp[i - K]$$
Base cases:
$$dp[0] = 1, \quad dp[1] = 1, \quad dp[2] = 2, \quad \dots$$

Since $N \le 10^{18}$, standard DP in $O(N \cdot K)$ will Time Limit Exceeded. We construct the **$K \times K$ Companion Matrix**.

---

## The $K \times K$ Companion Transition Matrix

Define the state column vector:
$$\vec{V}_i = \begin{pmatrix} dp[i] \\ dp[i - 1] \\ dp[i - 2] \\ \vdots \\ dp[i - K + 1] \end{pmatrix}$$

The transition equation is:
$$\begin{pmatrix} dp[i] \\ dp[i - 1] \\ dp[i - 2] \\ \vdots \\ dp[i - K + 1] \end{pmatrix} = \begin{pmatrix} 1 & 1 & 1 & \dots & 1 \\ 1 & 0 & 0 & \dots & 0 \\ 0 & 1 & 0 & \dots & 0 \\ \vdots & \vdots & \ddots & \dots & 0 \\ 0 & 0 & \dots & 1 & 0 \end{pmatrix} \begin{pmatrix} dp[i - 1] \\ dp[i - 2] \\ dp[i - 3] \\ \vdots \\ dp[i - K] \end{pmatrix}$$

By powering the $K \times K$ transition matrix $T$ to the power $N$:
$$\vec{V}_N = T^N \vec{V}_0$$
computed via Matrix Binary Exponentiation in $\mathcal{O}(K^3 \log N)$.

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $\mathcal{O}(K^3 \log N)$ ($\approx 10^3 \times 60 \approx 6 \times 10^4$ operations) |
| **Space Complexity** | $\mathcal{O}(K^2)$ for matrix storage |

