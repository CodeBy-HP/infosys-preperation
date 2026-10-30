#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a Node with random pointer.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class CopyListWithRandomPointer {
public:
    // =========================================================================
    // 1. Optimal 3-Pass Weaving Technique (O(1) Auxiliary Space)
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Pass 1: Clone each node and interleave it: A -> A' -> B -> B'
        Node* curr = head;
        while (curr) {
            Node* clone = new Node(curr->val);
            clone->next = curr->next;
            curr->next = clone;
            curr = clone->next;
        }

        // Pass 2: Assign random pointers for the cloned nodes
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Pass 3: Unweave and separate the lists
        Node* dummy = new Node(0);
        Node* cloneTail = dummy;
        curr = head;

        while (curr) {
            Node* clone = curr->next;
            curr->next = clone->next; // Restore original list link

            cloneTail->next = clone;  // Append to cloned list
            cloneTail = clone;

            curr = curr->next;
        }

        Node* clonedHead = dummy->next;
        delete dummy;
        return clonedHead;
    }

    // =========================================================================
    // 2. Hash Map Approach
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    // =========================================================================
    Node* copyRandomListHashMap(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> origToClone;
        Node* curr = head;
        while (curr) {
            origToClone[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while (curr) {
            origToClone[curr]->next = origToClone[curr->next];
            origToClone[curr]->random = origToClone[curr->random];
            curr = curr->next;
        }

        return origToClone[head];
    }
};

void printListWithRandom(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << "[" << curr->val << ", rnd: ";
        if (curr->random) cout << curr->random->val;
        else cout << "null";
        cout << "]";
        if (curr->next) cout << " -> ";
        curr = curr->next;
    }
    cout << "\n";
}

void freeRandomList(Node* head) {
    while (head) {
        Node* nxt = head->next;
        delete head;
        head = nxt;
    }
}

int main() {
    CopyListWithRandomPointer solver;

    // Build: 7 -> 13 -> 11 with randoms:
    // 7->random = null, 13->random = 7, 11->random = 13
    Node* n1 = new Node(7);
    Node* n2 = new Node(13);
    Node* n3 = new Node(11);

    n1->next = n2;
    n2->next = n3;

    n1->random = nullptr;
    n2->random = n1;
    n3->random = n2;

    cout << "Original List: ";
    printListWithRandom(n1);

    Node* copied = solver.copyRandomList(n1);
    cout << "Copied List:   ";
    printListWithRandom(copied);

    // Verify deep copy (modifying original clone doesn't affect copy)
    n1->val = 999;
    cout << "After modifying original val to 999:\n";
    cout << "  Original:    ";
    printListWithRandom(n1);
    cout << "  Deep Copy:   ";
    printListWithRandom(copied);

    freeRandomList(n1);
    freeRandomList(copied);
    return 0;
}
