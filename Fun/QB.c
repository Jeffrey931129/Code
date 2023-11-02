#include <stdio.h>

int main()
{
    int time,sum=0;
    printf("How many times do you want QB to run?");
    scanf("%d",&time);
    for(int Time=0;Time<time;Time++)
    {
        printf("How far should QB run this time?");
        int far;
        scanf("%d",&far);
        sum+=far;
        if(sum>100)
        {
            printf("QB is too tired.");
            break;
        }
        printf("QB has run %d m.\n",sum);
    }
}
// test