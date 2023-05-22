#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,n) for(int i=0;i<n;++i)

int T,N,M,K;
int farm[50][50] = {0,};
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int cnt = 0;
int dp[50][50] = {0,};

void solve(int r, int c){
    int res = 0;
    farm[r][c] = 0;
    FOR(i,4){
        int nextX = r+dir[i][0];
        int nextY = c+dir[i][1];
        if(nextX < 0 || nextX >= N || nextY < 0 || nextY >= M)
            continue;
        else if(farm[r+dir[i][0]][c+dir[i][1]] == 1)
            solve(r+dir[i][0],c+dir[i][1]);
    }
}

int main(){
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

    cin >> T;
    while(T--){
        cin >> N >> M >> K;
        FOR(i,K){
            int r,c;
            cin >> r >> c;
            farm[r][c] = 1;
        }
        FOR(i,N){
            FOR(j,M){
                if(farm[i][j] == 1){
                    // cout << i << j << endl;
                    solve(i,j);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;

        cnt = 0;
        FOR(i,50){
            memset(farm[i],0,sizeof(int)*50);
        }
    }
}