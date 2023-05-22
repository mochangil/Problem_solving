#include <iostream>
#include <vector>
#include <string.h>
#include <cstdio>
#include <map>

using namespace std;

#define MAXN 100000

map<string, int> names;
int root[MAXN] = {-1,};
int RANK[MAXN];
int cap[MAXN];

class Solution{
    private:
        int names_size = 0;
    public:
        Solution(int F)
        {
            for (int i = 0; i<MAXN;i++){
                root[i] = i;
                RANK[i] = 0;
                cap[i] = 1;
            }
        }
    int findRoot(int x);
	void UNION(string f1, string f2);
	void addNode(string name1, string name2);
	void printCap(string f1);
        
};
void Solution::printCap(string f1){
    cout << cap[names.at(f1)] << endl;
}
int Solution::findRoot(int x){
    while(x != root[x]){
        x = root[x];
    }
    return x;
    }
void Solution::UNION(string f1, string f2){
    int x = names.at(f1);
    int y = names.at(f2);
    int xRoot = findRoot(x);
    int yRoot = findRoot(y);
    if (xRoot == yRoot)
        return;
    root[y] = x;
    cap[x] = cap[x]+cap[y];
    }
void Solution::addNode(string name1,string name2){
    int count = 0;
    names.insert({name1,count++});
    names.insert({name2,count++});
    UNION(name1,name2);
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int T;
    cin >> T;

    while(T--){
        names.clear();
        int F;
        cin >> F;
        bool first = true;
        string name;
        Solution f_network(F);
        for (int i=0; i<F; i++){
            string f1,f2;
            cin >> f1 >> f2;
            if (first){
                name = f1;
                first = false;
            }
            f_network.addNode(f1,f2);
            f_network.printCap(name);
        }
    }
    return 0;
}