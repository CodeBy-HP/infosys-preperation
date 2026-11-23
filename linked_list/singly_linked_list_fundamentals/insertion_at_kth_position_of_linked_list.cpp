#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class InsertAtKthPositionOfLinkedList {
public:
    // =========================================================================
    // 1. Sentinel Node Insertion
    // Time Complexity: O(min(k, N))
    // Space Complexity: O(1)
    // =========================================================================
    ListNode* insertAtKth(ListNode* head, int val, int k) {
        if (k <= 0) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* curr = &dummy;

        for (int i = 1; i < k && curr != nullptr; i++) {
            curr = curr->next;
        }

        if (curr != nullptr) {
            ListNode* newNode = new ListNode(val);
            newNode->next = curr->next;
            curr->next = newNode;
        }

        return dummy.next;
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
    InsertAtKthPositionOfLinkedList solver;

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(5);

    cout << "Original: ";
    printList(head);

    head = solver.insertAtKth(head, 3, 3);
    cout << "Insert 3 at k=3: ";
    printList(head);

    head = solver.insertAtKth(head, 0, 1);
    cout << "Insert 0 at k=1: ";
    printList(head);

    while (head) {
        ListNode* tmp = head->next;
        delete head;
        head = tmp;
    }

    return 0;
}

