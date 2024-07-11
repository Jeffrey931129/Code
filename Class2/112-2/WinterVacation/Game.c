#include <stdio.h>
#include <math.h>

int main()
{
    int n,m,money,ans=0,temp=0;
    scanf("%d%d",&n,&m);
    int game[n];
    for(int i=0;i<n;i++) scanf("%d",&game[i]);
    while(m--)
    {
        scanf("%d",&money);
        if(temp==n) continue;
        while(temp!=n)
        {
            if(money>=game[temp])
            {
                temp++; ans++;
                break;
            }
            else
            {
                temp++;
            }
        }
    }
    printf("%d\n",ans);
}