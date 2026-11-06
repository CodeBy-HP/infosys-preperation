# Introduction to Graphs (Representations & Properties)

## 1. What is a Graph?
A **Graph** $G = (V, E)$ is a non-linear data structure consisting of a finite set of **Vertices (Nodes)** $V$ and a set of **Edges (Links)** $E$ connecting pairs of vertices.

Unlike trees, graphs do not have a designated root node and may contain cycles, multiple disjoint components, and arbitrary branching in any direction.

---

## 2. Fundamental Graph Classifications

| Type | Definition | Key Characteristics |
|---|---|---|
| **Undirected Graph** | Edges have no direction ($u - v \iff v - u$). | $\text{Degree}(u) = \text{number of incident edges}$. $\sum \text{deg} = 2E$ (Handshaking Lemma). |
| **Directed Graph (Digraph)** | Edges have direction ($u \to v$). | Separate **In-Degree** (incoming) and **Out-Degree** (outgoing). $\sum \text{in-deg} = \sum \text{out-deg} = E$. |
| **Weighted Graph** | Each edge carries a cost or weight $w$. | Used in shortest path (Dijkstra) and minimum spanning tree (MST) algorithms. |
| **Cyclic vs Acyclic** | Contains closed loops vs no loops. | A Directed Acyclic Graph is called a **DAG**. |
| **Connected vs Disconnected**| Path exists between every pair vs isolated components. | Requires outer loop over all $V$ vertices in traversals. |

---

## 3. Graph Storage Representations in C++

### Representation 1: Adjacency Matrix
A 2D array of size $V \times V$ where `matrix[u][v] = 1` (or edge weight) if an edge connects $u$ and $v$.
```cpp
vector<vector<int>> adjMatrix(V, vector<int>(V, 0));
// Add edge u - v:
adjMatrix[u][v] = 1;
adjMatrix[v][u] = 1; // for undirected
```
- **Time Complexity:** $O(1)$ to query edge existence between any $(u, v)$.
- **Space Complexity:** $O(V^2)$ — **Prohibitive for large sparse graphs** (e.g. $V = 10^5 \implies 10^{10}$ integers = 40 GB memory!).

---

### Representation 2: Adjacency List (Standard Choice)
An array of lists/vectors where `adj[u]` stores all adjacent neighbors of vertex $u$.
```cpp
vector<int> adj[V]; // Unweighted
// For weighted:
vector<pair<int, int>> adj[V]; // {neighbor, weight}

// Add edge u -> v with weight w:
adj[u].push_back({v, w});
```
- **Time Complexity:** $O(\text{deg}(u))$ to iterate over all neighbors of vertex $u$.
- **Space Complexity:** $O(V + 2E)$ for undirected, $O(V + E)$ for directed — **Strictly optimal linear memory**.

---

## 4. Graph Properties & Formulas
1. **Handshaking Lemma:** In any undirected graph, the sum of degrees of all vertices equals twice the number of edges:
   $$\sum_{v \in V} \text{deg}(v) = 2 |E|$$
   *Consequence:* The number of vertices with an odd degree is always **even**.
2. **Maximum Edges in a Simple Graph:**
   - Undirected: $\binom{V}{2} = \frac{V(V - 1)}{2}$.
   - Directed: $V(V - 1)$.
