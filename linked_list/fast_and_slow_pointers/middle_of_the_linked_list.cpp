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

class MiddleOfLinkedList {
public:
    // =========================================================================
    // 1. Optimal Fast & Slow Pointer Approach (Floyd's Tortoise & Hare)
    // Time Complexity: O(N) - single pass, exactly N/2 steps
    // Space Complexity: O(1) - two auxiliary pointers
    // =========================================================================
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // For even length, fast reaches nullptr; for odd length, fast->next is nullptr
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // =========================================================================
    // 2. Alternative Two-Pass Approach (Count Length)
    // Time Complexity: O(N) - passes list twice
    // Space Complexity: O(1)
    // =========================================================================
    ListNode* middleNodeTwoPass(ListNode* head) {
        int length = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            length++;
            curr = curr->next;
        }

        curr = head;
        for (int i = 0; i < length / 2; i++) {
            curr = curr->next;
        }
        return curr;
    }
};

// Helper utilities for testing
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
    MiddleOfLinkedList solver;

    // Test 1: Odd length [1, 2, 3, 4, 5] -> Expected middle: 3
    ListNode* list1 = buildList({1, 2, 3, 4, 5});
    cout << "Test 1 (Odd Length): ";
    printList(list1);
    ListNode* mid1 = solver.middleNode(list1);
    cout << "  Middle Node: " << (mid1 ? mid1->val : -1) << " (Expected: 3)\n";

    // Test 2: Even length [1, 2, 3, 4, 5, 6] -> Expected middle: 4
    ListNode* list2 = buildList({1, 2, 3, 4, 5, 6});
    cout << "Test 2 (Even Length): ";
    printList(list2);
    ListNode* mid2 = solver.middleNode(list2);
    cout << "  Middle Node: " << (mid2 ? mid2->val : -1) << " (Expected: 4)\n";

    freeList(list1);
    freeList(list2);
    return 0;
}
