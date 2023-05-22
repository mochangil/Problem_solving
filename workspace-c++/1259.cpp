#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;

int main(){
    int a;
    string aaa = "yes";
    while(true){
        vector<int> aa;
        int cnt = 0;
        cin >> a;
        if(a==0) break;
        while(a>0){
            aa.push_back(a%10);
            a /= 10;
            cnt++;
        }
        // cout << cnt << endl;
        for(int i = 0; i<=cnt/2;i++){
            if(aa[i] != aa[cnt-(i+1)]) {
                aaa = "no";
                // cout << aa[i] << aa[cnt-(i+1)];
                break;
            }
        }
        cout << aaa << endl;
        aaa = "yes";
        
    }
    return 0;
}