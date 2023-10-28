#include <stdio.h> 
#include <math.h>

int arr[102][102];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    int x=1,y=1,sum=arr[1][1],check=1;
    while(arr[x-1][y]!=0||arr[x][y+1]!=0||arr[x][y-1]!=0||arr[x+1][y]!=0)
    {
        
        int max=fmax(arr[x-1][y],fmax(arr[x][y+1],fmax(arr[x][y-1],arr[x+1][y])));
        if(max==arr[x-1][y])  // up
        {
            while(arr[x][y]<=max&&x!=1)
            {
                arr[x][y]=0;
                x--;
                if(arr[x][y]!=0)
                {
                    check++;
                    sum+=arr[x][y];
                }
                
            }
        }
        else if(max==arr[x][y-1])  // left
        {
            while(arr[x][y]<=max&&y!=1)
            {
                arr[x][y]=0;
                y--;
                if(arr[x][y]!=0)
                {
                    check++;
                    sum+=arr[x][y];
                }
            }
        }
        else if(max==arr[x][y+1])  // right
        {
            while(arr[x][y]<=max&&y!=m)
            {
                arr[x][y]=0;
                y++;
                if(arr[x][y]!=0)
                {
                    check++;
                    sum+=arr[x][y];
                }
            }
        }
        else  // down
        {
            while(arr[x][y]<=max&&x!=n)
            {
                arr[x][y]=0;
                x++;
                if(arr[x][y]!=0)
                {
                    check++;
                    sum+=arr[x][y];
                }
            }
        }
    }
    if(check==n*m)
    {
        printf("%d\nRoad Roller Da!!\n",sum);
    }
    else
    {
        printf("%d\n",sum);
    }
}