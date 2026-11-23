#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node(int x) : val(x), prev(nullptr), next(nullptr) {}
};

class DeleteAllOccurrencesOfKeyDLL {
public:
    // =========================================================================
    // 1. In-Place Single-Pass Deletion
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    Node* deleteAllOccurrences(Node* head, int key) {
        Node* curr = head;

        while (curr != nullptr) {
            if (curr->val == key) {
                // If deleting head
                if (curr == head) {
                    head = head->next;
                }

                Node* nextNode = curr->next;
                Node* prevNode = curr->prev;

                if (nextNode) nextNode->prev = prevNode;
                if (prevNode) prevNode->next = nextNode;

                delete curr;
                curr = nextNode;
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};

void printDLL(Node* head) {
    if (!head) { cout << "[]\n"; return; }
    Node* curr = head;
    while (curr) {
        cout << curr->val << (curr->next ? " <-> " : " -> nullptr\n");
        curr = curr->next;
    }
}

int main() {
    DeleteAllOccurrencesOfKeyDLL solver;

    Node* head = new Node(2);
    head->next = new Node(2); head->next->prev = head;
    head->next->next = new Node(10); head->next->next->prev = head->next;
    head->next->next->next = new Node(8); head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(2); head->next->next->next->next->prev = head->next->next->next;

    cout << "Original DLL: ";
    printDLL(head);

    head = solver.deleteAllOccurrences(head, 2);
    cout << "After deleting all 2s: ";
    printDLL(head);

    while (head) {
        Node* tmp = head->next;
        delete head;
        head = tmp;
    }
    return 0;
}

