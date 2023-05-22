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

int N,M,cnt=0;
int graphs[101][101];
bool visited[101];
queue<int> q;
set<int> s;

void dfs(int v){
    if(!visited[v]){
        visited[v]=true;
        for(int i=1;i<N;i++){
            
        }
    }
}

void bfs(int start){
    q.push(start);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        visited[v] = true;
        cnt++;
        // cout << v << " ";
        s.insert(v);
        for(int i=1;i<N;i++){
            if(!visited[i] && graphs[v][i] == 1)
                q.push(i);
        }
    }
}

int main(){
    cin >> N >> M;
    int i = 0;
    FOR(i,N){
        memset(graphs[i],0,sizeof(graphs[i]));
    }
    memset(visited,false,sizeof(visited));

    while(M--){
        int n,m;
        cin >> n >> m;
        graphs[n][m] = 1;
        graphs[m][n] = 1;
    }

    bfs(1);
    cout << s.size()-1;



    return 0;
}