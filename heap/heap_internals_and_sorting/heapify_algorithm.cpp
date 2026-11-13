#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class HeapifyOperations {
public:
    // Down-Heapify (Sink) for Min-Heap - O(log N) Time, O(1) Space
    static void minHeapify(std::vector<int>& arr, int n, int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] < arr[smallest]) {
            smallest = left;
        }
        if (right < n && arr[right] < arr[smallest]) {
            smallest = right;
        }

        if (smallest != i) {
            std::swap(arr[i], arr[smallest]);
            minHeapify(arr, n, smallest);
        }
    }

    // Down-Heapify (Sink) for Max-Heap - O(log N) Time, O(1) Space
    static void maxHeapify(std::vector<int>& arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            std::swap(arr[i], arr[largest]);
            maxHeapify(arr, n, largest);
        }
    }

    // Up-Heapify (Swim) for Min-Heap - O(log N) Time, O(1) Space
    static void upHeapifyMin(std::vector<int>& arr, int i) {
        while (i > 0 && arr[(i - 1) / 2] > arr[i]) {
            std::swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // Up-Heapify (Swim) for Max-Heap - O(log N) Time, O(1) Space
    static void upHeapifyMax(std::vector<int>& arr, int i) {
        while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
            std::swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
};

int main() {
    // Test Min-Heapify (Sink)
    std::vector<int> minArr = {10, 3, 5, 8, 9};
    HeapifyOperations::minHeapify(minArr, minArr.size(), 0);
    assert(minArr[0] == 3);

    // Test Max-Heapify (Sink)
    std::vector<int> maxArr = {1, 10, 15, 8, 9};
    HeapifyOperations::maxHeapify(maxArr, maxArr.size(), 0);
    assert(maxArr[0] == 15);

    // Test Up-Heapify (Swim)
    std::vector<int> swimMin = {2, 4, 8, 1}; // 1 at index 3 violates min-heap
    HeapifyOperations::upHeapifyMin(swimMin, 3);
    assert(swimMin[0] == 1);

    std::cout << "All Heapify Algorithm tests passed successfully!\n";
    return 0;
}

