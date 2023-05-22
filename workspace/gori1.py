import sys, time
input = sys.stdin.readline

K = list()
D = list()
A = list()

n = int(input())
for _ in range(n):
    res = 0
    m = int(input())
    for i in range(m):
        x1,x2,x3 = map(int,input().split())
        K.append(x1)
        D.append(x2)
        A.append(x3)

    y1,y2,y3 = map(int,input().split())

    for j in range(m):
        temp = K[j]*y1 - D[j]*y2 + A[j]*y3
        if temp < 0:
            temp = 0
        res += temp

    print(res)
    K.clear()
    D.clear()
    A.clear()
    
    