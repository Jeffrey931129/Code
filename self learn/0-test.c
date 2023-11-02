#include <stdio.h>
#include <math.h>

long long squ(int);
int main()
{
    int n;
    long long answer=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        answer+=pow(8,i);
    }
    printf("%lld\n",answer);
    return 0;
}

long long squ(int n)
{
    if(n==1)
    {
        return pow(8,0);
    }
    else
    {
        return pow(8,n-1)+squ(n-1);
    }
}