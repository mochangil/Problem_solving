C = int(input())
H = 0; W = 0
wcount = 0
#항상 board, 격자, 좌표에서 naive하게 항상 반복해서 똑같이 움직이는 좌표가 존재한다면,
#(in C) const int 배열로 미리 선언해놓자.
loc = [[[0,0],[0,1],[1,0]],[[0,0],[1,0],[1,1]],[[0,0],[0,1],[1,1]],[[0,0],[0,1],[-1,1]]]

#내가 생각한 is_feasible로 설정한 함수에서 그냥 바로 블록을 놓아버리자.
#또한 is_feasible 함수에서 치우는 역할까지 같이 해버리자.
#typ -> 블록을 놓을 모양의 type
#delta -> 1이면 block을 set, -1이면 block을 치우는 함수.
def set(board,x,y,typ,delta):
    tf = True
    #정해진 typ의 모양으로 set할수 있도록 nx와 ny를 설정해놓는다.
    #이때, 블록을 한번에 쾅쾅쾅 set하는것이 아닌 한칸한칸씩 set한다.
    for i in range(0,3): 
        nx = x + loc[typ][i][0]
        ny = y + loc[typ][i][1]
        #하나를 set 하려고 봤는데, board의 경계를 벗어났다면 -> 즉 feasible check
        if(ny < 0 or ny >= len(board) or nx < 0 or nx >= len(board[0])):
            tf = False
        #만약 board[nx][ny]에 이미 놓여져 있었다면 -> 1이었다면
        #delta = 1 일때 (set하는 과정) > 1 일테므로 feasible check에서 False를 반환.
        elif (board[nx][ny]+delta > 1) :
            tf = False
        #delta가 1이라면, board[nx][ny]에 한칸을 set한다.
        #delta가 -1이라면, board[nx][ny]에 한칸을 치운다.
        #이 기법은 지금 현재 놓여져 있는곳에 접근을 했어도, 겹쳐서 놓고 not feasible 결론을 내고, 2번이 겹친상태로 나둔다.
        #어차피 외부에서 한번더 호출되며 -1을 해줄것이기 때문에, 원래 놓여져 있었다면 놓여져 있는 상태로 원복이고,
        #놓여져 있지 않았다면 아무것도 없는 상태로 원복해주는 기법이다.
        board[nx][ny] += delta
    return tf

def cover(board):
    y = -1;x = -1
    #board에서, 아직 흰색인 타일의 좌표를 찾는데,
    #"맨 왼쪽, 맨 위부터 찾는다"  중요
    for i in range(len(board)):
        for j in range(len(board[0])):
            if(board[i][j] == 0):
                x = i
                y = j
                break
        if x != -1 : break # ????
    if x == -1 : return 1 # 기저 사례 - 모든 칸을 채웠을 경우
    res = 0
    for typ in range(0,4):
        #만약 타일을 놓을수 있는 4가지 방법 중 typ 방법으로 set이 가능하다면, set한다
        #set 된 상태로 다음 board에 cover하러 간다.
        #만약 set이 안되면, 바로 치운다.
        if(set(board,x,y,typ,1)):
            res += cover(board)
        #set이 가능하든 가능하지 않든, 어쨋건 set한 option을 test해보았으므로 board에서 치운다.
        set(board,x,y,typ,-1)
    return res


while(C != 0):
    wcount = 0
    cnt = 0
    C -= 1
    H,W = map(int,input().split())
    board = [[1 for _ in range(21)] for _ in range(21)]
    for i in range(H):
        board[i] = list(input())
        for a in range(len(board[i])):
            if board[i][a] == ".":
                board[i][a] = 0 #white = 0
                wcount += 1
            else:
                board[i][a] = 1 #black = 1
    #print(board)
    if wcount % 3 != 0:
        print(0)
        continue
    else: print(cover(board))