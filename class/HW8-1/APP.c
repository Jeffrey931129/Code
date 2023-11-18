#include <stdio.h>
#include <string.h>

int n,k,error,find(int step,int num,int x),check[1005][1005];
char str[1005];
int main()
{
    scanf("%d%d",&n,&k);
    scanf("%s",str);
    if(find(0,n-1,0))
    {
        printf("Yes\n");
        return 0;
    }
    
    printf("No\n");
    return 0;
}

int find(int x,int y,int pick)
{
    
    if(y<x)
    {
        return 1;
    }
    if(pick==k)
    {
        for(int temx=x,temy=y;temx<temy;temx++,temy--)
        {
            if(!(str[temx]==str[temy]))
            {
                return 0;
            }
        }
        return 1;
    }
    for(int temp=pick,temy=y;temp<=k&&temy>=x;temy--,temp++)  // ¥ªÃä¯d
    {
        if(str[x]==str[temy])
        {
            if(check[x][temy]<=temp&&check[x][temy]!=0)
            {
                return 0;
            }
            if(find(x+1,temy-1,temp))
            {
                return 1;
            }
            else
            {
                check[x][temy]=temp;
            }
            break;
        }
        
    }
    if(find(x+1,y,pick+1))  // ¥ªÃä±Ë
    {
        return 1;
    }
    return 0;
}