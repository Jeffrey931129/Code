#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int n,x,now=0,space=0;
    scanf("%d%d",&n,&x);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<n;i++)
    {
        
        if(arr[i]>arr[i-1])
        {
            now++;
            for(int j=i-1-now;j>=0&&i-j<=x+1;j--)
            {
                if(arr[i]>arr[j])
                {
                    now++;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            now=0;
            continue;
        }
        
        if(now==x)
        {
            if(!space)
            {
                printf("%d",i+1); space++;
            }
            else
            {
                printf(" %d",i+1);
            }
        }
    }
    if(!space)
    {
        printf("ouo");
    }
    printf("\n");
    return 0;
}