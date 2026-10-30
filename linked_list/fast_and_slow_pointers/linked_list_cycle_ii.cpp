#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedListCycleII {
public:
    // =========================================================================
    // 1. Optimal Floyd's Tortoise and Hare (Cycle Detection + Entry Point)
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    ListNode* detectCycle(ListNode* head) {
        if (!head || !head->next) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        // Phase 1: Detect cycle collision point
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                // Phase 2: Find entry point of the cycle
                ListNode* ptr1 = head;
                ListNode* ptr2 = slow;

                while (ptr1 != ptr2) {
                    ptr1 = ptr1->next;
                    ptr2 = ptr2->next;
                }
                return ptr1; // Guaranteed entry node
            }
        }

        return nullptr; // No cycle
    }

    // =========================================================================
    // 2. Hash Set Approach (Visited Pointer Tracking)
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    // =========================================================================
    ListNode* detectCycleHashSet(ListNode* head) {
        unordered_set<ListNode*> visited;
        ListNode* curr = head;

        while (curr != nullptr) {
            if (visited.count(curr)) {
                return curr; // First already-seen pointer is entry node
            }
            visited.insert(curr);
            curr = curr->next;
        }

        return nullptr;
    }
};

int main() {
    LinkedListCycleII solver;

    // Build list: 3 -> 2 -> 0 -> -4 with cycle at node 2 (index 1)
    ListNode* n0 = new ListNode(3);
    ListNode* n1 = new ListNode(2);
    ListNode* n2 = new ListNode(0);
    ListNode* n3 = new ListNode(-4);

    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n1; // Cycle to n1

    ListNode* cycleEntry = solver.detectCycle(n0);
    cout << "Test 1 (Cyclic List):\n";
    cout << "  Cycle Entry Node Value: " << (cycleEntry ? cycleEntry->val : -1) << " (Expected: 2)\n";

    // Break cycle for cleanup
    n3->next = nullptr;
    delete n0; delete n1; delete n2; delete n3;

    // Test 2: Linear list [1, 2] -> No cycle
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    a->next = b;

    ListNode* noCycle = solver.detectCycle(a);
    cout << "Test 2 (Linear List):\n";
    cout << "  Has Cycle: " << (noCycle ? "Yes" : "No") << " (Expected: No)\n";

    delete a; delete b;
    return 0;
}
