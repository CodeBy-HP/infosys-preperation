#include<bits/stdc++.h>
using namespace std;


void using_set(){
    int n;
    cin >> n;
    vector<int>arr(n,0);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int k,x;
    cin >> k >> x;

    vector<int>ans;

    set<pair<int,int>>st;

    for(int i = 0; i < k; i++){
        st.insert({arr[i],i});
    }


    auto getBeauty = [&]() {
        if(!st.empty() && st.size() >= x){

            auto it = st.begin();

            for(int i = 0; i < x-1; i++){
                it++;
            }
            if(it->first < 0){
                return it->first;
            }
        }
        return 0;
    };


    // insert beauty from the first window
    ans.push_back(getBeauty());

    // slide window from k to n
    for(int i = k; i < n; i++){

        // remove previous
        st.erase({arr[i-k],i-k});


        // add next
        st.insert({arr[i],i});

        // calculate beauty and insert in ans
        ans.push_back(getBeauty());
    }
}

void using_freq_arr(){
    int n;
    cin >> n;
    vector<int>arr(n,0);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int k,x;
    cin >> k >> x;

    vector<int>ans;
    // will keep a freq arr

    // freq[] -50 -> 50
    // indexes 0 -> 102
    // will have to +50 everytime accessing the index
    vector<int>freq(102,0);
    
    for(int i = 0; i < k; i++){
        freq[arr[i] + 50]++;
    }

    auto getBeauty = [&](){

        int count = 0;

        for(int i= 0; i < 50; i++){
            if(freq[i] > 0){
                count += freq[i];
            }

            if(count >= x){
                return i-50;
            }
        }

        return 0;
    };

    ans.push_back(getBeauty());

    for(int i = k; i < n; i++){
        freq[arr[i-k]+50]--;
        freq[arr[i]+50]++;

        ans.push_back(getBeauty());
    }
}


int main(){
    using_set();
    using_freq_arr();
}




