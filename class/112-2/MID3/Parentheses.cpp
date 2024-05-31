#include <iostream>
#include <string>
using namespace std;

int n,num;
string s;
int check(),cal();

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        num=0;
        cin>>s;
        cout<<"Case "<<i+1<<" ";
        if(s.empty()||check()){
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
    }
}

int check(){
    while(s[num]!=0){
        if(s[num]==s[++num]){
            num++; continue;
        }
        switch(s[num]){
            case '{':
                if(!cal()) return false;
                break;
            case '[':
                if(!cal()) return false;
                break;
            case '(':
                if(!cal()) return false;
                break;
            case '<':
                if(!cal()) return false;
                break;
            default: return false;
        }
    }
    return true;
}

int cal(){
    char c=s[num];
    while(s[num]!=0){
        if(c==s[++num]){
            num++; return true;
        }
        switch(s[num]){
            case '{':
                if(!cal()) return false;
                break;
            case '[':
                if(!cal()) return false;
                break;
            case '(':
                if(!cal()) return false;
                break;
            case '<':
                if(!cal()) return false;
                break;
            default: return false;
        }
    }
    return true;
}