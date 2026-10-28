#include<bits/stdc++.h>
using namespace std;

void approach1(){
    string s;
    if (!(cin >> s)) return;

    int n = s.size();

    vector<int> arr_0;
    vector<int> arr_1;
    int itr_0 = 0;
    int itr_1 = 0;
    
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            arr_0.push_back(itr_0 - i);
            itr_0++;
        }
        else{
            arr_1.push_back(itr_1 - i);
            itr_1++;
        }
    }

    auto helper = [&](vector<int>& arr) {
        int N = arr.size();
        
        if(N == 0) return 0; 

        int median = arr[N / 2]; 

        int sum = 0;
        for(int i = 0; i < N; i++){
            sum += abs(median - arr[i]); 
        }

        return sum;
    };

    cout << min(helper(arr_0), helper(arr_1)) << endl;
}
void approach2(){
    string s;
    if (!(cin >> s)) return;

    int total_0 = 0, total_1 = 0;
    
    // Pass 1: Count total occurrences of '0' and '1'
    for (char c : s) {
        if (c == '0') total_0++;
        else total_1++;
    }
    long long swaps_0 = 0, swaps_1 = 0;
    int count_0_left = 0, count_1_left = 0;

    // Pass 2: Calculate jumps for each obstacle character
    for (char c : s) {
        if (c == '0') {
            count_0_left++;
            // When grouping '1's, this '0' is an obstacle.
            // It gets jumped over by the smaller group of '1's.
            swaps_1 += min(count_1_left, total_1 - count_1_left);
        } else {
            count_1_left++;
            // When grouping '0's, this '1' is an obstacle.
            // It gets jumped over by the smaller group of '0's.
            swaps_0 += min(count_0_left, total_0 - count_0_left);
        }
    }
    cout << min(swaps_0, swaps_1) << "\n";
}

// Doubt -> answer
// Let's look at your string: 0 0 0 1 1 1 [0] (0) {0} <0> 1 1 0

// When those two 1s on the right travel left to join the others, they have to cross four zeros. Here is how the loop counts those swaps:

// When the loop is at the 4th zero [0]:

// Left 1s: 3, Right 1s: 2. min(3, 2) = 2.

// We add 2 to our total.

// When the loop moves to the 5th zero (0):

// Left 1s: 3, Right 1s: 2. min(3, 2) = 2.

// We add 2 more to our total.

// When the loop moves to the 6th zero {0}:

// Left 1s: 3, Right 1s: 2. min(3, 2) = 2.

// We add 2 more to our total.

// When the loop moves to the 7th zero <0>:

// Left 1s: 3, Right 1s: 2. min(3, 2) = 2.

// We add 2 more to our total.

// For those two 1s to move left, they require 8 total swaps (2 ones jumping over 4 zeros).
// Our loop calculates exactly 8 swaps (2 + 2 + 2 + 2) by simply iterating through those four zeros and adding up the cost at each step!

// You aren't ignoring the other zeros; you are just calculating the total cost of the movement by breaking it down into a toll collected by each individual zero. Every zero acts as a tollbooth, and it charges 1 swap for every '1' that passes through it.

int main(){
    approach1();
    return 0;
}