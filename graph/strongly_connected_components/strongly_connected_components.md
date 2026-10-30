### Problem 15: Strongly Connected Components (Kosaraju's Algorithm)

In a **Directed Graph**, streets are one-way. A **Strongly Connected Component (SCC)** is a cluster of nodes where every single node can reach every other node in that cluster. Think of it as a closed ecosystem or a clique.

If you leave an SCC, you might never be able to get back in.

**Sample Input:**

```text
0 -> 1 -> 2 -> 0   (This is a triangle cycle: SCC 1)
2 -> 3             (A one-way bridge leaving the cycle)
3 -> 4 -> 3        (A two-node cycle: SCC 2)

```

In this graph, the SCCs are `[0, 1, 2]` and `[3, 4]`.

---

### The "Spillover" Problem

If you just run a standard DFS starting from node `0`, it will traverse `1`, `2`, cross the bridge to `3`, and traverse `4`. It will claim the entire graph is one giant component!

Because DFS is greedy, it "spills over" one-way bridges and infects other clusters. We need a way to trap the DFS inside the SCC boundaries.

### Kosaraju's Algorithm: The 3-Step Magic

Kosaraju's Algorithm is one of the most elegant tricks in Computer Science. It uses a mathematical property of reversed graphs to perfectly trap the DFS.

**Step 1: The Finishing Order (Stack)**
Run a DFS on the original graph. Do not process the node immediately. Instead, explore all its neighbors first. *Only when a node has absolutely nowhere else to go*, push it onto a Stack.
*Why?* The nodes that finish last (and end up at the top of the Stack) are the "sources" of the graph—the nodes that can reach everything else.

**Step 2: Reverse the World (Transpose)**
Create a brand new graph where every single directed edge is reversed (if `A -> B`, make it `B -> A`).
*Why?* Reversing the edges doesn't change the internal cycles of an SCC (a reversed triangle is still a triangle). But it **breaks the one-way bridges** between different SCCs! If SCC A originally spilled over into SCC B, in the reversed graph, SCC B now points to SCC A.

**Step 3: Extract the SCCs**
Pop a node from the top of the Stack. If it hasn't been visited, run a DFS from it on the **Reversed Graph**.
Because the graph is reversed, the DFS is physically trapped. It can cycle around the inside of its own SCC, but it cannot cross the bridge to the next one. Every node it touches during this single run forms exactly one SCC.
