#include <stdio.h>

int main()
{
    float x,y;
    char c;
    scanf("%f\n%c\n%f",&x,&c,&y); 
    if(c=='+')
    {
        printf("%.3f\n",x+y);
    }
    if(c=='-')
    {
        printf("%.3f\n",x-y);
    }
    if(c=='*')
    {
        printf("%.3f\n",x*y);
    }
    if(c=='/')
    {
        printf("%.3f\n",x/y);
    }
    return 0;
}