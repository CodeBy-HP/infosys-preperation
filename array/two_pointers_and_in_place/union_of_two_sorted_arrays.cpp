#include <iostream>
#include <vector>
#include <set>
#include <cassert>

/**
 * Union of Two Sorted Arrays
 * Set (Brute Force) vs Two-Pointer Merge (Optimal).
 */

class Solution {
public:
    // Approach 1: Set - O((N + M) log(N + M)) Time, O(N + M) Space
    std::vector<int> unionBrute(const std::vector<int>& a, const std::vector<int>& b) {
        std::set<int> s;
        for (int x : a) s.insert(x);
        for (int x : b) s.insert(x);
        return std::vector<int>(s.begin(), s.end());
    }

    // Approach 2: Optimal Two-Pointer Merge - O(N + M) Time, O(1) Auxiliary Space
    std::vector<int> unionOptimal(const std::vector<int>& a, const std::vector<int>& b) {
        int n = static_cast<int>(a.size());
        int m = static_cast<int>(b.size());
        int i = 0, j = 0;
        std::vector<int> result;

        auto appendDistinct = [&](int val) {
            if (result.empty() || result.back() != val) {
                result.push_back(val);
            }
        };

        while (i < n && j < m) {
            if (a[i] <= b[j]) {
                appendDistinct(a[i]);
                i++;
            } else {
                appendDistinct(b[j]);
                j++;
            }
        }

        while (i < n) {
            appendDistinct(a[i++]);
        }
        while (j < m) {
            appendDistinct(b[j++]);
        }

        return result;
    }
};

int main() {
    Solution solver;

    std::vector<int> a = {1, 2, 3, 4, 5};
    std::vector<int> b = {1, 2, 3, 6, 7};
    std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7};

    assert(solver.unionBrute(a, b) == expected);
    assert(solver.unionOptimal(a, b) == expected);

    std::vector<int> a2 = {2, 2, 3, 4, 5};
    std::vector<int> b2 = {1, 1, 2, 3, 4};
    std::vector<int> expected2 = {1, 2, 3, 4, 5};

    assert(solver.unionBrute(a2, b2) == expected2);
    assert(solver.unionOptimal(a2, b2) == expected2);

    std::cout << "All Union of Two Sorted Arrays tests passed successfully!" << std::endl;
    return 0;
}

