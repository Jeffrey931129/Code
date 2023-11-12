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
    
    while(k--)
    {
        int x1,y1,x2,y2,z;
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&z);
        tem[x1][y1]+=z,tem[x2+1][y1]-=z,tem[x1][y2+1]-=z,tem[x2+1][y2+1]+=z;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            tem1[i][j]=tem[i][j]+tem[i][j-1];  // 加總
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=1;k<=i;k++)
            {
                arr[i][j]+=tem1[k][j];  // 加總
            }
            printf("%lld",arr[i][j]);  
            if(j==m) printf("\n");
            else printf(" ");
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            tem1[i][j]=arr[i][j-1]+arr[i][j];
        }
    }
    while(q--)
    {
        int x1,y1,x2,y2,answer=0;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        for(int x=x1;x<=x2;x++)
        {
            answer+=(tem1[y2]-tem1[y1-1]);
        }
        printf("%lld\n",answer);
    }
}