#include <stdio.h>

int main() {
    int T, n, m, k, ans;
    int A[505][505], B[5][5];
    scanf("%d", &T);

    while(T--){

        scanf("%d%d%d", &n, &m, &k);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%d", &A[i][n-j-1]);
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                scanf("%d", &B[i][j]);
            }
        }

        ans = 0;
        for(int i=0; i<n-m+1; i++){
            for(int j=0; j<n-m+1; j++){
                int sum = 0;
                for(int x=0; x<m; x++){
                    for(int y=0; y<m; y++){
                        sum += A[i+x][j+y] * B[x][y];
                    }
                }
                if(sum > k) ans++;
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
