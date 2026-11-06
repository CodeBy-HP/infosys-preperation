# Leaders in an Array (Superior Elements)

## Problem Statement

Given an integer array `nums` of size $n$, find all the **leaders** in the array.
An element is called a **leader** if it is **greater than or equal to all the elements to its right side**.
The rightmost element is always a leader.

Return all leaders in the array (typically preserved in left-to-right order).

---

## Examples

### Example 1
- **Input:** `nums = [16, 17, 4, 3, 5, 2]`
- **Output:** `[17, 5, 2]`
- **Explanation:**
  - `17` is greater than `4, 3, 5, 2`.
  - `5` is greater than `2`.
  - `2` is the rightmost element.

### Example 2
- **Input:** `nums = [1, 2, 3, 4, 0]`
- **Output:** `[4, 0]`

---

## Constraints

- $1 \le n \le 10^5$
- $-10^9 \le \text{nums}[i] \le 10^9$

---

## Approaches

### Approach 1: Brute Force
For each element at index $i$, run an inner loop from $i + 1$ to $n - 1$. If any element is strictly greater than `nums[i]`, it is not a leader.
- **Time Complexity:** $\mathcal{O}(N^2)$
- **Space Complexity:** $\mathcal{O}(1)$

### Approach 2: Optimal Right-to-Left Suffix Scan
Notice that an element at index $i$ is a leader if and only if:
$$\text{nums}[i] \ge \max_{j = i + 1}^{n - 1} \text{nums}[j]$$

1. Traverse from right to left ($n - 1$ down to $0$).
2. Maintain `max_from_right` initialized to negative infinity (or `nums[n - 1]`).
3. If `nums[i] >= max_from_right`:
   - `nums[i]` is a leader; append to leaders list.
   - Update `max_from_right = nums[i]`.
4. Reverse the collected leaders list to restore the original left-to-right ordering.
- **Time Complexity:** $\mathcal{O}(N)$
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Brute Force** | $\mathcal{O}(N^2)$ | $\mathcal{O}(1)$ |
| **Right-to-Left Scan** | $\mathcal{O}(N)$ | $\mathcal{O}(1)$ auxiliary |

