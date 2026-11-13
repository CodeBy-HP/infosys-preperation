# Maximize XOR Sum (Digit DP on Bits / Greedy Upper Bound)

## Problem Statement

You are given an array $A$ of $N$ integers and a maximum boundary integer $K$.

Your objective is to find an integer $x$ within the inclusive range $[0, K]$ that maximizes the resulting **XOR sum**:
$$\text{Max Score} = \max_{0 \le x \le K} \sum_{i=1}^{N} (x \oplus A[i])$$

---

## Examples

### Example 1
- **Input:**
  - $N = 3$, $K = 7$
  - $A = [1, 6, 3]$
- **Output:** `14` (achieved with $x = 4$)
- **Explanation:**
  - If $x = 4$:
    - $4 \oplus 1 = 5$
    - $4 \oplus 6 = 2$
    - $4 \oplus 3 = 7$
    - Total sum = $5 + 2 + 7 = 14$.
  - Any $x \in [0, 7]$ cannot yield a larger sum.

### Example 2
- **Input:**
  - $N = 4$, $K = 0$
  - $A = [10, 20, 30, 40]$
- **Output:** `100`
- **Explanation:** Only $x = 0$ is allowed, giving $0 \oplus A[i] = A[i]$, sum = $10 + 20 + 30 + 40 = 100$.

---

## Constraints

- $1 \le N \le 10^5$
- $0 \le K \le 10^{12}$ (or up to $2^{60} - 1$)
- $0 \le A[i] \le 10^{12}$

---

## Mathematical Principle: Independent Bit Contributions

Notice the summation expands bitwise:
$$\sum_{i=1}^{N} (x \oplus A[i]) = \sum_{b=0}^{B} 2^b \sum_{i=1}^{N} ((x \gg b) \& 1 \oplus (A[i] \gg b) \& 1)$$

For each bit position $b$:
- Let $c_1[b]$ be the count of elements in $A$ with bit $b$ set to $1$.
- Let $c_0[b] = N - c_1[b]$ be the count of elements in $A$ with bit $b$ set to $0$.

### Impact of Choosing the $b$-th Bit of $x$:
- If we set the $b$-th bit of $x$ to $0$:
  The $b$-th bit of $(x \oplus A[i])$ will be $1$ whenever $A[i]$ had bit $1$.
  Contribution to sum: $c_1[b] \times 2^b$.
- If we set the $b$-th bit of $x$ to $1$:
  The $b$-th bit of $(x \oplus A[i])$ will be $1$ whenever $A[i]$ had bit $0$.
  Contribution to sum: $c_0[b] \times 2^b$.

To maximize without constraints, we would greedily pick bit $b = 1$ whenever $c_0[b] > c_1[b]$.

### Satisfying the Upper Bound Constraint $x \le K$ (Digit DP)
Because $x$ must satisfy $x \le K$, we process bits from the Most Significant Bit ($B \approx 60$) down to $0$ with a boolean `tight` flag:
1. `tight == true`: $x$ currently matches the prefix of $K$.
   - If the $b$-th bit of $K$ is $0$, bit $b$ of $x$ **must** be $0$, remaining `tight = true`.
   - If the $b$-th bit of $K$ is $1$:
     - **Branch 1:** Choose bit $0$ for $x \implies$ transitions to `tight = false` (now strictly $< K$).
     - **Branch 2:** Choose bit $1$ for $x \implies$ remains `tight = true`.
2. `tight == false`: $x$ is strictly smaller than $K$. We are completely unconstrained and can freely choose whichever bit maximizes the contribution ($c_0[b]$ vs $c_1[b]$).

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Bit Frequency Count** | $\mathcal{O}(N \times B)$ where $B \le 62$ |
| **Digit DP Transitions** | $\mathcal{O}(B)$ states and $\mathcal{O}(1)$ transitions |
| **Total Time** | $\mathcal{O}(N \log(\max A) + \log K)$ |
| **Space Complexity** | $\mathcal{O}(B)$ memory |

