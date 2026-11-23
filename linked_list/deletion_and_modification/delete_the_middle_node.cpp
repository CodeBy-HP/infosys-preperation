#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class DeleteMiddleNode {
public:
    // =========================================================================
    // 1. Optimal Single-Pass Fast & Slow with Offset
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) {
            delete head;
            return nullptr;
        }

        // By initializing fast two steps ahead, slow stops right before the middle
        ListNode* slow = head;
        ListNode* fast = head->next->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* middle = slow->next;
        slow->next = middle->next;
        delete middle;

        return head;
    }

    // =========================================================================
    // 2. Fast & Slow with Prev Pointer
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    ListNode* deleteMiddleWithPrev(ListNode* head) {
        if (!head || !head->next) {
            delete head;
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;
        delete slow;

        return head;
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
    DeleteMiddleNode solver;

    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(3);
    head1->next->next = new ListNode(4);
    head1->next->next->next = new ListNode(7);
    head1->next->next->next->next = new ListNode(1);
    head1->next->next->next->next->next = new ListNode(2);
    head1->next->next->next->next->next->next = new ListNode(6);

    cout << "Original: ";
    printList(head1);

    head1 = solver.deleteMiddle(head1);
    cout << "After deleteMiddle: ";
    printList(head1);

    while (head1) {
        ListNode* tmp = head1->next;
        delete head1;
        head1 = tmp;
    }
    return 0;
}

