#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

// =============================================================================
// 1. Production LFU Cache using STL lists and Iterators
// Time Complexity: O(1) for both get() and put()
// Space Complexity: O(capacity)
// =============================================================================
class LFUCacheSTL {
private:
    struct CacheNode {
        int key;
        int value;
        int freq;
        CacheNode(int k, int v, int f) : key(k), value(v), freq(f) {}
    };

    int capacity;
    int minFreq;
    // Map key -> iterator in the corresponding freq list
    unordered_map<int, list<CacheNode>::iterator> keyMap;
    // Map freq -> list of CacheNodes (front is most recently used, back is least recently used)
    unordered_map<int, list<CacheNode>> freqMap;

    void updateFrequency(int key) {
        auto it = keyMap[key];
        int val = it->value;
        int freq = it->freq;

        // Remove from old frequency list
        freqMap[freq].erase(it);
        if (freqMap[freq].empty()) {
            freqMap.erase(freq);
            if (minFreq == freq) {
                minFreq++;
            }
        }

        // Add to freq + 1 list
        freqMap[freq + 1].push_front(CacheNode(key, val, freq + 1));
        keyMap[key] = freqMap[freq + 1].begin();
    }

public:
    LFUCacheSTL(int cap) : capacity(cap), minFreq(0) {}

    int get(int key) {
        if (capacity <= 0) return -1;
        auto it = keyMap.find(key);
        if (it == keyMap.end()) return -1;

        int val = it->second->value;
        updateFrequency(key);
        return val;
    }

    void put(int key, int value) {
        if (capacity <= 0) return;

        auto it = keyMap.find(key);
        if (it != keyMap.end()) {
            it->second->value = value;
            updateFrequency(key);
            return;
        }

        // Evict LFU element if at capacity
        if (static_cast<int>(keyMap.size()) >= capacity) {
            // Find the least recently used element among minFreq list
            auto& minList = freqMap[minFreq];
            int lfuKey = minList.back().key;
            minList.pop_back();
            if (minList.empty()) {
                freqMap.erase(minFreq);
            }
            keyMap.erase(lfuKey);
        }

        // Insert new element with freq = 1
        minFreq = 1;
        freqMap[1].push_front(CacheNode(key, value, 1));
        keyMap[key] = freqMap[1].begin();
    }
};

// =============================================================================
// 2. Custom Doubly Linked List LFU Cache (Zero dynamic STL overhead)
// Time Complexity: O(1) for get() and put()
// Space Complexity: O(capacity)
// =============================================================================
class LFUCacheCustom {
private:
    struct Node {
        int key;
        int value;
        int freq;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), freq(1), prev(nullptr), next(nullptr) {}
    };

    struct DLinkedList {
        Node* head;
        Node* tail;
        int size;

        DLinkedList() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        ~DLinkedList() {
            Node* curr = head;
            while (curr) {
                Node* nxt = curr->next;
                delete curr;
                curr = nxt;
            }
        }

        void addFront(Node* node) {
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
            size++;
        }

        void removeNode(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            size--;
        }

        Node* removeTail() {
            if (size == 0) return nullptr;
            Node* lru = tail->prev;
            removeNode(lru);
            return lru;
        }

        bool empty() const {
            return size == 0;
        }
    };

    int capacity;
    int minFreq;
    unordered_map<int, Node*> keyMap;
    unordered_map<int, DLinkedList*> freqMap;

    void update(Node* node) {
        int f = node->freq;
        freqMap[f]->removeNode(node);
        if (freqMap[f]->empty() && minFreq == f) {
            minFreq++;
        }

        node->freq++;
        if (freqMap.find(node->freq) == freqMap.end()) {
            freqMap[node->freq] = new DLinkedList();
        }
        freqMap[node->freq]->addFront(node);
    }

public:
    LFUCacheCustom(int cap) : capacity(cap), minFreq(0) {}

    ~LFUCacheCustom() {
        for (auto& pair : freqMap) {
            delete pair.second;
        }
    }

    int get(int key) {
        if (capacity <= 0 || keyMap.find(key) == keyMap.end()) return -1;
        Node* node = keyMap[key];
        update(node);
        return node->value;
    }

    void put(int key, int value) {
        if (capacity <= 0) return;

        if (keyMap.find(key) != keyMap.end()) {
            Node* node = keyMap[key];
            node->value = value;
            update(node);
            return;
        }

        if (static_cast<int>(keyMap.size()) >= capacity) {
            Node* toRemove = freqMap[minFreq]->removeTail();
            keyMap.erase(toRemove->key);
            delete toRemove;
        }

        Node* newNode = new Node(key, value);
        minFreq = 1;
        if (freqMap.find(1) == freqMap.end()) {
            freqMap[1] = new DLinkedList();
        }
        freqMap[1]->addFront(newNode);
        keyMap[key] = newNode;
    }
};

int main() {
    cout << "Testing STL LFU Cache:\n";
    LFUCacheSTL lfu1(2);
    lfu1.put(1, 1);
    lfu1.put(2, 2);
    cout << "get(1): " << lfu1.get(1) << " (Expected: 1)\n";
    lfu1.put(3, 3); // evicts 2 (both 1 and 2 had freq 1, but 2 was least recently used)
    cout << "get(2): " << lfu1.get(2) << " (Expected: -1)\n";
    cout << "get(3): " << lfu1.get(3) << " (Expected: 3)\n";
    lfu1.put(4, 4); // evicts 1 (freq 2 for 3 vs freq 2 for 1, 1 least recent)
    cout << "get(1): " << lfu1.get(1) << " (Expected: -1)\n";
    cout << "get(3): " << lfu1.get(3) << " (Expected: 3)\n";
    cout << "get(4): " << lfu1.get(4) << " (Expected: 4)\n\n";

    cout << "Testing Custom DLL LFU Cache:\n";
    LFUCacheCustom lfu2(2);
    lfu2.put(1, 1);
    lfu2.put(2, 2);
    cout << "get(1): " << lfu2.get(1) << " (Expected: 1)\n";
    lfu2.put(3, 3); // evicts 2
    cout << "get(2): " << lfu2.get(2) << " (Expected: -1)\n";
    cout << "get(3): " << lfu2.get(3) << " (Expected: 3)\n";

    return 0;
}

