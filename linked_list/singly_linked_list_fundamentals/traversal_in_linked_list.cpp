#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedListTraversal {
public:
    // =========================================================================
    // 1. Iterative Traversal
    // Time Complexity: O(N)
    // Space Complexity: O(1) auxiliary
    // =========================================================================
    vector<int> traverseIterative(ListNode* head) {
        vector<int> result;
        ListNode* curr = head;
        while (curr != nullptr) {
            result.push_back(curr->val);
            curr = curr->next;
        }
        return result;
    }

    // =========================================================================
    // 2. Recursive Traversal
    // Time Complexity: O(N)
    // Space Complexity: O(N) call stack
    // =========================================================================
    void traverseRecursiveHelper(ListNode* curr, vector<int>& result) {
        if (!curr) return;
        result.push_back(curr->val);
        traverseRecursiveHelper(curr->next, result);
    }

    vector<int> traverseRecursive(ListNode* head) {
        vector<int> result;
        traverseRecursiveHelper(head, result);
        return result;
    }
};

int main() {
    LinkedListTraversal solver;

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    vector<int> iterRes = solver.traverseIterative(head);
    cout << "Iterative Traversal: ";
    for (int v : iterRes) cout << v << " ";
    cout << "\n";

    vector<int> recRes = solver.traverseRecursive(head);
    cout << "Recursive Traversal: ";
    for (int v : recRes) cout << v << " ";
    cout << "\n";

    // Clean up
    while (head) {
        ListNode* tmp = head->next;
        delete head;
        head = tmp;
    }

    return 0;
}

