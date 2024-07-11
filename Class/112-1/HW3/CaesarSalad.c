#include <stdio.h>

int main()
{
    char x[4];
    int n;
    scanf("%s",x);
    scanf("%d",&n);
    n=n%26;
    if(n<0)
    {
        n=n+26;
    }
    if(x[0]+n>'Z')
    {
        x[0]=x[0]-26;
    }
    if(x[1]+n>'Z')
    {
        x[1]=x[1]-26;
    }
    if(x[2]+n>'Z')
    {
        x[2]=x[2]-26;
    }
    printf("%c%c%c\n",x[0]+n,x[1]+n,x[2]+n);
    return 0;
}