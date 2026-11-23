#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node(int x) : val(x), prev(nullptr), next(nullptr) {}
};

class DeleteTailOfDLL {
public:
    Node* deleteTail(Node* head) {
        if (!head || !head->next) {
            delete head;
            return nullptr;
        }

        Node* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }

        Node* newTail = tail->prev;
        newTail->next = nullptr;
        delete tail;

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
    DeleteTailOfDLL solver;

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    cout << "Original DLL: ";
    printDLL(head);

    head = solver.deleteTail(head);
    cout << "After deleteTail: ";
    printDLL(head);

    while (head) {
        Node* tmp = head->next;
        delete head;
        head = tmp;
    }
    return 0;
}

