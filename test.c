#include <stdio.h>


int main()
{
    int num;
    scanf("%x",&num);  // 16進位
    printf("%x",num);
    return 0;
}

void hanoi(int n,int from,int to,int temp)
{
    if(n==1)
    {
        printf("Move disk 1 from %d to %d\n",from,to);
    }
    hanoi(n-1,from,temp,to);
    printf("Move disk %d from %d to %d\n",n,from,to);
    hanoi(n-1,temp,to,from);
}