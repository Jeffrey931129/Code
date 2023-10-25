#include <stdio.h>

long long arr[1001][1001],tem[1001][1001],tem1[1001][1001];
int main()
{
    int n,m,k,q;
    scanf("%d%d%d%d",&n,&m,&k,&q);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%lld",&arr[i][j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            tem[i][j]=tem[i][j-1]+arr[i][j];  // 加總
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            tem1[i][j]=tem[i][j]-tem[i-1][j];  // 差值
        }
    }

    while(k--)
    {
        int x1,y1,x2,y2,z;
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&z);
        for(int y=0;y1+y<=y2;y++)
        {
            tem1[x1][y1+y]+=z*(y+1);
            tem1[x2+1][y1+y]-=z*(y+1);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            tem[i][j]=tem1[i][j]+tem[i-1][j];  // 差值
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            printf("%lld",tem[i][j]-tem[i][j-1]);  // 加總
            if(j=m) printf("\n");
            else printf(" ");
        }
    }
    while(q--)
    {
        int x1,y1,x2,y2,answer=0;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        for(int x=x1;x<=x2;x++)
        {
            answer+=(tem[y2]-tem[y1-1]);
        }
        printf("%lld\n",answer);
    }
}