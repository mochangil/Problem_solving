import numpy as np;


def counting():
    numCount = [0] * 20
    for _ in range(7):
        temp = list(input().split())
        for i in temp:
            numCount[int(i)] += 1
    for i in range(len(numCount)):
        print(str(i) +" = " + str(numCount[i]))

    print(sum(numCount))

def aa():
    numCount = [[0]*10]*7
    rcounter=0
    counter=0
    for _ in range(1):
        temp = list(input().split())
        for i in temp:
            numCount[rcounter][counter] = int(i)
            counter += 1
        counter = 0
        rcounter += 1
    
    print(np.mean(numCount))
    print(np.sqrt(np.var(numCount)))


aa()