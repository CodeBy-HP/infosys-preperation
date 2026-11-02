#include<bits/stdc++.h>
using namespace std;

int solve(int a,int b, int c){

    int flips = 0;
    for(int i = 0; i < 32; i++){
        int bitA = (a>>i) & 1;
        int bitB = (b>>i) & 1;
        int bitC = (c>>i) & 1;

        if(bitC == 1){
            if(bitA == 0 && bitB == 0){
                flips += 1;
            }
        } else{
            // bitC == 0 
            // if both bitA & bitB are 1 , then flips will be 2 , if one of them is set then flips will be 1 , otherwise 0

            flips += (bitA + bitB);
        }

    }
    
}

int main(){
}


