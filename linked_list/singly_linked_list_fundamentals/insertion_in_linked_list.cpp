#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class SinglyLinkedListInsertion {
public:
    ListNode* insertHead(ListNode* head, int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        return newNode;
    }

    ListNode* insertTail(ListNode* head, int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) return newNode;
        ListNode* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
        return head;
    }

    ListNode* insertKth(ListNode* head, int val, int k) {
        if (k <= 0) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* curr = &dummy;

        for (int i = 1; i < k && curr != nullptr; i++) {
            curr = curr->next;
        }

        if (curr != nullptr) {
            ListNode* newNode = new ListNode(val);
            newNode->next = curr->next;
            curr->next = newNode;
        }
        return dummy.next;
    }

    ListNode* insertBeforeValue(ListNode* head, int val, int x) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* curr = &dummy;

        while (curr->next != nullptr) {
            if (curr->next->val == x) {
                ListNode* newNode = new ListNode(val);
                newNode->next = curr->next;
                curr->next = newNode;
                break;
            }
            curr = curr->next;
        }
        return dummy.next;
    }
};

void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        cout << curr->val << (curr->next ? " -> " : " -> nullptr\n");
        curr = curr->next;
    }
}

int main() {
    SinglyLinkedListInsertion solver;

    ListNode* head = nullptr;
    head = solver.insertHead(head, 20); // [20]
    head = solver.insertHead(head, 10); // [10, 20]
    head = solver.insertTail(head, 40); // [10, 20, 40]
    head = solver.insertKth(head, 30, 3); // [10, 20, 30, 40]
    head = solver.insertBeforeValue(head, 5, 10); // [5, 10, 20, 30, 40]

    cout << "Final Linked List: ";
    printList(head);

    while (head) {
        ListNode* tmp = head->next;
        delete head;
        head = tmp;
    }

    return 0;
}

