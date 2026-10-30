### Problem 14: Bridges in a Graph (Critical Connections in a Network)

We have covered shortest paths, dependencies, and networks. Now we enter **Graph Vulnerability**.

**Problem Statement:**
You are given an undirected graph representing a massive data center. The nodes are servers, and the edges are cables connecting them.

You need to find all the **Critical Connections** (Bridges). A bridge is any edge that, if cut, completely splits the graph into two disconnected pieces, isolating some servers from the rest of the network.

**Sample Input:**

```text
Servers (N) = 4
Connections = [[0,1], [1,2], [2,0], [1,3]]

```

**Sample Output:**

```text
[[1,3]]

```

*(Explanation: Servers 0, 1, and 2 form a triangle. If you cut `[0,1]`, server 0 can still talk to 1 via server 2. But if you cut `[1,3]`, server 3 is completely dead to the world. `[1,3]` is a bridge.)*

---

### The Paradigm Shift: Time-Stamping (Tarjan's Concept)

Standard DFS or BFS cannot solve this. A standard `visited` array just tells you "I have been here." To find a bridge, you need to answer a much harder question: *"Is there a secret back-alley route that loops back to where I started?"*

To solve this, we introduce **Time Travel** to our DFS. We equip every node with two stopwatches:

1. **`discovery_time`:** The exact tick of the clock when we first stepped on this node.
2. **`lowest_time`:** The earliest (lowest) discovery time this node can reach by looking at its neighbors (excluding the parent it just came from).

**The Logic:**

* You start a DFS, ticking a global clock up by 1 with every step.
* When Node A visits Node B, Node B looks around for other paths.
* If Node B finds a "back-edge" (a connection to an already visited node from the past), it updates its `lowest_time` to match that past node's `discovery_time`.
* **The Bridge Check:** When the DFS steps back from Node B to Node A, Node A asks: *"Hey B, what is the earliest node you can reach?"*
* If `B's lowest_time <= A's discovery_time`, it means B found a back-alley route! The edge between A and B is safe.
* If `B's lowest_time > A's discovery_time`, B is trapped. It has absolutely no way back to A or earlier nodes except through the direct A-B cable. **That cable is a bridge.**

