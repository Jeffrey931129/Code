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
    // 讀取
    for(int i=1;i<=n;i++)  // 每一行相對於前一個arr數字的差
    {
        for(int j=1;j<=m;j++)
        {
            tem[i][j]=arr[i][j]-arr[i][j-1];
        }
    }
    for(int i=1;i<=m;i++)  // 每一列相對於前一個tem數字的差
    {
        for(int j=1;j<=n;j++)
        {
            tem1[j][i]=tem[j][i]-tem[j-1][i];
        }
    }
    while(k--)  // 加總
    {
        int x1,y1,x2,y2,z;
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&z);
        tem1[x1][y1]+=z,tem1[x2+1][y1]-=z,tem1[x1][y2+1]-=z,tem1[x2+1][y2+1]+=z;
    }
    for(int i=1;i<=m;i++)  // 推回tem
    {
        for(int j=1;j<=n;j++)
        {
            tem[j][i]=tem1[j][i]+tem[j-1][i];
        }
    }
    for(int i=1;i<=n;i++)  // 推回arr並print
    {
        for(int j=1;j<=m;j++)
        {
            arr[i][j]=tem[i][j]+arr[i][j-1];
            printf("%lld",arr[i][j]);
            if(j!=m)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    // arr以完成
    for(int i=1;i<=n;i++)  // 每一行到該arr數字的總和
    {
        for(int j=1;j<=m;j++)
        {
            tem[i][j]=tem[i][j-1]+arr[i][j];
        }
    }
    for(int i=1;i<=m;i++)  // 每一列到該tem數字的總和
    {
        for(int j=1;j<=n;j++)
        {
            tem1[j][i]=tem[j][i]+tem1[j-1][i];
        }
    }
    // tem1為涵蓋左上方長方形中的所有arr值
    while(q--)
    {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        long long answer=tem1[x2][y2]+tem1[x1-1][y1-1]-tem1[x1-1][y2]-tem1[x2][y1-1];
        printf("%lld\n",answer);
    }
}