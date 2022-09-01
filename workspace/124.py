from cmath import sqrt
import sys
input = sys.stdin.readline

re1=[]
re2=[]
Region = []

def findcluster(Reglist,x1,y1,x2,y2):
    for i in Reglist:
        d1 = (i[0]-x1)*(i[0]-x1) + (i[1]-y1)*(i[1]-y1)
        d2 = (i[0]-x2)*(i[0]-x2) + (i[1]-y2)*(i[1]-y2)
        if min(d1,d2) == d1:
            re1.append(i)
        else:
            re2.append(i)

def findavgpoint(lst):
    cnt = 0
    x = 0
    y = 0
    for i in lst:
        x += i[0]
        y += i[1]
        cnt+=1
    return int(x/cnt),int(y/cnt)

for C in range(int(input())):
    Region.append(list(map(int,input().split())))

x1pt = 1; x2pt = 2
y1pt = 1; y2pt = 1
for _ in range(6):
    re1.clear(); re2.clear();
    findcluster(Region,x1pt,y1pt,x2pt,y2pt)
    x1pt,y1pt = findavgpoint(re1)
    x2pt,y2pt = findavgpoint(re2)
    
    for i in range(0,10):
        for j in range(0,10):
            if [i,j] in re1:
                print("1 ",end="")
            elif [i,j] in re2:
                print("2 ",end="")
            else:
                print("* ",end="")
        print()
    print("-----------------\n\n")









