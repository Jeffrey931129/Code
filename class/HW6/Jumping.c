#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int rock[15],color[15],is_used[15],maxenergy,maxjump,n;
void jumping(int,int,int,int,int);
int main()
{
    int s,t;
    scanf("%d%d%d",&n,&s,&t);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&rock[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&color[i]);
    }
    jumping(s-1,s-1,t-1,0,0);
    printf("%d %d\n",maxenergy,maxjump);
    return 0;
}

void jumping(int x,int s,int t,int energy,int jump)  // 記得防止跳過界
{
    is_used[x]=1;
    if(x==t)
    {
        if(energy>maxenergy)
        {
            maxenergy=energy;
            maxjump=jump;
        }
        else if(energy==maxenergy)
        {
            maxjump=fmax(maxjump,jump);
        }
        is_used[x]=0;
        return;
    }
    if(x!=0&&is_used[x-1]!=1)
    {
        jumping(x-1,s,t,energy+abs(rock[x]-rock[x-1]),jump+1);

    }
    if(x!=n-1&&is_used[x+1]!=1)
    {
        jumping(x+1,s,t,energy+abs(rock[x]-rock[x-1]),jump+1);
        
    }
    for(int i=0;i<n;i++)
    {
        if(color[i]==color[x]&&is_used[i]!=1&&i!=x+1&&i!=x-1&&i!=x)
        {
            jumping(i,s,t,energy+abs(rock[x]-rock[i])*abs(x-i),jump+1);
        }
    }
    is_used[x]=0;
    return;
}