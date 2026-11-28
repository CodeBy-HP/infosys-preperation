# C++ Programming & DSA Cheat Sheet

A structured collection of tips, tricks, container behaviors, custom comparators, and common pitfalls when solving Data Structures and Algorithms (DSA) problems in C++.

---

## Table of Contents
1. [General Problem-Solving Strategies](#1-general-problem-solving-strategies)
2. [Math, Overflow & Precision](#2-math-overflow--precision)
3. [Pointers, References & Linked Lists](#3-pointers-references--linked-lists)
4. [STL Containers: Maps & Sets](#4-stl-containers-maps--sets)
5. [Custom Comparators](#5-custom-comparators)

---

## 1. General Problem-Solving Strategies

* **Use Simulation:** When there is no obvious or straightforward optimal approach, simulate the problem step-by-step to understand its behavior and uncover the underlying logic.
* **Read the Constraints:** Whenever you get confused by a problem statement or need to pick an algorithm, look at the input constraints. They hint at the expected time complexity.
* **Recursion & Stacks:** Conceptually, recursion and an explicit stack are identical. If recursion causes a stack overflow or feels tricky to manage, convert it to an iterative stack-based approach.
* **State Pruning in Recursion:** Always look for opportunities to prune invalid or redundant branches early in recursive/backtracking solutions to save time.
* **Characters to Integers:** When working with characters (e.g., `'a'`–`'z'`), convert them to integers (e.g., `ch - 'a'`) to easily index into arrays or perform math operations.

---

## 2. Math, Overflow & Precision

### 2.1 Avoiding Integer Overflow in Binary Search
Instead of calculating the middle index using `mid = (low + high) / 2;`, use:
```cpp
mid = low + (high - low) / 2;
```
This prevents overflow when `low + high` exceeds `INT_MAX`.

### 2.2 Integer Overflow in Multiplications
Assigning a result to a `long long` does **not** prevent overflow if the multiplication itself is performed using `int` operands.

```cpp
int a = 100000;
int b = 100000;

long long wrong = a * b;        // Overflows BEFORE assignment
long long right = 1LL * a * b;  // Correct: promotes calculation to long long
```

### 2.3 Integer Division & Ceiling
In C++, integer division truncates the decimal part without rounding (`10 / 3 == 3`). To calculate $\lceil x / m \rceil$ for non-negative $x$ and positive $m$:

```cpp
// Approach 1: Using modulo
int ans = x / m;
if (x % m != 0) ans++;

// Approach 2: Formula (watch out for overflow in x + m)
int ans = (x + m - 1) / m;
```

### 2.4 Floating-Point Division
If both operands are integers, C++ performs integer division even if stored in a `double`. Cast at least one operand to `double`:

```cpp
double a = 10 / 3;          // 3.0
double b = 10.0 / 3;        // 3.33333
double c = (double)10 / 3;  // 3.33333
```

### 2.5 Floating-Point Tolerance ($10^{-6}$)
When a problem states *"Answers within $10^{-6}$ of the actual answer will be accepted"*, it means your result can differ from the true answer by at most $0.000001$:
$$|\text{Your Answer} - \text{Actual Answer}| \le 10^{-6}$$
For example, if the actual answer is $5.000000$, anything in the range $[4.999999, 5.000001]$ is accepted.

### 2.6 Modulo with Negative Numbers
In C++, the remainder operator `%` can return a negative value (e.g., `-10 % 3 == -1`). To guarantee a non-negative result for a positive modulus `m`:

```cpp
int ans = ((x % m) + m) % m; // For x = -10, m = 3 -> outputs 2
```

### 2.7 Operator Precedence
C++ evaluates expressions according to operator precedence. **Tip:** Always use parentheses `()` in complex conditions or bit-manipulation expressions to avoid bugs.

| Priority | Operators | Meaning |
| :--- | :--- | :--- |
| 1 | `()` | Parentheses |
| 2 | `*`, `/`, `%` | Multiplication, Division, Modulo |
| 3 | `+`, `-` | Addition, Subtraction |
| 4 | `<`, `>`, `==` | Comparisons |
| 5 | `&&` | Logical AND |
| 6 | `\|\|` | Logical OR |
| 7 | `=` | Assignment |

---

## 3. Pointers, References & Linked Lists

### 3.1 Pointer vs. Reference
A **reference** is an alias for an existing variable, while a **pointer** is a separate variable storing a memory address.

| Feature | Reference (`int&`) | Pointer (`int*`) |
| :--- | :--- | :--- |
| **What it is** | Alias to an existing variable | Variable holding a memory address |
| **Must be initialized?** | **Yes**, upon declaration | **No**, can be uninitialized |
| **Can be null?** | **No** | **Yes** (`nullptr`) |
| **Can be reassigned?** | **No** (bound forever) | **Yes** (can point elsewhere) |
| **Access syntax** | Direct (`.`) | Dereference (`*ptr` or `->`) |

```cpp
int x = 10, y = 20;

// Reference: acts directly as x
int& ref = x;
ref = 15;        // x becomes 15
ref = y;         // Copies y's VALUE (20) into x; ref still aliases x!

// Pointer: holds address of x
int* ptr = &x;
*ptr = 30;       // x becomes 30
ptr = &y;        // ptr now points to y
ptr = nullptr;   // Valid
```

* **Rule of Thumb:** Default to references (`const T&` or `T&`) for function parameters. Use pointers (`T*`) when `nullptr` is a valid state or when building dynamic structures (`ListNode*`, `TreeNode*`).
* **Dangling Pointers:** Before calling `delete` on a pointer, ensure no other active pointer still references that memory address.
* **Member Access:** Use `->` when accessing members via a pointer, and `.` when accessing members via an object or reference.

### 3.2 Linked List Essentials
Always use a **dummy node** when the head of the linked list might change (e.g., insertions, deletions, merging).

```cpp
// 1. Create a dummy node using `new`
ListNode* dummy = new ListNode(0);
dummy->next = head;

// 2. Traversal pointer: copy the pointer
ListNode* curr = dummy;

// 3. Attach a new node using `new`
curr->next = new ListNode(42);

// 4. Move forward using `->`
curr = curr->next;

// 5. Return the modified list
return dummy->next;
```

---

## 4. STL Containers: Maps & Sets

### 4.1 Container Overview & Time Complexities
* **Complexity Warning:** `std::map` and `std::set` take $O(\log N)$ per operation. If a problem strictly requires $O(1)$ lookups, use `std::unordered_map` or `std::unordered_set`.

| Container | Ordering | Duplicates? | Implementation | Average Time | Worst Time |
| :--- | :--- | :--- | :--- | :--- | :--- |
| `map` / `set` | Ascending | No | Red-Black Tree | $O(\log N)$ | $O(\log N)$ |
| `multimap` / `multiset` | Ascending | **Yes** | Red-Black Tree | $O(\log N)$ | $O(\log N)$ |
| `unordered_map` / `unordered_set` | None | No | Hash Table | $O(1)$ | $O(N)$ |

### 4.2 Valid Key / Element Data Types
* **Ordered (`map`, `set`, `multimap`, `multiset`):** Any type that supports comparison (`<`). Works out-of-the-box with `int`, `string`, `pair`, `vector`, and raw pointers (`TreeNode*`, `ListNode*`).
* **Unordered (`unordered_map`, `unordered_set`):** Any type that can be hashed. Works out-of-the-box with `int`, `string`, and raw pointers (`TreeNode*`, `ListNode*`).

#### Using `pair` in `unordered_map` / `unordered_set`
C++ does not provide a default hash for `std::pair` (in C++20 and earlier). You must supply a custom hash struct:

```cpp
struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>{}(p.first) ^ (hash<int>{}(p.second) << 1);
    }
};

unordered_map<pair<int, int>, int, PairHash> ump;
unordered_set<pair<int, int>, PairHash> ust;
```

### 4.3 Essential Set & Map Operations

```cpp
set<int> st;
st.insert(10);
st.find(10);   // Returns iterator to 10, or st.end() if not found
st.count(10);  // Returns 1 if present, 0 otherwise

// Accessing Min & Max elements
int smallest = *st.begin();
int largest  = *st.rbegin();

int minKey   = mp.begin()->first;
int maxKey   = mp.rbegin()->first;

// Deleting Min & Max elements
st.erase(st.begin());          // Deletes smallest
st.erase(prev(st.end()));      // Deletes largest
// st.erase(st.rbegin());      // INVALID! erase() does not accept reverse_iterator
```

#### Deleting in a `multiset`
```cpp
multiset<int> mst = {5, 5, 5};

mst.erase(5);             // Removes ALL occurrences of 5
mst.erase(mst.find(5));   // Removes ONLY ONE occurrence of 5
```

### 4.4 Pointers (`TreeNode*` / `ListNode*`) in Maps & Sets
By default, `map<TreeNode*, int>` and `set<ListNode*>` order elements by **memory address**, not by node value (`node->val`). This is great for tracking visited nodes, parent pointers, or node levels:
```cpp
map<TreeNode*, TreeNode*> parent;
map<TreeNode*, int> level;
unordered_set<ListNode*> visited;
```
*(If you want to sort pointers by `node->val`, see Section 5.4 below.)*

---

## 5. Custom Comparators

To avoid confusion, **ditch lambdas for containers and always use a `struct`**. One single `struct` works across `vector`, `set`, `map`, and `priority_queue`.

### 5.1 The Universal Template
```cpp
struct Compare {
    bool operator()(const int& a, const int& b) const {
        return a < b; // <-- The ONLY line you change
    }
};
```
*(Always keep `const` at the end—`std::set` and `std::map` will fail to compile without it. Never use `<=` or `>=`; always use strict `<` or `>`.)*

### 5.2 The Two Golden Rules

| Data Structure | How to Pass It | Effect of `return a < b;` |
| :--- | :--- | :--- |
| **`std::sort` (vector)** | `Compare()` *(with parentheses)* | **Ascending** (Smallest first) |
| **`std::set`** | `Compare` *(no parentheses)* | **Ascending** (Smallest first) |
| **`std::map`** | `Compare` *(no parentheses)* | **Ascending** by key (Smallest first) |
| **`std::priority_queue`** | `Compare` *(no parentheses)* | **Max-Heap** (Largest on top — **REVERSED!**) |

1. **Parentheses Rule:** `std::sort` is a *function*, so pass an instance: `Compare()`. Containers (`set`, `map`, `priority_queue`) are *templates*, so pass the type: `Compare`.
2. **The `priority_queue` Flip:** For `sort`, `set`, and `map`, `return a < b` means "`a` goes **before** `b`". For `priority_queue`, it means "`a` sinks **below** `b`". To build a **Min-Heap** (smallest on top), use `return a > b;`.

```cpp
std::sort(v.begin(), v.end(), Compare());
std::set<int, Compare> s;
std::map<int, std::string, Compare> mp;
std::priority_queue<int, std::vector<int>, Compare> pq;
```

### 5.3 Multi-Level Tie-Breakers
Use an **if-not-equal ladder** to check fields in order of priority:

```cpp
struct Student {
    int score, age;
    std::string name;
};

struct CompareStudent {
    bool operator()(const Student& a, const Student& b) const {
        if (a.score != b.score) return a.score > b.score; // 1. Higher score first
        if (a.age != b.age)     return a.age < b.age;     // 2. Younger first
        return a.name < b.name;                           // 3. Alphabetical
    }
};
```
* **Shortcut (`std::tie`):** If *all* fields sort in the exact same direction, write:
  ```cpp
  return std::tie(a.score, a.age, a.name) < std::tie(b.score, b.age, b.name);
  ```

### 5.4 Sorting Node Pointers (`TreeNode*` / `ListNode*`) by Value

#### For `std::set` and `std::map` (Tie-Breaker Required)
If two distinct nodes have the same `val`, `set` and `map` will treat them as duplicates and drop the second node unless you add a memory-address tie-breaker using `std::less`:

```cpp
struct CompareNode {
    bool operator()(const TreeNode* a, const TreeNode* b) const {
        if (a->val != b->val) return a->val < b->val;
        return std::less<const TreeNode*>{}(a, b); // Safe pointer tie-breaker
    }
};

std::set<TreeNode*, CompareNode> s;
std::map<TreeNode*, int, CompareNode> mp;
```

#### For `std::priority_queue` (Min-Heap of Nodes)
`priority_queue` allows duplicate values, so no tie-breaker is needed (e.g., *Merge K Sorted Lists*):

```cpp
struct CompareList {
    bool operator()(const ListNode* a, const ListNode* b) const {
        return a->val > b->val; // Flipped for Min-Heap (smallest val on top)
    }
};

std::priority_queue<ListNode*, std::vector<ListNode*>, CompareList> pq;
```

#### Pointer Comparator Watch-Outs
* **Never insert `nullptr`:** Your comparator dereferences `a->val` and `b->val`. Always check `if (node != nullptr)` before inserting, or you will get a segmentation fault.
* **Never mutate `node->val` while stored:** Changing a node's value while it is inside a `set`, `map`, or `priority_queue` corrupts the container's ordering. Erase it first, update `val`, then re-insert it.


### Fermet Little Theorem

Whenever you need to divide by b under MOD = 1e9 + 7, never write / b. Replace it with * modPow(b, MOD - 2) % MOD.

