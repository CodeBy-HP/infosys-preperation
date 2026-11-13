# Bit Manipulation Prerequisites for Trie Problems

Bitwise Trie algorithms (such as Maximum XOR) require a solid understanding of binary representations and bitwise operations. This guide establishes the mathematical foundation and bit-level primitives required for binary Tries.

---

## 1. Core Bitwise Operators

| Operator | Name | Definition | Truth Invariant |
|:---:|:---:|---|---|
| `&` | **AND** | `1 & 1 = 1`, otherwise `0` | Extracts common set bits |
| `\|` | **OR** | `0 \| 0 = 0`, otherwise `1` | Combines set bits |
| `^` | **XOR** | `1 ^ 0 = 1`, `0 ^ 1 = 1`, `a ^ a = 0` | **Difference detector**: $1$ if bits differ, $0$ if same |
| `~` | **NOT** | Inverts all bits | Flip operator |
| `<<` | **Left Shift** | `x << k` shifts bits left by $k$ | Multiplies by $2^k$ |
| `>>` | **Right Shift** | `x >> k` shifts bits right by $k$ | Divides by $2^k$ (integer division) |

---

## 2. Essential Bit Tricks for Binary Tries

### A. Extracting the $i$-th Bit of a Number
To inspect whether the $i$-th bit (0-indexed from right to left) of an integer `num` is $0$ or $1$:

```cpp
int bit = (num >> i) & 1;
```

**Example:** $num = 13 = (1101)_2$:
- For $i = 3$: `(13 >> 3) & 1` $\to (1)_2 \& 1 = 1$.
- For $i = 1$: `(13 >> 1) & 1` $\to (110)_2 \& 1 = 0$.

---

### B. Setting the $i$-th Bit in an Accumulated Result
When building the maximum XOR answer bit-by-bit:
```cpp
maxXor |= (1 << i);
```
This flips the $i$-th bit of `maxXor` from $0$ to $1$ while keeping all other bits intact.

---

### C. The XOR Maximization Invariant
The bitwise XOR operation ($\oplus$) yields $1$ **if and only if the two input bits differ**:
$$0 \oplus 1 = 1, \quad 1 \oplus 0 = 1, \quad 0 \oplus 0 = 0, \quad 1 \oplus 1 = 0$$

Therefore, to maximize $X \oplus Y$:
- At the most significant bit (MSB), we desire $X_i \ne Y_i$.
- If the current bit of $X$ is `bit`, we want to pair it with a number $Y$ whose corresponding bit is:
  $$\text{oppositeBit} = 1 - \text{bit} \quad (\text{or } \text{bit} \oplus 1)$$
- **Greedy Principle:** Because $2^k > \sum_{j=0}^{k-1} 2^j$, securing a $1$ at a higher bit $k$ is always strictly better than any combination of $1$s at lower bits $0 \dots k-1$.

---

## 3. Fixed Bit-Width Convention
For 32-bit signed integers where numbers are non-negative ($0 \le \text{num} \le 10^9 < 2^{31} - 1$):
- Bit positions range from index **31 down to 0** (or **30 down to 0**).
- Every number is represented as a fixed-length binary string of 31 or 32 bits, prepended with leading zeros as necessary.

```
Number 5:  0000000000000000000000000000101
Number 25: 0000000000000000000000000011001
```

---

## 4. Binary Trie Node Architecture
A **Binary Trie** has an alphabet size of only **2** (`0` and `1`):

```cpp
struct BinaryTrieNode {
    BinaryTrieNode* links[2];

    BinaryTrieNode() {
        links[0] = nullptr;
        links[1] = nullptr;
    }

    bool containsKey(int bit) {
        return links[bit] != nullptr;
    }

    BinaryTrieNode* get(int bit) {
        return links[bit];
    }

    void put(int bit, BinaryTrieNode* node) {
        links[bit] = node;
    }
};
```
Each branch down the tree from root to leaf represents a 32-step binary number path.

