#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node(int x) : val(x), prev(nullptr), next(nullptr) {}
    Node(int x, Node* p, Node* n) : val(x), prev(p), next(n) {}
};

class InsertBeforeTailDLL {
public:
    Node* insertBeforeTail(Node* head, int val) {
        if (!head) return new Node(val);

        if (!head->next) {
            Node* newHead = new Node(val, nullptr, head);
            head->prev = newHead;
            return newHead;
        }

        Node* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }

        Node* back = tail->prev;
        Node* newNode = new Node(val, back, tail);
        back->next = newNode;
        tail->prev = newNode;

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
    InsertBeforeTailDLL solver;

    Node* head = new Node(1);
    head->next = new Node(2); head->next->prev = head;
    head->next->next = new Node(4); head->next->next->prev = head->next;

    cout << "Original: ";
    printDLL(head);

    head = solver.insertBeforeTail(head, 3);
    cout << "After inserting 3 before tail: ";
    printDLL(head);

    while (head) {
        Node* tmp = head->next;
        delete head;
        head = tmp;
    }
    return 0;
}

