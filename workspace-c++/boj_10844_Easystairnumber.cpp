#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int stairnumber(int N){
    long long dp[101][10] = {0};
    long long ans = 0;

    for (int j=0;j<=9;j++)
        dp[1][j] = 1;
    for (int j=2;j<=N;j++){
        for (int i=0;i<=9;i++){
            if (i == 0){
                dp[j][i] = dp[j-1][1];
            }
            else if(i == 9){
                dp[j][i] += dp[j-1][8];
            }
            else{
                dp[j][i] += (dp[j-1][i-1] + dp[j-1][i+1]);
                dp[j][i] = dp[j][i] % 1000000000;
            }
        }
    }
    for (int j=1;j<=9;j++){
        ans += dp[N][j];
        ans = ans%1000000000;
        // cout << "dp " << N << j << " = " << dp[N][j] << endl;
    }
    return ans;
}
int main(){
    int N;
    cin >> N;
    
    cout << stairnumber(N) << endl;
    
}

// 121,123,101
// 210,212,232,234
// 989,987,
// 10, 12
// 21, 23
// 3
// 4
// 5
// 67,65
// 76,68
// 89,87
// 98