import sys
input = sys.stdin.readline

global Madmax
Madmax = 0

n,m = map(int,input().split())

list1 = [list(map(int,input().split())) for _ in range(n)]
checked = [[0 for _ in range(m)] for _ in range(n)]
print(list1)
print(checked)

def find_max(lst):
    maxi = -1
    pi = 0; pj = 0
    for i in range(len(lst)):
        for j in range(len(lst[i])):
            if lst[i][j]>maxi and checked[i][j]!=1:
                maxi = lst[i][j]
                pi = i
                pj = j
    
    return maxi,pi,pj

def tetromino(sm,pi,pj,cnt):
    if pi > n or pi < 0 or pj > m or pj < 0:
        return
    cnt += 1
    if cnt >= 4:
        return sm
    else:
        sm1 += tetromino(sm,pi+1,pj,cnt)
        sm2 += tetromino(sm,pi-1,pj,cnt)
        sm3 += tetromino(sm,pi,pj+1,cnt)
        sm4 += tetromino(sm,pi,pj-1,cnt)
        sm = max(sm1,sm2,sm3,sm4)
    if sm > Madmax:
        Madmax = sm




for i in range(0,n*m+1):
        maxi,pi,pj = find_max(list1)
        print(maxi)
        print(pi,pj)

tetromino(list1)