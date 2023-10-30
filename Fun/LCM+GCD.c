#include <stdio.h>
#include <math.h>

int main()
{
    int x,y,answer;
    scanf("%d%d",&x,&y);
    for(int i=1;i<=fmin(x,y);i++)
    {
        if(x%i==0&&y%i==0)
        {
            answer=i;
        }
    }
    printf("%d %d\n",x*y/answer,answer);
    return 0;
}