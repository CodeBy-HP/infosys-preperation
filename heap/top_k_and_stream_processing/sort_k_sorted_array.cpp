#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>

class SortKSortedArray {
public:
    static void nearlySorted(std::vector<int>& arr, int k) {
        int n = arr.size();
        if (n <= 1 || k == 0) return;

        // Min-heap to maintain window of size k + 1
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        // Push first k + 1 elements
        int initialSize = std::min(n, k + 1);
        for (int i = 0; i < initialSize; ++i) {
            minHeap.push(arr[i]);
        }

        int targetIndex = 0;
        for (int i = k + 1; i < n; ++i) {
            arr[targetIndex++] = minHeap.top();
            minHeap.pop();
            minHeap.push(arr[i]);
        }

        while (!minHeap.empty()) {
            arr[targetIndex++] = minHeap.top();
            minHeap.pop();
        }
    }
};

int main() {
    std::vector<int> a1 = {6, 5, 3, 2, 8, 10, 9};
    int k1 = 3;
    SortKSortedArray::nearlySorted(a1, k1);
    assert(std::is_sorted(a1.begin(), a1.end()));

    std::vector<int> a2 = {10, 9, 8, 7, 4, 70, 60, 50};
    int k2 = 4;
    SortKSortedArray::nearlySorted(a2, k2);
    assert(std::is_sorted(a2.begin(), a2.end()));

    std::cout << "All Sort K-Sorted Array tests passed successfully!\n";
    return 0;
}

