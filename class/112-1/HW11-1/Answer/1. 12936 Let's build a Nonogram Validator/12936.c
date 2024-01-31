#include <stdio.h>

int T, N, M, r_len[50][50], c_len[50][50];
char Nonogram[50][50];

int solved(){
    for(int i=0; i<N; i++){
        int idx = 0, cnt = 0;
        for(int j=0; j<=M; j++){
            if(Nonogram[i][j] == 'o') cnt++;
            else if(cnt > 0){ //must be a 'x' or '\0'
                //found more grids than expected
                if(idx == r_len[i][0]) return 0;
                //the corresponding grid lengths are not matched
                if(cnt != r_len[i][++idx]) return 0;
                //reset length
                cnt = 0;
            }
        }
        //found less grids than expected
        if(idx != r_len[i][0]) return 0;
    }
    for(int j=0; j<M; j++){
        int idx = 0, cnt = 0;
        for(int i=0; i<=N; i++){
            if(Nonogram[i][j] == 'o') cnt++;
            else if(cnt > 0){ //must be a 'x' or '\0'
                //found more grids than expected
                if(idx == c_len[j][0]) return 0;
                //the corresponding grid lengths are not matched
                if(cnt != c_len[j][++idx]) return 0;
                //reset length
                cnt = 0;
            }
        }
        //found less grids than expected
        if(idx != c_len[j][0]) return 0;
    }
    return 1;
}

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &M);
        for(int i=0; i<N; i++){
            scanf("%d", &r_len[i][0]);
            for(int j=1; j<=r_len[i][0]; j++) scanf("%d", &r_len[i][j]);
        }
        for(int i=0; i<M; i++){
            scanf("%d", &c_len[i][0]);
            for(int j=1; j<=c_len[i][0]; j++) scanf("%d", &c_len[i][j]);
        }
        for(int i=0; i<N; i++) scanf("%s", Nonogram[i]);
        for(int i=0; i<M; i++) Nonogram[N][i] = '\0';
        printf(solved() ? "Yes\n" : "No\n");
    }
    return 0;
}
