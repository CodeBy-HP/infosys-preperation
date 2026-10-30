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

class ReverseLinkedList {
public:
    // =========================================================================
    // 1. Iterative 3-Pointer Approach
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    ListNode* reverseListIterative(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next; // Cache next node
            curr->next = prev;               // Invert link
            prev = curr;                     // Move prev forward
            curr = nextNode;                 // Move curr forward
        }

        return prev;
    }

    // =========================================================================
    // 2. Recursive Approach
    // Time Complexity: O(N)
    // Space Complexity: O(N) recursion stack
    // =========================================================================
    ListNode* reverseListRecursive(ListNode* head) {
        // Base case: empty or single node list
        if (!head || !head->next) return head;

        ListNode* newHead = reverseListRecursive(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newHead;
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
    ReverseLinkedList solver;

    // Test 1: Iterative Reversal [1, 2, 3, 4, 5]
    ListNode* l1 = buildList({1, 2, 3, 4, 5});
    cout << "Original 1: ";
    printList(l1);
    ListNode* rev1 = solver.reverseListIterative(l1);
    cout << "Reversed (Iterative): ";
    printList(rev1);
    freeList(rev1);

    // Test 2: Recursive Reversal [10, 20, 30]
    ListNode* l2 = buildList({10, 20, 30});
    cout << "Original 2: ";
    printList(l2);
    ListNode* rev2 = solver.reverseListRecursive(l2);
    cout << "Reversed (Recursive): ";
    printList(rev2);
    freeList(rev2);

    return 0;
}
