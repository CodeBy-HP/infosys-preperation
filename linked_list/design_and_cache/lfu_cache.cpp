#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LFUCache {
private:
    struct CacheNode {
        int key;
        int value;
        int freq;
    };

    int capacity;
    int minFreq;
    unordered_map<int, list<CacheNode>::iterator> keyTable;
    unordered_map<int, list<CacheNode>> freqTable;

    void updateFrequency(list<CacheNode>::iterator nodeIt) {
        int key = nodeIt->key;
        int value = nodeIt->value;
        int freq = nodeIt->freq;

        // Remove from current frequency list
        freqTable[freq].erase(nodeIt);

        // If minFreq list is now empty, update minFreq
        if (freqTable[freq].empty()) {
            freqTable.erase(freq);
            if (minFreq == freq) {
                minFreq++;
            }
        }

        // Add to new frequency list at front (most recent)
        freqTable[freq + 1].push_front({key, value, freq + 1});
        keyTable[key] = freqTable[freq + 1].begin();
    }

public:
    LFUCache(int cap) : capacity(cap), minFreq(0) {}

    int get(int key) {
        auto it = keyTable.find(key);
        if (it == keyTable.end()) return -1;

        updateFrequency(it->second);
        return it->second->value;
    }

    void put(int key, int value) {
        if (capacity <= 0) return;

        auto it = keyTable.find(key);
        if (it != keyTable.end()) {
            it->second->value = value;
            updateFrequency(it->second);
            return;
        }

        // Evict if at capacity
        if ((int)keyTable.size() >= capacity) {
            auto& minList = freqTable[minFreq];
            int evictKey = minList.back().key;
            minList.pop_back();
            if (minList.empty()) {
                freqTable.erase(minFreq);
            }
            keyTable.erase(evictKey);
        }

        // Insert new entry with frequency = 1
        minFreq = 1;
        freqTable[1].push_front({key, value, 1});
        keyTable[key] = freqTable[1].begin();
    }
};

int main() {
    LFUCache lfu(2);

    lfu.put(1, 1);
    lfu.put(2, 2);
    cout << "get(1): " << lfu.get(1) << " (Expected: 1, freq 1 -> 2)\n";

    lfu.put(3, 3); // Key 2 has freq 1, key 1 has freq 2 -> Evict key 2
    cout << "get(2): " << lfu.get(2) << " (Expected: -1, evicted)\n";
    cout << "get(3): " << lfu.get(3) << " (Expected: 3)\n";

    lfu.put(4, 4); // Key 1 has freq 2, key 3 has freq 2. Key 1 was accessed before 3 -> Evict key 1 (LRU tie-breaker)
    cout << "get(1): " << lfu.get(1) << " (Expected: -1, evicted)\n";
    cout << "get(3): " << lfu.get(3) << " (Expected: 3)\n";
    cout << "get(4): " << lfu.get(4) << " (Expected: 4)\n";

    return 0;
}
