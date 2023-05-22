#include <iostream>
#include <stdio.h>
using namespace std;

int is_palin(char st[], int n){
    cout << st << "\tsize = " << n <<endl;
    if (n <= 1) return 1;
    if (st[0] == st[n-1]){
        cout << "current recursion *st = " << *st << "\tst[n-1] = " << st[n-1] << "\nnext recursion *(st+1) = " << *(st+1) << "\tst[n-2] = " << st[n-2] << "\n" << endl;
        return is_palin(st+1, n-2);
    }
    else{
        return 0;
    }
}

int main(){
    char st[] = "abcdedcba";
    printf("%d",is_palin(st,9));
}