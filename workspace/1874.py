import sys, math

T = int(sys.stdin.readline())
stack = [0]
lst = []
top = 0
tf = True
n = 1
res = []
j = 0

for i in range(T):
    lst.append(int(sys.stdin.readline()))

while(j<T):
    if stack[top] == lst[j]:
        stack.pop()
        res.append("-")
        top -= 1
        j+=1
    elif stack[top] < lst[j]:
        while(n <= lst[j]):
            stack.append(n)
            res.append("+")
            n+=1
            top+=1
        continue
    else:
        tf = False
        break

if tf == False : print("NO")
else : 
    for l in res:
        print(l)





