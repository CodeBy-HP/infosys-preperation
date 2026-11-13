# Bit Manipulation Mental Models & Core Invariants

A structured reference of essential bitwise insights, mental models, arithmetic mechanics, and combinatorial principles.

---

## 1. Two's Complement & Negative Numbers

### Why Two's Complement?
Modern CPUs use **Two's Complement** to represent signed integers because it eliminates the need for separate addition and subtraction hardware circuitry. In two's complement, subtraction is performed by adding the negated counterpart:
$$A - B = A + (-B) = A + (\sim B + 1)$$

### The Negation Recipe: $-x = \sim x + 1$
To negate a number $x$:
1. **Invert all bits** ($\sim x$)
2. **Add 1** to the result

#### Example: Making $+12$ into $-12$ (using 8 bits)
```text
  +12 in binary:       0 0 0 0 1 1 0 0
  Invert all bits (~): 1 1 1 1 0 0 1 1
  Add 1 (+1):        + 0 0 0 0 0 0 0 1
  ------------------------------------
  -12 in binary:       1 1 1 1 0 1 0 0
```

### The Special Case: $0 - 1 = -1$ (Bit Underflow & All 1s)
In two's complement, $-1$ is represented as **all bits turned on (1s)**.
```text
  0 in 8-bit binary:   0 0 0 0 0 0 0 0
  Subtract 1 (-1):   - 0 0 0 0 0 0 0 1
  ------------------------------------
  Result (-1):         1 1 1 1 1 1 1 1  (Wraps around to 0xFF)
```
> [!NOTE]
> In an unsigned integer, subtracting $1$ from $0$ causes an underflow to the maximum possible value ($2^{32} - 1$). In a signed integer, it yields $-1$.

---

## 2. The Mechanics of `x - 1` and Lowest Set Bit Isolation

### What Happens When You Subtract 1 (`x - 1`)?
Subtracting 1 flips the **rightmost set bit (1)** to a `0`, and turns **all trailing 0s to its right into 1s**. All bits to its left remain unchanged.
```text
  x:       1 0 1 0 1 0 0 0   (Rightmost 1 is at index 3)
  x - 1:   1 0 1 0 0 1 1 1   (Bit 3 becomes 0; trailing zeros become 1s)
```

### Clearing the Lowest Set Bit: `x & (x - 1)`
Because `x - 1` inverts the rightmost 1 and all trailing 0s, ANDing `x` with `x - 1` clears strictly the lowest set bit:
```text
  x:           1 0 1 0 1 0 0 0
  x - 1:     & 1 0 1 0 0 1 1 1
  ----------------------------
  x & (x-1):   1 0 1 0 0 0 0 0   (Lowest set bit erased in O(1))
```
- **Use cases:**
  - **Brian Kernighan’s Popcount:** Counting set bits in $O(\text{number of 1s})$.
  - **Power of 2 Check:** `x > 0 && (x & (x - 1)) == 0`.

### Isolating the Lowest Set Bit: `x & (-x)`
Since $-x = \sim x + 1$, all bits up to and including the lowest set bit remain identical, while all higher bits are inverted. Performing `x & (-x)` isolates strictly the lowest set bit:
```text
  x:          0 1 1 0 0
 -x:        & 1 0 1 0 0   (Inverted bits + 1)
  ---------------------
  x & (-x):   0 0 1 0 0   (Only the lowest set bit remains!)
```
- **Use cases:**
  - **Fenwick Tree / Binary Indexed Tree (BIT)** child/parent index updates (`i += (i & -i)`).
  - Isolating differing bits to partition elements (e.g., *Single Number III*).
  - Building blocks for **Gosper's Hack**.

---

## 3. Bitwise Filtering, Disjoint Sets, and Hardware Adders

### 1. Mask Filtering (`x & filter`)
- Passing a number through a filter mask unsets all bits of $x$ that are `0` in `filter`.
- Retains only the target bits.

### 2. Disjoint Bit Test (`(a & b) == 0`)
- If two numbers have no common set bits, their bitwise AND is strictly `0`.
- In set theory, this tests if set $A$ and set $B$ are **disjoint**: $A \cap B = \emptyset$.
- Often used in string presence masking (e.g., *Maximum Product of Word Lengths*).

### 3. Digital Half-Adder Circuit
Binary addition can be broken down into two distinct bitwise operations:
- **Sum without Carry (XOR):** $A \oplus B$ (1 + 0 = 1, 1 + 1 = 0)
- **Carry Generation (AND):** $(A \ \& \ B) \ll 1$ (Carry occurs only when both bits are 1)

$$\text{Sum}(A, B) = (A \oplus B) + 2(A \ \& \ B)$$

---

## 4. The Combinatorial Bit Invariant (The "Half-of-All-Subsets" Rule)

> [!IMPORTANT]
> **Mathematical Guarantee:**
> If a bit $b$ is turned ON (1) in **at least one** number in an array of $N$ integers, it will be turned ON in **exactly half ($2^{N-1}$)** of all possible subsets!

### Why Does This Happen?
1. Suppose bit $b$ is set in element $x \in \text{Array}$.
2. Partition all $2^N$ subsets into pairs: $(S, S \cup \{x\})$, where $S$ does not contain $x$.
3. In each pair, exactly one subset has an odd count of bit $b$ set (resulting in XOR sum bit $b = 1$), and the other has an even count (resulting in XOR sum bit $b = 0$).
4. Hence, bit $b$ appears in exactly $\frac{2^N}{2} = 2^{N-1}$ subset XOR totals.

**Practical Application (*Sum of All Subset XOR Totals*):**
$$\text{Total XOR Sum} = (\text{OR of all elements}) \times 2^{N-1}$$
Computes the sum of all $2^N$ subset XOR totals in a single linear pass ($O(N)$) without generating subsets!

---

## 5. Submask Enumeration (`(sub - 1) & mask`)

A **submask** of `mask` is any number obtained by unsetting some of the `1` bits in `mask`.
- If `mask = 1010` (10), its valid submasks are: `1010` (10), `1000` (8), `0010` (2), and `0000` (0).

### The Canonical Loop Template
```cpp
// Descending enumeration visiting only valid submasks
for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
    // Process submask
}
// Note: 0 is also a valid submask; handle sub = 0 outside if required
```

### Why Does `(sub - 1) & mask` Work?
- `sub - 1` flips the lowest set bit of `sub` to 0 and all lower bits to 1.
- ANDing with `mask` strips away any 1s that were not part of the original mask!
- It directly jumps from one valid submask to the next without checking any non-submasks.

### Asymptotic Efficiency:
- For a single mask with $K$ bits: visits exactly $2^K$ submasks.
- Across all $N$-bit masks:
  $$\sum_{k=0}^N \binom{N}{k} 2^k = (1 + 2)^N = 3^N \quad (\ll 4^N)$$

---

## 6. Gosper's Hack: Combinations of Exactly $K$ Set Bits

When searching over $N$-bit numbers that have **exactly $K$ set bits** ($\binom{N}{K}$ combinations), testing all $2^N$ numbers is wasteful. **Gosper's Hack** finds the next lexicographical number with the same popcount in $O(1)$ operations:

```cpp
// Initialize with smallest integer having k set bits (e.g., k=3 -> 000111 in binary)
uint64_t mask = (1ULL << k) - 1ULL;
uint64_t limit = 1ULL << n;

while (mask < limit) {
    // Process mask...

    uint64_t c = mask & -mask;                // 1. Isolate lowest set bit
    uint64_t r = mask + c;                    // 2. Ripple carry addition
    mask = (((r ^ mask) >> 2) / c) | r;       // 3. Shift and restore trailing 1s
}
```

### Step-by-Step Mechanism:
1. `c = mask & -mask`: Isolates lowest set bit.
2. `r = mask + c`: Adds $c$. Flips the contiguous block of ones to zeros, and sets the bit immediately to its left.
3. `r ^ mask`: Identifies changed bits.
4. `((r ^ mask) >> 2) / c`: Discards extra carry bits and shifts remaining ones down to index 0.
5. `| r`: Combines the restored trailing ones with the new higher bit.

---

## 7. Geometric Perspective: The $N$-Dimensional Hypercube & Gray Code

A binary number with $N$ bits can be interpreted as a coordinate in an **$N$-dimensional geometric space**. The set of all $2^N$ binary numbers forms the vertices of an **$N$-Dimensional Hypercube (Qn)**:

```text
 1D (Line, N=1)       2D (Square, N=2)            3D (Cube, N=3)

     0 --- 1               01 --- 11                011 ----- 111
                           |       |               / |       / |
                           |       |             001 ----- 101 |
                           00 --- 10              |  010 --|-- 110
                                                  | /      | /
                                                 000 ----- 100
```

### Properties of the Hypercube Graph:
- **Vertices:** $2^N$ total nodes.
- **Edges:** Each vertex connects to exactly $N$ neighbors (flipping each of the $N$ bit positions).
- **Physical Meaning of an Edge:** Traveling along an edge means flipping **exactly one bit**.

### The Gray Code Connection:
- **Gray Code** ($G(i) = i \oplus (i \gg 1)$) generates a sequence of $2^N$ integers where every adjacent pair differs by strictly 1 bit.
- **Geometric Interpretation:** A Gray Code is a **Hamiltonian Cycle** on the Hypercube graph—a path that starts at the origin $(000\dots)$, visits every single corner of the $N$-dimensional hypercube **exactly once**, and returns to the start!

---

## 8. Linear Basis (Gaussian Elimination over $\mathbb{F}_2$)

Integers can be treated as vectors over the Galois Field $\mathbb{F}_2$ (where scalar addition is bitwise XOR $\oplus$).
- Any subset of numbers can be reduced to at most **64 basis vectors**.
- **The Basis Array (`basis[64]`):** Each slot `basis[i]` stores a basis vector whose highest set bit is strictly at index $i$.

```cpp
class LinearBasis {
    uint64_t basis[64] = {0};

    void insert(uint64_t x) {
        for (int i = 63; i >= 0; --i) {
            if ((x >> i) & 1) {
                if (!basis[i]) { basis[i] = x; return; }
                x ^= basis[i];
            }
        }
    }

    uint64_t getMaxXor() {
        uint64_t maxXor = 0;
        for (int i = 63; i >= 0; --i) {
            if ((maxXor ^ basis[i]) > maxXor) maxXor ^= basis[i];
        }
        return maxXor;
    }
};
```
- **Max XOR Query:** Solved in strictly $O(64) = O(1)$ greedy bit-decisions instead of exponential subset search.
