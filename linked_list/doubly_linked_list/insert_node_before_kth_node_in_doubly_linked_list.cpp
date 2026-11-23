#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node(int x) : val(x), prev(nullptr), next(nullptr) {}
    Node(int x, Node* p, Node* n) : val(x), prev(p), next(n) {}
};

class InsertBeforeKthNodeDLL {
public:
    Node* insertBeforeKth(Node* head, int val, int k) {
        if (k <= 0) return head;

        if (k == 1) {
            Node* newHead = new Node(val, nullptr, head);
            if (head) head->prev = newHead;
            return newHead;
        }

        Node* curr = head;
        int count = 1;
        while (curr != nullptr && count < k) {
            curr = curr->next;
            count++;
        }

        if (!curr) return head; // k > N

        Node* back = curr->prev;
        Node* newNode = new Node(val, back, curr);
        back->next = newNode;
        curr->prev = newNode;

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
    InsertBeforeKthNodeDLL solver;

    Node* head = new Node(1);
    head->next = new Node(2); head->next->prev = head;
    head->next->next = new Node(4); head->next->next->prev = head->next;
    head->next->next->next = new Node(5); head->next->next->next->prev = head->next->next;

    cout << "Original: ";
    printDLL(head);

    head = solver.insertBeforeKth(head, 3, 3);
    cout << "Insert 3 before k=3: ";
    printDLL(head);

    head = solver.insertBeforeKth(head, 0, 1);
    cout << "Insert 0 before k=1: ";
    printDLL(head);

    while (head) {
        Node* tmp = head->next;
        delete head;
        head = tmp;
    }
    return 0;
}

