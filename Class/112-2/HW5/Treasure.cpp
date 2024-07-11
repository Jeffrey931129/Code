#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
    int id;
    int dist;
    node(int id, int l) {
        this->id = id;
        this->dist = l;
    }
};


vector<int> diamondTowns;
vector<int> G[100005]; // G[i] is the neighbor towns of town i
queue<node> Q;
int Dist[100005];
bool rec[100005];
void bfs(vector<int>);
void put_distance(int i,int distance);
void pick(int i);

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        diamondTowns.push_back(x);
    }
    fill(Dist, Dist+100005, 2147483647);

    // [TODO] complete the task!
    bfs(diamondTowns);
    // Output
    for (int i = 1; i <= N; i++) {
        cout << Dist[i] << '\n';
    }
    return 0;
}

void bfs(vector<int> diamon){
    int size=diamon.size();
    for(int i=0;i<size;i++){
        Q.push(node(diamon[i],0));
        put_distance(diamon[i],0);
        pick(diamon[i]);
    }
    while(!Q.empty()){
        node now=Q.front();
        for(auto i:G[now.id]){
            if(!rec[i]){
                int new_distance=now.dist+1;
                put_distance(i,new_distance);
                pick(i);
                Q.push(node(i,new_distance));
            }
        }
        Q.pop();
    }
}

void put_distance(int i,int distance){
    if(distance<Dist[i]){
        Dist[i]=distance;
    }
}

void pick(int i){
    rec[i]=true;
}