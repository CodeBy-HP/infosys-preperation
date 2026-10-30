#include <vector>

using namespace std;

class DSU {
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int size) {
        parent.resize(size, -1); 
        rank.resize(size, 0);
    }
    
    // Set a cell as land by making it its own parent
    void setParent(int i) {
        if (parent[i] == -1) {
            parent[i] = i;
        }
    }
    
    // Check if a cell is land
    bool isLand(int i) {
        return parent[i] != -1;
    }
    
    // Find with Path Compression
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    
    // Union by Rank
    bool unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        
        if (rootI != rootJ) {
            if (rank[rootI] < rank[rootJ]) {
                parent[rootI] = rootJ;
            } else if (rank[rootI] > rank[rootJ]) {
                parent[rootJ] = rootI;
            } else {
                parent[rootJ] = rootI;
                rank[rootI]++;
            }
            return true; // Successfully merged two different sets
        }
        return false; // They were already in the same set
    }
};

vector<int> numIslands2(int n, int m, vector<vector<int>>& positions) {
    DSU dsu(n * m);
    vector<int> result;
    int current_islands = 0;
    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    for (auto& pos : positions) {
        int r = pos[0];
        int c = pos[1];
        int id = r * m + c;
        
        // If it's already land, count doesn't change
        if (dsu.isLand(id)) {
            result.push_back(current_islands);
            continue;
        }
        
        // Make it land
        dsu.setParent(id);
        current_islands++;
        
        // Check 4 neighbors
        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            int neighbor_id = nr * m + nc;
            
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && dsu.isLand(neighbor_id)) {
                // If they belong to different islands, merge them and decrease the count
                if (dsu.unite(id, neighbor_id)) {
                    current_islands--;
                }
            }
        }
        
        result.push_back(current_islands);
    }
    
    return result;
}