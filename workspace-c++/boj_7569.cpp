#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i, n) for(int i = 0; i < n; i++)

int M,N,H;
int tomato[101][101][101] = {0,};
int direction[6][3] = {{1,0,0},{0,1,0},{0,0,1},{-1,0,0},{0,-1,0},{0,0,-1}};

struct tt
{
    int n;
    int m;
    int h;
    int level;
};

queue<tt> farm;

int bfs(){
    while(!farm.empty()){
        tt t = farm.front();
        tomato[t.h][t.n][t.m] = t.level;
        farm.pop();
        for(auto d : direction){ //{1,0,0}, {0,-1,0}
            int d1 = t.h + d[0];
            int d2 = t.n + d[1];
            int d3 = t.m + d[2];
            int lv = t.level;
            if(tomato[d1][d2][d3] != 0 || d1 < 0 || d1 >= H || d2 < 0 || d2 >= N || d3 < 0 || d3 >= M)
                continue;
            tt t3;
            t3.h = d1;
            t3.n = d2;
            t3.m = d3;
            t3.level = lv+1;
            // cout << d1 << " " << d2 << " " << d3 << " " << lv << endl;
            tomato[d1][d2][d3]=1;
            farm.push(t3);
        }
    }
    int biggest = 1;
    FOR(i,M){
        FOR(j,N){
            FOR(h,H){
                int temp = tomato[i][j][h];
                if(temp == 0){
                    return -1;
                }
                if(temp > biggest)
                    biggest = temp;
            }
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

        cin >> M >> N >> H;

        FOR(h,H){
            FOR(n,N){
                FOR(m,M){
                    int temp;
                    cin >> temp;
                    if (temp == 1){
                        tt t;
                        t.m = m;
                        t.n = n;
                        t.h = h;
                        t.level = 1;
                    }
                    tomato[h][n][m] = temp;
                }
            }
        }
        // FOR(i,H){
        //     FOR(j,N){
        //         FOR(h,M){
        //             cout << tomato[i][j][h] << " ";
        //         }
        //         cout << endl;
        //     }
        // }

        int res = bfs();
        if (res == 1)
            cout << 0 << endl;
        else
            cout << res << endl;

        return 0;
}