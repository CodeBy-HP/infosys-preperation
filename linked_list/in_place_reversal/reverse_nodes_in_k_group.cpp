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

class ReverseNodesInKGroup {
private:
    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr != nullptr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }

public:
    // =========================================================================
    // 1. Iterative Lookahead Approach
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* groupPrev = &dummy;

        while (true) {
            ListNode* kth = getKthNode(groupPrev, k);
            if (!kth) break; // Remaining nodes < k, leave intact

            ListNode* groupNext = kth->next;

            // In-place reversal of the k-element sublist
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;
            while (curr != groupNext) {
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            // Stitch group into the main list
            ListNode* originalStart = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = originalStart; // Old start is now group tail
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
    ReverseNodesInKGroup solver;

    // Test 1: [1, 2, 3, 4, 5], k = 2 -> [2, 1, 4, 3, 5]
    ListNode* l1 = buildList({1, 2, 3, 4, 5});
    cout << "Original 1: ";
    printList(l1);
    ListNode* res1 = solver.reverseKGroup(l1, 2);
    cout << "Reverse k=2: ";
    printList(res1);
    freeList(res1);

    // Test 2: [1, 2, 3, 4, 5], k = 3 -> [3, 2, 1, 4, 5]
    ListNode* l2 = buildList({1, 2, 3, 4, 5});
    cout << "Original 2: ";
    printList(l2);
    ListNode* res2 = solver.reverseKGroup(l2, 3);
    cout << "Reverse k=3: ";
    printList(res2);
    freeList(res2);

    return 0;
}
