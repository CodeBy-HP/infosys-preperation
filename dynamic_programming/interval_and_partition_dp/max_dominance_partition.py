import sys
from functools import lru_cache

def precompute_dominance(arr: list, n: int) -> list:
    """Precomputes cost[i][j] = max frequency of any element in arr[i...j]."""
    cost = [[0] * n for _ in range(n)]
    for i in range(n):
        freq = {}
        max_freq = 0
        for j in range(i, n):
            x = arr[j]
            freq[x] = freq.get(x, 0) + 1
            max_freq = max(max_freq, freq[x])
            cost[i][j] = max_freq
    return cost

# =============================================================================
# 1. Top-Down Approach (Recursion + Memoization)
# Time Complexity: O(K * N^2)
# Space Complexity: O(N^2 + K * N)
# =============================================================================
def solve_recursive_memo(arr: list, n: int, k: int) -> int:
    cost = precompute_dominance(arr, n)

    @lru_cache(maxsize=None)
    def dp(start: int, groups_left: int) -> int:
        if groups_left == 0:
            return 0 if start == n else float("-inf")
        if start == n:
            return float("-inf")

        max_score = float("-inf")
        # Try all valid partition end points
        for end in range(start, n - groups_left + 1):
            score = cost[start][end] + dp(end + 1, groups_left - 1)
            max_score = max(max_score, score)

        return max_score

    return dp(0, k)

# =============================================================================
# 2. Bottom-Up Approach (Iterative Tabulation)
# Time Complexity: O(K * N^2)
# Space Complexity: O(N^2 + K * N)
# =============================================================================
def solve_tabulation(arr: list, n: int, k: int) -> int:
    cost = precompute_dominance(arr, n)

    # dp[i][g]: max dominance partitioning prefix arr[0...i-1] into g subarrays
    dp = [[float("-inf")] * (k + 1) for _ in range(n + 1)]
    dp[0][0] = 0

    for g in range(1, k + 1):
        for i in range(g, n + 1):
            for j in range(g - 1, i):
                dp[i][g] = max(dp[i][g], dp[j][g - 1] + cost[j][i - 1])

    return dp[n][k]

# =============================================================================
# 3. Space-Optimized Approach (Rolling Array)
# Time Complexity: O(K * N^2)
# Space Complexity: O(N^2 + N)
# =============================================================================
def solve_space_optimized(arr: list, n: int, k: int) -> int:
    cost = precompute_dominance(arr, n)

    dp = [float("-inf")] * (n + 1)
    dp[0] = 0

    for g in range(1, k + 1):
        new_dp = [float("-inf")] * (n + 1)
        for i in range(g, n + 1):
            for j in range(g - 1, i):
                new_dp[i] = max(new_dp[i], dp[j] + cost[j][i - 1])
        dp = new_dp

    return dp[n]


def main():
    lines = sys.stdin.read().split()
    if lines:
        n, k = int(lines[0]), int(lines[1])
        arr = [int(x) for x in lines[2:2 + n]]
        print(solve_space_optimized(arr, n, k))
    else:
        # Sample test demonstration
        arr = [1, 2, 2, 1, 2]
        n, k = 5, 2
        print(f"Sample Test (n={n}, k={k}):")
        print("  Memoization:     ", solve_recursive_memo(arr, n, k))
        print("  Tabulation:      ", solve_tabulation(arr, n, k))
        print("  Space-Optimized: ", solve_space_optimized(arr, n, k), "(Expected: 4)")


if __name__ == "__main__":
    main()

