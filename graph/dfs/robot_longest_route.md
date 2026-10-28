**Problem Statement:**
A robotics company has developed an autonomous robot that navigates through an N × M terrain. Each cell of the terrain contains an integer representing its elevation. The robot can move only to its adjacent cells in the four directions:

* Up
* Down
* Left
* Right

However, the robot can move to a neighboring cell only if the neighboring cell has a **strictly greater elevation** than the current cell. Your task is to determine the length of the **longest possible increasing route** that the robot can travel anywhere in the matrix. Return the maximum number of cells that can be visited in a strictly increasing path.

**Input Format:**

* The first line contains two integers N and M, denoting the number of rows and columns.
* The next N lines each contain M space-separated integers, representing the elevation matrix.