#include <stdio.h>

int main()
{
    int time,sum=0;
    printf("請問你想讓QB跑幾趟:");
    scanf("%d",&time);
    for(int Time=0;Time<time;Time++)
    {
        printf("請輸入QB該跑多遠:");
        int far;
        scanf("%d",&far);
        sum+=far;
        if(sum>100)
        {
            printf("QB累趴了");
            break;
        }
        printf("QB已經跑了%dm\n",sum);
    }
}