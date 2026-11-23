#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class DeleteKthElementOfLinkedList {
public:
    // =========================================================================
    // 1. Sentinel Dummy Node Approach (Uniform logic)
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    ListNode* deleteKthNode(ListNode* head, int k) {
        if (!head || k <= 0) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        for (int i = 1; i < k && prev->next != nullptr; i++) {
            prev = prev->next;
        }

        if (prev->next != nullptr) {
            ListNode* target = prev->next;
            prev->next = target->next;
            delete target;
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
    DeleteKthElementOfLinkedList solver;

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original: ";
    printList(head);

    head = solver.deleteKthNode(head, 3);
    cout << "After deleting 3rd node: ";
    printList(head);

    head = solver.deleteKthNode(head, 1);
    cout << "After deleting 1st node: ";
    printList(head);

    while (head) {
        ListNode* tmp = head->next;
        delete head;
        head = tmp;
    }

    return 0;
}

