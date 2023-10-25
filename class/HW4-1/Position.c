#include <stdio.h>
#include <string.h>

int main()
{
    char S[1000001];
    scanf("%s",S);
    int n=strlen(S);
    for(int i=65;i<150;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(S[j]==i)
            {
                printf("%c:",S[j]);
                for(;j<n;j++)
                {
                    if(S[j]==i)
                    {
                        printf(" %d",j);
                    }
                }
                printf("\n");
            }
        }
    }
    return 0;
}