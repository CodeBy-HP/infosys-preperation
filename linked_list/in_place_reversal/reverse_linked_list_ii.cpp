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

class ReverseLinkedListII {
public:
    // =========================================================================
    // 1. One-Pass Head Insertion with Dummy Node
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        // Step 1: Reach node (left - 1)
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Step 2: Head-insertion in place
        ListNode* curr = prev->next;
        for (int i = 0; i < right - left; i++) {
            ListNode* nextNode = curr->next;
            curr->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;
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
    ReverseLinkedListII solver;

    // Test 1: [1, 2, 3, 4, 5], left = 2, right = 4 -> [1, 4, 3, 2, 5]
    ListNode* l1 = buildList({1, 2, 3, 4, 5});
    cout << "Original 1: ";
    printList(l1);
    ListNode* res1 = solver.reverseBetween(l1, 2, 4);
    cout << "Reversed [2, 4]: ";
    printList(res1);
    freeList(res1);

    // Test 2: [1, 2, 3], left = 1, right = 2 -> [2, 1, 3] (Head reversed)
    ListNode* l2 = buildList({1, 2, 3});
    cout << "Original 2: ";
    printList(l2);
    ListNode* res2 = solver.reverseBetween(l2, 1, 2);
    cout << "Reversed [1, 2]: ";
    printList(res2);
    freeList(res2);

    return 0;
}
