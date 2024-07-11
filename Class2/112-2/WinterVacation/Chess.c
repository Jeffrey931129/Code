#include <stdio.h>
void solve(int row,int queen_num,int rook_num);
int n,m,answer;
int queen_position[9][2],rook_position[9][2];
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        answer=0;
        solve(1,0,0);
        printf("%d\n",answer);
    }
}

void solve(int row,int queen_num,int rook_num)
{
    if(row>n+m)
    {
        // printf("queen:");
        // for(int i=0;i<n;i++) printf("%d %d ",queen_position[i][0],queen_position[i][1]);
        // printf("\nrook:");
        // for(int i=0;i<m;i++) printf("%d %d ",rook_position[i][0],rook_position[i][1]);
        // puts("success");
        answer++; return;
    }
    for(int i=1;i<=n+m;i++)
    {
        int error=0;
        for(int j=0;j<queen_num;j++)
            if(row-queen_position[j][0]==i-queen_position[j][1]||row-queen_position[j][0]==queen_position[j][1]-i||queen_position[j][1]==i)
                error=1;
        for(int j=0;j<rook_num;j++)
            if(rook_position[j][1]==i)
                error=1;
        if(error) continue;
        if(rook_num<m)
        {
            rook_position[rook_num][0]=row,rook_position[rook_num][1]=i;
            // printf("rook:%d %d\n",rook_position[rook_num][0],rook_position[rook_num][1]);
            solve(row+1,queen_num,rook_num+1);
        }
        if(queen_num<n)
        {
            error=0;
            for(int j=0;j<rook_num;j++)
                if(row-rook_position[j][0]==i-rook_position[j][1]||row-rook_position[j][0]==rook_position[j][1]-i)
                    error=1;
            if(error) continue;
            queen_position[queen_num][0]=row,queen_position[queen_num][1]=i;
            // printf("queen:%d %d\n",queen_position[queen_num][0],queen_position[queen_num][1]);
            solve(row+1,queen_num+1,rook_num);
        }

    }
}