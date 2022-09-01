import sys
input = sys.stdin.readline

n,m = map(int,input().split())

root =[-1]*(n+1)

def make_set():
    for i in range(n+1):
        root[i] = i

def find(a):
    if root[a] == a:
        return a
    else:
        root[a] = find(root[a])
        return root[a]
def union(a,b):
    a = find(a)
    b = find(b)
    root[b] = a

make_set()
for _ in range(m):
    op,a,b = map(int,input().split())
    if op == 0:
        union(a,b)
    else:
        print("YES") if find(a) == find(b) else print("NO")



