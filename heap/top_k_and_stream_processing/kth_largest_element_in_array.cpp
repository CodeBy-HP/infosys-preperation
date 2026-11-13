#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>

class KthLargestElement {
public:
    // Approach 1: Min-Heap of Size K - O(N log K) Time, O(K) Space
    static int findKthLargestHeap(const std::vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);
            if (static_cast<int>(minHeap.size()) > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }

    // Approach 2: Quickselect - O(N) Average Time, O(1) Space
    static int quickSelect(std::vector<int>& nums, int left, int right, int targetIdx) {
        if (left == right) return nums[left];

        int pivot = nums[right];
        int pIndex = left;

        for (int i = left; i < right; ++i) {
            if (nums[i] <= pivot) {
                std::swap(nums[i], nums[pIndex]);
                pIndex++;
            }
        }
        std::swap(nums[pIndex], nums[right]);

        if (pIndex == targetIdx) return nums[pIndex];
        else if (pIndex < targetIdx) return quickSelect(nums, pIndex + 1, right, targetIdx);
        else return quickSelect(nums, left, pIndex - 1, targetIdx);
    }

    static int findKthLargestQuickSelect(std::vector<int> nums, int k) {
        int targetIdx = nums.size() - k; // Index in ascending array
        return quickSelect(nums, 0, nums.size() - 1, targetIdx);
    }
};

int main() {
    std::vector<int> n1 = {3, 2, 1, 5, 6, 4};
    assert(KthLargestElement::findKthLargestHeap(n1, 2) == 5);
    assert(KthLargestElement::findKthLargestQuickSelect(n1, 2) == 5);

    std::vector<int> n2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    assert(KthLargestElement::findKthLargestHeap(n2, 4) == 4);
    assert(KthLargestElement::findKthLargestQuickSelect(n2, 4) == 4);

    std::cout << "All K-th Largest Element tests passed successfully!\n";
    return 0;
}

