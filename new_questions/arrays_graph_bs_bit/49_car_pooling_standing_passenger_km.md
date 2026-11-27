# 49. Car Pooling — Standing Passenger Kilometers (Infosys SP OA Exact PYQ)

## Problem Statement

A shuttle vehicle drives straight east along a highway. You are given:
- `capacity`: the number of **seated** spots available on the shuttle.
- `trips`: a list where `trips[i] = [numPassengers_i, from_i, to_i]` means `numPassengers_i` passengers board at kilometer `from_i` and disembark at kilometer `to_i`.

Unlike standard Car Pooling (LeetCode 1094) which stops when capacity is exceeded, passengers who cannot get a seat **are allowed to stand**!
For every kilometer traveled while there are more than `capacity` passengers on board, each excess passenger accumulates **1 standing passenger-kilometer**.

Return the **total standing passenger-kilometers** accumulated across the entire journey!
*(Also includes standard LeetCode 1094 `canCarPool` boolean check.)*

---

## Examples

### Example 1
- **Input:** `trips = [[2, 1, 5], [3, 3, 7]]`, `capacity = 4`
- **Output:** `2`
- **Explanation:**
  - Segment `[1, 3)`: `2` passengers (`<= 4`), `0` standing.
  - Segment `[3, 5)`: `2 + 3 = 5` passengers (`5 - 4 = 1` standing!) over `5 - 3 = 2` km $\implies 1 \times 2 = 2$ standing passenger-km.
  - Segment `[5, 7)`: `3` passengers (`<= 4`), `0` standing.
  - Total = `2`.

### Example 2
- **Input:** `trips = [[3, 0, 10], [4, 2, 6]]`, `capacity = 5`
- **Output:** `8`
- **Explanation:** On `[2, 6)` (length 4 km), `7` passengers are aboard $\implies 2$ standing $\times 4 = 8$.

---

## Constraints

- $1 \le \text{trips.length} \le 10^5$
- $1 \le \text{numPassengers}_i \le 10^4$
- $0 \le \text{from}_i < \text{to}_i \le 10^9$
- $0 \le \text{capacity} \le 10^9$

---

## Pattern Insight: Sorted Sweep-Line Event Accumulation

Using a fixed difference array fails when coordinates reach $10^9$!
Instead, use a **Sweep Line** with coordinate events:
1. Create events `{from_i, +numPassengers_i}` and `{to_i, -numPassengers_i}`.
2. Sort events ascending by coordinate.
3. Sweep through grouped coordinates: between `prevPos` and `currPos`, if `currLoad > capacity`, add `(currLoad - capacity) * (currPos - prevPos)` to `standingKm`.
4. Update `currLoad` with all delta events at `currPos`.

Runs in **$O(N \log N)$ time** for arbitrary $10^9$ coordinates!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Coordinate-Independent Sweep Line** | $O(N \log N)$ | $O(N)$ |
| **Difference Array (Small Coordinates $\le 1000$)** | $O(N + \text{MaxCoord})$ | $O(\text{MaxCoord})$ |
