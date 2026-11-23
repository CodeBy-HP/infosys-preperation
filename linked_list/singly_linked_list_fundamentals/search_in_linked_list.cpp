#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class SearchInLinkedList {
public:
    // =========================================================================
    // 1. Iterative Search
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    bool searchIterative(ListNode* head, int key) {
        ListNode* curr = head;
        while (curr != nullptr) {
            if (curr->val == key) return true;
            curr = curr->next;
        }
        return false;
    }

    // =========================================================================
    // 2. Recursive Search
    // Time Complexity: O(N)
    // Space Complexity: O(N) call stack
    // =========================================================================
    bool searchRecursive(ListNode* head, int key) {
        if (!head) return false;
        if (head->val == key) return true;
        return searchRecursive(head->next, key);
    }
};

int main() {
    SearchInLinkedList solver;

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    cout << boolalpha;
    cout << "Search 3 (Iterative): " << solver.searchIterative(head, 3) << " (Expected: true)\n";
    cout << "Search 5 (Iterative): " << solver.searchIterative(head, 5) << " (Expected: false)\n";
    cout << "Search 4 (Recursive): " << solver.searchRecursive(head, 4) << " (Expected: true)\n";
    cout << "Search in nullptr:    " << solver.searchIterative(nullptr, 1) << " (Expected: false)\n";

    while (head) {
        ListNode* tmp = head->next;
        delete head;
        head = tmp;
    }

    return 0;
}

