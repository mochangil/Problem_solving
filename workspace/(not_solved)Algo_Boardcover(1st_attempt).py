C = int(input())
H = 0; W = 0
wcount = 0
loc = [[[0,0],[0,1],[1,0]],[[0,0],[1,0],[1,1]],[[0,0],[0,1],[1,1]],[[0,0],[0,1],[-1,1]]]

def is_feasible(a,board):
    for k in a:
        if board[k[0]][k[1]] == 1:
            return False
    return True


def cover(x,y,board, cnt):
    res = 0
    if board[x][y] == 1:
        return 0
    if cnt == wcount:
        return 1
    for a in loc:
        if is_feasible(a):
            for k in a:
                board[k[0]][k[1]] = 1
            for i in range(x,H):
                for j in range(y,W):
                    cnt += 1
                    res += cover(i,j,board,cnt)
            board[k[0]][k[1]] = 0

    return res