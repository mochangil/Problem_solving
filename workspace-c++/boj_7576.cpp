#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i, n) for(int i = 0; i < n; i++)

int N,M;
int tomato[1001][1001] = {0,};

struct tt
{
    int n;
    int m;
    int level;
};

queue<tt> farm;
int direction[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int bfs(){
    while(!farm.empty()){
        tt t = farm.front();
        tomato[t.n][t.m] = t.level;
        farm.pop();
        for(auto d : direction){
            int d1 = t.n + d[0];
            int d2 = t.m + d[1];
            int lv = t.level;
            if(tomato[d1][d2]!= 0 || d1 < 0 || d1 >= N || d2 < 0 || d2 >= M || tomato[d1][d2] == -1)
                continue;
            tt t2;
            t2.n = d1;
            t2.m = d2;
            t2.level = lv+1;
            // cout << d1 << " " << d2 << " " << lv << endl;
            tomato[d1][d2]=1;
            farm.push(t2);
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
                    tt t;
                    t.n = i;
                    t.m = j;
                    t.level = 1;
                    farm.push(t);
                }
                tomato[i][j] = temp;
            }
        }
        // FOR(i,N){
        //     FOR(j,M){
        //         cout << tomato[i][j] << " "; 
        //     }
        //     cout << endl;
        // }

        int res = bfs();
        if (res == 1)
            cout << 0 << endl;
        else
            cout << res << endl;

        return 0;
}