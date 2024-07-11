#include <stdio.h>
int n,solve=0,go[8][2]={1,2,-1,2,-2,1,-2,-1,1,-2,-1,-2,2,1,2,-1};
int find(int step,int x,int y);
char chess[100][100],S[10]="ICPCASIASG";
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf(" %c",&chess[i][j]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n&&!solve;j++)
        {
            if(chess[i][j]=='I')
                find(1,i,j);
        }
    if(solve) printf("YES\n");
    else printf("NO\n");
}

int find(int step,int x,int y)
{
    if(step==10)
    {
        solve=1; return 1;
    }
    for(int i=0;i<8;i++)
    {
        if(x+go[i][0]<n&&x+go[i][0]>=0&&y+go[i][1]>=0&&y+go[i][1]<n&&chess[x+go[i][0]][y+go[i][1]]==S[step])
            if(find(step+1,x+go[i][0],y+go[i][1]))
                return 1;
    }
    return 0;
}