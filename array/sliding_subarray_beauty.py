def solve():
    
    arr = list(map(int,input().split()))
    k,x = map(int,input().split())
    n = len(arr)

    ans = []

    freq = [[0] * 101]

    for i in range(k):
        freq[arr[i]+50] += 1

    def getBeauty():
        
        count = 0
        for i in range(50):
            count += freq[i]

            if count >= x:
                return i-50
        return 0

    ans.append(getBeauty())

    for i in range(k,n):

        freq[arr[i-k]+50] -= 1
        freq[arr[i]+50] += 1

        ans.append(getBeauty())



if __name__ == "__main__":
    solve()