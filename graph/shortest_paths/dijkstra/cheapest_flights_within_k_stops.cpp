#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

class CheapestFlightsKStops {
public:
    static int findCheapestPrice(int n, const std::vector<std::vector<int>>& flights, int src, int dst, int k) {
        std::vector<std::vector<std::pair<int, int>>> adj(n);
        for (const auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]}); // u -> {v, price}
        }

        const int INF = 1e9;
        std::vector<int> dist(n, INF);
        dist[src] = 0;

        // Queue storing {stops, node, cost}
        std::queue<std::tuple<int, int, int>> q;
        q.push({0, src, 0});

        while (!q.empty()) {
            auto [stops, node, cost] = q.front();
            q.pop();

            if (stops > k) continue;

            for (const auto& [neighbor, price] : adj[node]) {
                if (cost + price < dist[neighbor] && stops <= k) {
                    dist[neighbor] = cost + price;
                    q.push({stops + 1, neighbor, cost + price});
                }
            }
        }

        return (dist[dst] == INF) ? -1 : dist[dst];
    }
};

int main() {
    int n1 = 4;
    std::vector<std::vector<int>> flights1 = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 0, 100},
        {1, 3, 600},
        {2, 3, 200}
    };
    // 0 -> 1 -> 2 -> 3 has 2 stops, total cost 100 + 100 + 200 = 400 <= 1 stop limit? No!
    // With k = 1: 0 -> 1 -> 3 has 1 stop, cost 100 + 600 = 700.
    assert(CheapestFlightsKStops::findCheapestPrice(n1, flights1, 0, 3, 1) == 700);

    // With k = 2: 0 -> 1 -> 2 -> 3 (cost 400, 2 stops)
    assert(CheapestFlightsKStops::findCheapestPrice(n1, flights1, 0, 3, 2) == 400);

    std::cout << "All Cheapest Flights Within K Stops tests passed successfully!\n";
    return 0;
}

