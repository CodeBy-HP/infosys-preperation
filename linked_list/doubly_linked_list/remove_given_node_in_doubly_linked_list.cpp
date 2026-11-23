#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node(int x) : val(x), prev(nullptr), next(nullptr) {}
};

class RemoveGivenNodeInDLL {
public:
    // =========================================================================
    // 1. O(1) In-Place Removal of Given Node
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    // =========================================================================
    void deleteNode(Node* node) {
        if (!node) return;

        Node* back = node->prev;
        Node* front = node->next;

        if (back) {
            back->next = front;
        }
        if (front) {
            front->prev = back;
        }

        node->next = nullptr;
        node->prev = nullptr;
        delete node;
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
    RemoveGivenNodeInDLL solver;

    Node* head = new Node(1);
    head->next = new Node(2); head->next->prev = head;
    head->next->next = new Node(3); head->next->next->prev = head->next;
    head->next->next->next = new Node(4); head->next->next->next->prev = head->next->next;

    cout << "Original DLL: ";
    printDLL(head);

    // Delete node 3
    Node* node3 = head->next->next;
    solver.deleteNode(node3);
    cout << "After removing node 3: ";
    printDLL(head);

    // Delete tail node 4
    Node* node4 = head->next->next;
    solver.deleteNode(node4);
    cout << "After removing tail node 4: ";
    printDLL(head);

    while (head) {
        Node* tmp = head->next;
        delete head;
        head = tmp;
    }
    return 0;
}

