#include <iostream>
#include <vector>
#include <algorithm>

struct TrieNode {
    TrieNode* child[2] = {nullptr, nullptr};
};

class BinaryTrie {
private:
    TrieNode* root;

public:
    BinaryTrie() { root = new TrieNode(); }

    void insert(int num) {
        TrieNode* curr = root;
        for (int i = 30; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!curr->child[bit]) {
                curr->child[bit] = new TrieNode();
            }
            curr = curr->child[bit];
        }
    }

    int getMaxXor(int num) {
        TrieNode* curr = root;
        int maxXor = 0;
        for (int i = 30; i >= 0; --i) {
            int bit = (num >> i) & 1;
            int oppositeBit = 1 - bit;
            if (curr->child[oppositeBit]) {
                maxXor |= (1 << i);
                curr = curr->child[oppositeBit];
            } else {
                curr = curr->child[bit];
            }
        }
        return maxXor;
    }
};

class Solution {
public:
    std::vector<int> maximizeXor(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        std::sort(nums.begin(), nums.end());

        int qSize = queries.size();
        // Store {m, x, query_index}
        std::vector<std::vector<int>> offlineQueries(qSize);
        for (int i = 0; i < qSize; ++i) {
            offlineQueries[i] = {queries[i][1], queries[i][0], i};
        }
        std::sort(offlineQueries.begin(), offlineQueries.end());

        std::vector<int> result(qSize);
        BinaryTrie trie;
        int p = 0;
        int n = nums.size();

        for (const auto& q : offlineQueries) {
            int m = q[0], x = q[1], idx = q[2];

            // Dynamically add all nums <= m into the Trie
            while (p < n && nums[p] <= m) {
                trie.insert(nums[p]);
                p++;
            }

            if (p == 0) {
                result[idx] = -1; // No elements <= m
            } else {
                result[idx] = trie.getMaxXor(x);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {0, 1, 2, 3, 4};
    std::vector<std::vector<int>> queries = {{3, 1}, {1, 3}, {5, 6}};

    std::vector<int> ans = sol.maximizeXor(nums, queries);
    std::cout << "Maximize XOR Result: [ ";
    for (int x : ans) std::cout << x << " ";
    std::cout << "]\n(Expected: [ 3 3 7 ])\n";

    return 0;
}
