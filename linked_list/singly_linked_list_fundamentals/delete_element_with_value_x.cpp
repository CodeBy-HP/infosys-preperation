#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class DeleteElementWithValueX {
public:
    // =========================================================================
    // 1. Sentinel Dummy Node Approach
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    ListNode* deleteByValue(ListNode* head, int x) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* curr = &dummy;

        while (curr->next != nullptr) {
            if (curr->next->val == x) {
                ListNode* target = curr->next;
                curr->next = target->next;
                delete target;
                break; // Delete only the first occurrence
            }
            curr = curr->next;
        }

        return dummy.next;
    }
};

void printList(ListNode* head) {
    if (!head) { cout << "[]\n"; return; }
    ListNode* curr = head;
    while (curr) {
        cout << curr->val << (curr->next ? " -> " : " -> nullptr\n");
        curr = curr->next;
    }
}

int main() {
    DeleteElementWithValueX solver;

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    cout << "Original: ";
    printList(head);

    head = solver.deleteByValue(head, 3);
    cout << "After deleting value 3: ";
    printList(head);

    head = solver.deleteByValue(head, 1);
    cout << "After deleting value 1 (head): ";
    printList(head);

    while (head) {
        ListNode* tmp = head->next;
        delete head;
        head = tmp;
    }

    return 0;
}

