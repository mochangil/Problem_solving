import sys, time
input = sys.stdin.readline

start_time = int(round(time.time() * 1000)) 
stack1 = list(input().strip())
stack2 = []
arr = [list(input().split()) for _ in range(int(input()))]
for w in arr:
    if w[0] == "L":
        if len(stack1) : stack2.append(stack1.pop())
        else: continue
    elif w[0] == "D":
        if len(stack2) : stack1.append(stack2.pop())
        else: continue
    elif w[0] == "B":
        if len(stack1) : stack1.pop()
        else: continue
    elif w[0] == "P":
        stack1.append(w[1])

stack2.reverse()

print("".join(stack1 + stack2)) 
end_time = int(round(time.time() * 1000)) 
print('%d(ms)' % (end_time - start_time))