#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <queue>
using namespace std;
 
#define FOR(i, n) for(int i = 0; i < n; i++);

 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N,M, sv;
bool visited1[1001] = {false,};
bool visited2[1001] = {false,};
int graphs[1001][1001] = {0,};
queue<int> qq;


void dfs(int v){
    cout << v << " ";
    visited1[v] = true;
    for(int i = 1; i<=N; i++){
        if(!visited1[i] && graphs[v][i]==1)
            dfs(i);
    }
}

void bfs(){
    while(!qq.empty()){
        int v = qq.front();
        qq.pop();
        cout << v << " ";
        visited2[v] = true;
        for(int i=1;i<=N;i++){
            if (!visited2[i] && graphs[v][i]==1){
                qq.push(i);
                visited2[i]=true;
            }
        }
    }
}

int main(){
    cin >> N >> M >> sv;
    for(int i=0;i<N;i++){
        memset(graphs[i], 0, sizeof(graphs[i]));
    }
    memset(visited1,false,sizeof(visited1));
    memset(visited2,false,sizeof(visited2));
    while(M--){
        int n,m;
        cin >> n >> m;
        graphs[n][m] = 1;
        graphs[m][n] = 1;
        // cout << graphs[n][m] << graphs[m][n] << endl;
    }
    
    // for(int i=0; i<=N;i++){
    //     vector<int>::iterator it = graphs[i].begin();
    //     for(;it!=graphs[i].end();it++){
    //         cout << *it;
    //     }
    //     cout << endl;
    // }
    dfs(sv);
    cout << endl;
    qq.push(sv);
    bfs();
    cout << endl;
    return 0;
}
