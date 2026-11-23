#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class InsertAtHeadOfLinkedList {
public:
    // =========================================================================
    // 1. O(1) Head Insertion
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    // =========================================================================
    ListNode* insertAtHead(ListNode* head, int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        return newNode;
    }
};

void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        cout << curr->val << (curr->next ? " -> " : " -> nullptr\n");
        curr = curr->next;
    }
}

int main() {
    InsertAtHeadOfLinkedList solver;

    ListNode* head = nullptr;
    head = solver.insertAtHead(head, 3);
    head = solver.insertAtHead(head, 2);
    head = solver.insertAtHead(head, 1);

    cout << "After inserting 3, then 2, then 1 at head: ";
    printList(head);

    while (head) {
        ListNode* tmp = head->next;
        delete head;
        head = tmp;
    }

    return 0;
}

