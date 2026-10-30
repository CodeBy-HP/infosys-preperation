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

class MergeTwoSortedLists {
public:
    // =========================================================================
    // 1. Iterative Approach with Sentinel Dummy Node
    // Time Complexity: O(N + M)
    // Space Complexity: O(1)
    // =========================================================================
    ListNode* mergeTwoListsIterative(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Attach remaining nodes in O(1)
        tail->next = (list1 != nullptr) ? list1 : list2;

        return dummy.next;
    }

    // =========================================================================
    // 2. Recursive Approach
    // Time Complexity: O(N + M)
    // Space Complexity: O(N + M) call stack
    // =========================================================================
    ListNode* mergeTwoListsRecursive(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        if (list1->val <= list2->val) {
            list1->next = mergeTwoListsRecursive(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoListsRecursive(list1, list2->next);
            return list2;
        }
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
    MergeTwoSortedLists solver;

    // Test 1: Iterative Merge [1, 2, 4] and [1, 3, 4]
    ListNode* l1 = buildList({1, 2, 4});
    ListNode* l2 = buildList({1, 3, 4});
    ListNode* merged = solver.mergeTwoListsIterative(l1, l2);
    cout << "Merged (Iterative): ";
    printList(merged);
    freeList(merged);

    // Test 2: Recursive Merge [2, 5] and [1, 3, 7]
    ListNode* a = buildList({2, 5});
    ListNode* b = buildList({1, 3, 7});
    ListNode* recMerged = solver.mergeTwoListsRecursive(a, b);
    cout << "Merged (Recursive): ";
    printList(recMerged);
    freeList(recMerged);

    return 0;
}
