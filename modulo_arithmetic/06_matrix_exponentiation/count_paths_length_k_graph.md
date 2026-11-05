# Problem 18: Count Paths of Length K in Directed Graph (Adjacency Matrix Exponentiation)

## Problem Statement

You are given a directed graph with $V$ vertices labeled from $0$ to $V - 1$ represented as an adjacency matrix:
$$A[i][j] = \text{number of directed edges from vertex } i \text{ to vertex } j$$

Calculate the **number of directed paths of exact length $K$** from a given source vertex $u$ to destination vertex $v$ modulo $10^9 + 7$, where:
- $V \le 100$
- $K \le 10^{18}$

---

## Mathematical Principle: Powers of the Adjacency Matrix

Let $A$ be the $V \times V$ adjacency matrix of the graph.

### Theorem:
> For any positive integer $K$, the entry $(A^K)_{u, v}$ in the $K$-th power of the adjacency matrix is **strictly equal to the number of directed walks of length $K$ from vertex $u$ to vertex $v$**.

### Proof by Mathematical Induction:
- **Base Case ($K = 1$):** $(A^1)_{u, v} = A_{u, v}$ is the number of single-edge paths from $u$ to $v$.
- **Inductive Step:**
  By matrix multiplication:
  $$(A^K)_{u, v} = (A^{K - 1} \times A)_{u, v} = \sum_{w = 0}^{V - 1} (A^{K - 1})_{u, w} \times A_{w, v}$$
  A walk of length $K$ from $u$ to $v$ decomposes into a walk of length $K - 1$ from $u$ to some intermediate neighbor $w$, followed by a directed edge from $w$ to $v$. Summing over all possible intermediate vertices $w$ gives the exact count!

---

## Algorithm

1. Construct the $V \times V$ adjacency matrix $A$.
2. Compute $M = A^K \pmod{10^9 + 7}$ using **Matrix Binary Exponentiation**.
3. The answer is $M[u][v]$.

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $\mathcal{O}(V^3 \log K)$ |
| **Space Complexity** | $\mathcal{O}(V^2)$ for matrix storage |

