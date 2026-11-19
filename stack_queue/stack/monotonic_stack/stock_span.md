# Online Stock Span (LeetCode 901)

## Problem Statement

Design an algorithm that collects daily price quotes for some stock and returns the **span** of that stock's price for the current day.

The **span** of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

- For example, if the prices of the stock in the last four days is `[7, 2, 1, 2]` and the price of the stock today is `2`, then the span of today is `4` because starting from today, the price of the stock was less than or equal to `2` for `4` consecutive days.
- Also, if the prices of the stock in the last four days is `[7, 34, 1, 2]` and the price of the stock today is `8`, then the span of today is `3` because starting from today, the price of the stock was less than or equal to `8` for `3` consecutive days.

Implement the `StockSpanner` class:
- `StockSpanner()` Initializes the object of the class.
- `int next(int price)` Returns the span of the stock's price given that today's price is `price`.

---

## Examples

### Example 1
- **Input:**
  `["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]`
  `[[], [100], [80], [60], [70], [60], [75], [85]]`
- **Output:**
  `[null, 1, 1, 1, 2, 1, 4, 6]`
- **Explanation:**
  - `StockSpanner stockSpanner = new StockSpanner();`
  - `stockSpanner.next(100); // return 1`
  - `stockSpanner.next(80);  // return 1`
  - `stockSpanner.next(60);  // return 1`
  - `stockSpanner.next(70);  // return 2 (covers 70, 60)`
  - `stockSpanner.next(60);  // return 1`
  - `stockSpanner.next(75);  // return 4 (covers 75, 60, 70, 60)`
  - `stockSpanner.next(85);  // return 6 (covers 85, 75, 60, 70, 60, 80)`

---

## Constraints

- $1 \le \text{price} \le 10^5$
- At most $10^4$ calls will be made to `next`.

---

## Monotonic Stack Invariant

The span calculation requires finding the distance to the **Previous Greater Element (PGE)**.
Every daily price strictly less than or equal to today's price can be collapsed into today's price record because any future price that exceeds today's price will also exceed all those previous prices.

Maintain a stack of pairs: `(price, span)`:
1. Initialize `span = 1`.
2. While stack is not empty and `stack.top().price <= price`:
   - `span += stack.top().span`
   - `stack.pop()`
3. Push `(price, span)` onto stack.
4. Return `span`.

Because each day's price is pushed onto the stack exactly once and popped at most once, across $N$ calls to `next()`, the total time spent across all pops is $O(N)$. Thus, the **amortized time per query is $O(1)$**.

---

## Complexity Analysis

| Approach | Amortized Time / Call | Total Time ($N$ calls) | Space Complexity |
| :--- | :--- | :--- | :--- |
| **Monotonic Stack with Span Weights** | $O(1)$ | $O(N)$ | $O(N)$ |
| **Monotonic Stack with Day Indices** | $O(1)$ | $O(N)$ | $O(N)$ |
| **Brute Force History Scan** | $O(N)$ | $O(N^2)$ | $O(N)$ |

