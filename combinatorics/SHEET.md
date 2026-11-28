### 1. Must-Know Combinatorics Formulas for Coding Assessments

| Pattern | Formula | When to Spot It |
| --- | --- | --- |
| **Combinations** (Order doesn't matter) | $\binom{n}{r} = \frac{n!}{r!(n-r)!}$ | Picking a team, choosing positions for identical characters. Memorize $\binom{n}{2} = \frac{n(n-1)}{2}$ and $\binom{n}{3} = \frac{n(n-1)(n-2)}{6}$. |
| **Permutations** (Order matters) | $P(n, r) = \frac{n!}{(n-r)!}$ | Arranging distinct items in a line, assigning distinct ranks/roles. |
| **Arranging with Duplicates** | $\frac{n!}{c_1! \cdot c_2! \cdots c_k!}$ | Counting unique anagrams of a string (e.g., `"AABBBC"` $\to \frac{6!}{2!3!1!}$). |
| **Stars & Bars** (Empty bins allowed) | $\binom{n + k - 1}{k - 1}$ | Distributing $n$ identical coins into $k$ distinct people (someone can get 0), or non-negative integer solutions to $x_1 + \dots + x_k = n$. |
| **Stars & Bars** (Every bin $\ge 1$) | $\binom{n - 1}{k - 1}$ | Splitting an array of length $n$ into $k$ non-empty contiguous subarrays. |
| **Grid Paths** | $\binom{R + C}{R}$ | Counting paths from $(0,0)$ to $(R, C)$ moving only Right and Down. |
| **Catalan Numbers** | $C_n = \frac{1}{n+1}\binom{2n}{n}$ | Valid parentheses of $n$ pairs, number of unique BSTs with $n$ nodes. |

---

### 2. Three Coding Tricks You Need for OAs

Knowing the math isn't enough—OAs test whether you can implement it without overflowing or getting TLE:

1. **Complementary Counting (`Total - Invalid`):** Whenever a problem says *"at least one..."* (e.g., "strings with at least one vowel"), it is almost always faster to calculate `Total Strings - Strings with 0 vowels`.
2. **Division Under Modulo ($10^9 + 7$):** You **cannot** do `(a / b) % M`. Because $M = 10^9 + 7$ is prime, use Fermat's Little Theorem to replace division by `b` with multiplication by `power(b, M - 2) % M`.
3. **Precompute `fact[]` and `invFact[]`:** If you need $\binom{n}{r} \pmod M$ inside a loop, precompute factorials up to $N$ in $O(N)$ so every $\binom{n}{r}$ query runs in $O(1)$.