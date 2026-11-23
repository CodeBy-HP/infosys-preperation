#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node(int x) : val(x), prev(nullptr), next(nullptr) {}
};

class RemoveDuplicatesSortedDLL {
public:
    // =========================================================================
    // 1. In-Place Duplicate Removal
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    Node* removeDuplicates(Node* head) {
        if (!head || !head->next) return head;

        Node* curr = head;

        while (curr != nullptr && curr->next != nullptr) {
            Node* nextNode = curr->next;

            // Skip and free all duplicate nodes
            while (nextNode != nullptr && nextNode->val == curr->val) {
                Node* duplicate = nextNode;
                nextNode = nextNode->next;
                delete duplicate;
            }

            curr->next = nextNode;
            if (nextNode != nullptr) {
                nextNode->prev = curr;
            }

            curr = curr->next;
        }

        return head;
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
    RemoveDuplicatesSortedDLL solver;

    Node* head = new Node(1);
    head->next = new Node(1); head->next->prev = head;
    head->next->next = new Node(1); head->next->next->prev = head->next;
    head->next->next->next = new Node(2); head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(3); head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(3); head->next->next->next->next->next->prev = head->next->next->next->next;

    cout << "Original Sorted DLL: ";
    printDLL(head);

    head = solver.removeDuplicates(head);
    cout << "After removing duplicates: ";
    printDLL(head);

    while (head) {
        Node* tmp = head->next;
        delete head;
        head = tmp;
    }
    return 0;
}

