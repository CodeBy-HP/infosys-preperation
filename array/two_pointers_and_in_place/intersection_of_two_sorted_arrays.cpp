#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>

/**
 * Intersection of Two Sorted Arrays
 * Hash Set vs Two-Pointer Optimal Merge.
 */

class Solution {
public:
    // Approach 1: Hash Set - O(N + M) Time, O(N) Space
    std::vector<int> intersectionSet(const std::vector<int>& a, const std::vector<int>& b) {
        std::unordered_set<int> set_a(a.begin(), a.end());
        std::vector<int> result;
        for (int x : b) {
            if (set_a.count(x)) {
                if (result.empty() || result.back() != x) {
                    result.push_back(x);
                }
            }
        }
        return result;
    }

    // Approach 2: Optimal Two-Pointer Merge - O(N + M) Time, O(1) Auxiliary Space
    std::vector<int> intersectionOptimal(const std::vector<int>& a, const std::vector<int>& b) {
        int n = static_cast<int>(a.size());
        int m = static_cast<int>(b.size());
        int i = 0, j = 0;
        std::vector<int> result;

        while (i < n && j < m) {
            if (a[i] == b[j]) {
                if (result.empty() || result.back() != a[i]) {
                    result.push_back(a[i]);
                }
                i++;
                j++;
            } else if (a[i] < b[j]) {
                i++;
            } else {
                j++;
            }
        }

        return result;
    }
};

int main() {
    Solution solver;

    std::vector<int> a1 = {1, 2, 2, 3, 4};
    std::vector<int> b1 = {2, 2, 4, 6, 7, 8};
    std::vector<int> expected1 = {2, 4};

    assert(solver.intersectionSet(a1, b1) == expected1);
    assert(solver.intersectionOptimal(a1, b1) == expected1);

    std::vector<int> a2 = {1, 2, 3};
    std::vector<int> b2 = {4, 5, 6};
    assert(solver.intersectionOptimal(a2, b2).empty());

    std::cout << "All Intersection of Two Sorted Arrays tests passed successfully!" << std::endl;
    return 0;
}

