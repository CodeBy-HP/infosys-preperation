# Problem 12: Group Anagrams (LeetCode 49)

## Problem Statement

Given an array of strings `strs`, group the **anagrams** together. You can return the answer in **any order**.

An **anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

---

## Examples

### Example 1
- **Input:** `strs = ["eat","tea","tan","ate","nat","bat"]`
- **Output:** `[["bat"],["nat","tan"],["ate","eat","tea"]]`

### Example 2
- **Input:** `strs = [""]`
- **Output:** `[[""]]`

### Example 3
- **Input:** `strs = ["a"]`
- **Output:** `[["a"]]`

---

## Constraints

- $1 \le \text{strs.length} \le 10^4$
- $0 \le \text{strs}[i]\text{.length} \le 100$
- `strs[i]` consists of lowercase English letters.

---

## Two Canonical Grouping Fingerprints

### 1. Canonical Sorted Key
Sort each word alphabetically: `"eat" -> "aet"`, `"tea" -> "aet"`. Use the sorted string as hash map key:
$$\text{Time: } O(N \times K \log K)$$

### 2. Character Count Tuple Fingerprint
Count frequencies of 26 letters: `#1#0#0...#1...`. Map array of counts directly:
$$\text{Time: } O(N \times K)$$

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Sorted String Key** | $O(N \times K \log K)$ | $O(N \times K)$ |
| **Frequency Fingerprint** | $O(N \times K)$ | $O(N \times K)$ |
