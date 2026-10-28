
def count_pairs(arr,D,M):

    lookup = {}

    count = 0
    for x in arr:

        req1 = (D-(x%D))%D

        if req1 in lookup:
            
            for y in lookup[req1]:

                if y%M == x%M:
                    count += 1
        
        if lookup.get(x%D) is None:
            lookup[x%D] = []

        lookup[x%D].append(x)

    return count
        


if __name__ == "__main__":

    N,D,M = map(int,input().split())
    arr = list(map(int,input().split()))


    print(count_pairs(arr,D,M))
    