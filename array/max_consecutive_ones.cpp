#include<bits/stdc++.h>
using namespace std;

int solve(){
    int n;
    cin >> n;

    vector<int>nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }


    int curr_count = 0;
    int max_count = 0;

    for(int i = 0; i < n; i++){
        if(nums[i] == 1){
            curr_count++;
        } else{
            max_count = max(max_count,curr_count);
            curr_count = 0;
        }
    }

    max_count = max(max_count,curr_count);

    return max_count;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}