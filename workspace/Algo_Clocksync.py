import sys
input = sys.stdin.readline

INF = 9999
SWITCHES = 10

switch = [
    [0, 1, 2],
    [3, 7, 9, 11],
    [4, 10, 14, 15],
    [0, 4, 5, 6, 7],
    [6, 7, 8, 10, 12],
    [0, 2, 14, 15],
    [3, 14, 15],
    [4, 5, 7, 14, 15],
    [1, 2, 3, 4, 5],
    [3, 4, 5, 9, 13]
]


def push_switch(clocks,cnt):
    for e in switch[cnt]:
        clocks[e] += 3
        if clocks[e] == 15:
            clocks[e] = 3

def areAligned(clocks):
    if all(clocks) == 12:
        return True
    else:
        return False

def clocksync(clocks,cnt):
    if cnt == SWITCHES:
        if areAligned(clocks):
            return 0 
        else : 
            return INF

    res = INF
    for i in range(0,4):
        cand = i+clocksync(clocks,cnt+1)
        res = min(res,cand)
        push_switch(clocks,cnt)

    return res

    
if __name__ == "__main__":
    C = int(input())
    while(C != 0):
        C-=1
        clocks = list(map(int,input().split()))
        res = clocksync(clocks,0)

        if res == INF:
            print(-1)
        else:
            print(res)


