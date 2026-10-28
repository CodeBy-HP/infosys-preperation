#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>&mat){

    int n = mat.size();
    int m = mat[0].size();

    auto isValid = [&](int i, int j){
        return i >= 0 && i < n && j >= 0 && j < m;
    };

    vector<pair<int,int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<pair<int,int>>dash_dir = {{2,0},{-2,0},{0,2},{0,-2}};

    // dp
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(2,-1)));

    // direction
    auto dfs = [&](int i ,int j,int dashUsed,auto&self){

        if(!isValid(i,j)) return 0;

        if(dp[i][j][dashUsed] != -1) return dp[i][j][dashUsed];

        int max_ans = INT_MIN;

        for(auto it : dir){
            int new_i = i + it.first;
            int new_j = j + it.second;

            if(!isValid(new_i,new_j)) continue;

            if(mat[new_i][new_j] <= mat[i][j]) continue;

            max_ans = max(max_ans, 1+self(new_i,new_j,dashUsed,self));

        }

        if(!dashUsed){
            for(auto it : dash_dir){
            int new_i = i + it.first;
            int new_j = j + it.second;

            if(!isValid(new_i,new_j)) continue;

            if(mat[new_i][new_j] <= mat[i][j]) continue;
            
            max_ans = max(max_ans, 1+self(new_i,new_j,1,self));
        }
        }

        return dp[i][j][dashUsed] = max(max_ans,1);
    };


    int max_ans = INT_MIN;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            max_ans = max(max_ans,dfs(i,j,0,dfs));
        }
    }

    return max_ans;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>>mat(n,vector<int>(m,0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    cout << solve(mat);
}