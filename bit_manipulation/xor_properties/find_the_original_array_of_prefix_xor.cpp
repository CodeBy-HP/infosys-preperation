#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> findArray(const std::vector<int>& pref) {
        int n = pref.size();
        std::vector<int> arr(n);
        arr[0] = pref[0];
        for (int i = 1; i < n; ++i) {
            arr[i] = pref[i] ^ pref[i - 1];
        }
        return arr;
    }
};

int main() {
    Solution sol;
    std::vector<int> pref = {5, 2, 0, 3, 1};
    std::vector<int> arr = sol.findArray(pref);

    std::cout << "Recovered Array: [ ";
    for (int x : arr) std::cout << x << " ";
    std::cout << "]\n(Expected: [ 5 7 2 3 2 ])\n";

    return 0;
}
