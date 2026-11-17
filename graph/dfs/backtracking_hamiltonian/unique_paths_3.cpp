#include <vector>

using namespace std;

// Bit Masking DP solution
class Solution {
private:
    int solve(int r, int c, int mask, int target_mask, int cols, int rows, 
              vector<vector<int>>& grid, vector<vector<int>>& memo) {
                  
        int current_bit = r * cols + c;
        
        // Base Case: Reached the ending square
        if (grid[r][c] == 2) {
            // Did we visit exactly all walkable cells?
            return (mask == target_mask) ? 1 : 0;
        }
        
        if (memo[current_bit][mask] != -1) return memo[current_bit][mask];
        
        int ways = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        // Explore all 4 directions
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            // Check bounds and obstacles
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] != -1) {
                
                int next_bit = nr * cols + nc;
                
                // If the next cell is NOT visited in our current timeline's mask
                if ((mask & (1 << next_bit)) == 0) {
                    
                    // Pass the newly updated mask down the recursion
                    ways += solve(nr, nc, mask | (1 << next_bit), target_mask, 
                                  cols, rows, grid, memo);
                }
            }
        }
        
        return memo[current_bit][mask] = ways;
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        int start_r = -1, start_c = -1;
        int target_mask = 0;
        
        // Setup the board
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] != -1) {
                    // Turn on the bit for every non-obstacle cell
                    int bit = r * cols + c;
                    target_mask |= (1 << bit);
                }
                if (grid[r][c] == 1) {
                    start_r = r;
                    start_c = c;
                }
            }
        }
        
        int total_cells = rows * cols;
        // memo[current_cell][mask]
        // Mask can go up to 2^20 (which is 1 << 20, roughly 1,000,000)
        vector<vector<int>> memo(total_cells, vector<int>(1 << total_cells, -1));
        
        // Start the journey with the starting cell's bit already turned on
        int start_bit = start_r * cols + start_c;
        int initial_mask = (1 << start_bit);
        
        return solve(start_r, start_c, initial_mask, target_mask, cols, rows, grid, memo);
    }
};

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