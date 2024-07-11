#include <stdio.h>
#include <math.h>

int squ(int);
int main()
{
    int n,answer;
    scanf("%d",&n);
    
    printf("%d\n",squ(n));
}

int squ(int n)
{
    if(n==0)
    {
        return 0;
    }
    else
    {
        return pow(8,n-1)+squ(n-1);
    }
}