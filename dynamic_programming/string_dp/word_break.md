# Word Break (LeetCode 139)

## Problem Statement

Given a string `s` and a dictionary of strings `wordDict`, return `true` if `s` can be segmented into a space-separated sequence of one or more dictionary words.

**Note:**
- The same word in the dictionary may be reused multiple times in the segmentation.
- You may assume the dictionary does not contain duplicate words.

---

## Examples

### Example 1:
```text
Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation:
Return true because "leetcode" can be segmented as "leet code".
```

### Example 2:
```text
Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation:
Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
```

### Example 3:
```text
Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
```

---

## Constraints

- `1 <= s.length <= 300`
- `1 <= wordDict.length <= 1000`
- `1 <= wordDict[i].length <= 20`
- `s` and `wordDict[i]` consist of only lowercase English letters.
- All the strings of `wordDict` are **unique**.

---

## Recurrence Formulation & Algorithmic Approaches

### 1. State Definition
Let $dp[i]$ be a boolean value indicating whether the prefix $s[0 \dots i - 1]$ of length $i$ can be segmented into a valid sequence of dictionary words.

### 2. State Transition
To determine if prefix $s[0 \dots i - 1]$ can be segmented, inspect all potential split points $j \in [0, i - 1]$:
If:
1. The prefix $s[0 \dots j - 1]$ is valid ($dp[j] == \text{true}$), AND
2. The remaining suffix $s[j \dots i - 1]$ exists in `wordDict`.

Then:
$$dp[i] = \bigvee_{\substack{0 \le j < i \\ (i - j) \le L_{\max}}} \Big( dp[j] \land (s[j \dots i - 1] \in \text{wordDict}) \Big)$$
where $L_{\max} = \max_{w \in \text{wordDict}} |w|$ is the maximum word length in the dictionary. Pruning splits where $i - j > L_{\max}$ dramatically speeds up evaluation.

### 3. Base Case
- $dp[0] = \text{true}$ (the empty string prefix is valid).

### 4. Implementation
```cpp
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int n = s.length();
    int maxLen = 0;
    for (const string& w : wordDict) maxLen = max(maxLen, (int)w.length());

    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; ++i) {
        for (int len = 1; len <= min(i, maxLen); ++len) {
            int j = i - len;
            if (dp[j] && dict.count(s.substr(j, len))) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}
```

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **DP with Length Pruning** | $O(N \cdot L_{\max}^2)$ | $O(N)$ for DP table + $O(\sum |w|)$ for hash set |
| **Trie-Optimized DP** | $O(N \cdot L_{\max})$ | $O(N)$ for DP table + $O(\sum |w| \times 26)$ for Trie |
