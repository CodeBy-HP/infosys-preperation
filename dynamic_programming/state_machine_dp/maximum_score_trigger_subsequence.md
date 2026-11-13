# Maximum Score with Trigger-Based Subsequence Earnings

## Problem Statement
Given an array `nums` of $n$ integers and a trigger interval $k$, select a subsequence of elements (maintaining their original relative order) to **maximize the total earnings**.

### Rules & Mechanics:
1. Items are chosen sequentially as a subsequence.
2. The items collected are counted: 1st, 2nd, 3rd, $\dots$, $m$-th item.
3. Every $k$-th item collected ($k, 2k, 3k, \dots$) acts as a **"trigger checkpoint"**.
4. The item collected **immediately after any trigger checkpoint** (i.e. item numbers $k+1, 2k+1, 3k+1, \dots$) earns **double its face value** ($2 \times nums[i]$).
5. All other items earn their normal face value ($1 \times nums[i]$).

Find the maximum possible total earnings from any chosen subsequence.

### Example 1:
```
Input: nums = [10, 20, 30, 40], k = 2
Output: 130
Explanation:
Pick all 4 elements in order:
- 1st item: 10 (earns 10)
- 2nd item: 20 (checkpoint reached! earns 20)
- 3rd item: 30 (immediately follows checkpoint #1, earns 2 * 30 = 60!)
- 4th item: 40 (checkpoint reached! earns 40)
Total = 10 + 20 + 60 + 40 = 130.
```

### Constraints:
- `1 <= n <= 10^5`
- `1 <= k <= 100`
- `-10^4 <= nums[i] <= 10^4`

---

## Pattern Insight: State Machine DP Modulo $K$
- Notice that the reward multiplier for taking `nums[i]` depends strictly on whether the *number of previously collected items* is a positive multiple of $k$.
- We can track the number of items picked so far modulo $k$:
  - State `0`: Exactly 0 items picked so far. Next item is item #1 (normal value $1 \times nums[i]$).
  - State `rem` ($1 \le rem \le k - 1$): Picked count $\equiv rem \pmod k$. Next item is item $\#(rem + 1)$ (normal value $1 \times nums[i]$).
  - State `k`: Picked count $> 0$ and count $\equiv 0 \pmod k$ (just triggered a checkpoint!). Next item is immediately after a trigger, so it earns **double value** ($2 \times nums[i]$)!
- There are only $k + 1$ states!
- **Transitions for each element `val = nums[i]`:**
  - Let `next_dp = dp` (skipping `val`).
  - From State `0`:
    - Taking `val`: `next_state = (k == 1 ? 1 : 1)`. Value added is $1 \times val$.
  - From State `rem` ($1 \le rem < k - 1$):
    - Taking `val`: `next_state = rem + 1`. Value added is $1 \times val$.
  - From State `k - 1`:
    - Taking `val`: completes a checkpoint $\to$ `next_state = k`. Value added is $1 \times val$.
  - From State `k` (checkpoint state):
    - Taking `val`: earns **$2 \times val$**! `next_state = (k == 1 ? k : 1)`.
- Running 1D DP of size $k + 1$ allows solving the problem in $O(n \times k)$ time and $O(k)$ space!

---

## Complexity
- **Time Complexity:** $O(n \cdot k)$ — $k+1$ constant-time state transitions per element.
- **Space Complexity:** $O(k)$ auxiliary space using rolling array.

