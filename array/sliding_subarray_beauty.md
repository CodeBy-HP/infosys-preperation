

**Problem Statement**

Given an integer array nums containing n integers, find the **beauty** of every subarray of size k.

The **beauty** of a subarray is defined as:

* The **x-th smallest integer** in the subarray if it is **negative**.


* Otherwise, the beauty is **0** if there are fewer than x negative integers in the subarray.



Return an integer array of size n - k + 1, where each element represents the beauty of the corresponding subarray in the order they appear.

A **subarray** is a contiguous non-empty sequence of elements within an array.

---

**Input**

* An integer array nums


* An integer k representing the size of each subarray


* An integer x



---

**Output**

Return an integer array containing the beauty of each subarray of size k.

---

**Example 1**

**Input**

nums = [1, -1, -3, -2, 3]

k = 3

x = 2