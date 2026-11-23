#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node(int x) : val(x), prev(nullptr), next(nullptr) {}
    Node(int x, Node* p, Node* n) : val(x), prev(p), next(n) {}
};

class DoublyLinkedListInsertion {
public:
    Node* insertBeforeHead(Node* head, int val) {
        Node* newHead = new Node(val, nullptr, head);
        if (head) head->prev = newHead;
        return newHead;
    }

    Node* insertBeforeTail(Node* head, int val) {
        if (!head) return new Node(val);
        if (!head->next) {
            Node* newHead = new Node(val, nullptr, head);
            head->prev = newHead;
            return newHead;
        }

        Node* tail = head;
        while (tail->next) {
            tail = tail->next;
        }

        Node* back = tail->prev;
        Node* newNode = new Node(val, back, tail);
        back->next = newNode;
        tail->prev = newNode;
        return head;
    }

    Node* insertBeforeKth(Node* head, int val, int k) {
        if (k <= 0) return head;
        if (k == 1) return insertBeforeHead(head, val);

        Node* curr = head;
        int count = 1;
        while (curr && count < k) {
            curr = curr->next;
            count++;
        }
        if (!curr) return head;

        Node* back = curr->prev;
        Node* newNode = new Node(val, back, curr);
        back->next = newNode;
        curr->prev = newNode;
        return head;
    }

    void insertBeforeGivenNode(Node* node, int val) {
        if (!node) return;
        Node* back = node->prev;
        Node* newNode = new Node(val, back, node);
        if (back) back->next = newNode;
        node->prev = newNode;
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
    DoublyLinkedListInsertion solver;

    Node* head = nullptr;
    head = solver.insertBeforeHead(head, 30);
    head = solver.insertBeforeHead(head, 10);
    head = solver.insertBeforeTail(head, 20); // [10, 20, 30]

    cout << "Constructed DLL: ";
    printDLL(head);

    head = solver.insertBeforeKth(head, 5, 1);
    cout << "Insert 5 before k=1: ";
    printDLL(head);

    while (head) {
        Node* tmp = head->next;
        delete head;
        head = tmp;
    }
    return 0;
}

