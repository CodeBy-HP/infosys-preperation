#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class HeapSort {
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
    static void heapSort(std::vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return;

        // Phase 1: Build Max-Heap - O(N)
        for (int i = n / 2 - 1; i >= 0; --i) {
            maxHeapify(arr, n, i);
        }

        // Phase 2: In-place extract maximum - O(N log N)
        for (int i = n - 1; i > 0; --i) {
            std::swap(arr[0], arr[i]); // Move current max to end
            maxHeapify(arr, i, 0);     // Heapify reduced heap
        }
    }
};

int main() {
    std::vector<int> a1 = {12, 11, 13, 5, 6, 7};
    HeapSort::heapSort(a1);
    assert(std::is_sorted(a1.begin(), a1.end()));

    std::vector<int> a2 = {4, 10, 3, 5, 1};
    HeapSort::heapSort(a2);
    assert(std::is_sorted(a2.begin(), a2.end()));

    std::vector<int> a3 = {1};
    HeapSort::heapSort(a3);
    assert(std::is_sorted(a3.begin(), a3.end()));

    std::cout << "All Heap Sort tests passed successfully!\n";
    return 0;
}

