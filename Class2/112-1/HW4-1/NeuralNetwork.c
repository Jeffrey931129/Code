#include <stdio.h>

int main()
{
    int T,n,m,k,answer=0;
    scanf("%d",&T);
    //printf("%d",T);
    for(int final=0;final<T;final++)
    {
        scanf(" %d %d %d",&n,&m,&k);
        //printf("%d%d%d",n,m,k);
        int A[n][n],B[m][m],C[n-m+1][n-m+1];
        for(int i=0;i<n;i++)
        {
            //scanf("%d",&A[i][0]);
            for(int j=0;j<n;j++)
            {
                scanf("%d",&A[i][n-j-1]);
            }
        }
        for(int i=0;i<m;i++)
        {
            //scanf("%d",&B[i][0]);
            for(int j=0;j<m;j++)
            {
                scanf(" %d",&B[i][j]);
            }
        }
        for(int i=0;i<(n-m+1);i++)
        {
            for(int j=0;j<(n-m+1);j++)
            {
                C[i][j]=0;
            }
        }
        for(int i=0;i<(n-m+1);i++)
        {
            for(int j=0;j<(n-m+1);j++)
            {
                for(int x=0;x<m;x++)
                {
                    for(int y=0;y<m;y++)
                    {
                        C[i][j]+=(A[i+x][j+y]*B[x][y]);
                    }
                }
                if(C[i][j]>k)
                {
                    answer++;
                }
            }
        }
        printf("%d\n",answer);
        answer=0;
    }
    return 0;
}