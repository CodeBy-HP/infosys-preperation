#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node(int x) : val(x), prev(nullptr), next(nullptr) {}
};

class DeleteKthElementOfDLL {
public:
    Node* deleteKth(Node* head, int k) {
        if (!head || k <= 0) return head;

        Node* curr = head;
        int count = 1;
        while (curr != nullptr && count < k) {
            curr = curr->next;
            count++;
        }

        if (!curr) return head; // k out of range

        Node* back = curr->prev;
        Node* front = curr->next;

        if (!back && !front) {
            // Only node in list
            delete curr;
            return nullptr;
        } else if (!back) {
            // Deleting head node
            head = front;
            head->prev = nullptr;
            delete curr;
            return head;
        } else if (!front) {
            // Deleting tail node
            back->next = nullptr;
            delete curr;
            return head;
        } else {
            // Deleting internal node
            back->next = front;
            front->prev = back;
            delete curr;
            return head;
        }
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
    DeleteKthElementOfDLL solver;

    Node* head = new Node(1);
    head->next = new Node(2); head->next->prev = head;
    head->next->next = new Node(3); head->next->next->prev = head->next;
    head->next->next->next = new Node(4); head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5); head->next->next->next->next->prev = head->next->next->next;

    cout << "Original: ";
    printDLL(head);

    head = solver.deleteKth(head, 3);
    cout << "After deleteKth(3): ";
    printDLL(head);

    head = solver.deleteKth(head, 1);
    cout << "After deleteKth(1): ";
    printDLL(head);

    while (head) {
        Node* tmp = head->next;
        delete head;
        head = tmp;
    }
    return 0;
}

