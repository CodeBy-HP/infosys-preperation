### Problem 4: Shortest Path to Get All Keys

**Problem Statement:**
You are given an $N \times M$ grid representing a maze containing empty cells, walls, keys, and locks.

* `.` is an empty cell.
* `#` is a wall.
* `@` is your starting position.
* Lowercase letters (`a`-`f`) represent keys.
* Uppercase letters (`A`-`F`) represent locks.

You can move in the 4 cardinal directions. You cannot walk into a wall. If you walk over a key, you pick it up. You cannot walk over a lock unless you have previously picked up the corresponding key (e.g., you need key `a` to open lock `A`).

**Your Task:**
Find the minimum number of steps required to collect **all** the keys in the maze. If it is impossible to collect all of them, return `-1`.

**Sample Input:**

```text
Grid:
@.a.#
###.#
b.A.B

```

**Sample Output:**

```text
8

```

*(Explanation: Start at `@` (0,0). Move right to collect key `a` at (0,2). This takes 2 steps. Because you now have key `a`, you can unlock `A`. However, you must walk back to the start, move down to the bottom row, and move left to collect key `b` at (2,0). Total steps = 8.)*
