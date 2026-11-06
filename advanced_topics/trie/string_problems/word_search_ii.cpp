#include <iostream>
#include <vector>
#include <string>

using namespace std;

// =============================================================================
// Trie Node definition storing the full word string at the leaf
// =============================================================================
struct TrieNode {
    TrieNode* children[26];
    string word;
    int childCount; // Used for in-situ branch pruning

    TrieNode() : word(""), childCount(0) {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }

    ~TrieNode() {
        for (int i = 0; i < 26; i++) delete children[i];
    }
};

class WordSearchII {
private:
    TrieNode* buildTrie(const vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& w : words) {
            TrieNode* curr = root;
            for (char c : w) {
                int idx = c - 'a';
                if (!curr->children[idx]) {
                    curr->children[idx] = new TrieNode();
                    curr->childCount++;
                }
                curr = curr->children[idx];
            }
            curr->word = w;
        }
        return root;
    }

    void dfsStandard(int r, int c, vector<vector<char>>& board, TrieNode* node, vector<string>& results) {
        if (r < 0 || c < 0 || r >= (int)board.size() || c >= (int)board[0].size()) return;
        char ch = board[r][c];
        if (ch == '#' || !node->children[ch - 'a']) return;

        TrieNode* nextNode = node->children[ch - 'a'];

        if (!nextNode->word.empty()) {
            results.push_back(nextNode->word);
            nextNode->word = ""; // Prevent duplicate matches
        }

        board[r][c] = '#'; // Mark visited

        dfsStandard(r + 1, c, board, nextNode, results);
        dfsStandard(r - 1, c, board, nextNode, results);
        dfsStandard(r, c + 1, board, nextNode, results);
        dfsStandard(r, c - 1, board, nextNode, results);

        board[r][c] = ch; // Backtrack
    }

    void dfsPruned(int r, int c, vector<vector<char>>& board, TrieNode* parent, TrieNode* node, vector<string>& results) {
        if (r < 0 || c < 0 || r >= (int)board.size() || c >= (int)board[0].size()) return;
        char ch = board[r][c];
        if (ch == '#' || !node->children[ch - 'a']) return;

        TrieNode* nextNode = node->children[ch - 'a'];

        if (!nextNode->word.empty()) {
            results.push_back(nextNode->word);
            nextNode->word = "";
        }

        board[r][c] = '#';

        dfsPruned(r + 1, c, board, node, nextNode, results);
        dfsPruned(r - 1, c, board, node, nextNode, results);
        dfsPruned(r, c + 1, board, node, nextNode, results);
        dfsPruned(r, c - 1, board, node, nextNode, results);

        board[r][c] = ch;

        // In-situ pruning: If nextNode has no children and is not a word, prune it
        if (nextNode->childCount == 0 && nextNode->word.empty()) {
            delete nextNode;
            node->children[ch - 'a'] = nullptr;
            node->childCount--;
        }
    }

public:
    // =========================================================================
    // 1. Standard Trie + DFS with Backtracking
    // =========================================================================
    vector<string> findWordsStandard(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = buildTrie(words);
        vector<string> results;

        int m = board.size(), n = board[0].size();
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                dfsStandard(r, c, board, root, results);
            }
        }

        delete root;
        return results;
    }

    // =========================================================================
    // 2. Optimized Trie with In-Situ Dead-End Node Pruning
    // =========================================================================
    vector<string> findWordsPruned(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = buildTrie(words);
        vector<string> results;

        int m = board.size(), n = board[0].size();
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                dfsPruned(r, c, board, nullptr, root, results);
            }
        }

        delete root;
        return results;
    }
};

int main() {
    WordSearchII solver;

    vector<vector<char>> board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };
    vector<string> words = {"oath", "pea", "eat", "rain"};

    cout << "Board Search Results (eat, oath expected):\n";
    vector<string> found = solver.findWordsStandard(board, words);
    for (const string& w : found) {
        cout << "  Found: " << w << "\n";
    }

    return 0;
}

