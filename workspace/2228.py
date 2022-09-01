stack1 = []
stack2 = []

line = input()
arr = [i for i in line]
tok = ['a']
cno = 0
first = 0
for i in arr:
    if i == '(':
        stack1.append(i)
        tok.pop()
        tok.append(i)
    elif  i == ")":
        if len(stack1) == 0:
            print(0)
            break
        else:
            stack1.pop()
            if tok[0] == '(':
                cno += 2
            else:
                cno *= 2
            
    elif i == "[":
        stack2.append(i)
        tok.pop()
        tok.append(i)
    else:
        if len(stack2) == 0:
            print(0)
            break
        else:
            stack2.pop()
            if tok[0] == "[":
                cno = +3
            else:
                cno *= 3
print(cno)
