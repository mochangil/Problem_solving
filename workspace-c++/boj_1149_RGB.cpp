#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

int painting[1001][3];
int dp[1000][3] = {-1};


int main(){
    int N;
    int cost[3];
    painting[0][0] = 0;
    painting[0][1] = 0;
    painting[0][2] = 0;
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> cost[0] >> cost[1] >> cost[2];
        painting[i][0] = min(painting[i-1][1],painting[i-1][2])+cost[0];
        painting[i][1] = min(painting[i-1][0],painting[i-1][2])+cost[1];
        painting[i][2] = min(painting[i-1][1],painting[i-1][0])+cost[2];
    }
    cout << min({painting[N][0],painting[N][1],painting[N][2]});

}