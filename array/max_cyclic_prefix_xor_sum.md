## Maximum Cyclic Prefix XOR Sum

**Problem Statement**
You are given an array $ARR$ consisting of $N$ integers. The array is cyclic, meaning the element after the last index is the first index, and the element before the first index is the last index.

You want to construct a new array $RES$ of size $N$ using the following algorithm:

1. Start at any index of $ARR$.
2. Choose a direction (left or right).
3. Iterate over all $N$ elements of $ARR$ starting from the chosen index in the chosen direction.
4. Add each iterated element to the end of the initially empty array $RES$.

The **value** of $RES$ is defined as the sum of the bitwise XOR values of all its prefixes. Mathematically, it is:


$$\text{value}(RES) = \sum_{i=0}^{N-1} (RES[0] \oplus RES[1] \oplus \dots \oplus RES[i])$$

Find the **maximum possible value** of $RES$ across all possible starting indices and directions.

---

**Input Format**

* The first line contains a single integer $N$, representing the size of the array.
* The second line contains $N$ space-separated integers representing the elements of $ARR$.

**Output Format**

* Print a single integer representing the maximum possible value of $RES$.

**Constraints**

* $1 \le N \le 10^5$
* $0 \le ARR[i] \le 10^9$

---

**Example**
**Input:**

```text
5
1 2 4 5 8

```

**Output:**

```text
53

```

**Explanation:**
The optimal configuration is achieved by starting at index 4 (the number `8`) and moving to the **right**.
Because the array is cyclic, traversing to the right from index 4 gives the sequence:
`RES = [8, 1, 2, 4, 5]`

The prefix XORs of this sequence are:

1. $8 = 8$
2. $8 \oplus 1 = 9$
3. $8 \oplus 1 \oplus 2 = 11$
4. $8 \oplus 1 \oplus 2 \oplus 4 = 15$
5. $8 \oplus 1 \oplus 2 \oplus 4 \oplus 5 = 10$

The sum of these prefix XORs is $8 + 9 + 11 + 15 + 10 = 53$.

## 1. The Core Idea in 30 Seconds

We want to find the sum of all prefix XORs when starting circularly from any index $i$, but computing it naively takes **$O(N^2)$**. We can optimize this to **$O(N)$** using two insights:

1. **Math Trick**: You don't need to rebuild the prefix XOR array when starting at index $i$. All new prefix XOR values are just original values XORed with either $X$ or $Y$:
   - $X = \text{pref}[i - 1]$ (or $0$ if $i = 0$)
   - $Y = \text{total\_xor} \oplus X$
2. **Bit Trick**: We only care about the **sum** of values. Instead of computing each number, count how many numbers have bit $b$ set ($1$).
   $$\text{Sum} = \sum_{b=0}^{30} (\text{count of set bit } b) \times 2^b$$

---

## 2. Deriving the New Prefix XORs

Let $\text{pref}[k] = \text{arr}[0] \oplus \dots \oplus \text{arr}[k]$ and $\text{total\_xor} = \text{pref}[N-1]$.

When starting at index $i$, any circular prefix splits into two parts:

| Part | Range of $k$ | Formula | Why? |
|---|---|---|---|
| **Unwrapped** | $i \le k < N$ | $\text{pref}[k] \oplus X$ | Elements from $i$ to $k$: removes $\text{pref}[i-1]$. |
| **Wrapped** | $0 \le k < i$ | $\text{pref}[k] \oplus Y$ | Full wrap $[i \dots N-1]$ gives $Y$, then continues with $\text{pref}[k]$. |

> **Key Rule**: Every value in the new prefix XOR is simply $\text{pref}[k] \oplus X$ (for $k \ge i$) or $\text{pref}[k] \oplus Y$ (for $k < i$).

---

## 3. Counting Bits in $O(1)$

XORing numbers with a constant $C$ (where $C$ is $X$ or $Y$) changes bit counts predictably:

- **If bit $b$ of $C$ is `0`**: XOR with `0` leaves bits unchanged $\implies$ **count stays same**.
- **If bit $b$ of $C$ is `1`**: XOR with `1` flips all bits ($0 \leftrightarrow 1$) $\implies$ **new count = $\text{range\_length} - \text{old\_count}$**.

To get the count of set bits in any range in $O(1)$ time, precompute a cumulative table:
- `bit_count[k][b]` = count of numbers in $\text{pref}[0 \dots k]$ with bit $b$ set.
- Set bits in range $[L, R]$ = `bit_count[R][b] - bit_count[L-1][b]`.

---

## 4. Complete Step-by-Step Example

Let $\text{arr} = [1, 2, 3, 1]$ ($N = 4$):
- $\text{pref} = [1, 3, 0, 1]$
- $\text{total\_xor} = \text{pref}[3] = 1$

### Start at $i = 1$:
- $X = \text{pref}[0] = 1$ (binary `01`)
- $Y = \text{total\_xor} \oplus X = 1 \oplus 1 = 0$ (binary `00`)

#### Step A: Unwrapped Part (indices $1 \dots 3$, length = 3)
Values in `pref`: $[3, 0, 1]$:
- **Bit 0**: Contains two 1s (in $3$ and $1$).
  - Bit 0 of $X$ is `1` $\implies$ **FLIP**: $3 - 2 = \mathbf{1}$ one.
- **Bit 1**: Contains one 1 (in $3$).
  - Bit 1 of $X$ is `0` $\implies$ **KEEP**: $\mathbf{1}$ one.

#### Step B: Wrapped Part (indices $0 \dots 0$, length = 1)
Value in `pref`: $[1]$:
- **Bit 0**: Contains one 1.
  - Bit 0 of $Y$ is `0` $\implies$ **KEEP**: $\mathbf{1}$ one.
- **Bit 1**: Contains zero 1s.
  - Bit 1 of $Y$ is `0` $\implies$ **KEEP**: $\mathbf{0}$ ones.

#### Step C: Total Sum
- **Bit 0 total**: $(1 + 1) \times 2^0 = 2 \times 1 = \mathbf{2}$
- **Bit 1 total**: $(1 + 0) \times 2^1 = 1 \times 2 = \mathbf{2}$
- **Sum** = $2 + 2 = \mathbf{4}$

*(Verification: Rotated array is $[2, 3, 1, 1] \implies$ prefix XORs are $[2, 1, 0, 1] \implies$ sum is $2 + 1 + 0 + 1 = 4$. Exact match!)*

---

## 5. Algorithm & Complexity

```text
1. Compute pref[0...N-1] and total_xor.
2. Build bit_count[N][31] prefix table.
3. For each starting index i (0 to N-1):
     X = (i == 0) ? 0 : pref[i - 1]
     Y = total_xor ^ X
     sum = 0
     For b from 0 to 30:
       unwrapped_ones = count_ones(pref, range [i, N-1], bit b)
       if (b-th bit of X is 1) unwrapped_ones = (N - i) - unwrapped_ones

       wrapped_ones = count_ones(pref, range [0, i-1], bit b)
       if (b-th bit of Y is 1) wrapped_ones = i - wrapped_ones

       sum += (unwrapped_ones + wrapped_ones) * (1 << b)
     track_max(sum)
4. (Optional) Reverse arr and repeat if traversal can be counter-clockwise.
```

- **Time Complexity:** $O(N \times 31) = \mathbf{O(N)}$
- **Space Complexity:** $O(N \times 31) = \mathbf{O(N)}$