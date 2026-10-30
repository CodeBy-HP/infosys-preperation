### Problem 6: Path With Minimum Effort (The "Hiker" Problem)

**Problem Statement:**
You are a hiker preparing for an upcoming hike. You are given an $N \times M$ 2D matrix `heights`, where `heights[row][col]` represents the height of the mountain at that cell.

You start at the top-left cell `(0, 0)` and you hope to travel to the bottom-right cell `(N-1, M-1)`. You can move up, down, left, or right.

The **effort** of a path is the **maximum absolute difference** in heights between any two consecutive cells on that path.

**Your Task:**
Find a path that minimizes this effort, and return the minimum effort required.

**Sample Input:**

```text
Grid (Heights):
1 2 2
3 8 2
5 3 5

```

**Sample Output:**

```text
2

```

*(Explanation:
Path A (Right and Down): 1 -> 2 -> 2 -> 2 -> 5. The height differences are: |1-2|=1, |2-2|=0, |2-2|=0, |2-5|=3. The maximum difference (effort) here is 3.
Path B (Zig-zag left): 1 -> 3 -> 5 -> 3 -> 5. The height differences are: |1-3|=2, |3-5|=2, |5-3|=2, |3-5|=2. The maximum difference here is 2.
Since 2 is less than 3, Path B is the better route, despite taking more steps!)*

Since the "cost" of a move can now be any arbitrary number like 2, 3, or 8, we can no longer use a Deque to perfectly sort 0s and 1s. What data structure would you use to ensure you are always exploring the path with the smallest effort first?