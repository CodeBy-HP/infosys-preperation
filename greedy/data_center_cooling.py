import sys
import heapq

def main():
    # Read all inputs from standard input at once for faster execution
    input_data = sys.stdin.read().split()
    if not input_data:
        return
        
    iterator = iter(input_data)
    
    n = int(next(iterator))
    d = int(next(iterator))
    
    arr = [int(next(iterator)) for _ in range(n)]
    
    q = int(next(iterator))
    
    total = 0
    
    for _ in range(q):
        type_op = int(next(iterator))
        
        if type_op == 1:
            # Update operation
            pos = int(next(iterator))
            value = int(next(iterator))
            arr[pos] = value
            
        else:
            # Query operation
            l = int(next(iterator))
            r = int(next(iterator))
            critical = int(next(iterator))
            
            mark = [False] * n
            
            # Python's heapq is a min-heap.
            # To simulate the C++ max-heap ordered by largest value, then smallest index:
            # We negate the value. heapq will pop the most negative number first (largest value).
            # If values tie, it evaluates the second tuple item (index) and pops the smallest index.
            pq = [(-arr[i], i) for i in range(l, r + 1)]
            heapq.heapify(pq) # O(N) creation, faster than pushing elements one by one
            
            res = 0
            while pq:
                neg_value, index = heapq.heappop(pq)
                value = -neg_value
                
                if mark[index]:
                    continue
                    
                # Critical check
                if value >= critical:
                    res += value * 4
                else:
                    res += value
                    
                # Mark invalid indices within the range [index - d + 1, index + d - 1]
                start_idx = max(0, index - d + 1)
                end_idx = min(n - 1, index + d - 1)
                
                for i in range(start_idx, end_idx + 1):
                    mark[i] = True
                    
            total += res
            
    print(total)

if __name__ == '__main__':
    main()