# Minimum Insertion Steps to Make a String Palindrome (LeetCode 1312)

## Problem Statement

Given a string `s`, in one step you can insert any character at any position of the string.

Return the **minimum number of steps** to make `s` a palindrome.

A palindrome is a string that reads the same backward as forward.

---

## Examples

### Example 1:
```text
Input: s = "zzazz"
Output: 0
Explanation:
The string "zzazz" is already a palindrome, so no insertions needed.
```

### Example 2:
```text
Input: s = "mbadm"
Output: 2
Explanation:
String can be made "mbdadbm" or "mdbabdm" in 2 insertions.
```

### Example 3:
```text
Input: s = "leetcode"
Output: 5
Explanation:
Inserting 5 characters produces "leetcodocteel", which is a palindrome.
```

---

## Constraints

- `1 <= s.length <= 500`
- `s` consists of lowercase English letters.

---

## Recurrence Formulation & Algorithmic Approaches

### 1. Invariant & LPS Reduction
To minimize the number of characters inserted into $s$, we should keep as many existing characters as possible to form the palindromic spine.
The largest symmetrical subsequence already contained in $s$ is its **Longest Palindromic Subsequence (LPS)**.

Any character not in this LPS must have a matching partner inserted in the mirror position on the other side of the string.
Thus:
$$\text{Min Insertions} = |s| - \text{Length of LPS}(s)$$

Since $\text{LPS}(s) = \text{LCS}(s, \; \text{reverse}(s))$:
$$\text{Min Insertions} = |s| - \text{LCS}(s, \; \text{reverse}(s))$$

### 2. Space-Optimized Implementation
Compute $\text{LCS}(s, \text{rev}(s))$ using two rolling 1D arrays:
```cpp
string rev = s;
reverse(rev.begin(), rev.end());
int n = s.length();
vector<int> prev(n + 1, 0), curr(n + 1, 0);

for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
        if (s[i - 1] == rev[j - 1]) curr[j] = 1 + prev[j - 1];
        else curr[j] = max(prev[j], curr[j - 1]);
    }
    prev = curr;
}
return n - prev[n];
```

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Interval DP / LCS Tabulation** | $O(N^2)$ | $O(N^2)$ |
| **Space-Optimized (Rolling Rows)** | $O(N^2)$ | $O(N)$ |
