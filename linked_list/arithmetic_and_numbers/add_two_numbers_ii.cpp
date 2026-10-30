#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class AddTwoNumbersII {
public:
    // =========================================================================
    // 1. Stack-Based LIFO Approach (No List Reversal)
    // Time Complexity: O(N + M)
    // Space Complexity: O(N + M)
    // =========================================================================
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;

        while (l1) { s1.push(l1->val); l1 = l1->next; }
        while (l2) { s2.push(l2->val); l2 = l2->next; }

        int carry = 0;
        ListNode* head = nullptr;

        while (!s1.empty() || !s2.empty() || carry != 0) {
            int sum = carry;
            if (!s1.empty()) { sum += s1.top(); s1.pop(); }
            if (!s2.empty()) { sum += s2.top(); s2.pop(); }

            carry = sum / 10;
            ListNode* newNode = new ListNode(sum % 10);
            newNode->next = head; // Front-insertion
            head = newNode;
        }

        return head;
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
    AddTwoNumbersII solver;

    // Test 1: [7, 2, 4, 3] + [5, 6, 4] -> [7, 8, 0, 7]
    ListNode* l1 = buildList({7, 2, 4, 3});
    ListNode* l2 = buildList({5, 6, 4});
    cout << "List 1: "; printList(l1);
    cout << "List 2: "; printList(l2);
    ListNode* res = solver.addTwoNumbers(l1, l2);
    cout << "Sum:    "; printList(res);

    freeList(l1); freeList(l2); freeList(res);
    return 0;
}
