
def find_min_cost(N,A,B):

    if N == 0:
        return 0
    

    prev2 = 0
    prev1 = 1

    min_cost = float("inf")
    while True:

        curr  = prev1 + prev2

        if(curr > N):
            break

        cost = A + (B * (curr))
        find_cost = find_min_cost(N-curr,A,B)

        min_cost = min(min_cost,cost+find_cost)

        prev2 = prev1
        prev1 = curr
    
    return min_cost
        

def trick(N,A,B):

    if N == 0:
        return 0
    
    total = 0

    prev1 = 1
    prev2 = 0

    curr = 0

    while curr < N:
        curr = prev1 + prev2

        prev2 = prev1
        prev1 = curr
        
    total = A + (B * prev2)

    total += trick(N-prev2,A,B)


    return total
        

if __name__ == "__main__":
    
    
    N,A,B = map(int,input().split())

    print(trick(N-1,A,B))
    
