#include <stdio.h>
#include "D:\Jeffrey\code\class\HW7\function.h"

#define maxn 1000

char input[1000010];

int solver(int **ptr, int *sum, char *s)
{
    int temp=0,rec=0,hi=0,zero=0;
    for(int i=0;i<1000010;i++)
    {
        if(s[i]=='-')
        {
            if(hi)
            {
                temp*=-1;
                hi=0;
            }
            if(zero)
            {
                *ptr[rec]=temp; rec++;
                *sum+=temp;
                temp=0; zero=0;
            }
            hi++;
        }
        else if(s[i]>='0'&&s[i]<='9')
        {
            temp=temp*10+s[i]-'0';
            zero++;
        }
        else
        {
            if(hi)
            {
                temp*=-1;
                hi=0;
            }
            if(zero)
            {
                *ptr[rec]=temp; rec++;
                *sum+=temp;
                temp=0; zero=0;
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