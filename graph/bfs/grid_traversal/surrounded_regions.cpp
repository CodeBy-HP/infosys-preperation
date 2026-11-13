#include <iostream>
#include <vector>
#include <cassert>

class SurroundedRegions {
public:
    static void dfs(int r, int c, std::vector<std::vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        board[r][c] = '#'; // Mark protected

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int d = 0; d < 4; ++d) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'O') {
                dfs(nr, nc, board);
            }
        }
    }

    static void solve(std::vector<std::vector<char>>& board) {
        if (board.empty()) return;
        int m = board.size();
        int n = board[0].size();

        // 1. Mark all boundary connected 'O' as '#'
        for (int r = 0; r < m; ++r) {
            if (board[r][0] == 'O') dfs(r, 0, board);
            if (board[r][n - 1] == 'O') dfs(r, n - 1, board);
        }
        for (int c = 0; c < n; ++c) {
            if (board[0][c] == 'O') dfs(0, c, board);
            if (board[m - 1][c] == 'O') dfs(m - 1, c, board);
        }

        // 2. Flip surrounded 'O' to 'X', and restore '#' to 'O'
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                } else if (board[r][c] == '#') {
                    board[r][c] = 'O';
                }
            }
        }
    }
};

int main() {
    std::vector<std::vector<char>> b1 = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    SurroundedRegions::solve(b1);
    std::vector<std::vector<char>> expected1 = {
        {'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    assert(b1 == expected1);

    std::vector<std::vector<char>> b2 = {{'X'}};
    SurroundedRegions::solve(b2);
    assert(b2 == std::vector<std::vector<char>>({{'X'}}));

    std::cout << "All Surrounded Regions tests passed successfully!\n";
    return 0;
}

