#include <stdio.h>
#include <string.h>

int main()
{
    int check1=0,answer=0;
    char x[1001],y[1000],z[1000];
    scanf("%s",x);
    int n=strlen(x);
    for(int i=3;i<=n;i++)
    {
        for(int j=0;j<=n-i;j++)
        {
            for(int k=0;k<i;k++)
            {
                y[k]=x[j+k];
                z[k]=x[j+i-1-k];
            }
            for(int k=0;k<i;k++)
            {
                if(y[k]==z[k])
                {
                    check1++;
                }
            }
            if(check1==i)
            {
                answer++;
            }
            check1=0;
        }
    }
    printf("%d\n",answer);
    return 0;
}