#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long g1,g2,answer;
int n,seq[20],find(int,long long num1,long long num2);
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        g1=g2=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&seq[i]);
            g2+=seq[i];
        }
        answer=g2;
        find(0,g1,g2);
        printf("%lld\n",answer);
    }
    return 0;
}

int find(int x,long long num1,long long num2)
{
    
    answer=fmin(answer,abs(num1-num2));
    if(x==n)
    {
        return 0;
    }
    find(x+1,num1+seq[x],num2-seq[x]);
    find(x+1,num1,num2);
    return 0;
}