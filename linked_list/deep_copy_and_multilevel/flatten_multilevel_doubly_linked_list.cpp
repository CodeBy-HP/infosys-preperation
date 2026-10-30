#include <iostream>
#include <vector>

using namespace std;

// Definition for a Multilevel Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) : val(_val), prev(nullptr), next(nullptr), child(nullptr) {}
};

class FlattenMultilevelDoublyLinkedList {
public:
    // =========================================================================
    // 1. Optimal Iterative Splicing
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    Node* flatten(Node* head) {
        Node* curr = head;

        while (curr != nullptr) {
            // If curr has a child, splice the child chain in-line
            if (curr->child != nullptr) {
                Node* nextNode = curr->next;
                Node* childHead = curr->child;

                // Find the tail of the child chain
                Node* childTail = childHead;
                while (childTail->next != nullptr) {
                    childTail = childTail->next;
                }

                // Connect curr to childHead
                curr->next = childHead;
                childHead->prev = curr;

                // Connect childTail to nextNode (if exists)
                childTail->next = nextNode;
                if (nextNode != nullptr) {
                    nextNode->prev = childTail;
                }

                // Nullify child pointer
                curr->child = nullptr;
            }

            curr = curr->next;
        }

        return head;
    }
};

void printDoublyList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->val;
        if (curr->next) cout << " <-> ";
        curr = curr->next;
    }
    cout << "\n";
}

void freeDoublyList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    FlattenMultilevelDoublyLinkedList solver;

    // Construct:
    // 1 <-> 2 <-> 3
    //       |
    //       4 <-> 5
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;

    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    n4->next = n5; n5->prev = n4;

    n2->child = n4;

    cout << "Flattening Multilevel List...\n";
    Node* res = solver.flatten(n1);
    cout << "Result: ";
    printDoublyList(res);

    freeDoublyList(res);
    return 0;
}
