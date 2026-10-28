
## **Problem Statement: Data Center Cooling Optimization**

You are managing a data center cooling system operating over $n$ discrete time intervals, indexed from $0$ to $n-1$. You are given an initial array $H$ of size $n$, where $H[i]$ represents the initial heat load at interval $i$.

You are also given an integer $d$, which represents the minimum required index separation between any two selected cooling units. Specifically, if you select intervals at indices $i$ and $j$, they must satisfy $\vert{}i - j\vert{} \ge d$.

You must process $q$ operations, which can be of two types:

### **1. Update Operation**

Format: `1 position value`

* **Action:** Update the heat load at `position` to `value`. (i.e., $H[\text{position}] = \text{value}$).

### **2. Query Operation**

Format: `2 l r k critical`

* **Action:** Consider the subarray $H[l \dots r]$. You must select at most $k$ intervals from this range.
* **Selection Rule:** You must select the intervals **greedily**. In each step, choose the available interval with the highest heat load. Once an interval at index $i$ is selected, all unselected intervals in the range $[i - d + 1, i + d - 1]$ become unavailable. Repeat this until $k$ intervals are selected or no valid intervals remain. *(Note: If there is a tie for the highest heat load, pick the one with the smallest index).*
* **Scoring:** For each selected interval with heat load $x$:
* If $x \ge \text{critical}$, the unit enters turbo mode and contributes $4x$ to the heat reduction.
* If $x < \text{critical}$, the unit operates normally and contributes $x$ to the heat reduction.


* **Output:** Calculate the total heat reduction for this query.

**Final Result:** Return the sum of the total heat reductions across all type-2 queries.

---

## **Completed Example Walkthrough**

### **Input Parameters**

* $n = 3$ (Array size)
* $d = 2$ (Assume $d=2$ for illustration so adjacent elements cannot be picked. If $d=1$, you could pick adjacent elements).
* $H = [5, 5, 5]$
* $q = 1$

### **Query Execution**

`2 0 2 3 0`

* **$l = 0$, $r = 2$:** We are looking at the full array $[5, 5, 5]$ at indices $0, 1, 2$.
* **$k = 3$:** We can pick up to 3 units.
* **$\text{critical} = 0$:** Any selected heat load $\ge 0$ gets the $4\times$ multiplier.

**Step-by-step Greedy Selection:**

1. **First pick:** All available indices $(0, 1, 2)$ have the maximum heat load of $5$. By standard tie-breaking rules, we pick the smallest index: **Index 0**.
* *Contribution:* $5 \ge 0$, so it contributes $5 \times 4 = 20$.
* *Invalidated indices:* With $d = 2$, choosing index $0$ invalidates index $1$.


2. **Second pick:** The only remaining valid index in the range is **Index 2** (heat load $5$).
* *Contribution:* $5 \ge 0$, so it contributes $5 \times 4 = 20$.
* *Invalidated indices:* None remain in range.


3. **Third pick:** No valid intervals are left. The selection stops early, even though $k=3$.

**Query Result:** $20 + 20 = 40$.
**Total Output:** $40$.