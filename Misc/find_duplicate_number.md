# 287. Find the Duplicate Number

[LeetCode Problem](https://leetcode.com/problems/find-the-duplicate-number/)

**Difficulty:** Medium

## Problem Statement

Given an array of integers `nums` containing `n + 1` integers where each integer is in the range `[1, n]` inclusive.

There is only **one repeated number** in `nums`. Return *this repeated number*.

You must solve the problem **without** modifying the array `nums` and using only constant extra space.

## Examples

**Example 1:**
```text
Input: nums = [1,3,4,2,2]
Output: 2
````

**Example 2:**

```
Input: nums = [3,1,3,4,2]
Output: 3
```

**Example 3:**

```
Input: nums = [3,3,3,3,3]
Output: 3
```

## **Constraints**

- `1 <= n <= 10^5`
- `nums.length == n + 1`
- `1 <= nums[i] <= n`
- All the integers in `nums` appear only once except for precisely one integer which appears two or more times.


---
---

> **Treat every array INDEX as a Linked List Node, and treat the VALUE inside it as its `next` pointer.**

---

## 1. Watch Example 1 Turn Into a Linked List

Take `nums = [1, 3, 4, 2, 2]`:

| Index (Node) | `0` | `1` | `2` | `3` | `4` |
| --- | --- | --- | --- | --- | --- |
| **Value (`node->next`)** | `1` | `3` | `4` | `2` | `2` |

Now start at index **`0`** and just follow the arrows (`index -> nums[index]`):

* Index **`0`** holds `1` $\rightarrow$ jump to **`1`**
* Index **`1`** holds `3` $\rightarrow$ jump to **`3`**
* Index **`3`** holds `2` $\rightarrow$ jump to **`2`**
* Index **`2`** holds `4` $\rightarrow$ jump to **`4`**
* Index **`4`** holds `2` $\rightarrow$ jump back to **`2`** (LOOP!)

Draw that out and it is literally a Linked List with a cycle:

```text
0  --->  1  --->  3  --->  2  --->  4
                           ^        |
                           |________|

```

---

## 2. Why the Duplicate Is ALWAYS the Cycle Entry

Look at node **`2`** in the diagram above. Notice anything special about it?

* Index **`3`** points to `2` (`nums[3] = 2`).
* Index **`4`** *also* points to `2` (`nums[4] = 2`).

**Two different indices hold the same value `2` $\iff$ two different arrows point INTO node `2`.**

In a linked list where every node has only one `next` arrow, what is the **only** node that can have two incoming arrows? **The Cycle Entry!**

And two quick constraints make this 100% airtight:

1. **Never goes out of bounds:** Every value is in `[1, n]`, and the valid indices are `[0, n]`. So every `nums[i]` is guaranteed to be a valid index to jump to.
2. **Why we always start at index `0`:** Because values are in `[1, n]`, **no index can ever hold `0**`. That means nothing can ever point back to `0`—so `0` is guaranteed to sit outside the cycle at the start of the tail.

---

## 3. Literal Line-by-Line Translation From LC 142

| Linked List Cycle II (LC 142) | Find the Duplicate Number (LC 287) |
| --- | --- |
| `slow = head` | `slow = 0` |
| `slow = slow->next` | `slow = nums[slow]` |
| `fast = fast->next->next` | `fast = nums[nums[fast]]` |



