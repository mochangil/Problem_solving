import sys
from collections import deque
N,K = map(int,input().split())

deq = [i for i in range(1,N+1)]
k = K-1
cnt = 0
while(len(deq)!=0):
    if k>N : k%=N
    N -= 1
    print(deq.pop(k))
    k += K-1


# 1 2 3 4 5 6 7 8
# 1 2 3 0 5 6 7 8
# 1 2 3   5 6 7 0
# 1 2 3   0 6 7  
# 1 0 3     6 7
# 0   3     6 7
#     0     6 7
#           6 0
