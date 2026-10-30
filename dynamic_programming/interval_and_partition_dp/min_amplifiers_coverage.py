import sys
from bisect import bisect_right
from functools import lru_cache

# =============================================================================
# 1. Top-Down Approach (Recursion + Memoization)
# Time Complexity: O(N * K + N log N)
# Space Complexity: O(N * K)
# =============================================================================
def find_min_amplifiers_memo(arr: list, r: int, k: int) -> int:
    arr = sorted(arr)
    n = len(arr)

    @lru_cache(maxsize=None)
    def dp(i: int, remaining: int) -> int:
        if i >= n:
            return 0

        # Choice 1: Place normal amplifier (span = 2 * r)
        j1 = bisect_right(arr, arr[i] + 2 * r)
        way1 = 1 + dp(j1, remaining)

        # Choice 2: Place super amplifier (span = 4 * r)
        way2 = float("inf")
        if remaining > 0:
            j2 = bisect_right(arr, arr[i] + 4 * r)
            way2 = 1 + dp(j2, remaining - 1)

        return min(way1, way2)

    return dp(0, k)


# =============================================================================
# 2. Bottom-Up Approach (Iterative Tabulation)
# Time Complexity: O(N * K + N log N)
# Space Complexity: O(N * K)
# =============================================================================
def find_min_amplifiers_tabulation(arr: list, r: int, k: int) -> int:
    arr = sorted(arr)
    n = len(arr)

    # Precalculate next post indices for normal and super jumps
    next_normal = [bisect_right(arr, arr[i] + 2 * r) for i in range(n)]
    next_super = [bisect_right(arr, arr[i] + 4 * r) for i in range(n)]

    # dp[i][rem]: min amplifiers to cover posts i...n-1 with rem super amplifiers left
    dp = [[0] * (k + 1) for _ in range(n + 1)]

    for i in range(n - 1, -1, -1):
        for rem in range(k + 1):
            # Normal amplifier
            ans = 1 + dp[next_normal[i]][rem]

            # Super amplifier
            if rem > 0:
                ans = min(ans, 1 + dp[next_super[i]][rem - 1])

            dp[i][rem] = ans

    return dp[0][k]


# =============================================================================
# 3. Space-Optimized Approach (Rolling Array)
# Time Complexity: O(N * K + N log N)
# Space Complexity: O(N)
# =============================================================================
def find_min_amplifiers_space_optimized(arr: list, r: int, k: int) -> int:
    arr = sorted(arr)
    n = len(arr)

    next_normal = [bisect_right(arr, arr[i] + 2 * r) for i in range(n)]
    next_super = [bisect_right(arr, arr[i] + 4 * r) for i in range(n)]

    # dp[i] for rem = 0
    dp = [0] * (n + 1)
    for i in range(n - 1, -1, -1):
        dp[i] = 1 + dp[next_normal[i]]

    # Progressively compute for rem = 1...k
    for rem in range(1, k + 1):
        new_dp = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            use_normal = 1 + new_dp[next_normal[i]]
            use_super = 1 + dp[next_super[i]]
            new_dp[i] = min(use_normal, use_super)
        dp = new_dp

    return dp[0]


def main():
    lines = sys.stdin.read().split()
    if lines:
        n = int(lines[0])
        arr = [int(x) for x in lines[1:1 + n]]
        r = int(lines[1 + n])
        k = int(lines[2 + n])
        print(find_min_amplifiers_space_optimized(arr, r, k))
    else:
        # Sample test
        arr = [1, 5, 10, 15, 20]
        r, k = 2, 1
        print("Sample Test [1, 5, 10, 15, 20], r=2, k=1:")
        print("  Memoization:     ", find_min_amplifiers_memo(arr, r, k))
        print("  Tabulation:      ", find_min_amplifiers_tabulation(arr, r, k))
        print("  Space-Optimized: ", find_min_amplifiers_space_optimized(arr, r, k))


if __name__ == "__main__":
    main()

