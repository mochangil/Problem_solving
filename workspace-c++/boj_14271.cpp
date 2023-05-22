#include <iostream>
#include <math.h>
#include <vector>
#include <queue>


using namespace std;

const int MAX = 2050;
queue<int> q;
bool visited[MAX][MAX];

void bfs(vector<vector<int>> grid, int row){
    q.push(source);
    visited[source] = true;

    while(!q.empty()){
        int current = q.front();
        q.pop();

        for(int next: grid[current]){
            if(!visited[next]){
                q.push(next);
                visited[next] = true;
            }
        }
    }
}
int main(){
    int N,M,K;
    cin >> N >> M;

    vector<vector<int>> grid(2050,vector<int>(2050));

    for(int i = 1000; i<N+1000;++i){
        for(int j = 1000; j<M+1000;++j){
            char mark;
            cin >> mark;
            if (mark == 'o'){
                grid[i][j] = 1;
                visited[i][j] = true;
            }
        }
    }
    cin >> K;
    for(int i = 1000; i<N+1000;++i){
        for(int j = 1000; j<M+1000;++j){
            q.push()
    }

    
}


...OO..
..OO...
.O.....

.OOO..
.O....
.O....

.OOOOO.

.OOOO.
.O....
......


.O....
......
....O.