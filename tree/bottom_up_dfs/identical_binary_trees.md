# Check if Two Binary Trees are Identical

## Problem Statement
Given the roots of two binary trees `p` and `q`, write a function to check if they are identical or not.

Two binary trees are considered identical if:
1. They are structurally identical.
2. The nodes have the exact same values at corresponding positions.

---

## 1. Algorithmic Approach (Simultaneous Traversal)

### Core Invariant
At any pair of nodes `(p, q)`:
- If both `p == nullptr` and `q == nullptr`: structurally matched leaf boundaries $\longrightarrow$ return `true`.
- If one is `nullptr` while the other is not: structural mismatch $\longrightarrow$ return `false`.
- If `p->val != q->val`: value mismatch $\longrightarrow$ return `false`.
- Otherwise: recursively verify both subtrees:
  $$\text{isSameTree}(p->\text{left}, q->\text{left}) \land \text{isSameTree}(p->\text{right}, q->\text{right})$$

---

## 2. Complexity Analysis
- **Time Complexity:** $O(\min(N, M))$ where $N$ and $M$ are the node counts of trees `p` and `q`. The traversal stops as soon as a mismatch is detected.
- **Space Complexity:** $O(\min(H_p, H_q))$ auxiliary stack space for tree heights.

