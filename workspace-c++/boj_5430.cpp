#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,n) for(int i=0;i<n;++i)

int T;

deque<int> dq;
int main(){
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

    cin >> T;
    while(T--){
        int n;
        bool emp = false;
        string P,Q,buf;
        vector<string> Q2;
        stringstream ss;
        int rev = 1;
        cin >> P >> n >> Q;
        Q = Q.substr(1,Q.size()-2);
        ss << Q;

        while(getline(ss,buf,',')){
            dq.push_back(stoi(buf));
        }

        // cout << P << Q << endl;
        FOR(i,P.size()){
            if (P[i] == 'R')
                rev *= -1;
            else{
                if (dq.empty()){
                    emp = true;
                    continue;
                }
                if (rev < 0){
                    dq.pop_back();
                }
                else{
                    dq.pop_front();
                }
            }
        }
        // FOR(i,dq.size()){
        //     cout << "dq = " << dq[i] << " ";
        // }
        if (emp){
            cout << "error" << endl;
            continue;
        }
        else if(dq.empty()){
            cout << "[]" << endl;
        }
        else if(rev>0){
            cout << '[';
            FOR(i,dq.size()-1){
                cout << dq[i] << ",";
            }
            cout << dq[dq.size()-1] << ']' << endl;
            // cout << ']' << endl;
        }
        else{
            cout << '[';
            for(int i = dq.size()-1; i>0;--i){
                cout << dq[i] << ",";
            }
            cout << dq[0] << ']' << endl;
            // cout << ']' << endl;
        }

        dq.clear();

    }
}