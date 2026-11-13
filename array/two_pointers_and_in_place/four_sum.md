# 4Sum (LeetCode 18)

## Problem Statement

Given an array `nums` of $n$ integers, return an array of all the **unique quadruplets** `[nums[a], nums[b], nums[c], nums[d]]` such that:
- $0 \le a, b, c, d < n$
- $a, b, c,$ and $d$ are **distinct**.
- $\text{nums}[a] + \text{nums}[b] + \text{nums}[c] + \text{nums}[d] == \text{target}$

You may return the answer in any order. The solution set must not contain duplicate quadruplets.

---

## Examples

### Example 1
- **Input:** `nums = [1, 0, -1, 0, -2, 2]`, `target = 0`
- **Output:** `[[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]`

### Example 2
- **Input:** `nums = [2, 2, 2, 2, 2]`, `target = 8`
- **Output:** `[[2, 2, 2, 2]]`

---

## Constraints

- $1 \le \text{nums.length} \le 200$
- $-10^9 \le \text{nums}[i] \le 10^9$
- $-10^9 \le \text{target} \le 10^9$

---

## Approaches

### Approach 1: Brute Force (4 Loops + Set Deduplication)
Generate all 4-tuples using 4 nested loops. If their sum equals `target`, sort the quadruplet and insert it into a `std::set`.
- **Time Complexity:** $\mathcal{O}(N^4 \log(\dots))$
- **Space Complexity:** $\mathcal{O}(N)$ for the set

### Approach 2: Better (3 Loops + Hash Set)
Fix the first 3 elements with 3 nested loops. The required fourth element is $\text{target} - (nums[i] + nums[j] + nums[k])$. Check for its presence in a hash set.
- **Time Complexity:** $\mathcal{O}(N^3)$
- **Space Complexity:** $\mathcal{O}(N)$

### Approach 3: Optimal (Sort + Fixed Pivots + Two Pointers)
1. Sort `nums` in ascending order.
2. Loop $i$ from $0$ to $n - 4$:
   - If $i > 0$ and `nums[i] == nums[i - 1]`, skip duplicate.
3. Loop $j$ from $i + 1$ to $n - 3$:
   - If $j > i + 1$ and `nums[j] == nums[j - 1]`, skip duplicate.
4. Two pointers: $k = j + 1$ and $l = n - 1$.
   - Calculate $\text{sum} = 1\text{LL} \times \text{nums}[i] + \text{nums}[j] + \text{nums}[k] + \text{nums}[l]$ (using `long long` to prevent 32-bit overflow).
   - If $\text{sum} == \text{target}$:
     - Record `[nums[i], nums[j], nums[k], nums[l]]`.
     - Skip identical elements for $k++$ and $l--$.
   - Else if $\text{sum} < \text{target}$: $k++$.
   - Else: $l--$.
- **Time Complexity:** $\mathcal{O}(N^3)$
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Brute Force** | $\mathcal{O}(N^4)$ | $\mathcal{O}(N)$ |
| **Hash Set** | $\mathcal{O}(N^3)$ | $\mathcal{O}(N)$ |
| **Sort + Two Pointers** | $\mathcal{O}(N^3)$ | $\mathcal{O}(1)$ auxiliary |

