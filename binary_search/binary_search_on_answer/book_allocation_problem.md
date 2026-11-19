# Book Allocation Problem (Allocate Minimum Number of Pages)

## Problem Statement

You are given an array `arr` of $N$ integers, where `arr[i]` represents the number of pages in the $i$-th book. You are also given an integer $M$ representing the number of students.

Allocate books to students such that:
1. Each student gets at least one book.
2. Each book should be allocated to exactly one student.
3. Book allocation to a student must be **contiguous**.

Allocate books to all $M$ students such that the **maximum number of pages assigned to a student is minimized**.

If allocation is not possible (e.g., $M > N$), return `-1`.

---

## Examples

### Example 1
- **Input:** `arr = [12, 34, 67, 90]`, `M = 2`
- **Output:** `113`
- **Explanation:**
  - Allocation: Student 1 gets `[12, 34, 67]` (sum = 113), Student 2 gets `[90]` (sum = 90).
  - Maximum pages assigned = $\max(113, 90) = 113$. This is the minimum possible maximum.

### Example 2
- **Input:** `arr = [25, 46, 28, 49, 24]`, `M = 4`
- **Output:** `71`
- **Explanation:**
  - Student 1: `[25, 46]` (71)
  - Student 2: `[28]` (28)
  - Student 3: `[49]` (49)
  - Student 4: `[24]` (24)
  - Max pages = 71.

### Example 3
- **Input:** `arr = [10, 20, 30]`, `M = 4`
- **Output:** `-1`
- **Explanation:** Since $M > N$, it is impossible for each student to get at least one book.

---

## Constraints

- $1 \le N \le 10^5$
- $1 \le M \le 10^5$
- $1 \le \text{arr}[i] \le 10^9$

---

## Monotonic Decision Invariant

If the maximum pages allowed per student is $P$:
- As $P$ increases, the number of students required decreases (monotonically non-increasing function).

### Search Range
- **Minimum possible bound:** $\max(\text{arr})$ (the student getting the largest book must be allocated at least that many pages).
- **Maximum possible bound:** $\sum \text{arr}$ (one student gets all books).

### Binary Search Transition
- Check feasibility with `countStudents(arr, mid)`:
  - If students required $\le M$: $mid$ is achievable! Try minimizing further: `right = mid - 1`, `ans = mid`.
  - If students required $> M$: $mid$ is too restrictive, we need to allow more pages: `left = mid + 1`.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Binary Search on Answer** | $O(N \log(\sum \text{arr}))$ | $O(1)$ |
| **Linear Search Range Probing** | $O(N \times (\sum \text{arr} - \max(\text{arr})))$ | $O(1)$ |

