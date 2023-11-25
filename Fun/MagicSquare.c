#include <stdio.h>
#define N 5
int s[N][N],is_used[N*N],fuck(int),num=N*(N*N+1)/2;
int main()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d",&s[i][j]);
            if(s[i][j]!=0)
            {
                is_used[s[i][j]-1]=1;
            }
        }
    }
    fuck(0);
    return 0;
}

int fuck(int x)
{
    if(x%N==0&&x!=0)
    {
        int total=0;
        for(int i=1;i<=N;i++)
        {
            total+=s[(x-i)/N][(x-i)%N];
        }
        if(total!=num)
        {
            return 0;
        }
    }
    if(x/N>N-2&&x!=N*(N-1))
    {
        int total=0;
        for(int i=0;i<N;i++)
        {
            total+=s[(x-1-i*N)/N][(x-1-i*N)%N];
        }
        if(total!=num)
        {
            return 0;
        }
    }
    if(x==N*(N-1)+1)
    {
        int total=0;
        for(int i=0;i<N;i++)
        {
            total+=s[i][N-i-1];
        }
        if(total!=num)
        {
            return 0;
        }
    }
    if(x==N*N)
    {
        int total=0;
        for(int i=0;i<N;i++)
        {
            total+=s[i][i];
        }
        if(total!=num)
        {
            return 0;
        }
        // 目前的s即為正解，自行調整print的東西吧
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                printf("%d ",s[i][j]);
            }
            printf("\n");
        }
        // 自行調整到此為止
        return 0;
    }
    if(s[x/N][x%N]!=0)
    {
        fuck(x+1);
        return 0;
    }
    else
    {
        for(int i=0;i<N*N;i++)
        {
            if(!is_used[i])
            {
                s[x/N][x%N]=i+1;
                is_used[i]=1;
                fuck(x+1);
                s[x/N][x%N]=0;
                is_used[i]=0;
            }
        }
        return 0;
    }
}