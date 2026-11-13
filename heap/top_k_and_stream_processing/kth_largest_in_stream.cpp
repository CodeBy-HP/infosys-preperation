#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

class KthLargest {
private:
    int k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

public:
    KthLargest(int k, const std::vector<int>& nums) : k(k) {
        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        minHeap.push(val);
        if (static_cast<int>(minHeap.size()) > k) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};

int main() {
    std::vector<int> nums = {4, 5, 8, 2};
    KthLargest kthLargest(3, nums);

    assert(kthLargest.add(3) == 4);   // returns 4
    assert(kthLargest.add(5) == 5);   // returns 5
    assert(kthLargest.add(10) == 5);  // returns 5
    assert(kthLargest.add(9) == 8);   // returns 8
    assert(kthLargest.add(4) == 8);   // returns 8

    std::cout << "All K-th Largest in Stream tests passed successfully!\n";
    return 0;
}

