#include <stdio.h>

int student[1005],time[1005];
int main()
{
    int n; scanf("%d",&n);
    for(int i=2;i<=n;i++) scanf("%d",&student[i]);
    for(int i=2;i<=n;i++)
    {
        int rec=i;
        while(student[rec]!=0)
        {
            rec=student[rec],time[i]++;
        }
        if(i==2) printf("%d",time[i]);
        else printf(" %d",time[i]);
    }
    puts("");
    int q; scanf("%d",&q);
    while(q--)
    {
        int i,run; scanf("%d%d",&i,&run);
        if(run>time[i]) printf("-1\n");
        else if(run==time[i]) printf("1\n");
        else
        {
            int rec=i;
            while(run--)
            {
                rec=student[rec];
            }
            printf("%d\n",rec);
        }
    }
}