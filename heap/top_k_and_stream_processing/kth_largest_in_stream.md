# K-th Largest Element in a Stream (LeetCode 703)

## Problem Overview
Design a class to find the $k^{\text{th}}$ largest element in a stream. Note that it is the $k^{\text{th}}$ largest element in the sorted order, not the $k^{\text{th}}$ distinct element.
Implement `KthLargest` class:
- `KthLargest(int k, int[] nums)`: Initializes the object with the integer $k$ and the stream of integers `nums`.
- `int add(int val)`: Appends the integer `val` to the stream and returns the element representing the $k^{\text{th}}$ largest element in the stream.

---

## Min-Heap of Capacity $K$ Invariant
To maintain the $k^{\text{th}}$ largest element dynamically:
1. Maintain a **Min-Heap `std::priority_queue<int, vector<int>, greater<int>>`** storing only the **$k$ largest elements seen so far across the entire stream**.
2. For each incoming number `val`:
   - Push `val` into the min-heap.
   - If `heap.size() > k`, pop the smallest element via `pop()`.
3. Because the min-heap always holds exactly the $k$ largest elements, its **top element is mathematically guaranteed to be the $k^{\text{th}}$ largest**:
   $$\text{Result} = \text{heap.top()}$$

---

## Complexity Analysis
- **Constructor Time:** $O(N \log K)$ where $N$ is initial array size.
- **`add()` Time:** $O(\log K)$ per incoming stream query.
- **Space Complexity:** $O(K)$ space strictly bounded by $k$.

