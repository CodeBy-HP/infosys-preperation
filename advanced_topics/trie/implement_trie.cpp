#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// =============================================================================
// 1. Array-Based Trie (Optimized for Lowercase English 'a'-'z')
// Extremely fast O(L) lookup with cache-friendly contiguous pointer arrays.
// =============================================================================
class ArrayTrie {
private:
    struct Node {
        Node* children[26];
        bool isEndOfWord;

        Node() : isEndOfWord(false) {
            for (int i = 0; i < 26; i++) children[i] = nullptr;
        }

        ~Node() {
            for (int i = 0; i < 26; i++) {
                delete children[i];
            }
        }
    };

    Node* root;

    bool removeHelper(Node* curr, const string& word, int depth) {
        if (!curr) return false;

        if (depth == (int)word.length()) {
            if (!curr->isEndOfWord) return false;
            curr->isEndOfWord = false;

            // Check if curr has no children
            for (int i = 0; i < 26; i++) {
                if (curr->children[i]) return false;
            }
            return true;
        }

        int idx = word[depth] - 'a';
        if (removeHelper(curr->children[idx], word, depth + 1)) {
            delete curr->children[idx];
            curr->children[idx] = nullptr;

            if (!curr->isEndOfWord) {
                for (int i = 0; i < 26; i++) {
                    if (curr->children[i]) return false;
                }
                return true;
            }
        }

        return false;
    }

public:
    ArrayTrie() {
        root = new Node();
    }

    ~ArrayTrie() {
        delete root;
    }

    void insert(const string& word) {
        Node* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new Node();
            }
            curr = curr->children[idx];
        }
        curr->isEndOfWord = true;
    }

    bool search(const string& word) const {
        Node* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) return false;
            curr = curr->children[idx];
        }
        return curr->isEndOfWord;
    }

    bool startsWith(const string& prefix) const {
        Node* curr = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!curr->children[idx]) return false;
            curr = curr->children[idx];
        }
        return true;
    }

    void remove(const string& word) {
        removeHelper(root, word, 0);
    }
};

// =============================================================================
// 2. Hash Map-Based Trie (Supports Any Character Set / Unicode)
// Memory efficient for sparse alphabets.
// =============================================================================
class MapTrie {
private:
    struct MapNode {
        unordered_map<char, MapNode*> children;
        bool isEndOfWord;

        MapNode() : isEndOfWord(false) {}

        ~MapNode() {
            for (auto& pair : children) {
                delete pair.second;
            }
        }
    };

    MapNode* root;

public:
    MapTrie() {
        root = new MapNode();
    }

    ~MapTrie() {
        delete root;
    }

    void insert(const string& word) {
        MapNode* curr = root;
        for (char c : word) {
            if (!curr->children.count(c)) {
                curr->children[c] = new MapNode();
            }
            curr = curr->children[c];
        }
        curr->isEndOfWord = true;
    }

    bool search(const string& word) const {
        MapNode* curr = root;
        for (char c : word) {
            if (!curr->children.count(c)) return false;
            curr = curr->children[c];
        }
        return curr->isEndOfWord;
    }

    bool startsWith(const string& prefix) const {
        MapNode* curr = root;
        for (char c : prefix) {
            if (!curr->children.count(c)) return false;
            curr = curr->children[c];
        }
        return true;
    }
};

int main() {
    cout << "=== Array-Based Trie ===\n";
    ArrayTrie trie;
    trie.insert("apple");
    cout << "search(\"apple\"):     " << (trie.search("apple") ? "true" : "false") << " (Expected: true)\n";
    cout << "search(\"app\"):       " << (trie.search("app") ? "true" : "false") << " (Expected: false)\n";
    cout << "startsWith(\"app\"):   " << (trie.startsWith("app") ? "true" : "false") << " (Expected: true)\n";
    trie.insert("app");
    cout << "search(\"app\"):       " << (trie.search("app") ? "true" : "false") << " (Expected: true)\n";

    cout << "\n=== Map-Based Trie ===\n";
    MapTrie mapTrie;
    mapTrie.insert("Code-123");
    cout << "search(\"Code-123\"):   " << (mapTrie.search("Code-123") ? "true" : "false") << " (Expected: true)\n";
    cout << "startsWith(\"Code-\"): " << (mapTrie.startsWith("Code-") ? "true" : "false") << " (Expected: true)\n";

    return 0;
}

