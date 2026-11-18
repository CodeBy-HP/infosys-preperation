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
