# Bit Manipulation & XOR: Quick Reference Sheet

## 1. Fundamental XOR Properties & Identities

- **Identity Element:**
  - $A \oplus 0 = A$
  - XORing any value with $0$ leaves it unchanged.

- **Self-Inversion (Cancellation):**
  - $A \oplus A = 0$
  - Any number XORed with itself cancels out to $0$.
  - **Even vs. Odd Frequency Rule:**
    - Appears an **even** number of times $\rightarrow$ Cancels out to $0$.
    - Appears an **odd** number of times $\rightarrow$ Survives as $A$.

- **Bit Toggling (Inversion):**
  - Single bit flip: $x \oplus 1 = \sim x$ (i.e., $0 \oplus 1 = 1$, $1 \oplus 1 = 0$).
  - **Toggle $k$-th bit of an integer:** `x ^ (1 << k)`

- **Commutative & Associative:**
  - Commutative: $A \oplus B = B \oplus A$
  - Associative: $(A \oplus B) \oplus C = A \oplus (B \oplus C)$
  - *Implication:* Order of operations does not matter; numbers can be reordered freely.

- **Arithmetic Link (Addition, XOR & AND):**
  - Addition without carry is XOR ($A \oplus B$).
  - Carry bits are generated where both bits are $1$ ($A \ \& \ B$), shifted left by 1 position ($\times 2$).
  - **Key Equations:**
    $$A + B = (A \oplus B) + 2 \times (A \ \& \ B)$$
    $$A \oplus B = (A + B) - 2 \times (A \ \& \ B)$$

> **Precedence Warning (C++ / Java):**  
> Arithmetic operators (`+`, `-`) have **higher precedence** than bitwise operators (`^`, `&`, `|`).  
> *Always use parentheses:* `(A ^ B) + 2 * (A & B)` instead of `A ^ B + 2 * A & B`.

---

## 2. Prefix XOR & Range Queries

- **Prefix XOR Definition:**
  - If `pref[i]` stores the cumulative XOR sum from index $0$ to $i$:
    $$\text{pref}[i] = \text{pref}[i - 1] \oplus \text{arr}[i] \quad (\text{with } \text{pref}[-1] = 0)$$

- **Range XOR Query Formula:**
  - For any 0-indexed subarray in range $[L, R]$:
    $$\boxed{\text{xorSum}(L, R) = \text{pref}[R] \oplus \text{pref}[L - 1]}$$

- **Why it works (Self-Inverse Property):**
  - $\text{pref}[R] = (\text{arr}[0] \oplus \dots \oplus \text{arr}[L-1]) \oplus (\text{arr}[L] \oplus \dots \oplus \text{arr}[R])$
  - $\text{pref}[L-1] = (\text{arr}[0] \oplus \dots \oplus \text{arr}[L-1])$
  - XORing both cancels out the common prefix from $0$ to $L-1$:
    $$\text{pref}[R] \oplus \text{pref}[L-1] = (\text{prefix}) \oplus (\text{range}) \oplus (\text{prefix}) = 0 \oplus (\text{range}) = \text{xorSum}(L, R)$$
  - *Contrast with standard prefix sums:* Prefix addition uses subtraction ($-$) as its inverse, whereas XOR uses itself ($\oplus$) as its own inverse.

---

## 3. Bitwise Contribution Technique

### Core Concept: Independent Bit Columns
- Bits are 0-indexed from right to left, where bit position $i$ has positional weight $2^i$.
- Bitwise operations (`AND`, `OR`, `XOR`) act **independently column-by-column**.
- No carries overflow across columns during pure bitwise operations.
- The total answer can be computed by calculating the contribution of each bit position $i$ independently, then summing them up weighted by $2^i$.

### General Master Formula
$$\boxed{\text{Total Answer} = \sum_{i} C_i \times 2^i}$$

- $i$: The bit position ($0, 1, 2, \dots$).
- $C_i$: The calculated contribution / count at bit position $i$.
- $2^i$: The positional weight of bit $i$ (e.g., `1 << i`).

---

## 4. Application: Adding Numbers Using Bit Contributions

### The Formula
Instead of adding numbers horizontally, count the `1`s vertically column-by-column:

$$\boxed{\text{Contribution at bit } i = (\text{no. of 1s at bit } i) \times 2^i}$$

$$\boxed{\text{Total Sum} = \sum_{i} (\text{no. of 1s at bit } i) \times 2^i}$$

### Concrete Example: Add 3, 2, and 1
Binary representations:
```text
  3 = 0 1 1  (Bit 1, Bit 0)
  2 = 0 1 0  (Bit 1)
  1 = 0 0 1  (Bit 0)
      -----
```

- **Bit 0:** Two `1`s $\rightarrow 2 \times 2^0 = 2 \times 1 = 2$
- **Bit 1:** Two `1`s $\rightarrow 2 \times 2^1 = 2 \times 2 = 4$
- **Bit 2:** Zero `1`s $\rightarrow 0 \times 2^2 = 0 \times 4 = 0$

$$\text{Total Sum} = 2 + 4 + 0 = \mathbf{6}$$

### Why Does This Work?
Every integer can be written as the sum of its active bit weights:
$$3 = 2 + 1, \quad 2 = 2, \quad 1 = 1$$

Summing them:
$$3 + 2 + 1 = (2 + 1) + 2 + 1$$

Rearranging and grouping identical bit positions:
$$= (1 + 1) + (2 + 2) = 2(2^0) + 2(2^1) = 2 + 4 = \mathbf{6}$$

> **Key Difference from Standard Binary Addition:**
> - **Standard binary addition:** Adds column-by-column and handles carry propagation explicitly at each step.
> - **Bit contribution method:** Counts `1`s independently per column without carry propagation. Carries are handled automatically at the end when multiplying by $2^i$ and performing standard numerical addition.

---

## 5. Quick Revision Summary Table

| Property / Concept | Formula / Rule | Quick Insight |
| :--- | :--- | :--- |
| **Identity** | $A \oplus 0 = A$ | $0$ does not change any bit |
| **Self-Inverse** | $A \oplus A = 0$ | Even occurrences cancel to $0$; odd remain |
| **Bit Toggling** | `x ^ (1 << k)` | Flips bit $k$ ($0 \leftrightarrow 1$) |
| **Arithmetic Link** | $A + B = (A \oplus B) + 2(A \ \& \ B)$ | Addition = XOR + Carry |
| **Range XOR Query** | $\text{pref}[R] \oplus \text{pref}[L-1]$ | $O(1)$ range XOR after $O(N)$ prefix array |
| **Bit Contribution** | $\sum C_i \times 2^i$ | Solve bitwise problems column-by-column |
