import sys
T = int(input())
res = []
for _ in range(T):
    arr = sys.stdin.readline().split()
    for word in arr:
        res = "".join(word[::-1])
        print(res)