# First Unique Character in a Stream

## Problem Statement
Given a stream of characters, find the first non-repeating character each time a new character is inserted into the stream. If there is no unique character at any point, output `'#'`.

Implement the `StreamFirstUnique` class:
- `void add(char c)`: Appends character `c` to the stream.
- `char getFirstUnique()`: Returns the first unique character in the stream so far, or `'#'` if no unique characters exist.

### Example 1:
```
Stream: "a", "a", "b", "c"
add('a') -> getFirstUnique() returns 'a'
add('a') -> getFirstUnique() returns '#' (since 'a' is repeated)
add('b') -> getFirstUnique() returns 'b'
add('c') -> getFirstUnique() returns 'b'
```

### Constraints:
- Stream can have up to $10^5$ characters.
- Characters are lowercase English letters `'a'` - `'z'`.

---

## Pattern Insight: Frequency Table + Queue Lazy Eviction
- A queue preserves insertion order.
- A frequency table tracks how many times each character has appeared.
- Upon `add(c)`:
  - Increment `freq[c]`.
  - Push `c` into the queue.
- Upon `getFirstUnique()`:
  - Look at `q.front()`. If `freq[q.front()] > 1`, that character is repeated and can never become unique again. Pop it from the front!
  - Repeat until `q` is empty or `freq[q.front()] == 1`.
  - Return `q.front()`, or `'#'` if empty.
- **Amortized Analysis**: Each character is pushed at most once and popped at most once across the lifetime of the stream. Thus, the amortized cost of each operation is $O(1)$.

---

## Complexity
- **Time Complexity:** $O(1)$ amortized for both `add()` and `getFirstUnique()`.
- **Space Complexity:** $O(\Sigma)$ where $\Sigma$ is alphabet size (or $O(N)$ for queue).
