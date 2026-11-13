#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cassert>

struct BinaryTrieNode {
    BinaryTrieNode* links[2];

    BinaryTrieNode() {
        links[0] = nullptr;
        links[1] = nullptr;
    }

    bool containsKey(int bit) {
        return links[bit] != nullptr;
    }

    BinaryTrieNode* get(int bit) {
        return links[bit];
    }

    void put(int bit, BinaryTrieNode* node) {
        links[bit] = node;
    }
};

class BinaryTrie {
private:
    BinaryTrieNode* root;

    void deleteTrie(BinaryTrieNode* node) {
        if (!node) return;
        if (node->links[0]) deleteTrie(node->links[0]);
        if (node->links[1]) deleteTrie(node->links[1]);
        delete node;
    }

public:
    BinaryTrie() {
        root = new BinaryTrieNode();
    }

    ~BinaryTrie() {
        deleteTrie(root);
    }

    void insert(int num) {
        BinaryTrieNode* node = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new BinaryTrieNode());
            }
            node = node->get(bit);
        }
    }

    int getMaxXor(int num) {
        BinaryTrieNode* node = root;
        int maxXor = 0;

        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            int oppositeBit = 1 - bit;

            if (node->containsKey(oppositeBit)) {
                maxXor |= (1 << i);
                node = node->get(oppositeBit);
            } else {
                node = node->get(bit);
            }
        }

        return maxXor;
    }
};

std::vector<int> maximizeXor(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
    int qSize = queries.size();
    std::vector<int> answer(qSize);

    // Sort nums in ascending order
    std::sort(nums.begin(), nums.end());

    // Vector of tuples: {m_i, x_i, original_index}
    std::vector<std::tuple<int, int, int>> offlineQueries;
    for (int i = 0; i < qSize; ++i) {
        offlineQueries.push_back({queries[i][1], queries[i][0], i});
    }

    // Sort queries by ascending m_i
    std::sort(offlineQueries.begin(), offlineQueries.end());

    BinaryTrie trie;
    int numIdx = 0;
    int n = nums.size();

    for (const auto& [mi, xi, origIdx] : offlineQueries) {
        // Incrementally insert elements <= mi into Trie
        while (numIdx < n && nums[numIdx] <= mi) {
            trie.insert(nums[numIdx]);
            numIdx++;
        }

        // If no element <= mi was inserted, Trie is empty
        if (numIdx == 0) {
            answer[origIdx] = -1;
        } else {
            answer[origIdx] = trie.getMaxXor(xi);
        }
    }

    return answer;
}

int main() {
    std::vector<int> nums1 = {0, 1, 2, 3, 4};
    std::vector<std::vector<int>> queries1 = {{3, 1}, {1, 3}, {5, 6}};
    std::vector<int> expected1 = {3, 3, 7};
    assert(maximizeXor(nums1, queries1) == expected1);

    std::vector<int> nums2 = {5, 2, 4, 6, 6, 3};
    std::vector<std::vector<int>> queries2 = {{12, 4}, {8, 1}, {6, 3}};
    // For query {8, 1}: no elements <= 1 exist -> answer is -1
    std::vector<int> res2 = maximizeXor(nums2, queries2);
    assert(res2[1] == -1);

    std::cout << "All Maximum XOR with an Element tests passed successfully!\n";
    return 0;
}

