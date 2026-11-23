#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class InsertBeforeValueXInLinkedList {
public:
    // =========================================================================
    // 1. Sentinel Lookahead Approach
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    ListNode* insertBeforeX(ListNode* head, int val, int x) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* curr = &dummy;

        while (curr->next != nullptr) {
            if (curr->next->val == x) {
                ListNode* newNode = new ListNode(val);
                newNode->next = curr->next;
                curr->next = newNode;
                break;
            }
            curr = curr->next;
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
    InsertBeforeValueXInLinkedList solver;

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(5);

    cout << "Original: ";
    printList(head);

    head = solver.insertBeforeX(head, 3, 4);
    cout << "Insert 3 before 4: ";
    printList(head);

    head = solver.insertBeforeX(head, 0, 1);
    cout << "Insert 0 before 1 (head): ";
    printList(head);

    while (head) {
        ListNode* tmp = head->next;
        delete head;
        head = tmp;
    }

    return 0;
}

