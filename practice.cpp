#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int helper(int ind,bool isSold,vector<int>&prices){
    // base case
    if(ind == n){
        return 0;
    }

    // do nothing
    int pocket = helper(ind+1,isSold);
    // buy 
    if(isSold){
        pocket = max(pocket,-prices[ind] + helper(ind+1,!isSold));
    }

    // sell
    else{
        pocket = max(pocket,prices[ind] + helper(ind+1,!isSold));
    }

    return max(pocket,0);
}




int main(){
}


