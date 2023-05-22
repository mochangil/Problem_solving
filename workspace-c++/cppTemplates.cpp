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
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
 
int n;
struct INFO{
   int multi, sum, num;
   INFO(int m, int s, int n){
      multi = m;
      sum = s;
      num = n;
   }
   INFO(){}

   bool operator<(const INFO& info){
      if(multi < info.multi) return true;
      else if(multi > info.multi) return false;

      if(sum < info.sum) return true;
      else if(sum > info.sum) return false;


      if(num < info.num) return true;
      else if(num > info.num) return false;

      return false;
   }
};

vector<INFO> infos;

signed main(int argc, char** argv) {
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

      cin >> n;
      FOR(i, n){
         int num,a,b,c;
         cin >> num >> a >> b >> c;
         infos.push_back(INFO(a*b*c, (a + b + c), num));
      }

      sort(ALL(infos));

      FOR(i, 3){
         cout << infos[i].num << " ";
      }

        return 0;
}