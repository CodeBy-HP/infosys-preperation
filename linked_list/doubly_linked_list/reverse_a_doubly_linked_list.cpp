#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node(int x) : val(x), prev(nullptr), next(nullptr) {}
};

class ReverseDoublyLinkedList {
public:
    // =========================================================================
    // 1. In-Place Swapping of next and prev Pointers
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    Node* reverseDLL(Node* head) {
        if (!head || !head->next) return head;

        Node* curr = head;
        Node* last = nullptr;

        while (curr != nullptr) {
            last = curr->prev;
            curr->prev = curr->next;
            curr->next = last;
            // Advance to the next node in original order (which is now in curr->prev)
            curr = curr->prev;
        }

        // 'last' was the prev of the null pointer (i.e., previous tail's original prev)
        // So the new head is last->prev
        return last->prev;
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
    ReverseDoublyLinkedList solver;

    Node* head = new Node(1);
    head->next = new Node(2); head->next->prev = head;
    head->next->next = new Node(3); head->next->next->prev = head->next;
    head->next->next->next = new Node(4); head->next->next->next->prev = head->next->next;

    cout << "Original DLL: ";
    printDLL(head);

    head = solver.reverseDLL(head);
    cout << "Reversed DLL: ";
    printDLL(head);

    while (head) {
        Node* tmp = head->next;
        delete head;
        head = tmp;
    }
    return 0;
}

