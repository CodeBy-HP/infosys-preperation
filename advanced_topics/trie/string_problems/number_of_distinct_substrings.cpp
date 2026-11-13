#include <iostream>
#include <string>
#include <vector>
#include <cassert>

struct TrieNode {
    TrieNode* links[26];

    TrieNode() {
        for (int i = 0; i < 26; ++i) links[i] = nullptr;
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    TrieNode* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, TrieNode* node) {
        links[ch - 'a'] = node;
    }
};

// Memory cleanup helper
void cleanTrie(TrieNode* node) {
    if (!node) return;
    for (int i = 0; i < 26; ++i) {
        if (node->links[i]) cleanTrie(node->links[i]);
    }
    delete node;
}

int countDistinctSubstrings(const std::string& s) {
    int count = 0;
    TrieNode* root = new TrieNode();

    int n = s.length();
    for (int i = 0; i < n; ++i) {
        TrieNode* curr = root;
        for (int j = i; j < n; ++j) {
            char ch = s[j];
            if (!curr->containsKey(ch)) {
                curr->put(ch, new TrieNode());
                count++;
            }
            curr = curr->get(ch);
        }
    }

    cleanTrie(root);
    return count;
}

int main() {
    // "abab" -> distinct substrings: "a", "b", "ab", "ba", "aba", "bab", "abab" -> 7
    assert(countDistinctSubstrings("abab") == 7);

    // "aaa" -> distinct substrings: "a", "aa", "aaa" -> 3
    assert(countDistinctSubstrings("aaa") == 3);

    // "abcdef" -> all substrings distinct: 6 * 7 / 2 = 21
    assert(countDistinctSubstrings("abcdef") == 21);

    // Single character
    assert(countDistinctSubstrings("z") == 1);

    // Empty string
    assert(countDistinctSubstrings("") == 0);

    std::cout << "All Number of Distinct Substrings tests passed successfully!\n";
    return 0;
}

