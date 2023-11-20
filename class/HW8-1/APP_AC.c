#include <stdio.h>
#include <math.h>
#include <string.h>

int n,k,check[1005][1005],find(int,int);
char s[1005];
int main()
{
    memset(check,-1,sizeof(check));
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    if(find(0,n-1)<=k)
    {
        printf("Yes\n");
        return 0;
    }
    printf("No\n");
    return 0;
}

int find(int x,int y)
{
    if(check[x][y]!=-1)
    {
        return check[x][y];
    }
    if(x>=y)
    {
        check[x][y]=0;
        return check[x][y];
    }
    if(s[x]==s[y])
    {
        check[x][y]=find(x+1,y-1);
        return check[x][y];
    }
    else
    {
        check[x][y]=fmin(find(x+1,y),find(x,y-1))+1;
        return check[x][y];
    }
}