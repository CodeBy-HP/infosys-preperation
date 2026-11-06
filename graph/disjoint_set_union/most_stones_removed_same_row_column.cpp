#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <cassert>

class MostStonesRemoved {
private:
    class DSU {
        std::unordered_map<int, int> parent;
    public:
        int findUPar(int node) {
            if (!parent.count(node)) {
                parent[node] = node;
                return node;
            }
            if (node == parent[node]) return node;
            return parent[node] = findUPar(parent[node]);
        }
        void unionNodes(int u, int v) {
            int rootU = findUPar(u), rootV = findUPar(v);
            if (rootU != rootV) {
                parent[rootU] = rootV;
            }
        }
    };

public:
    static int removeStones(const std::vector<std::vector<int>>& stones) {
        int n = stones.size();
        DSU dsu;
        std::unordered_set<int> stoneNodes;

        // Offset column coordinates by 10001
        for (const auto& stone : stones) {
            int rowNode = stone[0];
            int colNode = stone[1] + 10001;

            dsu.unionNodes(rowNode, colNode);
            stoneNodes.insert(rowNode);
            stoneNodes.insert(colNode);
        }

        std::unordered_set<int> uniqueRoots;
        for (int node : stoneNodes) {
            uniqueRoots.insert(dsu.findUPar(node));
        }

        int components = uniqueRoots.size();
        return n - components;
    }
};

int main() {
    std::vector<std::vector<int>> stones1 = {
        {0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}
    };
    // 6 stones all connected into 1 component -> 6 - 1 = 5
    assert(MostStonesRemoved::removeStones(stones1) == 5);

    std::vector<std::vector<int>> stones2 = {
        {0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2}
    };
    // 2 components: { (0,0),(0,2),(2,0),(2,2) } and { (1,1) } -> 5 - 2 = 3
    assert(MostStonesRemoved::removeStones(stones2) == 3);

    std::vector<std::vector<int>> stones3 = {{0, 0}};
    assert(MostStonesRemoved::removeStones(stones3) == 0);

    std::cout << "All Most Stones Removed with Same Row or Column tests passed successfully!\n";
    return 0;
}

