# Graph Traversal Techniques (BFS and DFS)

## 1. Breadth-First Search (BFS) — Level Order Exploration

### Definition & Mechanics
**BFS** explores vertices in concentric radial layers outward from the source vertex:
- Vertices at distance 1 are visited first, followed by vertices at distance 2, and so forth.
- Implemented using a **First-In, First-Out (FIFO) queue** and a `visited` array to prevent revisiting nodes in cycles.

### BFS Algorithm Pattern
```cpp
vector<int> bfsOfGraph(int V, vector<int> adj[], int src = 0) {
    vector<int> bfsOrder;
    vector<bool> vis(V, false);
    queue<int> q;

    vis[src] = true;
    q.push(src);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        bfsOrder.push_back(u);

        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true; // Mark visited immediately on enqueue
                q.push(v);
            }
        }
    }
    return bfsOrder;
}
```
- **Time Complexity:** $O(V + 2E)$ for undirected, $O(V + E)$ for directed.
- **Space Complexity:** $O(V)$ for queue and `vis` array.

---

## 2. Depth-First Search (DFS) — Deep Branching & Backtracking

### Definition & Mechanics
**DFS** plunges as deeply as possible along each branch before backtracking:
- Recursively traverses to unvisited neighbors until a dead end is reached, then unwinds to explore unvisited alternative paths.
- Uses the system **call stack** (or explicit `stack<int>`).

### DFS Algorithm Pattern
```cpp
void dfsHelper(int u, vector<int> adj[], vector<bool>& vis, vector<int>& dfsOrder) {
    vis[u] = true;
    dfsOrder.push_back(u);

    for (int v : adj[u]) {
        if (!vis[v]) {
            dfsHelper(v, adj, vis, dfsOrder);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[], int src = 0) {
    vector<int> dfsOrder;
    vector<bool> vis(V, false);
    dfsHelper(src, adj, vis, dfsOrder);
    return dfsOrder;
}
```
- **Time Complexity:** $O(V + 2E)$ for undirected, $O(V + E)$ for directed.
- **Space Complexity:** $O(V)$ for recursion stack frames and `vis` array.

---

## 3. Disconnected Graph Handling Pattern
Graphs may be fragmented into multiple isolated components. To guarantee complete traversal of all $V$ nodes:
```cpp
vector<bool> vis(V, false);
for (int i = 0; i < V; ++i) {
    if (!vis[i]) {
        // Launch BFS or DFS from node i
        dfsHelper(i, adj, vis, dfsOrder);
    }
}
```
