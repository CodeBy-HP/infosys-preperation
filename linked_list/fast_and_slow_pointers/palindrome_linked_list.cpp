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

class PalindromeLinkedList {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

public:
    // =========================================================================
    // 1. Optimal In-Place Reversal with List Restoration
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // Step 1: Find middle using fast and slow pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* secondHalfStart = reverseList(slow->next);

        // Step 3: Compare halves
        ListNode* p1 = head;
        ListNode* p2 = secondHalfStart;
        bool palindrome = true;
        while (palindrome && p2 != nullptr) {
            if (p1->val != p2->val) {
                palindrome = false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        // Step 4: Restore original list structure
        slow->next = reverseList(secondHalfStart);

        return palindrome;
    }

    // =========================================================================
    // 2. Vector Copy Approach
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    // =========================================================================
    bool isPalindromeVector(ListNode* head) {
        vector<int> vals;
        ListNode* curr = head;
        while (curr != nullptr) {
            vals.push_back(curr->val);
            curr = curr->next;
        }

        int left = 0, right = (int)vals.size() - 1;
        while (left < right) {
            if (vals[left++] != vals[right--]) return false;
        }
        return true;
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

void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    PalindromeLinkedList solver;

    // Test 1: Even length palindrome [1, 2, 2, 1] -> true
    ListNode* l1 = buildList({1, 2, 2, 1});
    cout << "Test 1 [1, 2, 2, 1]: " << (solver.isPalindrome(l1) ? "Palindrome" : "Not Palindrome") << " (Expected: Palindrome)\n";
    freeList(l1);

    // Test 2: Odd length palindrome [1, 2, 3, 2, 1] -> true
    ListNode* l2 = buildList({1, 2, 3, 2, 1});
    cout << "Test 2 [1, 2, 3, 2, 1]: " << (solver.isPalindrome(l2) ? "Palindrome" : "Not Palindrome") << " (Expected: Palindrome)\n";
    freeList(l2);

    // Test 3: Not palindrome [1, 2, 3, 4] -> false
    ListNode* l3 = buildList({1, 2, 3, 4});
    cout << "Test 3 [1, 2, 3, 4]: " << (solver.isPalindrome(l3) ? "Palindrome" : "Not Palindrome") << " (Expected: Not Palindrome)\n";
    freeList(l3);

    return 0;
}
