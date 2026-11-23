#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class SinglyLinkedListDeletion {
public:
    ListNode* deleteHead(ListNode* head) {
        if (!head) return nullptr;
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    ListNode* deleteTail(ListNode* head) {
        if (!head || !head->next) {
            delete head;
            return nullptr;
        }
        ListNode* curr = head;
        while (curr->next->next != nullptr) {
            curr = curr->next;
        }
        delete curr->next;
        curr->next = nullptr;
        return head;
    }

    ListNode* deleteKth(ListNode* head, int k) {
        if (!head || k <= 0) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        for (int i = 1; i < k && prev->next != nullptr; i++) {
            prev = prev->next;
        }

        if (prev->next != nullptr) {
            ListNode* target = prev->next;
            prev->next = target->next;
            delete target;
        }
        return dummy.next;
    }

    ListNode* deleteValue(ListNode* head, int x) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* curr = &dummy;

        while (curr->next != nullptr) {
            if (curr->next->val == x) {
                ListNode* target = curr->next;
                curr->next = target->next;
                delete target;
                break;
            }
            curr = curr->next;
        }
        return dummy.next;
    }
};

void printList(ListNode* head) {
    if (!head) { cout << "[]\n"; return; }
    ListNode* curr = head;
    while (curr) {
        cout << curr->val << (curr->next ? " -> " : " -> nullptr\n");
        curr = curr->next;
    }
}

int main() {
    SinglyLinkedListDeletion solver;

    ListNode* head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);

    cout << "Original: ";
    printList(head);

    head = solver.deleteHead(head); // deletes 10
    cout << "After deleteHead: ";
    printList(head);

    head = solver.deleteTail(head); // deletes 40
    cout << "After deleteTail: ";
    printList(head);

    head = solver.deleteValue(head, 20); // deletes 20
    cout << "After deleteValue(20): ";
    printList(head);

    head = solver.deleteKth(head, 1); // deletes 30
    cout << "After deleteKth(1): ";
    printList(head);

    return 0;
}

