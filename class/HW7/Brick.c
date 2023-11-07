#include <stdio.h>
#include "D:\Jeffrey\code\class\HW7\function.h"

#define maxn 1000

char input[1000010];

int solver(int **ptr, int *sum, char *s)
{
    int temp=0,rec=1;
    for(int i=0;i<1000010;i++)
    {
        if(input[i]>='0'&&input[i]<='9')
        {
            temp=temp*10+input[i]-'0';
        }
        else
        {
            if(temp!=0)
            {
                *ptr[rec]=temp; rec++;
                *sum+=temp;
                temp=0;
            }
        }
    }
    return rec;
}

int main() {
    int sum = 0;
    int a[maxn];
    int *ptr[maxn];

    for (int i = 0; i < maxn; i++) {
        a[i] = 0;
        ptr[i] = &a[i];
    }

    scanf("%s", input);
    int n = solver(ptr, &sum, input);
    printf("%d", a[0]);
    for (int i = 1; i < n; i++)
        printf(" %d", a[i]);
    printf("\n%d\n", sum);
    return 0;
}