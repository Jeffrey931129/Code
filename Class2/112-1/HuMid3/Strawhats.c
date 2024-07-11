#include <stdio.h>
#include <string.h>
#include <math.h>

int lenth;
char s[25];
int main()
{
    scanf("%s",s);
    lenth=strlen(s);
    int step=pow(2,lenth)-1;
    for(int i=1;i<=step;i++)
    {
        for(int j=0;j<lenth;j++)
        {
            if(i>>j&1)
            {
                printf("%c",s[j]);
            }
        }
        printf("\n");
    }
    return 0;
}