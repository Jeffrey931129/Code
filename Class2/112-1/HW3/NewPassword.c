#include <stdio.h>

int main()
{
    char x[27],y[27],z[4];
    int i;
    i=0;
    while(i<26)
    {
        x[i]=65+i;
        i++;
    }
    i=0;
    scanf("%s",y);
    scanf("%s",z);
    if(z[0]>96)   // 小寫
    {
        z[0]=z[0]-32;
        while(x[i]!=z[0])
        {
            i++;
        }
        printf("%c",y[i]+32);
    }
    else
    {
        while(x[i]!=z[0])
        {
            i++;
        }
        printf("%c",y[i]);
    }
    i=0;
    if(z[1]>96)   // 小寫
    {
        z[1]=z[1]-32;
        while(x[i]!=z[1])
        {
            i++;
        }
        printf("%c",y[i]+32);
    }
    else
    {
        while(x[i]!=z[1])
        {
            i++;
        }
        printf("%c",y[i]);
    }
    i=0;
    if(z[2]>96)   // 小寫
    {
        z[2]=z[2]-32;
        while(x[i]!=z[2])
        {
            i++;
        }
        printf("%c",y[i]+32);
    }
    else
    {
        while(x[i]!=z[2])
        {
            i++;
        }
        printf("%c",y[i]);
    }
    printf("\n");
    return 0;
}