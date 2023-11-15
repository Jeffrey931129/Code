#include <stdio.h>
#include <string.h>

int n,k,complete,find(int step,int num,int x),is_used[1005];
char str[1005];
int main()
{
    scanf("%d%d",&n,&k);
    scanf("%s",str);
    if(find(0,k,0))
    {
        return 0;
    }
    if(find(0,k-1,0))
    {
        return 0;
    }
    printf("No\n");
    return 0;
}

int find(int step,int num,int x)
{
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
        printf("Yes\n");
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
}