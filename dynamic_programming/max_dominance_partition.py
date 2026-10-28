from functools import lru_cache

def solve():
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))

    # pre compute the cost

    cost = [[0] * n for _ in range(n)]

    for i in range(n):
        freq = {}
        max_freq = 0
        for j in range(i,n):
            x = arr[j]
            freq[x] = freq.get(x,0) + 1
            max_freq = max(max_freq,freq[x])
            cost[i][j] = max_freq

    @lru_cache(maxsize=None)
    def dp(start, groups):
        if groups == 0:
            return 0

        max_score = float("-inf")

        for end in range(start, n - groups + 1):
            score = cost[start][end] + dp(end + 1, groups - 1)
            max_score = max(max_score, score)

        return max_score

    print(dp(0, k))


if __name__ == "__main__":
    solve()