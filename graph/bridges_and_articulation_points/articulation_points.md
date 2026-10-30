The leap from Bridges (critical edges) to Articulation Points (critical nodes) requires just two incredibly subtle tweaks to the time-stamping logic.

### Tweak 1: The `>=` Condition

For a bridge, the condition was `low[neighbor] > disc[node]`. This meant the neighbor had absolutely no way to reach the `node` or anything before it.

For an Articulation Point, the condition becomes **`low[neighbor] >= disc[node]`**.
Why the equals sign? If the neighbor's absolute best back-alley route takes it *exactly* to the current `node` and no further, the `node` itself is the bottleneck. If that `node` explodes, the neighbor is completely cut off from the rest of the graph.

### Tweak 2: The Root Node Trap

Imagine a simple graph: `A --- B --- C`.
If we start our DFS at `A`, it is the "Root." `B` will report `low[B] >= disc[A]`. According to Tweak 1, `A` is an Articulation Point!
But wait—if `A` explodes, `B` and `C` are still perfectly connected. Removing the end of a line doesn't split the network.

**The Rule for the Root:** The starting node of a DFS is *only* an Articulation Point if it launches **two or more independent DFS branches** (children). If it has multiple branches, it acts as the central hub gluing those distinct branches together.

### C++ Implementation

Notice how we use a boolean array `is_articulation` instead of a list. This is because a single server might act as a bottleneck for multiple different neighbors, and we don't want to add it to our final answer twice!
