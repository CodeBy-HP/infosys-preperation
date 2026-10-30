### Problem 12: Shortest Path with Negative Weights

Every shortest-path problem we have solved so far (like BFS and Dijkstra) assumed that traveling always *costs* something. But what if a graph has **Negative Edge Weights**?

Imagine a game where moving between rooms costs energy, but certain secret corridors actually *restore* your energy (a negative cost). Or a financial trading algorithm where certain currency exchanges yield a net profit.

**The Problem:**
You are given a directed graph with $N$ nodes and a list of edges where `edges[i] = [from, to, weight]`. The `weight` can be negative. Find the shortest path from a starting node to all other nodes.

**Why Dijkstra completely fails here:**
Dijkstra's Algorithm is strictly greedy. Its core philosophy is: *"The moment I pop a node from the Priority Queue, its shortest path is 100% finalized forever. I will never look back."*

Look at this simple 3-node graph:

* `0 -> 1` (Cost: 5)
* `0 -> 2` (Cost: 10)
* `2 -> 1` (Cost: -8)

If you start at `0`, Dijkstra looks at its neighbors and says: *"I can reach node 1 for 5, and node 2 for 10. Node 1 is cheaper, so the absolute best way to reach node 1 is 5. Finalized!"*
Then it visits node 2, takes the `-8` edge to node 1, and realizes the cost is `10 - 8 = 2`.
But it's too late. Dijkstra already finalized node 1 and will never push its updated cost to the rest of the graph. Your answer is completely wrong.

---

### The Solution: The Bellman-Ford Algorithm

If Dijkstra is a highly efficient, greedy sniper, **Bellman-Ford** is a brute-force shockwave. It throws away the Priority Queue and says: *"I don't know which path is best, so I am just going to try updating every single edge in the entire graph, over and over again."*

**How it works:**

1. **The Array:** Create a `distance` array and set everything to Infinity (`1e9`), except the start node which is `0`.
2. **The Brute Force:** Loop through **every single edge in the graph** and try to relax it. (Relax means: if `distance[from] + weight < distance[to]`, update `distance[to]`).
3. **The Magic Number:** How many times do you need to loop through every edge? Exactly **$N - 1$ times** (where $N$ is the number of nodes).

**Why exactly $N - 1$ times?**
In any graph with $N$ nodes, the longest possible path you can take without walking in a circle (a cycle) is exactly $N - 1$ edges long.

* On the 1st iteration, all paths of length 1 are guaranteed to be found.
* On the 2nd iteration, all paths of length 2 are guaranteed to be found.
* By the $(N-1)$-th iteration, even the most convoluted, snake-like path through the entire graph is mathematically guaranteed to have fully updated its final distances.