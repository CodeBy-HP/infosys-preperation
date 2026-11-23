#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class DeleteHeadOfLinkedList {
public:
    // =========================================================================
    // 1. Direct Head Deletion with Memory Freeing
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    // =========================================================================
    ListNode* deleteHead(ListNode* head) {
        if (!head) return nullptr;

        ListNode* temp = head;
        head = head->next;
        delete temp;

        return head;
    }
};

void printList(ListNode* head) {
    ListNode* curr = head;
    if (!curr) {
        cout << "[]\n";
        return;
    }
    while (curr) {
        cout << curr->val << (curr->next ? " -> " : " -> nullptr\n");
        curr = curr->next;
    }
}

int main() {
    DeleteHeadOfLinkedList solver;

    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);

    cout << "Original: ";
    printList(head1);
    head1 = solver.deleteHead(head1);
    cout << "After deleteHead: ";
    printList(head1);

    ListNode* head2 = new ListNode(42);
    head2 = solver.deleteHead(head2);
    cout << "After deleting single node: ";
    printList(head2);

    while (head1) {
        ListNode* tmp = head1->next;
        delete head1;
        head1 = tmp;
    }

    return 0;
}

