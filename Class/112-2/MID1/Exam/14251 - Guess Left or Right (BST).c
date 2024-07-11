#include <stdio.h>
typedef long long ll;
int ch[100000][2];
int ans;

void swap(int *a, int *b);

ll sum(int n){
    ll s = 0;
    for(int i = 1; i <= n; i++)
        s +=i;
    return s;
}

void dfs(int root, int l, int r){
    if(!ans) return;
    if(root < l || root > r){
        ans = 0;
        return;
    }
    if(ch[root][0])
        dfs(ch[root][0], l, root - 1);
    if(ch[root][1])
        dfs(ch[root][1], root + 1, r);
        
}

int main(int argc, const char * argv[]) {
    int n;
    ll r;
    while(scanf("%d", &n) != EOF){
        ans = 1;
        r = sum(n);
        for(int i = 1; i <= n; i++)
            ch[i][0] = ch[i][1] = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d%d", &ch[i][0], &ch[i][1]);
            r -= (ch[i][0] + ch[i][1]);
            if(ch[i][0] > ch[i][1])
                swap(&ch[i][0], &ch[i][1]);
            if(ch[i][0] == 0){
                if(ch[i][1] < i)
                    swap(&ch[i][0], &ch[i][1]);
            }
            if(ch[i][0] && ch[i][1]){
                if((ch[i][0] < i && ch[i][1] < i) || (ch[i][0] > i && ch[i][1] > i) || (ch[i][0] == i || ch[i][1] == i)){
                    ans = 0;
                }
            }
                
        }
        if(ans){
            dfs((int)r, 1, n);
        }
        
        if(ans){
            printf("YES\n");
            for(int i = 1; i < n; i++){
                printf("%d ", i);
            }
            printf("%d\n", n);
        }
        else
            printf("NO\n");
        
    }
    return 0;
}

void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
