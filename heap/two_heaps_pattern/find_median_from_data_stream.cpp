#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cassert>

class MedianFinder {
private:
    std::priority_queue<int> maxHeap; // Smaller half
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // Larger half

public:
    MedianFinder() = default;

    void addNum(int num) {
        // Step 1: Add to leftMaxHeap
        maxHeap.push(num);

        // Step 2: Ensure order invariant: max(left) <= min(right)
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // Step 3: Ensure size invariant: |left| >= |right|
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() const {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
};

int main() {
    MedianFinder mf;
    mf.addNum(1);
    assert(std::abs(mf.findMedian() - 1.0) < 1e-5);

    mf.addNum(2);
    assert(std::abs(mf.findMedian() - 1.5) < 1e-5);

    mf.addNum(3);
    assert(std::abs(mf.findMedian() - 2.0) < 1e-5);

    mf.addNum(4);
    assert(std::abs(mf.findMedian() - 2.5) < 1e-5);

    std::cout << "All Find Median from Data Stream tests passed successfully!\n";
    return 0;
}

