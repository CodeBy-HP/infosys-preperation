#include <iostream>
#include <vector>
#include <cassert>

class GraphRepresentations {
public:
    // Adjacency Matrix Builder
    static std::vector<std::vector<int>> buildAdjMatrix(int V, const std::vector<std::pair<int, int>>& edges, bool directed = false) {
        std::vector<std::vector<int>> matrix(V, std::vector<int>(V, 0));
        for (const auto& e : edges) {
            matrix[e.first][e.second] = 1;
            if (!directed) {
                matrix[e.second][e.first] = 1;
            }
        }
        return matrix;
    }

    // Adjacency List Builder
    static std::vector<std::vector<int>> buildAdjList(int V, const std::vector<std::pair<int, int>>& edges, bool directed = false) {
        std::vector<std::vector<int>> adj(V);
        for (const auto& e : edges) {
            adj[e.first].push_back(e.second);
            if (!directed) {
                adj[e.second].push_back(e.first);
            }
        }
        return adj;
    }
};

int main() {
    int V = 4;
    std::vector<std::pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};

    auto matrix = GraphRepresentations::buildAdjMatrix(V, edges);
    assert(matrix[0][1] == 1);
    assert(matrix[1][0] == 1);
    assert(matrix[0][3] == 0);

    auto adj = GraphRepresentations::buildAdjList(V, edges);
    assert(adj[0].size() == 2); // 1 and 2
    assert(adj[2].size() == 3); // 0, 1, and 3

    std::cout << "All Introduction to Graph tests passed successfully!\n";
    return 0;
}

