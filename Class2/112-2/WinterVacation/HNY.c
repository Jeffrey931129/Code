#include <stdio.h>
#include <math.h>

int main()
{
    int n,max,min;
    scanf("%d%d",&n,&max);
    min=max;
    for(int i=0;i<n;i++) 
    {
        int temp;
        scanf("%d",&temp);
        if(temp>max) max=temp;
        if(temp<min) min=temp;
    }
    printf("%d\n",(max-min)*2);
}