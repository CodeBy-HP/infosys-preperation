# Word Ladder I (LeetCode 127)

## Problem Statement
A **transformation sequence** from word `beginWord` to word `endWord` using a dictionary `wordList` is a sequence of words `beginWord -> s_1 -> s_2 -> ... -> s_k` such that:
1. Every adjacent pair of words differs by exactly **one letter**.
2. Every $s_i$ for $1 \le i \le k$ is in `wordList` (`beginWord` does not need to be in `wordList`).
3. $s_k == \text{endWord}$.

Given two words, `beginWord` and `endWord`, and a dictionary `wordList`, return the **number of words in the shortest transformation sequence** from `beginWord` to `endWord`, or `0` if no such sequence exists.

---

## Constraints
* `1 <= beginWord.length <= 10`
* `endWord.length == beginWord.length`
* `1 <= wordList.length <= 5000`
* `wordList[i].length == beginWord.length`
* `beginWord`, `endWord`, and `wordList[i]` consist of lowercase English letters.
* `beginWord != endWord`
* All strings in `wordList` are **unique**.

---

## Examples

### Example 1
**Input:**
```text
beginWord = "hit", endWord = "cog", 
wordList = ["hot", "dot", "dog", "lot", "log", "cog"]
```
**Output:**
```text
5
```
**Explanation:**
One shortest transformation sequence is `"hit" -> "hot" -> "dot" -> "dog" -> "cog"`, which contains 5 words.

```
"hit" ---> "hot" ---> "dot" ---> "dog" ---> "cog"
 (1)        (2)        (3)        (4)        (5)
```

---

### Example 2
**Input:**
```text
beginWord = "hit", endWord = "cog", 
wordList = ["hot", "dot", "dog", "lot", "log"]
```
**Output:**
```text
0
```
**Explanation:**
The `endWord` `"cog"` is not present in `wordList`, so no valid transformation sequence exists.

---

## Algorithmic Approaches

### State-Space BFS on Word Graph
- Finding the shortest transformation sequence in an unweighted graph is solved via **Breadth-First Search (BFS)**.
- **Efficient Neighbor Generation:**
  Instead of comparing the current word with all $5000$ words in `wordList` ($O(N \cdot L)$ per step), **generate all $26 \times L$ possible 1-character mutations** of the current word and check their presence in a hash set in $O(L)$ time!
  $$\text{Transformations per word} = 26 \times L$$

### Step-by-Step Algorithm
1. Store all dictionary words in an `unordered_set<string> wordSet(wordList.begin(), wordList.end())`.
2. If `endWord` is not in `wordSet`, return `0`.
3. Initialize a queue storing `pair<string, int>` (`{current_word, current_step}`).
4. Push `{beginWord, 1}` and remove `beginWord` from `wordSet`.
5. While queue is not empty:
   - Pop `{word, steps}`.
   - If `word == endWord`, return `steps`.
   - For each index $i$ from $0$ to $L - 1$:
     - Save original character `char original = word[i]`.
     - Try replacing `word[i]` with every character `'a'` through `'z'`:
       - If mutated `word` exists in `wordSet`:
         - Erase `word` from `wordSet` (prevents revisiting and acts as `visited`).
         - Push `{word, steps + 1}` into queue.
     - Restore `word[i] = original`.
6. Return `0` if queue is exhausted.

---

## Complexity Analysis
- **Time Complexity:** $O(N \cdot L \cdot 26) = O(N \cdot L)$ where $N = \text{wordList.length}$ and $L = \text{word.length}$.
- **Space Complexity:** $O(N \cdot L)$ for `wordSet` and BFS queue.
