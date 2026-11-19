# Tree Uniqueness

You asked: "Is it true a traversal array is unique for every tree, and we can build the exact same tree again?"

The answer is Yes, but you have to follow one of two strict mathematical laws:

Law 1: The "Two Array" System (No Nulls)
If you do not record nulls, a single array is never enough. You must have two different traversals of the exact same tree, and one of them must be Inorder.

Preorder + Inorder = 100% Unique Tree.

Postorder + Inorder = 100% Unique Tree.(This is how you solve LeetCode 105 and 106).

Law 2: The "Null Marker" System (One Array)
If you explicitly record nullptr gaps as "#" in your array, you only need one traversal, but it cannot be Inorder.

Preorder + Nulls = 100% Unique Tree.

Postorder + Nulls = 100% Unique Tree.

Level-Order + Nulls = 100% Unique Tree.(This is exactly how LeetCode feeds tree test cases into your compiler!)


# Catalan Number
The **Catalan numbers** ($C_n$) are a famous sequence of natural numbers that answer a fundamental counting question in computer science: **"How many ways can you recursively split a structure into valid left and right sub-problems?"**

The sequence starts as:


$$C_0 = 1,\; C_1 = 1,\; C_2 = 2,\; C_3 = 5,\; C_4 = 14,\; C_5 = 42,\; C_6 = 132, \dots$$

## The Binary Tree Intuition (The Recurrence)

It answers **How many structurally unique Binary Trees (or BSTs) can you build with $n$ nodes?**

Suppose you have $n$ nodes. One node *must* be the root, leaving **$n - 1$** nodes to distribute between the left and right subtrees:

* If you put **$i$** nodes in the left subtree, you must put **$n - 1 - i$** nodes in the right subtree.
* There are $C_i$ ways to shape the left subtree and $C_{n-1-i}$ ways to shape the right subtree.
* Because the left and right shapes are independent, you multiply them: $C_i \times C_{n-1-i}$.

Summing this across every possible split from $i = 0$ to $n - 1$ gives the **Catalan DP recurrence**:

$$C_n = \sum_{i=0}^{n-1} C_i \cdot C_{n-1-i}, \quad \text{with } C_0 = 1$$

For **$n = 3$** ($C_3 = 5$), the splits work out cleanly:

* **0 left, 2 right:** $C_0 \cdot C_2 = 1 \times 2 = 2$ trees
* **1 left, 1 right:** $C_1 \cdot C_1 = 1 \times 1 = 1$ tree
* **2 left, 0 right:** $C_2 \cdot C_0 = 2 \times 1 = 2$ trees
* **Total:** $2 + 1 + 2 = 5$ unique binary trees.

## The Closed-Form Formula

Instead of building a DP table in $O(n^2)$ time, you can compute the $n$-th Catalan number directly in $O(n)$ time using combinatorics:

$$C_n = \frac{1}{n+1}\binom{2n}{n} = \frac{(2n)!}{(n+1)!\,n!}$$

This comes from counting all paths of $n$ steps right and $n$ steps up (total $\binom{2n}{n}$ paths) and subtracting the invalid paths that cross the diagonal.

## Classic DSA Problems That Are Secretly Catalan Numbers

Whenever a problem asks you to count valid nested structures or non-crossing partitions, check if the first few outputs are `1, 1, 2, 5, 14`:

| Problem | What $n$ Represents | Example for $n = 3$ ($C_3 = 5$) |
| --- | --- | --- |
| **Unique BSTs (LC 96)** | $n$ distinct keys (`1..n`) | 5 distinct BST topologies |
| **Valid Parentheses (LC 22)** | $n$ pairs of `()` | `((()))`, `(()())`, `(())()`, `()(())`, `()()()` |
| **Full Binary Trees** | $n$ internal nodes ($n+1$ leaves) | 5 full binary tree shapes |
| **Polygon Triangulation** | Convex polygon with $n + 2$ sides | 5 ways to divide a pentagon into triangles |
| **Stack Permutations** | $n$ elements pushed/popped | 5 valid output permutations of `[1, 2, 3]` |

