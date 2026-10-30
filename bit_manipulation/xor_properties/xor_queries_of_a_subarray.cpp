#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> xorQueries(const std::vector<int>& arr, const std::vector<std::vector<int>>& queries) {
        int n = arr.size();
        std::vector<int> prefixXor(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixXor[i + 1] = prefixXor[i] ^ arr[i];
        }

        std::vector<int> result;
        result.reserve(queries.size());
        for (const auto& q : queries) {
            int left = q[0], right = q[1];
            result.push_back(prefixXor[right + 1] ^ prefixXor[left]);
        }
        return result;
    }
};

int main() {
    Solution sol;
    std::vector<int> arr = {1, 3, 4, 8};
    std::vector<std::vector<int>> queries = {{0, 1}, {1, 2}, {0, 3}, {3, 3}};

    std::vector<int> res = sol.xorQueries(arr, queries);
    std::cout << "XOR Queries Result: [ ";
    for (int x : res) std::cout << x << " ";
    std::cout << "]\n(Expected: [ 2 7 14 8 ])\n";

    return 0;
}
