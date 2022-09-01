C = int(input())
board = []
word = []
xdir = [1,1,0,-1,-1,-1,0,1]
ydir = [0,-1,-1,-1,0,1,1,1]
def inRange(x,y,l):
    if x<0 or x>=5 or y<0 or y>=5 or l >= len(word):
        return False
    else:
        return True

def hasWord(x,y,l):
    if (inRange(x,y,l) == False):
        return False
    if (board[x][y] != word[l]):
        return False
    elif (len(word) == 1 or l == len(word)-1):
        return True
    for i in range(8):
        nextx = x+xdir[i]
        nexty = y+ydir[i]
        if(hasWord(nextx,nexty,l+1)):
            return True
    return False


while(C != 0):
    C -= 1
    board = [list(input()) for _ in range(5)]
    print(board)
    N = int(input())
    for _ in range(N):
        word = list(input())
        print(word)
        TF = False
        for j in range(0,5):
            for k in range(0,5):
                if(hasWord(j,k,0) == True):
                    TF = True
                    break
                else:
                    continue
            if TF == True:
                print("YES")
                break
            else: continue
        if TF == False:
            print("NO")
    