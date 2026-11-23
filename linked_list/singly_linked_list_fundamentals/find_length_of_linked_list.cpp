#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedListLength {
public:
    // =========================================================================
    // 1. Iterative Counter
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    int lengthIterative(ListNode* head) {
        int count = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }
        return count;
    }

    // =========================================================================
    // 2. Recursive Counter
    // Time Complexity: O(N)
    // Space Complexity: O(N) stack
    // =========================================================================
    int lengthRecursive(ListNode* head) {
        if (!head) return 0;
        return 1 + lengthRecursive(head->next);
    }
};

int main() {
    LinkedListLength solver;

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Iterative Length: " << solver.lengthIterative(head) << " (Expected: 5)\n";
    cout << "Recursive Length: " << solver.lengthRecursive(head) << " (Expected: 5)\n";
    cout << "Empty List Length: " << solver.lengthIterative(nullptr) << " (Expected: 0)\n";

    while (head) {
        ListNode* tmp = head->next;
        delete head;
        head = tmp;
    }

    return 0;
}

