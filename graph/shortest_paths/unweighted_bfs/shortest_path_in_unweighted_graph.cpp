#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

/**
 * Shortest Path in an Unweighted Graph (Breadth-First Search)
 * 
 * Problem:
 * Given an unweighted, undirected graph with V vertices and an edge list,
 * find the shortest distance from node 0 to all other nodes.
 * Unreachable nodes are assigned -1.
 * 
 * Time Complexity: O(V + E)
 * Space Complexity: O(V + E)
 */

class Solution {
public:
    std::vector<int> shortestPathUnweighted(int V, const std::vector<std::pair<int, int>>& edges, int source = 0) {
        // Step 1: Build adjacency list
        std::vector<std::vector<int>> adj(V);
        for (const auto& edge : edges) {
            adj[edge.first].push_back(edge.second);
            adj[edge.second].push_back(edge.first);
        }

        // Step 2: Distance vector initialized to -1 (unvisited)
        std::vector<int> dist(V, -1);
        std::queue<int> q;

        // Step 3: Base case
        dist[source] = 0;
        q.push(source);

        // Step 4: BFS traversal
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        return dist;
    }
};

int main() {
    Solution solver;

    // Test 1: Connected graph with 5 vertices
    {
        int V = 5;
        std::vector<std::pair<int, int>> edges = {
            {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 4}
        };
        std::vector<int> expected = {0, 1, 1, 2, 2};
        std::vector<int> actual = solver.shortestPathUnweighted(V, edges, 0);

        std::cout << "Test 1: Distances = ";
        for (int d : actual) std::cout << d << " ";
        std::cout << std::endl;
        assert(actual == expected);
    }

    // Test 2: Disconnected components
    {
        int V = 4;
        std::vector<std::pair<int, int>> edges = {
            {0, 1}, {2, 3}
        };
        std::vector<int> expected = {0, 1, -1, -1};
        std::vector<int> actual = solver.shortestPathUnweighted(V, edges, 0);

        std::cout << "Test 2: Distances = ";
        for (int d : actual) std::cout << d << " ";
        std::cout << std::endl;
        assert(actual == expected);
    }

    // Test 3: Single vertex graph
    {
        int V = 1;
        std::vector<std::pair<int, int>> edges = {};
        std::vector<int> expected = {0};
        std::vector<int> actual = solver.shortestPathUnweighted(V, edges, 0);
        assert(actual == expected);
    }

    std::cout << "All Shortest Path in Unweighted Graph tests passed successfully!" << std::endl;
    return 0;
}

