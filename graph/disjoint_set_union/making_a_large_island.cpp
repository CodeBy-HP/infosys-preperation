#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <cassert>

class MakingLargeIsland {
private:
    class DSU {
    public:
        std::vector<int> parent, size;
        DSU(int n) {
            parent.resize(n);
            std::iota(parent.begin(), parent.end(), 0);
            size.assign(n, 1);
        }
        int findUPar(int node) {
            if (node == parent[node]) return node;
            return parent[node] = findUPar(parent[node]);
        }
        void unionBySize(int u, int v) {
            int rootU = findUPar(u), rootV = findUPar(v);
            if (rootU == rootV) return;
            if (size[rootU] < size[rootV]) {
                parent[rootU] = rootV;
                size[rootV] += size[rootU];
            } else {
                parent[rootV] = rootU;
                size[rootU] += size[rootV];
            }
        }
    };

public:
    static int largestIsland(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        DSU dsu(n * n);

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // Phase 1: Union all existing land components
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    for (int d = 0; d < 4; ++d) {
                        int nr = r + dr[d];
                        int nc = c + dc[d];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                            dsu.unionBySize(r * n + c, nr * n + nc);
                        }
                    }
                }
            }
        }

        // Phase 2: Try flipping each 0
        int maxIsland = 0;
        for (int i = 0; i < n * n; ++i) {
            maxIsland = std::max(maxIsland, dsu.size[dsu.findUPar(i)]);
        }

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0) {
                    std::unordered_set<int> uniqueRoots;
                    for (int d = 0; d < 4; ++d) {
                        int nr = r + dr[d];
                        int nc = c + dc[d];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                            uniqueRoots.insert(dsu.findUPar(nr * n + nc));
                        }
                    }

                    int currentSize = 1; // Flipping current cell (r, c)
                    for (int root : uniqueRoots) {
                        currentSize += dsu.size[root];
                    }
                    maxIsland = std::max(maxIsland, currentSize);
                }
            }
        }
        return maxIsland;
    }
};

int main() {
    std::vector<std::vector<int>> g1 = {
        {1, 0},
        {0, 1}
    };
    assert(MakingLargeIsland::largestIsland(g1) == 3);

    std::vector<std::vector<int>> g2 = {
        {1, 1},
        {1, 0}
    };
    assert(MakingLargeIsland::largestIsland(g2) == 4);

    std::vector<std::vector<int>> g3 = {
        {1, 1},
        {1, 1}
    };
    assert(MakingLargeIsland::largestIsland(g3) == 4);

    std::cout << "All Making a Large Island tests passed successfully!\n";
    return 0;
}

