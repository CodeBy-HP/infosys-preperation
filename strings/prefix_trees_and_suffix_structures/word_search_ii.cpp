#include <iostream>
#include <string>
#include <vector>

using namespace std;

class WordSearchII {
private:
    struct TrieNode {
        TrieNode* children[26];
        string word;
        TrieNode() : word("") {
            for (int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };

    void insertWord(TrieNode* root, const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->word = word; // Store word at leaf
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, vector<string>& result) {
        char ch = board[r][c];
        if (ch == '#' || !node->children[ch - 'a']) return;

        node = node->children[ch - 'a'];
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word.clear(); // Avoid duplicates
        }

        board[r][c] = '#'; // Mark visited

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < (int)board.size() && nc >= 0 && nc < (int)board[0].size()) {
                dfs(board, nr, nc, node, result);
            }
        }

        board[r][c] = ch; // Backtrack
    }

    void freeTrie(TrieNode* node) {
        if (!node) return;
        for (int i = 0; i < 26; i++) {
            if (node->children[i]) freeTrie(node->children[i]);
        }
        delete node;
    }

public:
    // =========================================================================
    // 1. Grid DFS with Trie Prefix Pruning
    // =========================================================================
    vector<string> findWords(vector<vector<char>>& board, const vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& w : words) insertWord(root, w);

        vector<string> result;
        int m = board.size();
        int n = board[0].size();

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                dfs(board, r, c, root, result);
            }
        }

        freeTrie(root);
        return result;
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

    vector<string> found = solver.findWords(board, words);
    cout << "Words found on board: [ ";
    for (const string& w : found) cout << "\"" << w << "\" ";
    cout << "]\n(Expected: [ \"oath\" \"eat\" ] in any order)\n";

    return 0;
}
