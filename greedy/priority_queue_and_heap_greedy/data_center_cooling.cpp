#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct HeatComparator {
    // Defines max-heap order: highest heat first; ties broken by smallest index
    bool operator()(const pair<long long, int>& a, const pair<long long, int>& b) const {
        if (a.first == b.first) {
            return a.second > b.second; // Smaller index has higher priority
        }
        return a.first < b.first;       // Larger value has higher priority
    }
};

class DataCenterCooling {
private:
    int n;
    int d;
    vector<long long> H;

public:
    DataCenterCooling(int n, int d, const vector<long long>& heat) : n(n), d(d), H(heat) {}

    void update(int pos, long long value) {
        if (pos >= 0 && pos < n) {
            H[pos] = value;
        }
    }

    // =========================================================================
    // Query Execution using Priority Queue (Max-Heap)
    // =========================================================================
    long long query(int l, int r, int k, long long critical) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, HeatComparator> pq;

        for (int i = l; i <= r; i++) {
            pq.push({H[i], i});
        }

        vector<bool> invalidated(n, false);
        long long queryReduction = 0;
        int selectedCount = 0;

        while (!pq.empty() && selectedCount < k) {
            auto [heat, idx] = pq.top();
            pq.pop();

            if (invalidated[idx]) continue;

            selectedCount++;
            if (heat >= critical) {
                queryReduction += heat * 4;
            } else {
                queryReduction += heat;
            }

            // Invalidate interval [idx - d + 1, idx + d - 1]
            int startIdx = max(0, idx - d + 1);
            int endIdx = min(n - 1, idx + d - 1);
            for (int i = startIdx; i <= endIdx; i++) {
                invalidated[i] = true;
            }
        }

        return queryReduction;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;
    if (!(cin >> n >> d)) return 0;

    vector<long long> H(n);
    for (int i = 0; i < n; i++) cin >> H[i];

    int q;
    if (!(cin >> q)) return 0;

    DataCenterCooling system(n, d, H);
    long long totalReduction = 0;

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int pos;
            long long val;
            cin >> pos >> val;
            system.update(pos, val);
        } else if (type == 2) {
            int l, r, k;
            long long critical;
            cin >> l >> r >> k >> critical;
            totalReduction += system.query(l, r, k, critical);
        }
    }

    cout << totalReduction << "\n";
    return 0;
}

