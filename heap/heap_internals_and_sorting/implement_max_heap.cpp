#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>

class MaxHeap {
private:
    std::vector<int> heap;

    void upHeapify(int i) {
        while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
            std::swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void downHeapify(int i) {
        int n = heap.size();
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && heap[left] > heap[largest]) largest = left;
        if (right < n && heap[right] > heap[largest]) largest = right;

        if (largest != i) {
            std::swap(heap[i], heap[largest]);
            downHeapify(largest);
        }
    }

public:
    MaxHeap() = default;

    int size() const {
        return heap.size();
    }

    bool empty() const {
        return heap.empty();
    }

    int getMax() const {
        assert(!heap.empty());
        return heap[0];
    }

    void insert(int val) {
        heap.push_back(val);
        upHeapify(heap.size() - 1);
    }

    int extractMax() {
        assert(!heap.empty());
        int rootVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty()) {
            downHeapify(0);
        }
        return rootVal;
    }

    void increaseKey(int i, int newVal) {
        assert(i >= 0 && i < static_cast<int>(heap.size()));
        assert(newVal >= heap[i]);
        heap[i] = newVal;
        upHeapify(i);
    }

    void deleteKey(int i) {
        increaseKey(i, INT_MAX);
        extractMax();
    }
};

int main() {
    MaxHeap h;
    h.insert(10);
    h.insert(20);
    h.insert(15);
    assert(h.getMax() == 20);

    h.insert(40);
    h.insert(50);
    h.insert(100);
    assert(h.getMax() == 100);

    assert(h.extractMax() == 100);
    assert(h.getMax() == 50);

    h.deleteKey(2); // delete an intermediate element
    assert(h.getMax() == 50);

    std::cout << "All Implement Max Heap tests passed successfully!\n";
    return 0;
}

