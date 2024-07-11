#include <stdio.h>

int n,q,command;
int seafu[1005],disciple[1005];
int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++) scanf("%d",&seafu[i]);
    for(int i=n;i>=1;i--) disciple[seafu[i]]+=disciple[i]+1;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&command);
        if(command==1)
        {
            int num; scanf("%d",&num);
            printf("%d\n",disciple[num]);
        }
        else 
        {
            int a,b; scanf("%d%d",&a,&b);
            if(a>b)
            {
                int rec=seafu[a];
                while(rec>b) rec=seafu[rec];
                if(rec==b) printf("0\n");
                else printf("-1\n");
            }
            else
            {
                int rec=seafu[b];
                while(rec>a) rec=seafu[rec];
                if(rec==a) printf("1\n");
                else printf("-1\n");
            }
        }
    }
}