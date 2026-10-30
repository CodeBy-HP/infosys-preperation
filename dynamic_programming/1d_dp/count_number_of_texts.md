# Problem: Count Number of Texts (LeetCode 2266)

## Problem Statement

Alice is texting Bob using a traditional phone keypad where multiple letters share the same numeric key:
- Key `2`: `'a', 'b', 'c'` (3 characters)
- Key `3`: `'d', 'e', 'f'` (3 characters)
- Key `4`: `'g', 'h', 'i'` (3 characters)
- Key `5`: `'j', 'k', 'l'` (3 characters)
- Key `6`: `'m', 'n', 'o'` (3 characters)
- Key `7`: `'p', 'q', 'r', 's'` (4 characters)
- Key `8`: `'t', 'u', 'v'` (3 characters)
- Key `9`: `'w', 'x', 'y', 'z'` (4 characters)

To type a character:
- Press the key $1$ time for the 1st letter on the key.
- Press the key $2$ times consecutively for the 2nd letter.
- Press the key $3$ times consecutively for the 3rd letter.
- Press the key $4$ times consecutively for the 4th letter (only for keys `7` and `9`).

Given a string `pressedKeys` consisting only of digits from `'2'` to `'9'`, return the **total number of possible text messages** Alice could have sent.

Since the answer may be very large, return it **modulo $10^9 + 7$**.

---

## Examples

### Example 1
- **Input:** `pressedKeys = "22233"`
- **Output:** `8`
- **Explanation:**
  - `"222"` can be interpreted as:
    - `"2"` + `"2"` + `"2"` $\rightarrow$ `"aaa"`
    - `"2"` + `"22"` $\rightarrow$ `"ab"`
    - `"22"` + `"2"` $\rightarrow$ `"ba"`
    - `"222"` $\rightarrow$ `"c"`
    (4 possibilities)
  - `"33"` can be interpreted as:
    - `"3"` + `"3"` $\rightarrow$ `"dd"`
    - `"33"` $\rightarrow$ `"e"`
    (2 possibilities)
  - Total messages = $4 \times 2 = 8$.

### Example 2
- **Input:** `pressedKeys = "222222222222222222222222222222222222"`
- **Output:** `82876089`

---

## Constraints

- $1 \le \text{pressedKeys.length} \le 10^5$
- `pressedKeys` contains only digits from `'2'` to `'9'`.

---

## DP Logic & Transitions

1. **State:**
   - `dp[i]` represents the number of valid messages that can be formed from index `i` to the end of the string.
2. **Transitions:**
   Let `maxPresses = (pressedKeys[i] == '7' || pressedKeys[i] == '9') ? 4 : 3`.
   We can group $1, 2, \dots, \text{maxPresses}$ identical consecutive digits together:
   $$\text{dp}[i] = \sum_{k=1}^{\min(\text{maxPresses},\, \text{runLength})} \text{dp}[i + k] \pmod{10^9 + 7}$$
3. **Base Case:**
   - $\text{dp}[N] = 1$ (1 valid message for an empty suffix).

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Top-Down (Recursion + Memoization)** | $O(N)$ | $O(N)$ [Memo table + Recursion depth] |
| **Bottom-Up Tabulation** | $O(N)$ | $O(N)$ [DP array] |
| **Space-Optimized Iterative** | $O(N)$ | $O(1)$ [Rolling window of size 5] |

