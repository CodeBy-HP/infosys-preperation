# Number of Valid Words for Each Puzzle (LeetCode 1178)

## Problem Statement
With respect to a given `puzzle` string, a `word` is **valid** if both the following conditions are satisfied:
1. `word` contains the **first letter** of `puzzle`.
2. For each letter in `word`, that letter is in `puzzle`.
   - For example, if the puzzle is `"abcdefg"`, then valid words could be `"faced"`, `"cabbage"`, and `"baggage"`, while invalid words are `"beefed"` (does not include `'a'`) and `"based"` (includes `'s'`, which is not in the puzzle).

Return an array `answer`, where `answer[i]` is the number of words in the given word list `words` that are valid with respect to the puzzle `puzzle[i]`.

### Example 1:
```
Input: 
words = ["aaaa","asas","able","ability","actt","actor","access"], 
puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]
Output: [1,1,3,2,4,0]
```

### Constraints:
- `1 <= words.length <= 10^5`
- `4 <= words[i].length <= 50`
- `1 <= puzzles.length <= 10^4`
- `puzzles[i].length == 7`
- `words[i]` and `puzzles[i]` consist of lowercase English letters.
- Each `puzzles[i]` does not contain repeated characters.

---

## Pattern Insight: Bitmask Signature + Puzzle Submask Enumeration
- A naive check of all words for every puzzle takes $O(\text{puzzles} \times \text{words}) \approx 10^4 \times 10^5 = 10^9$ (TLE).
- **Core Insights:**
  1. Any word with $> 7$ unique characters can never be valid for any puzzle of length 7.
  2. Precompute a frequency map `wordCount[mask]` for all words.
  3. For a puzzle, the first letter `puzzle[0]` is **mandatory**: `firstBit = 1 << (puzzle[0] - 'a')`.
  4. The other 6 letters of the puzzle form a submask `restMask` with at most 6 bits set.
  5. There are at most $2^6 = 64$ submasks of `restMask`!
  6. Enumerate all submasks of `restMask` using `sub = (sub - 1) & restMask`.
     The candidate word mask is `sub | firstBit`.
     Add `wordCount[sub | firstBit]` to answer!
- Total operations per puzzle: at most $64$ iterations.
  $10^4 \times 64 \approx 6.4 \times 10^5$ operations (blazing fast!).

---

## Complexity
- **Time Complexity:** $O(\sum |words[i]| + P \cdot 2^6)$ where $P$ is the number of puzzles.
- **Space Complexity:** $O(\text{unique word masks})$.
