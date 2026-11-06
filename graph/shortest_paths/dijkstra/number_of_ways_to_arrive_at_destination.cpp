#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

class NumberOfWaysToDestination {
public:
    static const int MOD = 1e9 + 7;

    static int countPaths(int n, const std::vector<std::vector<int>>& roads) {
        std::vector<std::vector<std::pair<int, long long>>> adj(n);
        for (const auto& r : roads) {
            int u = r[0], v = r[1];
            long long time = r[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        const long long INF = 1e18;
        std::vector<long long> dist(n, INF);
        std::vector<int> ways(n, 0);

        // Min-heap storing {distance, node}
        std::priority_queue<std::pair<long long, int>,
                            std::vector<std::pair<long long, int>>,
                            std::greater<std::pair<long long, int>>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (const auto& [v, time] : adj[u]) {
                if (d + time < dist[v]) {
                    dist[v] = d + time;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                } else if (d + time == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[n - 1];
    }
};

int main() {
    int n1 = 7;
    std::vector<std::vector<int>> roads1 = {
        {0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3},
        {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}
    };
    assert(NumberOfWaysToDestination::countPaths(n1, roads1) == 4);

    int n2 = 2;
    std::vector<std::vector<int>> roads2 = {{1, 0, 10}};
    assert(NumberOfWaysToDestination::countPaths(n2, roads2) == 1);

    std::cout << "All Number of Ways to Arrive at Destination tests passed successfully!\n";
    return 0;
}

