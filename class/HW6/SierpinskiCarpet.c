#include <stdio.h>
#include <math.h>

long long squ(int);
int main()
{
    int n;
    scanf("%d",&n);
    //printf("%d",sizeof(long long));
    printf("%lld\n",squ(n));
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