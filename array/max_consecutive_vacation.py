import sys

def solve():
    tokens = iter(sys.stdin.read().split())
    
    try:
        N = int(next(tokens))
        M = int(next(tokens))
        K = int(next(tokens))
        arr = [int(next(tokens)) for _ in range(M)]
    except StopIteration:
        return

    if K >= M:
        print(N)
        return
    
    # Sort the obligations
    arr.sort()
    
    # Pad boundaries: day 0 and day N + 1 act as un-cancelable "walls"
    arr = [0] + arr + [N + 1]
    
    max_interval = 0
    
    # Slide a window of size K + 1. 
    # If we cancel K obligations between index i and i + K + 1,
    # the vacation runs strictly between arr[i] and arr[i + K + 1].
    for i in range(len(arr) - (K + 1)):
        left_boundary = arr[i]
        right_boundary = arr[i + K + 1]
        
        # Calculate the days between the two boundaries
        interval = right_boundary - left_boundary - 1
        max_interval = max(max_interval, interval)

    print(max_interval)

if __name__ == "__main__":
    solve()