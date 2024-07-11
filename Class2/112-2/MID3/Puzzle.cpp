#include <iostream>
#include <queue>
#include <vector>
using namespace std;

enum Direction{UP,LEFT,RIGHT,DOWN,NON};
struct State{
    int round;
    int space_x,space_y;
    int h;
    int liner=0;
    int sum=0;
    Direction prev=NON;
    int v[4][4];
    State(int round,int rec[4][4],int x,int y):round(round),space_x(x),space_y(y){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++) v[i][j]=rec[i][j];
        }
    }
    bool operator<(const State& x)const{        
        return sum>x.sum;
    }
};

priority_queue<State> q;
int goal[16][2]={{3,3},{0,0},{0,1},{0,2},{0,3},{1,0},{1,1},{1,2},{1,3},{2,0},{2,1},{2,2},{2,3},{3,0},{3,1},{3,2}};
int x,y;
void heuristic(State& s,Direction m);
void line_conflict(State& s);
State swap(State s,Direction m);

int main(){
    int rec[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>rec[i][j];
            if(!rec[i][j]) x=i,y=j;
        }
    }
    State temp(0,rec,x,y);
    heuristic(temp,NON);
    if(!temp.h){
        cout<<"0\n"; return 0;
    } 
    q.push(temp);
    while(!q.empty()){
        temp=q.top();
        q.pop();
        if(temp.prev!=DOWN&&temp.space_x>0){     // space up
            State up=swap(temp,UP);
            if(!up.h){
                cout<<up.round<<endl; return 0;
            }
            if(up.round+up.h+up.liner<=80){
                q.push(up);
            }
        }
        if(temp.prev!=UP&&temp.space_x<3){     // space down
            State down=swap(temp,DOWN);
            if(!down.h){
                cout<<down.round<<endl; return 0;
            }
            if(down.round+down.h+down.liner<=80){
                q.push(down);
            }
        }
        if(temp.prev!=RIGHT&&temp.space_y>0){     // space left
            State left=swap(temp,LEFT);
            if(!left.h){
                cout<<left.round<<endl; return 0;
            }
            if(left.round+left.h+left.liner<=80){
                q.push(left);
            }
        }
        if(temp.prev!=LEFT&&temp.space_y<3){     // space right
            State right=swap(temp,RIGHT);
            if(!right.h){
                cout<<right.round<<endl; return 0;
            }
            if(right.round+right.h+right.liner<=80){
                q.push(right);
            }
        }
    }
    cout<<"-1\n";
}

void heuristic(State& s,Direction m){
    switch(m){
        case UP: 
            s.h+= -abs(s.space_x-goal[s.v[s.space_x+1][s.space_y]][0])+abs(s.space_x+1-goal[s.v[s.space_x+1][s.space_y]][0]);
            break;
        case DOWN: 
            s.h+= -abs(s.space_x-goal[s.v[s.space_x-1][s.space_y]][0])+abs(s.space_x-1-goal[s.v[s.space_x-1][s.space_y]][0]);
            break;
        case LEFT: 
            s.h+= -abs(s.space_y-goal[s.v[s.space_x][s.space_y+1]][1])+abs(s.space_y+1-goal[s.v[s.space_x][s.space_y+1]][1]);
            break;
        case RIGHT: 
            s.h+= -abs(s.space_y-goal[s.v[s.space_x][s.space_y-1]][1])+abs(s.space_y-1-goal[s.v[s.space_x][s.space_y-1]][1]);
            break;
        default:
            s.h=0;  
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    if(s.v[i][j]){
                        s.h+=abs(i-goal[s.v[i][j]][0])+abs(j-goal[s.v[i][j]][1]);
                    }
                }
            }
    }
}

void line_conflict(State& s){
    s.liner=0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (s.v[i][j]) {
                if (i == goal[s.v[i][j]][0]) {
                    for (int k = j; k < 4; k++) {
                        if (s.v[i][k] && goal[s.v[i][k]][0] == i && s.v[i][j] > s.v[i][k])
                        s.liner += 2;
                    }
                }
                if (j == goal[s.v[i][j]][1]) {
                    for (int k = i; k < 4; k++) {
                        if (s.v[k][j] && goal[s.v[k][j]][1] == j && s.v[i][j] > s.v[k][j])
                        s.liner += 2;
                    }
                }
            }
        }
    }
}

State swap(State s,Direction m){
    switch(m){
        case UP: 
            s.v[s.space_x][s.space_y]=s.v[s.space_x-1][s.space_y];
            s.v[--(s.space_x)][s.space_y]=0; s.prev=UP;
            heuristic(s,UP); line_conflict(s);
            break;
        case DOWN: 
            s.v[s.space_x][s.space_y]=s.v[s.space_x+1][s.space_y];
            s.v[++(s.space_x)][s.space_y]=0; s.prev=DOWN;
            heuristic(s,DOWN); line_conflict(s);
            break;
        case LEFT: 
            s.v[s.space_x][s.space_y]=s.v[s.space_x][s.space_y-1];
            s.v[s.space_x][--(s.space_y)]=0; s.prev=LEFT;
            heuristic(s,LEFT); line_conflict(s);
            break;
        case RIGHT: 
            s.v[s.space_x][s.space_y]=s.v[s.space_x][s.space_y+1];
            s.v[s.space_x][++(s.space_y)]=0; s.prev=RIGHT;
            heuristic(s,RIGHT); line_conflict(s);  
            break;
        default: break;  
    }
    s.round++;
    s.sum=s.round+s.h+s.liner;
    return s;
}