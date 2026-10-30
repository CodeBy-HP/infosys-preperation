#include <iostream>
#include <vector>

using namespace std;

// =============================================================================
// 1. Classic Segment Tree with Point Updates & Range Sum Queries
// Time Complexity: Build: O(N), Update: O(log N), Query: O(log N)
// Space Complexity: 4 * N
// =============================================================================
class SegmentTreePointUpdate {
private:
    int n;
    vector<long long> tree;

    void build(int node, int start, int end, const vector<int>& nums) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        }

        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        build(leftChild, start, mid, nums);
        build(rightChild, mid + 1, end, nums);

        tree[node] = tree[leftChild] + tree[rightChild];
    }

    void updateTree(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }

        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        if (idx <= mid) {
            updateTree(leftChild, start, mid, idx, val);
        } else {
            updateTree(rightChild, mid + 1, end, idx, val);
        }

        tree[node] = tree[leftChild] + tree[rightChild];
    }

    long long queryTree(int node, int start, int end, int L, int R) const {
        // Scenario 1: No Overlap
        if (R < start || L > end) return 0;

        // Scenario 2: Total Overlap
        if (L <= start && end <= R) return tree[node];

        // Scenario 3: Partial Overlap
        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        return queryTree(leftChild, start, mid, L, R) +
               queryTree(rightChild, mid + 1, end, L, R);
    }

public:
    SegmentTreePointUpdate(const vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n, 0);
        if (n > 0) build(0, 0, n - 1, nums);
    }

    void update(int index, int val) {
        updateTree(0, 0, n - 1, index, val);
    }

    long long sumRange(int left, int right) const {
        return queryTree(0, 0, n - 1, left, right);
    }
};

// =============================================================================
// 2. Segment Tree with Lazy Propagation (Range Updates & Range Sum Queries)
// Allows updating an entire range [L, R] by +delta in O(log N) time!
// Time Complexity: Build: O(N), Range Update: O(log N), Range Query: O(log N)
// Space Complexity: 4 * N for tree + 4 * N for lazy tags
// =============================================================================
class SegmentTreeLazy {
private:
    int n;
    vector<long long> tree;
    vector<long long> lazy;

    void build(int node, int start, int end, const vector<int>& nums) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        }

        int mid = start + (end - start) / 2;
        int left = 2 * node + 1, right = 2 * node + 2;

        build(left, start, mid, nums);
        build(right, mid + 1, end, nums);

        tree[node] = tree[left] + tree[right];
    }

    void pushDown(int node, int start, int end) {
        if (lazy[node] == 0) return;

        int mid = start + (end - start) / 2;
        int left = 2 * node + 1, right = 2 * node + 2;

        // Apply pending updates to children
        tree[left] += lazy[node] * (mid - start + 1);
        lazy[left] += lazy[node];

        tree[right] += lazy[node] * (end - mid);
        lazy[right] += lazy[node];

        lazy[node] = 0; // Clear parent lazy tag
    }

    void updateRangeTree(int node, int start, int end, int L, int R, long long delta) {
        if (R < start || L > end) return;

        if (L <= start && end <= R) {
            tree[node] += delta * (end - start + 1);
            lazy[node] += delta;
            return;
        }

        pushDown(node, start, end);

        int mid = start + (end - start) / 2;
        int left = 2 * node + 1, right = 2 * node + 2;

        updateRangeTree(left, start, mid, L, R, delta);
        updateRangeTree(right, mid + 1, end, L, R, delta);

        tree[node] = tree[left] + tree[right];
    }

    long long queryRangeTree(int node, int start, int end, int L, int R) {
        if (R < start || L > end) return 0;

        if (L <= start && end <= R) return tree[node];

        pushDown(node, start, end);

        int mid = start + (end - start) / 2;
        int left = 2 * node + 1, right = 2 * node + 2;

        return queryRangeTree(left, start, mid, L, R) +
               queryRangeTree(right, mid + 1, end, L, R);
    }

public:
    SegmentTreeLazy(const vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        if (n > 0) build(0, 0, n - 1, nums);
    }

    void updateRange(int left, int right, long long delta) {
        updateRangeTree(0, 0, n - 1, left, right, delta);
    }

    long long queryRange(int left, int right) {
        return queryRangeTree(0, 0, n - 1, left, right);
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11};

    cout << "=== Point Update Segment Tree ===\n";
    SegmentTreePointUpdate st(nums);
    cout << "Initial sumRange(1, 3): " << st.sumRange(1, 3) << " (Expected: 3+5+7 = 15)\n";
    st.update(1, 10); // nums becomes {1, 10, 5, 7, 9, 11}
    cout << "After update(1, 10), sumRange(1, 3): " << st.sumRange(1, 3) << " (Expected: 10+5+7 = 22)\n";

    cout << "\n=== Lazy Propagation Segment Tree ===\n";
    SegmentTreeLazy lazyST(nums);
    cout << "Initial sumRange(0, 2): " << lazyST.queryRange(0, 2) << " (Expected: 1+3+5 = 9)\n";
    lazyST.updateRange(1, 3, 10); // Add 10 to indices 1, 2, 3
    cout << "After updateRange(1, 3, +10), queryRange(0, 3): "
         << lazyST.queryRange(0, 3) << " (Expected: 1+13+15+17 = 46)\n";

    return 0;
}

