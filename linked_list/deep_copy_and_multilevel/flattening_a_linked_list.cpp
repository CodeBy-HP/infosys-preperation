#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* bottom;
    Node(int x) : data(x), next(nullptr), bottom(nullptr) {}
};

class FlatteningLinkedList {
private:
    // Helper to merge two sorted vertical lists using 'bottom' pointer
    Node* merge(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;

        Node* result = nullptr;
        if (a->data <= b->data) {
            result = a;
            result->bottom = merge(a->bottom, b);
        } else {
            result = b;
            result->bottom = merge(a, b->bottom);
        }
        result->next = nullptr; // Clear horizontal pointer
        return result;
    }

public:
    // =========================================================================
    // 1. Recursive Two-Way Merge (Divide & Conquer)
    // Time Complexity: O(Total Nodes)
    // Space Complexity: O(N) recursion stack
    // =========================================================================
    Node* flatten(Node* root) {
        if (!root || !root->next) return root;

        // Recurse for the list on the right
        root->next = flatten(root->next);

        // Merge current list with the right flattened list
        root = merge(root, root->next);

        return root;
    }

    // =========================================================================
    // 2. Min-Heap Multi-Way Merge
    // Time Complexity: O(Total Nodes * log K)
    // Space Complexity: O(K) for priority queue
    // =========================================================================
    struct Compare {
        bool operator()(Node* a, Node* b) {
            return a->data > b->data;
        }
    };

    Node* flattenHeap(Node* root) {
        if (!root) return nullptr;

        priority_queue<Node*, vector<Node*>, Compare> pq;
        Node* curr = root;
        while (curr) {
            pq.push(curr);
            curr = curr->next;
        }

        Node dummy(0);
        Node* tail = &dummy;

        while (!pq.empty()) {
            Node* topNode = pq.top();
            pq.pop();

            tail->bottom = topNode;
            tail = tail->bottom;
            tail->next = nullptr;

            if (topNode->bottom) {
                pq.push(topNode->bottom);
            }
        }

        return dummy.bottom;
    }
};

void printFlattened(Node* root) {
    Node* curr = root;
    while (curr) {
        cout << curr->data << (curr->bottom ? " -> " : " -> nullptr\n");
        curr = curr->bottom;
    }
}

int main() {
    FlatteningLinkedList solver;

    /*
      5 -> 10 -> 19
      |    |     |
      7    20    22
      |          |
      8          50
    */
    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    cout << "Flattening multi-level sorted list:\n";
    Node* flatHead = solver.flatten(head);
    printFlattened(flatHead);

    while (flatHead) {
        Node* tmp = flatHead->bottom;
        delete flatHead;
        flatHead = tmp;
    }

    return 0;
}

