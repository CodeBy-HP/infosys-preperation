#include <vector>

using namespace std;

int dfs(vector<vector<int>>& grid, int x, int y, int empty_cells) {
    int n = grid.size();
    int m = grid[0].size();

    // Out of bounds or hitting an obstacle/already visited cell
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == -1) {
        return 0;
    }

    // Base Case: Reached the end
    if (grid[x][y] == 2) {
        // Did we cover every empty cell? (empty_cells will drop to -1 because we count the starting cell too)
        return empty_cells == -1 ? 1 : 0;
    }

    // Mark the current cell as visited by turning it into an obstacle
    grid[x][y] = -1;
    
    // Explore all 4 directions, decreasing the empty cell count
    int total_paths = 0;
    total_paths += dfs(grid, x + 1, y, empty_cells - 1);
    total_paths += dfs(grid, x - 1, y, empty_cells - 1);
    total_paths += dfs(grid, x, y + 1, empty_cells - 1);
    total_paths += dfs(grid, x, y - 1, empty_cells - 1);

    // BACKTRACK: Unvisit the cell so other timelines can use it
    grid[x][y] = 0;

    return total_paths;
}

int uniquePathsIII(vector<vector<int>>& grid) {
    int start_x = 0, start_y = 0;
    int empty_cells = 0;

    // Find the start and count exactly how many empty cells we need to step on
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 1) {
                start_x = i;
                start_y = j;
            } else if (grid[i][j] == 0) {
                empty_cells++;
            }
        }
    }

    return dfs(grid, start_x, start_y, empty_cells);
}