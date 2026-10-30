# Find The Original Array of Prefix XOR (LeetCode 2433)

## Problem Statement
You are given an integer array `pref` of size `n`. Find and return the array `arr` of size `n` that satisfies:
- `pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i]`.

Note that `^` denotes the bitwise-xor operation. It can be proven that the answer is unique.

### Example 1:
```
Input: pref = [5,2,0,3,1]
Output: [5,7,2,3,2]
Explanation: From the array [5,7,2,3,2] we have the following:
- pref[0] = 5.
- pref[1] = 5 ^ 7 = 2.
- pref[2] = 5 ^ 7 ^ 2 = 0.
- pref[3] = 5 ^ 7 ^ 2 ^ 3 = 3.
- pref[4] = 5 ^ 7 ^ 2 ^ 3 ^ 2 = 1.
```

### Constraints:
- `1 <= pref.length <= 10^5`
- `0 <= pref[i] <= 10^6`

---

## Pattern Insight: Inverse Prefix XOR Equation
- By definition:
  $$pref[i] = pref[i - 1] \oplus arr[i]$$
- XORing both sides by $pref[i - 1]$:
  $$pref[i] \oplus pref[i - 1] = (pref[i - 1] \oplus pref[i - 1]) \oplus arr[i] = 0 \oplus arr[i] = arr[i]$$
- Therefore, each element is recovered directly via:
  $$arr[i] = pref[i] \oplus pref[i - 1] \quad (\text{for } i \ge 1)$$
  with $arr[0] = pref[0]$.
- Can even be computed in-place in $O(1)$ auxiliary space!

---

## Complexity
- **Time Complexity:** $O(N)$ single pass.
- **Space Complexity:** $O(1)$ auxiliary space.
