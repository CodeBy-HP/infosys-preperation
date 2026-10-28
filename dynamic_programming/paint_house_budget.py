import sys
from functools import lru_cache

sys.setrecursionlimit(200000)

def solve():
    tokens = iter(sys.stdin.read().split())

    N = int(next(tokens))
    C = int(next(tokens))
    B = int(next(tokens))

    cost = [[int(next(tokens)) for _ in range(C)] for _ in range(N)]

    @lru_cache(maxsize=None)
    def helper(idx: int, prev_color: int) -> int:
        if idx < 0:
            return 0

        min_cost = float("inf")

        for color in range(C):
            if color != prev_color:
                curr_cost = cost[idx][color]
                res = helper(idx - 1, color)

                if res != float("inf"):
                    min_cost = min(min_cost, res + curr_cost)

        return min_cost

    ans = helper(N - 1, -1)
    
    if ans <= B:
        print(ans)
    else:
        print(-1)


if __name__ == '__main__':
    solve()