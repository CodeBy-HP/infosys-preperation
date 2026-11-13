#include <iostream>
#include <vector>
#include <set>
#include <cassert>

/**
 * Sliding Window X-th Smallest Element
 * 
 * Uses the Two Multisets (Balanced Red-Black Tree) pattern:
 * - 'left' multiset stores the x smallest elements (size strictly x).
 * - 'right' multiset stores the remaining (k - x) elements.
 * - The x-th smallest element is always *left.rbegin().
 * 
 * Time Complexity: O(N log K)
 * Space Complexity: O(K)
 */

class TwoMultisets {
private:
    int x;
    std::multiset<long long> left;   // Stores x smallest elements
    std::multiset<long long> right;  // Stores remaining larger elements

    void balance() {
        // If left has more than x elements, transfer excess to right
        while (static_cast<int>(left.size()) > x) {
            auto it = std::prev(left.end());
            right.insert(*it);
            left.erase(it);
        }

        // If left has fewer than x elements, pull smallest from right
        while (static_cast<int>(left.size()) < x && !right.empty()) {
            auto it = right.begin();
            left.insert(*it);
            right.erase(it);
        }
    }

public:
    TwoMultisets(int required_x) : x(required_x) {}

    void insert(long long val) {
        if (left.empty() || val <= *left.rbegin()) {
            left.insert(val);
        } else {
            right.insert(val);
        }
        balance();
    }

    void erase(long long val) {
        // Must erase by iterator to remove ONLY ONE instance of val
        auto it = left.find(val);
        if (it != left.end()) {
            left.erase(it);
        } else {
            it = right.find(val);
            if (it != right.end()) {
                right.erase(it);
            }
        }
        balance();
    }

    long long getXthSmallest() const {
        return *left.rbegin();
    }
};

class Solution {
public:
    std::vector<long long> xthSmallestSlidingWindow(const std::vector<long long>& nums, int k, int x) {
        int n = static_cast<int>(nums.size());
        if (n == 0 || k <= 0 || x <= 0 || x > k || n < k) {
            return {};
        }

        TwoMultisets window(x);
        std::vector<long long> result;

        // Initialize first window of size k
        for (int i = 0; i < k; ++i) {
            window.insert(nums[i]);
        }
        result.push_back(window.getXthSmallest());

        // Slide the window across the remaining elements
        for (int i = k; i < n; ++i) {
            window.insert(nums[i]);
            window.erase(nums[i - k]);
            result.push_back(window.getXthSmallest());
        }

        return result;
    }
};

int main() {
    Solution solver;

    // Test 1: Example 1 from problem statement
    {
        std::vector<long long> nums = {1, 5, 2, 8, 3, 7};
        int k = 3, x = 2;
        std::vector<long long> expected = {2, 5, 3, 7};
        std::vector<long long> actual = solver.xthSmallestSlidingWindow(nums, k, x);
        assert(actual == expected);
    }

    // Test 2: Unbounded large negative/positive values (impossible with frequency buckets)
    {
        std::vector<long long> nums = {-1000000000LL, 1000000000LL, -500000000LL, 500000000LL};
        int k = 2, x = 1; // Sliding window minimum
        std::vector<long long> expected = {-1000000000LL, -500000000LL, -500000000LL};
        std::vector<long long> actual = solver.xthSmallestSlidingWindow(nums, k, x);
        assert(actual == expected);
    }

    // Test 3: Duplicates handling
    {
        std::vector<long long> nums = {4, 4, 4, 4};
        int k = 3, x = 2;
        std::vector<long long> expected = {4, 4};
        std::vector<long long> actual = solver.xthSmallestSlidingWindow(nums, k, x);
        assert(actual == expected);
    }

    // Test 4: x = k (Sliding window maximum)
    {
        std::vector<long long> nums = {1, 3, -1, -3, 5, 3, 6, 7};
        int k = 3, x = 3;
        std::vector<long long> expected = {3, 3, 5, 5, 6, 7};
        std::vector<long long> actual = solver.xthSmallestSlidingWindow(nums, k, x);
        assert(actual == expected);
    }

    std::cout << "All Sliding Window X-th Smallest Element tests passed successfully!" << std::endl;
    return 0;
}

