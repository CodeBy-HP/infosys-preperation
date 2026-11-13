#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class ConvertHeap {
private:
    static void maxHeapify(std::vector<int>& arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest]) largest = left;
        if (right < n && arr[right] > arr[largest]) largest = right;

        if (largest != i) {
            std::swap(arr[i], arr[largest]);
            maxHeapify(arr, n, largest);
        }
    }

public:
    static void convertMinToMaxHeap(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = (n - 2) / 2; i >= 0; --i) {
            maxHeapify(arr, n, i);
        }
    }

    static bool isMaxHeap(const std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i <= (n - 2) / 2; ++i) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < n && arr[i] < arr[left]) return false;
            if (right < n && arr[i] < arr[right]) return false;
        }
        return true;
    }
};

int main() {
    // Valid Min-Heap: 1, 2, 3, 4, 5, 6, 7
    std::vector<int> minHeap = {1, 2, 3, 4, 5, 6, 7};
    ConvertHeap::convertMinToMaxHeap(minHeap);
    assert(ConvertHeap::isMaxHeap(minHeap));
    assert(minHeap[0] == 7);

    std::vector<int> minHeap2 = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    ConvertHeap::convertMinToMaxHeap(minHeap2);
    assert(ConvertHeap::isMaxHeap(minHeap2));
    assert(minHeap2[0] == 20);

    std::cout << "All Convert Min Heap to Max Heap tests passed successfully!\n";
    return 0;
}

