# Assign Cookies (LeetCode 455)

## Problem Overview
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
Each child $i$ has a greed factor `g[i]`, which is the minimum size of a cookie that the child will be content with.
Each cookie $j$ has a size `s[j]`. If `s[j] >= g[i]`, we can assign the cookie $j$ to the child $i$, and the child will be content.
Your goal is to **maximize the number of your content children** and output the maximum number.

---

## Greedy Two-Pointer Invariant
To maximize the number of content children, we should **satisfy the least greedy child with the smallest possible cookie that suffices**:
1. Sort both the greed factors array `g` and the cookie sizes array `s` in ascending order.
2. Initialize two pointers: `child = 0` and `cookie = 0`.
3. While `child < g.size()` and `cookie < s.size()`:
   - If `s[cookie] >= g[child]`: The current cookie satisfies the current child! Advance both `child++` and `cookie++`.
   - Else: The current cookie is too small for this child (and thus too small for all subsequent greedier children). Advance `cookie++` to try a larger cookie.
4. When the loop terminates, `child` represents the maximum number of satisfied children.

---

## Complexity Analysis
- **Time Complexity:** $O(N \log N + M \log M)$ to sort both arrays of sizes $N$ and $M$.
- **Space Complexity:** $O(1)$ auxiliary space (ignoring sorting recursion stack).

