We have conquered grid traversals and directed dependency graphs (Topological Sort). The next major paradigm in graph theory is **Graph Partitioning and Coloring**.

### Problem 10: Is Graph Bipartite?

**Problem Statement:**
You are given an undirected graph. You need to figure out if the graph is **Bipartite**.

A graph is Bipartite if you can split all its nodes into two independent sets (let's call them Group A and Group B) such that **every single edge** in the graph connects a node in Group A to a node in Group B.

A simpler way to think about it: Imagine you have two paint colors (Red and Blue). Can you paint every node in the graph so that **no two adjacent nodes have the same color**?

**Sample Input 1:**

```text
Graph: 
0 --- 1
|     |
3 --- 2

```

**Sample Output 1:**

```text
true

```

*(Explanation: Paint 0 Red. Its neighbors (1 and 3) must be Blue. Node 2 is a neighbor of 1 and 3, so it must be Red. No two connected nodes share a color. It works!)*

**Sample Input 2:**

```text
Graph:
0 --- 1
 \   /
   2

```

**Sample Output 2:**

```text
false

```

*(Explanation: Paint 0 Red. Its neighbors (1 and 2) must be Blue. But wait! 1 and 2 are connected to each other! If they are both Blue, they violate the rule. It is impossible to color a triangle with only 2 colors.)*

---

### The Underlying Secret: Odd-Length Cycles

This problem teaches a fundamental rule of graph theory: **A graph is Bipartite if and only if it does NOT contain a cycle of odd length.**

* A cycle of length 4 (a square) can alternate: Red-Blue-Red-Blue.
* A cycle of length 3 (a triangle) alternates: Red-Blue-Red... and crashes because the last Red touches the first Red.

### How do we solve it? (The Alternating BFS/DFS)

Instead of a standard `visited` array tracking `true/false`, we upgrade to a `color` array tracking `0 (Red)`, `1 (Blue)`, and `-1 (Uncolored)`.

You can use either BFS or DFS. The logic is identical to a contagious alternating virus:

1. Start at an uncolored node and paint it `0 (Red)`.
2. Look at all its neighbors.
3. If a neighbor is uncolored, paint it the **opposite** color (`1 - current_color`) and add it to your queue/stack.
4. If a neighbor is *already* colored, check its color. If it has the **exact same color** as your current node, the alarm bells ring—return `false`.