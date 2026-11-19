# Next Smaller Element

## Problem Statement

Given an array of integers `arr` of size $n$, find the **Next Smaller Element (NSE)** for each element in the array.

The Next Smaller Element for an element at index $i$ is the first smaller element on its right side ($j > i$ such that $\text{arr}[j] < \text{arr}[i]$). If no smaller element exists to the right, consider it as `-1`.

Additionally, also support finding the **Previous Smaller Element (PSE)** for each element ($j < i$ such that $\text{arr}[j] < \text{arr}[i]$).

---

## Examples

### Example 1
- **Input:** `arr = [4, 5, 2, 10, 8]`
- **Next Smaller Element:** `[2, 2, -1, 8, -1]`
- **Explanation:**
  - For $4$, the next smaller element is $2$.
  - For $5$, the next smaller element is $2$.
  - For $2$, no smaller element exists to the right $\implies -1$.
  - For $10$, the next smaller element is $8$.
  - For $8$, no smaller element exists to the right $\implies -1$.

### Example 2
- **Input:** `arr = [3, 2, 1]`
- **Next Smaller Element:** `[2, 1, -1]`

---

## Constraints

- $1 \le n \le 10^5$
- $-10^9 \le \text{arr}[i] \le 10^9$

---

## Monotonic Increasing Stack Paradigm

To find the next smaller element to the right in $O(N)$ time:
- Traverse the array **from right to left** ($i = n - 1 \to 0$).
- Maintain a stack in **strictly increasing order** from bottom to top:
  - While `!st.empty() && st.top() >= arr[i]`: pop `st.top()` (these elements are $\ge \text{arr}[i]$ and will never serve as a smaller element for any element to the left of $i$).
  - If `st.empty()`, answer for $i$ is `-1`.
  - Else, answer for $i$ is `st.top()`.
  - Push `arr[i]` onto `st`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Monotonic Increasing Stack** | $O(N)$ | $O(N)$ stack |
| **Brute Force Nested Loops** | $O(N^2)$ | $O(1)$ |

