#include <stdio.h>
#include <string.h>

int t,n,m,count;
int rec_n[45][50],rec_m[45][50];
char arr[50][50];
int main()
{
    scanf("%d",&t);
    int t_rec=t;
    while(t_rec--)
    {
        
        memset(rec_n,0,sizeof(rec_n)); memset(rec_m,0,sizeof(rec_m)); memset(arr,0,sizeof(arr));
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&rec_n[i][0]);
            for(int j=1;j<=rec_n[i][0];j++)
            {
                scanf("%d",&rec_n[i][j]);
            }
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d",&rec_m[i][0]);
            for(int j=1;j<=rec_m[i][0];j++)
            {
                scanf("%d",&rec_m[i][j]);
            }
        }
        for(int i=0;i<n;i++)
        {
            scanf(" %s",arr[i]);
        }
        int error=0;
        for(int i=0;i<n;i++)
        {
            error=0;
            int j=0,k=1,rec[50]={0};
            for(;j<m;j++)
            {
                if(arr[i][j]=='o')
                {
                    count++;
                }
                else
                {
                    if(count) rec[k++]=count;
                    count=0;
                }
                if(j==m-1)
                {
                    if(count) rec[k++]=count;
                    count=0;
                }
            }
            for(int h=1;h<=k;h++)
            {
                if(rec_n[i][h]!=rec[h]) 
                {
                    error++; printf("No\n"); break;
                }
            }
            
            if(error) break;
        }
        if(error) continue;
        for(int i=0;i<m;i++)
        {
            error=0;
            int j=0,k=1,rec[50]={0};
            for(;j<n;j++)
            {
                if(arr[j][i]=='o')
                {
                    count++;
                }
                else
                {
                    if(count) rec[k++]=count;
                    count=0;
                }
                if(j==n-1)
                {
                    if(count) rec[k++]=count;
                    count=0;
                }
            }
            for(int h=1;h<=k;h++)
            {
                if(rec_m[i][h]!=rec[h]) 
                {
                    error++; printf("No\n"); break;
                }
            }
            
            if(error) break;
        }
        if(error) continue;
        printf("Yes\n");
    }
    return 0;
}