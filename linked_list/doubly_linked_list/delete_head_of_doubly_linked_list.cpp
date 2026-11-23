#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node(int x) : val(x), prev(nullptr), next(nullptr) {}
};

class DeleteHeadOfDLL {
public:
    Node* deleteHead(Node* head) {
        if (!head) return nullptr;
        if (!head->next) {
            delete head;
            return nullptr;
        }

        Node* prevHead = head;
        head = head->next;
        head->prev = nullptr;
        delete prevHead;

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
    DeleteHeadOfDLL solver;

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    cout << "Original DLL: ";
    printDLL(head);

    head = solver.deleteHead(head);
    cout << "After deleteHead: ";
    printDLL(head);

    while (head) {
        Node* tmp = head->next;
        delete head;
        head = tmp;
    }
    return 0;
}

