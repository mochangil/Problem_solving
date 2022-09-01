N,M,V = map(int,input().split())
gr = [[0] for i in range(N+1)]
visited = [0 for _ in range(N+1)]
for _ in range(M):
    n,m = map(int,input().split())
    gr[n].append(m)
    gr[m].append(n)

def dfs(k):
    visited[k] = 1
    print("visits",k)
    for i in range(1,len(gr[k])):
        there = gr[k][i]
        if(visited[there]!=1):
            dfs(there)
dfs(1)