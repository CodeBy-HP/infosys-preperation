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

class RotateList {
public:
    // =========================================================================
    // 1. Ring Cut Approach
    // Time Complexity: O(L)
    // Space Complexity: O(1)
    // =========================================================================
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Compute length and find current tail
        int length = 1;
        ListNode* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
            length++;
        }

        // Step 2: Normalize k
        k = k % length;
        if (k == 0) return head;

        // Step 3: Connect tail to head to form circle
        tail->next = head;

        // Step 4: Find new tail: (length - k) steps from head
        int stepsToNewTail = length - k;
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        // Step 5: Sever circle and set new head
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

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
    RotateList solver;

    // Test 1: [1, 2, 3, 4, 5], k = 2 -> [4, 5, 1, 2, 3]
    ListNode* l1 = buildList({1, 2, 3, 4, 5});
    cout << "Original 1: ";
    printList(l1);
    ListNode* res1 = solver.rotateRight(l1, 2);
    cout << "Rotated k=2: ";
    printList(res1);
    freeList(res1);

    // Test 2: [0, 1, 2], k = 4 -> [2, 0, 1]
    ListNode* l2 = buildList({0, 1, 2});
    cout << "Original 2: ";
    printList(l2);
    ListNode* res2 = solver.rotateRight(l2, 4);
    cout << "Rotated k=4: ";
    printList(res2);
    freeList(res2);

    return 0;
}
