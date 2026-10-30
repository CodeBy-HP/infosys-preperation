#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>&arr){
    int n = arr.size();
    if (n == 0) return; 
    int m = arr[0].size();

    auto isValid = [&](int i, int j){
        return i >= 0 && j >= 0 && i < n && j < m;
    };

    vector<pair<int,int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>>dp(n,vector<int>(m,-1));

    auto dfs = [&](int i, int j, auto&self){
        if(dp[i][j] != -1) return dp[i][j];
        
        int max_len = 1; 
        
        for(auto& d : dir){
            int new_i = i + d.first;
            int new_j = j + d.second;

            if(!isValid(new_i,new_j)) continue;

            if(arr[new_i][new_j] > arr[i][j]){
                max_len = max(max_len, self(new_i, new_j, self) + 1);
            }
        }
        return dp[i][j] = max_len; 
    };

    int global_max = 0; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            global_max = max(global_max, dfs(i, j, dfs));
        }
    }

    cout << global_max << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> mat(n,vector<int>(m,0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j]; 
        }
    }

    solve(mat); 
    return 0;
}