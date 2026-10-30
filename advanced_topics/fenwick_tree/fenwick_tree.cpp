#include <iostream>
#include <vector>

using namespace std;

// =============================================================================
// 1. Classic 1D Fenwick Tree (Point Update, Range Query)
// Time Complexity: Build: O(N), Update: O(log N), Query: O(log N)
// Space Complexity: N + 1
// =============================================================================
class FenwickTree1D {
private:
    int n;
    vector<long long> bit;
    vector<int> original;

    inline int LSB(int i) const {
        return i & (-i);
    }

public:
    // Linear O(N) build constructor
    FenwickTree1D(const vector<int>& nums) {
        n = nums.size();
        original = nums;
        bit.assign(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            bit[i] += nums[i - 1];
            int parent = i + LSB(i);
            if (parent <= n) {
                bit[parent] += bit[i];
            }
        }
    }

    void add(int index, long long delta) {
        // index is 0-based; BIT is 1-based
        int i = index + 1;
        while (i <= n) {
            bit[i] += delta;
            i += LSB(i);
        }
    }

    void update(int index, int val) {
        long long delta = (long long)val - original[index];
        original[index] = val;
        add(index, delta);
    }

    // Prefix sum from index 0 to index (inclusive)
    long long queryPrefix(int index) const {
        int i = index + 1;
        long long sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= LSB(i);
        }
        return sum;
    }

    // Range sum from left to right (inclusive)
    long long queryRange(int left, int right) const {
        if (left > right) return 0;
        return queryPrefix(right) - (left > 0 ? queryPrefix(left - 1) : 0);
    }
};

// =============================================================================
// 2. Range Update & Point Query Fenwick Tree (Difference Array)
// Update range [L, R] by +delta in O(log N)
// Query value at index i in O(log N)
// =============================================================================
class FenwickTreeRangeUpdate {
private:
    int n;
    vector<long long> bit;

    inline int LSB(int i) const {
        return i & (-i);
    }

    void add(int i, long long delta) {
        while (i <= n) {
            bit[i] += delta;
            i += LSB(i);
        }
    }

public:
    FenwickTreeRangeUpdate(int size) : n(size), bit(size + 1, 0) {}

    // Add delta to all elements in range [L, R] (0-based)
    void updateRange(int L, int R, long long delta) {
        add(L + 1, delta);
        add(R + 2, -delta);
    }

    // Query value at index (0-based)
    long long queryPoint(int index) const {
        int i = index + 1;
        long long val = 0;
        while (i > 0) {
            val += bit[i];
            i -= LSB(i);
        }
        return val;
    }
};

// =============================================================================
// 3. 2D Fenwick Tree (Matrix Point Update & 2D Prefix Sum Query)
// Time Complexity: Update: O(log R * log C), Query: O(log R * log C)
// Space Complexity: O(R * C)
// =============================================================================
class FenwickTree2D {
private:
    int rows, cols;
    vector<vector<long long>> bit;

    inline int LSB(int i) const { return i & (-i); }

public:
    FenwickTree2D(int r, int c) : rows(r), cols(c), bit(r + 1, vector<long long>(c + 1, 0)) {}

    void add(int r, int c, long long delta) {
        for (int i = r + 1; i <= rows; i += LSB(i)) {
            for (int j = c + 1; j <= cols; j += LSB(j)) {
                bit[i][j] += delta;
            }
        }
    }

    long long queryPrefix(int r, int c) const {
        long long sum = 0;
        for (int i = r + 1; i > 0; i -= LSB(i)) {
            for (int j = c + 1; j > 0; j -= LSB(j)) {
                sum += bit[i][j];
            }
        }
        return sum;
    }

    // Submatrix sum from (r1, c1) to (r2, c2)
    long long queryRegion(int r1, int c1, int r2, int c2) const {
        return queryPrefix(r2, c2)
             - queryPrefix(r1 - 1, c2)
             - queryPrefix(r2, c1 - 1)
             + queryPrefix(r1 - 1, c1 - 1);
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11};

    cout << "=== 1D Fenwick Tree (Point Update, Range Query) ===\n";
    FenwickTree1D bit1(nums);
    cout << "Range sum [1, 3]: " << bit1.queryRange(1, 3) << " (Expected: 3+5+7 = 15)\n";
    bit1.update(1, 10); // nums becomes {1, 10, 5, 7, 9, 11}
    cout << "After update(1, 10), Range sum [1, 3]: " << bit1.queryRange(1, 3) << " (Expected: 10+5+7 = 22)\n";

    cout << "\n=== Range Update Fenwick Tree ===\n";
    FenwickTreeRangeUpdate bitRange(6);
    bitRange.updateRange(1, 3, 10);
    cout << "Point query at index 2: " << bitRange.queryPoint(2) << " (Expected: 10)\n";
    cout << "Point query at index 4: " << bitRange.queryPoint(4) << " (Expected: 0)\n";

    cout << "\n=== 2D Fenwick Tree ===\n";
    FenwickTree2D bit2D(3, 3);
    bit2D.add(1, 1, 5);
    bit2D.add(1, 2, 3);
    cout << "Region sum (0,0) to (2,2): " << bit2D.queryRegion(0, 0, 2, 2) << " (Expected: 8)\n";

    return 0;
}

