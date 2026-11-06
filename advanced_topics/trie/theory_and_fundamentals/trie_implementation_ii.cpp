#include <iostream>
#include <string>
#include <cassert>

struct TrieNode {
    TrieNode* links[26];
    int countEndsWith;
    int countPrefix;

    TrieNode() : countEndsWith(0), countPrefix(0) {
        for (int i = 0; i < 26; ++i) {
            links[i] = nullptr;
        }
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

    void increaseEnd() {
        countEndsWith++;
    }

    void increasePrefix() {
        countPrefix++;
    }

    void deleteEnd() {
        countEndsWith--;
    }

    void reducePrefix() {
        countPrefix--;
    }

    int getEnd() {
        return countEndsWith;
    }

    int getPrefix() {
        return countPrefix;
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

    void insert(const std::string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new TrieNode());
            }
            node = node->get(ch);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(const std::string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                return 0;
            }
            node = node->get(ch);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(const std::string& prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (!node->containsKey(ch)) {
                return 0;
            }
            node = node->get(ch);
        }
        return node->getPrefix();
    }

    void erase(const std::string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                return;
            }
            node = node->get(ch);
            node->reducePrefix();
        }
        node->deleteEnd();
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    trie.insert("apple");
    trie.insert("apps");
    trie.insert("app");

    assert(trie.countWordsEqualTo("apple") == 2);
    assert(trie.countWordsEqualTo("app") == 1);
    assert(trie.countWordsStartingWith("app") == 4); // "apple", "apple", "apps", "app"

    trie.erase("apple");
    assert(trie.countWordsEqualTo("apple") == 1);
    assert(trie.countWordsStartingWith("app") == 3);

    trie.erase("app");
    assert(trie.countWordsEqualTo("app") == 0);
    assert(trie.countWordsStartingWith("app") == 2);

    assert(trie.countWordsEqualTo("banana") == 0);
    assert(trie.countWordsStartingWith("ban") == 0);

    std::cout << "All Trie II advanced operations tests passed successfully!\n";
    return 0;
}

