from collections import deque
import sys

input = sys.stdin.readline
deq = deque()
for _ in range(int(input())):
    a = input().split()
    if a[0]== "push":
        deq.append(a[1])
    elif a[0] == "front":
        print(deq[0] if len(deq)!=0 else "-1")
    elif a[0] == "back":
        print(deq[-1] if len(deq)!=0 else "-1")
    elif a[0] == "size":
        print(len(deq))
    elif a[0] == "empty":
        if len(deq)==0: print(1)
        else : print(0)
    elif a[0] == "pop":
        print(deq.popleft() if len(deq)!=0 else "-1")