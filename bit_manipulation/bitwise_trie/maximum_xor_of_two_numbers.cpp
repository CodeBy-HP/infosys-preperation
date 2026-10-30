#include <iostream>
#include <vector>
#include <algorithm>

struct TrieNode {
    TrieNode* child[2];
    TrieNode() {
        child[0] = nullptr;
        child[1] = nullptr;
    }
};

class BinaryTrie {
private:
    TrieNode* root;

public:
    BinaryTrie() {
        root = new TrieNode();
    }

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
            // Greedily choose opposite bit to make the XOR bit 1
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
    int findMaximumXOR(const std::vector<int>& nums) {
        BinaryTrie trie;
        for (int num : nums) {
            trie.insert(num);
        }

        int maxResult = 0;
        for (int num : nums) {
            maxResult = std::max(maxResult, trie.getMaxXor(num));
        }
        return maxResult;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {3, 10, 5, 25, 2, 8};
    std::cout << "Maximum XOR: " << sol.findMaximumXOR(nums) 
              << " (Expected: 28, from 5 ^ 25)\n";

    return 0;
}
