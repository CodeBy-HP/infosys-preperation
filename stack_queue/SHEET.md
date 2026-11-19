# Stacks & Queues Master Roadmap & Problem Sheet

Welcome to the **Stacks & Queues Algorithms & Design** master roadmap. Stacks (LIFO — Last-In, First-Out) and Queues (FIFO — First-In, First-Out) are fundamental data structures governing expression parsing, evaluation engines, sliding window optimizers, cache replacements, monotonic boundary tracking, and stream processing.

This directory organizes problems into dedicated **`stack/`** and **`queue/`** trees across **7 core algorithmic patterns**, containing **39 production-grade implementations** with rigorous mathematical proofs and multiple approaches per problem.

---

## The Core Invariants of Stacks & Queues

1. **Monotonic Stack Invariant ($O(N)$ Optimal):**
   - When querying the "next greater", "previous smaller", or bounding rectangular indices, a monotonic stack maintains elements in strictly increasing or decreasing order.
   - Dominated candidates are popped eagerly. Each element is pushed and popped at most once, guaranteeing **strictly $O(N)$ amortized time** instead of naive $O(N^2)$.
2. **Grammar & Expression Evaluation:**
   - Balanced brackets match the most recent unmatched opening delimiter with the earliest closing delimiter.
   - Infix, Prefix (Polish), and Postfix (Reverse Polish) conversions rely on operator precedence and associativity rules to resolve operands and sub-expressions via stack frames.
3. **Monotonic Deque (Sliding Window Extrema):**
   - A double-ended queue maintains candidate indices in strictly decreasing (or increasing) value order.
   - Elements outside the active sliding window $[i - k + 1, i]$ are evicted from the front (`pop_front()`), while elements dominated by incoming values are evicted from the back (`pop_back()`), yielding $O(1)$ amortized window extrema.
4. **Ring Buffer Pointer Arithmetic:**
   - Circular queues and deques eliminate memory shifting overhead by treating a contiguous vector as a ring buffer using modular arithmetic:
     $$\text{tail} = (\text{head} + \text{count} - 1) \pmod{\text{capacity}}$$
     $$\text{new\_head} = (\text{head} - 1 + \text{capacity}) \pmod{\text{capacity}}$$
5. **Cache Eviction Mechanics (LRU & LFU):**
   - **LRU:** Doubly-Linked List + Hash Map provides $O(1)$ key lookup and $O(1)$ node relocation to MRU position.
   - **LFU:** Dual Hash Maps + Frequency Doubly-Linked Lists track access frequencies with a dynamically maintained `minFreq` pointer, achieving $O(1)$ operations with LRU tie-breaking.
6. **Streaming & Lazy Eviction:**
   - In real-time streams, historical records expire either due to capacity, elapsed time ($t - 3000$), or duplicate frequency. Stale elements are lazily evicted from the front of the queue.

---

# Part I: Stacks (`stack/`)

## 1. Monotonic Stack
*Focus: Next/previous greater/smaller elements, histogram bounding boxes, elevation trapping, and lexicographical greedy trimming.*

* **[Problem 1: Next Greater Element I](stack/monotonic_stack/next_greater_element_i.md)** ([C++ Code](stack/monotonic_stack/next_greater_element_i.cpp)): Monotonic decreasing stack with hash map lookup resolving immediate rightward dominance in $O(N)$ time.
* **[Problem 2: Next Greater Element II](stack/monotonic_stack/next_greater_element_ii.md)** ([C++ Code](stack/monotonic_stack/next_greater_element_ii.cpp)): Circular array handling via virtual double-length index pass $(2N - 1 \to 0)$ with modulo indexing.
* **[Problem 3: Next Smaller Element](stack/monotonic_stack/next_smaller_element.md)** ([C++ Code](stack/monotonic_stack/next_smaller_element.cpp)): Monotonic increasing stack computing Next Smaller Element (NSE) and Previous Smaller Element (PSE) bounds.
* **[Problem 4: Daily Temperatures](stack/monotonic_stack/daily_temperatures.md)** ([C++ Code](stack/monotonic_stack/daily_temperatures.cpp)): Index-tracking monotonic stack calculating future index distance for warmer days.
* **[Problem 5: Largest Rectangle in Histogram](stack/monotonic_stack/largest_rectangle_in_histogram.md)** ([C++ Code](stack/monotonic_stack/largest_rectangle_in_histogram.cpp)): Single-pass monotonic increasing stack computing left and right smaller bounds to maximize $height \times (right - left - 1)$.
* **[Problem 6: Maximal Rectangle](stack/monotonic_stack/maximal_rectangle.md)** ([C++ Code](stack/monotonic_stack/maximal_rectangle.cpp)): Rolling histogram reduction converting 2D binary matrix into consecutive row histogram sweeps evaluated via monotonic stack in $O(R \times C)$.
* **[Problem 7: Trapping Rain Water](stack/monotonic_stack/trapping_rain_water.md)** ([C++ Code](stack/monotonic_stack/trapping_rain_water.cpp)): Dual-approach implementation featuring Two Pointers ($O(1)$ space) and Monotonic Stack bounded basin calculation.
* **[Problem 8: Sum of Subarray Minimums](stack/monotonic_stack/sum_of_subarray_minimums.md)** ([C++ Code](stack/monotonic_stack/sum_of_subarray_minimums.cpp)): Contribution trick calculating $(i - \text{pse}[i]) \times (\text{nse}[i] - i) \times \text{arr}[i] \pmod{10^9+7}$ using two-pass monotonic stack.
* **[Problem 9: Sum of Subarray Ranges](stack/monotonic_stack/sum_of_subarray_ranges.md)** ([C++ Code](stack/monotonic_stack/sum_of_subarray_ranges.cpp)): Linearity of summation decomposing range sum into $(\sum \text{maxima} - \sum \text{minima})$ evaluated in $O(N)$ time.
* **[Problem 10: Remove K Digits](stack/monotonic_stack/remove_k_digits.md)** ([C++ Code](stack/monotonic_stack/remove_k_digits.cpp)): Monotonic increasing stack with greedy peak elimination and leading-zero truncation in $O(N)$ time.
* **[Problem 11: Online Stock Span](stack/monotonic_stack/stock_span.md)** ([C++ Code](stack/monotonic_stack/stock_span.cpp)): Monotonic decreasing stack collapsing consecutive smaller/equal prices into running span weights in amortized $O(1)$ per query.
* **[Problem 12: Number of Greater Elements to the Right](stack/monotonic_stack/number_of_greater_elements_to_the_right.md)** ([C++ Code](stack/monotonic_stack/number_of_greater_elements_to_the_right.cpp)): Contrasts local monotonic stack boundaries with global order statistics via Fenwick Tree (BIT) and Coordinate Compression in $O((N + Q) \log N)$.

---

## 2. Expression Conversions
*Focus: Parsing algorithms, Shunting-yard, precedence evaluation, and notation transformation.*

* **[Problem 13: Infix to Postfix Conversion](stack/expression_conversions/infix_to_postfix.md)** ([C++ Code](stack/expression_conversions/infix_to_postfix.cpp)): Dijkstra's Shunting-yard algorithm handling operator precedence (`^` > `*`, `/` > `+`, `-`) and parentheses.
* **[Problem 14: Infix to Prefix Conversion](stack/expression_conversions/infix_to_prefix.md)** ([C++ Code](stack/expression_conversions/infix_to_prefix.cpp)): String inversion, parenthesis mirroring, modified postfix translation, and reverse pass.
* **[Problem 15: Prefix to Infix Conversion](stack/expression_conversions/prefix_to_infix.md)** ([C++ Code](stack/expression_conversions/prefix_to_infix.cpp)): Right-to-left stack assembly synthesizing nested expressions: `(op1 + op + op2)`.
* **[Problem 16: Prefix to Postfix Conversion](stack/expression_conversions/prefix_to_postfix.md)** ([C++ Code](stack/expression_conversions/prefix_to_postfix.cpp)): Right-to-left scan reordering operator and operand pairs into `op1 + op2 + op`.
* **[Problem 17: Postfix to Infix Conversion](stack/expression_conversions/postfix_to_infix.md)** ([C++ Code](stack/expression_conversions/postfix_to_infix.cpp)): Left-to-right scan with stack operand bracket encapsulation: `(op1 + op + op2)`.
* **[Problem 18: Postfix to Prefix Conversion](stack/expression_conversions/postfix_to_prefix.md)** ([C++ Code](stack/expression_conversions/postfix_to_prefix.cpp)): Left-to-right scan prefixing operator before popped operands: `op + op1 + op2`.

---

## 3. Parentheses & Parsing
*Focus: Bracket matching, string validity sanitization, and arithmetic expression evaluation.*

* **[Problem 19: Valid Parentheses](stack/parentheses_and_parsing/valid_parentheses.md)** ([C++ Code](stack/parentheses_and_parsing/valid_parentheses.cpp)): Classical delimiter stack validating matching and nesting orders of `()`, `[]`, and `{}`.
* **[Problem 20: Minimum Remove to Make Valid Parentheses](stack/parentheses_and_parsing/min_remove_to_make_valid_parentheses.md)** ([C++ Code](stack/parentheses_and_parsing/min_remove_to_make_valid_parentheses.cpp)): Index-tracking stack isolating unmatched brackets for $O(N)$ in-place character filtering.
* **[Problem 21: Evaluate Reverse Polish Notation](stack/parentheses_and_parsing/evaluate_reverse_polish_notation.md)** ([C++ Code](stack/parentheses_and_parsing/evaluate_reverse_polish_notation.cpp)): Postfix expression evaluation popping operands for binary arithmetic operations.
* **[Problem 22: Basic Calculator II](stack/parentheses_and_parsing/basic_calculator_ii.md)** ([C++ Code](stack/parentheses_and_parsing/basic_calculator_ii.cpp)): Operator precedence parser evaluating `*` and `/` eagerly and deferring `+` and `-` with $O(1)$ space optimization.
* **[Problem 23: Bracket Balance Cost](stack/parentheses_and_parsing/bracket_balance_cost.md)** ([C++ Code](stack/parentheses_and_parsing/bracket_balance_cost.cpp)): Minimum insertion cost to balance bracket sequence modulo $10^9 + 7$ via greedy deficit tracking.

---

## 4. Design & Simulation (Stack)
*Focus: Data structure internals, state tracking, and elimination games.*

* **[Problem 24: Implement Stack using Array](stack/design_and_simulation/implement_stack_using_array.md)** ([C++ Code](stack/design_and_simulation/implement_stack_using_array.cpp)): Fixed-capacity contiguous buffer and dynamic geometric amortized array implementations.
* **[Problem 25: Implement Stack using Linked List](stack/design_and_simulation/implement_stack_using_linked_list.md)** ([C++ Code](stack/design_and_simulation/implement_stack_using_linked_list.cpp)): Singly linked list stack using raw pointers and modern C++ `std::unique_ptr` ownership.
* **[Problem 26: Implement Queue using Stacks](stack/design_and_simulation/implement_queue_using_stacks.md)** ([C++ Code](stack/design_and_simulation/implement_queue_using_stacks.cpp)): Dual-stack FIFO simulation achieving amortized $O(1)$ per operation via lazy transfer.
* **[Problem 27: Min Stack](stack/design_and_simulation/min_stack.md)** ([C++ Code](stack/design_and_simulation/min_stack.cpp)): Parallel tracking of running minimums guaranteeing $O(1)$ `getMin()`, `push()`, and `pop()`.
* **[Problem 28: Asteroid Collision](stack/design_and_simulation/asteroid_collision.md)** ([C++ Code](stack/design_and_simulation/asteroid_collision.cpp)): Vector-as-stack collision simulator resolving opposing directional vectors.
* **[Problem 29: The Celebrity Problem](stack/design_and_simulation/celebrity_problem.md)** ([C++ Code](stack/design_and_simulation/celebrity_problem.cpp)): Elimination invariant reducing $N$ candidates to 1 in $O(N)$ comparisons via stack and two-pointer techniques.

---

# Part II: Queues (`queue/`)

## 5. Monotonic Deque
*Focus: Extreme value tracking over sliding windows, constrained DP, and prefix sum optimization.*

* **[Problem 30: Sliding Window Maximum](queue/monotonic_deque/sliding_window_maximum.md)** ([C++ Code](queue/monotonic_deque/sliding_window_maximum.cpp)): Monotonic decreasing deque maintaining candidate maxima across moving windows of length $k$ in $O(N)$ time.
* **[Problem 31: Shortest Subarray with Sum at Least K](queue/monotonic_deque/shortest_subarray_with_sum_at_least_k.md)** ([C++ Code](queue/monotonic_deque/shortest_subarray_with_sum_at_least_k.cpp)): Monotonic increasing deque over prefix sums with negative values achieving optimal $O(N)$ where two pointers fail.
* **[Problem 32: Constrained Subsequence Sum](queue/monotonic_deque/constrained_subsequence_sum.md)** ([C++ Code](queue/monotonic_deque/constrained_subsequence_sum.cpp)): Monotonic deque optimization reducing dynamic programming transition from $O(N \cdot k)$ to optimal $O(N)$.

---

## 6. Design & Simulation (Queue & Caches)
*Focus: Circular buffers, cross-structure emulation, and LRU/LFU cache eviction architectures.*

* **[Problem 33: Implement Queue using Array](queue/design_and_simulation/implement_queue_using_array.md)** ([C++ Code](queue/design_and_simulation/implement_queue_using_array.cpp)): Fixed-size circular ring buffer and dynamic circular resizing queue.
* **[Problem 34: Implement Queue using Linked List](queue/design_and_simulation/implement_queue_using_linked_list.md)** ([C++ Code](queue/design_and_simulation/implement_queue_using_linked_list.cpp)): Head and tail pointer linked list achieving strict $O(1)$ bounded enqueue and dequeue.
* **[Problem 35: Design Circular Queue](queue/design_and_simulation/design_circular_queue.md)** ([C++ Code](queue/design_and_simulation/design_circular_queue.cpp)): Fixed-capacity ring buffer using modular index arithmetic without dynamic reallocation.
* **[Problem 36: Design Circular Deque](queue/design_and_simulation/design_circular_deque.md)** ([C++ Code](queue/design_and_simulation/design_circular_deque.cpp)): Double-ended circular ring buffer supporting push and pop at both boundaries in $O(1)$ time.
* **[Problem 37: Implement Stack using Queues](queue/design_and_simulation/implement_stack_using_queues.md)** ([C++ Code](queue/design_and_simulation/implement_stack_using_queues.cpp)): Elegant single-queue internal rotation simulating LIFO mechanics with $O(1)$ pop and top.
* **[Problem 38: LRU Cache](queue/design_and_simulation/lru_cache.md)** ([C++ Code](queue/design_and_simulation/lru_cache.cpp)): Doubly-Linked List + Hash Map supporting $O(1)$ `get()` and `put()` with sentinel boundary nodes.
* **[Problem 39: LFU Cache](queue/design_and_simulation/lfu_cache.md)** ([C++ Code](queue/design_and_simulation/lfu_cache.cpp)): Dual Hash Maps + Frequency Doubly-Linked Lists with dynamic `minFreq` tracker achieving $O(1)$ LFU eviction with LRU tie-breaking.

---

## 7. Stream & Sliding Buffer
*Focus: Online real-time streaming, sliding averages, and lazy element eviction.*

* **[Problem 40: Moving Average from Data Stream](queue/stream_and_sliding_buffer/moving_average_from_data_stream.md)** ([C++ Code](queue/stream_and_sliding_buffer/moving_average_from_data_stream.cpp)): FIFO queue sliding window maintaining a running sum for $O(1)$ arithmetic average calculation.
* **[Problem 41: First Unique Character in a Stream](queue/stream_and_sliding_buffer/first_unique_character_in_a_stream.md)** ([C++ Code](queue/stream_and_sliding_buffer/first_unique_character_in_a_stream.cpp)): Frequency table paired with a queue employing lazy front eviction to return first unique characters in amortized $O(1)$.
* **[Problem 42: Number of Recent Calls](queue/stream_and_sliding_buffer/number_of_recent_calls.md)** ([C++ Code](queue/stream_and_sliding_buffer/number_of_recent_calls.cpp)): Chronological timestamp queue evicting calls older than 3000ms in amortized $O(1)$ time.

---

## Quick Reference Summary

| Category | Problem | Time Complexity | Auxiliary Space | Primary Invariant / Pattern |
| :--- | :--- | :--- | :--- | :--- |
| **Stack** | [Next Greater Element I](stack/monotonic_stack/next_greater_element_i.md) | $O(N)$ | $O(N)$ | Monotonic decreasing stack + Hash Map |
| **Stack** | [Next Greater Element II](stack/monotonic_stack/next_greater_element_ii.md) | $O(N)$ | $O(N)$ | Circular array $(2N)$ virtual scan |
| **Stack** | [Next Smaller Element](stack/monotonic_stack/next_smaller_element.md) | $O(N)$ | $O(N)$ | Monotonic increasing stack for NSE/PSE bounds |
| **Stack** | [Daily Temperatures](stack/monotonic_stack/daily_temperatures.md) | $O(N)$ | $O(N)$ | Monotonic stack storing indices |
| **Stack** | [Largest Rectangle in Histogram](stack/monotonic_stack/largest_rectangle_in_histogram.md) | $O(N)$ | $O(N)$ | Monotonic increasing stack width expansion |
| **Stack** | [Maximal Rectangle](stack/monotonic_stack/maximal_rectangle.md) | $O(R \times C)$ | $O(C)$ | Rolling row histogram + Monotonic Stack |
| **Stack** | [Trapping Rain Water](stack/monotonic_stack/trapping_rain_water.md) | $O(N)$ | $O(1)$ / $O(N)$ | Two Pointers & Monotonic Stack basin math |
| **Stack** | [Sum of Subarray Minimums](stack/monotonic_stack/sum_of_subarray_minimums.md) | $O(N)$ | $O(N)$ | Contribution trick: $(i - pse) \times (nse - i) \times arr[i]$ |
| **Stack** | [Sum of Subarray Ranges](stack/monotonic_stack/sum_of_subarray_ranges.md) | $O(N)$ | $O(N)$ | Linearity: $(\sum \text{maxima} - \sum \text{minima})$ |
| **Stack** | [Remove K Digits](stack/monotonic_stack/remove_k_digits.md) | $O(N)$ | $O(N)$ | Monotonic increasing stack greedy peak removal |
| **Stack** | [Online Stock Span](stack/monotonic_stack/stock_span.md) | $O(1)$ amortized | $O(N)$ | Monotonic stack storing `{price, span}` pairs |
| **Stack** | [Number of Greater Elements to Right](stack/monotonic_stack/number_of_greater_elements_to_the_right.md) | $O((N + Q) \log N)$ | $O(N)$ | Fenwick Tree (BIT) + Coordinate Compression |
| **Stack** | [Infix to Postfix](stack/expression_conversions/infix_to_postfix.md) | $O(N)$ | $O(N)$ | Shunting-yard operator precedence algorithm |
| **Stack** | [Infix to Prefix](stack/expression_conversions/infix_to_prefix.md) | $O(N)$ | $O(N)$ | String inversion + modified postfix |
| **Stack** | [Prefix to Infix](stack/expression_conversions/prefix_to_infix.md) | $O(N)$ | $O(N)$ | Right-to-left scan with stack assembly |
| **Stack** | [Prefix to Postfix](stack/expression_conversions/prefix_to_postfix.md) | $O(N)$ | $O(N)$ | Right-to-left scan stack concatenation |
| **Stack** | [Postfix to Infix](stack/expression_conversions/postfix_to_infix.md) | $O(N)$ | $O(N)$ | Left-to-right scan stack assembly |
| **Stack** | [Postfix to Prefix](stack/expression_conversions/postfix_to_prefix.md) | $O(N)$ | $O(N)$ | Left-to-right scan stack concatenation |
| **Stack** | [Valid Parentheses](stack/parentheses_and_parsing/valid_parentheses.md) | $O(N)$ | $O(N)$ | LIFO matching delimiter stack |
| **Stack** | [Min Remove Valid Parentheses](stack/parentheses_and_parsing/min_remove_to_make_valid_parentheses.md) | $O(N)$ | $O(N)$ | Index tracking stack + two-pass filter |
| **Stack** | [Evaluate RPN](stack/parentheses_and_parsing/evaluate_reverse_polish_notation.md) | $O(N)$ | $O(N)$ | Postfix arithmetic stack evaluation |
| **Stack** | [Basic Calculator II](stack/parentheses_and_parsing/basic_calculator_ii.md) | $O(N)$ | $O(1)$ | Operator precedence and intermediate sum |
| **Stack** | [Bracket Balance Cost](stack/parentheses_and_parsing/bracket_balance_cost.md) | $O(N)$ | $O(1)$ | Greedy deficit tracking modulo $10^9+7$ |
| **Stack** | [Implement Stack using Array](stack/design_and_simulation/implement_stack_using_array.md) | $O(1)$ amortized | $O(N)$ | Contiguous buffer + geometric dynamic resizing |
| **Stack** | [Implement Stack using Linked List](stack/design_and_simulation/implement_stack_using_linked_list.md) | $O(1)$ | $O(N)$ | Top pointer manipulation + `std::unique_ptr` |
| **Stack** | [Implement Queue using Stacks](stack/design_and_simulation/implement_queue_using_stacks.md) | $O(1)$ amortized | $O(N)$ | Dual stack lazy transfer |
| **Stack** | [Min Stack](stack/design_and_simulation/min_stack.md) | $O(1)$ | $O(N)$ | Auxiliary stack / pair storing minimums |
| **Stack** | [Asteroid Collision](stack/design_and_simulation/asteroid_collision.md) | $O(N)$ | $O(N)$ | Directional sign cancellation simulation |
| **Stack** | [The Celebrity Problem](stack/design_and_simulation/celebrity_problem.md) | $O(N)$ | $O(1)$ / $O(N)$ | Stack and Two-Pointer elimination |
| **Queue** | [Implement Queue using Array](queue/design_and_simulation/implement_queue_using_array.md) | $O(1)$ | $O(N)$ | Circular ring buffer pointer arithmetic |
| **Queue** | [Implement Queue using Linked List](queue/design_and_simulation/implement_queue_using_linked_list.md) | $O(1)$ | $O(N)$ | Head and tail pointer FIFO queue |
| **Queue** | [Sliding Window Maximum](queue/monotonic_deque/sliding_window_maximum.md) | $O(N)$ | $O(k)$ | Monotonic decreasing deque |
| **Queue** | [Shortest Subarray with Sum $\ge K$](queue/monotonic_deque/shortest_subarray_with_sum_at_least_k.md) | $O(N)$ | $O(N)$ | Monotonic increasing deque over prefix sums |
| **Queue** | [Constrained Subsequence Sum](queue/monotonic_deque/constrained_subsequence_sum.md) | $O(N)$ | $O(N)$ | Monotonic deque optimized DP |
| **Queue** | [Design Circular Queue](queue/design_and_simulation/design_circular_queue.md) | $O(1)$ | $O(k)$ | Fixed ring buffer with head and count |
| **Queue** | [Design Circular Deque](queue/design_and_simulation/design_circular_deque.md) | $O(1)$ | $O(k)$ | Bidirectional ring buffer pointer math |
| **Queue** | [Implement Stack using Queues](queue/design_and_simulation/implement_stack_using_queues.md) | Push $O(N)$, Pop $O(1)$ | $O(N)$ | Single-queue rotation trick |
| **Queue** | [LRU Cache](queue/design_and_simulation/lru_cache.md) | $O(1)$ | $O(\text{capacity})$ | Doubly-Linked List + Hash Map |
| **Queue** | [LFU Cache](queue/design_and_simulation/lfu_cache.md) | $O(1)$ | $O(\text{capacity})$ | Dual Hash Maps + Frequency Doubly-Linked Lists |
| **Queue** | [Moving Average from Stream](queue/stream_and_sliding_buffer/moving_average_from_data_stream.md) | $O(1)$ | $O(size)$ | Sliding window FIFO running sum |
| **Queue** | [First Unique Character in Stream](queue/stream_and_sliding_buffer/first_unique_character_in_a_stream.md) | $O(1)$ amortized | $O(\Sigma)$ | Frequency count + queue lazy eviction |
| **Queue** | [Number of Recent Calls](queue/stream_and_sliding_buffer/number_of_recent_calls.md) | $O(1)$ amortized | $O(W)$ | Sliding timestamp queue |
