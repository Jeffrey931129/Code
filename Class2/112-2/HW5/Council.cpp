#include <iostream>
#include <string>
#include <set>
using namespace std;

multiset<int> myset;        // multiset 允許insert重複的元素，set 則不

int main(){
    int n; string s;
    cin>>n;
    while(n--){
        cin>>s;
        if(s=="Add"){
            int val; cin>>val;
            myset.insert(val);
        }
        else if(s=="Remove"){
            int val; cin>>val;
            auto find=myset.find(val);
            if(find!=myset.end()) myset.erase(find);
        }
        else if(s=="Max"){
            if(!myset.empty()){
                cout<<*(myset.rbegin())<<endl;
            }
            else cout<<"No votes recorded"<<endl;
        }
        else if(s=="Min"){
            if(!myset.empty()){
                cout<<*(myset.begin())<<endl;
            }
            else cout<<"No votes recorded"<<endl;
        }
    }
}