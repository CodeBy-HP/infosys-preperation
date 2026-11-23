#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node(int x) : val(x), prev(nullptr), next(nullptr) {}
};

class InsertBeforeHeadDLL {
public:
    Node* insertBeforeHead(Node* head, int val) {
        Node* newHead = new Node(val);
        if (!head) return newHead;

        newHead->next = head;
        head->prev = newHead;

        return newHead;
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
    InsertBeforeHeadDLL solver;

    Node* head = new Node(2);
    head->next = new Node(3); head->next->prev = head;

    cout << "Original: ";
    printDLL(head);

    head = solver.insertBeforeHead(head, 1);
    cout << "After inserting 1 before head: ";
    printDLL(head);

    while (head) {
        Node* tmp = head->next;
        delete head;
        head = tmp;
    }
    return 0;
}

