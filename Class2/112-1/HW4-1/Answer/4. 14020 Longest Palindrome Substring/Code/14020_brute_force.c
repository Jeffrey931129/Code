#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[10002];
    int length, max_len;
    int i, j, k, l;
    int is_pal;

    while( scanf("%s", str) != EOF )
    {
        length = strlen(str);
        max_len = 0;
        for (i = 0; i < length; i++)
        {
            for (j = length - 1; j >= i; j--)
            {
                is_pal = 1;
                for(k = i, l = j; k <= l; k++, l--)
                {
                    // check if str[i...j] is palindrome or not
                    if( str[k] != str[l] )
                    {
                        is_pal = 0;
                        break;
                    }
                }
                if( is_pal && j - i + 1 > max_len) max_len = j - i + 1;
            }
        }
        printf("%d\n", max_len);
    }
    return 0;
}
