#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>

class DisjointSet {
private:
    std::vector<int> parent;
    std::vector<int> rank;
    std::vector<int> size;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        std::iota(parent.begin(), parent.end(), 0);
        rank.assign(n + 1, 0);
        size.assign(n + 1, 1);
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]); // Path compression
    }

    bool unionByRank(int u, int v) {
        int rootU = findUPar(u);
        int rootV = findUPar(v);
        if (rootU == rootV) return false; // Already in same set

        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootV] < rank[rootU]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
        return true;
    }

    bool unionBySize(int u, int v) {
        int rootU = findUPar(u);
        int rootV = findUPar(v);
        if (rootU == rootV) return false;

        if (size[rootU] < size[rootV]) {
            parent[rootU] = rootV;
            size[rootV] += size[rootU];
        } else {
            parent[rootV] = rootU;
            size[rootU] += size[rootV];
        }
        return true;
    }

    int getSize(int node) {
        return size[findUPar(node)];
    }
};

int main() {
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    // Check if 3 and 7 are in same component
    assert(ds.findUPar(3) != ds.findUPar(7));

    // Connect components
    ds.unionBySize(3, 7);
    assert(ds.findUPar(3) == ds.findUPar(7));
    assert(ds.getSize(1) == 7); // All 7 nodes in one component

    std::cout << "All Disjoint Set (DSU) tests passed successfully!\n";
    return 0;
}

