#include <iostream>
#include <vector>
#include <cassert>

class CheckMinHeap {
public:
    static bool isMinHeap(const std::vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return true;

        // Check all internal nodes
        for (int i = 0; i <= (n - 2) / 2; ++i) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && arr[i] > arr[left]) {
                return false;
            }
            if (right < n && arr[i] > arr[right]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::vector<int> a1 = {10, 20, 30, 25, 35, 40};
    assert(CheckMinHeap::isMinHeap(a1) == true);

    std::vector<int> a2 = {10, 20, 30, 40, 15}; // 15 is child of 20 -> violation!
    assert(CheckMinHeap::isMinHeap(a2) == false);

    std::vector<int> a3 = {1};
    assert(CheckMinHeap::isMinHeap(a3) == true);

    std::cout << "All Check If Array is Min Heap tests passed successfully!\n";
    return 0;
}

