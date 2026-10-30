#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class IntersectionOfTwoLinkedLists {
public:
    // =========================================================================
    // 1. Optimal Two-Pointer Switching Approach
    // Time Complexity: O(M + N)
    // Space Complexity: O(1)
    // =========================================================================
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) return nullptr;

        ListNode* pA = headA;
        ListNode* pB = headB;

        // When pA reaches end of A, redirect to B.
        // When pB reaches end of B, redirect to A.
        // They either meet at intersection node or both hit nullptr.
        while (pA != pB) {
            pA = (pA == nullptr) ? headB : pA->next;
            pB = (pB == nullptr) ? headA : pB->next;
        }

        return pA;
    }

    // =========================================================================
    // 2. Length Difference Offset Approach
    // Time Complexity: O(M + N)
    // Space Complexity: O(1)
    // =========================================================================
    ListNode* getIntersectionNodeDifference(ListNode* headA, ListNode* headB) {
        int lenA = 0, lenB = 0;
        ListNode* currA = headA;
        ListNode* currB = headB;

        while (currA) { lenA++; currA = currA->next; }
        while (currB) { lenB++; currB = currB->next; }

        currA = headA;
        currB = headB;

        // Align starting points
        if (lenA > lenB) {
            for (int i = 0; i < lenA - lenB; i++) currA = currA->next;
        } else {
            for (int i = 0; i < lenB - lenA; i++) currB = currB->next;
        }

        while (currA && currB) {
            if (currA == currB) return currA;
            currA = currA->next;
            currB = currB->next;
        }

        return nullptr;
    }
};

int main() {
    IntersectionOfTwoLinkedLists solver;

    // Construct common tail: 8 -> 4 -> 5
    ListNode* c1 = new ListNode(8);
    ListNode* c2 = new ListNode(4);
    ListNode* c3 = new ListNode(5);
    c1->next = c2; c2->next = c3;

    // List A: 4 -> 1 -> [8 -> 4 -> 5]
    ListNode* a1 = new ListNode(4);
    ListNode* a2 = new ListNode(1);
    a1->next = a2; a2->next = c1;

    // List B: 5 -> 6 -> 1 -> [8 -> 4 -> 5]
    ListNode* b1 = new ListNode(5);
    ListNode* b2 = new ListNode(6);
    ListNode* b3 = new ListNode(1);
    b1->next = b2; b2->next = b3; b3->next = c1;

    ListNode* intersection = solver.getIntersectionNode(a1, b1);
    cout << "Test 1 (Intersecting Lists):\n";
    cout << "  Intersection Node Val: " << (intersection ? intersection->val : -1) << " (Expected: 8)\n";

    // Disconnect shared tail before deleting
    a2->next = nullptr;
    b3->next = nullptr;
    delete a1; delete a2;
    delete b1; delete b2; delete b3;
    delete c1; delete c2; delete c3;

    return 0;
}
