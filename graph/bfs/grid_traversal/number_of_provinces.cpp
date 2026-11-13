#include <iostream>
#include <vector>
#include <cassert>

class NumberOfProvinces {
public:
    static void dfs(int city, const std::vector<std::vector<int>>& isConnected, std::vector<bool>& visited) {
        visited[city] = true;
        for (size_t next = 0; next < isConnected.size(); ++next) {
            if (isConnected[city][next] == 1 && !visited[next]) {
                dfs(next, isConnected, visited);
            }
        }
    }

    static int findCircleNum(const std::vector<std::vector<int>>& isConnected) {
        int n = isConnected.size();
        std::vector<bool> visited(n, false);
        int provinces = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++provinces;
                dfs(i, isConnected, visited);
            }
        }
        return provinces;
    }
};

int main() {
    std::vector<std::vector<int>> g1 = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    assert(NumberOfProvinces::findCircleNum(g1) == 2);

    std::vector<std::vector<int>> g2 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    assert(NumberOfProvinces::findCircleNum(g2) == 3);

    std::cout << "All Number of Provinces tests passed successfully!\n";
    return 0;
}

