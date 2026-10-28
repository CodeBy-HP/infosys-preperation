# CSES Problem Set: Monsters (Task 1194)

## Problem Statement

You and some monsters are in a labyrinth. When taking a step in some direction in the labyrinth, each monster may simultaneously take one as well. Your goal is to reach one of the boundary squares without ever sharing a square with a monster.

Your task is to find out if your goal is possible, and if it is, print a path that you can follow. Your plan has to work in any situation; even if the monsters know your path beforehand.

---

## Input Format

* The first input line has two integers $n$ and $m$: the height and width of the map.
* After this, there are $n$ lines of $m$ characters describing the map.
* Each character is:
  * `.` (floor)
  * `#` (wall)
  * `A` (your starting position)
  * `M` (monster starting position)
* There is **exactly one** `A` in the input.

---

## Output Format

* First, print `YES` if your goal is possible, and `NO` otherwise.
* If your goal is possible, print an example of a valid path:
  * On the first line, print the length of the path.
  * On the second line, print the description of the path using characters:
    * `D` (down)
    * `U` (up)
    * `L` (left)
    * `R` (right)
  * You can print any valid path as long as its length is at most $n \cdot m$ steps.

---

## Constraints

* $1 \le n, m \le 1000$
* Characters in map are strictly `.` , `#` , `A` , `M`
* Time limit: 1.00 s
* Memory limit: 512 MB

---

## Examples

### Example 1

**Input:**
```text
5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######
```

**Output:**
```text
YES
5
RRDDR
```

**Explanation:**
You start at `A` at `(1, 4)` (0-indexed). By taking the moves `R -> R -> D -> D -> R`, you reach a boundary cell before any monster can intercept you.
