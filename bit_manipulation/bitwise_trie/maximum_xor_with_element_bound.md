# Maximum XOR With an Element From Array (LeetCode 1707)

## Problem Statement
You are given an array `nums` consisting of non-negative integers. You are also given a `queries` array, where `queries[i] = [x_i, m_i]`.

The answer to the $i$-th query is the maximum bitwise `XOR` value of $x_i$ and any `nums[j]` such that `nums[j] <= m_i`. In other words, the answer is $\max(nums[j] \oplus x_i)$ for all $j$ such that $nums[j] \le m_i$. If all elements in `nums` are larger than $m_i$, then the answer is `-1`.

Return an array `answer` where `answer.length == queries.length` and `answer[i]` is the answer to the $i$-th query.

### Example 1:
```
Input: nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
Output: [3,3,7]
Explanation:
1) 0 and 1 are <= 1. 0^3 = 3, 1^3 = 2. Maximum is 3.
2) 0, 1, 2, 3 are <= 3. Maximum is 1^2 = 3.
3) 0, 1, 2, 3, 4 are <= 6. Maximum is 5^2 = 7.
```

### Constraints:
- `1 <= nums.length, queries.length <= 10^5`
- `queries[i].length == 2`
- `0 <= nums[j], x_i, m_i <= 10^9`

---

## Pattern Insight: Offline Query Sorting + Dynamic Trie Insertion
- Online queries with bounds would require persistent Tries or complex subtree min tracking.
- **Offline Strategy:**
  1. Sort `nums` in ascending order.
  2. Index all queries: `{m_i, x_i, original_index}` and sort by $m_i$ ascending.
  3. Maintain a pointer `p` in `nums`. For each query $[x_i, m_i]$:
     - As long as `nums[p] <= m_i`, insert `nums[p]` into the Binary Trie and increment `p`.
     - All numbers currently in the Trie are guaranteed to satisfy $\le m_i$!
     - If the Trie is empty (i.e. `p == 0`), output `-1`.
     - Otherwise, query Trie for maximum XOR with $x_i$.
  4. Write results back to `original_index`.

---

## Complexity
- **Time Complexity:** $O(N \log N + Q \log Q + 31(N + Q))$ optimal.
- **Space Complexity:** $O(31 \cdot N + Q)$ for Trie and offline queries.
