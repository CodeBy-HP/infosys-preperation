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

class SortList {
private:
    // Splits list by taking first 'step' nodes, severing link, and returning the remainder head
    ListNode* split(ListNode* head, int step) {
        if (!head) return nullptr;
        for (int i = 1; head->next && i < step; i++) {
            head = head->next;
        }
        ListNode* rest = head->next;
        head->next = nullptr;
        return rest;
    }

    // Merges two sorted lists and links them to 'tail', returns the new tail of the merged section
    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* tail) {
        ListNode* curr = tail;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 ? l1 : l2;
        while (curr->next) {
            curr = curr->next;
        }
        return curr;
    }

public:
    // =========================================================================
    // 1. Bottom-Up Merge Sort (Strictly O(1) Auxiliary Space)
    // Time Complexity: O(N log N)
    // Space Complexity: O(1)
    // =========================================================================
    ListNode* sortListBottomUp(ListNode* head) {
        if (!head || !head->next) return head;

        // Step 1: Count total length
        int length = 0;
        ListNode* curr = head;
        while (curr) {
            length++;
            curr = curr->next;
        }

        ListNode dummy(0);
        dummy.next = head;

        // Step 2: Merge in sublists of size 1, 2, 4, 8...
        for (int step = 1; step < length; step *= 2) {
            ListNode* prev = &dummy;
            curr = dummy.next;

            while (curr) {
                ListNode* left = curr;
                ListNode* right = split(left, step);
                curr = split(right, step);

                prev = merge(left, right, prev);
            }
        }

        return dummy.next;
    }

    // =========================================================================
    // 2. Top-Down Recursive Merge Sort
    // Time Complexity: O(N log N)
    // Space Complexity: O(log N) stack
    // =========================================================================
    ListNode* sortListTopDown(ListNode* head) {
        if (!head || !head->next) return head;

        // Fast & slow pointers to find middle and break list
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr; // Sever list into two halves

        ListNode* l1 = sortListTopDown(head);
        ListNode* l2 = sortListTopDown(slow);

        // Standard merge
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1; l1 = l1->next;
            } else {
                tail->next = l2; l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
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
    SortList solver;

    // Test 1: Bottom-Up Sort [4, 2, 1, 3] -> [1, 2, 3, 4]
    ListNode* l1 = buildList({4, 2, 1, 3});
    cout << "Original 1: ";
    printList(l1);
    ListNode* res1 = solver.sortListBottomUp(l1);
    cout << "Sorted (Bottom-Up O(1) space): ";
    printList(res1);
    freeList(res1);

    // Test 2: Top-Down Sort [-1, 5, 3, 4, 0] -> [-1, 0, 3, 4, 5]
    ListNode* l2 = buildList({-1, 5, 3, 4, 0});
    cout << "Original 2: ";
    printList(l2);
    ListNode* res2 = solver.sortListTopDown(l2);
    cout << "Sorted (Top-Down):             ";
    printList(res2);
    freeList(res2);

    return 0;
}
