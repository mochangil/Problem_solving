#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i, n) for(int i = 0; i < n; i++)
#define MIN(a,b) ((a<b) ? a:b)

queue<int> hide;
int visited[200001] = {0,};
int path[200001];
int n,k;

int nextX(int x, int type){
    if (type == 0)
        return x+1;
    else if (type == 1)
        return x-1;
    else
        return x*2;
}

int_fast64_t solve(){
    int cnt = 0;
    int res = 0;
    int hasFound = 100001;
    while(!hide.empty()){
        int x = hide.front();
        hide.pop();
        cnt++;
        if (hasFound < visited[x])
            return res;
        if (x == k){
            res++;
            hasFound = visited[x];
            cout << "find!!!!!!! = " << hasFound << endl;
            continue;
            // cout << "x = " << x  <<" visited[x] = " << visited[x] << " hasFound = " << hasFound << " res = " << res <<  endl;
        }
        
        FOR(i,3){
            int nx = nextX(x,i);
            cout << x << " " << nx << endl;
        
            if((visited[nx] != 0 && nx != k) || nx < 1 || nx > 100000){
                cout << nx << endl;
                continue;
            }
            hide.push(nx);
            
            visited[nx] = visited[x]+1;
            // cout << "x = " << x << " nx = " << nx << " "<< visited[x] << " " << visited[nx] << endl;
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
    int res = 0;
    hide.push(n);
    visited[n] = 0;
    if(k == 0){
        path[k] = n-k; 
        res = 1;
    }       
    else{
        res = solve();
    }   
    cout << path[k] << "\n" << res;
}