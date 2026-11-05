# Problem 21: Baby-Step Giant-Step (Discrete Logarithm)

## Problem Statement

Given integers $a, b,$ and a prime modulus $m$ with $\gcd(a, m) = 1$, find the **smallest non-negative integer $x$** satisfying:
$$a^x \equiv b \pmod m$$

If no such integer $x$ exists, return `-1`.

---

## Examples

### Example 1
- **Input:** $a = 2$, $b = 8$, $m = 11$
- **Output:** `3`
- **Explanation:** $2^3 = 8 \equiv 8 \pmod{11}$.

### Example 2
- **Input:** $a = 2$, $b = 7$, $m = 13$
- **Output:** `11`
- **Explanation:** $2^{11} = 2048 \equiv 7 \pmod{13}$.

---

## Mathematical Principle: Meet-in-the-Middle on Exponents

A naive linear search through all possible values of $x \in [0, m - 1]$ takes $\mathcal{O}(m)$ time. When $m \approx 10^9$, this causes TLE.

The **Baby-Step Giant-Step (BSGS)** algorithm applies a **Meet-in-the-Middle** decomposition.

Let:
$$k = \lceil \sqrt{m} \rceil$$

Any integer $x \in [0, m - 1]$ can be uniquely represented as:
$$x = i \cdot k - j \quad \text{where } 1 \le i \le k \text{ and } 0 \le j < k$$

Substitute $x$ into the discrete logarithm equation:
$$a^{i \cdot k - j} \equiv b \pmod m$$

Multiply both sides by $a^j$:
$$(a^k)^i \equiv b \cdot a^j \pmod m$$

---

## Algorithm Steps

### Step 1: Baby Steps
Iterate $j$ from $0$ to $k - 1$:
- Compute $V_{\text{baby}} = (b \cdot a^j) \pmod m$.
- Store in a hash map: `table[V_baby] = j`.
*(If duplicates occur, record the maximum $j$ to minimize $x = i \cdot k - j$)*.

### Step 2: Giant Steps
Compute the giant base $C = a^k \pmod m$.
Iterate $i$ from $1$ to $k$:
- Compute $V_{\text{giant}} = C^i \pmod m$.
- Check if $V_{\text{giant}}$ exists in `table`.
- If found:
  $$x = i \cdot k - \text{table}[V_{\text{giant}}]$$
  Return $x$ immediately (the first match produces the minimal non-negative solution).

If no match is found after checking all $i \in [1, k]$, no solution exists.

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $\mathcal{O}(\sqrt{m})$ operations ($\approx 3.16 \times 10^4$ operations for $m = 10^9$) |
| **Space Complexity** | $\mathcal{O}(\sqrt{m})$ for the hash map |
