#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;

struct Task{
    int type,position;
    Task(int t,int p):type(t),position(p){}
};
struct task_cmp{
    bool operator()(Task x,Task y)const{
        return x.type==y.type?x.position<y.position:x.type<y.type;
    }
};
int n,m,t,value;
multiset<Task,task_cmp> task;

int main(){
    cin>>m>>n;
    vector<vector<int>> cute(m);
    vector<int> answer(n,0);
    for(int i=0;i<m;i++){
        cin>>t;
        while(t--){
            cin>>value;
            cute[i].push_back(value);
        }
    }
    for(int i=0;i<n;i++){
        cin>>value;
        task.insert(Task(value,i));
    }
    // for(auto i:task){
    //     cout<<i.type<<'-'<<i.position<<endl;
    // }
    bool cry=false;
    for(int i=0;i<m;i++){
        vector<int> job;
        for(auto j:cute[i]){
            auto find=task.lower_bound(Task(j,0));
            if(find==task.end()){
                cry=true; break;
            }
            else if(find->type!=j){
                cry=true; break;
            }
            else{
                job.push_back(find->position);
                task.erase(find);
            }
        }
        if(cry){
            break;
        }
        for(auto j:job){
            answer[j]=i+1;
        }
    }
    for(int i=0;i<n;i++){
        cout<<answer[i]<<endl;
    }
}