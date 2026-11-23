
# Hand of Straights (LeetCode 846)

## Problem Overview

Alice has some number of cards and wants to rearrange them into groups such that:

- Each group contains exactly `groupSize` cards.
- Each group consists of `groupSize` consecutive card values.

Given an integer array `hand`, where `hand[i]` represents the value written on the ith card, and an integer `groupSize`, return `true` if Alice can rearrange all the cards into valid groups, or `false` otherwise.

---

## Examples

### Example 1

**Input:**
```python
hand = [1, 2, 3, 6, 2, 3, 4, 7, 8]
groupSize = 3
```

**Output:**
```python
true
```

**Explanation:**

Alice's hand can be rearranged into the following groups:

`[1, 2, 3], [2, 3, 4], [6, 7, 8]`

Each group contains exactly 3 consecutive cards.

### Example 2

**Input:**
```python
hand = [1, 2, 3, 4, 5]
groupSize = 4
```

**Output:**
```python
false
```

**Explanation:**

Alice cannot rearrange all the cards into groups of 4 consecutive cards.

---

## Constraints

- `1 <= hand.length <= 10^4`
- `0 <= hand[i] <= 10^9`
- `1 <= groupSize <= hand.length`


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

