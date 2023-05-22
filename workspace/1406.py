import sys, time
input = sys.stdin.readline
k = list()
d = list()
a = list()

for _ in range(n = int(input())):
    
    m = int(input())
    for _ in range(m):
        x1,x2,x3 = map(int,input().split())
        k.append(x1);
        d.append(x2);
        a.append(x3);

    y1,y2,y3 = map(int,input().split())

    for i in range(m):
        res += k[i]*y1 - d[i]*y2 + a[i]*y3
        if res<0:
            res = 0
    
    print(res)
    k.clear()
    d.clear()
    a.clear()

