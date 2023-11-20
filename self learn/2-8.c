#include <stdio.h>

int main()
{
    char c='A';   // c所存的資料為該字元的ASCII編號
    printf("%c\n",c);
    c=c+1;   // 利用ASCII編號來做運算
    printf("%c",c);
    return 0;
}