# Rabin-Karp String Matching (Rolling Hash) Algorithm

## Problem Statement

Given a text string `text` of length $n$ and a pattern string `pattern` of length $m$, find the index of the **first occurrence** of `pattern` in `text`, or return **all matching indices**.

The **Rabin-Karp algorithm** solves this problem by using a **Rolling Hash**: instead of comparing strings character by character, it computes and compares integer hashes of substrings in $O(1)$ time per sliding window step.

---

## The Rolling Hash Mechanism

### 1. Polynomial Hash Function:
For a string of length $m$ with base $B = 256$ (or $31$) and prime modulo $M = 10^9 + 7$:
$$H(s[0 \dots m - 1]) = \left( \sum_{i=0}^{m - 1} s[i] \cdot B^{m - 1 - i} \right) \pmod M$$

### 2. $O(1)$ Sliding Window Hash Shift:
When shifting the window from $[i \dots i + m - 1]$ to $[i + 1 \dots i + m]$:
1. **Remove Old Character:** Subtract the leading character's weighted contribution: $s[i] \cdot B^{m - 1}$.
2. **Shift Left:** Multiply the remaining hash by $B$.
3. **Add New Character:** Add $s[i + m]$.
4. Apply modulo arithmetic:
   $$H_{\text{new}} = \left( (H_{\text{old}} - s[i] \cdot B^{m - 1}) \cdot B + s[i + m] \right) \pmod M$$

### 3. Spurious Hits & Collision Verification:
Because two different strings can yield the exact same hash modulo $M$ (a hash collision or "spurious hit"), whenever the window hash matches the pattern hash, we perform a character-by-character verification.

---

## Single Hash vs. Double Hash

| Feature | Single Rolling Hash | Double Rolling Hash |
| :--- | :--- | :--- |
| **Bases & Modulos** | Base $B_1$, Mod $M_1$ | $(B_1, M_1)$ and $(B_2, M_2)$ |
| **Collision Probability** | $1 / M_1 \approx 10^{-9}$ | $1 / (M_1 \cdot M_2) \approx 10^{-18}$ |
| **Character Check Needed?** | Yes (to guarantee correctness) | Virtually never collides in practice |

---

## Complexity Analysis

| Scenario | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Best / Average Case** | $O(n + m)$ | $O(1)$ |
| **Worst Case (Every hash collides)** | $O(n \times m)$ | $O(1)$ |

