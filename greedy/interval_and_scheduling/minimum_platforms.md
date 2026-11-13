# Minimum Number of Platforms Required for a Railway

## Problem Overview
Given arrival and departure times of all trains that reach a railway station. Find the **minimum number of platforms required** for the railway station so that no train is kept waiting.
Consider that all trains arrive on the same day and leave on the same day.
Arrival and departure time can never be the same for a train, but we can have arrival time of one train equal to departure time of another. At any given instant, the same platform cannot be used for both departure of a train and arrival of another train (in such cases, platforms cannot be shared at the exact collision second).

---

## Chronological Sweep-Line Invariant
The minimum number of platforms required is mathematically equivalent to the **maximum number of trains present at the station simultaneously** at any point on the timeline.
Instead of tracking which train is on which platform:
1. **Sort arrival times `arr` and departure times `dep` independently**:
   - We do not need to preserve which arrival corresponds to which departure!
   - Every arrival increments active train count (`+1`).
   - Every departure decrements active train count (`-1`).
2. Two-pointer timeline simulation:
   - Pointer `i` on `arr`, pointer `j` on `dep`.
   - If `arr[i] <= dep[j]`:
     A new train arrives before a previously parked train leaves $\implies$ platform required:
     $$\text{currentPlatforms}++, \quad i++$$
   - Else:
     A train has successfully departed $\implies$ platform is freed:
     $$\text{currentPlatforms}--, \quad j++$$
3. Maintain $\text{maxPlatforms} = \max(\text{maxPlatforms}, \; \text{currentPlatforms})$.

---

## Complexity Analysis
- **Time Complexity:** $O(N \log N)$ to sort both arrival and departure arrays.
- **Space Complexity:** $O(1)$ auxiliary space.

