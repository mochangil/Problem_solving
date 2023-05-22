#include <iostream>
#include <vector>
using namespace std;

vector<long long> K;
vector<long long> D;
vector<long long> A;


signed main(int argc, char** argv) {

        int N,M;
        long long res;

        cin >> N;
        while(N--){
                cin >> M;
                int m = M;
                res = 0;
                while(M--){
                        int x1,x2,x3;
                        cin >> x1 >> x2 >> x3;
                        K.push_back(x1);
                        // cout<<a<<endl;
                        D.push_back(x2);
                        // cout<<b<<endl;
                        A.push_back(x3);
                        // cout<<c<<endl;
                }
                int k,d,a;
                cin >> k >> d >> a;
                for(int i=0;i<m;i++){
                        res+=(K[i]*k - D[i]*d + A[i]*a);
                }
                printf("%lld\n",res);
                K.clear();
                D.clear();
                A.clear();
        }
        return 0;
        
}
