#include<bits/stdc++.h>
using namespace std;


struct Comparator{
    // defines which has lower priority
    bool operator()(const pair<int,int>& a, pair<int,int>& b){
        // if they are equal
        if(a.first == b.first){
            return a.second > b.second;
        }
        return a.first < b.first;
        // normal case
    }
};


int main(){
    int n,d;
    cin >> n >> d;

    vector<int>arr(n,0);
    for(int i= 0; i < n; i++){
        cin >> arr[i];
    }

    int q;
    cin >> q;


    int total = 0;
    for(int i = 0; i < q; i++){
        int type;
        cin >> type;

        if(type == 1){ // update operation

            int pos,value;
            cin >> pos >> value;

            arr[pos] = value;
        }

        else{ // query operation
            int l,r,k,critical;
            cin >> l >> r >> k >> critical;

            // main Logic

            vector<int>mark(n,0);

            priority_queue<pair<int,int>,
                            vector<pair<int,int>>,
                            Comparator> pq;

            
            for(int i = l; i <= r; i++){
                pq.push({arr[i],i});
            }


            int res = 0;
            int selected = 0;
            while(!pq.empty() && selected <= k){
                auto element = pq.top();
                pq.pop();

                if(mark[element.second] == 1){
                    continue;
                }

                selected++;

                // critical check
                if(element.first >= critical){
                    res += element.first * 4;
                } else{
                    res += element.first;
                }

                // marking invalid indexes
                for(int i = element.second-d+1, i <= element.second+d-1; i++){
                    if(i >= 0 && i < mark.size()){
                        mark[i] = 1; // invalidated
                    }
                }

            }


            total += res;
        }
    }

    cout << total;
}