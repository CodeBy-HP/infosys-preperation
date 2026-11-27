// 1.  Binary Search + Pruned Backtracking ($N <= 15)
// T.C. days^N

// Prunning Technique used
// --- Sort weights descending: Heavy packages are the hardest to fit—placing them first causes invalid branches to fail immediately.
// --- Break on an empty bucket: If placing a package into an empty bucket (buckets[i] == 0) fails, every remaining empty bucket will also fail—break immediately.

bool dfs(int idx, const vector<int>& weights, vector<int>& buckets, int cap) {
    if (idx == weights.size()) return true;

    for (int i = 0; i < buckets.size(); i++) {
        if (buckets[i] + weights[idx] > cap) continue;

        buckets[i] += weights[idx];
        if (dfs(idx + 1, weights, buckets, cap)) return true;
        buckets[i] -= weights[idx];

        // Pruning: if an empty bucket didn't work, no other empty bucket will
        if (buckets[i] == 0) break;
    }
    return false;
}

// Little Optimised with Prunning

// --- Skip duplicate bucket states: If two buckets currently have the exact same load, trying the second one is redundant.

// T.C. days^N * days^2

bool LittleOptimdfs(int idx, const vector<int>& weights, vector<int>& buckets, int cap) {
    if (idx == weights.size()) return true;

    for (int i = 0; i < buckets.size(); i++) {
        if (buckets[i] + weights[idx] > cap) continue;

        // Rule 2: Skip duplicate bucket states
        bool seen = false;
        for (int j = 0; j < i; j++) {
            if (buckets[j] == buckets[i]) {
                seen = true;
                break;
            }
        }
        if (seen) continue;

        buckets[i] += weights[idx];
        if (dfs(idx + 1, weights, buckets, cap)) return true;
        buckets[i] -= weights[idx];

        // Rule 3: Break on empty bucket
        if (buckets[i] == 0) break;
    }
    return false;
}

bool canPack(vector<int>& weights, int cap, int days) {
    sort(weights.rbegin(), weights.rend()); // Largest first to fail fast
    vector<int> buckets(days, 0);
    return dfs(0, weights, buckets, cap);
}


// 2. Bitmasking
bool canPackBitmask(const vector<int>& weights, int cap, int maxDays) {
    int n = weights.size();
    int full = (1 << n) - 1;
    // {daysUsed, currentLoad}
    vector<pair<int, int>> dp(1 << n, {INT_MAX, INT_MAX});
    dp[0] = {1, 0};

    for (int mask = 0; mask <= full; mask++) {
        auto [d, load] = dp[mask];
        if (d > maxDays) continue;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) continue; // Already packed
            int nextMask = mask | (1 << i);

            pair<int, int> candidate = (load + weights[i] <= cap)
                ? make_pair(d, load + weights[i])
                : make_pair(d + 1, weights[i]);

            dp[nextMask] = min(dp[nextMask], candidate);
        }
    }

    return dp[full].first <= maxDays;
}



