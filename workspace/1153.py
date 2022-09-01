def solution(n):
    num = set(range(2,n+1))

    for i in range(2, n+1):
        if i in num:
            num -= set(range(2*i, n+1, i))

    return num

#print(solution(1000000))
def ertos(n):
    arr = [True]*(n+1)
    arr[0] = False
    arr[1] = False
    for i in range(2,int(n**0.5)+1):
        if arr[i] == True:
            for j in range(i+i,n+1,i):
                arr[j] = False
    return arr


n = int(input())
arr = (ertos(n))
narr = []
stack = []
cmax = 0
csum = 0
cnt = 0
tf = False
for i in range(n+1):
    if arr[i] == True:
        narr.append(i)
        print(i)

for i in range(len(narr),-1,-1):
    csum = narr[i]
    k = i
    for j in range(3):
        if k == 0 and j == 2:
            break
        if csum == n:
            if j != 2:
                csum -= narr[k]
                j -= 1
                k -= 1
            else:
                tf = True
                break

        elif csum > n:
            csum -= narr[k]
            j -= 1
            k -= 1
        elif csum < n:
            csum += narr[k]

        


