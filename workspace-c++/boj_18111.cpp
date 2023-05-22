#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;

int N,M,B;
int land[500][500] = {0,};
int landdiff[500][500] = {0,};
int maxHeight = 0;
int minHeight = 0;
int maxTime = 99999999;

int minecraft(int h){
    int temp = 0;
    int blocks = B;
    int highCnt = 0;
    int lowCnt = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            temp = land[i][j] - h;
            if (temp > 0){
                blocks += temp;
                highCnt += temp;
            }
            else if(temp < 0){
                blocks += temp;
                lowCnt += temp;
            }
        }
    }
    if (blocks < 0){
        // cout << "blocks run out!" << endl;
        return maxTime;
    }
    return highCnt*2+lowCnt*-1;
}

int main(){
    cin >> N >> M >> B;
    int height, minTime=maxTime;
    int currentHeight = 0;
    for(int i = 0; i<N;i++){
        for(int j = 0; j<M;j++){
            cin >> height;
            land[i][j] = height;
            if (maxHeight < height) maxHeight = height;
        }
    }
    for(int i = maxHeight;i>=minHeight;i--){
        int temp = 0;
        temp = minecraft(i);
        // cout << minTime << " " <<temp << endl; 
        if (minTime > temp){
            minTime = temp;
            currentHeight = i;
        }
        // cout << "maxHeight = " << maxHeight << " minHeight = "  << minHeight << endl;
        // cout << "currentHeight = " << i << " minTime = " << minTime << endl;
    }

    cout << minTime << " " << currentHeight << endl;
    return 0;
}


//시나리오
/*
1. maxHeight부터 차례대로 내려온다
1-1. 이때 소유한 블록 갯수가 없다면, 다음 층으로 내려간다.


*/