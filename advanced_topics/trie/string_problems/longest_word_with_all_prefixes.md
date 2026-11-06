# Longest Word with All Prefixes (Complete String)

## Problem Statement
Given an array of strings `words`, find the **longest string** in `words` such that **every prefix** of it is also present in `words`.

If there are multiple answers with the same maximum length, return the **lexicographically smallest** one. If no such string exists, return an empty string `""`.

```
Input: words = ["n", "ni", "nin", "ninj", "ninja", "ninga"]
Output: "ninja"

Explanation:
- "ninja" has prefixes: "n", "ni", "nin", "ninj", "ninja". All exist in words.
- "ninga" also has length 5, but "ninja" is lexicographically smaller than "ninga".
```

---

## 1. Algorithmic Approach (Trie Prefix Chain Verification)

### Step 1: Insert All Words into Trie
Insert every word into a standard Trie, marking `isEnd = true` at the final node of each word.

### Step 2: Validate Complete Prefix Chains
A word $W$ of length $L$ satisfies the condition **if and only if** every character node along its path in the Trie has `isEnd == true`:
$$\forall i \in [1, L], \quad \text{node}(W[0 \dots i-1])\to\text{isEnd} == \text{true}$$

For each word:
1. Traverse character by character from the root.
2. If at any character `node->isEnd() == false`, abort the word immediately.
3. If all nodes along the path have `isEnd == true`, the word is complete!
4. Update `longest`:
   - If `word.length() > longest.length()`: update `longest = word`.
   - If `word.length() == longest.length() && word < longest`: update `longest = word` (lexicographical tie-breaker).

---

## 2. Complexity Analysis
- **Time Complexity:** $O(\sum |W_i|)$ — Inserting all words takes $O(\sum |W_i|)$. Checking each word takes $O(\sum |W_i|)$. Total time is linear with respect to the sum of all character lengths.
- **Space Complexity:** $O(\sum |W_i| \cdot 26)$ — Trie node allocations.

