### **Longest Strictly Increasing Path in Grid**

You are given an $N \times M$ grid of integers.

You want to find the **maximum possible length of a strictly increasing path**. The length of a path is defined as the **number of cells visited**.

Normally, from any cell, you can move **1** step in any of the **4** cardinal directions (up, down, left, right) to a neighboring cell, provided that the value in the neighboring cell is **strictly greater** than the value in your current cell.

However, to make things interesting, you are allowed to use a special "Dash" move **at most once** during your entire path. A Dash move allows you to jump over an immediate neighboring cell to land on the cell exactly two steps away in the same direction (e.g., from `(i, j)` to `(i+2, j)`). To perform a Dash:

1. The destination cell must be **strictly greater** than your current cell.


2. The destination cell must be within the grid boundaries.