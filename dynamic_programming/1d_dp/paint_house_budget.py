import sys
from functools import lru_cache

# =============================================================================
# 1. Top-Down Approach (Recursion + Memoization)
# Time Complexity: O(N * C^2)
# Space Complexity: O(N * C) [Memo cache + Call stack]
# =============================================================================
def paint_house_memo(N: int, C: int, B: int, cost: list) -> int:
    @lru_cache(maxsize=None)
    def solve(idx: int, prev_color: int) -> int:
        if idx == N:
            return 0

        min_cost = float("inf")
        for color in range(C):
            if color != prev_color:
                res = solve(idx + 1, color)
                if res != float("inf"):
                    min_cost = min(min_cost, cost[idx][color] + res)

        return min_cost

    ans = solve(0, -1)
    return ans if ans <= B else -1


# =============================================================================
# 2. Bottom-Up Approach (Iterative Tabulation)
# Time Complexity: O(N * C^2)
# Space Complexity: O(N * C) [DP Table]
# =============================================================================
def paint_house_tabulation(N: int, C: int, B: int, cost: list) -> int:
    if N == 0:
        return 0

    dp = [[float("inf")] * C for _ in range(N)]

    # Base case: first house
    for c in range(C):
        dp[0][c] = cost[0][c]

    # Fill table
    for i in range(1, N):
        for c in range(C):
            prev_min = min(dp[i - 1][k] for k in range(C) if k != c)
            dp[i][c] = cost[i][c] + prev_min

    ans = min(dp[N - 1])
    return ans if ans <= B else -1


# =============================================================================
# 3. Space-Optimized Approach (O(C) Space with O(N * C) Optimization)
# Finds the smallest and second smallest costs in the previous row to eliminate
# the inner O(C) search loop!
# Time Complexity: O(N * C)
# Space Complexity: O(C)
# =============================================================================
def paint_house_space_optimized(N: int, C: int, B: int, cost: list) -> int:
    if N == 0:
        return 0

    dp = list(cost[0])

    for i in range(1, N):
        # Find 1st min and 2nd min from previous row
        min1, min2 = float("inf"), float("inf")
        idx1 = -1
        for c in range(C):
            if dp[c] < min1:
                min2 = min1
                min1 = dp[c]
                idx1 = c
            elif dp[c] < min2:
                min2 = dp[c]

        new_dp = [0] * C
        for c in range(C):
            # If current color matches the 1st min color, use 2nd min
            prev_best = min2 if c == idx1 else min1
            new_dp[c] = cost[i][c] + prev_best

        dp = new_dp

    ans = min(dp)
    return ans if ans <= B else -1


def main():
    tokens = iter(sys.stdin.read().split())
    try:
        N = int(next(tokens))
        C = int(next(tokens))
        B = int(next(tokens))
        cost = [[int(next(tokens)) for _ in range(C)] for _ in range(N)]
    except StopIteration:
        # Default test run
        N, C, B = 3, 3, 20
        cost = [
            [1, 2, 3],
            [1, 4, 6],
            [3, 2, 1]
        ]

    ans = paint_house_space_optimized(N, C, B, cost)
    print(ans)


if __name__ == '__main__':
    main()

