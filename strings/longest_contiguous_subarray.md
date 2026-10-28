
**Question 1 ->**
You are given an array arr[1..N] and a limit L.
You need to find the length of the **longest contiguous subarray** in which no two adjacent elements differ by more than L.
That is, for every pair of consecutive elements in the chosen subarray,
| a[ i + 1 ] - a [ i ] | <= L
Find the length of the longest contiguous subarray satisfying this condition.

**Constraints ->**
1 <= N <= 10^5
0 <= L <= 10^9
0 <= a[i] <= 10^9