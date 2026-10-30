# Problem 22: Serialize and Deserialize Binary Tree (LeetCode 297)

## Problem Statement

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string or array, and reconstructed back to the exact original tree structure.

---

## Examples

### Example 1
```text
    1
   / \
  2   3
     / \
    4   5
```
- **Input:** `root = [1,2,3,null,null,4,5]`
- **String Output:** `"1,2,#,#,3,4,#,#,5,#,#"`
- **Array Output:** `[1, 2, null, null, 3, 4, null, null, 5, null, null]`

---

## Constraints

- The number of nodes in the tree is in the range $[0, 10^4]$.
- $-1000 \le \text{Node.val} \le 1000$

---

## Two Core Serialization Paradigms

### 1. Preorder DFS with String Delimiters (LeetCode 297 Standard)
- **Serialization:** Preorder traversal (`Root -> Left -> Right`). When hitting a null pointer, record `"#, "`. Non-null nodes write their value followed by a delimiter: `"val, "`.
- **Deserialization:** Split tokens by comma into a queue. Read the front token:
  - If token is `"#"`, pop and return `nullptr`.
  - Else, construct `TreeNode(stoi(token))`, then recursively deserialize left and right children.

### 2. Preorder DFS with Vector / Array Sentinels (`INT_MIN`)
- In systems and network protocols, string formatting introduces significant allocation and parse overhead. An integer array with sentinel markers (e.g. `INT_MIN` representing `null`) provides a compact binary layout.
- **Serialization:** Append `node->val` or `INT_MIN` for `nullptr` into `vector<int>`.
- **Deserialization:** Maintain an index pointer `ind`. If `arr[ind] == INT_MIN`, increment and return `nullptr`. Otherwise, create the node and recursively construct children.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Preorder Stringstream DFS** | $O(N)$ | $O(N)$ | Standard LC string format |
| **Preorder Vector / Array DFS** | $O(N)$ | $O(N)$ | Compact binary format without string parsing |
