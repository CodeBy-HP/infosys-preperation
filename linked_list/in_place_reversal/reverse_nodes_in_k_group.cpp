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
        if (!head || k == 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        while (true) {
            // 1. Check if at least k nodes remain ahead of prev
            ListNode* check = prev;
            for (int i = 0; i < k; ++i) {
                check = check->next;
                if (!check) {
                    ListNode* ans = dummy->next;
                    delete dummy;
                    return ans;
                }
            }

            // 2. Your exact 4-line head-insertion loop (k - 1 times)
            ListNode* curr = prev->next;
            for (int i = 0; i < k - 1; ++i) {
                ListNode* nextNode = curr->next;
                curr->next = nextNode->next;
                nextNode->next = prev->next;
                prev->next = nextNode;
            }

            // 3. Move prev to the tail of this group (which is curr!)
            prev = curr;
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
