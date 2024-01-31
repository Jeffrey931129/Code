#include <stdio.h>

int function(int,int,int);

/*int main()
{
    int G0,G1,n;
    scanf("%d%d%d",&G0,&G1,&n);
    int G[n+1];
    G[0]=G0;G[1]=G1;
    for(int i=2;i<=n;i++)
    {
        G[i]=G[i-2]-G[i-1];
    }
    printf("%d\n",G[n]);
    return 0;
}*/

int main()
{
    int G0,G1,n;
    scanf("%d%d%d",&G0,&G1,&n);
    printf("%d\n",function(G0,G1,n));
    return 0;
}

int function(int G0,int G1,int n)
{
    if(n==1) return G1;
    if(n==2) return G0-G1;
    return function(G0,G1,n-2)-function(G0,G1,n-1);
}