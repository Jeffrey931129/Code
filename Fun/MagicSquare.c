#include <stdio.h>

int s[5][5],is_used[25],fuck(int);
int main()
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
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
    if(x%5==0&&x!=0)
    {
        if(s[(x-5)/5][(x-5)%5]+s[(x-4)/5][(x-4)%5]+s[(x-3)/5][(x-3)%5]+s[(x-2)/5][(x-2)%5]+s[(x-1)/5][(x-1)%5]!=65)
        {
            return 0;
        }
    }
    if(x/5>3&&x!=20)
    {
        if(s[(x-21)/5][(x-21)%5]+s[(x-16)/5][(x-16)%5]+s[(x-11)/5][(x-11)%5]+s[(x-6)/5][(x-6)%5]+s[(x-1)/5][(x-1)%5]!=65)
        {
            return 0;
        }
    }
    if(x==21)
    {
        if(s[0][4]+s[1][3]+s[2][2]+s[3][1]+s[4][0]!=65)
        {
            return 0;
        }
    }
    if(x==25)
    {
        if(s[0][0]+s[1][1]+s[2][2]+s[3][3]+s[4][4]!=65)
        {
            return 0;
        }
        // 目前的s即為正解，自行調整print的東西吧
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                printf("%d ",s[i][j]);
            }
            printf("\n");
        }
        // 自行調整到此為止
        return 0;
    }
    if(s[x/5][x%5]!=0)
    {
        fuck(x+1);
        return 0;
    }
    else
    {
        for(int i=0;i<25;i++)
        {
            if(!is_used[i])
            {
                s[x/5][x%5]=i+1;
                is_used[i]=1;
                fuck(x+1);
                s[x/5][x%5]=0;
                is_used[i]=0;
            }
        }
        return 0;
    }
}