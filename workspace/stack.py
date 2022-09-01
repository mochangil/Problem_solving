import sys
T = int(sys.stdin.readline())
stack = []
for i in range(T):
    op = sys.stdin.readline()
    arr = op.split()
    if arr[0] == "push":
        stack.append(arr[1])
    elif arr[0] == "pop":
        if len(stack):
            num = stack.pop()
            print(num)
        else:
            print(-1)
    elif arr[0] == "size":
        print(len(stack))
    elif arr[0] == "empty":
        print(1 if len(stack)==0 else 0)
    else:
        if len(stack)==0:
            print(-1)
        else:
            print(stack[len(stack)-1]) 
            # stack length가 0이라면 빈 stack의 -1인덱스 참조는 불가능