#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,n) for(int i=0; i<n; i++)
#define MAX(a,b) ((a>b) ? a:b)

int n,m,drawNum = 0,cnt = 0;
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int drawing[501][501] = {0,};
int res = 0;


void dfs(int r, int c){
    res++;
    drawing[r][c] = 0;
    FOR(i,4){
        int nextX = r+dir[i][0];
        int nextY = c+dir[i][1];
        if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m)
        {
            continue;
        }
        else if(drawing[nextX][nextY] == 1)
            dfs(nextX,nextY);
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

    cin >> n >> m;
    int maxcnt = 0;
    FOR(i,n){
        FOR(j,m){
            int temp = 0;
            cin >> temp;
            drawing[i][j] = temp;
            
        }
    }
    FOR(i,n){
        FOR(j,m){
            if(drawing[i][j] == 1){
                res = 0;
                cnt++;
                dfs(i,j);
                maxcnt = MAX(res,maxcnt);
            }
        }
    }
    cout << cnt << "\n" << maxcnt;
    return 0;
}