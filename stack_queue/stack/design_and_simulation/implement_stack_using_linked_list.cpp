#include <iostream>
#include <memory>

using namespace std;

// =============================================================================
// 1. Raw Pointer Linked List Stack (Classic C++ Style)
// =============================================================================
class LinkedListStack {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head;
    int count;

public:
    LinkedListStack() : head(nullptr), count(0) {}

    ~LinkedListStack() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        count++;
    }

    int pop() {
        if (isEmpty()) return -1;
        Node* temp = head;
        int val = temp->data;
        head = head->next;
        delete temp;
        count--;
        return val;
    }

    int top() const {
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

// =============================================================================
// 2. Modern C++ Smart Pointer (std::unique_ptr) Stack (Memory-Safe)
// =============================================================================
class SafeLinkedListStack {
private:
    struct SafeNode {
        int data;
        unique_ptr<SafeNode> next;
        SafeNode(int val, unique_ptr<SafeNode> nxt = nullptr)
            : data(val), next(move(nxt)) {}
    };

    unique_ptr<SafeNode> head;
    int count;

public:
    SafeLinkedListStack() : head(nullptr), count(0) {}

    void push(int x) {
        head = make_unique<SafeNode>(x, move(head));
        count++;
    }

    int pop() {
        if (isEmpty()) return -1;
        int val = head->data;
        head = move(head->next);
        count--;
        return val;
    }

    int top() const {
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
    cout << "=== Raw Pointer Linked List Stack ===\n";
    LinkedListStack st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Top: " << st.top() << " (Expected: 30)\n";
    cout << "Pop: " << st.pop() << " (Expected: 30)\n";
    cout << "Size: " << st.size() << " (Expected: 2)\n";

    cout << "\n=== Safe Smart Pointer Stack ===\n";
    SafeLinkedListStack safeSt;
    safeSt.push(100);
    safeSt.push(200);
    cout << "Safe Top: " << safeSt.top() << " (Expected: 200)\n";
    cout << "Safe Pop: " << safeSt.pop() << " (Expected: 200)\n";
    cout << "Safe Size: " << safeSt.size() << " (Expected: 1)\n";

    return 0;
}

