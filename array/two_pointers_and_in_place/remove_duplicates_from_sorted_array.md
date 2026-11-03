# Remove Duplicates from Sorted Array (LeetCode 26)

## Problem Statement
Given an integer array `nums` sorted in **non-decreasing order**, remove the duplicates **in-place** such that each unique element appears only once. The **relative order** of the elements should be kept the same. Then return the number of unique elements in `nums`.

Consider the number of unique elements of `nums` to be `k`. To get accepted, you need to do the following things:
1. Change the array `nums` such that the first `k` elements of `nums` contain the unique elements in the order they were present in `nums` initially.
2. The remaining elements of `nums` are not important, as well as the size of `nums`.
3. Return `k`.

### Custom Judge:
The judge will test your solution with the following code:
```java
int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
```

### Example 1:
```
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
```

### Example 2:
```
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
```

### Constraints:
- `1 <= nums.length <= 3 * 10^4`
- `-100 <= nums[i] <= 100`
- `nums` is sorted in non-decreasing order.

---

## Pattern Insight: Two Pointers (Reader & Writer In-Place Compaction)
- Because `nums` is already sorted, all duplicate occurrences of any number appear in contiguous clusters.
- Maintain two pointers:
  - `writer`: index where the next unique element should be written (starts at index `1`).
  - `reader`: scans through the array from index `1` to `n - 1`.
- When `nums[reader] != nums[reader - 1]`:
  - We have encountered a new unique element!
  - Write it to `nums[writer]`, and advance `writer++`.
- When the scan completes, `writer` equals the number of unique elements $k$.
- Executes in $O(N)$ time with strictly $O(1)$ auxiliary memory.

---

## Complexity
- **Time Complexity:** $O(N)$ single pass.
- **Space Complexity:** $O(1)$ strictly in-place.

