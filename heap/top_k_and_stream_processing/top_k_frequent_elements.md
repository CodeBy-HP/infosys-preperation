# Top K Frequent Elements (LeetCode 347)

## Problem Overview
Given an integer array `nums` and an integer `k`, return the **$k$ most frequent elements**.
You may return the answer in **any order**.

---

## 1. Min-Heap of Size $K$ ($O(N \log K)$)
1. Count the frequencies of each unique number in an `unordered_map<int, int> freq`.
2. Maintain a **Min-Heap** storing `{frequency, num}` ordered by smallest frequency.
3. For each pair `{num, count}` in the frequency map:
   - Push `{count, num}` into the min-heap.
   - If `minHeap.size() > k`, pop the element with the lowest frequency.
4. When all unique numbers have been processed, the min-heap holds the $K$ most frequent elements!
- **Time Complexity:** $O(N \log K)$
- **Space Complexity:** $O(N)$

---

## 2. Bucket Sort ($O(N)$ Strictly Linear)
Since any element's frequency is bounded by $[1, N]$:
1. Count frequencies in a hash map.
2. Create an array of buckets: `vector<vector<int>> buckets(N + 1)` where `buckets[f]` contains all numbers with frequency $f$.
3. Traverse `buckets` backwards from $N$ down to $1$, collecting numbers until $K$ elements are accumulated!
- **Time Complexity:** $O(N)$
- **Space Complexity:** $O(N)$

