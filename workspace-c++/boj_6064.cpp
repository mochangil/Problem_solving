#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

#define MAX(a,b) (a>b ? a:b)
#define MIN(a,b) (a<b ? a:b)
#define FOR(i,n) for(int i = 0; i<n; i++)

int N,M,x,y;
int lastYear;
int solve(){
    int a,b;
    for(int i = x; i<=lastYear;i+=N){
        
        a = i%N;
        b = i%M;
        if(a == 0)
            a = N;
        if(b == 0)
            b = M;
        // cout << "a = " << a << "b = " << b << endl;
        if(a == x && b == y)
            return i;
    }
    return 0;
}
int gcd(int x, int y){
    while(y != 0){
        int tmp = y;
        y = x%y;
        x = tmp;
    }
    return x;
}

int lcm(int x, int y){
    // cout << "lcm = " << x * (y/gcd(x,y)) << endl;
    return x * (y/gcd(x,y));
}


int main(){
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        int res = 0;
        cin >> N >> M >> x >> y;
        // cout << MAX(N,M) << MIN(N,M) << endl;
        lastYear = lcm(MAX(N,M),MIN(N,M));
        res = solve();
        if(res)
            cout << res << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
