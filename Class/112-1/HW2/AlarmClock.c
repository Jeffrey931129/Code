#include <stdio.h>

int main()
{
    int a,b,c,d;
    scanf("%d:%d\n%d:%d",&a,&b,&c,&d);
    if(c<a)
    {
        c=c+24;
        printf("%d\n",c*60+d-(a*60+b));
    }
    else if(c==a)
    {
        if(d<b)
        {
            c=c+24;
            printf("%d\n",c*60+d-(a*60+b));
        }
    }
    else
    {
        printf("%d\n",c*60+d-(a*60+b));
    }
    return 0;
}