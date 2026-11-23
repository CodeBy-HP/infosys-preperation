#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node(int x) : val(x), prev(nullptr), next(nullptr) {}
};

class FindPairsWithSumDLL {
public:
    // =========================================================================
    // 1. Two-Pointer Bidirectional Inward Scan (Optimal)
    // Time Complexity: O(N)
    // Space Complexity: O(1) auxiliary
    // =========================================================================
    vector<pair<int, int>> findPairsWithGivenSum(Node* head, int targetSum) {
        vector<pair<int, int>> result;
        if (!head || !head->next) return result;

        Node* left = head;
        Node* right = head;
        while (right->next != nullptr) {
            right = right->next;
        }

        // Loop until pointers meet or cross each other
        while (left != right && right->next != left) {
            int currentSum = left->val + right->val;

            if (currentSum == targetSum) {
                result.push_back({left->val, right->val});
                left = left->next;
                right = right->prev;
            } else if (currentSum < targetSum) {
                left = left->next;
            } else {
                right = right->prev;
            }
        }

        return result;
    }
};

int main() {
    FindPairsWithSumDLL solver;

    Node* head = new Node(1);
    head->next = new Node(2); head->next->prev = head;
    head->next->next = new Node(4); head->next->next->prev = head->next;
    head->next->next->next = new Node(5); head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(6); head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(8); head->next->next->next->next->next->prev = head->next->next->next->next;
    head->next->next->next->next->next->next = new Node(9); head->next->next->next->next->next->next->prev = head->next->next->next->next->next;

    auto pairs = solver.findPairsWithGivenSum(head, 7);
    cout << "Pairs with sum 7:\n";
    for (auto& p : pairs) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << "\n(Expected: (1, 6), (2, 5))\n";

    while (head) {
        Node* tmp = head->next;
        delete head;
        head = tmp;
    }
    return 0;
}

