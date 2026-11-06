# Accounts Merge (LeetCode 721)

## Problem Overview
Given a list of `accounts` where each element `accounts[i]` is a list of strings, with the first element `accounts[i][0]` being a name, and the rest of the elements being emails representing that account.
Two accounts definitely belong to the same person if there is some common email to both accounts.
After merging the accounts, return the accounts in the format: the first element of each account is the name, and the rest of the elements are emails in **sorted order**.

---

## DSU on Account Indices
1. Treat each of the $N$ accounts as a node in DSU: $0, 1, \dots, N - 1$.
2. Maintain an `unordered_map<string, int> emailToId` mapping each distinct email to the first account index that claimed it.
3. For each account $i$:
   - For each email $e$ in `accounts[i]`:
     - If $e$ has not been seen: `emailToId[e] = i`.
     - If $e$ has already been seen in account $prev$:
       $$\text{dsu.unionNodes}(i, \; prev)$$
4. Group emails by root component:
   - For every entry $(e, id)$ in `emailToId`:
     - Find representative root: $root = \text{dsu.findUPar}(id)$.
     - Add $e$ to list of emails for $root$.
5. Format output:
   - For each non-empty root component, sort emails lexicographically, prepend the user's name (`accounts[root][0]`), and add to output.

---

## Complexity Analysis
- **Time Complexity:** $O(N \cdot M \log(N \cdot M))$ where $N$ is number of accounts, $M$ is max emails per account (dominated by sorting emails per component).
- **Space Complexity:** $O(N \cdot M)$ for hash maps and DSU structures.

