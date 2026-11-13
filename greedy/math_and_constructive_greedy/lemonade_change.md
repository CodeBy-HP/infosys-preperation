# Lemonade Change (LeetCode 860)

## Problem Overview
At a lemonade stand, each lemonade costs $\$5$. Customers are standing in a queue to buy from you and order one at a time.
Each customer will only buy one lemonade and pay with either a $\$5$, $\$10$, or $\$20$ bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $\$5$.
You start with no change in hand.
Given an integer array `bills` where `bills[i]` is the bill the $i$-th customer pays, return `true` if you can provide every customer with the correct change, or `false` otherwise.

---

## Greedy Bill Reservation Invariant
We only need to track the inventory count of $\$5$ bills and $\$10$ bills (a $\$20$ bill can never be used to provide change).
1. **Customer pays $\$5$:**
   $$\text{five} \leftarrow \text{five} + 1$$
2. **Customer pays $\$10$:**
   Requires $\$5$ change.
   $$\text{If five } > 0 \implies \text{five} \leftarrow \text{five} - 1, \quad \text{ten} \leftarrow \text{ten} + 1$$
   $$\text{Else } \implies \text{return false}$$
3. **Customer pays $\$20$:**
   Requires $\$15$ change.
   - **Crucial Greedy Decision:** **Always prefer giving one $\$10$ and one $\$5$ over three $\$5$ bills!**
   - *Why?* A $\$5$ bill is universally flexible (needed to change both $\$10$ and $\$20$ bills), whereas a $\$10$ bill can *only* be used to change $\$20$ bills. Preserving $\$5$ bills maximizes future success.
   - If `ten > 0 && five > 0`: $\text{ten}--, \text{five}--$
   - Else if `five >= 3`: $\text{five} -= 3$
   - Else: $\text{return false}$

---

## Complexity Analysis
- **Time Complexity:** $O(N)$ single pass over all customers.
- **Space Complexity:** $O(1)$ auxiliary space using two integer counters.

