#include <stdio.h>
#include <string.h>

int n,k,error,find(int step,int num,int x),is_used[1005];
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
    /*if(find(0,k-1,0))
    {
        return 0;
    }*/
    printf("No\n");
    return 0;
}

/*int find(int step,int num,int x)
{
    if(step==num-1)
    {
        error=0;
        for(int i=0,j=n-1;i<j;i++,j--)
        {
            while(is_used[i])
            {
                i++;
            }
            while(is_used[j])
            {
                j--;
            }
            if(!(str[i]==str[j]))
            {
                error++; break;
            }
        }
        if(!error)
        {
            
            return 1;
        }
        
    }
    if(step==num)
    {
        for(int i=0,j=n-1;i<j;i++,j--)
        {
            while(is_used[i])
            {
                i++;
            }
            while(is_used[j])
            {
                j--;
            }
            if(!(str[i]==str[j]))
            {
                return 0;
            }
        }
        
        return 1;
    }
    
    for(int i=x;i<n;i++)
    {
        is_used[i]=1;
        if(find(step+1,num,i+1))
        {
            return 1;
        }
        is_used[i]=0;
    }
    return 0;
}*/

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
        if(str[x]==str[y])
        {
            
            if(find(x+1,temy-1,temp))
            {
                return 1;
            }
        }
        
    }
    if(find(x+1,y,pick+1))  // ¥ªÃä±Ë
    {
        return 1;
    }
    return 0;
}