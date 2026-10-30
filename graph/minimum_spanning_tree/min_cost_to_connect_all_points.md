### Problem 11: Min Cost to Connect All Points (Minimum Spanning Tree)

**Problem Statement:**
You are given an array of `points` representing integer coordinates on a 2D plane, where `points[i] = [xi, yi]`.

The cost of connecting any two points is the **Manhattan distance** between them: `|xi - xj| + |yi - yj|`.

Return the minimum total cost to make all points connected. All points are considered connected if there is exactly one simple path between any two points (meaning all points are in a single group, and there are no cycles).

**Sample Input:**

```text
Points: [[0,0], [2,2], [3,10], [5,2], [7,0]]

```

**Sample Output:**

```text
20

```

*(Explanation: You can connect [0,0] to [2,2] for a cost of 4. Then [2,2] to [5,2] for a cost of 3. Then [5,2] to [7,0] for a cost of 4. Finally, [2,2] to [3,10] for a cost of 9. Total cost = 4 + 3 + 4 + 9 = 20. Every point is reachable, no cycles exist, and this is the absolute cheapest network possible.)*

---

### What exactly is a Minimum Spanning Tree (MST)?

In graph theory, a "Spanning Tree" is a subset of a graph that connects all the vertices together without creating any closed loops (cycles).
The *Minimum* Spanning Tree is the version of this network where the sum of the edge weights is as small as mathematically possible.

If you have $N$ cities and want to build the cheapest road network so every city is reachable, you are looking for an MST. A fundamental rule of graph theory: **A valid MST for $N$ nodes will always contain exactly $N - 1$ edges.**

### The Two Legendary Algorithms

There are two famous ways to solve MST problems, and they perfectly utilize data structures you have already mastered earlier on this sheet:

1. **Kruskal's Algorithm (The Edge-Centric Approach):** This heavily utilizes the **Disjoint Set Union (DSU)** you learned in the "Number of Islands II" problem. You calculate all possible edges, sort them from cheapest to most expensive, and try to merge them using DSU. If two points already share the same root, you skip the edge because it would create a cycle.
2. **Prim's Algorithm (The Node-Centric Approach):** This approach uses a **Min-Heap (Priority Queue)** and feels very similar to Dijkstra's Algorithm. You start at an arbitrary point, throw all its connecting edges into the queue, and greedily expand your network one node at a time by always picking the cheapest available outgoing edge.