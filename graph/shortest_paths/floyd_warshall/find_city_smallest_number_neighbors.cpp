#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class CitySmallestNeighbors {
public:
    static int findTheCity(int n, const std::vector<std::vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;
        std::vector<std::vector<int>> dist(n, std::vector<int>(n, INF));

        for (int i = 0; i < n; ++i) dist[i][i] = 0;

        for (const auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        // Floyd-Warshall APSP
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        int minReachable = n + 1;
        int bestCity = -1;

        for (int i = 0; i < n; ++i) {
            int reachable = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    reachable++;
                }
            }
            if (reachable <= minReachable) {
                minReachable = reachable;
                bestCity = i; // Greater index preferred in tie
            }
        }
        return bestCity;
    }
};

int main() {
    int n1 = 4, threshold1 = 4;
    std::vector<std::vector<int>> edges1 = {
        {0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}
    };
    assert(CitySmallestNeighbors::findTheCity(n1, edges1, threshold1) == 3);

    int n2 = 5, threshold2 = 2;
    std::vector<std::vector<int>> edges2 = {
        {0, 1, 2}, {0, 4, 8}, {1, 2, 3}, {1, 4, 2}, {2, 3, 1}, {3, 4, 1}
    };
    assert(CitySmallestNeighbors::findTheCity(n2, edges2, threshold2) == 0);

    std::cout << "All Find City with Smallest Number of Neighbors tests passed successfully!\n";
    return 0;
}

