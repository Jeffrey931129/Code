#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[10002];
    int length, max_len, i, j, k;
    while( scanf("%s", str) != EOF )
    {
        length = strlen(str);
        max_len = 0;
        for (i = 0; i < length; i++)
        {
            // odd length
            for(j = i, k = i; j >= 0 && k < length; j--, k++)
            {
                if(str[j] != str[k]) break;
                if(k - j + 1 > max_len) max_len = k - j + 1;
            }
            // even length
            for(j = i, k = i + 1; j >= 0 && k < length; j--, k++)
            {
                if(str[j] != str[k]) break;
                if(k - j + 1 > max_len) max_len = k - j + 1;
            }
        }
        printf("%d\n", max_len);
    }
    return 0;
}

