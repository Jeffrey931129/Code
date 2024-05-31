#include <iostream>
#include <set>
using namespace std;

multiset<int> s;

int main(){
    int n,m,value; cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>value;
        s.insert(value);
    }
    for(int i=0;i<m;i++){
        cin>>value;
        auto find=s.lower_bound(value);
        if(find==s.begin()) cout<<*find<<endl;
        else if(find==s.end()) cout<<*s.rbegin()<<endl;
        else if(*find-value>=value-*prev(find)) cout<<*prev(find)<<endl;
        else cout<<*find<<endl;
    }
}