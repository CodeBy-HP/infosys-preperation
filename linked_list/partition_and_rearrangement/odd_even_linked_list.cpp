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

class OddEvenLinkedList {
public:
    // =========================================================================
    // 1. Parallel Leapfrog Approach
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
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
    OddEvenLinkedList solver;

    // Test 1: [1, 2, 3, 4, 5] -> [1, 3, 5, 2, 4]
    ListNode* l1 = buildList({1, 2, 3, 4, 5});
    cout << "Original 1: ";
    printList(l1);
    ListNode* res1 = solver.oddEvenList(l1);
    cout << "Odd-Even 1: ";
    printList(res1);
    freeList(res1);

    // Test 2: [2, 1, 3, 5, 6, 4, 7] -> [2, 3, 6, 7, 1, 5, 4]
    ListNode* l2 = buildList({2, 1, 3, 5, 6, 4, 7});
    cout << "Original 2: ";
    printList(l2);
    ListNode* res2 = solver.oddEvenList(l2);
    cout << "Odd-Even 2: ";
    printList(res2);
    freeList(res2);

    return 0;
}
