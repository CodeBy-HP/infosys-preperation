#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

// =============================================================================
// Paradigm 1: String Serialization & Deserialization (LeetCode 297 Standard)
// Uses Preorder Traversal with Comma Delimiters and '#' for Null Sentinels.
// Time Complexity: O(N)
// Space Complexity: O(N)
// =============================================================================
class CodecString {
private:
    void serializeDFS(TreeNode* node, stringstream& ss) {
        if (!node) {
            ss << "#,";
            return;
        }
        ss << node->val << ",";
        serializeDFS(node->left, ss);
        serializeDFS(node->right, ss);
    }

    TreeNode* deserializeDFS(queue<string>& tokens) {
        if (tokens.empty()) return nullptr;

        string curr = tokens.front();
        tokens.pop();

        if (curr == "#") return nullptr;

        TreeNode* node = new TreeNode(stoi(curr));
        node->left = deserializeDFS(tokens);
        node->right = deserializeDFS(tokens);
        return node;
    }

public:
    string serialize(TreeNode* root) {
        stringstream ss;
        serializeDFS(root, ss);
        string s = ss.str();
        if (!s.empty() && s.back() == ',') s.pop_back();
        return s;
    }

    TreeNode* deserialize(const string& data) {
        if (data.empty()) return nullptr;
        stringstream ss(data);
        queue<string> tokens;
        string token;
        while (getline(ss, token, ',')) {
            tokens.push(token);
        }
        return deserializeDFS(tokens);
    }
};

// =============================================================================
// Paradigm 2: Array / Vector Serialization & Deserialization
// Uses Preorder Traversal with INT_MIN Sentinel for Null Pointers.
// Useful for binary network protocols and compact in-memory transmission.
// Time Complexity: O(N)
// Space Complexity: O(N)
// =============================================================================
class CodecArray {
private:
    void serializeDFS(TreeNode* node, vector<int>& arr) {
        if (!node) {
            arr.push_back(INT_MIN);
            return;
        }
        arr.push_back(node->val);
        serializeDFS(node->left, arr);
        serializeDFS(node->right, arr);
    }

    TreeNode* deserializeDFS(const vector<int>& arr, int& ind) {
        if (ind >= (int)arr.size() || arr[ind] == INT_MIN) {
            ind++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(arr[ind++]);
        node->left = deserializeDFS(arr, ind);
        node->right = deserializeDFS(arr, ind);
        return node;
    }

public:
    vector<int> serialize(TreeNode* root) {
        vector<int> arr;
        serializeDFS(root, arr);
        return arr;
    }

    TreeNode* deserialize(const vector<int>& arr) {
        int ind = 0;
        return deserializeDFS(arr, ind);
    }
};

void printInOrder(TreeNode* root) {
    if (!root) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    // Build tree:
    //      1
    //     / \
    //    2   3
    //       / \
    //      4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    cout << "Original Tree In-Order: ";
    printInOrder(root);
    cout << "\n\n";

    // 1. Test String Codec
    CodecString strCodec;
    string serializedStr = strCodec.serialize(root);
    cout << "[String Codec] Serialized:   " << serializedStr << "\n";
    TreeNode* rootFromStr = strCodec.deserialize(serializedStr);
    cout << "[String Codec] Deserialized: ";
    printInOrder(rootFromStr);
    cout << "(Expected: 2 1 4 3 5)\n\n";

    // 2. Test Array Codec
    CodecArray arrCodec;
    vector<int> serializedArr = arrCodec.serialize(root);
    cout << "[Array Codec] Serialized count: " << serializedArr.size() << " elements\n";
    cout << "[Array Codec] Array elements:   [ ";
    for (int v : serializedArr) {
        if (v == INT_MIN) cout << "# ";
        else cout << v << " ";
    }
    cout << "]\n";
    TreeNode* rootFromArr = arrCodec.deserialize(serializedArr);
    cout << "[Array Codec] Deserialized:  ";
    printInOrder(rootFromArr);
    cout << "(Expected: 2 1 4 3 5)\n";

    freeTree(root);
    freeTree(rootFromStr);
    freeTree(rootFromArr);

    return 0;
}
