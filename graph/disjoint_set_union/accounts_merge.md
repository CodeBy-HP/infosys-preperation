# Accounts Merge (LeetCode 721)

## Problem Statement
Given a list of `accounts` where each element `accounts[i]` is an array of strings, for which the first element `accounts[i][0]` is a **name**, and the rest of the elements are **emails** representing emails of the account.

Now, we would like to **merge these accounts**. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format:
- The first element of each account is the name.
- The rest of the elements are emails **in sorted order**.
- The accounts themselves can be returned in **any order**.

---

## Constraints
* `1 <= accounts.length <= 1000`
* `2 <= accounts[i].length <= 10`
* `1 <= accounts[i][j].length <= 30`
* `accounts[i][0]` consists of English letters.
* `accounts[i][j]` (for $j > 0$) is a valid email.

---

## Examples

### Example 1
**Input:**
```text
accounts = [
  ["John", "johnsmith@mail.com", "john_newyork@mail.com"],
  ["John", "johnsmith@mail.com", "john00@mail.com"],
  ["Mary", "mary@mail.com"],
  ["John", "johnnybravo@mail.com"]
]
```
**Output:**
```text
[
  ["John", "john00@mail.com", "john_newyork@mail.com", "johnsmith@mail.com"],
  ["Mary", "mary@mail.com"],
  ["John", "johnnybravo@mail.com"]
]
```
**Explanation:**
- The first and second John are the same person because they share the email `"johnsmith@mail.com"`.
- The third John (`"johnnybravo@mail.com"`) and Mary are distinct persons as they do not share emails with anyone else.

```
Account 0 (John) -----[johnsmith@mail.com]----- Account 1 (John)
  \                                                   /
   +--- MERGED: ["john00@mail.com", "john_newyork@mail.com", "johnsmith@mail.com"] ---+
```

---

### Example 2
**Input:**
```text
accounts = [
  ["Gabe", "Gabe0@m.co", "Gabe3@m.co", "Gabe1@m.co"],
  ["Kevin", "Kevin3@m.co", "Kevin5@m.co", "Kevin0@m.co"],
  ["Ethan", "Ethan5@m.co", "Ethan4@m.co", "Ethan0@m.co"],
  ["Hanzo", "Hanzo3@m.co", "Hanzo1@m.co", "Hanzo0@m.co"],
  ["Dan", "Dan4@m.co", "Dan5@m.co", "Dan0@m.co"]
]
```
**Output:**
*(All 5 accounts are disjoint and returned sorted individually).*

---

## Algorithmic Approaches

### Disjoint Set Union (DSU) on Account Indices
1. **Email-to-Index Mapping:**
   - Map each unique email to the first account index where it appeared: `unordered_map<string, int> emailToAcc`.
   - Iterate through all accounts $i \in [0, N - 1]$:
     - For each email $e$ in `accounts[i]`:
       - If $e$ has not been seen: `emailToAcc[e] = i`.
       - If $e$ was previously seen in account $j$: union account $i$ with account $j$: `dsu.unionBySize(i, j)`.
2. **Group Emails by Root Representative:**
   - Create `unordered_map<int, vector<string>> mergedEmails` (mapping root account index $\to$ list of emails).
   - For every `(email, accIdx)` in `emailToAcc`:
     - `int root = dsu.findUPar(accIdx)`.
     - `mergedEmails[root].push_back(email)`.
3. **Format Result:**
   - For each root group:
     - Sort emails lexicographically.
     - Prepend the account name: `accounts[root][0]`.
     - Push into `result`.

---

## Complexity Analysis
- **Time Complexity:** $O(N \cdot K \log(N \cdot K))$ where $N$ is accounts count and $K$ is max emails per account (dominated by sorting the merged email lists). DSU unions take near-linear $O(N \cdot K \cdot \alpha(N))$.
- **Space Complexity:** $O(N \cdot K)$ for the email hash map and DSU structures.
