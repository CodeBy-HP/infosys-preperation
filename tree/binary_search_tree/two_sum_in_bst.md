# Two Sum in a Binary Search Tree (BST)

## Problem Statement
Given the `root` of a binary search tree (BST) and an integer `k`, return `true` if there exist two elements in the BST such that their sum is equal to `k`, or `false` otherwise.

```
          5
        /   \
       3     6
      / \     \
     2   4     7

Target k = 9:
2 + 7 = 9 (or 3 + 6 = 9) -> Output: true

Target k = 28:
Output: false
```

---

## 1. Algorithmic Approaches

### Approach A: Hash Set Traversal ($O(N)$ time, $O(N)$ space)
Perform any traversal (preorder/inorder). For each node, check if `k - node->val` exists in `std::unordered_set<int>`. If found, return `true`; else insert `node->val`.

---

### Approach B: Optimal Dual BST Iterator ($O(N)$ time, $O(H)$ space)

#### The Two-Pointer Adaptation on BST
In a sorted array, Two-Sum runs in $O(1)$ space using `left` and `right` pointers moving inwards.
Can we do the same on a BST without allocating an $O(N)$ array?
**YES, using a Bidirectional BST Iterator:**
- **Forward Iterator (`isReverse = false`):** Pushes left children; `next()` steps forward in **ascending order** (acts as the `left` pointer).
- **Reverse Iterator (`isReverse = true`):** Pushes right children; `next()` steps backward in **descending order** (acts as the `right` pointer).

```
Initialize:
left = forwardIt.next()
right = reverseIt.next()

While left < right:
    sum = left + right
    if sum == k:
        return true
    else if sum < k:
        left = forwardIt.next()
    else:
        right = reverseIt.next()

return false
```

---

## 2. Complexity Analysis
- **Time Complexity:** $O(N)$ — In the worst case, every node is pushed and popped from the iterator stacks at most once.
- **Space Complexity:** $O(H)$ — Two stacks storing at most $2H$ nodes, achieving the optimal $O(H)$ space bound.

