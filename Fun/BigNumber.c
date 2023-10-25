#include <stdio.h>

int main()
{
    int a,b,x[100]={0},y[100]={0};
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
        scanf("%1d",&x[i]);
    }
    scanf("%d",&b);
    for(int i=0;i<b;i++)
    {
        scanf("%1d",&y[i]);
    }
    char answer[101]={0};
    for(int i=1;i<=a;i++)
    {
        answer[101-i]+=x[a-i];
    }
    for(int i=1;i<=b;i++)
    {
        answer[101-i]+=y[b-i];
    }
    for(int i=0;100-i>=0;i++)
    {
        if(answer[100-i]>=10)
        {
            answer[100-i]-=10;
            answer[99-i]+=1;
        }
    }
    if(a>=b)
    {
        if(answer[100-a]>0)
        {
            for(int i=100-a;i<=100;i++)
            {
                printf("%01d",answer[i]);
            }
        }
        else
        {
            for(int i=101-a;i<=100;i++)
            {
                printf("%01d",answer[i]);
            }
        }
    }
    if(a<b)
    {
        if(answer[100-b]>0)
        {
            for(int i=100-b;i<=100;i++)
            {
                printf("%01d",answer[i]);
            }
        }
        else
        {
            for(int i=101-b;i<=100;i++)
            {
                printf("%01d",answer[i]);
            }
        }
    }
    return 0;
}