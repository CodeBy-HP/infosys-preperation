# Disjoint Set Union (DSU / Union-Find)

## Conceptual Overview
**Disjoint Set Union (DSU)** is a dynamic tree-based data structure that partitions a universe of $N$ elements into non-overlapping disjoint sets. It supports two nearly constant-time operations:
1. `findUPar(u)`: Returns the canonical representative (root) of the set containing element $u$.
2. `unionByRank(u, v)` / `unionBySize(u, v)`: Merges the set containing element $u$ with the set containing element $v$.

---

## The Two Crucial Optimizations

### 1. Path Compression
When finding the root of element $u$, recursively re-point all nodes along the search path directly to the root:
```cpp
int findUPar(int node) {
    if (node == parent[node]) return node;
    return parent[node] = findUPar(parent[node]); // Path compression
}
```
This flattens the tree height to near-constant depth ($O(1)$ amortized).

### 2. Union by Rank vs Union by Size
Always attach the smaller tree under the root of the larger tree:
- **Union by Rank:** Attaches tree of smaller height under tree of larger height. Rank only increments when two trees of identical rank merge.
- **Union by Size (Preferred):** Tracks total elements in each tree. Always attaches the root with smaller `size` to the root with larger `size`:
  $$\text{size}[\text{root}_A] += \text{size}[\text{root}_B]$$

```
Before Union:
    (Root A, size 5)        (Root B, size 2)
       /   \                    |
      ...  ...                 (x)

After Union by Size:
         (Root A, size 7)
       /   \        \
      ...  ...     (Root B)
                      |
                     (x)
```

---

## C++ Implementation Class

```cpp
#include <vector>
#include <numeric>

class DisjointSet {
public:
    std::vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n + 1);
        std::iota(parent.begin(), parent.end(), 0);
        size.assign(n + 1, 1);
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    bool unionBySize(int u, int v) {
        int rootU = findUPar(u);
        int rootV = findUPar(v);
        if (rootU == rootV) return false; // Already in same set (Cycle / Redundant edge)

        if (size[rootU] < size[rootV]) {
            parent[rootU] = rootV;
            size[rootV] += size[rootU];
        } else {
            parent[rootV] = rootU;
            size[rootU] += size[rootV];
        }
        return true;
    }
};
```

---

## Complexity Analysis
- **Time Complexity:** $O(\alpha(N))$ per operation, where $\alpha(N)$ is the **Inverse Ackermann Function**. For all practical purposes on earth ($N \le 10^{80}$ atoms in the observable universe), $\alpha(N) \le 4 \approx O(1)$ constant time!
- **Space Complexity:** $O(N)$ for `parent` and `size` arrays.
