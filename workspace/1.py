import math

n,m = map(int,input().split())
arr = [1] * (m+1)
arr[0] = 0
arr[1] = 0

for i in range(2,int(math.sqrt(m)+1)):
    if arr[i] == 1:
        j=2
        while(i*j) <= m:
            arr[i*j] = 0
            j += 1

for i in range(n,m+1):
    if arr[i] == 1:
        num = str(i)
        if num == num[::-1]:
            print(num)

print("-1")
