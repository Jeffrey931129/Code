#include <stdio.h>
#include <math.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int y,delta=0,rec=0,leap=0,leap_rec=0;
        scanf("%d",&y);
        if((y%4==0&&y%100!=0)||y%400==0) leap=1;
        while(++delta)
        {
            if(((y+delta)%4==0&&(y+delta)%100!=0)||(y+delta)%400==0) leap_rec=1; else leap_rec=0;
            if(leap_rec) rec+=2; else rec++;
            if(rec%7==0&&leap==leap_rec) break;
        }
        printf("%d\n",y+delta);
    }
}