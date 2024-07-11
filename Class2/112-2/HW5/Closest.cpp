#include <iostream>
#include <set>
using namespace std;

set<int> myset;

int main(){
    int n,m; cin>>n>>m;
    while(n--){
        int val; cin>>val;
        myset.insert(val);
    }
    while(m--){
        int val; cin>>val;
        auto big=myset.lower_bound(val);        // 尋找 >= val的值
        if(big==myset.end()) cout<<*(myset.rbegin())<<endl;
        else if(big==myset.begin()) cout<<*big<<endl;
        else if(val-*(prev(big))<=*big-val) cout<<*(prev(big))<<endl;
        else cout<<*big<<endl;
    }
}