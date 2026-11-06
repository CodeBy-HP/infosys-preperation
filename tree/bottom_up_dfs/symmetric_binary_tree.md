# Symmetric Binary Tree (Check for Symmetry)

## Problem Statement
Given the `root` of a binary tree, check whether it is a **mirror of itself** (i.e., symmetric around its center).

```
        1
      /   \
     2     2
    / \   / \
   3   4 4   3
Output: true (Symmetric)

        1
      /   \
     2     2
      \     \
       3     3
Output: false (Not symmetric)
```

---

## 1. Algorithmic Approach (Mirror Pair Comparison)

### Recursive Invariant
A tree is symmetric if its left subtree $L$ and right subtree $R$ are mirror reflections.
Two subtrees $T_1$ and $T_2$ are mirrors if:
1. Both are `nullptr` $\longrightarrow$ `true`.
2. One is `nullptr` and the other is not $\longrightarrow$ `false`.
3. Their root values are equal: $T_1\to\text{val} == T_2\to\text{val}$.
4. **Opposite children are mirrors**:
   - $T_1\to\text{left}$ mirrors $T_2\to\text{right}$.
   - $T_1\to\text{right}$ mirrors $T_2\to\text{left}$.

$$\text{isMirror}(T_1, T_2) = (T_1\to\text{val} == T_2\to\text{val}) \land \text{isMirror}(T_1\to\text{left}, T_2\to\text{right}) \land \text{isMirror}(T_1\to\text{right}, T_2\to\text{left})$$

---

## 2. Complexity Analysis
- **Time Complexity:** $O(N)$ — Every node is visited once.
- **Space Complexity:** $O(H)$ auxiliary call stack or queue frames ($O(\log N)$ balanced, $O(N)$ worst-case).

