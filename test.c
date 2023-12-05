#include <stdio.h>
#include <string.h>

char s[1000001],save[100000];
int main()
{
    
    scanf(" %[^\n]",s);
    scanf(" %[^\n]",save);
    printf("%d %d",strlen(s),strlen(save));
}