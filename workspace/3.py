from collections import Counter
from itertools import combinations, permutations
N,M,K = map(int,input().split())
#N개의 "a", M개의 "z"로 이루어진 사전


arr = ["a"]*N + ["z"]*M
    
narr = list(set(list(permutations(arr,N+M))))
narr = narr.sort()

print(narr)

if(K>len(narr)):
    print("-1")
else:
    print(narr[K-1])
