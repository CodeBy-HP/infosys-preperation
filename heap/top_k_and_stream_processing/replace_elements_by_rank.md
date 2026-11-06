# Replace Elements by Their Rank

## Problem Overview
Given an array of $N$ integers `arr`, replace each element of the array with its **rank**.
The rank represents how small an element is compared to others:
- The smallest element gets rank `1`.
- If two elements are equal, they must receive the **same rank**.
- Ranks are consecutive integers starting from `1`.

---

## Min-Heap Ordered Assignment Invariant
1. Store all elements along with their original indices as pairs: `{arr[i], i}`.
2. Insert all pairs into a **Min-Heap** (`std::priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>`).
3. Maintain:
   - `currentRank = 0`
   - `previousValue = INT_MIN`
4. Pop pairs `{val, index}` one-by-one from the min-heap:
   - If `val != previousValue`:
     $$\text{currentRank}++, \quad \text{previousValue} = val$$
   - Assign `result[index] = currentRank`.
5. Return the resulting `result` array.

---

## Complexity Analysis
- **Time Complexity:** $O(N \log N)$
- **Space Complexity:** $O(N)$ for min-heap and result array.

