#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<
pair<int,int>,
null_type,
less<pair<int,int>>,
rb_tree_tag,
tree_order_statistics_node_update
> ordered_set;

void find_all_anagrams(){

    string s,p;
    cin >> s >> p;

    if (s.size() < p.size()) return;

    int k = p.size();

    vector<int>og_freq(26,0);
    vector<int>window_freq(26,0);
    vector<int>ans;

    for(auto c: p){
        og_freq[c-'a']++;
    }

    for(int i = 0; i < k; i++){
        window_freq[s[i]-'a']++;
    }


    auto match_freq = [&](){
        for(int i = 0; i < 26; i++){
            if(og_freq[i] != window_freq[i]){
                return false;
            }
        }
        return true;
    };

    
    if(match_freq()){
        ans.push_back(0);
    }


    for(int i = k; i < s.size(); i++){
        // decrement
        window_freq[s[i-k]-'a']--;
        // increment
        window_freq[s[i]-'a']++;

        if(match_freq()){
        ans.push_back(i-k+1);
        }
    }
}

bool permutations_in_strings(){
    string s,p;
    cin >> s >> p;

    if (s.size() < p.size()) return;

    int k = p.size();

    vector<int>og_freq(26,0);
    vector<int>window_freq(26,0);

    for(auto c: p){
        og_freq[c-'a']++;
    }

    for(int i = 0; i < k; i++){
        window_freq[s[i]-'a']++;
    }


    auto match_freq = [&](){
        for(int i = 0; i < 26; i++){
            if(og_freq[i] != window_freq[i]){
                return false;
            }
        }
        return true;
    };

    
    if(match_freq()){
        return true;
    }


    for(int i = k; i < s.size(); i++){
        // decrement
        window_freq[s[i-k]-'a']--;
        // increment
        window_freq[s[i]-'a']++;

        if(match_freq()){
        return true;
        }
    }
}

void max_points_from_cards(){
    int n;
    cin >> n;

    vector<int>arr(n,0);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int k;
    cin >> k;

    int w_size = n-k;

    int win_score = 0;

    for(int i = 0; i < w_size; i++){
        win_score += arr[i];
    }

    int min_score = win_score;

    for(int i = w_size; i < n; i++){
        win_score -= arr[i-w_size];
        win_score += arr[i];
        min_score = min(min_score,win_score);
    }

    int total = accumulate(arr.begin(),arr.end(),0);

    cout << total-min_score;
}

void longest_substring_without_rep_chars() {
    string s;
    cin >> s; 

    if (s.empty()) {
        cout << 0 << "\n";
        return;
    }

    vector<int> freq(128, 0); 
    
    int max_size = 0;
    int left = 0; 


    for (int i = 0; i < s.size(); i++) {
        char curr = s[i];
        freq[curr]++; 

        while (freq[curr] > 1) {
            char left_char = s[left];
            freq[left_char]--; 
            left++;           
        }

        int current_win_size = i - left + 1;
        max_size = max(max_size, current_win_size);
    }

    cout << max_size << "\n";
}

void fruits_in_basket(){

    int n;
    cin >> n;

    vector<int>arr(n,0);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    map<int,int>mpp;
    int left = 0;

    int max_size = 0;
    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;

        while(mpp.size() > 2){
            mpp[arr[left]]--;
            if(mpp[arr[left]] == 0){
                mpp.erase(arr[left]);
            }
            left++;
        }

        int window_size = i - left + 1;
        max_size = max(max_size,window_size);
    }
}

void sliding_win_median(){
    ordered_set st;

    int n;
    cin >> n;

    vector<int>arr(n,0);
    vector<double>ans;

    for(int i = 0; i< n; i++){
        cin >> arr[i];
    }

    int k;
    cin >> k;


    for(int i = 0; i < k; i++){
        st.insert({arr[i],i});
    }


    auto find_median = [&](){
        double res = 0;
        int median1 = st.find_by_order(k/2)->first;
        if(k%2==0){ // even
            int median2 = st.find_by_order((k/2)-1)->first;
            res = ((double)median1+(double)median2)/2.0;
        }
        else{
            res = median1/1.0;
        }
        ans.push_back(res);
    };

    find_median();


    for(int i = k; i < n; i++){
        st.insert({arr[i],i});
        st.erase({arr[i-k],i-k});

        find_median();
    }
}

void count_of_smaller_no_after_self(){
    ordered_set st;

    int n;
    cin >> n;

    vector<int>arr(n,0);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int>ans(n,0);

    for(int i = n-1; i >= 0; i--){

        st.insert({arr[i],i});

        int order = st.order_of_key({arr[i],i});
        ans[i] = order;
    }
}

int main(){
    find_all_anagrams();
    permutations_in_strings();
    max_points_from_cards();
    longest_substring_without_rep_chars();
    fruits_in_basket();
    sliding_win_median();
    count_of_smaller_no_after_self();
}
