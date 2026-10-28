

**Problem Statement**


There are **N** houses arranged in a straight line. Each house must be painted using one of **C** available colors.

The cost of painting the **i-th** house with the **j-th** color is given by cost[i][j].

The following conditions must be satisfied:

1. Every house must be painted exactly one color.


2. No two adjacent houses can have the same color.


3. The total painting cost must not exceed the given budget **B**.



Your task is to determine the **minimum total painting cost**.

If it is impossible to paint all the houses within the given budget, print **-1**.

**Input Format**

* The first line contains an integer **N**, the number of houses.


* The second line contains an integer **C**, the number of available colors.


* The third line contains an integer **B**, the maximum allowed budget.


* The next **N** lines each contain **C** integers, where the j-th integer in the i-th line represents the cost of painting house i with color j.



**Output Format**


Print a single integer:

* The minimum total painting cost if it does not exceed **B**.


* Otherwise print **-1**.