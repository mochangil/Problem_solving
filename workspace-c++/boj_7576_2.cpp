#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i, n) for(int i = 0; i < n; i++)
#define INF 1234567890
#define MAX 1234567891
#define MOD 1234567891

int N,M;
int tomato[1001][1001] = {0,};
int days[1001][1001] = {0,};

queue<pair<int, int>> farm;
int direction[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int bfs(){
    while(!farm.empty()){
        tomato[farm.front().first][farm.front().second] = 1;
        farm.pop();
        for(auto d : direction){
            int d1 = farm.front().first + d[0];
            int d2 = farm.front().second + d[1];
            if(tomato[d1][d2]!= 0 || d1 < 0 || d1 >= N || d2 < 0 || d2 >= M || tomato[d1][d2] == -1)
                continue;
            days[d1][d2] = tomato[farm.front().first][farm.front().second]+1;
            farm.push(make_pair(d1,d2));
        }
    }
    int biggest = 1;
    FOR(i,N){
        FOR(j,M){
            int temp = tomato[i][j];
            if(temp == 0){
                return -1;
            }
            if(temp > biggest)
                biggest = temp;
        }
    }
    return biggest-1;

}


signed main(int argc, char** argv) {
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        cin >> M >> N;

        FOR(i,N){
            FOR(j,M){
                int temp;
                cin >> temp;
                if(temp == 1){
                    farm.push(make_pair(i,j));
                    days[i][j] = 0;
                }
                tomato[i][j] = temp;
            }
        }

        int res = bfs();
        if (res == 1)
            cout << 0 << endl;
        else
            cout << res << endl;

        return 0;
}