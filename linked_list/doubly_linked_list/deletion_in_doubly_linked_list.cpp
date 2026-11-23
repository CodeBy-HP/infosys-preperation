#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node(int x) : val(x), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedListDeletion {
public:
    Node* deleteHead(Node* head) {
        if (!head) return nullptr;
        if (!head->next) {
            delete head;
            return nullptr;
        }
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
        return head;
    }

    Node* deleteTail(Node* head) {
        if (!head || !head->next) {
            delete head;
            return nullptr;
        }
        Node* tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        Node* newTail = tail->prev;
        newTail->next = nullptr;
        delete tail;
        return head;
    }

    Node* deleteKth(Node* head, int k) {
        if (!head || k <= 0) return head;
        Node* curr = head;
        int count = 1;
        while (curr && count < k) {
            curr = curr->next;
            count++;
        }
        if (!curr) return head;

        Node* back = curr->prev;
        Node* front = curr->next;

        if (!back && !front) {
            delete curr;
            return nullptr;
        } else if (!back) {
            head = front;
            head->prev = nullptr;
            delete curr;
            return head;
        } else if (!front) {
            back->next = nullptr;
            delete curr;
            return head;
        } else {
            back->next = front;
            front->prev = back;
            delete curr;
            return head;
        }
    }

    void deleteGivenNode(Node* node) {
        if (!node) return;
        Node* back = node->prev;
        Node* front = node->next;
        if (back) back->next = front;
        if (front) front->prev = back;
        delete node;
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
    DoublyLinkedListDeletion solver;

    Node* head = new Node(10);
    head->next = new Node(20); head->next->prev = head;
    head->next->next = new Node(30); head->next->next->prev = head->next;
    head->next->next->next = new Node(40); head->next->next->next->prev = head->next->next;

    cout << "Original: ";
    printDLL(head);

    head = solver.deleteHead(head); // deletes 10
    cout << "After deleteHead: ";
    printDLL(head);

    head = solver.deleteTail(head); // deletes 40
    cout << "After deleteTail: ";
    printDLL(head);

    head = solver.deleteKth(head, 2); // deletes 30
    cout << "After deleteKth(2): ";
    printDLL(head);

    while (head) {
        Node* tmp = head->next;
        delete head;
        head = tmp;
    }
    return 0;
}

