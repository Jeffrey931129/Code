#include <stdio.h>

int main()
{
    int time,sum=0;
    printf("�аݱz�Q��QB�]�X��:");
    scanf("%d",&time);
    for(int Time=0;Time<time;Time++)
    {
        printf("�п�JQB�Ӷ]�h��:");
        int far;
        scanf("%d",&far);
        sum+=far;
        if(sum>100)
        {
            printf("QB�֭w�F");
            break;
        }
        printf("QB�w�g�]�F%dm\n",sum);
    }
}
// test