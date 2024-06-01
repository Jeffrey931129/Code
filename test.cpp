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
        cout<<"Case "<<i+1<<": ";
        if(s.empty()||cal()){
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
    }
}

int cal(){
    while(s[num]!=0){
        if(!check()) return false;
        num++;
    }
    return true;
}

int check(){
    char c=s[num];
    while(s[num]!=0){
        if(c==s[++num]){
            return true;
        }
        switch(s[num]){
            case '{':
                if(!check()) return false;
                break;
            case '[':
                if(!check()) return false;
                break;
            case '(':
                if(!check()) return false;
                break;
            case '<':
                if(!check()) return false;
                break;
            default: return false;
        }
    }
    return true;
}
