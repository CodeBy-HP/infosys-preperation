#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

// =============================================================================
// 1. Custom Doubly-Linked List + Hash Map (Standard Production Implementation)
// Time Complexity: O(1) for both get() and put()
// Space Complexity: O(capacity)
// =============================================================================
class LRUCacheCustomDLL {
private:
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> nodeMap;
    Node* head;
    Node* tail;

    void addAfterHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(Node* node) {
        removeNode(node);
        addAfterHead(node);
    }

    Node* popTail() {
        Node* lru = tail->prev;
        removeNode(lru);
        return lru;
    }

public:
    LRUCacheCustomDLL(int cap) : capacity(cap) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCacheCustomDLL() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* nxt = curr->next;
            delete curr;
            curr = nxt;
        }
    }

    int get(int key) {
        auto it = nodeMap.find(key);
        if (it == nodeMap.end()) return -1;
        moveToHead(it->second);
        return it->second->val;
    }

    void put(int key, int value) {
        auto it = nodeMap.find(key);
        if (it != nodeMap.end()) {
            it->second->val = value;
            moveToHead(it->second);
        } else {
            if (static_cast<int>(nodeMap.size()) >= capacity) {
                Node* lru = popTail();
                nodeMap.erase(lru->key);
                delete lru;
            }
            Node* newNode = new Node(key, value);
            nodeMap[key] = newNode;
            addAfterHead(newNode);
        }
    }
};

// =============================================================================
// 2. STL std::list + std::unordered_map implementation
// Time Complexity: O(1) for get() and put()
// Space Complexity: O(capacity)
// =============================================================================
class LRUCacheSTL {
private:
    int capacity;
    // List of pairs: {key, value}, front is most recent, back is least recent
    list<pair<int, int>> dll;
    unordered_map<int, list<pair<int, int>>::iterator> cache;

public:
    LRUCacheSTL(int cap) : capacity(cap) {}

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;

        // Splice accessed element to the front of the list
        dll.splice(dll.begin(), dll, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            it->second->second = value;
            dll.splice(dll.begin(), dll, it->second);
            return;
        }

        if (static_cast<int>(cache.size()) >= capacity) {
            int lruKey = dll.back().first;
            dll.pop_back();
            cache.erase(lruKey);
        }

        dll.push_front({key, value});
        cache[key] = dll.begin();
    }
};

int main() {
    cout << "Testing Custom DLL LRU Cache:\n";
    LRUCacheCustomDLL lru1(2);
    lru1.put(1, 1);
    lru1.put(2, 2);
    cout << "get(1): " << lru1.get(1) << " (Expected: 1)\n";
    lru1.put(3, 3); // evicts key 2
    cout << "get(2): " << lru1.get(2) << " (Expected: -1)\n";
    lru1.put(4, 4); // evicts key 1
    cout << "get(1): " << lru1.get(1) << " (Expected: -1)\n";
    cout << "get(3): " << lru1.get(3) << " (Expected: 3)\n";
    cout << "get(4): " << lru1.get(4) << " (Expected: 4)\n\n";

    cout << "Testing STL LRU Cache:\n";
    LRUCacheSTL lru2(2);
    lru2.put(1, 1);
    lru2.put(2, 2);
    cout << "get(1): " << lru2.get(1) << " (Expected: 1)\n";
    lru2.put(3, 3); // evicts key 2
    cout << "get(2): " << lru2.get(2) << " (Expected: -1)\n";

    return 0;
}

