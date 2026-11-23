#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class InsertAtTailOfLinkedList {
public:
    // =========================================================================
    // 1. O(N) Traversal to Tail
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    ListNode* insertAtTail(ListNode* head, int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) return newNode;

        ListNode* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;

        return head;
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
    InsertAtTailOfLinkedList solver;

    ListNode* head = nullptr;
    head = solver.insertAtTail(head, 1);
    head = solver.insertAtTail(head, 2);
    head = solver.insertAtTail(head, 3);

    cout << "After inserting 1, 2, 3 at tail: ";
    printList(head);

    while (head) {
        ListNode* tmp = head->next;
        delete head;
        head = tmp;
    }

    return 0;
}

