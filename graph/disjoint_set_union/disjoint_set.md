# Disjoint Set Union (DSU / Union-Find)

## Overview & Mathematical Foundations
A **Disjoint Set Union (DSU)** data structure maintains a collection of disjoint dynamic sets supporting two nearly $O(1)$ operations:
1. `find(u)`: Returns the representative (root) of the set containing element $u$.
2. `union(u, v)`: Merges the set containing $u$ with the set containing $v$.

---

## Two Critical Optimizations

### 1. Path Compression
During `find(u)`, every traversed node directly re-points its parent to the root:
```cpp
int findParent(int node) {
    if (node == parent[node]) return node;
    return parent[node] = findParent(parent[node]);
}
```
This flattens the tree dynamically, keeping future lookups at depth 1.

### 2. Union by Rank / Size
Always attach the root of the smaller tree under the root of the larger tree:
- **Union by Rank:** Keeps tree height bounded by $\log N$.
- **Union by Size:** Tracks the number of elements in the component, attaching smaller size under larger size.

Combining **Path Compression** with **Union by Rank/Size** guarantees an amortized time complexity per operation of:
$$O(\alpha(N))$$
where $\alpha$ is the **Inverse Ackermann function**, which is $\le 4$ for any input $N \le 10^{80}$ (atoms in the observable universe!).

---

## Complexity Analysis
- **Time Complexity:** $O(4 \alpha) \approx O(1)$ amortized per query/union.
- **Space Complexity:** $O(N)$ for `parent` and `rank`/`size` arrays.

