#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct CompareNode {
    bool operator()(const ListNode* a, const ListNode* b) const {
        return a->val > b->val; // Min-heap
    }
};

class MergeKSortedLists {
public:
    static ListNode* mergeKLists(const std::vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, CompareNode> minHeap;

        for (auto head : lists) {
            if (head != nullptr) {
                minHeap.push(head);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!minHeap.empty()) {
            ListNode* curr = minHeap.top();
            minHeap.pop();

            tail->next = curr;
            tail = tail->next;

            if (curr->next != nullptr) {
                minHeap.push(curr->next);
            }
        }
        return dummy.next;
    }
};

int main() {
    // List 1: 1 -> 4 -> 5
    ListNode* l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    // List 2: 1 -> 3 -> 4
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    // List 3: 2 -> 6
    ListNode* l3 = new ListNode(2, new ListNode(6));

    std::vector<ListNode*> lists = {l1, l2, l3};
    ListNode* merged = MergeKSortedLists::mergeKLists(lists);

    std::vector<int> result;
    while (merged) {
        result.push_back(merged->val);
        ListNode* temp = merged;
        merged = merged->next;
        delete temp;
    }

    std::vector<int> expected = {1, 1, 2, 3, 4, 4, 5, 6};
    assert(result == expected);

    std::cout << "All Merge K Sorted Lists tests passed successfully!\n";
    return 0;
}

