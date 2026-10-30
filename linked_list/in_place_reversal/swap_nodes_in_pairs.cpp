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

class SwapNodesInPairs {
public:
    // =========================================================================
    // 1. Iterative Approach with Sentinel Dummy Node
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    ListNode* swapPairsIterative(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        while (prev->next != nullptr && prev->next->next != nullptr) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            // Rewire pointers
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Advance prev for next pair
            prev = first;
        }

        return dummy.next;
    }

    // =========================================================================
    // 2. Recursive Approach
    // Time Complexity: O(N)
    // Space Complexity: O(N) call stack
    // =========================================================================
    ListNode* swapPairsRecursive(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* second = head->next;
        head->next = swapPairsRecursive(second->next);
        second->next = head;

        return second;
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
    SwapNodesInPairs solver;

    // Test 1: Even length [1, 2, 3, 4] -> [2, 1, 4, 3]
    ListNode* l1 = buildList({1, 2, 3, 4});
    cout << "Original 1: ";
    printList(l1);
    ListNode* res1 = solver.swapPairsIterative(l1);
    cout << "Swapped 1:  ";
    printList(res1);
    freeList(res1);

    // Test 2: Odd length [1, 2, 3, 4, 5] -> [2, 1, 4, 3, 5]
    ListNode* l2 = buildList({1, 2, 3, 4, 5});
    cout << "Original 2: ";
    printList(l2);
    ListNode* res2 = solver.swapPairsRecursive(l2);
    cout << "Swapped 2:  ";
    printList(res2);
    freeList(res2);

    return 0;
}
