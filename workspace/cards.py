import sys
from collections import deque
L,U = map(int,sys.stdin.readline().split())
def total(n):
    if n<=0 : return 0
    c = [0]*10
    tot = 0
    for i in range(1,len(str(n)+1)):
        t = n / (i*10)
        r = n % (i*10)
        for j in range(0, 10) : c[i] += t*i


#res=total(U) - total(L)
print(total(U))
 