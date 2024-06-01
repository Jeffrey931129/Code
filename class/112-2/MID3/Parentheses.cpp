#include <iostream>
#include <string>
using namespace std;

int n,num;
char r;
string s;
int check(),cal();

int main(){
    cin>>n; getline(cin,s);
    for(int i=0;i<n;i++){
        num=0; 
        getline(cin,s);
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
        // cout<<c<<" ";
        // cout<<s[num+1]<<endl;
        switch(c){
            case '{':
                if(s[++num]=='}') return true;
                break;
            case '[':
                if(s[++num]==']') return true;
                break;
            case '(':
                if(s[++num]==')') return true;
                break;
            case '<':
                if(s[++num]=='>') return true;
                break;
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
