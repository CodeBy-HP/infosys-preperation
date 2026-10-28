#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<string> grid(n);
    queue<pair<int, int>> fireQueue;
    queue<pair<int, int>> humanQueue;
    
    vector<vector<int>> fireTime(n, vector<int>(m, 1e9));
    vector<vector<int>> humanTime(n, vector<int>(m, 1e9));

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'F') {
                fireQueue.push({i, j});
                fireTime[i][j] = 0;
            } else if (grid[i][j] == 'H') {
                humanQueue.push({i, j});
                humanTime[i][j] = 0;
            }
        }
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!fireQueue.empty()) {
        auto [x, y] = fireQueue.front();
        fireQueue.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#') {
                if (fireTime[nx][ny] > fireTime[x][y] + 1) {
                    fireTime[nx][ny] = fireTime[x][y] + 1;
                    fireQueue.push({nx, ny});
                }
            }
        }
    }

    while (!humanQueue.empty()) {
        auto [x, y] = humanQueue.front();
        humanQueue.pop();

        if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
            cout << "YES\n";
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#') {
                if (humanTime[x][y] + 1 < fireTime[nx][ny] && humanTime[nx][ny] > humanTime[x][y] + 1) {
                    humanTime[nx][ny] = humanTime[x][y] + 1;
                    humanQueue.push({nx, ny});
                }
            }
        }
    }

    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}