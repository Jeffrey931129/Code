#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    long long n,prev=__INT_MAX__,small=0,now=0,answer=0;
    scanf("%lld",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&now);
        if(now>prev) answer+=now-prev;
        prev=now;
    }
    printf("%lld\n",answer);
    return 0;
}