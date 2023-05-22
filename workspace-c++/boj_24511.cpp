#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;
 
#define FOR(i, n) for(int i = 0; i < n; i++)
#define INF 1234567890
#define MAX 1234567891
#define MOD 1234567891
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())

vector<int> queuestack,values;
queue<int> vqueue;
int n,m;


signed main(int argc, char** argv) {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        cin >> n;
        FOR(i,n){
            int types;
            cin >> types;
            queuestack.push_back(types);
        }
        FOR(i,n){
            int num;
            cin >> num;
            values.push_back(num);
        }
        for(int i = n-1; i>=0;i--){
            if (queuestack[i] == 0)
                vqueue.push(values[i]);
        }

        cin >> m;
        
        if (vqueue.size() == 0)
            FOR(i,m){
                int nums;
                cin >> nums;    
                cout << nums << " ";
            }
        else
            FOR(i,m){
                int nums;
                cin >> nums;
                cout << vqueue.front() << " ";
                vqueue.pop();
                vqueue.push(nums);
            }
        
        // deque, 역순
}