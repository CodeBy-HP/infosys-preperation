# Minimum Multiplications to Reach End

## Problem Overview
Given `start`, `end`, and an array `arr` of integers. At each step, `start` is multiplied with any number in the array and then modulo $100,000$ is taken to get the next number:
$$\text{next} = (\text{curr} \times arr[i]) \pmod{100,000}$$
Find the **minimum number of multiplications** required to reach `end` from `start`. If not possible, return `-1`.

---

## State-Space Modulo BFS ($10^5$ States)
1. The space of all reachable states is strictly bounded by the modulo: $[0, 99999]$ ($10^5$ possible values).
2. Because each multiplication costs exactly **1 step**, this is an **unweighted graph shortest-path problem** solvable via BFS in $O(10^5 \times |arr|)$ time!
3. Maintain a distance array `dist[100000]` initialized to $\infty$.
4. Set `dist[start] = 0`, push `{0, start}` into a queue.
5. Pop `{steps, curr}`. If `curr == end`, return `steps`.
6. For each element $x \in arr$:
   $$num = (curr \times x) \pmod{100000}$$
   If $steps + 1 < dist[num]$:
   $$dist[num] = steps + 1, \quad \text{push } \{steps + 1, num\}$$

---

## Complexity Analysis
- **Time Complexity:** $O(100,000 \times N)$ where $N = |arr|$.
- **Space Complexity:** $O(100,000)$ for queue and distance array.

