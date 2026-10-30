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

class RemoveDuplicatesFromSortedListII {
public:
    // =========================================================================
    // 1. Sentinel Dummy with Duplicate Cluster Skip
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        while (head != nullptr) {
            // Check if head starts a duplicate cluster
            if (head->next != nullptr && head->val == head->next->val) {
                // Skip all nodes with the duplicate value
                while (head->next != nullptr && head->val == head->next->val) {
                    ListNode* temp = head;
                    head = head->next;
                    delete temp; // Clean up memory
                }
                ListNode* temp = head;
                head = head->next;
                delete temp;

                prev->next = head; // Discard whole cluster
            } else {
                prev = prev->next;
                head = head->next;
            }
        }

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
    if (!head) { cout << "[]\n"; return; }
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
    RemoveDuplicatesFromSortedListII solver;

    // Test 1: [1, 2, 3, 3, 4, 4, 5] -> [1, 2, 5]
    ListNode* l1 = buildList({1, 2, 3, 3, 4, 4, 5});
    cout << "Original 1: "; printList(l1);
    ListNode* res1 = solver.deleteDuplicates(l1);
    cout << "Distinct 1: "; printList(res1);
    freeList(res1);

    // Test 2: [1, 1, 1, 2, 3] -> [2, 3]
    ListNode* l2 = buildList({1, 1, 1, 2, 3});
    cout << "Original 2: "; printList(l2);
    ListNode* res2 = solver.deleteDuplicates(l2);
    cout << "Distinct 2: "; printList(res2);
    freeList(res2);

    return 0;
}
