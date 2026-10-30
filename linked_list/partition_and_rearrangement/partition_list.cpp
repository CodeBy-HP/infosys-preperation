#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class PartitionList {
public:
    // =========================================================================
    // 1. Two-Chain Separation with Dummy Nodes
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    ListNode* partition(ListNode* head, int x) {
        ListNode lessDummy(0);
        ListNode greaterDummy(0);

        ListNode* lessTail = &lessDummy;
        ListNode* greaterTail = &greaterDummy;

        ListNode* curr = head;
        while (curr != nullptr) {
            if (curr->val < x) {
                lessTail->next = curr;
                lessTail = lessTail->next;
            } else {
                greaterTail->next = curr;
                greaterTail = greaterTail->next;
            }
            curr = curr->next;
        }

        // Crucial: Cut off the end of greater list to avoid circular references
        greaterTail->next = nullptr;

        // Stitch the two chains together
        lessTail->next = greaterDummy.next;

        return lessDummy.next;
    }
};

ListNode* buildList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val;
        if (curr->next) cout << " -> ";
        curr = curr->next;
    }
    cout << "\n";
}

void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    PartitionList solver;

    // Test 1: [1, 4, 3, 2, 5, 2], x = 3 -> [1, 2, 2, 4, 3, 5]
    ListNode* l1 = buildList({1, 4, 3, 2, 5, 2});
    cout << "Original 1: ";
    printList(l1);
    ListNode* res1 = solver.partition(l1, 3);
    cout << "Partitioned (x=3): ";
    printList(res1);
    freeList(res1);

    return 0;
}
