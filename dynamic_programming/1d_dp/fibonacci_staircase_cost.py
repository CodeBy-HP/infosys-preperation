import sys
from functools import lru_cache

# Generate Fibonacci numbers up to limit
def get_fibonacci_numbers(limit: int):
    fibs = []
    a, b = 1, 2
    while a <= limit:
        fibs.append(a)
        a, b = b, a + b
    return fibs

# =============================================================================
# 1. Top-Down Approach (Recursion + Memoization DP)
# Time Complexity: O(D * log D), where D = N - 1
# Space Complexity: O(D)
# =============================================================================
def solve_recursive_memo(N: int, A: int, B: int) -> int:
    dist = N - 1
    if dist <= 0:
        return 0

    fibs = get_fibonacci_numbers(dist)

    @lru_cache(maxsize=None)
    def min_jumps(rem: int) -> int:
        if rem == 0:
            return 0
        ans = float("inf")
        for f in reversed(fibs):
            if f <= rem:
                ans = min(ans, 1 + min_jumps(rem - f))
        return ans

    jumps = min_jumps(dist)
    return jumps * A + B * dist

# =============================================================================
# 2. Bottom-Up Approach (Iterative Tabulation DP)
# Time Complexity: O(D * log D), where D = N - 1
# Space Complexity: O(D)
# =============================================================================
def solve_bottom_up_dp(N: int, A: int, B: int) -> int:
    dist = N - 1
    if dist <= 0:
        return 0

    fibs = get_fibonacci_numbers(dist)
    dp = [float("inf")] * (dist + 1)
    dp[0] = 0

    for i in range(1, dist + 1):
        for f in fibs:
            if f > i:
                break
            dp[i] = min(dp[i], 1 + dp[i - f])

    return dp[dist] * A + B * dist

# =============================================================================
# 3. Optimal Zeckendorf Greedy Approach
# Since cost = (jumps * A) + B * (N - 1), minimizing cost is strictly equivalent
# to minimizing the number of jumps. By Zeckendorf's theorem, repeatedly taking
# the largest Fibonacci number <= remaining distance achieves the minimal count.
# Time Complexity: O(log N)
# Space Complexity: O(1)
# =============================================================================
def solve_zeckendorf_greedy(N: int, A: int, B: int) -> int:
    dist = N - 1
    if dist <= 0:
        return 0

    fibs = get_fibonacci_numbers(dist)
    jumps = 0
    rem = dist

    for f in reversed(fibs):
        if f <= rem:
            jumps += 1
            rem -= f
            if rem == 0:
                break

    return jumps * A + B * dist


if __name__ == "__main__":
    line = sys.stdin.read().strip()
    if line:
        N, A, B = map(int, line.split())
        print(solve_zeckendorf_greedy(N, A, B))
    else:
        # Example demonstration
        print("Demo N=10, A=5, B=2:")
        print("  Recursive Memo:   ", solve_recursive_memo(10, 5, 2))
        print("  Bottom-Up DP:     ", solve_bottom_up_dp(10, 5, 2))
        print("  Zeckendorf Greedy:", solve_zeckendorf_greedy(10, 5, 2))

