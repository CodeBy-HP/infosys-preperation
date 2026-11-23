#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class DeleteTailOfLinkedList {
public:
    // =========================================================================
    // 1. Two-Node Lookahead
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    ListNode* deleteTail(ListNode* head) {
        if (!head || !head->next) {
            delete head;
            return nullptr;
        }

        ListNode* curr = head;
        while (curr->next->next != nullptr) {
            curr = curr->next;
        }

        delete curr->next;
        curr->next = nullptr;

        return head;
    }
};

void printList(ListNode* head) {
    if (!head) {
        cout << "[]\n";
        return;
    }
    ListNode* curr = head;
    while (curr) {
        cout << curr->val << (curr->next ? " -> " : " -> nullptr\n");
        curr = curr->next;
    }
}

int main() {
    DeleteTailOfLinkedList solver;

    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);

    cout << "Original: ";
    printList(head1);
    head1 = solver.deleteTail(head1);
    cout << "After deleteTail: ";
    printList(head1);

    ListNode* head2 = new ListNode(99);
    head2 = solver.deleteTail(head2);
    cout << "Single node after deleteTail: ";
    printList(head2);

    while (head1) {
        ListNode* tmp = head1->next;
        delete head1;
        head1 = tmp;
    }

    return 0;
}

