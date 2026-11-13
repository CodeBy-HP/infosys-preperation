# Problem: Missing Number (LeetCode 268)

## Problem Statement

Given an array `nums` containing $n$ distinct numbers in the range $[0, n]$, return the **only number** in the range that is missing from the array.

---

## Examples

### Example 1
- **Input:** `nums = [3, 0, 1]`
- **Output:** `2`
- **Explanation:** $n = 3$ since there are 3 numbers, so all numbers are in the range $[0, 3]$. 2 is the missing number in the range since it does not appear in nums.

### Example 2
- **Input:** `nums = [0, 1]`
- **Output:** `2`

### Example 3
- **Input:** `nums = [9, 6, 4, 2, 3, 5, 7, 0, 1]`
- **Output:** `8`

---

## Constraints

- $n == \text{nums.length}$
- $1 \le n \le 10^4$
- $0 \le \text{nums}[i] \le n$
- All the numbers of `nums` are unique.

---

## Approaches

### Approach 1: Hash Set / Frequency Array (Brute Force)
Store all elements in a hash set or boolean array. Check which number from $0$ to $n$ is not present.
- **Time Complexity:** $\mathcal{O}(N)$
- **Space Complexity:** $\mathcal{O}(N)$

### Approach 2: Mathematical Sum Formula (Better)
The expected sum of numbers from $0$ to $n$ is:
$$\text{Expected Sum} = \frac{n(n + 1)}{2}$$
Subtract the actual sum of `nums`:
$$\text{Missing} = \text{Expected Sum} - \sum_{i=0}^{n-1} \text{nums}[i]$$
- **Time Complexity:** $\mathcal{O}(N)$
- **Space Complexity:** $\mathcal{O}(1)$
- **Limitation:** $n(n+1)$ can cause 32-bit integer overflow when $n \ge 10^5$.

### Approach 3: Bitwise XOR Invariant (Optimal)
XOR has two fundamental algebraic properties:
1. $x \oplus x = 0$ (self-inverse)
2. $x \oplus 0 = x$ (identity)

If we XOR all numbers in $[0, n]$ together with all elements in `nums`, every number present in `nums` will appear exactly twice and cancel out to $0$, leaving **strictly the missing number**:
$$\text{ans} = \left( \bigoplus_{i=0}^{n} i \right) \oplus \left( \bigoplus_{x \in \text{nums}} x \right)$$
- **Time Complexity:** $\mathcal{O}(N)$
- **Space Complexity:** $\mathcal{O}(1)$
- **Advantage:** Never overflows registers!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Overflow Risk |
| :--- | :--- | :--- | :--- |
| **Hash Set** | $\mathcal{O}(N)$ | $\mathcal{O}(N)$ | None |
| **Math Sum** | $\mathcal{O}(N)$ | $\mathcal{O}(1)$ | Moderate ($N \ge 10^5$) |
| **Bitwise XOR** | $\mathcal{O}(N)$ | $\mathcal{O}(1)$ | **Zero** |

