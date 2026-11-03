#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <cassert>

/**
 * Problem 17: Frequency Balanced Window
 * 
 * Problem:
 * Given n data packets, each with a category and signal weight.
 * A window [L, R] is frequency balanced if at least one category appears
 * strictly more than half the time: count(c) > (R - L + 1) / 2.
 * Find the maximum total weight among all frequency balanced windows.
 * 
 * Approach:
 * For each candidate category c:
 *   Transform to +1 if cat[i] == c else -1.
 *   Condition: P_D[R + 1] - P_D[L] >= 1 <=> P_D[L] <= P_D[R + 1] - 1.
 *   We want to maximize P_W[R + 1] - P_W[L] <=> minimize P_W[L].
 *   Maintain a Fenwick Tree (Binary Indexed Tree) for prefix minimums over P_D values.
 * 
 * Time Complexity: O(U * n log n) where U is the number of distinct categories.
 * Space Complexity: O(n)
 */

class FenwickTreeMin {
private:
    int size;
    const long long INF = 4e18; // Large enough for max weight bounds
    std::vector<long long> tree;

public:
    FenwickTreeMin(int n) : size(n), tree(n + 1, INF) {}

    void clear() {
        std::fill(tree.begin(), tree.end(), INF);
    }

    void update(int idx, long long val) {
        while (idx <= size) {
            if (val < tree[idx]) {
                tree[idx] = val;
            }
            idx += idx & (-idx);
        }
    }

    long long query(int idx) {
        idx = std::min(idx, size);
        long long res = INF;
        while (idx > 0) {
            if (tree[idx] < res) {
                res = tree[idx];
            }
            idx -= idx & (-idx);
        }
        return res;
    }
};

class Solution {
public:
    long long maxWeightFrequencyBalancedWindow(const std::vector<int>& categories,
                                               const std::vector<long long>& weights) {
        int n = static_cast<int>(categories.size());
        if (n == 0) return 0;

        // Baseline: Any single packet has length 1 where its category appears 100% of the time (> 50%).
        long long max_weight = LLONG_MIN;
        for (long long w : weights) {
            max_weight = std::max(max_weight, w);
        }

        // Prefix weights: pw[k] = sum_{i=0}^{k-1} weights[i]
        std::vector<long long> pw(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pw[i + 1] = pw[i] + weights[i];
        }

        // Find distinct categories present
        std::unordered_set<int> unique_categories(categories.begin(), categories.end());

        // Difference values range from -n to +n.
        // Shift values by offset = n + 1 so they fall in [1, 2n + 1].
        int offset = n + 1;
        int tree_size = 2 * n + 5;
        FenwickTreeMin bit(tree_size);

        for (int c : unique_categories) {
            bit.clear();

            // At prefix L = 0: P_D = 0, P_W = 0
            int cur_diff = 0;
            bit.update(cur_diff + offset, 0);

            for (int i = 0; i < n; ++i) {
                if (categories[i] == c) {
                    cur_diff += 1;
                } else {
                    cur_diff -= 1;
                }

                // Condition: P_D[L] <= cur_diff - 1
                int target_diff = cur_diff - 1 + offset;
                if (target_diff > 0) {
                    long long min_pw = bit.query(target_diff);
                    if (min_pw < 4e18) {
                        max_weight = std::max(max_weight, pw[i + 1] - min_pw);
                    }
                }

                // Insert prefix L = i + 1 with its weight pw[i + 1]
                bit.update(cur_diff + offset, pw[i + 1]);
            }
        }

        return max_weight;
    }
};

int main() {
    Solution solver;

    // Test 1: Mixed weights with clear majority
    {
        std::vector<int> cats = {1, 2, 1, 1, 3};
        std::vector<long long> w = {5, -2, 4, 3, -10};
        // Window [0, 3] gives 5 - 2 + 4 + 3 = 10, category 1 appears 3 / 4 times.
        long long ans = solver.maxWeightFrequencyBalancedWindow(cats, w);
        std::cout << "Test 1: Expected = 10, Actual = " << ans << std::endl;
        assert(ans == 10);
    }

    // Test 2: All negative weights
    {
        std::vector<int> cats = {2, 2, 2};
        std::vector<long long> w = {-5, -1, -3};
        long long ans = solver.maxWeightFrequencyBalancedWindow(cats, w);
        std::cout << "Test 2: Expected = -1, Actual = " << ans << std::endl;
        assert(ans == -1);
    }

    // Test 3: Single element
    {
        std::vector<int> cats = {7};
        std::vector<long long> w = {42};
        long long ans = solver.maxWeightFrequencyBalancedWindow(cats, w);
        std::cout << "Test 3: Expected = 42, Actual = " << ans << std::endl;
        assert(ans == 42);
    }

    // Test 4: Alternating categories with positive weights
    {
        std::vector<int> cats = {1, 2, 1, 2, 1};
        std::vector<long long> w = {10, 10, 10, 10, 10};
        // Window [0, 4] has length 5, category 1 appears 3 times (3 > 2.5), weight = 50.
        long long ans = solver.maxWeightFrequencyBalancedWindow(cats, w);
        std::cout << "Test 4: Expected = 50, Actual = " << ans << std::endl;
        assert(ans == 50);
    }

    std::cout << "All Frequency Balanced Window test cases passed successfully!" << std::endl;
    return 0;
}

