#include <stdio.h>
#include <stdlib.h>

int tree[1005] = {0}; // seafu
int dis[1005] = {0}; // number of diciple

void recur(int cur){ // for disciples query
    if(cur == 1){ // if cur == FrankLee  
        dis[1]++; // disiples++
        return; // finish recursion
    }
    else{
        dis[cur]++; // cur id's number of disiples++
        int next = tree[cur]; // next = cur's seafu
        recur(next); // continue checking
    }
}

int find_seafu(int a, int b){ //check a is b's seafu or not
    if(tree[b] == a) return 1;
    else if(tree[b] != a && tree[b] == -1) return 0;
    else find_seafu(a, tree[b]);
}

int main(){
    int n;
    scanf("%d", &n);

    tree[1] = -1; //initialize FrankLee

    for(int i = 2; i <= n; i++){
        int par;
        scanf("%d", &par);
        tree[i] = par;
        recur(par);
    }

    int q;
    scanf("%d", &q);
    while(q--){
        int test, x, a, b;
        int ans;
        scanf("%d", &test);
        if(test == 1){
            scanf("%d", &x);
            ans = dis[x];
        }
        else{ //test == 2
            scanf("%d %d", &a, &b);
            if(find_seafu(a, b)) ans = 1;
            else if(find_seafu(b, a)) ans = 0;
            else ans = -1;
        }
        printf("%d\n", ans);
    }
}
