#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i, n) for(int i = 0; i < n; i++)
#define MIN(a,b) ((a<b) ? a:b)

queue<int> hide;
bool visited[100001] = {0,};
int path[100001];
int n,k;

int nextX(int x, int type){
    if (type == 0)
        return x+1;
    else if (type == 1)
        return x-1;
    else
        return x*2;
}

void solve(){
    while(!hide.empty()){
        int x = hide.front();
        if (x == k)
            return;
        hide.pop();
        FOR(i,3){
            int nx = nextX(x,i);
            if(visited[nx] != 0 || nx < 1 || nx > 100000){
                cout << "nx = " << nx << endl;
                continue;
            }
            hide.push(nx);
            visited[nx] = true;
            path[nx] = path[x]+1;
        }
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

    cin >> n >> k;
    path[n] = 0;
    hide.push(n);
    visited[n] = true;
    if(k == 0)
        path[k] = n-k;        
    else
    solve();

    cout << path[k];
}