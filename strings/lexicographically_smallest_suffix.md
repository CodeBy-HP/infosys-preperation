**Problem Statement**
You are provided with a main string $S$ of length $N$. You must process a series of queries against this string.

**Query Definition**
For each query, you are given a search string $T$. You need to perform the following steps:

1. Identify all suffixes of the main string $S$ that begin with the exact prefix $T$.


2. Out of all these valid suffixes, find the single suffix that is lexicographically (alphabetically) smallest.


3. Determine the length of this lexicographically smallest suffix.


4. If there is no suffix in $S$ that starts with $T$, the query result is 0.



**Expected Output**
Keep a running total of the lengths returned by every query. Because this sum can grow very large, you must return the final total modulo $10^9 + 7$.

**Example Walkthrough**

* **Input String $S$:** `mzadpoghyykht` (Length $N = 13$)


* **Number of Queries:** 1


* **Query String $T$:** `yk`


* **Execution:**
* If we list the suffixes of $S$, they are: `mzadpoghyykht`, `zadpoghyykht`, ..., `yykht`, `ykht`, `kht`, `ht`, `t`.
* We look for suffixes starting with `yk`. There is only one match: `ykht`.
* Since `ykht` is the only match, it is automatically the lexicographically smallest.
* The length of the string `ykht` is 4.


* **Output:** 4