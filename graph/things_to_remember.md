Dont use Memoization with visited array in DFS

Try to use BFS for shortest path type problems


You use BFS when you want the shortest path in an unweighted grid (like the fire/obstacle problems).
 You use DFS + DP when you want the longest/max/min path in a grid where cycles are impossible (like strictly increasing paths) like DAGs.


BFS vs State Space BFS
In a Simple BFS, the graph consists purely of physical locations. Your state is just (x, y). Once you step on (x, y), you mark visited[x][y] = true, and you physically never process that cell again, no matter what.

In a State-Space BFS, the graph consists of situations, not just locations. Your state is (x, y, condition). You are allowed to visit the exact same physical (x, y) coordinate multiple times, provided you arrive in a different, strictly better "state."

Whenever your pathfinding depends on "what you are carrying," "what time it is," or "which keys you have picked up," you are no longer just moving through a 2D grid—you are moving through a multi-dimensional State-Space.


the Breadth-First Search (BFS) queue automatically guarantees the shortest path based on time.