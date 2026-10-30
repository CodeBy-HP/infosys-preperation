# Problem 6: Minimum Deletions to Make Character Frequencies Unique (LeetCode 1647)

## Problem Statement

A string `s` is called **good** if there are no two different characters in `s` that have the same frequency.

Given a string `s`, return the **minimum number of characters you need to delete** to make `s` good.

The frequency of a character in a string is the number of times it appears in the string. For example, in the string `"aab"`, the frequency of `'a'` is $2$, while the frequency of `'b'` is $1$.

---

## Examples

### Example 1
- **Input:** `s = "aab"`
- **Output:** `0`
- **Explanation:** `s` is already good because frequency of `'a'` is 2 and frequency of `'b'` is 1 (all distinct).

### Example 2
- **Input:** `s = "aaabbbcc"`
- **Output:** `2`
- **Explanation:** You can delete two `'b'`s resulting in the good string `"aaabcc"`.
  - Frequency of `'a'` = 3, `'c'` = 2, `'b'` = 1.
  - Another valid solution is deleting one `'b'` and one `'c'` resulting in `"aaabbc"`.

### Example 3
- **Input:** `s = "ceabaacb"`
- **Output:** `2`
- **Explanation:** You can delete both `'c'`s or delete one `'a'` and one `'c'`.

---

## Constraints

- $1 \le \text{s.length} \le 10^5$
- `s` contains only lowercase English letters.

---

## Greedy Logic: Collision Resolution

Because the alphabet size is constant ($\Sigma = 26$), resolving frequency conflicts can be done in $O(N)$ time.

### 1. Hash Set Greedy Resolution:
1. Count character occurrences in an array of size $26$.
2. Maintain a hash set `seen_frequencies`.
3. For each frequency `count`:
   - While `count > 0` and `seen_frequencies` already contains `count`:
     - Decrement `count--` (we must delete 1 character).
     - Increment `deletions++`.
   - If `count > 0`, insert `count` into `seen_frequencies`.

### 2. Sorting-Based Greedy (No Hash Set, $O(1)$ Space):
1. Sort the 26 frequencies in descending order.
2. For each frequency $i$ from $1$ to $25$:
   - If `freq[i] >= freq[i - 1]`:
     - We can keep at most $\max(0, \text{freq}[i - 1] - 1)$ occurrences.
     - Add `freq[i] - new_freq` to deletions.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Hash Set Greedy** | $O(N)$ | $O(\Sigma) = O(1)$ | Direct collision resolution |
| **Sorting-Based Greedy** | $O(N + \Sigma \log \Sigma) = O(N)$ | $O(1)$ | No hash set; sorts 26 numbers |
| **Max-Heap Greedy** | $O(N + \Sigma \log \Sigma) = O(N)$ | $O(1)$ | Repeatedly pulls duplicates |

