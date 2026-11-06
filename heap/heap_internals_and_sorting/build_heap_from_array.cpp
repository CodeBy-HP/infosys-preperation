#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class BuildHeap {
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

    static void minHeapify(std::vector<int>& arr, int n, int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] < arr[smallest]) smallest = left;
        if (right < n && arr[right] < arr[smallest]) smallest = right;

        if (smallest != i) {
            std::swap(arr[i], arr[smallest]);
            minHeapify(arr, n, smallest);
        }
    }

public:
    // Build Max-Heap in O(N) Time
    static void buildMaxHeap(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = n / 2 - 1; i >= 0; --i) {
            maxHeapify(arr, n, i);
        }
    }

    // Build Min-Heap in O(N) Time
    static void buildMinHeap(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = n / 2 - 1; i >= 0; --i) {
            minHeapify(arr, n, i);
        }
    }

    static bool isMaxHeap(const std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i <= n / 2 - 1; ++i) {
            if (2 * i + 1 < n && arr[i] < arr[2 * i + 1]) return false;
            if (2 * i + 2 < n && arr[i] < arr[2 * i + 2]) return false;
        }
        return true;
    }

    static bool isMinHeap(const std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i <= n / 2 - 1; ++i) {
            if (2 * i + 1 < n && arr[i] > arr[2 * i + 1]) return false;
            if (2 * i + 2 < n && arr[i] > arr[2 * i + 2]) return false;
        }
        return true;
    }
};

int main() {
    std::vector<int> a1 = {4, 10, 3, 5, 1};
    BuildHeap::buildMaxHeap(a1);
    assert(BuildHeap::isMaxHeap(a1));
    assert(a1[0] == 10);

    std::vector<int> a2 = {12, 11, 13, 5, 6, 7};
    BuildHeap::buildMinHeap(a2);
    assert(BuildHeap::isMinHeap(a2));
    assert(a2[0] == 5);

    std::cout << "All Build Heap From Array tests passed successfully!\n";
    return 0;
}

