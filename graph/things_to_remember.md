Dont use Memoization with visited array in DFS

Try to use BFS for shortest path type problems


You use BFS when you want the shortest path in an unweighted grid (like the fire/obstacle problems).
 You use DFS + DP when you want the longest/max/min path in a grid where cycles are impossible (like strictly increasing paths) like DAGs.


BFS vs State Space BFS
In a Simple BFS, the graph consists purely of physical locations. Your state is just (x, y). Once you step on (x, y), you mark visited[x][y] = true, and you physically never process that cell again, no matter what.

In a State-Space BFS, the graph consists of situations, not just locations. Your state is (x, y, condition). You are allowed to visit the exact same physical (x, y) coordinate multiple times, provided you arrive in a different, strictly better "state."

Whenever your pathfinding depends on "what you are carrying," "what time it is," or "which keys you have picked up," you are no longer just moving through a 2D grid—you are moving through a multi-dimensional State-Space.


the Breadth-First Search (BFS) queue automatically guarantees the shortest path based on time.


Choose DFS (The Bloodhound) When the Prompt Asks:
"Return all possible paths/combinations/subsets."

"Count the total number of ways to reach the target."

"Does a path exist between A and B?" (If distance doesn't matter, DFS is faster to write).

"Can you reach the end by making choices?" (Backtracking/Decision Trees).


Choose BFS (The Radar) When the Prompt Asks:
"Find the shortest path from A to B."

"What is the minimum number of steps/operations to reach state X?"

"Find the closest exit/zero/target."

Why? Because BFS guarantees that the absolute first time you touch the target, it is the mathematically shortest route. You never waste time exploring a 5-step path if a 4-step path exists.