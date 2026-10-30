#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MergeKSortedLists {
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }

public:
    // =========================================================================
    // 1. Divide and Conquer Approach
    // Time Complexity: O(N log k) where N is total nodes, k is number of lists
    // Space Complexity: O(1) auxiliary space (in-place merges)
    // =========================================================================
    ListNode* mergeKListsDivideAndConquer(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        int interval = 1;
        int n = lists.size();

        while (interval < n) {
            for (int i = 0; i + interval < n; i += interval * 2) {
                lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }

        return lists[0];
    }

    // =========================================================================
    // 2. Min-Heap (Priority Queue) Approach
    // Time Complexity: O(N log k)
    // Space Complexity: O(k) for heap
    // =========================================================================
    struct CompareNode {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKListsPriorityQueue(const vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareNode> minHeap;

        for (ListNode* head : lists) {
            if (head) minHeap.push(head);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next) {
                minHeap.push(smallest->next);
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
    MergeKSortedLists solver;

    // Test 1: [[1,4,5], [1,3,4], [2,6]] -> [1,1,2,3,4,4,5,6]
    vector<ListNode*> lists1 = {
        buildList({1, 4, 5}),
        buildList({1, 3, 4}),
        buildList({2, 6})
    };

    ListNode* res1 = solver.mergeKListsDivideAndConquer(lists1);
    cout << "Merged via Divide & Conquer: ";
    printList(res1);
    freeList(res1);

    // Test 2: Min-Heap verification
    vector<ListNode*> lists2 = {
        buildList({2, 8}),
        buildList({1, 5, 9}),
        buildList({3, 7})
    };
    ListNode* res2 = solver.mergeKListsPriorityQueue(lists2);
    cout << "Merged via Min-Heap:         ";
    printList(res2);
    freeList(res2);

    return 0;
}
