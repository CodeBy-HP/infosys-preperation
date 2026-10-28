**Problem Statement**

There are N posts located along a highway. The positions of the posts are given in a sorted integer array posts[], where posts[i] represents the position of the i-th post.

Your task is to install amplifiers such that every post is covered.

There are two types of amplifiers available:

**1. Normal Amplifier**

* Can be installed at any position on the highway.


* If placed at position x, it covers all posts in the interval:



[x - r, x + r]

* There is an unlimited supply of normal amplifiers.



**2. Super Amplifier**

* Can also be installed at any position on the highway.


* If placed at position x, it covers all posts in the interval:



[x - 2r, x + 2r]

* Only K super amplifiers are available.



An amplifier does not have to be placed at the position of a post. It may be installed anywhere on the highway to maximize the number of posts covered.

Print a single integer representing the minimum total number of amplifiers required to cover all the posts.

**Constraints**

1 ≤ N ≤ 10^5

1 ≤ posts[i] ≤ 10^9

posts[] is sorted in non-decreasing order

1 ≤ r ≤ 10^9

0 ≤ K ≤ N