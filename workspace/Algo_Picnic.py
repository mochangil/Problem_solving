C = int(input())
pair = [[0 for _ in range(10)] for _ in range(10)]
cnt = 0
N = 0; M = 0

def findPair(check): 
    firstFree = -1       #수를 세는 방법에는 두가지가 있다.    
    for i in range(0,N):
        if check[i] == 0:       #짝이 없는 친구가 있다면
            firstFree = i
            break
    if firstFree == -1:      #짝이 없는 친구가 없다면 -> solution
        return 1
    res = 0
    for pairw in range(firstFree+1,N):
        if check[pairw] == 0 and pair[firstFree][pairw] == 1:
            check[firstFree] = 1;check[pairw] = 1
            res += findPair(check)
            check[firstFree] = 0;check[pairw] = 0
    return res

while(C != 0):
    C -= 1
    N,M = map(int,input().split())
    check = [0]*(N)
    tmp = list(map(int,input().split()))
    for i in range(0,2*M,2):
        pair[tmp[i]][tmp[i+1]] = 1 # 내가 틀린 부분
        pair[tmp[i+1]][tmp[i]] = 1
    print(findPair(check))
    #print(check)
    tmp.clear()
    for i in range(0,N):            # 초기화 해줄때 너무 간단하게 clear 해주면 당연히 안되지.. 이걸 놓치네 ㅠ
        for j in range(0,N):
            pair[i][j] = 0
    check.clear()