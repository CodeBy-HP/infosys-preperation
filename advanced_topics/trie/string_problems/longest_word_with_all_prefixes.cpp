#include <iostream>
#include <vector>
#include <string>
#include <cassert>

struct TrieNode {
    TrieNode* links[26];
    bool isEnd;

    TrieNode() : isEnd(false) {
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

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const std::string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new TrieNode());
            }
            node = node->get(ch);
        }
        node->isEnd = true;
    }

    // Checks if every prefix of the word exists as a complete word
    bool checkIfAllPrefixesExist(const std::string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) return false;
            node = node->get(ch);
            if (!node->isEnd) return false;
        }
        return true;
    }
};

std::string completeString(const std::vector<std::string>& words) {
    Trie trie;
    for (const auto& w : words) {
        trie.insert(w);
    }

    std::string longest = "";

    for (const auto& w : words) {
        if (trie.checkIfAllPrefixesExist(w)) {
            if (w.length() > longest.length()) {
                longest = w;
            } else if (w.length() == longest.length() && w < longest) {
                longest = w;
            }
        }
    }

    return longest.empty() ? "None" : longest;
}

int main() {
    std::vector<std::string> words1 = {"n", "ni", "nin", "ninj", "ninja", "ninga"};
    assert(completeString(words1) == "ninja");

    std::vector<std::string> words2 = {"ab", "bc"};
    assert(completeString(words2) == "None");

    std::vector<std::string> words3 = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    // "apple" and "apply" both have length 5 with all prefixes existing:
    // "apple" < "apply" lexicographically
    assert(completeString(words3) == "apple");

    std::cout << "All Longest Word with All Prefixes tests passed successfully!\n";
    return 0;
}

