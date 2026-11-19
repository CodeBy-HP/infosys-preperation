# Count Occurrences in a Sorted Array

## Problem Statement

Given a sorted array `arr` of $N$ integers and an integer `target`, return the total number of times `target` occurs in `arr`.

If `target` does not appear in the array, return `0`.

---

## Examples

### Example 1
- **Input:** `arr = [1, 1, 2, 2, 2, 2, 3]`, `target = 2`
- **Output:** `4`
- **Explanation:** `2` appears 4 times at indices `2, 3, 4, 5`.

### Example 2
- **Input:** `arr = [1, 1, 2, 2, 2, 2, 3]`, `target = 4`
- **Output:** `0`
- **Explanation:** `4` is not present in the array.

### Example 3
- **Input:** `arr = [8, 9, 10, 12, 12, 12]`, `target = 12`
- **Output:** `3`

---

## Constraints

- $1 \le N \le 10^5$
- $1 \le \text{arr}[i], target \le 10^9$
- `arr` is sorted in non-decreasing order.

---

## Pattern Insight: Bound Subtraction

Instead of a linear scan which takes $O(N)$ time, we can utilize the sorted property to achieve **$O(\log N)$** time:
1. **Method A: First & Last Position via Binary Search**
   - Find the first index where $\text{arr}[i] == target$. If not found, return 0.
   - Find the last index where $\text{arr}[i] == target$.
   - $\text{count} = \text{last} - \text{first} + 1$.
2. **Method B: Upper Bound $-$ Lower Bound**
   - $\text{count} = \text{upper\_bound}(target) - \text{lower\_bound}(target)$.
   - Since both bounds operate in $O(\log N)$, the total runtime is $O(\log N)$.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Upper Bound $-$ Lower Bound** | $O(\log N)$ | $O(1)$ |
| **First and Last Occurrence Search** | $O(\log N)$ | $O(1)$ |
| **Linear Search** | $O(N)$ | $O(1)$ |

