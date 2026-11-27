#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* nxt) : val(x), next(nxt) {}
};

class IntroductionToLinkedList {
public:
    // =========================================================================
    // 1. Iterative Construction using Tail Pointer
    // Time Complexity: O(N)
    // Space Complexity: O(1) auxiliary
    // =========================================================================
    ListNode* constructLL(const vector<int>& arr) {
        if (arr.empty()) return nullptr;

        ListNode* head = new ListNode(arr[0]);
        ListNode* mover = head;

        for (size_t i = 1; i < arr.size(); i++) {
            ListNode* temp = new ListNode(arr[i]);
            mover->next = temp;
            mover = temp;
        }

        return head;
    }

    // =========================================================================
    // 2. Construction using Dummy Sentinel Node
    // Time Complexity: O(N)
    // Space Complexity: O(1) auxiliary
    // =========================================================================
    ListNode* constructLLWithDummy(const vector<int>& arr) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        for (int val : arr) {
            curr->next = new ListNode(val);
            curr = curr->next;
        }

        return dummy->next;
    }

    // =========================================================================
    // 3. Recursive Construction
    // Time Complexity: O(N)
    // Space Complexity: O(N) stack frames
    // =========================================================================
    ListNode* constructLLRecursiveHelper(const vector<int>& arr, size_t index) {
        if (index >= arr.size()) return nullptr;
        ListNode* node = new ListNode(arr[index]);
        node->next = constructLLRecursiveHelper(arr, index + 1);
        return node;
    }

    ListNode* constructLLRecursive(const vector<int>& arr) {
        return constructLLRecursiveHelper(arr, 0);
    }
};

void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        cout << curr->val << (curr->next ? " -> " : " -> nullptr\n");
        curr = curr->next;
    }
}

void deleteList(ListNode* head) {
    while (head) {
        ListNode* nxt = head->next;
        delete head;
        head = nxt;
    }
}

int main() {
    IntroductionToLinkedList solver;

    vector<int> arr1 = {1, 2, 3, 4, 5};
    ListNode* head1 = solver.constructLL(arr1);
    cout << "Test 1 (Tail Pointer): ";
    printList(head1);

    vector<int> arr2 = {10, 20, 30};
    ListNode* head2 = solver.constructLLWithDummy(arr2);
    cout << "Test 2 (Dummy Head):   ";
    printList(head2);

    vector<int> arr3 = {7};
    ListNode* head3 = solver.constructLLRecursive(arr3);
    cout << "Test 3 (Recursive):    ";
    printList(head3);

    deleteList(head1);
    deleteList(head2);
    deleteList(head3);

    return 0;
}

