#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i, n) for(int i = 0; i < n; i++)
#define INF 1234567890
#define MAX 1234567891
#define MOD 1234567891
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
 
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

#define modulo(S, N) ((S) & (N - 1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))
#define ll long long
#define int ll

int mission(int K, int D, int A, int k,int d, int a){
        int res = K*k - D*d + A*a;
        return (res>0) ? res : 0;
}

vector<int> K;
vector<int> D;
vector<int> A;


signed main(int argc, char** argv) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int N,M;

        cin >> N;
        while(N--){
                cin >> M;
                int m = M;
                int res = 0;
                while(M--){
                        int a,b,c;
                        cin >> a >> b >> c;
                        K.push_back(a);
                        // cout<<a<<endl;
                        D.push_back(b);
                        // cout<<b<<endl;
                        A.push_back(c);
                        // cout<<c<<endl;
                }
                int k,d,a;
                cin >> k >> d >> a;
                FOR(i,m){
                        res+=mission(K[i],D[i],A[i],k,d,a);
                }
                
                cout << res << endl;
                K.clear();
                D.clear();
                A.clear();
        }
        return 0;

        
}