#include <stdio.h>
#include <math.h>

int t,n,m,k,find(int,int,int),answer[5],seq[10];
int main()
{
    
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        
        for(int i=0;i<n;i++)
        {
            scanf("%d",&seq[i]);
            for(int j=i-1;j>=0;j--)
            {
                if(seq[j+1]<seq[j])
                {
                    int temp=seq[j+1];
                    seq[j+1]=seq[j];
                    seq[j]=temp;
                }
                else
                {
                    break;
                }
            }
        }
        
        find(0,0,0);
    }
}



int find(int step,int sum,int x)
{
    if(step==m)
    {
        if(sum==k)
        {
            
            for(int i=0;i<m;i++)
            {
                printf("%d ",answer[i]);
                if(i==m-1)
                {
                    printf("\n");                    
                }
                    
            }         
            
            
        }
        return 0;
    }
    int temp=-1;
    for(int i=x;i<n;i++)
    {
        if(temp==seq[i])
        {
            continue;
        }
        answer[step]=seq[i];
        temp=seq[i];
        find(step+1,sum+seq[i],i+1);
    }
    return 0;
}

