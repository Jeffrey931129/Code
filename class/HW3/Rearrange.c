#include <stdio.h>

int main()
{
    int N,M,i=0,ex1,ex2,j,k;
    scanf("%d %d",&N,&M);
    int seat[N+1];
    while(i<=N+1)
    {
        seat[i]=i;
        i=i+1;
    }
    i=0;
    while(i<M)
    {
        scanf("%d %d",&ex1,&ex2);
        j=0;
        k=0;
        while(seat[j]!=ex1)   // != 不等於符號
        {
            j=j+1;
        }
        while(seat[k]!=ex2)
        {
            k=k+1;
        }
        seat[0]=seat[j];
        seat[j]=seat[k];
        seat[k]=seat[0];
        seat[0]=0;
        i=i+1;
    }
    i=1;
    while(i<N)
    {
        printf("%d ",seat[i]);
        i=i+1;
    }
    printf("%d\n",seat[N]);
    return 0;
}