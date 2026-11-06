#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>

class MakeNetworkConnected {
private:
    class DSU {
        std::vector<int> parent;
    public:
        DSU(int n) {
            parent.resize(n);
            std::iota(parent.begin(), parent.end(), 0);
        }
        int findUPar(int node) {
            if (node == parent[node]) return node;
            return parent[node] = findUPar(parent[node]);
        }
        bool unionNodes(int u, int v) {
            int rootU = findUPar(u), rootV = findUPar(v);
            if (rootU == rootV) return false;
            parent[rootU] = rootV;
            return true;
        }
    };

public:
    static int makeConnected(int n, const std::vector<std::vector<int>>& connections) {
        if (static_cast<int>(connections.size()) < n - 1) {
            return -1; // Not enough total cables to span n nodes
        }

        DSU dsu(n);
        for (const auto& conn : connections) {
            dsu.unionNodes(conn[0], conn[1]);
        }

        int components = 0;
        for (int i = 0; i < n; ++i) {
            if (dsu.findUPar(i) == i) {
                components++;
            }
        }

        return components - 1;
    }
};

int main() {
    int n1 = 4;
    std::vector<std::vector<int>> c1 = {{0, 1}, {0, 2}, {1, 2}};
    assert(MakeNetworkConnected::makeConnected(n1, c1) == 1);

    int n2 = 6;
    std::vector<std::vector<int>> c2 = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
    assert(MakeNetworkConnected::makeConnected(n2, c2) == 2);

    int n3 = 6;
    std::vector<std::vector<int>> c3 = {{0, 1}, {0, 2}, {0, 3}, {1, 2}}; // only 4 edges for 6 nodes
    assert(MakeNetworkConnected::makeConnected(n3, c3) == -1);

    std::cout << "All Number of Operations to Make Network Connected tests passed successfully!\n";
    return 0;
}

