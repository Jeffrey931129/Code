#include <stdio.h>

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    char ch[n+2][m+2];
    for(int i=0;i<n;i++)
    {
       scanf("%s",ch[i+1]);
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int x=0,y,end=0;
        scanf("%d",&y);
        y--;
        for(int time=1;time<=n;time++)
        {
            if((ch[x+1][y]=='/'&&ch[x+1][y-1]=='/')||(ch[x+1][y]=='/'&&y==0))
            {
                x++;y--;
            }
            else if(ch[x+1][y]=='\\'&&ch[x+1][y+1]=='\\'||(ch[x+1][y]=='\\'&&y==m-1))
            {
                x++;y++;
            }
            else
            {
                printf("Stuck QQ\n"); end++; break;
            }
            
            if(y==-1)
            {
                printf("Left!\n"); end++; break;
            }
            if(y==m)
            {
                printf("Right!\n"); end++; break;
            }
        }
        if(!end)
        {
            printf("Position: %d\n",y+1);
        }
    }
    return 0;
}