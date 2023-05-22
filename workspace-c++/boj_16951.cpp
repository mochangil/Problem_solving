#include <iostream>
#include <math.h>
#include <vector>


using namespace std;

int main(){
    int N,K,currentHeight,standard;
    vector<int> towers,count;
    vector<int>::iterator iter;
    int maxcount = 0;


    cin >> N >> K;

    for (int i=0;i<N;i++){
        int num;
        cin >> num;
        towers.push_back(num);
        if(i!=0 && K==towers[i]-towers[i-1]){
            count[i] = count[i-1]+1;
        }
        else
            count[i] = 0;
    }

    for (int j=0;j<N;j++){
        if (maxcount>count[j]){
            maxcount = count[j];
            standard = j;
        }
    }
    standard -= maxcount;

    cout << standard-N;




    
    return 0;
}