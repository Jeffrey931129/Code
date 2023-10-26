#include <stdio.h>
#include <math.h>

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i=fmin(a,b);i>0;i--)
    {
        if((a%i==0)&&(b%i==0))
        {
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}