# Keep In Mind Sheet: Tricky DSA Patterns & Quick Revision

> A cheat sheet of non-obvious problem patterns, mathematical transformations, and concise code snippets to revise before interviews and contests.

---

## 1. Core C++ Syntactic Tools & Data Structures

### Recursive Lambda Function
Avoids writing separate global helper functions or passing many references.
```cpp
// C++14/17 generic lambda recursion: pass `self` as parameter
auto dfs = [&](int u, int p, auto& self) -> int {
    int res = 0;
    // self(neighbor, u, self);
    return res;
};

// Calling it:
int ans = dfs(0, -1, dfs);
```

### Policy-Based Data Structure (PBDS) — Ordered Set & Ordered Map
Used when you need $O(\log N)$ dynamic insertions, deletions, **and**:
1. `find_by_order(k)`: Find iterator to $k$-th smallest element (0-indexed).
2. `order_of_key(x)`: Count elements strictly smaller than $x$.
*Note: Use `pair<int, int>` as element type to handle duplicates (multiset behavior).*

```cpp
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// Ordered Map: Key -> Value
typedef tree<
    int,
    int,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_map;

// Ordered Set (with pair to allow duplicate elements)
typedef tree<
    pair<int, int>,
    null_type,
    less<pair<int, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;

// Usage:
ordered_set st;
st.insert({val, idx}); // unique by index
auto it = st.find_by_order(k); // k-th smallest element
int smaller_count = st.order_of_key({x, -1}); // elements strictly less than x
st.erase({val, idx});
```

### Fast Array Lookup vs `unordered_map`
When mapping digits `'0'`-`'9'` or lowercase `'a'`-`'z'`, always prefer a static flat array over `unordered_map` to eliminate hash collisions and heap allocations.
```cpp
// Phone keypad max presses (e.g. 7 and 9 have 4 letters, rest have 3)
const int max_press[10] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
int limit = max_press[digit - '0'];
```

---

## 2. Mathematical Transformations & Reductions

### Difference Modulo Equivalence (Pair Counting)
- **Problem**: Count pairs $(i, j)$ where `(a[i] + a[j]) % D == 0` and `|a[i] - a[j]| % M == 0`.
- **Aha! Intuition**: 
  1. `|a - b| % M == 0` is mathematically equivalent to `a % M == b % M` (they share the exact same remainder modulo $M$).
  2. `(a + b) % D == 0` means `b % D == (D - (a % D)) % D`.
  3. Instead of checking all pairs in $O(N^2)$, map each number to a 2D bucket key `(remD, remM)` and count matches in $O(N)$.
```cpp
map<pair<int, int>, int> freq;
long long valid_pairs = 0;

for (int x : arr) {
    int remD = (x % D + D) % D;
    int remM = (x % M + M) % M;
    int reqD = (D - remD) % D; // needed complement modulo D

    if (freq.count({reqD, remM})) {
        valid_pairs += freq[{reqD, remM}];
    }
    freq[{remD, remM}]++;
}
```

### Delta / Baseline Sorting (Exchange Argument)
- **Problem**: 2-way distribution (e.g. Two City Scheduling: assign $N$ employees to City A and $N$ to City B).
- **Aha! Intuition**:
  - Don't jump to 2D DP! Start with a default baseline: assume **everyone** is sent to City A.
  - The net cost change of sending person $i$ to City B instead is:
    $$\Delta_i = \text{costB}[i] - \text{costA}[i]$$
  - Sort all candidates by $\Delta_i$ in ascending order and pick the $N$ smallest deltas to redirect to City B.
```cpp
long long total = 0;
vector<int> delta(2 * n);
for (int i = 0; i < 2 * n; i++) {
    total += costA[i]; // baseline
    delta[i] = costB[i] - costA[i];
}
sort(delta.begin(), delta.end());
for (int i = 0; i < n; i++) {
    total += delta[i]; // apply best n transitions
}
```

### The "Tollbooth" / Obstacle-Jump Pattern (Adjacent Swaps to Group)
- **Problem**: Find the minimum adjacent swaps to group all identical characters (e.g. all `'1'`s or all `'0'`s) into one contiguous block.
- **Aha! Intuition**:
  - Instead of tracking which `'1'` moves where, invert the perspective: **inspect each obstacle character (`'0'`)**.
  - Every `'0'` sitting between `'1'`s splits them into two sides: `'1'`s on its left (`count_left`) and `'1'`s on its right (`total - count_left`).
  - To bring the `'1'`s together, the smaller group of `'1'`s will jump over this `'0'`.
  - Every obstacle `'0'` acts like a **tollbooth**: it collects $1$ swap for each `'1'` jumping past it:
    $$\text{toll} = \min(\text{count\_1\_left},\; \text{total\_1} - \text{count\_1\_left})$$
  - Sum the tolls over all `'0'`s in a single $O(N)$ pass with $O(1)$ extra space!
```cpp
long long swaps_1 = 0; // Cost to group all '1's together
int count_1_left = 0;

for (char c : s) {
    if (c == '1') {
        count_1_left++;
    } else {
        // '0' is the obstacle: smaller group of '1's jumps over it
        swaps_1 += min(count_1_left, total_1 - count_1_left);
    }
}
```

### Median on Transformed Coordinates $P[i] - i$ (Clustering Elements)
- **Problem**: Minimum adjacent swaps to gather $K$ elements at original indices $P[0], P[1], \dots, P[K-1]$ into any contiguous block $[S, S + K - 1]$.
- **Aha! Intuition**:
  - Target final positions are $S + i$ for $i = 0 \dots K - 1$.
  - Total swaps formula:
    $$\sum_{i=0}^{K-1} |P[i] - (S + i)| = \sum_{i=0}^{K-1} |(P[i] - i) - S|$$
  - Let transformed coordinate $A[i] = P[i] - i$.
  - Minimizing $\sum |A[i] - S|$ is the classic **median property**: absolute distance $\sum |x - S|$ is mathematically minimized when $S$ is the **median** of array $A$!
```cpp
vector<int> A;
for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
        A.push_back(i - (int)A.size()); // original_index - rank
    }
}

// Optimal start position aligns with the median of A:
int median = A[A.size() / 2];
long long min_swaps = 0;
for (int val : A) {
    min_swaps += abs(median - val);
}
```

---

## 3. Sliding Window & Boundary Tricks

### Wall Padding on Boundary Constraints (Event Gaps)
- **Problem**: Given $N$ total days ($N \le 10^9$) and $M$ scheduled obligations, find maximum consecutive free days after canceling at most $K$ obligations.
- **Aha! Intuition**:
  - Never iterate through days $1 \dots N$. The only points that matter are the $M$ obligations.
  - Add virtual "uncancelable walls" at `day 0` and `day N + 1`.
  - Canceling $K$ obligations between index $i$ and $i + K + 1$ merges the days between them into one continuous vacation of length:
    $$\text{days} = \text{arr}[i + K + 1] - \text{arr}[i] - 1$$
```cpp
vector<int> obs = {0}; // left wall
for (int d : obligations) obs.push_back(d);
obs.push_back(N + 1);  // right wall
sort(obs.begin(), obs.end());

int max_vacation = 0;
for (int i = 0; i + K + 1 < obs.size(); i++) {
    max_vacation = max(max_vacation, obs[i + K + 1] - obs[i] - 1);
}
```

### Small Value Range Frequency Bucket vs Balanced BST
- **Problem**: Sliding window of size $K$ to query the $x$-th smallest value (e.g., LeetCode 2653).
- **Aha! Intuition**:
  - When numbers fall in a tight range (e.g., $[-50, 50]$), PBDS or heaps ($O(\log K)$) are slower and heavier than necessary.
  - Use a fixed array `freq[101]` with an offset `+ 50`.
  - Sliding the window is $O(1)$, and finding the $x$-th smallest element takes at most $50$ iterations.
```cpp
int freq[105] = {0};
// Window query:
auto get_kth_smallest_negative = [&](int x) {
    int count = 0;
    for (int v = 0; v < 50; v++) { // values: v - 50 < 0
        count += freq[v];
        if (count >= x) return v - 50;
    }
    return 0;
};
// In sliding loop:
freq[arr[i - k] + 50]--;
freq[arr[i] + 50]++;
```

### "Exactly K" via "At Most K" Reduction
- **Problem**: Count contiguous subarrays with **exactly $K$** distinct elements / odds / conditions.
- **Aha! Intuition**:
  - Sliding window conditions must be monotonic (expanding right only adds, shrinking left only removes).
  - "At most $K$" is monotonic, but "exactly $K$" is NOT.
  - Use the universal identity:
    $$\text{countExactly}(K) = \text{countAtMost}(K) - \text{countAtMost}(K - 1)$$
```cpp
auto atMostK = [&](int k) -> long long {
    if (k < 0) return 0;
    unordered_map<int, int> count;
    long long subarrays = 0;
    for (int r = 0, l = 0; r < n; r++) {
        if (count[arr[r]]++ == 0) k--;
        while (k < 0) {
            if (--count[arr[l]] == 0) k++;
            l++;
        }
        subarrays += (r - l + 1); // all valid subarrays ending at r
    }
    return subarrays;
};

long long answer = atMostK(k) - atMostK(k - 1);
```

### Monotonic Deque (Sliding Window Min/Max in $O(N)$)
- **Aha! Intuition**:
  - Maintain indices in a deque. Pop elements from the back if they are worse (e.g., smaller for max-window) than the current element, because they can never be the answer again.
  - The front always contains the index of the optimal element in the current window.
```cpp
deque<int> dq; // stores indices
for (int i = 0; i < n; i++) {
    // 1. Expire elements outside window [i - k + 1, i]
    if (!dq.empty() && dq.front() <= i - k) dq.pop_front();

    // 2. Maintain decreasing order
    while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
    dq.push_back(i);

    // 3. Front is the window maximum
    if (i >= k - 1) ans.push_back(nums[dq.front()]);
}
```

---

## 4. Range Updates & Greedy Steps

### Difference Array for $O(1)$ Range Additions
- **Aha! Intuition**: To add $V$ to all indices in range $[L, R]$ across $Q$ operations, do not touch every element. Mark endpoints in a difference array and run a single prefix sum at the end.
```cpp
vector<long long> diff(n + 2, 0);

// Query: Add v to range [l, r] (1-indexed)
diff[l] += v;
diff[r + 1] -= v;

// Final rebuild:
for (int i = 1; i <= n; i++) {
    diff[i] += diff[i - 1]; // diff[i] is now the final value at index i
}
```

### Greedy Coverage with Binary Search Fast-Forward
- **Problem**: Covering discrete sorted targets with variable reach units (e.g. Highway Amplifiers: normal covers $[x-r, x+r]$, super covers $[x-2r, x+2r]$).
- **Aha! Intuition**:
  - To cover the leftmost uncovered post $arr[i]$, the optimal position to place the amplifier is as far right as possible ($arr[i] + r$ or $arr[i] + 2r$).
  - Instead of stepping through posts one by one, jump straight to the next uncovered post with `upper_bound`:
```cpp
// Normal amplifier placed at arr[i] + r reaches arr[i] + 2*r
int next_idx_normal = upper_bound(arr.begin(), arr.end(), arr[i] + 2 * r) - arr.begin();

// Super amplifier placed at arr[i] + 2*r reaches arr[i] + 4*r
int next_idx_super  = upper_bound(arr.begin(), arr.end(), arr[i] + 4 * r) - arr.begin();
```

### Coordinate Compression (Mapping $10^9 \to 10^5$)
- **Aha! Intuition**: When values are huge (up to $10^9$) but you only care about relative order for Fenwick trees, Segment trees, or PBDS:
```cpp
vector<int> vals = arr;
sort(vals.begin(), vals.end());
vals.erase(unique(vals.begin(), vals.end()), vals.end());

// Get 0-indexed rank of any original value:
auto get_rank = [&](int val) {
    return lower_bound(vals.begin(), vals.end(), val) - vals.begin();
};
```

---

## 5. Dynamic Programming Patterns

### Precomputing Palindromes in $O(N^2)$ (Cleaner Iteration)
Precomputing all substring palindromes allows any palindrome partition DP to check substring validity in $O(1)$.
```cpp
vector<vector<bool>> is_pal(n, vector<bool>(n, false));

// Outer loop goes backward from n-1, inner loop goes forward from i
for (int i = n - 1; i >= 0; i--) {
    for (int j = i; j < n; j++) {
        if (s[i] == s[j] && (j - i < 3 || is_pal[i + 1][j - 1])) {
            is_pal[i][j] = true;
        }
    }
}
```

### 1D Suffix DP for Palindrome Partitioning II
- **Aha! Intuition**: 
  - Standard MCM 2D interval DP `dp[i][j]` is $O(N^3)$.
  - After precomputing `is_pal[i][j]`, define 1D DP `dp[i]` = min cuts for suffix $s[i \dots n-1]$.
  - Transition: For every $j \ge i$ where $s[i \dots j]$ is a palindrome, $dp[i] = \min(dp[i], 1 + dp[j + 1])$.
```cpp
vector<int> dp(n + 1, 0);
for (int i = n - 1; i >= 0; i--) {
    int min_parts = INT_MAX;
    for (int j = i; j < n; j++) {
        if (is_pal[i][j]) {
            min_parts = min(min_parts, 1 + dp[j + 1]);
        }
    }
    dp[i] = min_parts;
}
int min_cuts = dp[0] - 1; // cuts = substrings - 1
```

### Submask Enumeration Trick in $O(3^N)$
- **Problem**: Iterate over all submasks of all masks for Bitmask DP (e.g. SOS DP / traveling salesman / matching).
- **Aha! Intuition**: Naive nested iteration takes $O(4^N)$. The `sub = (sub - 1) & mask` trick skips non-submasks and achieves $O(3^N)$ total iterations across all masks.
```cpp
for (int mask = 0; mask < (1 << n); mask++) {
    // sub starts at mask, and decrements strictly through submasks
    for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
        // 'sub' is guaranteed to be a submask of 'mask'
    }
    // Handle sub = 0 case if needed
}
```