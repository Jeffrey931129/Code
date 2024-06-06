#include <iostream>
#include <set>
using namespace std;

set<int> s;

int main(){
    int n,command,x; cin>>n;
    while(n--){
        cin>>command>>x;
        if(command==1){
            auto find=s.find(x);
            if(find==s.end()) s.insert(x);
            else s.erase(x);
        }
        else{
            auto find=s.lower_bound(x);
            if(find==s.end()) cout<<"-1\n";
            else if(*find==*(s.rbegin())&&*find==x) cout<<"-1\n";
            else if(find==s.begin()&&*find!=x) cout<<"-1\n";
            else if(*find==x){
                cout<<*next(find)-x<<endl;
            }
            else{
                cout<<*find-*prev(find)<<endl;
            }
        }
    }
}