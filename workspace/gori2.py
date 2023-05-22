import sys
input = sys.stdin.readline

N,M,q = map(int,input().split())

mat = [list(map(int,input().split())) for _ in range(N)]
query = list(map(int,input().split()))
print(query)
temp = list(M)

if query[0] == 0:
    mat[query[1]][query[2]] = query[3]
else:
    temp = mat[query[1]]
    mat[query[1]] = mat[query[2]]
    mat[query[2]] = temp