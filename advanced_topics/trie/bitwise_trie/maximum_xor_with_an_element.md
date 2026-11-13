# Maximum XOR With an Element From Array (Offline Queries)

## Problem Statement
You are given an array `nums` consisting of non-negative integers. You are also given a `queries` array, where `queries[i] = [x_i, m_i]`.

The answer to the $i$-th query is the **maximum bitwise XOR value** of $x_i$ and any $\text{nums}[j]$ such that:
$$\text{nums}[j] \le m_i$$
If all elements in `nums` are strictly greater than $m_i$, then the answer to that query is `-1`.

Return an integer array `answer` where `answer[i]` is the answer to the $i$-th query.

```
Input: nums = [0, 1, 2, 3, 4], queries = [[3, 1], [1, 3], [5, 6]]
Output: [3, 3, 7]

Explanation:
1) Query [3, 1]: Available elements <= 1 are {0, 1}.
   3 ^ 0 = 3, 3 ^ 1 = 2 -> Max = 3.
2) Query [1, 3]: Available elements <= 3 are {0, 1, 2, 3}.
   1 ^ 2 = 3 (or 1 ^ 0 = 1, 1 ^ 1 = 0, 1 ^ 3 = 2) -> Max = 3.
3) Query [5, 6]: Available elements <= 6 are {0, 1, 2, 3, 4}.
   5 ^ 2 = 7 -> Max = 7.
```

---

## 1. Algorithmic Approach (Offline Processing + Dynamic Bitwise Trie)

### The Offline Query Paradigm
Notice that queries can be answered in **any order**, provided we place each answer back into its original index:
- If we process queries sorted by increasing $m_i$, the threshold condition $\text{nums}[j] \le m_i$ is **monotonically expanding**!
- As $m_i$ increases, we only ever **insert new elements into the Trie**, never having to delete elements!

### Step-by-Step Algorithm
1. **Sort `nums`** in ascending order.
2. **Reformat and Sort Queries:**
   - Store each query as a tuple: $(m_i, x_i, \text{original\_index})$.
   - Sort these query tuples in ascending order of $m_i$.
3. **Two-Pointer Monotonic Trie Insertion:**
   - Maintain a pointer `numIdx = 0` into the sorted `nums` array.
   - For each sorted query $(m_i, x_i, \text{idx})$:
     - While `numIdx < nums.size()` and `nums[numIdx] <= mi`:
       - Insert `nums[numIdx]` into the Binary Trie.
       - Increment `numIdx++`.
     - If the Trie is empty (i.e., `numIdx == 0`, meaning no element $\le m_i$ exists):
       - `result[idx] = -1`.
     - Else:
       - Query the Trie: `result[idx] = trie.getMaxXor(xi)`.
4. Return `result`.

---

## 2. Complexity Analysis
- **Time Complexity:** $O(N \log N + Q \log Q + 32(N + Q))$:
  - Sorting `nums`: $O(N \log N)$.
  - Sorting `queries`: $O(Q \log Q)$.
  - Inserting each of the $N$ numbers into the Trie: $32 \times N$.
  - Querying each of the $Q$ queries in the Trie: $32 \times Q$.
- **Space Complexity:** $O(32 \cdot N + Q)$ — Trie nodes storage and auxiliary query tuple vector.

