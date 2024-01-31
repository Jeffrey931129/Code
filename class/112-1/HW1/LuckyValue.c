#include <stdio.h>

int main()
{
    int x;
    scanf("%d",&x);
    float y=(x/1000)+(x%100/10);
    float z=(x%1000/100)+(x%10);
    printf("%.2f",y/z);
    printf("\n");
    return 0;
}