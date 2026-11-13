# Alien Dictionary (LeetCode 269)

## Problem Statement
There is a new alien language that uses the Latin alphabet. However, the order among letters is unknown to you.

You are given a list of strings `words` from the alien language's dictionary, where the strings are claimed to be **sorted lexicographically** by the rules of this new language.

Derive the order of letters in this language.
- Return a string of the unique letters in the new alien language sorted in **lexicographically increasing order** by the new language's rules.
- If there is no valid letter order (e.g. Due to a cycle or prefix invalidity), return `""`.
- If there are multiple valid letter orders, return **any** of them.

**Lexicographical Rule:**
A string `a` is lexicographically smaller than string `b` if either of the following holds:
1. At the first index where `a[i] != b[i]`, letter `a[i]` comes before `b[i]` in the alien alphabet ($a[i] \to b[i]$ directed dependency).
2. If no such difference exists and `a.length < b.length`, then `a` is smaller than `b`.
- **Invalid Prefix Rule:** If string `b` is a prefix of `a` and `a.length > b.length` (e.g., `words = ["abc", "ab"]`), the list is invalid $\longrightarrow$ return `""`.

---

## Constraints
* `1 <= words.length <= 500`
* `1 <= words[i].length <= 100`
* `words[i]` consists only of lowercase English letters.
* Total unique characters $K \le 26$.

---

## Examples

### Example 1
**Input:**
```text
words = ["wrt", "wrf", "er", "ett", "rftt"]
```
**Output:**
```text
"wertf"
```
**Explanation:**
By comparing adjacent pairs of words:
1. `"wrt"` vs `"wrf"`: First differing character is at index 2 $\implies$ `'t' -> 'f'`.
2. `"wrf"` vs `"er"`: First differing character is at index 0 $\implies$ `'w' -> 'e'`.
3. `"er"` vs `"ett"`: First differing character is at index 1 $\implies$ `'r' -> 't'`.
4. `"ett"` vs `"rftt"`: First differing character is at index 0 $\implies$ `'e' -> 'r'`.
Directed edges: `w -> e -> r -> t -> f`.
Topological sort: `"wertf"`.

---

### Example 2
**Input:**
```text
words = ["z", "x"]
```
**Output:**
```text
"zx"
```
**Explanation:**
First difference is `'z'` vs `'x'` $\implies$ `'z' -> 'x'`. Order: `"zx"`.

---

### Example 3
**Input:**
```text
words = ["z", "x", "z"]
```
**Output:**
```text
""
```
**Explanation:**
- `"z"` vs `"x"` gives `'z' -> 'x'`.
- `"x"` vs `"z"` gives `'x' -> 'z'`.
This forms a cycle (`z <-> x`). No valid ordering exists $\implies$ `""`.

---

## Algorithmic Approaches

### Step 1: Graph Construction via Adjacent Pair Comparisons
1. Collect all unique characters present across all words.
2. For each adjacent pair `words[i]` and `words[i + 1]`:
   - Check invalid prefix condition: If `words[i].length() > words[i + 1].length()` and `words[i].rfind(words[i + 1], 0) == 0`:
     - Return `""` (e.g. `["apple", "app"]` is fundamentally invalid).
   - Find the first index `j` where `words[i][j] != words[i + 1][j]`:
     - Add directed edge: `words[i][j] -> words[i + 1][j]`.
     - Increment in-degree: `inDegree[words[i + 1][j]]++`.
     - Break immediately (subsequent characters give no ordering information).

### Step 2: Kahn's Algorithm (Topological Sort)
1. Push all unique characters with `inDegree == 0` into a queue.
2. Pop and append to result string `order`, decrementing neighbors' in-degrees.
3. If `order.length() == uniqueCharCount`, return `order`. Otherwise return `""` (cycle detected).

---

## Complexity Analysis
- **Time Complexity:** $O(C + V + E)$ where $C$ is the total number of characters across all words, $V \le 26$ unique letters, and $E \le 26^2$ edges.
- **Space Complexity:** $O(V + E) = O(1)$ since the alphabet size is bounded by $26$.
