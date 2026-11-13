#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>

class NetworkDelayTime {
public:
    static int networkDelayTime(const std::vector<std::vector<int>>& times, int n, int k) {
        std::vector<std::vector<std::pair<int, int>>> adj(n + 1);
        for (const auto& t : times) {
            adj[t[0]].push_back({t[1], t[2]}); // u -> {v, time}
        }

        const int INF = 1e9;
        std::vector<int> dist(n + 1, INF);
        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>,
                            std::greater<std::pair<int, int>>> pq;

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (const auto& [v, time] : adj[u]) {
                if (dist[u] + time < dist[v]) {
                    dist[v] = dist[u] + time;
                    pq.push({dist[v], v});
                }
            }
        }

        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INF) return -1;
            maxTime = std::max(maxTime, dist[i]);
        }
        return maxTime;
    }
};

int main() {
    std::vector<std::vector<int>> times1 = {
        {2, 1, 1},
        {2, 3, 1},
        {3, 4, 1}
    };
    assert(NetworkDelayTime::networkDelayTime(times1, 4, 2) == 2);

    std::vector<std::vector<int>> times2 = {{1, 2, 1}};
    assert(NetworkDelayTime::networkDelayTime(times2, 2, 1) == 1);

    std::vector<std::vector<int>> times3 = {{1, 2, 1}};
    assert(NetworkDelayTime::networkDelayTime(times3, 2, 2) == -1);

    std::cout << "All Network Delay Time tests passed successfully!\n";
    return 0;
}

