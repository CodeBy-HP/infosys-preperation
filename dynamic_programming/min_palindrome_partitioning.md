## DSA problem (**Palindrome Partitioning II**):


You are given a string **S**.

Split the string into the **minimum number of contiguous substrings** such that **every substring is a palindrome**.

A **palindrome** is a string that reads the same forwards and backwards.

Return the **minimum number of palindromic substrings** required to partition the entire string.

**Note:**

* Every character of the string must belong to exactly one substring.


* Consider both **odd-length** and **even-length** palindromes while partitioning.



---

### **Input Format**

* A single string **S** consisting of lowercase English letters.



### **Output Format**

* Return an integer representing the minimum number of palindromic substrings required.

### **Constraints**

* $1 \le \text{length of } S \le 2000$
* $S$ consists of lowercase English letters only.

### **Examples**

#### **Example 1:**

* **Input:** `S = "aab"`
* **Output:** `2`
* **Explanation:** The palindrome partitioning that uses the minimum number of substrings is `["aa", "b"]`. Total number of substrings = $2$.

#### **Example 2:**

* **Input:** `S = "a"`
* **Output:** `1`
* **Explanation:** The string itself is already a palindrome, so only $1$ substring is needed (`["a"]`).

#### **Example 3:**

* **Input:** `S = "ababbbabbababa"`
* **Output:** `3`
* **Explanation:** One optimal partitioning is `["aba", "babbabb", "ababa"]` or similar depending on the valid palindrome combinations.


# Map Constraints to Acceptable ComplexitiesMemorize this standard guide for $N$:
* $N \le 10$ to $12$: $O(N!)$ or $O(2^N \cdot N)$ (Backtracking / Bitmask DP)
* $N \le 400$ to $500$: $O(N^3)$ (Matrix chain multiplication style DP)
* $N \le 2000$ to $5000$: $O(N^2)$ (Classic 2D DP or 1D DP with an inner loop)
* $N \le 10^5$ to $10^6$: $O(N \log N)$ or $O(N)$ (Greedy, Sorting, 1D linear DP)