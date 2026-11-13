# Sliding Window X-th Smallest Element (The Two Multisets Pattern)

## Problem Statement

Given an integer array `nums` of size $N$, a sliding window size $k$, and an integer $x$ ($1 \le x \le k$), return an array containing the **$x^{\text{th}}$ smallest element** in each contiguous sliding window of size $k$.

---

## Examples

### Example 1
- **Input:** `nums = [1, 5, 2, 8, 3, 7]`, `k = 3`, `x = 2`
- **Output:** `[2, 5, 3, 7]`
- **Explanation:**
  - Window 1: `[1, 5, 2]` $\to$ sorted: `[1, 2, 5]`. $2^{\text{nd}}$ smallest is `2`.
  - Window 2: `[5, 2, 8]` $\to$ sorted: `[2, 5, 8]`. $2^{\text{nd}}$ smallest is `5`.
  - Window 3: `[2, 8, 3]` $\to$ sorted: `[2, 3, 8]`. $2^{\text{nd}}$ smallest is `3`.
  - Window 4: `[8, 3, 7]` $\to$ sorted: `[3, 7, 8]`. $2^{\text{nd}}$ smallest is `7`.

### Example 2
- **Input:** `nums = [10, -5, -10, 20], k = 2, x = 1`
- **Output:** `[-5, -10, -10]`
- **Explanation:** For $x = 1$, the problem simplifies to the sliding window minimum.

---

## Constraints

- $1 \le k \le N \le 10^5$
- $1 \le x \le k$
- $-10^9 \le \text{nums}[i] \le 10^9$

---

## Paradigm Shift: Why Frequency Buckets Fail

In [Problem 11: Sliding Subarray Beauty](sliding_subarray_beauty.md), numbers were bounded in $[-50, 50]$, allowing $O(50)$ frequency bucket traversal.

Here, numbers range from $-10^9$ to $10^9$.
- Allocating a direct frequency array of size $2 \times 10^9$ requires $\approx 8 \text{ GB}$ of RAM, triggering an immediate **Memory Limit Exceeded (MLE)** or segmentation fault.
- When values are unbounded, we must maintain the **relative sorted order** of elements dynamically rather than their absolute values.

---

## The "Two Multisets" Partition Invariant

In C++, `std::multiset` is a self-balancing Binary Search Tree (Red-Black Tree) supporting insertion, deletion, and boundary queries in $\mathcal{O}(\log k)$ time.

We partition the elements of the current window across two multisets:
1. **`left` multiset:** Always maintained to hold **exactly $x$ elements**, which represent the **$x$ smallest elements** in the current window.
2. **`right` multiset:** Holds the remaining $(k - x)$ elements (the larger elements).

### The Core Invariant
Because `left` holds the $x$ smallest elements sorted in non-decreasing order:
$$\text{The } x^{\text{th}} \text{ smallest element in the entire window} = \text{The maximum element in } \text{left} = \text{*left.rbegin()}$$

---

## Balancing & Operations

### 1. Adding an Element `val`:
- If `left.empty()` or `val <= *left.rbegin()`:
  - Insert into `left`.
- Else:
  - Insert into `right`.
- **Rebalance:**
  - If `left.size() > x`: Move `*left.rbegin()` to `right`.
  - If `left.size() < x` and `!right.empty()`: Move `*right.begin()` to `left`.

### 2. Removing Outgoing Element `val`:
⚠️ **Crucial C++ `std::multiset` Trapping Rule:**
Executing `left.erase(val)` removes **all duplicate occurrences** of `val`.
To remove strictly **one** instance of `val`, find its iterator first and erase the iterator:
```cpp
auto it = left.find(val);
if (it != left.end()) {
    left.erase(it);
} else {
    it = right.find(val);
    if (it != right.end()) {
        right.erase(it);
    }
}
```
- **Rebalance:**
  - If `left.size() < x && !right.empty()`:
    - Move `*right.begin()` into `left`.

### 3. Querying:
Return `*left.rbegin()` in $\mathcal{O}(1)$ time.

---

## Complexity Analysis

| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Insert / Erase** | $\mathcal{O}(\log k)$ | $\mathcal{O}(k)$ |
| **Rebalance** | $\mathcal{O}(\log k)$ amortized | $\mathcal{O}(1)$ |
| **Query $x^{\text{th}}$ Smallest** | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ |
| **Total Algorithm** | $\mathcal{O}(N \log k)$ | $\mathcal{O}(k)$ |

