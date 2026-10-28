from bisect import bisect_right
from functools import lru_cache

def find_min_amplifiers(arr, r, k):
    arr = tuple(sorted(arr))
    n = len(arr)

    @lru_cache(maxsize=None)
    def dp(i, remaining):
        if i >= n:
            return 0

        # Normal amplifier
        j = bisect_right(arr, arr[i] + 2 * r)
        way1 = 1 + dp(j, remaining)

        # Super amplifier
        way2 = float("inf")
        if remaining > 0:
            j = bisect_right(arr, arr[i] + 4 * r)
            way2 = 1 + dp(j, remaining - 1)

        return min(way1, way2)

    return dp(0, k)


if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))
    r, k = map(int, input().split())

    print(find_min_amplifiers(arr, r, k))