# Stacks & Queues Master Roadmap & Problem Sheet

Welcome to the **Stacks & Queues Algorithms & Design** paradigm. Stacks (LIFO — Last-In, First-Out) and Queues (FIFO — First-In, First-Out) are fundamental linear data structures that govern execution flows, parsing engines, expression evaluators, sliding window optimizers, and stream processors. In technical assessments, these structures are heavily tested to evaluate **monotonic invariant maintenance, parenthetical grammar parsing, ring buffer pointer manipulation, and amortized $O(1)$ complexity analysis**.

Per requirements, this repository explicitly separates problems into dedicated **`stack/`** and **`queue/`** directories, organizing **21 production-grade problems** across **6 core patterns**.

---

## The Core Invariants of Stacks & Queues

1. **Monotonic Stack Invariant ($O(N)$ Optimal):**
   - When seeking the "next greater" or "previous smaller" element, a monotonic stack maintains elements in strictly increasing or decreasing order.
   - Any element that is dominated by a newly arrived candidate is popped immediately.
   - Every element is pushed onto the stack at most once and popped at most once, guaranteeing **strictly $O(N)$ total time** instead of naive $O(N^2)$.
2. **Grammar & Expression Evaluation:**
   - Balanced brackets match the most recent unmatched opening delimiter with the earliest closing delimiter — a textbook LIFO scenario.
   - In arithmetic calculators (e.g., Reverse Polish Notation or infix expressions), stacks handle operator precedence (* and / evaluated before + and -) and parenthesis nesting depth.
3. **Monotonic Deque (Sliding Window Extrema):**
   - A double-ended queue maintains candidate indices in strictly decreasing (or increasing) value order.
   - Elements outside the active sliding window $[i - k + 1, i]$ are evicted from the front (`pop_front()`), while elements smaller than or equal to incoming $nums[i]$ are evicted from the back (`pop_back()`).
   - The current maximum/minimum is always accessible in $O(1)$ at `dq.front()`.
4. **Ring Buffer Pointer Arithmetic:**
   - Circular queues and deques eliminate memory shifting overhead by treating a fixed-size vector as a ring buffer using modular arithmetic:
     $$\text{tail} = (\text{head} + \text{count} - 1) \pmod{\text{capacity}}$$
     $$\text{new\_head} = (\text{head} - 1 + \text{capacity}) \pmod{\text{capacity}}$$
   - Guarantees true $O(1)$ bounded memory without dynamic reallocation.
5. **Streaming & Lazy Eviction:**
   - In real-time data streams, historical records expire either due to window capacity, elapsed time ($t - 3000$), or duplicate frequency.
   - Stale elements are lazily popped from the front of the queue only when queried or when window boundaries are exceeded, achieving amortized $O(1)$ per operation.

---

# Part I: Stacks (`stack/`)

## 1. Monotonic Stack
*Focus: Next greater/smaller element queries, histogram bounding boxes, and elevation trapping.*

* **[Problem 1: Next Greater Element I](stack/monotonic_stack/next_greater_element_i.md)** ([C++ Code](stack/monotonic_stack/next_greater_element_i.cpp)): Monotonic decreasing stack with hash map lookup resolving immediate rightward dominance in $O(N)$ time.
* **[Problem 2: Next Greater Element II](stack/monotonic_stack/next_greater_element_ii.md)** ([C++ Code](stack/monotonic_stack/next_greater_element_ii.cpp)): Circular array handling via virtual double-length index pass $(2N - 1 \to 0)$ with modulo indexing.
* **[Problem 3: Daily Temperatures](stack/monotonic_stack/daily_temperatures.md)** ([C++ Code](stack/monotonic_stack/daily_temperatures.cpp)): Index-tracking monotonic stack calculating future index distance for warmer days.
* **[Problem 4: Largest Rectangle in Histogram](stack/monotonic_stack/largest_rectangle_in_histogram.md)** ([C++ Code](stack/monotonic_stack/largest_rectangle_in_histogram.cpp)): Single-pass monotonic increasing stack computing left and right smaller bounds to maximize $height \times (right - left - 1)$.
* **[Problem 5: Trapping Rain Water](stack/monotonic_stack/trapping_rain_water.md)** ([C++ Code](stack/monotonic_stack/trapping_rain_water.cpp)): Dual-approach implementation featuring Two Pointers ($O(1)$ space) and Monotonic Stack bounded basin calculation.

---

## 2. Parentheses & Parsing
*Focus: Bracket matching, string validity sanitization, and arithmetic expression evaluation.*

* **[Problem 6: Valid Parentheses](stack/parentheses_and_parsing/valid_parentheses.md)** ([C++ Code](stack/parentheses_and_parsing/valid_parentheses.cpp)): Classical delimiter stack validating matching and nesting orders of `()`, `[]`, and `{}`.
* **[Problem 7: Minimum Remove to Make Valid Parentheses](stack/parentheses_and_parsing/min_remove_to_make_valid_parentheses.md)** ([C++ Code](stack/parentheses_and_parsing/min_remove_to_make_valid_parentheses.cpp)): Index-tracking stack isolating unmatched brackets for $O(N)$ in-place character filtering.
* **[Problem 8: Evaluate Reverse Polish Notation](stack/parentheses_and_parsing/evaluate_reverse_polish_notation.md)** ([C++ Code](stack/parentheses_and_parsing/evaluate_reverse_polish_notation.cpp)): Postfix expression evaluation popping operands for binary arithmetic operations.
* **[Problem 9: Basic Calculator II](stack/parentheses_and_parsing/basic_calculator_ii.md)** ([C++ Code](stack/parentheses_and_parsing/basic_calculator_ii.cpp)): Operator precedence parser evaluating `*` and `/` eagerly and deferring `+` and `-` with $O(1)$ space optimization.

---

## 3. Design & Simulation
*Focus: Augmented state tracking, cross-structure emulation, and physical simulations.*

* **[Problem 10: Min Stack](stack/design_and_simulation/min_stack.md)** ([C++ Code](stack/design_and_simulation/min_stack.cpp)): Parallel tracking of running minimums guaranteeing $O(1)$ `getMin()`, `push()`, and `pop()`.
* **[Problem 11: Implement Queue using Stacks](stack/design_and_simulation/implement_queue_using_stacks.md)** ([C++ Code](stack/design_and_simulation/implement_queue_using_stacks.cpp)): Dual-stack FIFO simulation achieving amortized $O(1)$ per operation via lazy transfer.
* **[Problem 12: Asteroid Collision](stack/design_and_simulation/asteroid_collision.md)** ([C++ Code](stack/design_and_simulation/asteroid_collision.cpp)): Vector-as-stack collision simulator resolving opposing directional vectors.

---

# Part II: Queues (`queue/`)

## 4. Monotonic Deque
*Focus: Extreme value tracking over sliding windows, constrained DP, and prefix sum optimization.*

* **[Problem 13: Sliding Window Maximum](queue/monotonic_deque/sliding_window_maximum.md)** ([C++ Code](queue/monotonic_deque/sliding_window_maximum.cpp)): Monotonic decreasing deque maintaining candidate maxima across moving windows of length $k$ in $O(N)$ time.
* **[Problem 14: Shortest Subarray with Sum at Least K](queue/monotonic_deque/shortest_subarray_with_sum_at_least_k.md)** ([C++ Code](queue/monotonic_deque/shortest_subarray_with_sum_at_least_k.cpp)): Monotonic increasing deque over prefix sums with negative values achieving optimal $O(N)$ where two pointers fail.
* **[Problem 15: Constrained Subsequence Sum](queue/monotonic_deque/constrained_subsequence_sum.md)** ([C++ Code](queue/monotonic_deque/constrained_subsequence_sum.cpp)): Monotonic deque optimization reducing dynamic programming transition from $O(N \cdot k)$ to optimal $O(N)$.

---

## 5. Design & Simulation
*Focus: Circular ring buffers, double-ended queues, and single-queue rotation simulation.*

* **[Problem 16: Design Circular Queue](queue/design_and_simulation/design_circular_queue.md)** ([C++ Code](queue/design_and_simulation/design_circular_queue.cpp)): Fixed-capacity ring buffer using modular index arithmetic without dynamic reallocation.
* **[Problem 17: Design Circular Deque](queue/design_and_simulation/design_circular_deque.md)** ([C++ Code](queue/design_and_simulation/design_circular_deque.cpp)): Double-ended circular ring buffer supporting push and pop at both boundaries in $O(1)$ time.
* **[Problem 18: Implement Stack using Queues](queue/design_and_simulation/implement_stack_using_queues.md)** ([C++ Code](queue/design_and_simulation/implement_stack_using_queues.cpp)): Elegant single-queue internal rotation simulating LIFO mechanics with $O(1)$ pop and top.

---

## 6. Stream & Sliding Buffer
*Focus: Online real-time streaming, sliding averages, and lazy element eviction.*

* **[Problem 19: Moving Average from Data Stream](queue/stream_and_sliding_buffer/moving_average_from_data_stream.md)** ([C++ Code](queue/stream_and_sliding_buffer/moving_average_from_data_stream.cpp)): FIFO queue sliding window maintaining a running sum for $O(1)$ arithmetic average calculation.
* **[Problem 20: First Unique Character in a Stream](queue/stream_and_sliding_buffer/first_unique_character_in_a_stream.md)** ([C++ Code](queue/stream_and_sliding_buffer/first_unique_character_in_a_stream.cpp)): Frequency table paired with a queue employing lazy front eviction to return first unique characters in amortized $O(1)$.
* **[Problem 21: Number of Recent Calls](queue/stream_and_sliding_buffer/number_of_recent_calls.md)** ([C++ Code](queue/stream_and_sliding_buffer/number_of_recent_calls.cpp)): Chronological timestamp queue evicting calls older than 3000ms in amortized $O(1)$ time.

---

## Quick Reference Summary

| Category | Problem | Time | Space | Primary Invariant / Pattern |
| :--- | :--- | :--- | :--- | :--- |
| **Stack** | [Next Greater Element I](stack/monotonic_stack/next_greater_element_i.md) | $O(N)$ | $O(N)$ | Monotonic decreasing stack + Hash Map |
| **Stack** | [Next Greater Element II](stack/monotonic_stack/next_greater_element_ii.md) | $O(N)$ | $O(N)$ | Circular array $(2N)$ virtual scan |
| **Stack** | [Daily Temperatures](stack/monotonic_stack/daily_temperatures.md) | $O(N)$ | $O(N)$ | Monotonic stack storing indices |
| **Stack** | [Largest Rectangle in Histogram](stack/monotonic_stack/largest_rectangle_in_histogram.md) | $O(N)$ | $O(N)$ | Monotonic increasing stack width expansion |
| **Stack** | [Trapping Rain Water](stack/monotonic_stack/trapping_rain_water.md) | $O(N)$ | $O(1)$ / $O(N)$ | Two Pointers & Monotonic Stack basin math |
| **Stack** | [Valid Parentheses](stack/parentheses_and_parsing/valid_parentheses.md) | $O(N)$ | $O(N)$ | LIFO matching delimiter stack |
| **Stack** | [Min Remove Valid Parentheses](stack/parentheses_and_parsing/min_remove_to_make_valid_parentheses.md) | $O(N)$ | $O(N)$ | Index tracking stack + two-pass filter |
| **Stack** | [Evaluate RPN](stack/parentheses_and_parsing/evaluate_reverse_polish_notation.md) | $O(N)$ | $O(N)$ | Postfix arithmetic stack evaluation |
| **Stack** | [Basic Calculator II](stack/parentheses_and_parsing/basic_calculator_ii.md) | $O(N)$ | $O(1)$ | Operator precedence and intermediate sum |
| **Stack** | [Min Stack](stack/design_and_simulation/min_stack.md) | $O(1)$ | $O(N)$ | Auxiliary stack / pair storing minimums |
| **Stack** | [Implement Queue using Stacks](stack/design_and_simulation/implement_queue_using_stacks.md) | $O(1)$ amortized | $O(N)$ | Dual stack lazy transfer |
| **Stack** | [Asteroid Collision](stack/design_and_simulation/asteroid_collision.md) | $O(N)$ | $O(N)$ | Directional sign cancellation simulation |
| **Queue** | [Sliding Window Maximum](queue/monotonic_deque/sliding_window_maximum.md) | $O(N)$ | $O(k)$ | Monotonic decreasing deque |
| **Queue** | [Shortest Subarray with Sum $\ge K$](queue/monotonic_deque/shortest_subarray_with_sum_at_least_k.md) | $O(N)$ | $O(N)$ | Monotonic increasing deque over prefix sums |
| **Queue** | [Constrained Subsequence Sum](queue/monotonic_deque/constrained_subsequence_sum.md) | $O(N)$ | $O(N)$ | Monotonic deque optimized DP |
| **Queue** | [Design Circular Queue](queue/design_and_simulation/design_circular_queue.md) | $O(1)$ | $O(k)$ | Fixed ring buffer with head and count |
| **Queue** | [Design Circular Deque](queue/design_and_simulation/design_circular_deque.md) | $O(1)$ | $O(k)$ | Bidirectional ring buffer pointer math |
| **Queue** | [Implement Stack using Queues](queue/design_and_simulation/implement_stack_using_queues.md) | Push $O(N)$, Pop $O(1)$ | $O(N)$ | Single-queue rotation trick |
| **Queue** | [Moving Average from Stream](queue/stream_and_sliding_buffer/moving_average_from_data_stream.md) | $O(1)$ | $O(size)$ | Sliding window FIFO running sum |
| **Queue** | [First Unique Character in Stream](queue/stream_and_sliding_buffer/first_unique_character_in_a_stream.md) | $O(1)$ amortized | $O(\Sigma)$ | Frequency count + queue lazy eviction |
| **Queue** | [Number of Recent Calls](queue/stream_and_sliding_buffer/number_of_recent_calls.md) | $O(1)$ amortized | $O(W)$ | Sliding timestamp queue |

