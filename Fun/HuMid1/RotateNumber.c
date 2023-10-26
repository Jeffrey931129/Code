#include <stdio.h>
#include <string.h>

char arr[101];
int main()
{
    scanf("%s",arr);
    int n=strlen(arr),NO=0;
    for(int i=0;i<n;i++)
    {
        switch(arr[i])
        {
            case '0':
            case '1':
            case '8':
            break;
            case '6':
            arr[i]='9'; break;
            case '9':
            arr[i]='6'; break;
            default:
            NO++; break;
        }
    }
}