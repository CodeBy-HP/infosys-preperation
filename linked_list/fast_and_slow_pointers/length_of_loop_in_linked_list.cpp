#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class LengthOfLoopInLinkedList {
public:
    // =========================================================================
    // 1. Floyd's Tortoise and Hare Cycle Length
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    int countNodesinLoop(ListNode* head) {
        if (!head || !head->next) return 0;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Cycle detected, count loop length
                int count = 1;
                ListNode* curr = slow->next;
                while (curr != slow) {
                    count++;
                    curr = curr->next;
                }
                return count;
            }
        }

        return 0; // No loop
    }

    // =========================================================================
    // 2. Hash Map Step Tracking
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    // =========================================================================
    int countNodesinLoopHashMap(ListNode* head) {
        unordered_map<ListNode*, int> visitedSteps;
        ListNode* curr = head;
        int step = 1;

        while (curr != nullptr) {
            if (visitedSteps.count(curr)) {
                return step - visitedSteps[curr];
            }
            visitedSteps[curr] = step++;
            curr = curr->next;
        }

        return 0;
    }
};

int main() {
    LengthOfLoopInLinkedList solver;

    // Linear list
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    cout << "Test 1 (No loop): " << solver.countNodesinLoop(head1) << " (Expected: 0)\n";

    // Loop of length 3: 1 -> 2 -> 3 -> 4 -> 2
    ListNode* head2 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    head2->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2; // loop: 2 -> 3 -> 4 -> 2 (length = 3)

    cout << "Test 2 (Loop len 3): " << solver.countNodesinLoop(head2) << " (Expected: 3)\n";

    n4->next = nullptr; // break loop
    while (head2) {
        ListNode* tmp = head2->next;
        delete head2;
        head2 = tmp;
    }
    while (head1) {
        ListNode* tmp = head1->next;
        delete head1;
        head1 = tmp;
    }

    return 0;
}

