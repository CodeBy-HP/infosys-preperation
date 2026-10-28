
#include<bits/stdc++.h>
using namespace std;


solve(){
    string s;
    cin >> s;

    int n = s.size();

    vector<vector<int>>dp(n,vector<int>(n,-1));

    auto check_palindrome = [&](int i, int j){
        while(i < j){
            if(s[i] != s[j])
            return false;

            i++;
            j--;
        }
        return true;
    };

    auto palindrome_patrition = [&](int i,int j,auto& self){

        // base case
        if(i == n && j ==n){
            return 0;
        } 

        if(j >= n){
            return INT_MAX;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // is partition possible
        // yes -> either do partiion or not
        // no -> no partition possible


        // no partition
        int way1 = self(i,j+1,self);
        int way2 = INT_MAX;
        if(check_palindrome(i,j)){
            int temp = self(j+1,j+1,self);
            if(temp != INT_MAX){
                way2 = 1 + temp;
            }
        } 

        return dp[i][j] = min(way1,way2);
    };


    vector<int>dp2(n,-1);
    auto space_optim_palindrome_patrition = [&](int i, auto& self){

        if(i == n){
            return 0;
        }
        if(dp2[i] != -1){
            return dp2[i];
        }
        
        int min_ways_count = INT_MAX;
        for(int k = i; k < n; k++){
            int way1 = INT_MAX;
            if(check_palindrome(i,k)){
                int temp = self(k+1,self);
                if(temp != INT_MAX){
                    way1 = 1 + temp;
                }
            }
            min_ways_count = min(min_ways_count,way1);
        }
        return dp2[i] = min_ways_count;
    };


    vector<vector<bool>>pre_computed_palindrome(n,vector<bool>(n,false));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i; j++){
            int k = j + i;
            
            if(i < 3){
                if(s[j] == s[k]){
                pre_computed_palindrome[j][k] = true;
            }
            } else{
                if(s[j] == s[k] && pre_computed_palindrome[j+1][k-1]){
                pre_computed_palindrome[j][k] = true;
            }
            }
        }
    }


    vector<vector<bool>>cleaner_pre_compute_palindrome(n,vector<bool>(n,false));
    for(int i = n-1; i >= 0; i--){
        for(int j = i; j < n; j++){
            if(s[i] == s[j] && ( j-i < 3 || cleaner_pre_compute_palindrome[i+1][j-1])){
                cleaner_pre_compute_palindrome[i][j] = true;
            }
        }
    }

    auto check_palindrome_optim = [&](int i, int j){
        return pre_computed_palindrome[i][j];
    };

    auto space_time_optim_palindrome_partition = [&](int i, auto& self){
        if(i == n){
            return 0;
        }
        if(dp2[i] != -1){
            return dp2[i];
        }
        
        int min_ways_count = INT_MAX;
        for(int k = i; k < n; k++){
            int way1 = INT_MAX;
            if(check_palindrome_optim(i,k)){
                int temp = self(k+1,self);
                if(temp != INT_MAX){
                    way1 = 1 + temp;
                }
            }
            min_ways_count = min(min_ways_count,way1);
        }
        return dp2[i] = min_ways_count;

    }


    cout << palindrome_patrition(0,0,palindrome_patrition);
    cout << space_optim_palindrome_patrition(0,space_optim_palindrome_patrition);
}

int main(){
    solve();
}