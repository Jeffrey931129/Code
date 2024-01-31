#include <stdio.h>
#include <math.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        int n,m,k,r,p,s;
        scanf("%d %d %d %d %d %d",&n,&m,&k,&r,&p,&s);
        r=r%4;
        int ceil = (n+2*p-m+1)/s;
        if((n+2*p-m+1)%s != 0) ceil++;
        int A[520][520]={0},B[m][m],C[ceil][ceil];
        
        switch(r)
        {
            case 0:
            for(int i=p;i<n+p;i++)
            {
                for(int j=p;j<n+p;j++)
                {
                    scanf("%d",&A[i][j]);
                }
            }
            break;
            case 1:
            for(int y=n+p-1;y>=p;y--)
            {
                for(int x=p;x<n+p;x++)
                {
                    scanf("%d",&A[x][y]);
                }
            }
            break;
            case 2:
            for(int x=n+p-1;x>=p;x--)
            {
                for(int y=n+p-1;y>=p;y--)
                {
                    scanf("%d",&A[x][y]);
                }
            }
            break;
            case 3:
            for(int y=p;y<=n+p-1;y++)
            {
                for(int x=n+p-1;x>=p;x--)
                {
                    scanf("%d",&A[x][y]);
                }
            }
            break;
        }


        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%d",&B[i][j]);
            }
        }
        for(int i=0;i<ceil;i++)
        {
            for(int j=0;j<ceil;j++)
            {
                C[i][j]=0;
				for(int x=0;x<m;x++)
                {
                    for(int y=0;y<m;y++)
                    {
                        C[i][j]+=A[i*s+x][j*s+y]*B[x][y];
                    }
                }
            }
        }
        int MaxP=ceil/k;
        if(ceil%k!=0) MaxP++;
        for(int x_time=0;x_time<MaxP;x_time++)
        {
            for(int y_time=0;y_time<MaxP;y_time++)
            {
                int Max=C[x_time*k][y_time*k];
                for(int x=0;x<k&&x_time*k+x<ceil;x++)
                {
                    for(int y=0;y<k&&y_time*k+y<ceil;y++)
                    {
                        Max=fmax(Max,C[x_time*k+x][y_time*k+y]);
                    }
                }
                printf("%d ",Max);
            }
            printf("\n");
        }
    }
	return 0;
}
