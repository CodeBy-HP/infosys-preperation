#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node(int x) : val(x), prev(nullptr), next(nullptr) {}
    Node(int x, Node* p, Node* n) : val(x), prev(p), next(n) {}
};

class InsertBeforeGivenNodeDLL {
public:
    // =========================================================================
    // 1. O(1) Insertion before a non-head node
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    // =========================================================================
    void insertBeforeNode(Node* node, int val) {
        if (!node) return;

        Node* back = node->prev;
        Node* newNode = new Node(val, back, node);

        if (back) {
            back->next = newNode;
        }
        node->prev = newNode;
    }
};

void printDLL(Node* head) {
    if (!head) { cout << "[]\n"; return; }
    Node* curr = head;
    while (curr) {
        cout << curr->val << (curr->next ? " <-> " : " -> nullptr\n");
        curr = curr->next;
    }
}

int main() {
    InsertBeforeGivenNodeDLL solver;

    Node* head = new Node(1);
    head->next = new Node(2); head->next->prev = head;
    head->next->next = new Node(4); head->next->next->prev = head->next;

    cout << "Original: ";
    printDLL(head);

    Node* node4 = head->next->next;
    solver.insertBeforeNode(node4, 3);
    cout << "After inserting 3 before node 4: ";
    printDLL(head);

    while (head) {
        Node* tmp = head->next;
        delete head;
        head = tmp;
    }
    return 0;
}

