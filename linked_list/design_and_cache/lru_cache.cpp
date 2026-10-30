#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    void addNode(Node* node) {
        // Always insert right after pseudo head
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        // Unlink node from doubly linked list
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }

    Node* popTail() {
        Node* lru = tail->prev;
        removeNode(lru);
        return lru;
    }

public:
    LRUCache(int cap) : capacity(cap) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        Node* curr = head;
        while (curr) {
            Node* nxt = curr->next;
            delete curr;
            curr = nxt;
        }
    }

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;

        Node* node = it->second;
        moveToHead(node); // Accessed -> mark most recent
        return node->value;
    }

    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            Node* node = it->second;
            node->value = value;
            moveToHead(node);
        } else {
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addNode(newNode);

            if ((int)cache.size() > capacity) {
                Node* evicted = popTail();
                cache.erase(evicted->key);
                delete evicted;
            }
        }
    }
};

int main() {
    LRUCache lru(2);

    lru.put(1, 1);
    lru.put(2, 2);
    cout << "get(1): " << lru.get(1) << " (Expected: 1)\n";

    lru.put(3, 3); // Evicts key 2
    cout << "get(2): " << lru.get(2) << " (Expected: -1, evicted)\n";

    lru.put(4, 4); // Evicts key 1
    cout << "get(1): " << lru.get(1) << " (Expected: -1, evicted)\n";
    cout << "get(3): " << lru.get(3) << " (Expected: 3)\n";
    cout << "get(4): " << lru.get(4) << " (Expected: 4)\n";

    return 0;
}
