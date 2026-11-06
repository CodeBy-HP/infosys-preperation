#include <iostream>
#include <vector>
#include <algorithm>
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

    // Insert 32-bit integer into Trie (from bit 31 down to 0)
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

    // Greedily find the number in Trie that produces max XOR with num
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

int findMaximumXOR(const std::vector<int>& nums) {
    BinaryTrie trie;
    for (int x : nums) {
        trie.insert(x);
    }

    int maxResult = 0;
    for (int x : nums) {
        maxResult = std::max(maxResult, trie.getMaxXor(x));
    }

    return maxResult;
}

int main() {
    std::vector<int> nums1 = {3, 10, 5, 25, 2, 8};
    assert(findMaximumXOR(nums1) == 28);

    std::vector<int> nums2 = {14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
    assert(findMaximumXOR(nums2) == 127);

    // Single element array: 42 ^ 42 = 0
    std::vector<int> nums3 = {42};
    assert(findMaximumXOR(nums3) == 0);

    std::cout << "All Maximum XOR of Two Numbers tests passed successfully!\n";
    return 0;
}

