#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define INF 1234567890
#define MAX 550
#define MOD 1234567891
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

#define modulo(S, N) ((S) & (N - 1))  // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))

#define int long long

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int a, b, d, N;
int dpsum[1000010];

// dpsum[r]을 구한다.
void solve(int r) {
    int cost = 0;

    if (r >= a && r < b) {
        cost = dpsum[r - a];
    } else if (r >= b) {
        cost = (dpsum[r - a] - dpsum[r - b] + 1000) % 1000;
    }

    if (r < d) cost += 1;

    dpsum[r] = dpsum[r - 1] + cost;
    dpsum[r] %= 1000;
}

signed main(signed argc, char **argv) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dpsum, -1, sizeof(dpsum));

    cin >> a >> b >> d >> N;
    dpsum[0] = 1;
    for (int i = 1; i <= N; i++)
        solve(i);

    int result = (dpsum[N] - dpsum[N - 1] + 1000) % 1000;
    cout << result;

    return 0;
}