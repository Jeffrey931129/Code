#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node{
  int level,hp,monster_hp,round;
  node(int l,int h,int mh,int r):level(l),hp(h),monster_hp(mh),round(r){}
};

int value;
int maxlevel,maxhp,m_hp,m_damage;
bool vis[20][310][410];     // 這個是必要的，因為如果只能一直治療一直打會沒完沒了，造成 Runtime Error
vector<int> damage,heal;
queue<node> q;
void bfs(int,int,int,int);

int main(){
    cin>>maxlevel>>maxhp>>m_hp>>m_damage;
    damage.push_back(0); heal.push_back(0);
    for(int i=0;i<maxlevel;i++){
        cin>>value; damage.push_back(value);
        cin>>value; heal.push_back(value);
    }
    value=-1;
    bfs(1,maxhp,m_hp,0);
    if(value==-1) cout<<"-1\n";
    else cout<<value<<endl;
}

void bfs(int level,int hp,int monster_hp,int round){
    q.push(node(level,hp,monster_hp,round));
    while(!q.empty()){
        node temp=q.front();
        if(temp.monster_hp<=0){
            value=temp.round; return;
        }
        if(temp.hp>0&&!vis[temp.level][temp.hp][temp.monster_hp]){
            vis[temp.level][temp.hp][temp.monster_hp]=true;
            q.push(node(temp.level,temp.hp-m_damage,temp.monster_hp-damage[temp.level],temp.round+1));
            q.push(node(temp.level,min(temp.hp+heal[temp.level],maxhp)-m_damage,temp.monster_hp,temp.round+1));
            if(temp.level<maxlevel) q.push(node(temp.level+1,temp.hp-m_damage,temp.monster_hp,temp.round+1));
        }
        q.pop();
    }
    return;
}