# Hand of Straights (LeetCode 846)

## Problem Overview
Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size `groupSize`, and consists of `groupSize` consecutive cards.
Given an integer array `hand` where `hand[i]` is the value written on the $i^{\text{th}}$ card and an integer `groupSize`, return `true` if she can rearrange the cards, or `false` otherwise.

---

## Min-Heap & Frequency Map Invariant
1. **Divisibility Check:** If $|hand| \pmod{groupSize} \ne 0$, it is impossible to form complete groups $\implies$ return `false`.
2. Count the frequency of each card in an `unordered_map<int, int> count`.
3. Insert all unique card values into a **Min-Heap** (`std::priority_queue<int, vector<int>, greater<int>>`).
4. While the min-heap is not empty:
   - Pop the smallest card value `start = minHeap.top()`.
   - If `count[start] == 0`, this card has already been consumed by an earlier sequence $\implies$ continue.
   - The card `start` **must** serve as the beginning of `c = count[start]` consecutive groups!
   - For $k = 0 \dots groupSize - 1$:
     - Check card `curr = start + k`.
     - If `count[curr] < c`, we cannot form the required consecutive straights $\implies$ return `false`.
     - Deduct `count[curr] -= c`.
5. If all groups are formed successfully, return `true`.

---

## Complexity Analysis
- **Time Complexity:** $O(N \log N)$ where $N$ is the number of cards.
- **Space Complexity:** $O(N)$ for frequency map and min-heap.

