# Number of Operations to Make Network Connected (LeetCode 1319)

## Problem Overview
There are $N$ computers numbered from $0$ to $N - 1$ connected by ethernet cables `connections` where `connections[i] = [a_i, b_i]`.
You can extract certain cables connected between two computers and reconnect them between any two unconnected computers to make them connected.
Return the **minimum number of times you need to do this in order to make all computers connected**.
If it is impossible, return `-1`.

---

## DSU & Redundant Cable Theorem
To connect $N$ computers into a single component, **at least $N - 1$ total cables are mathematically required**:
$$\text{If } |connections| < N - 1 \implies \text{Impossible (return } -1)$$

If $|connections| \ge N - 1$:
1. We have enough physical cables to span the entire network.
2. Initialize DSU for $N$ computers.
3. For each connection $(u, v)$, perform `unionBySize(u, v)`.
4. Count the number of **connected components $C$**:
   - The number of components is the number of nodes where `findUPar(i) == i`.
5. To connect $C$ disjoint components, we need exactly **$C - 1$ bridge cables**.
6. Because total cables $\ge N - 1$, there are guaranteed to be at least $C - 1$ redundant cycle-forming cables available to repurpose!

---

## Complexity Analysis
- **Time Complexity:** $O(E \cdot \alpha(V) + V)$
- **Space Complexity:** $O(V)$ for DSU parent and size arrays.

