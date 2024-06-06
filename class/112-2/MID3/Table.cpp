#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

enum Command{ARRIVE,RELEASE,ASSIGN};
struct Clock{
    int time;
    Command type;
    Clock(int time,Command type):time(time),type(type){}
    bool operator<(const Clock& x)const{
        return time==x.time?type<x.type:time<x.time;
    }
};
struct Guest{
    int arrival,size,dinning_time,id=0;
    Guest(int a,int s,int t,int i):arrival(a),size(s),dinning_time(t),id(i){}
    bool operator==(Guest x){
        if(arrival==x.arrival) return true;
        else return false;
    }
};
struct Table{
    int size;
    int dinning;
    Table(int s,int t):size(s),dinning(t){}
};
struct table_size{
    bool operator()(Table x,Table y)const{
        return x.size<y.size;
    }
};
struct table_dinning{
    bool operator()(Table x,Table y)const{
        return x.dinning<y.dinning;
    }
};
struct guest_arrival{
    bool operator()(Guest x,Guest y)const{
        return x.arrival<y.arrival;
    }
};
struct guest_large{
    bool operator()(Guest x,Guest y)const{
        return x.size==y.size?x.arrival>y.arrival:x.size<y.size;
    }
};

set<Clock> s;
vector<Guest> guest;
map<int,int> table;
multiset<Table,table_dinning> used_table;
set<Guest,guest_arrival> waiting_arrival;
set<Guest,guest_large> waiting_large;
int answer[200000];
bool first_arrange(int now),other_arrange(int now);

int main(){
    int n,m; cin>>n>>m;
    int arrival,size,time;
    for(int i=0;i<n;i++){
        cin>>arrival>>size>>time;
        guest.push_back(Guest(arrival,size,time,i));
        s.insert(Clock(arrival,ARRIVE));
    }
    for(int i=0;i<m;i++){
        cin>>size>>time;
        table[size]=time;
    }
    while(!s.empty()){
        time=s.begin()->time;
        switch(s.begin()->type){
            case ARRIVE:
                if(time==guest[0].arrival){
                    waiting_arrival.insert(guest[0]),waiting_large.insert(guest[0]);
                    guest.erase(guest.begin());
                    s.insert(Clock(time,ASSIGN));
                    //cout<<time<<":push a guest"<<endl;
                }
                break;
            case RELEASE:
                while(used_table.size()){
                    if(time==used_table.begin()->dinning){
                        table[used_table.begin()->size]++;
                        used_table.erase(used_table.begin());
                        //cout<<time<<":clean a table"<<endl;
                    }
                    else break;
                }
                s.insert(Clock(time,ASSIGN));
                break;
            case ASSIGN:
                while(!waiting_arrival.empty()&&!table.empty()){
                    if(first_arrange(time)) continue;
                    else if(other_arrange(time)) continue;
                    else break;
                }
                break;
        }
        s.erase(s.begin());
    }
    for(int i=0;i<n;i++) cout<<answer[i]<<endl;
}

bool first_arrange(int now){
    Guest guest=*waiting_arrival.begin();
    auto find=table.lower_bound(guest.size);
    if(find!=table.end()){
        s.insert(Clock(now+guest.dinning_time,RELEASE));
        answer[guest.id]=now;
        used_table.insert(Table(find->first,now+guest.dinning_time));
        table[find->first]--;
        if(!table[find->first]) table.erase(find->first);
        waiting_large.erase(guest);
        waiting_arrival.erase(guest);
        //cout<<now<<":first arrange"<<endl;
        return true;
    }
    return false;
}

bool other_arrange(int now){
    auto large=waiting_large.upper_bound(Guest(0,table.rbegin()->first,0,0));
    if(large==waiting_large.begin()) return false;
    large--;
    auto find=table.lower_bound(large->size);
    
    s.insert(Clock(now+large->dinning_time,RELEASE));
    answer[large->id]=now;
    used_table.insert(Table(find->first,now+large->dinning_time));
    table[find->first]--;
    if(!table[find->first]) table.erase(find->first);
    waiting_arrival.erase(*large);
    waiting_large.erase(*large);
    //cout<<now<<":other arrange"<<endl;
    return true;
}