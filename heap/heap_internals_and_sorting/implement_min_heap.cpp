#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>

class MinHeap {
private:
    std::vector<int> heap;

    void upHeapify(int i) {
        while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
            std::swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void downHeapify(int i) {
        int n = heap.size();
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && heap[left] < heap[smallest]) smallest = left;
        if (right < n && heap[right] < heap[smallest]) smallest = right;

        if (smallest != i) {
            std::swap(heap[i], heap[smallest]);
            downHeapify(smallest);
        }
    }

public:
    MinHeap() = default;

    int size() const {
        return heap.size();
    }

    bool empty() const {
        return heap.empty();
    }

    int getMin() const {
        assert(!heap.empty());
        return heap[0];
    }

    void insert(int val) {
        heap.push_back(val);
        upHeapify(heap.size() - 1);
    }

    int extractMin() {
        assert(!heap.empty());
        int rootVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty()) {
            downHeapify(0);
        }
        return rootVal;
    }

    void decreaseKey(int i, int newVal) {
        assert(i >= 0 && i < static_cast<int>(heap.size()));
        assert(newVal <= heap[i]);
        heap[i] = newVal;
        upHeapify(i);
    }

    void deleteKey(int i) {
        decreaseKey(i, INT_MIN);
        extractMin();
    }
};

int main() {
    MinHeap h;
    h.insert(3);
    h.insert(2);
    assert(h.getMin() == 2);

    h.deleteKey(1); // delete 3
    assert(h.getMin() == 2);

    h.insert(15);
    h.insert(5);
    h.insert(4);
    h.insert(45);

    assert(h.extractMin() == 2);
    assert(h.getMin() == 4);

    h.decreaseKey(2, 1);
    assert(h.getMin() == 1);

    std::cout << "All Implement Min Heap tests passed successfully!\n";
    return 0;
}

