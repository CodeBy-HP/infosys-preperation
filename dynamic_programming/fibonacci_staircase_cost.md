**Problem Statement**

A staircase contains **N** steps numbered from **1** to **N**.

You start from step **1** and want to reach step **N**.

From any step, you may jump **only to the next Fibonacci step ahead**. That is, if you are currently on step i, you may move to:

* $i + 1$

* $i + 2$

* $i + 3$

* $i + 5$

* $i + 8$

* ...



where the jump length must be a Fibonacci number and the destination must not exceed N.

The cost of making a jump of length $k$ is:

$$\text{Cost} = A + B \times k$$

where:

* **A** = fixed cost per jump


* **B** = cost per step jumped


* **k** = jump length (a Fibonacci number)



Find the **minimum total cost** required to reach step N.

---

**Input Format**

N A B

---

**Output Format**

Print a single integer representing the minimum total cost.

---

**Constraints**

* $2 \le N \le 2 \times 10^5$

* $1 \le A, B \le 10^9$