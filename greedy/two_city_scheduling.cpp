#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int>A(2*n,0);
    vector<int>B(2*n,0);

    for(int i = 0; i < 2*n; i++){
        cin >> A[i];
    }
    
    for(int i = 0; i < 2*n; i++){
        cin >> B[i];
    }

    long long total = accumulate(A.begin(),A.end(),0LL);

    vector<int>diff(2*n,0);

    for(int i = 0; i < 2*n; i++){
        diff[i] = (min(A[i],B[i])+B[i]) - A[i];
    }

    sort(diff.begin(),diff.end());

    for(int i = 0; i < n; i++){
        total += diff[i];
    }

    cout << total;
}

int main(){
    solve();
}