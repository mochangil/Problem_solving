#python의 자체 자료구조 heap(minheap)을 이용하여
#max heap을 구현. input값에 -1을 곱해줌.
#sys.stdin.readline()을 사용하여 입력에 가속을 해줌.
import sys, heapq  
heap = []  

for i in range(int(sys.stdin.readline())):  
    N = int(sys.stdin.readline()) * -1
    if N == 0:  
        if len(heap) == 0:  
            print(0)  
        else:  
            print(heapq.heappop(heap) * -1)  
    else:  
        heapq.heappush(heap, N)