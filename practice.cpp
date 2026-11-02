#include<bits/stdc++.h>
using namespace std;

int solve(int a,int b){

    int ans = 0;
    int carry = 0;
    for(int i = 0; i < 32; i++){

        int bit_a = (a >> i) & 1;
        int bit_b = (b >> i) & 1;
        // xor sum with carry
        int sum = bit_a ^ bit_b  ^ carry;

        if((bit_a && bit_b) || (bit_b && carry) || (carry && bit_a)) carry = 1;
        else carry = 0;

        ans = ans | (sum << i);
    }
    return ans;
}

int main(){
}


