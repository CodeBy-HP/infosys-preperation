#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class DetectCycleInLinkedList {
public:
    // =========================================================================
    // 1. Floyd's Tortoise and Hare (Optimal)
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    bool hasCycle(ListNode* head) {
        if (!head || !head->next) return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true; // Cycle detected
            }
        }

        return false;
    }

    // =========================================================================
    // 2. Hash Set Visited Tracking
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    // =========================================================================
    bool hasCycleHashSet(ListNode* head) {
        unordered_set<ListNode*> visited;
        ListNode* curr = head;

        while (curr != nullptr) {
            if (visited.count(curr)) {
                return true;
            }
            visited.insert(curr);
            curr = curr->next;
        }

        return false;
    }
};

int main() {
    DetectCycleInLinkedList solver;

    // Linear list: 1 -> 2 -> 3 -> nullptr
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);

    cout << boolalpha;
    cout << "Test 1 (No Cycle): " << solver.hasCycle(head1) << " (Expected: false)\n";

    // Cyclic list: 1 -> 2 -> 3 -> 4 -> 2
    ListNode* head2 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);

    head2->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // cycle to 2

    cout << "Test 2 (Has Cycle): " << solver.hasCycle(head2) << " (Expected: true)\n";

    // Break cycle for cleanup
    node4->next = nullptr;
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

