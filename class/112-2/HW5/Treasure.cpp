#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// G[i] is the neighbor towns of town i
vector<int> diamondTowns;
vector<int> G[100005];
queue<node> Q;
int Dist[100005];
bool bfs(int,int,int);

struct node {
    int id;
    int dist;
    node(int id, int l) {
        this->id = id;
        this->dist = l;
    }
};

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
    fill(Dist, Dist+100005, -1);

    // [TODO] complete the task!
    for(int i=0;i<N;i++){
        while(!Q.empty()) Q.pop();
        bfs(i+1);
    }
    // Output
    for (int i = 1; i <= N; i++) {
        cout << Dist[i] << '\n';
    }
    return 0;
}

bool bfs(int now,int distance,int start){
    node temp(now,distance);
    for(auto i:diamondTowns){
        if(i==now) return true;
    }
    for(auto i:G[now]){
        if(bfs(i,distance+1,start)) return true;
    }
}