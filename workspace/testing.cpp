#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int>s;

    for (int i = 0; i<10 ;i++)
    {
        s.push(i+1);
    }
    cout << "스택의 size" << s.size();
    for(int i=0;i<10;i++)
    {
        cout << "가장 위에 있는 원소:" << s.top() << endl;
        s.pop();
    }

    if(s.empty()) cout << "비어있음" << endl;
    else cout << "비어있지 않음" << endl;
}