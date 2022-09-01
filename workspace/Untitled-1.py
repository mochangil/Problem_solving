import math, sys

n,m = map(int,sys.stdin.readline().split())
if m >= 10000000 : m = 10000000

arr = []

for i in range(n,m+1):
    #if arr[i] == 1:
    num = str(i)
    if i == 11:
        arr.append(i)
        continue
    if len(num)%2 == 0:
        continue
    if num == num[::-1]:
        arr.append(i)


for i in arr:
    tf = True
    for j in range(2,int(math.sqrt(i)+1)):
        if i%j == 0:
            tf = False
            break
    if tf:
        print(i)
    
print("-1")