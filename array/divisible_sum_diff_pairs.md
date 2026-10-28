

## Problem Statement



You are given an integer array `a` of size `n` and two integers `D` and `M`.

Your task is to count the number of **unordered pairs** `(i, j)` such that:

* $0 \le i < j < n$

* `(a[i] + a[j]) % D == 0`

* `|a[i] - a[j]| % M == 0`


Return the total number of pairs satisfying both conditions.

---

## Input Format



* The first line contains three integers `n`, `D`, and `M`.


* The second line contains `n` space-separated integers representing the array `a`.



## Output Format



* Print a single integer representing the number of valid unordered pairs.



---

## Constraints



* $1 \le n \le 10^5$

* $1 \le D, M \le 10^9$

* $-10^9 \le a[i] \le 10^9$


---

## Example 1



**Input**

```text
5 3 2
1 2 5 4 7

```

**Output**

```text
4

```