#include <stdio.h>
#include <string.h>

long long arr[65][2];
char find(long long,long long);
char f[2005],g[2005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf(" %s %s",f,g);
        long long n,k;
        scanf("%lld%lld",&n,&k);
        int len1=strlen(f),len2=strlen(g);
        arr[2][0]=len1,arr[2][1]=len2;
        for(int i=3;i<=n;i++)
        {
            arr[i][0]=arr[i-1][1];
            arr[i][1]=arr[i-1][0]+arr[i-1][1];
        }
        printf("%c\n",find(n,k));
    }
}

char find(long long n,long long k)
{
    if(n==0)
    {
        return f[k];
    }
    else if(n==1)
    {
        return g[k];
    }
    if(k<arr[n][0])
    {
        return find(n-2,k);
    }
    else
    {
        return find(n-1,k-arr[n][0]);
    }
}