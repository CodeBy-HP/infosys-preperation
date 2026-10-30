# Problem 13: Zigzag Conversion (LeetCode 6)

## Problem Statement

The string `"PAYPALISHIRING"` is written in a zigzag pattern on a given number of rows like this:

```text
P   A   H   N
A P L S I I G
Y   I   R
```
And then read line by line: `"PAHNAPLSIIGYIR"`.

Write the code that will take a string and make this conversion given a number of rows.

---

## Examples

### Example 1
- **Input:** `s = "PAYPALISHIRING", numRows = 3`
- **Output:** `"PAHNAPLSIIGYIR"`

### Example 2
- **Input:** `s = "PAYPALISHIRING", numRows = 4`
- **Output:** `"PINALSIGYAHRPI"`
- **Explanation:**
```text
P     I    N
A   L S  I G
Y A   H R
P     I
```

---

## Constraints

- $1 \le \text{s.length} \le 1000$
- `s` consists of English letters (lower-case and upper-case), `','` and `'.'`.
- $1 \le \text{numRows} \le 1000$

---

## Pattern: Row Tracking with Direction Bouncing

Maintain an array of strings `rows[numRows]`:
- Maintain `currRow = 0` and `goingDown = false`.
- For each character `c` in `s`:
  - Append `rows[currRow] += c`.
  - If `currRow == 0` or `currRow == numRows - 1`: flip direction `goingDown = !goingDown`.
  - Advance `currRow += goingDown ? 1 : -1`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Row Direction Bouncing** | $O(N)$ | $O(N)$ output buffer |
