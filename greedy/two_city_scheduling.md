
## **Problem Statement**

A company is organizing a conference in two cities, **City A** and **City B**. There are **2N** employees, and exactly **N** employees must be assigned to each city.

For each employee $i$:

* The cost of sending the employee directly to **City A** is **A[i]**.


* To travel to **City B**, the employee must first stop at a transit hub. The total travel cost to City B is:



$$\min(A[i], B[i]) + B[i]$$

where:

* **A[i]** is the cost of traveling directly to City A.


* **B[i]** is the cost of traveling from the transit hub to City B.



Determine the **minimum total travel cost** while ensuring that exactly **N** employees are assigned to each city.

---

## **Input Format**

* The first line contains an integer **N**.


* The second line contains **2N** space-separated integers representing array **A**.


* The third line contains **2N** space-separated integers representing array **B**.



---

## **Output Format**

Print a single integer representing the **minimum total travel cost**.

---

## **Constraints**

* $1 \le N \le 10^5$

* $1 \le A[i], B[i] \le 10^5$