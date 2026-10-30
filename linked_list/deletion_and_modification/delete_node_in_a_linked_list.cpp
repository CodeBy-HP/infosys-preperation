#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class DeleteNodeWithoutHead {
public:
    // =========================================================================
    // 1. Copy Next Value & Bypass
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    // =========================================================================
    void deleteNode(ListNode* node) {
        ListNode* nextNode = node->next;
        node->val = nextNode->val;
        node->next = nextNode->next;
        delete nextNode;
    }
};

void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val;
        if (curr->next) cout << " -> ";
        curr = curr->next;
    }
    cout << "\n";
}

int main() {
    DeleteNodeWithoutHead solver;

    // List: 4 -> 5 -> 1 -> 9
    ListNode* n1 = new ListNode(4);
    ListNode* n2 = new ListNode(5);
    ListNode* n3 = new ListNode(1);
    ListNode* n4 = new ListNode(9);
    n1->next = n2; n2->next = n3; n3->next = n4;

    cout << "Original List: ";
    printList(n1);

    // Delete node 5 without head pointer
    solver.deleteNode(n2);
    cout << "After deleting 5: ";
    printList(n1);

    // Cleanup
    delete n1; delete n3; delete n4;
    return 0;
}
