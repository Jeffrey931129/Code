#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

long long calc(vector<int> x);
struct cmp{
    bool operator()(vector<int> x,vector<int> y)const{
        return calc(x)<calc(y);
    }
};

long long calc(vector<int> x){
    long long x_sum=0;
    for(int i=0;i<x.size();i++){
        x_sum+=(x.size()-i)*x[i];
    }
    return x_sum;
}

set<vector<int>,cmp> s;
int main(){
    string command;
    while(cin>>command){
        if(command=="output"){
            for(auto i:s){
                for(auto j:i){
                    cout<<j<<" ";
                }
                cout<<endl;
            }
        }
        else if(command=="insert"){
            int val; vector<int> temp;
            while(cin>>val){
                if(val){
                    temp.push_back(val);
                }
                else break;
            }
            long long sum=calc(temp);
            for(auto i:s){
                if(calc(i)==sum){
                    cout<<"exist"<<endl;
                    s.erase(i);
                    vector<int> temp2;
                    for(int j=temp.size()-1;j>=0;j--){
                        temp2.push_back(temp[j]);
                    }
                    temp=temp2;
                    break;
                }
            }
            s.insert(temp);
        }
        else if(command=="range_out"){
            long long small,big;
            int val; vector<int> temp;
            while(cin>>val){
                if(val){
                    temp.push_back(val);
                }
                else break;
            }
            small=calc(temp); temp.clear();
            while(cin>>val){
                if(val){
                    temp.push_back(val);
                }
                else break;
            }
            big=calc(temp);
            for(auto i:s){
                long long sum=calc(i); bool stop=0;
                if(sum>=small&&sum<=big){
                    for(auto j:i){
                        cout<<j<<" ";
                    }
                    cout<<endl;
                    stop=1;
                }
                else if(stop) break;
            }
        }
    }
}