#include<bits/stdc++.h>
using namespace std;

void brute_force(){
    int n; 
    cin >> n;

    vector<int>arr(n,0);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int>compute(n,-1);
    int max_value = INT_MIN;
    for(int i = 0; i < n; i++){

        // right 
    int value_right = 0;
    for(int j = 0; j < n; j++) { 
        int curr = (i + j) % n;
        if(j == 0) compute[j] = arr[curr];
        else compute[j] = compute[j-1] ^ arr[curr];
        value_right += compute[j];
    }
    max_value = max(max_value, value_right);

    // left
    int value_left = 0;
    for(int j = 0; j < n; j++) { 
        int curr = (i - j + n) % n; // +n handles negative remainders in C++
        if(j == 0) compute[j] = arr[curr];
        else compute[j] = compute[j-1] ^ arr[curr];
        value_left += compute[j];
    }
    max_value = max(max_value, value_left);
    }

    cout << max_value;
}

long long optimized_bit_manipulation(vector<int>& arr) {
    int n = arr.size();
    if(n == 0) return 0;

    // calculating blueprint pref
    vector<int>pref(n,0);
    pref[0] = arr[0];
    for(int i = 1; i < n; i++){
        pref[i] = pref[i-1] ^ arr[i];
    }

    int total = pref[n-1];

    vector<vector<int>>bit_count(n,vector<int>(31,0));
    for(int i = 0; i < n; i++){
        for(int b = 0; b <= 30; b++){
            int curr = pref[i];
            if(i > 0) bit_count[i][b] = bit_count[i-1][b];
            if((curr >> b) & 1){
                bit_count[i][b]++;
            }
        }
    }
    
    long long max_value = -1;

    for(int i = 0; i < n; i++){
        int X = (i == 0) ? 0 : pref[i-1];
        int Y = total ^ X;

        long long value = 0; 
        for(int b = 0; b <= 30; b++){

            int ones_in_uwrap = 0;
            int ones_in_wrap = 0;

            if(i == 0){
                ones_in_uwrap = bit_count[n-1][b];
            } else{
                ones_in_uwrap = bit_count[n-1][b] - bit_count[i-1][b];
                ones_in_wrap = bit_count[i-1][b];

                if((X>>b) & 1){
                    ones_in_uwrap = (n-i) - ones_in_uwrap;
                }
                if((Y>>b) & 1){
                    ones_in_wrap = (i) - ones_in_wrap;
                }
            }
            
            int total_ones = ones_in_uwrap + ones_in_wrap;
            
            value += total_ones * (1LL << b); 
        }

        max_value = max(max_value, value);
    }
    return max_value;
}



int main(){
    long long best_right = optimized_bit_manipulation(arr);
    reverse(arr.begin(), arr.end());
    long long best_left = optimized_bit_manipulation(arr);
    cout << max(best_right, best_left) << endl;
}