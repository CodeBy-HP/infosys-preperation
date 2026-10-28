You are given an array **A** consisting of **N** integers and an integer **K**.

Your task is to divide the array into exactly **K** non-empty contiguous subarrays.

The **dominance score** of a subarray is defined as the **maximum frequency of any element** in that subarray.

For example,

Subarray = [2, 3, 2, 4, 2]

Frequency of 2 = 3

Frequency of 3 = 1

Frequency of 4 = 1

Dominance Score = 3

The score of a partition is the **sum of the dominance scores** of all K subarrays.

Find the **maximum possible score**.

**Input Format**

* The first line contains two integers **N** and **K**.


* The second line contains **N** space-separated integers representing the array.



**Output Format**

Print a single integer representing the maximum possible dominance score.

**Constraints**

1 ≤ K ≤ N ≤ 300

1 ≤ A[i] ≤ 10^9

**Sample Test Case 1**

**Input**

5 2

1 2 2 1 2