#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n,m,t;
int chess[20][20],flip_position[5][2]={-1,0,0,-1,0,0,0,1,1,0};
int dfs(int x,int step,int goal),check();
void flip(int x);
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(chess,0,sizeof(chess));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                char ch;
                scanf(" %c",&ch);
                if(ch=='b') chess[i][j]=0;
                else chess[i][j]=1;
            }
        }
        int success=0;
        for(int i=0;i<=n*m;i++)
        {
            if(dfs(1,0,i))
            {
                printf("%d\n",i); success++;
                break;
            }
        }
        if(!success) printf("oops\n");
    }
}

int dfs(int x,int step,int goal)
{
    if(step==goal)
    {
        if(check()) return 1;
        return 0;
    }
    for(int i=x;i<=n*m-goal+step+1;i++)
    {
        flip(i);
        if(dfs(x+1,step+1,goal)) return 1;
        flip(i);
    }
    return 0;
}

int check()
{
    int base=chess[1][1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(chess[i][j]!=base) return 0;
        }
    }
    return 1;
}

void flip(int x)
{
    for(int i=0;i<5;i++)
    {
        chess[(x-1)/m+1+flip_position[i][0]][(x-1)%m+1+flip_position[i][1]]=!chess[(x-1)/m+1+flip_position[i][0]][(x-1)%m+1+flip_position[i][1]];
    }
}