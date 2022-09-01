#include <iostream>
#include <stdlib.h>
using namespace std;

bool han(int n, int d){
    int a,b,dd;
    if (n/10 < 10)
        return true;
    a = (n/10)%10;
    b = n%10;
    dd = a-b;
    if (d == dd)
        han(n/10,d);
    else
        return false;
}
int main(){
    int num,counting = 0;
    cin >> num;
    if (num <= 99)
        cout << num << endl;
    else{
        for (int i = 100; i<=num; i++){
            int d = (i/10)%10 - i%10;
            cout << d << endl;
            if (han(i,d))
                counting++;
            }
        cout << counting+99 << endl;
    }
}

// 0~9는 한수가 아니고, 10 ~ 99 는 항상 한수이다.
// 