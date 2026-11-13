# Find the Repeating and Missing Number

## Problem Statement

You are given a read-only array of $n$ integers with values also in the range $[1, n]$ both inclusive. Each integer appears exactly once except $A$ which appears **twice** and $B$ which is **missing**.

Return $[A, B]$ (the repeating number followed by the missing number).

---

## Examples

### Example 1
- **Input:** `nums = [3, 1, 2, 5, 3]`
- **Output:** `[3, 4]`
- **Explanation:** $3$ occurs twice, and $4$ is missing from $[1, 5]$.

### Example 2
- **Input:** `nums = [3, 1, 3]`
- **Output:** `[3, 2]`

---

## Constraints

- $2 \le n \le 10^5$
- $1 \le \text{nums}[i] \le n$

---

## Approaches

### Approach 1: Frequency Array / Hash Map (Brute Force)
Count frequencies using an array of size $n + 1$. The element with frequency $2$ is $A$, and the element with frequency $0$ is $B$.
- **Time Complexity:** $\mathcal{O}(N)$
- **Space Complexity:** $\mathcal{O}(N)$

### Approach 2: Mathematical Sum and Sum of Squares (Optimal 1)
Let $S$ be the sum of elements in `nums`, and $S_n = \frac{n(n + 1)}{2}$.
$$S - S_n = A - B$$

Let $S_2$ be the sum of squares of elements in `nums`, and $S_{2n} = \frac{n(n + 1)(2n + 1)}{6}$.
$$S_2 - S_{2n} = A^2 - B^2 = (A - B)(A + B)$$

Dividing the two equations gives:
$$A + B = \frac{S_2 - S_{2n}}{A - B}$$

Now we have a system of two linear equations:
$$A = \frac{(A - B) + (A + B)}{2}, \quad B = (A + B) - A$$
- **Time Complexity:** $\mathcal{O}(N)$
- **Space Complexity:** $\mathcal{O}(1)$

### Approach 3: Bitwise XOR Partitioning (Optimal 2)
XOR all elements in `nums` with all numbers from $1$ to $n$:
$$\text{xor\_val} = \left( \bigoplus_{x \in \text{nums}} x \right) \oplus \left( \bigoplus_{i=1}^{n} i \right) = A \oplus B$$

Since $A \ne B$, $\text{xor\_val} \ne 0$, meaning at least one bit differs between $A$ and $B$.
Isolate the rightmost set bit:
$$\text{differentiating\_bit} = \text{xor\_val} \ \& \ (-\text{xor\_val})$$

Partition all elements of `nums` and all numbers from $1$ to $n$ into two groups based on this bit:
- Group 1: numbers with the bit set.
- Group 2: numbers with the bit unset.
XORing within each group isolates $A$ and $B$. A quick verification pass identifies which is the duplicate.
- **Time Complexity:** $\mathcal{O}(N)$
- **Space Complexity:** $\mathcal{O}(1)$ (Zero overflow risk!)

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Overflow Risk |
| :--- | :--- | :--- | :--- |
| **Frequency Array** | $\mathcal{O}(N)$ | $\mathcal{O}(N)$ | None |
| **Math Equations** | $\mathcal{O}(N)$ | $\mathcal{O}(1)$ | Handled via `long long` |
| **Bitwise XOR** | $\mathcal{O}(N)$ | $\mathcal{O}(1)$ | **Zero** |

