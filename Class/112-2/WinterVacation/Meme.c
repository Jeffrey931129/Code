#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long a,b;
        scanf("%lld%lld",&a,&b);
        if(b<9) printf("%lld\n",0*a);
        else if(9<=b&&b<99) printf("%lld\n",1*a);
        else if(99<=b&&b<999) printf("%lld\n",2*a);
        else if(999<=b&&b<9999) printf("%lld\n",3*a);
        else if(9999<=b&&b<99999) printf("%lld\n",4*a);
        else if(99999<=b&&b<999999) printf("%lld\n",5*a);
        else if(999999<=b&&b<9999999) printf("%lld\n",6*a);
        else if(9999999<=b&&b<99999999) printf("%lld\n",7*a);
        else if(99999999<=b&&b<999999999) printf("%lld\n",8*a);
        else if(999999999<=b) printf("%lld\n",9*a);
    }
}