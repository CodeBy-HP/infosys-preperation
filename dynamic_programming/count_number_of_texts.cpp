#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;

int main(){
    string s;
    cin >> s;

    int n = s.size();

    // map<int,int>mpp;
    // mpp[2]=3; mpp[3]=3; mpp[4]=3; mpp[5]=3; mpp[6]=3; mpp[8]=3; 
    // mpp[7]=4; mpp[9]=4;


    int mpp[10] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
    // as array lookup is fast than map which is (log k)

    vector<int>dp(n,-1);

    auto solve = [&](int ind, auto self) -> int {
        if (ind == n){
            return 1;
        }

        if(dp[ind] != -1){
            return dp[i];
        }

        int itr = mpp[s[ind]-'0'];
        char curr = s[ind];

        long long ways = 0;
        for(int i = 0; i < itr; i++){
            int new_ind = ind+i;
            
            if(new_ind >= n) break;
            
            if(s[new_ind] == curr){
                ways = (ways + self(new_ind+1, self)) % MOD;
            } else {
                break;
            }
        }
        return dp[ind] = ways;
    };

    cout << solve(0, solve) << "\n";
    return 0;
}