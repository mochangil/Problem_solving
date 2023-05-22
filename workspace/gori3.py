import sys
input = sys.stdin.readline

N = int(input())
dominos = [list(map(int,input().split())) for _ in range(N)]


count = 1

dominos.sort(key=lambda x:x[0])

for i in range(N-1):
    if(dominos[i][0] + dominos[i][1] < dominos[i+1][0]):
        count += 1

print(count)
