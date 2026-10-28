Here is the extracted text from the images:

---

## Problem Statement

Andy wants to go on a vacation to de-stress himself. He can take **only one continuous vacation** during the next **N** days, where the days are numbered from **1 to N**.

Andy already has **M obligations** scheduled on specific days. The **i-th obligation** is on day **D[i]**. To extend his vacation, Andy is allowed to **cancel at most K obligations**.

Your task is to determine the **maximum number of consecutive vacation days** Andy can take after canceling at most **K** obligations.

---

## Input Format

* The first line contains three integers:


* **N** – Total number of days.


* **M** – Number of scheduled obligations.


* **K** – Maximum number of obligations that can be canceled.




* The second line contains **M** space-separated integers representing the days on which the obligations are scheduled.



---

## Output Format

Print a single integer representing the **maximum number of consecutive vacation days** Andy can take.

---

## Constraints

* $1 \le \text{N} \le 10^9$

* $0 \le \text{M} \le 2 \times 10^5$

* $0 \le \text{K} \le \text{M}$

* $1 \le \text{D[i]} \le \text{N}$

* All obligation days are distinct.





---

## Sample Input

```text
20 5 2
3 8 12 15 18


## Sample Output

11

```