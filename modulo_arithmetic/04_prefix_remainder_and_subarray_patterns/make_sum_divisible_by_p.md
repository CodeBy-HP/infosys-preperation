# Problem 11: Make Sum Divisible by P (LeetCode 1590)

## Problem Statement

Given an array of positive integers `nums` and a positive integer `p`, remove the **smallest non-empty subarray** (possibly empty) such that the sum of the remaining elements is **divisible by $p$**. It is not allowed to remove the whole array.

Return the **length of the shortest subarray** that you need to remove, or `-1` if it's impossible.

---

## Examples

### Example 1
- **Input:** `nums = [3, 1, 4, 2]`, `p = 6`
- **Output:** `1`
- **Explanation:** Total sum = 10, $10 \pmod 6 = 4$. Removing `[4]` leaves `[3, 1, 2]` with sum 6, which is divisible by 6.

### Example 2
- **Input:** `nums = [6, 3, 5, 2]`, `p = 9`
- **Output:** `2`
- **Explanation:** Total sum = 16, $16 \pmod 9 = 7$. Removing `[5, 2]` leaves `[6, 3]` with sum 9.

### Example 3
- **Input:** `nums = [1, 2, 3]`, `p = 3`
- **Output:** `0`
- **Explanation:** Sum = 6, already divisible by 3.

---

## Mathematical Formulation: Remainder Target Matching

Let the total sum modulo $p$ be:
$$\text{rem\_total} = \sum_{i=0}^{n-1} \text{nums}[i] \pmod p$$

If $\text{rem\_total} == 0$, the array is already divisible; return `0`.

Otherwise, we must remove a subarray $[L, R]$ with sum $S_{\text{sub}}$ such that:
$$(\text{Total} - S_{\text{sub}}) \equiv 0 \pmod p \iff S_{\text{sub}} \equiv \text{rem\_total} \pmod p$$

The sum of subarray $[L, R]$ is $P[R] - P[L - 1]$ (where $P$ is the prefix sum):
$$(P[R] - P[L - 1]) \equiv \text{rem\_total} \pmod p$$

Rearranging for the required prefix remainder at index $L - 1$:
$$P[L - 1] \equiv (P[R] - \text{rem\_total}) \pmod p$$

Normalizing for negative remainders:
$$\text{target\_rem} = ((P[R] - \text{rem\_total}) \pmod p + p) \pmod p$$

### Finding the Shortest Subarray:
To **minimize** the length of the removed subarray $(R - (L - 1))$, we want the index $L - 1$ to be as **close to $R$ as possible** (i.e., the most recent index where `target_rem` occurred).
- We maintain a hash map: `last_seen[remainder] = index`.
- Base case: `last_seen[0] = -1`.

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $\mathcal{O}(N)$ single pass |
| **Space Complexity** | $\mathcal{O}(\min(N, p))$ hash map space |

