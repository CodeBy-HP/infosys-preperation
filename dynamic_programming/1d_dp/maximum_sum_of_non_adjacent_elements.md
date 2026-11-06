# Maximum Sum of Non-Adjacent Elements

## Problem Overview
Given an array of $N$ integers, find the maximum sum of a subsequence such that no two elements in the chosen subsequence are adjacent in the original array.
(Also known as the canonical linear Stickler Thief / House Robber formulation).

---

## Recurrence Formulation
At index $i$, we have two choices:
1. **Pick element $i$:** We cannot pick element $i-1$, so we transition to $i-2$:
   $$\text{pick} = \text{nums}[i] + (i \ge 2 \; ? \; dp[i-2] : 0)$$
2. **Not pick element $i$:** We can freely pick from $i-1$:
   $$\text{not\_pick} = dp[i-1]$$

Thus:
$$dp[i] = \max(\text{nums}[i] + dp[i-2], \; dp[i-1])$$

---

## Complexity Analysis
- **Brute Force (Recursion):** $O(2^N)$ Time, $O(N)$ Space.
- **Tabulation:** $O(N)$ Time, $O(N)$ Space.
- **Space-Optimized Tabulation:** $O(N)$ Time, $O(1)$ Space using two rolling state variables.

