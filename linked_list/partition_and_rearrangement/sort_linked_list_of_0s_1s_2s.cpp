#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class SortListOf012 {
public:
    // =========================================================================
    // 1. In-Place Pointer Rewiring via Three Dummy Heads
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    ListNode* sortListPointers(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode zeroDummy(0), oneDummy(0), twoDummy(0);
        ListNode* zero = &zeroDummy;
        ListNode* one = &oneDummy;
        ListNode* two = &twoDummy;

        ListNode* curr = head;
        while (curr != nullptr) {
            if (curr->val == 0) {
                zero->next = curr;
                zero = zero->next;
            } else if (curr->val == 1) {
                one->next = curr;
                one = one->next;
            } else {
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }

        // Connect the three chains
        zero->next = (oneDummy.next) ? oneDummy.next : twoDummy.next;
        one->next = twoDummy.next;
        two->next = nullptr; // Terminate list

        return zeroDummy.next ? zeroDummy.next : (oneDummy.next ? oneDummy.next : twoDummy.next);
    }

    // =========================================================================
    // 2. Value Replacement via Frequency Counting
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    ListNode* sortListCounting(ListNode* head) {
        int count[3] = {0, 0, 0};
        ListNode* curr = head;
        while (curr) {
            count[curr->val]++;
            curr = curr->next;
        }

        curr = head;
        int idx = 0;
        while (curr) {
            while (count[idx] == 0) idx++;
            curr->val = idx;
            count[idx]--;
            curr = curr->next;
        }
        return head;
    }
};

void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        cout << curr->val << (curr->next ? " -> " : " -> nullptr\n");
        curr = curr->next;
    }
}

int main() {
    SortListOf012 solver;

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next = new ListNode(0);

    cout << "Original List: ";
    printList(head);

    head = solver.sortListPointers(head);
    cout << "Sorted by Pointers: ";
    printList(head);

    while (head) {
        ListNode* tmp = head->next;
        delete head;
        head = tmp;
    }
    return 0;
}

