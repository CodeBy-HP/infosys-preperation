### Problem 13: All-Pairs Shortest Path (Floyd-Warshall)

**Problem Statement:**
Dijkstra and Bellman-Ford are **Single-Source** algorithms—they give you the shortest path from *one* specific starting node to everywhere else.

But what if you are building a routing table for the internet, or calculating a distance matrix for a map application? You need the absolute shortest path from **every node to every other node simultaneously**.

**Sample Input:**
An adjacency matrix where `matrix[i][j]` represents the direct road from city `i` to city `j`. If there is no direct road, the value is infinity (`1e9`).

---

### The Paradigm Shift: Dynamic Programming on Graphs

The **Floyd-Warshall Algorithm** completely Abandons the idea of queues, BFS, or edge relaxation. Instead, it uses pure 2D Dynamic Programming.

The core philosophy is built on a single, brilliant question:
*"I currently know the shortest distance from City A to City B. But what if I travel from City A to City B **via City K**? Is it cheaper?"*

**How it works:**

1. **The Matrix:** You start with a 2D matrix where `dist[i][j]` is just the direct edge weight between `i` and `j`. The distance from any node to itself `dist[i][i]` is `0`.
2. **The Intermediary (Node K):** You pick a node, let's call it `k` (Node 0). You look at every single pair of cities `(i, j)` and ask: *"Is `dist[i][0] + dist[0][j]` strictly less than my current `dist[i][j]`?"* If yes, you update `dist[i][j]`.
3. **The Loop:** You repeat this process, allowing node 1 to be the intermediary, then node 2, all the way up to node $N-1$.

By the time you finish allowing every single node to act as a potential middleman, the matrix mathematically guarantees it contains the absolute shortest path between every pair of nodes.

### The $O(N^3)$ Catch

Because of the three nested loops, the time complexity is strictly $O(N^3)$.
This means Floyd-Warshall is only used when the number of nodes is relatively small (typically $N \le 400$). If $N$ is 10,000, $N^3$ is a trillion operations, which will instantly cause a Time Limit Exceeded error. In massive graphs, running Dijkstra $N$ times is faster!