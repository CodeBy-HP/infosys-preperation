#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// time complexity
// q*n^2*t

// space complexity
// n space complexity

void brute_force()
{
    string s;
    cin >> s;

    int q;
    cin >> q;

    auto match = [&](int ind, string &t)
    {
        for (int i = 0; i < t.size(); i++)
        {
            if (s[ind + i] != t[i])
            {
                return false;
            }
        }
        return true;
    };

    int n = s.size();

    long long total_sum = 0;

    while (q--)
    {
        string t;
        cin >> t;

        string res = "";

        if (t.size() > s.size())
            continue;

        for (int i = 0; i <= n - t.size(); i++)
        {

            if (match(i, t))
            {
                string suffix = s.substr(i);
                if (res == "")
                {
                    res = suffix;
                }
                else
                {
                    res = min(res, suffix);
                }
            }
        }

        total_sum = (total_sum + res.size()) % MOD;
    }

    cout << total_sum;
}

// Suffix Array construction using Prefix Doubling: O(N log^2 N)
vector<int> buildSuffixArray(const string &s)
{
    int n = s.length();
    vector<int> sa(n), rank(n), temp_rank(n);

    // Step 1: Rank by Length 1 (using ASCII values as initial ranks)
    for (int i = 0; i < n; i++)
    {
        sa[i] = i;
        rank[i] = s[i];
    }

    // Step 2: Double the length k at each step (k = 1, 2, 4, 8...)
    for (int k = 1; k < n; k *= 2)
    {

        // This comparator perfectly mimics our integer pair logic: (Rank[i], Rank[i+k])
        auto cmp = [&](int a, int b)
        {
            if (rank[a] != rank[b])
            {
                return rank[a] < rank[b]; // Compare Left Halves
            }
            // If Left Halves tie, evaluate Right Halves (handling Out-of-Bounds as -1)
            int rank_a_right = (a + k < n) ? rank[a + k] : -1;
            int rank_b_right = (b + k < n) ? rank[b + k] : -1;
            return rank_a_right < rank_b_right;
        };

        // Sort the indices based on the integer pairs
        sort(sa.begin(), sa.end(), cmp);

        // Assign new integer ranks based on the sorted order
        temp_rank[sa[0]] = 0;
        for (int i = 1; i < n; i++)
        {
            // If cmp returns false, they are tied, so they get the exact same rank
            // If cmp returns true, the current one is larger, so rank increases by 1
            temp_rank[sa[i]] = temp_rank[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
        }

        for (int i = 0; i < n; i++)
        {
            rank[i] = temp_rank[i];
        }

        // Optimization: If all ranks are mathematically unique, array is completely sorted
        if (rank[sa[n - 1]] == n - 1)
        {
            break;
        }
    }
    return sa;
}

// Binary search to find the lexicographically smallest suffix starting with T: O(|T| log N)
int getMinSuffixLength(const string &s, const vector<int> &sa, const string &t)
{
    int n = s.length();
    int m = t.length();
    int L = 0, R = n - 1;
    int best_idx = -1;

    while (L <= R)
    {
        int mid = L + (R - L) / 2;
        int suffix_start = sa[mid];

        int cmp_val = 0;
        for (int i = 0; i < m; i++)
        {
            if (suffix_start + i >= n)
            {
                cmp_val = -1; // Suffix is too short, inherently smaller
                break;
            }
            if (s[suffix_start + i] != t[i])
            {
                cmp_val = (s[suffix_start + i] < t[i]) ? -1 : 1;
                break;
            }
        }

        if (cmp_val < 0)
        {
            L = mid + 1; // Suffix is smaller, search right
        }
        else if (cmp_val > 0)
        {
            R = mid - 1; // Suffix is larger, search left
        }
        else
        {
            // Perfect match! Record it and aggressively search left to ensure it is the FIRST one.
            best_idx = mid;
            R = mid - 1;
        }
    }

    if (best_idx != -1)
    {
        return n - sa[best_idx]; // Return the length of the matched suffix
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    // Proper input parsing alignment: N, then Q, then S
    if (!(cin >> n >> q))
        return 0;

    string s;
    cin >> s;

    // Phase 1: Precompute the Suffix Array ONCE
    vector<int> sa = buildSuffixArray(s);
    long long total_len = 0;

    // Phase 2: Resolve Queries
    while (q--)
    {
        string t;
        cin >> t;

        if (t.size() > s.size())
        {
            continue;
        }

        int len = getMinSuffixLength(s, sa, t);
        total_len = (total_len + len) % MOD;
    }

    cout << total_len << "\n";
    return 0;
}