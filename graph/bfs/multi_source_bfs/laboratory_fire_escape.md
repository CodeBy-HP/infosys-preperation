
### Problem Statement

A research laboratory is represented as an N × M grid containing walls, empty cells, fire sources, and one human. Each cell contains one of the following characters:

* '#' → Wall


* '.' → Empty cell


* 'F' → Fire source


* 'H' → Human



Every minute:

* Fire spreads simultaneously to all adjacent cells (up, down, left, right).


* The human can also move one step in any of the four directions.



The human **cannot**:

* Move through walls.


* Move into a cell already occupied by fire.


* Move into a cell where fire reaches at the same time.



The human escapes successfully if they reach **any boundary cell** before the fire reaches that cell.
Your task is to determine whether escape is possible. Print **YES** if the human can escape, otherwise print **NO**.

### Input Format

* The first line contains two integers N and M, representing the number of rows and columns.


* The next N lines each contain a string of length M, representing the laboratory grid.



### Output Format

* Print YES if the human can escape, otherwise print NO.



### Constraints

* 1 ≤ N, M ≤ 1000



### Sample Input

```text
5 6
######
#H...#
#.##F#
#....#
.....#

```



### Sample Output

```text
YES

```