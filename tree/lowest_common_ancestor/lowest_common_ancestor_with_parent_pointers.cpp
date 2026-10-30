#include <iostream>

using namespace std;

// Definition for a Node with parent pointer.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
    Node(int x) : val(x), left(nullptr), right(nullptr), parent(nullptr) {}
};

class LowestCommonAncestorWithParent {
public:
    // =========================================================================
    // 1. Two-Pointer Linked List Intersection Analogy
    // Time Complexity: O(H)
    // Space Complexity: O(1)
    // =========================================================================
    Node* lowestCommonAncestor(Node* p, Node* q) {
        Node* a = p;
        Node* b = q;

        // When pointer reaches root, redirect to the other node
        while (a != b) {
            a = (a->parent != nullptr) ? a->parent : q;
            b = (b->parent != nullptr) ? b->parent : p;
        }

        return a; // Meeting point is LCA
    }
};

int main() {
    LowestCommonAncestorWithParent solver;

    // Tree:
    //        3
    //       / \
    //      5   1
    //     / \
    //    6   2
    Node* n3 = new Node(3);
    Node* n5 = new Node(5);
    Node* n1 = new Node(1);
    Node* n6 = new Node(6);
    Node* n2 = new Node(2);

    n3->left = n5; n5->parent = n3;
    n3->right = n1; n1->parent = n3;
    n5->left = n6; n6->parent = n5;
    n5->right = n2; n2->parent = n5;

    Node* lca = solver.lowestCommonAncestor(n6, n2);
    cout << "LCA of 6 and 2 with parent pointers: " << (lca ? lca->val : -1) << " (Expected: 5)\n";

    delete n6; delete n2; delete n5; delete n1; delete n3;
    return 0;
}
