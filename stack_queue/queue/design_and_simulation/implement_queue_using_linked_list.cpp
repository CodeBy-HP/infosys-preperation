#include <iostream>

using namespace std;

class LinkedListQueue {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int count;

public:
    LinkedListQueue() : head(nullptr), tail(nullptr), count(0) {}

    ~LinkedListQueue() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        Node* temp = head;
        int val = temp->data;
        head = head->next;
        if (!head) {
            tail = nullptr;
        }
        delete temp;
        count--;
        return val;
    }

    int front() const {
        if (isEmpty()) return -1;
        return head->data;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    int size() const {
        return count;
    }
};

int main() {
    LinkedListQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.front() << " (Expected: 10)\n";
    cout << "Dequeue: " << q.dequeue() << " (Expected: 10)\n";
    cout << "Front: " << q.front() << " (Expected: 20)\n";
    cout << "Size: " << q.size() << " (Expected: 2)\n";

    return 0;
}

