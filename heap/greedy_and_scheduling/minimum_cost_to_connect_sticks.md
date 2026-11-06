# Minimum Cost to Connect Sticks (LeetCode 1167)

## Problem Overview
You have some number of sticks with positive integer lengths.
You can connect any two sticks of lengths $x$ and $y$ by paying a cost of $x + y$. You must continue connecting sticks until there is only one stick remaining.
Return the **minimum cost of connecting all the given sticks** in this manner.

---

## Huffman Coding Greedy Min-Heap Invariant
Connecting sticks creates an implicit binary merge tree:
- Sticks merged earliest have their lengths added repeatedly into every subsequent merge.
- To minimize the total cumulative cost, the **smallest sticks must be merged first** so their contributions are minimized.
- This is mathematically identical to **Huffman Optimal Prefix Code Tree Construction**!

### Algorithm:
1. Insert all stick lengths into a **Min-Heap** (`std::priority_queue<int, vector<int>, greater<int>>`).
2. Maintain `totalCost = 0`.
3. While `minHeap.size() > 1`:
   - Pop the two smallest sticks: $a = minHeap.top()$, $b = minHeap.top()$.
   - Pay connection cost: $cost = a + b$.
   - Accumulate: $totalCost += cost$.
   - Push the new merged stick of length $cost$ back into the min-heap.
4. When only 1 stick remains, return `totalCost`.

---

## Complexity Analysis
- **Time Complexity:** $O(N \log N)$ because each of the $N - 1$ merges does 2 pops and 1 push in $O(\log N)$.
- **Space Complexity:** $O(N)$ for the min-heap.

