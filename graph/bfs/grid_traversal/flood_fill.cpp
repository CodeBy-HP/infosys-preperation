#include <iostream>
#include <vector>
#include <cassert>

class FloodFill {
public:
    static void dfs(int r, int c, int initialColor, int newColor, std::vector<std::vector<int>>& image) {
        int m = image.size();
        int n = image[0].size();
        image[r][c] = newColor;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int d = 0; d < 4; ++d) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && image[nr][nc] == initialColor) {
                dfs(nr, nc, initialColor, newColor, image);
            }
        }
    }

    static std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        if (initialColor != color) {
            dfs(sr, sc, initialColor, color, image);
        }
        return image;
    }
};

int main() {
    std::vector<std::vector<int>> img1 = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    auto res1 = FloodFill::floodFill(img1, 1, 1, 2);
    std::vector<std::vector<int>> expected1 = {
        {2, 2, 2},
        {2, 2, 0},
        {2, 0, 1}
    };
    assert(res1 == expected1);

    std::vector<std::vector<int>> img2 = {
        {0, 0, 0},
        {0, 0, 0}
    };
    auto res2 = FloodFill::floodFill(img2, 0, 0, 0);
    assert(res2 == img2);

    std::cout << "All Flood Fill tests passed successfully!\n";
    return 0;
}

