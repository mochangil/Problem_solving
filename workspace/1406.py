import sys, time
input = sys.stdin.readline

start_time = int(round(time.time() * 1000)) 
line = list(input())
arr = [list(input().split()) for _ in range(int(input()))]
line.pop()
cursor = len(line)
#print(cursor)
#print(line)

#시간을 줄일수 있는 부분?
#1. w[0]을 비교하는 부분, 명령어를 확인하는 부분은 필수적이다.
#2. pop, insert 연산의 시간은 필요 이상으로 걸려, 슬라이싱 기법을 사용하였다.
#3. 아무리 봐도 slicing하는 부분이다.
#4. 리스트를 슬라이싱하여 반, 반을 자르고 붙이고 하는것보다
#   커서부분을 기준으로 왼쪽 배열, 오른쪽 배열로 나누어 계산한다.
for w in arr:
    if w[0] == "P":
        print(line[0:cursor-1])
        line = line[0:cursor]+list(w[1])+line[cursor:]
        if cursor == len(line): continue
        else: cursor += 1
    elif w[0] == "L":
        if cursor == 0: continue
        else : cursor -= 1
    elif w[0] == "B":
        if cursor == 0: continue
        else : 
            line = line[0:cursor-1] + line[cursor:]
            cursor -= 1
    else:
        if cursor == len(line): continue
        else : cursor += 1


print("".join(line))

end_time = int(round(time.time() * 1000)) 
print('%d(ms)' % (end_time - start_time))