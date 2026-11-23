#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node(int x) : val(x), prev(nullptr), next(nullptr) {}
    Node(int x, Node* p, Node* n) : val(x), prev(p), next(n) {}
};

class IntroToDoublyLinkedList {
public:
    Node* constructDLL(const vector<int>& arr) {
        if (arr.empty()) return nullptr;

        Node* head = new Node(arr[0]);
        Node* prevNode = head;

        for (size_t i = 1; i < arr.size(); i++) {
            Node* newNode = new Node(arr[i], prevNode, nullptr);
            prevNode->next = newNode;
            prevNode = newNode;
        }

        return head;
    }
};

void printDLLForward(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->val << (curr->next ? " <-> " : " -> nullptr\n");
        curr = curr->next;
    }
}

int main() {
    IntroToDoublyLinkedList solver;
    vector<int> arr = {1, 2, 3, 4};
    Node* head = solver.constructDLL(arr);

    cout << "Doubly Linked List: ";
    printDLLForward(head);

    while (head) {
        Node* tmp = head->next;
        delete head;
        head = tmp;
    }
    return 0;
}

