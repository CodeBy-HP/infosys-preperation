import sys

def solve(mat):
    n = len(mat)
    m = len(mat[0])

    dir = [[1, 0], [-1, 0], [0, 1], [0, -1]]
    dash_dir = [[2, 0], [-2, 0], [0, 2], [0, -2]]

    def isValid(i, j):
        return 0 <= i < n and 0 <= j < m

    dp = [[[-1] * 2 for _ in range(m)] for _ in range(n)]

    def dfs(i, j, dashUsed):
        if dp[i][j][dashUsed] != -1:
            return dp[i][j][dashUsed]

        max_ans = 1  

        for d in dir:
            new_i = i + d[0]
            new_j = j + d[1]

            if not isValid(new_i, new_j):
                continue
            
            if mat[new_i][new_j] <= mat[i][j]:
                continue

            max_ans = max(max_ans, 1 + dfs(new_i, new_j, dashUsed))

        if not dashUsed:
            for d in dash_dir:
                new_i = i + d[0]
                new_j = j + d[1]

                if not isValid(new_i, new_j):
                    continue

                if mat[new_i][new_j] <= mat[i][j]:
                    continue

                max_ans = max(max_ans, 1 + dfs(new_i, new_j, 1))

        dp[i][j][dashUsed] = max_ans
        return dp[i][j][dashUsed]

    max_path = 0
    for i in range(n):
        for j in range(m):
            max_path = max(max_path, dfs(i, j, 0))

    return max_path


if __name__ == "__main__":
    input = sys.stdin.read
    data = input().split()
    
    if not data:
        sys.exit(0)
        
    n = int(data[0])
    m = int(data[1])
    
    mat = []
    idx = 2
    for i in range(n):
        row = []
        for j in range(m):
            row.append(int(data[idx]))
            idx += 1
        mat.append(row)

    print(solve(mat))