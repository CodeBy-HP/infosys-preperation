# Word Break

## Problem Overview
Given a string `s` and a dictionary of strings `wordDict`, return `true` if `s` can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.

---

## Prefix DP Formulation
Let $dp[i]$ denote whether the prefix $s[0 \dots i-1]$ of length $i$ can be segmented into dictionary words:
- **Base Case:** $dp[0] = \text{true}$ (empty prefix).
- **Transition:**
  For each $i \in [1, N]$, we check all potential split points $j \in [0, i-1]$:
  $$dp[i] = \bigvee_{0 \le j < i, \; (i - j) \le L_{\max}} \big(dp[j] \land (s[j \dots i - 1] \in \text{wordDict})\big)$$
  where $L_{\max}$ is the maximum word length in `wordDict` (pruning lookbacks longer than the longest dictionary word).

---

## Complexity Analysis
- **Time Complexity:** $O(N \cdot L_{\max}^2)$ where $N = |s|$ and $L_{\max}$ is the max word length.
- **Auxiliary Space:** $O(N)$ for the boolean DP array plus $O(\sum |w|)$ for the hash set.

