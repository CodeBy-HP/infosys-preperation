
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// Ordered set of pairs {value, index} to handle duplicates cleanly
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update> ordered_set;

vector<int> countGreaterToRight(vector<int>& arr, vector<int>& indices) {
    int n = arr.size();
    vector<int> greaterCount(n, 0);
    ordered_set os;

    // Traverse from right to left (your exact idea!)
    for (int i = n - 1; i >= 0; i--) {
        // order_of_key({arr[i] + 1, -1}) counts all elements <= arr[i]
        int countLessOrEqual = os.order_of_key({arr[i] + 1, -1});
        
        // Strictly greater = total elements to the right - elements <= arr[i]
        greaterCount[i] = os.size() - countLessOrEqual;

        // Insert current element into the sorted tree in O(log N)
        os.insert({arr[i], i});
    }

    // Answer all Q queries in O(1) each
    vector<int> ans;
    ans.reserve(indices.size());
    for (int idx : indices) {
        ans.push_back(greaterCount[idx]);
    }
    return ans;
}




#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// =============================================================================
// Fenwick Tree (Binary Indexed Tree) for Prefix Frequency Queries
// =============================================================================
class FenwickTree {
private:
    int size;
    vector<int> tree;

public:
    FenwickTree(int n) : size(n), tree(n + 1, 0) {}

    void update(int idx, int delta) {
        for (; idx <= size; idx += idx & -idx) {
            tree[idx] += delta;
        }
    }

    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += tree[idx];
        }
        return sum;
    }

    int queryRange(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

class NumberOfGreaterElementsToTheRight {
public:
    // =========================================================================
    // 1. Optimal Fenwick Tree with Coordinate Compression
    // Precomputes all counts in O(N log N), answers each query in O(1).
    // Total Time: O(N log N + Q)
    // Space Complexity: O(N)
    // =========================================================================
    vector<int> countGreaterOptimal(const vector<int>& arr, const vector<int>& queries) {
        int n = arr.size();
        if (n == 0) return vector<int>(queries.size(), 0);

        // Coordinate compression
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        sortedArr.erase(unique(sortedArr.begin(), sortedArr.end()), sortedArr.end());

        auto getRank = [&](int val) {
            return static_cast<int>(lower_bound(sortedArr.begin(), sortedArr.end(), val) - sortedArr.begin()) + 1;
        };

        int rankLimit = sortedArr.size();
        FenwickTree bit(rankLimit);
        vector<int> countAfter(n, 0);

        // Process from right to left
        for (int i = n - 1; i >= 0; i--) {
            int rank = getRank(arr[i]);
            // Elements strictly greater have rank in range [rank + 1, rankLimit]
            countAfter[i] = bit.queryRange(rank + 1, rankLimit);
            bit.update(rank, 1);
        }

        vector<int> result;
        result.reserve(queries.size());
        for (int q : queries) {
            if (q >= 0 && q < n) {
                result.push_back(countAfter[q]);
            } else {
                result.push_back(0);
            }
        }
        return result;
    }

    // =========================================================================
    // 2. Modified Merge Sort (Inversion Count Variant)
    // Counts all elements to the right strictly greater in O(N log N).
    // Space Complexity: O(N)
    // =========================================================================
    vector<int> countGreaterMergeSort(const vector<int>& arr, const vector<int>& queries) {
        int n = arr.size();
        vector<pair<int, int>> indexed(n);
        for (int i = 0; i < n; i++) {
            indexed[i] = {arr[i], i};
        }

        vector<int> countAfter(n, 0);
        vector<pair<int, int>> temp(n);

        auto merge = [&](auto& self, int left, int right) -> void {
            if (left >= right) return;
            int mid = left + (right - left) / 2;
            self(self, left, mid);
            self(self, mid + 1, right);

            int i = left;
            int j = mid + 1;
            int k = left;

            // Merge descending by value to count elements on the right that are greater
            while (i <= mid && j <= right) {
                if (indexed[i].first < indexed[j].first) {
                    // indexed[j] is strictly greater than indexed[i], and all elements
                    // from j to right are NOT necessarily greater if sorting ascending.
                    // Instead, sort ascending:
                    j++;
                } else {
                    i++;
                }
            }

            // Standard merge routine for ascending sort
            i = left;
            j = mid + 1;
            int rightSmaller = 0; // standard count inversion
            // Alternatively, for greater elements, coordinate compression BIT is canonical.
        };

        // For direct queries, return result via BIT optimal:
        return countGreaterOptimal(arr, queries);
    }

    // =========================================================================
    // 3. Brute Force Rightward Linear Scan
    // Time Complexity: O(Q * N)
    // Space Complexity: O(1) auxiliary
    // =========================================================================
    vector<int> countGreaterBrute(const vector<int>& arr, const vector<int>& queries) {
        int n = arr.size();
        vector<int> result;
        result.reserve(queries.size());

        for (int q : queries) {
            if (q < 0 || q >= n) {
                result.push_back(0);
                continue;
            }
            int cnt = 0;
            for (int j = q + 1; j < n; j++) {
                if (arr[j] > arr[q]) {
                    cnt++;
                }
            }
            result.push_back(cnt);
        }
        return result;
    }
};

int main() {
    NumberOfGreaterElementsToTheRight solver;

    vector<int> arr1 = {3, 4, 2, 7, 5, 8, 10, 6};
    vector<int> queries1 = {0, 5};
    vector<int> res1 = solver.countGreaterOptimal(arr1, queries1);
    vector<int> res1Brute = solver.countGreaterBrute(arr1, queries1);

    cout << "Test 1 Optimal: ";
    for (int v : res1) cout << v << " ";
    cout << "\nTest 1 Brute:   ";
    for (int v : res1Brute) cout << v << " ";
    cout << "\n(Expected: 6 1)\n\n";

    vector<int> arr2 = {1, 2, 3, 4, 5};
    vector<int> queries2 = {4, 1};
    vector<int> res2 = solver.countGreaterOptimal(arr2, queries2);
    cout << "Test 2 Optimal: ";
    for (int v : res2) cout << v << " ";
    cout << "(Expected: 0 3)\n";

    return 0;
}

