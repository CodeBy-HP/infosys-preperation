#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&arr){

    int count_odd = 0;
    int count_even = 0;

    int odd_first = 0;
    int even_first = 0;

    for(auto e : arr){
        if(e&1){
            // odd
            odd_first += count_even;
            count_odd++;
        }else{
            // even
            even_first += count_odd;
            count_even++;
        }
    }
    return min(odd_first,even_first);
}

int main(){
}


