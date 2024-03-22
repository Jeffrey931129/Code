#include <stdio.h>

int child[200005][2] = {0};
int idx[200005] = {0};
int p[200005] = {0};
int ans = 1;

// Solve
void sol(int root, int l, int r){ 
    if(!ans) return;
    if(child[root][0] && child[root][1]){ // have 2 children
        // Check index to determine which side of the tree
        if((idx[child[root][0]] > idx[root] && idx[child[root][0]] <= r) && (idx[child[root][1]] < idx[root] && idx[child[root][1]] >= l)){ // 0 is right and 1 is left
            sol(child[root][0], idx[root] + 1, r);
            sol(child[root][1], l, idx[root] - 1);
        }
        else if((idx[child[root][1]] > idx[root] && idx[child[root][1]] <= r) && (idx[child[root][0]] < idx[root] && idx[child[root][0]] >= l)){ // 1 is right and 0 is left
            sol(child[root][1], idx[root] + 1, r);
            sol(child[root][0], l, idx[root] - 1);
        }
        else ans = 0;
    }
    else if(child[root][0]){
        // Check index to determine which side of the tree
        if(idx[child[root][0]] < idx[root] && idx[child[root][0]] >= l) // left
            sol(child[root][0], l, idx[root] - 1);
        else if(idx[child[root][0]] > idx[root] && idx[child[root][0]] <= r) // right
            sol(child[root][0], idx[root] + 1, r);
        else ans = 0;
    }
    else if(child[root][1]){
        // Check index to determine which side of the tree
        if(idx[child[root][1]] < idx[root] && idx[child[root][1]] >= l) // left
            sol(child[root][1], l, idx[root] - 1);
        else if(idx[child[root][1]] > idx[root] && idx[child[root][1]] <= r) // right
            sol(child[root][1], idx[root] + 1, r);
        else ans = 0;
    }
    else return; // leaf
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        ans = 1;
        for(int i = 0; i <= n; i++){ // initialize
            p[i] = 0;
            idx[i] = 0;
            child[i][0] = 0;
            child[i][1] = 0;
        }
        for(int i = 1; i <= n; i++){
            scanf("%d %d", &child[i][0], &child[i][1]);
            p[child[i][0]] = i;
            p[child[i][1]] = i;
        }
        for(int i = 1; i <= n; i++){
            int num;
            scanf("%d", &num);
            idx[num] = i; // record the inorder location
        }
        int root;
        for(int i = 1; i <= n; i++){
            if(!p[i]) {root = i; break;}
        }
        sol(root, 1, n);
        if(ans)
            printf("YES\n");
        else
            printf("NO\n");
    }
}