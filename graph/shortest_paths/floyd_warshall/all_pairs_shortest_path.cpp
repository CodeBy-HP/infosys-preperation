#include <vector>
#include <algorithm>

using namespace std;

void floydWarshall(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    // Replace any -1 (no edge) with a large number (infinity) to prevent math errors
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 1e9;
            }
            if (i == j) {
                matrix[i][j] = 0;
            }
        }
    }
    
    // The core Floyd-Warshall algorithm: 3 nested loops
    // k is the intermediate node, i is the source, j is the destination
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // If a path exists through k, check if it's cheaper
                if (matrix[i][k] != 1e9 && matrix[k][j] != 1e9) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }
    
    // Negative Cycle Detection:
    // If the distance from a node to ITSELF ever drops below 0, 
    // a negative cycle exists in the graph.
    for (int i = 0; i < n; i++) {
        if (matrix[i][i] < 0) {
            // Negative cycle detected!
        }
    }
}