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

class ReorderList {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

public:
    // =========================================================================
    // 1. Three-Phase In-Place Pipeline
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        // Phase 1: Find middle using fast & slow
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Sever second half
        ListNode* second = slow->next;
        slow->next = nullptr;

        // Phase 2: Reverse second half
        second = reverseList(second);

        // Phase 3: Interweave both halves
        ListNode* first = head;
        while (second) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;

            first->next = second;
            second->next = tmp1;

            first = tmp1;
            second = tmp2;
        }
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
    ReorderList solver;

    // Test 1: [1, 2, 3, 4] -> [1, 4, 2, 3]
    ListNode* l1 = buildList({1, 2, 3, 4});
    cout << "Original 1: ";
    printList(l1);
    solver.reorderList(l1);
    cout << "Reordered 1: ";
    printList(l1);
    freeList(l1);

    // Test 2: [1, 2, 3, 4, 5] -> [1, 5, 2, 4, 3]
    ListNode* l2 = buildList({1, 2, 3, 4, 5});
    cout << "Original 2: ";
    printList(l2);
    solver.reorderList(l2);
    cout << "Reordered 2: ";
    printList(l2);
    freeList(l2);

    return 0;
}
