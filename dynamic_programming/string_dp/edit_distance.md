# Problem 8: Edit Distance (Levenshtein Distance)

## Problem Statement

Given two strings `word1` and `word2`, return the **minimum number of operations** required to convert `word1` to `word2`.

You have the following three operations permitted on a word:
1. **Insert** a character
2. **Delete** a character
3. **Replace** a character

---

## Examples

### Example 1
- **Input:** `word1 = "horse", word2 = "ros"`
- **Output:** `3`
- **Explanation:**
  1. `horse` $\rightarrow$ `rorse` (replace `'h'` with `'r'`)
  2. `rorse` $\rightarrow$ `rose` (delete `'r'`)
  3. `rose` $\rightarrow$ `ros` (delete `'e'`)

### Example 2
- **Input:** `word1 = "intention", word2 = "execution"`
- **Output:** `5`
- **Explanation:**
  1. `intention` $\rightarrow$ `inention` (delete `'t'`)
  2. `inention` $\rightarrow$ `enention` (replace `'i'` with `'e'`)
  3. `enention` $\rightarrow$ `exention` (replace `'n'` with `'x'`)
  4. `exention` $\rightarrow$ `exection` (replace `'n'` with `'c'`)
  5. `exection` $\rightarrow$ `execution` (insert `'u'`)

---

## Constraints

- $0 \le \text{word1.length}, \text{word2.length} \le 500$
- `word1` and `word2` consist of lowercase English letters.

---

## DP Recurrence: The 3 Parallel Universes

Let pointer $i$ index `word1` and pointer $j$ index `word2`.

1. **State:**
   - $\text{dp}[i][j]$ is the minimum operations to convert `word1[0...i-1]` to `word2[0...j-1]`.
2. **Transitions:**
   - If characters match (`word1[i - 1] == word2[j - 1]`):
     $$\text{dp}[i][j] = \text{dp}[i - 1][j - 1]$$
   - If characters differ:
     $$\text{dp}[i][j] = 1 + \min \begin{cases}
     \text{dp}[i][j - 1] & \text{(Insert)} \\
     \text{dp}[i - 1][j] & \text{(Delete)} \\
     \text{dp}[i - 1][j - 1] & \text{(Replace)}
     \end{cases}$$
3. **Base Cases:**
   - Converting an empty string to length $j$: $\text{dp}[0][j] = j$ (Insert $j$ times).
   - Converting length $i$ to an empty string: $\text{dp}[i][0] = i$ (Delete $i$ times).

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Top-Down (Recursion + Memoization)** | $O(M \times N)$ | $O(M \times N)$ |
| **Bottom-Up (2D Tabulation)** | $O(M \times N)$ | $O(M \times N)$ |
| **Space-Optimized Iterative** | $O(M \times N)$ | $O(N)$ (Rolling row) |

