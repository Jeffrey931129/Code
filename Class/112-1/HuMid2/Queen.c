#include <stdio.h>

int chess[10][10],answer,col[10],valid(int,int);
void queen(int,int);
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%1d",&chess[i][j]);
        }
    }
    queen(n,0);
    printf("%d\n",answer);
}

void queen(int n,int row)
{
    if(row==n)
    {
        answer++; return;
    }
    for(int y=0;y<n;y++)
    {
        if(chess[row][y]==0&&valid(row,y))
        {
            col[row]=y;
            queen(n,row+1);
        }
    }
}

int valid(int x,int y)
{
    for(int i=0;i<x;i++)
    {
        if(y!=col[i]&&y!=col[i]+x-i&&y!=col[i]-x+i)
        {
            ;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}