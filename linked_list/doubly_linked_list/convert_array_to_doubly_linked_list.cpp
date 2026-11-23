#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node(int x) : val(x), prev(nullptr), next(nullptr) {}
};

class ConvertArrayToDLL {
public:
    Node* arrayToDLL(const vector<int>& arr) {
        if (arr.empty()) return nullptr;

        Node* head = new Node(arr[0]);
        Node* curr = head;

        for (size_t i = 1; i < arr.size(); i++) {
            Node* temp = new Node(arr[i]);
            curr->next = temp;
            temp->prev = curr;
            curr = temp;
        }

        return head;
    }
};

void printDLL(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->val << (curr->next ? " <-> " : " -> nullptr\n");
        curr = curr->next;
    }
}

int main() {
    ConvertArrayToDLL solver;
    vector<int> arr = {3, 5, 8, 10};
    Node* head = solver.arrayToDLL(arr);

    cout << "Converted DLL: ";
    printDLL(head);

    while (head) {
        Node* tmp = head->next;
        delete head;
        head = tmp;
    }
    return 0;
}

