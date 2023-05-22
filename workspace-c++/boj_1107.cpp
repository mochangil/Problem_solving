#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

#define MIN(a,b) (a<b ? a:b)
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
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int allow[10] = {1,1,1,1,1,1,1,1,1,1};
int min_cnt = 999999;
int N,M,sz;

void solve(string res){
    FOR(i,10){
        if(allow[i]){
            string currentNum = res+to_string(i);
            //가능한 숫자를 하나하나 넣고 현재까지 넣은 숫자에서 +,- 로 N까지 접근한 경우
            //length가 
            min_cnt = MIN(min_cnt,abs(N-stoi(currentNum))+currentNum.length());
            // cout << "current number is = " << allow[i] << "current count is = " << min_cnt << endl;
            if(currentNum.length() < 6){
                solve(currentNum);
            }
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
    
    string NUM;
    int bruteNum,res;
    cin >> NUM >> M;
    N = stoi(NUM);
    bruteNum = abs(N - 100);
    min_cnt = MIN(min_cnt, bruteNum);

    FOR(i,M){
        int num;
        cin >> num;
        allow[num] = 0;
    }
    
    if(M < 10){
        solve("");
    }

    cout << min_cnt;
}