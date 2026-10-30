### Problem 8: Exact Coverage and Backtracking (Unique Paths III)

**Problem Statement:**
You are given an $N \times M$ grid where:

* `1` represents the starting square.
* `2` represents the ending square.
* `0` represents empty squares you can walk over.
* `-1` represents obstacles you cannot walk over.

You can move up, down, left, or right.

**Your Task:**
Find the total number of valid paths from the start to the end. The catch? A valid path must walk over **every single empty square (`0`) exactly once**.

**Sample Input:**

```text
1  0  0  0
0  0  0  0
0  0  2 -1

```

**Sample Output:**

```text
2

```

*(Explanation: There are exactly two paths that snake through the grid, touching every single `0` before finally landing on `2`.)*

---

### Why is this a completely new paradigm?

Up until now, every problem we have solved asked for the *shortest* path, the *minimum* cost, or the *fastest* connectivity. For those, BFS, Dijkstra, and DSU are king.

This problem introduces the **Hamiltonian Path** concept: you are not looking for the shortest route, you are looking for an exhaustive route that touches everything.

If you try to use BFS here, your queue will explode with overlapping timelines because you aren't just tracking a single "best" state; you have to track the exact sequence of squares visited so far.

To solve this, we must use **DFS with Backtracking**.
