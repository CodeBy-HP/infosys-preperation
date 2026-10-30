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

class PlusOneLinkedList {
public:
    // =========================================================================
    // 1. Optimal Single Pass Rightmost Non-9 Tracking
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    ListNode* plusOne(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* notNine = &dummy;
        ListNode* curr = head;

        // Find the rightmost node whose value is not 9
        while (curr != nullptr) {
            if (curr->val != 9) {
                notNine = curr;
            }
            curr = curr->next;
        }

        // Increment the rightmost non-9 digit
        notNine->val++;

        // All subsequent digits flip to 0
        curr = notNine->next;
        while (curr != nullptr) {
            curr->val = 0;
            curr = curr->next;
        }

        if (dummy.val != 0) {
            ListNode* newHead = new ListNode(1);
            newHead->next = head;
            return newHead;
        }

        return dummy.next;
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
    PlusOneLinkedList solver;

    // Test 1: [1, 2, 3] -> [1, 2, 4]
    ListNode* l1 = buildList({1, 2, 3});
    cout << "Original 1: "; printList(l1);
    ListNode* res1 = solver.plusOne(l1);
    cout << "Plus One 1: "; printList(res1);
    freeList(res1);

    // Test 2: [9, 9, 9] -> [1, 0, 0, 0]
    ListNode* l2 = buildList({9, 9, 9});
    cout << "Original 2: "; printList(l2);
    ListNode* res2 = solver.plusOne(l2);
    cout << "Plus One 2: "; printList(res2);
    freeList(res2);

    return 0;
}
