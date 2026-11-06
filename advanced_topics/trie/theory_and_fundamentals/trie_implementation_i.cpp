#include <iostream>
#include <string>
#include <vector>
#include <cassert>

struct TrieNode {
    TrieNode* links[26];
    bool flag;

    TrieNode() : flag(false) {
        for (int i = 0; i < 26; ++i) {
            links[i] = nullptr;
        }
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, TrieNode* node) {
        links[ch - 'a'] = node;
    }

    TrieNode* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    TrieNode* root;

    void deleteTrie(TrieNode* node) {
        if (!node) return;
        for (int i = 0; i < 26; ++i) {
            if (node->links[i]) {
                deleteTrie(node->links[i]);
            }
        }
        delete node;
    }

public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        deleteTrie(root);
    }

    // Inserts a word into the trie
    void insert(const std::string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new TrieNode());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    // Returns true if the word is in the trie
    bool search(const std::string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->get(ch);
        }
        return node->isEnd();
    }

    // Returns true if there is any word in the trie that starts with the given prefix
    bool startsWith(const std::string& prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->get(ch);
        }
        return true;
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    assert(trie.search("apple") == true);
    assert(trie.search("app") == false);
    assert(trie.startsWith("app") == true);

    trie.insert("app");
    assert(trie.search("app") == true);

    trie.insert("banana");
    assert(trie.search("banana") == true);
    assert(trie.startsWith("ban") == true);
    assert(trie.startsWith("band") == false);

    std::cout << "All Trie I operations tests passed successfully!\n";
    return 0;
}

