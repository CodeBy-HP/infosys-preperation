#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cassert>

class TopKFrequent {
public:
    // Approach 1: Min-Heap of Size K - O(N log K) Time, O(N) Space
    static std::vector<int> topKFrequentHeap(const std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;

        // Min-heap: {count, num}
        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>,
                            std::greater<std::pair<int, int>>> minHeap;

        for (const auto& [num, count] : freq) {
            minHeap.push({count, num});
            if (static_cast<int>(minHeap.size()) > k) {
                minHeap.pop();
            }
        }

        std::vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }

    // Approach 2: Bucket Sort - O(N) Time, O(N) Space
    static std::vector<int> topKFrequentBucket(const std::vector<int>& nums, int k) {
        int n = nums.size();
        std::unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;

        std::vector<std::vector<int>> buckets(n + 1);
        for (const auto& [num, count] : freq) {
            buckets[count].push_back(num);
        }

        std::vector<int> result;
        for (int f = n; f >= 1 && static_cast<int>(result.size()) < k; --f) {
            for (int num : buckets[f]) {
                result.push_back(num);
                if (static_cast<int>(result.size()) == k) break;
            }
        }
        return result;
    }
};

int main() {
    std::vector<int> n1 = {1, 1, 1, 2, 2, 3};
    auto res1_heap = TopKFrequent::topKFrequentHeap(n1, 2);
    auto res1_buck = TopKFrequent::topKFrequentBucket(n1, 2);
    std::sort(res1_heap.begin(), res1_heap.end());
    std::sort(res1_buck.begin(), res1_buck.end());
    assert(res1_heap == std::vector<int>({1, 2}));
    assert(res1_buck == std::vector<int>({1, 2}));

    std::vector<int> n2 = {1};
    assert(TopKFrequent::topKFrequentHeap(n2, 1) == std::vector<int>({1}));
    assert(TopKFrequent::topKFrequentBucket(n2, 1) == std::vector<int>({1}));

    std::cout << "All Top K Frequent Elements tests passed successfully!\n";
    return 0;
}

