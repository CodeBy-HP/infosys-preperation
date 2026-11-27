#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int helper(int n, vector<int>&nums,int ind,int curr,int target,vector<vector<int>>&dp){
    // base case
    if(ind == n){
        if(curr == target)
            return 1;
        return 0;
    }

    if(dp[ind][curr+1000] != -1) return dp[ind][curr+1000];

    return dp[ind][curr+1000] = helper(n,nums,ind+1,curr+nums[ind],target) + helper(n,nums,ind+1,curr-nums[ind],target);
}

int count_ways(vector<int>&nums, int target){
    int n = nums.size();
    vector<vector<int>>dp(n,vector<int>(2002,-1));
    return  helper(n,nums,0,0,target,dp);
}


int main(){
}


