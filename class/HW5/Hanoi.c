#include <stdio.h>

void hanoi(int,char,char,char);
int main()
{
    int n;
    scanf("%d",&n);
    hanoi(n,65,66,67);
    return 0;
}

void hanoi(int n,char A,char B,char C)
{
    if(n==1)
    {
        printf("1\n");
        return;
    }
    hanoi(n-1,A,C,B);
    printf("%d\n",n);
    hanoi(n-1,B,A,C);
}