import sys
input = sys.stdin.readline

route = [0]


def find(a):
    if root[a] == a:
        return a
    else:
        root[a] = find(root[a])
        return root[a]

def union(a,b):
    a = find(a)
    b = find(b)
    if a<b:
        root[b] = a
    elif a>b:
        root[a] = b
    
N = int(input())
M = int(input())

root = [i for i in range(N+1)]


for i in range(1,N+1):
    R = (list(map(int,input().split())))
    for j in range(N):
        if R[j] == 1:
            union(i,j+1)
            #실수한 부분!!!!
                

ans = "YES"
result = []
plan = list(map(int,input().split()))
for i in range(0,len(plan)-1):
    if find(plan[i]) == find(plan[i+1]):
        continue
    else:
        ans = "NO"
        break
print(ans)