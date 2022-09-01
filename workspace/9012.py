import sys
T = int(sys.stdin.readline())

def VPS(line):
    stack = []
    for i in line:
        if i == "(":
            stack.append(i)
        elif i == ")":
            if len(stack) == 0:
                return False
            else:
                stack.pop()
    if len(stack) == 0:
        return True
    else:
        return False

for _ in range(T):
    arr = sys.stdin.readline()
    print("YES" if(VPS(arr)) else "NO")

# 문자열의 끝에는 항상 "\n"이 존재한다는것
#if len(line)%2 != 0:
        #return False
    #else: