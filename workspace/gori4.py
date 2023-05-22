import sys,math
input = sys.stdin.readline

def inTyphoon(cx,cy,x,y,r,vertical):
    reach = math.sqrt((cx-x)**2 + (cy-y)**2)
    if reach>r:
        return 4
    elif vertical == False:
        if cy == y:
            return 3
        elif cy>y:
            return 2
        else:
            return 1
    else:
        if cx == x:
            return 3
        elif cx<x:
            return 2
        else:
            return 1

N,K,R,Q = map(int,input().split())

typhoon = [list(map(int,input().split())) for _ in range(K)]
humans = [list(map(int,input().split())) for _ in range(Q)]

typhoon.sort(key=lambda x:x[0])
humans.sort(key=lambda x:x[0])

for i in range(K-1):
    verticalMove = True
    currentDay = typhoon[i]
    nextDay = typhoon[i+1]
    days = currentDay[0] - nextDay[0]

    

    if currentDay[1] == nextDay[1]:
        verticalMove = True
    else:
        verticalMove = False

    for j in range(currentDay[0],nextDay[0]):
        flows = j-currentDay[0]
        # print("\n")

        for k in range(Q):
            if(humans[k][0] == j):
                if verticalMove == False:
                    type = inTyphoon(currentDay[1]+flows,currentDay[2],humans[k][1],humans[k][2],R,False)
                else:
                    # print(currentDay[0],nextDay[0],flows,k)
                    type = inTyphoon(currentDay[1],currentDay[2]+flows,humans[k][1],humans[k][2],R,True)
                    
                if (type == 4) or (type ==3):
                    print("gori")
                elif type == 2:
                    print("unsafe")
                else:
                    print("safe")
        

