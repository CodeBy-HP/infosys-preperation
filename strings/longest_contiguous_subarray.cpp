
// # 1 indexed

// find length of
// longest contiguous subarray

// abs(arr[i]-arr[i+1]) <= length

// 0 1 2 3 4 5  6 7 8
// 4 5 9 3 2 1 45 3 4
// 3


#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr, int L) {
    int n = arr.size(); 
    if (n == 0) {
        cout << 0;
        return;
    }

    int prev = 0;
    int maxLen = 0;
    int i = 0;
    
    for(i = 0; i < n - 1; i++) {
        if(abs(arr[i] - arr[i+1]) > L) {
            maxLen = max(maxLen, i - prev + 1);
            prev = i + 1;
        }
    }
    
    maxLen = max(maxLen, i - prev + 1);
    cout << maxLen << endl;
}


int main(){
    int n;
    cin >> n;
    int L;
    cin >> L;

    vector<int>arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    solve(arr,L);
}