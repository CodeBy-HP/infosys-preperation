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

class RemoveNthNodeFromEnd {
public:
    // =========================================================================
    // 1. Optimal One-Pass Approach (Gap of N + 1 with Dummy Node)
    // Time Complexity: O(L)
    // Space Complexity: O(1)
    // =========================================================================
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // Advance fast by n + 1 steps to establish gap
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both until fast hits the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete the nth node from the end
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete; // Avoid memory leaks

        return dummy.next;
    }

    // =========================================================================
    // 2. Alternative Two-Pass Approach (Compute Length)
    // Time Complexity: O(L)
    // Space Complexity: O(1)
    // =========================================================================
    ListNode* removeNthFromEndTwoPass(ListNode* head, int n) {
        int length = 0;
        ListNode* curr = head;
        while (curr) {
            length++;
            curr = curr->next;
        }

        ListNode dummy(0);
        dummy.next = head;
        curr = &dummy;

        for (int i = 0; i < length - n; i++) {
            curr = curr->next;
        }

        ListNode* target = curr->next;
        curr->next = curr->next->next;
        delete target;

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
    if (!head) {
        cout << "[]\n";
        return;
    }
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
    RemoveNthNodeFromEnd solver;

    // Test 1: [1, 2, 3, 4, 5], n = 2 -> [1, 2, 3, 5]
    ListNode* l1 = buildList({1, 2, 3, 4, 5});
    cout << "Original 1: ";
    printList(l1);
    ListNode* res1 = solver.removeNthFromEnd(l1, 2);
    cout << "After removing 2nd from end: ";
    printList(res1);
    freeList(res1);

    // Test 2: [1], n = 1 -> [] (Removing only node)
    ListNode* l2 = buildList({1});
    cout << "Original 2: ";
    printList(l2);
    ListNode* res2 = solver.removeNthFromEnd(l2, 1);
    cout << "After removing 1st from end: ";
    printList(res2);
    freeList(res2);

    return 0;
}
